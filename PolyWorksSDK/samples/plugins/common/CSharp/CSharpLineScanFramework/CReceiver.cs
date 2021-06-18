// =================================================================================================
//   CReceiver class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Concurrent;
using System.Collections.Generic;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Enumeration used to specify the type of data returned by the SDK.
// -------------------------------------------------------------------------------------------------
enum EScanLineType
{
    Normal,     // Normal line with point data.
    PassStart,  // First line in a pass with point data.
    PassEnd,    // Empty line just signaling end of pass.
    ScanEnd     // Empty line just signaling that the "Scan End" button was pressed.
}

// =================================================================================================
//   This is a simple structure to communicate line data between the stub and the receiver and
// between the reader and writer threads. It contains the data necessary to send to the application.
// -------------------------------------------------------------------------------------------------
class CScanLine
{
    public EScanLineType m_type;
    public float         m_x; // Normal vector.
    public float         m_y;
    public float         m_z;
    public CPoint[]      m_data;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : type_ : Type of line to create.
    // -------------------------------------------------------------------------------------------------
    public CScanLine( EScanLineType type_ )
    {
        m_type = type_;
    }
}

// =================================================================================================
//   This is an example of a class that manages the plug-in and interact with the stub on one
// side and the COM interfaces on the other. It is also responsible for getting the scan data from
// the stub and sending it to the application. There are wildly varying SDK architectures,
// data types and data rates from device to device. So there cannot be one implementation that
// covers all possible cases. This class gives a simple example of a possible architecture of
// relationship between the stub and the receiver.
// However this class contains many elements that should be in all plug-ins since they are related
// to interaction with the application.
//
// TODO : Adjust this class to fit the needs of your SDK.
// TODO : If your receiver does not contain any unmanaged resources, you can remove the IDisposable interface.
// -------------------------------------------------------------------------------------------------
class CReceiver : CScanningProfilesUser, IDisposable
{
    private IMPluginLib.IIMScannerFeedback m_scannerFeedback;
    private IMPluginLib.IIMLineScan        m_lineScan;
    private IMPluginLib.IIMPointCloud      m_pointCloud;

    private System.Threading.Thread      m_readerThread;
    private System.Threading.Thread      m_writerThread;
    private bool                         m_isScanning = false;
    private bool                         m_passStarted = false;
    private bool                         m_pointsRecorded = false;
    private ConcurrentQueue< CScanLine > m_queue;
    private CScanLine[]                  m_tmpArray;
    private int                          m_tmpArrayIndex;

    // Settings cache for worker thread.
    private double m_minAngleInRad;
    private double m_squareMaxPointToPointDist;
    private bool   m_useAutomaticViewpoint;

    private bool m_isUpdatingFromSettings = false;

    // Storage for the ScanningObjectsUser interface.
    private List< string > m_surfaceScanNames;
    private string         m_surfaceScanNameCurrentChoice;
    private List< string > m_boundaryScanNames;
    private string         m_boundaryScanNameCurrentChoice;

    private CSDKStub    m_stub;
    private IM.CIMHost     m_host;
    private CSettings   m_settings;
    private CDlgInspect m_dialog;

    // Internal delegate to perform delayed updates on the dialog.
    public delegate void InvokeDelegate();

    public event EventHandler StateChanged;

    // =================================================================================================
    //   Constructor
    //
    // Parameter : host_     : Acces to host application functionalities (must not be null).
    // Parameter : settings_ : Access to the plug-in settings (must not be null).
    // -------------------------------------------------------------------------------------------------
    public CReceiver( IM.CIMHost host_, CSettings settings_ )
    {
        System.Diagnostics.Debug.Assert( host_ != null );
        System.Diagnostics.Debug.Assert( settings_ != null );

        m_stub     = new CSDKStub();
        m_host     = host_;
        m_settings = settings_;
        m_queue    = new ConcurrentQueue< CScanLine >();
        m_tmpArray = new CScanLine[ 25 ];

        m_surfaceScanNames  = new List< string >();
        m_boundaryScanNames = new List< string >();
    }

    // =================================================================================================
    //   Destructor
    //
    // Frees unmanaged resources.
    // -------------------------------------------------------------------------------------------------
    ~CReceiver()
    {
        // These references should have been freed long ago.
        System.Diagnostics.Debug.Assert( m_scannerFeedback == null );
        System.Diagnostics.Debug.Assert( m_lineScan == null );
        System.Diagnostics.Debug.Assert( m_pointCloud == null );
        Dispose( false );
    }

    // =================================================================================================
    //   Internal code for freeing unmanaged resources common to destructor and Dispose.
    //
    // Parameter : disposing_ : true if calling from Dispose, false if calling from destructor.
    // -------------------------------------------------------------------------------------------------
    private void Dispose( bool disposing_ )
    {
        if ( m_stub != null )
        {
            m_stub.Dispose();
            m_stub = null;
        }

        if ( disposing_ )
        {
            // We have freed the resources, tell the GC it does not need to Finalize this object.
            GC.SuppressFinalize( this );
        }
    }

    // =================================================================================================
    //   Implementation of IDisposable interface.
    // -------------------------------------------------------------------------------------------------
    public void Dispose()
    {
        Dispose( true );
    }

    // =================================================================================================
    //   Property access.
    // -------------------------------------------------------------------------------------------------
    public IM.CIMHost Host
    {
        get { return m_host; }
    }

    public CSettings Settings
    {
        get { return m_settings; }
    }

    public bool IsScanning
    {
        get { return m_isScanning; }
    }

    // =================================================================================================
    //   Reader thread that gets scan lines from the stub and put them in a queue for the "writer" thread.
    // -------------------------------------------------------------------------------------------------
    [System.STAThread]
    private void ReaderThreadMain()
    {
        while( m_isScanning )
        {
            CScanLine newLine = m_stub.NextLineGet();

            if ( newLine != null )
            {
                m_queue.Enqueue( newLine );
            }
        }
    }

    // =================================================================================================
    //   Get lines from the queue and group them in a temporary array.
    //
    // Return : true if a "PassEnd" was requested, false otherwise.
    // -------------------------------------------------------------------------------------------------
    private bool LinesGroup()
    {
        // We have to know the size of SAFEARRAYs in advance so we must
        // decide how many lines we will transfer. We store them locally.
        // We take as many lines are available up to an arbitrary maximum of 25.
        m_tmpArrayIndex = 0;

        while( ( m_tmpArrayIndex < m_tmpArray.Length ) && !m_queue.IsEmpty )
        { 
            // We don't want to cross a pass start/end.
            CScanLine line;
            
            // We loop while queue is not empty so this call should not fail
            // since only one thread is reading.
            if ( !m_queue.TryPeek( out line ) )
            {
                System.Diagnostics.Debug.Assert( false );
                return false;
            }

            if ( line.m_type == EScanLineType.PassStart )
            {
                if ( m_tmpArrayIndex > 0 )
                {
                    break;
                }
                else
                {
                    // Since we are now sending lines, make sure the cursor is erased.
                    var visualFeedback = m_lineScan as IMInspectLib.IIMVisualFeedback;
                    if ( visualFeedback != null  )
                    {
                        visualFeedback.PolylineDraw( null, null );
                    }

                    m_lineScan.PassStart();
                    m_passStarted = true;
                }
            }
            else if ( line.m_type == EScanLineType.PassEnd )
            {
                // Remove the line from the queue but don't keep it as it contains no data.
                m_queue.TryDequeue( out line );
                return true;
            }
            else if ( line.m_type == EScanLineType.ScanEnd )
            {
                // Remove the line from the queue but don't keep it as it contains no data.
                m_queue.TryDequeue( out line );
                // ScanEnd is requested but we cannot perform it synchronously, it must be
                // triggered by the application. So we send MSCL commands on a secondary thread.
                var thread = new System.Threading.Thread( new System.Threading.ThreadStart( ScanEndRequest ) );
                thread.SetApartmentState( System.Threading.ApartmentState.STA );
                thread.Start();
                return false;
            }

            m_queue.TryDequeue( out m_tmpArray[ m_tmpArrayIndex ] );
            ++m_tmpArrayIndex;
        }

        return false;
    }

    // =================================================================================================
    // Basic algorithm to detect sharp edges of simulated data.
    //
    // Parameter: scanLine_   : Input line scan
    // Parameter: edgePoints_ : Detected sharp edge points
    //
    // TODO: Do not use this algorithm as it is. It is used only to illustrate edge extraction with
    //       simulated data points. If you don't have an appropriate edge extraction algorithm, remove
    //       implementation relative to the E_SCAN_TYPE_SHARP_EDGE scan type.
    // -------------------------------------------------------------------------------------------------
    private void DetectRidgeEdgesOfSimulatedData( CPoint[] scanLine_, List< CPoint > edgePoints_ )
    {
        if ( scanLine_.Length < 3 )
        {
            return;
        }
        
        CPoint secondPoint = scanLine_[ 0 ];
        CPoint thirdPoint  = scanLine_[ 1 ];

        for( int i = 2; i < scanLine_.Length; ++ i )
        {
            // Get three consecutive points
            CPoint firstPoint  = secondPoint;
                   secondPoint = thirdPoint;
                   thirdPoint  = scanLine_[ i ];

            // Check the max distance between the first and the second point
            if ( m_squareMaxPointToPointDist < firstPoint.SqrDistance( secondPoint ) )
            {
                continue;
            }

            // Check the max distance between the second and the third point
            if ( m_squareMaxPointToPointDist < secondPoint.SqrDistance( thirdPoint ) )
            {
                continue;
            }

            // Create vectors from the three consecutive points
            CPoint u = secondPoint.Diff( firstPoint );
            CPoint v = thirdPoint.Diff( secondPoint );

            // Compute the scalar product and the square modulus of the two vectors
            float u_dot_v = u.DotProduct( v );
            float mod_u_2 = u.SqrModulus();
            float mod_v_2 = v.SqrModulus();

            // Compute the angle between the two vectors u and v
            double theta = Math.Abs( Math.Acos( u_dot_v / Math.Sqrt( mod_u_2 * mod_v_2 ) ) );

            // If the angle is higher than the sharp edge min angle
            if ( theta > m_minAngleInRad )
            {
                edgePoints_.Add( secondPoint );
            }
        }
    }

    // =================================================================================================
    //   Take the lines in the temporary array and tranform them in the format needed by the application
    // and then send them to the application.
    // -------------------------------------------------------------------------------------------------
    private void LinesSend()
    {
        // TODO: The data sent to the application must always be in application units.
        //       If your device always generate data in a fixed units (mm for example),
        //       you must convert before sending to the application.
        float scaleFactor = (float) m_settings.HostUnitsScalingFactor;

        bool passEndRequested = LinesGroup();

        if ( m_tmpArrayIndex > 0 )
        {
            // Surface or Surface and Boundary modes.
            if ( m_pointCloud == null )
            {
                int nCoords = 0;

                // First fill the "number of points per line" and "normal vector"
                // arrays to count the total number of points.
                System.Array normalVectors = System.Array.CreateInstance( typeof( float ), 3 * m_tmpArrayIndex );
                System.Array pointCounts = System.Array.CreateInstance( typeof( int ), m_tmpArrayIndex );

                for( int i = 0; i < m_tmpArrayIndex; ++i )
                {
                    CScanLine line = m_tmpArray[ i ];

                    normalVectors.SetValue( line.m_x, i * 3 );
                    normalVectors.SetValue( line.m_y, i * 3 + 1 );
                    normalVectors.SetValue( line.m_z, i * 3 + 2 );

                    pointCounts.SetValue( line.m_data.Length, i );

                    nCoords += line.m_data.Length * 3;
                }

                // Convert the points.
                System.Array points = System.Array.CreateInstance( typeof( float ), nCoords );

                int index = 0;

                for( int i = 0; i < m_tmpArrayIndex; ++i )
                {
                    CScanLine line = m_tmpArray[ i ];

                    for( int j=0; j < line.m_data.Length; ++j )
                    { 
                        points.SetValue( line.m_data[ j ].X * scaleFactor, index + j * 3 );
                        points.SetValue( line.m_data[ j ].Y * scaleFactor, index + j * 3 + 1 );
                        points.SetValue( line.m_data[ j ].Z * scaleFactor, index + j * 3 + 2 );
                    }

                    index += line.m_data.Length * 3;
                }

                m_lineScan.LinesAdd( ref normalVectors, ref points, ref pointCounts );
            }
            else
            {
                // Sharp edge mode. Lines are passed through a filter to detect edges.
                List< CPoint > filteredPoints = new List< CPoint >();

                for( int i = 0; i < m_tmpArrayIndex; ++i )
                {
                    DetectRidgeEdgesOfSimulatedData( m_tmpArray[ i ].m_data, filteredPoints );
                }

                System.Array points = System.Array.CreateInstance( typeof( float ), filteredPoints.Count * 3 );

                for( int i = 0; i < filteredPoints.Count; ++i )
                {
                    points.SetValue( filteredPoints[ i ].X * scaleFactor, i * 3 );
                    points.SetValue( filteredPoints[ i ].Y * scaleFactor, i * 3 + 1 );
                    points.SetValue( filteredPoints[ i ].Z * scaleFactor, i * 3 + 2 );
                }

                m_pointCloud.PointsAdd( ref points, null, null );
            }
            
            m_pointsRecorded = true;
        }

        if ( passEndRequested )
        {
            m_lineScan.PassEnd();
            m_passStarted = false;
        }
    }

    // =================================================================================================
    //   When a pass is not started, received lines are sent to draw a "cursor" in the 3D scene.
    // -------------------------------------------------------------------------------------------------
    private void CursorSend()
    {
        // TODO: The data sent to the application must always be in application units.
        //       If your device always generate data in a fixed units (mm for example),
        //       you must convert before sending to the application.
        float scaleFactor = (float) m_settings.HostUnitsScalingFactor;

        int i = 0;

        var visualFeedback = m_lineScan as IMInspectLib.IIMVisualFeedback;

        IMInspectLib.IIMSceneCamera sceneCamera = null;
        if ( m_useAutomaticViewpoint )
        {
            sceneCamera = m_lineScan as IMInspectLib.IIMSceneCamera;
        }

        while( ( i < 50 ) && !m_queue.IsEmpty )
        {
            CScanLine line;
            
            if ( !m_queue.TryPeek( out line ) || ( line.m_type != EScanLineType.Normal ) )
            {
                break;
            }
                   
            m_queue.TryDequeue( out line );

            if ( visualFeedback != null  )
            {
                System.Array points      = System.Array.CreateInstance( typeof( float ), line.m_data.Length * 3 );
                System.Array pointCounts = System.Array.CreateInstance( typeof( int ), 1 );

                for( int j=0; j < line.m_data.Length; ++j )
                { 
                    points.SetValue( line.m_data[ j ].X * scaleFactor, j * 3 );
                    points.SetValue( line.m_data[ j ].Y * scaleFactor, j * 3 + 1 );
                    points.SetValue( line.m_data[ j ].Z * scaleFactor, j * 3 + 2 );
                }

                pointCounts.SetValue( line.m_data.Length, 0 );

                visualFeedback.PolylineDraw( ref points, ref pointCounts );

                if ( sceneCamera != null )
                {
                    System.Array vector = System.Array.CreateInstance( typeof( float ), 3 );
                    vector.SetValue( line.m_x, 0 );
                    vector.SetValue( line.m_y, 1 );
                    vector.SetValue( line.m_z, 2 );
                    sceneCamera.ViewpointSet( ref vector );
                }
            }

            ++i;
        }
    }

    // =================================================================================================
    //   Writer thread that gets scan lines from the queue and either send them to the application or
    // draw a cursor.
    // -------------------------------------------------------------------------------------------------
    [System.STAThread]
    private void WriterThreadMain()
    {
        while( m_isScanning || !m_queue.IsEmpty )
        {
            // Sleep to give a chance to other threads. This also allows grouping of lines to call
            // the application less often.
            System.Threading.Thread.Sleep( 100 );

            if ( !m_queue.IsEmpty )
            {
                CScanLine line;
                m_queue.TryPeek( out line );

                if ( m_passStarted || ( line.m_type != EScanLineType.Normal ) )
                {
                    LinesSend();
                }
                else
                {
                    CursorSend();
                }
            }
        }
    }

    // =================================================================================================
    //   Internal function to trigger the "StateChanged" event.
    // -------------------------------------------------------------------------------------------------
    private void OnStateChange()
    {
        EventHandler handler = StateChanged;

        if ( handler != null )
        {
            handler( this, new EventArgs() );
        }
    }

    // =================================================================================================
    //   Try to connect to the device.
    //
    // Parameter : feedback_ : Feedback object than can must used to inform the application on disconnection.
    //
    // Return : true if connection was successful, false on failure.
    // -------------------------------------------------------------------------------------------------
    public bool Connect( IMPluginLib.IIMScannerFeedback feedback_ )
    {
        if ( m_stub.Connect() )
        {
            m_scannerFeedback = feedback_;
            return true;
        }
        else
        {
            IM.Utils.COMObjectRelease( ref feedback_ );
            return false;
        }
    }

    // =================================================================================================
    //   Disconnect from the device.
    //
    // Return : true if disconnection was successful, false on failure.
    // -------------------------------------------------------------------------------------------------
    public bool Disconnect()
    {
        ScanEnd();

        if ( m_scannerFeedback != null )
        { 
            m_scannerFeedback.ScanningConnectionEnd();
            IM.Utils.COMObjectRelease( ref m_scannerFeedback );
        }

        return true;
    }

    // =================================================================================================
    //   Start a scanning session.can lines from the stub and put them in a queue for the "writer" thread.
    //
    // Parameter : lineScan_   : The line scan object that allows to control the session and send lines
    //                           when pointCloud_ is null (Surface or Surface and Boundary). Cannot be
    //                           null.
    // Parameter : pointCloud_ : The point cloud object to use to send points in "Sharp Edge" mode.
    //                           Will be null for other modes.
    //
    // Return : true on success, false on failure.
    // -------------------------------------------------------------------------------------------------
    public bool ScanStart( IMPluginLib.IIMLineScan lineScan_, IMPluginLib.IIMPointCloud pointCloud_ )
    {
        // Read settings at start to avoid reading them repeatedly in the worker thread,
        // which is very costly.
        if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
        {
            m_minAngleInRad = IM.Utils.DegToRad( m_settings.IMISharpEdgeMinAngle );
            // The filtering algo is executed on data in mm so we must "unscale" the max distance parameter.
            m_squareMaxPointToPointDist = IM.Utils.Square( m_settings.IMISharpEdgeMaxPointToPointDistance / m_settings.HostUnitsScalingFactor );
        }
        m_useAutomaticViewpoint = m_settings.UseAutoViewpoint;

        m_pointCloud = pointCloud_;
        m_lineScan = lineScan_;
        m_lineScan.TransferStart( IMPluginLib.EDigitizingVectorDirections.E_DIGITIZING_VECTOR_DIRECTION_SCANNER_TO_OBJECT );
        m_stub.ScanStart();
        m_isScanning = true;
        m_passStarted = false;
        m_pointsRecorded = false;

        m_readerThread = new System.Threading.Thread( new System.Threading.ThreadStart( ReaderThreadMain ) );
        m_writerThread = new System.Threading.Thread( new System.Threading.ThreadStart( WriterThreadMain ) );
        m_readerThread.Start();
        m_writerThread.Start();

        var sceneCamera = lineScan_ as IMInspectLib.IIMSceneCamera;

        if ( sceneCamera != null )
        {
            double offset = 1000 * m_settings.HostUnitsScalingFactor;
            sceneCamera.ClippingPlanesOffsetSet( offset, -offset );
            sceneCamera.RefreshTriggerSetTimeDelay( m_settings.RefreshDelay );
        }

        EnableRealTimeInspection( m_settings.IMIRealTimeInspection );
        OnStateChange();
        return true;
    }

    // =================================================================================================
    //   End a scanning session.
    // -------------------------------------------------------------------------------------------------
    public void ScanEnd()
    {
        if ( m_isScanning )
        {
            // Stop the scanning on the device side before stopping the worker threads to make
            // sure we don't lose any lines.
            m_stub.ScanEnd();
            m_isScanning = false;
            m_readerThread.Join();
            m_writerThread.Join();

            if ( m_lineScan != null )
            {
                m_lineScan.TransferEnd();
                IM.Utils.COMObjectRelease( ref m_lineScan );
            }
            IM.Utils.COMObjectRelease( ref m_pointCloud );

            OnStateChange();
        }
    }

    // =================================================================================================
    //   Event-handler called when the dialog is closed. Disconnect from the device and inform the
    // application that the dialog is closed.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void FormClosed( object sender, System.Windows.Forms.FormClosedEventArgs e )
    {
        Disconnect();

        if ( m_scannerFeedback != null )
        {
            var feedback2 = m_scannerFeedback as IMInspectLib.IIMScannerFeedback2;

            if ( feedback2 != null )
            { 
                feedback2.ScanningDlgClosed();
            }
        }

        m_dialog = null;
    }

    // =================================================================================================
    //   Show the configuration dialog. This is a modeless floating dialog as it is not possible to use
    // the DialogZone from .NET.
    // -------------------------------------------------------------------------------------------------
    public void InterfacePopup()
    {
        // This example only provides a GUI for Inspector.
        if ( m_host.HostApplication != IM.EHostApplication.IMINSPECT )
        {
            return;
        }

        if ( m_dialog == null )
        {
            m_dialog = new CDlgInspect( this );
            m_dialog.FormClosed += FormClosed;
        }

        // Using the overload of Show that takes a parameter will use the "main window" when we
        // pass null. This way the plug-in window cannot end up hidden behind the main window.
        System.Windows.Forms.IWin32Window owner = null;
        m_dialog.Show( owner );
    }

    // =================================================================================================
    //   Close the configuration dialog.
    // -------------------------------------------------------------------------------------------------
    public void InterfacePopdown()
    {
        if ( m_dialog != null )
        { 
            m_dialog.Close();
        }
    }

    // =================================================================================================
    //   Called by the COM layer to store the current object names by scan type.
    //
    // Parameter : scanType_      : The scan type for which names are given.
    // Parameter : objectNames_   : The list of all existing object names (may be empty but not null).
    // Parameter : currentChoice_ : The current choice (which may not be in objectNames_ if it has not
    //                              been created yet).
    // -------------------------------------------------------------------------------------------------
    public void ScanningObjectsSet( IMPluginLib.EScanTypes scanType_, ref System.Array objectNames_, string currentChoice_ )
    {
        bool updateDialog = false;

        if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE )
        {
            m_boundaryScanNameCurrentChoice = currentChoice_;
            m_boundaryScanNames.Clear();
            foreach( string name in objectNames_ )
            { 
                m_boundaryScanNames.Add( name );
            }

            updateDialog = true;
        }
        else if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE )
        {
            m_surfaceScanNameCurrentChoice = currentChoice_;
            m_surfaceScanNames.Clear();
            foreach( string name in objectNames_ )
            { 
                m_surfaceScanNames.Add( name );
            }

            updateDialog = true;
        }

        // Ask the dialog to update itself.
        if ( updateDialog && ( m_dialog != null ) && m_dialog.Created )
        {
            m_dialog.BeginInvoke( new InvokeDelegate( m_dialog.DialogUpdate ) );
        }
    }

    // =================================================================================================
    //   Called by the UI to get the current list of available names and the current choice for the
    // next scan.
    //
    // Parameter : scanType_    : The scan type for which names are requested.
    // Parameter : objectNames_ : On output, list of available names. May be empty but not null.
    //
    // Return : The current choice (may not be in objectNames_ if not created yet).
    // -------------------------------------------------------------------------------------------------
    public string ScanningObjectsGet( IMPluginLib.EScanTypes scanType_, out List< string > objectNames_ )
    {
        // Full copy not just reference so that caller cannot modify our list.
        objectNames_ = new List< string >();

        string result = "";

        if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE )
        {
            objectNames_.AddRange( m_boundaryScanNames );
            if ( m_boundaryScanNameCurrentChoice != null )
            {
                result = m_boundaryScanNameCurrentChoice;
            }
        }
        else if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE )
        {
            objectNames_.AddRange( m_surfaceScanNames );
            if ( m_surfaceScanNameCurrentChoice != null )
            {
                result = m_surfaceScanNameCurrentChoice;
            }
        }

        return result;
    }

    // =================================================================================================
    //   Enable/disable Real Time Inspection.
    //
    // Parameter : enable_ : true to enable, false to disable.
    // -------------------------------------------------------------------------------------------------
    public void EnableRealTimeInspection( bool enable_ )
    {
        if ( m_lineScan != null )
        {
            var inspector = m_lineScan as IMInspectLib.IIMRealTimeInspector2;

            if ( inspector != null )
            {
                int result = inspector.RealTimeInspectionEnable( enable_ );

                if ( ( enable_  && ( result == 0 ) ) ||
                     ( !enable_ && ( result == 1 ) ) )
                {
                    System.Diagnostics.Debug.Assert( false );
                }
            }

            OnStateChange();
        }
    }

    // =================================================================================================
    //   Enable/disable Real Time Quality Meshing.
    //
    // Parameter : enable_ : true to enable, false to disable.
    // -------------------------------------------------------------------------------------------------
    public void EnableRealTimeMeshing( bool enable_ )
    {
        if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
        {
            m_host.ValueOnOffSynchWithApp( Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_GET,
                                           Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_SET,
                                           enable_,
                                           true );

            m_settings.IMIRealTimeMeshing = enable_;
        }
    }

    // =================================================================================================
    //   Execute the SCAN END command and finalize when in Real Time Meshing mode and there are points
    // acquired.
    // -------------------------------------------------------------------------------------------------
    public void ScanEndRequest()
    {
        // Since this function may be called from a secondary thread, we register a message filter
        // so that a retry will be perform if the application is busy.
        using( var comMessageFilter = IM.CComMessageFilter.Create() )
        {
            System.Diagnostics.Debug.Assert( comMessageFilter != null );
            m_host.ExecuteCommand( Consts.CMD_SCAN_END, true, true, false );

            if ( m_settings.IMIRealTimeMeshing && !m_settings.TestMode && m_pointsRecorded )
            {
                m_host.ExecuteCommand( "DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING FINAL_DATA_OBJECT CREATE", true, false, false );
            }
        }
    }

    // =================================================================================================
    //   Just a wrapper around CSettings.ScanType.set to make sure the dialog is notified.
    //
    // Parameter : scanType_ : The new type.
    // -------------------------------------------------------------------------------------------------
    public void ScanTypeSet( IMPluginLib.EScanTypes scanType_ )
    {
        m_settings.ScanType = scanType_;
        OnStateChange();
    }

    // =================================================================================================
    //   Update application from plug-in settings
    // -------------------------------------------------------------------------------------------------
    public void UpdateFromSettings()
    {
        m_isUpdatingFromSettings = true;

        if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
        {
            EnableRealTimeInspection( m_settings.IMIRealTimeInspection );
        }

        // Update application auto viewpoint settings
        m_host.ValueOnOffSynchWithApp( Consts.CMD_AUTO_VIEWPOINT_SET + Consts.CMD_GET_SUFFIX,
                                       Consts.CMD_AUTO_VIEWPOINT_SET,
                                       m_settings.UseAutoViewpoint,
                                       true );

        m_host.ValueStrSynchWithApp( Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET + Consts.CMD_GET_SUFFIX,
                                     Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET,
                                     IM.Utils.EnumToMSCL( m_settings.DeviceVerticalAxis ),
                                     true );

        m_host.ValueIntSynchWithApp( Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET + Consts.CMD_GET_SUFFIX,
                                     Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET,
                                     m_settings.AutoViewpointZoomCloseUp,
                                     true );

        // Update application settings for PolyWorks|Inspector
        if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
        {

            m_host.ValueOnOffSynchWithApp( Consts.CMD_EXTRACT_NORMAL_VECTORS + Consts.CMD_GET_SUFFIX,
                                           Consts.CMD_EXTRACT_NORMAL_VECTORS,
                                           m_settings.IMIExtractNormals,
                                           true );

            m_host.ValueDoubleSynchWithApp( Consts.CMD_EXTRACT_NORMALS_MAX_DISTANCE + Consts.CMD_GET_SUFFIX,
                                            Consts.CMD_EXTRACT_NORMALS_MAX_DISTANCE,
                                            m_settings.IMIMaxSearchDist,
                                            true );

            m_host.ValueDoubleSynchWithApp( Consts.CMD_EXTRACT_NORMALS_MIN_DISTANCE + Consts.CMD_GET_SUFFIX,
                                            Consts.CMD_EXTRACT_NORMALS_MIN_DISTANCE,
                                            m_settings.IMIMinSearchDist,
                                            true );

            // Update application real-time meshing settings
            m_host.ValueOnOffSynchWithApp( Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_GET,
                                           Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_SET,
                                           m_settings.IMIRealTimeMeshing,
                                           true );
        }

        m_isUpdatingFromSettings = false;
    }

    // =================================================================================================
    //   Update settings from the application settings
    //
    // Parameter : updateProfileSettings_ : Indicates whether profile settings should be updated
    // -------------------------------------------------------------------------------------------------
    public void UpdateSettingsFromApp( bool updateProfileSettings_ )
    {
        if( m_isUpdatingFromSettings )
        {
            return;
        }

        bool   boolValue;
        double doubleValue;
        int    intValue;
        string strValue;

        // Contains only settings that are also kept by the application.
        // (As a guide line, the get commands must be application commands and not plug-in commands)
        if ( m_host.ValueOnOffSynchFromApp( Consts.CMD_AUTO_VIEWPOINT_SET + Consts.CMD_GET_SUFFIX,
                                            m_settings.UseAutoViewpoint,
                                            out boolValue ) )
        {
            m_settings.UseAutoViewpoint = boolValue;
        }

        if( updateProfileSettings_ )
        {
            if ( m_host.ValueStrSynchFromApp( Consts.CMD_AUTO_VIEWPOINT_VERTICAL_AXIS_SET + Consts.CMD_GET_SUFFIX,
                                              IM.Utils.EnumToMSCL( m_settings.DeviceVerticalAxis ),
                                              out strValue ) )
            {
                EStdAxis? deviceVerticalAxis = IM.Utils.MSCLToEnum<EStdAxis>(strValue);
                if( deviceVerticalAxis.HasValue )
                {
                     m_settings.DeviceVerticalAxis = deviceVerticalAxis.Value;
                }
            }
        }

        if ( m_host.ValueIntSynchFromApp( Consts.CMD_AUTO_VIEWPOINT_CLOSEUP_ZOOM_SET + Consts.CMD_GET_SUFFIX,
                                          m_settings.AutoViewpointZoomCloseUp,
                                          out intValue ) )
        {
            m_settings.AutoViewpointZoomCloseUp = intValue;
        }

        if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
        {

            if ( m_host.ValueOnOffSynchFromApp( Consts.CMD_EXTRACT_NORMAL_VECTORS + Consts.CMD_GET_SUFFIX,
                                                m_settings.IMIExtractNormals,
                                                out boolValue ) )
            {
                m_settings.IMIExtractNormals = boolValue;
            }

            if ( m_host.ValueDoubleSynchFromApp( Consts.CMD_EXTRACT_NORMALS_MAX_DISTANCE + Consts.CMD_GET_SUFFIX,
                                                 m_settings.IMIMaxSearchDist,
                                                 out doubleValue ) )
            {
                m_settings.IMIMaxSearchDist = doubleValue;
            }

            if ( m_host.ValueDoubleSynchFromApp( Consts.CMD_EXTRACT_NORMALS_MIN_DISTANCE + Consts.CMD_GET_SUFFIX,
                                                 m_settings.IMIMinSearchDist,
                                                 out doubleValue ) )
            {
                m_settings.IMIMinSearchDist = doubleValue;
            }

            if ( m_host.ValueOnOffSynchFromApp( Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_GET,
                                                m_settings.IMIRealTimeMeshing,
                                                out boolValue ) )
            {
                m_settings.IMIRealTimeMeshing = boolValue;
            }
        }
    }

    // =================================================================================================
    //   Override from the CScanningProfilesUser class to inform the dialog that profiles have changed.
    // -------------------------------------------------------------------------------------------------
    public override void UpdateProfiles()
    {
        if ( ( m_dialog != null ) && m_dialog.Created )
        {
            m_dialog.BeginInvoke( new InvokeDelegate( m_dialog.ProfilesControlUpdate ) );
        }
    }

    // =================================================================================================
    //   Used by the SaveAs dialog to request saving of a custom profile.
    // -------------------------------------------------------------------------------------------------
    public bool UserScanningProfileSave( string name_ )
    {
        return m_host.ExecuteCommand( IM.Utils.CommandBuild( "DIGITIZE DEVICE SCAN PROFILE SAVE_AS", IM.Utils.Quote( name_ ) ), true, true, true );
    }
}

}
