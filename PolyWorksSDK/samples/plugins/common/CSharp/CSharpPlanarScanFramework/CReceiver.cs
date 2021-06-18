// =================================================================================================
//   CReceiver class
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using IMPluginLib;

namespace CompanyNameCsPlanarScanner
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
class CReceiver : IDisposable
{
    private IMPluginLib.IIMScannerFeedback m_scannerFeedback;
    private IMPluginLib.IIMPlanarGrid      m_planarGridScan;
    private bool                           m_isScanning = false;
        
    // Storage for the ScanningObjectsUser interface.
    private List<string> m_surfaceScanName;
    private string m_surfaceScanNameCurrentChoice;
   
    private CSDKStub    m_stub;
    private IM.CIMHost  m_host;
    private CSettings   m_settings;
    private CDlgBase    m_dialog;

    private Array             m_digitizingVector = new float[]{ 0.0f, 0.0f, 0.0f }; 
    private readonly object[] m_NewDevicePositionIfNeededCMDArgArray = { null, null, true };
    private int               m_nbPointsRecorded = 0;

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

        m_stub     = new CSDKStub( this );
        m_host     = host_;
        m_settings = settings_;
        m_surfaceScanName = new List<string>();
    }

    // =================================================================================================
    //   Destructor
    //
    // Frees unmanaged resources.
    // -------------------------------------------------------------------------------------------------
    ~CReceiver()
    {
        if ( m_stub != null )
        {
            m_stub.Dispose();
            m_stub = null;
        }

        // These references should have been freed long ago.
        System.Diagnostics.Debug.Assert( m_scannerFeedback == null );
        System.Diagnostics.Debug.Assert( m_planarGridScan == null );
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

    public int NbPointsRecorded
    {
        get { return m_nbPointsRecorded;  }
    }

    // =================================================================================================
    // Called when data is received
    //
    // Parameter: data_ : Received data
    // -------------------------------------------------------------------------------------------------
    public void OnDataAcquired( CScanData data )
    {     
        // Packaging digitizing vector for COM transfer ( using +Z for simulation )
        //Array normal = Array.CreateInstance( typeof( float ), data.m_normal.Length );
        data.m_normal.CopyTo( m_digitizingVector, 0 );
        
        // Beginning transfer
        m_planarGridScan.TransferStart( ( short )( data.m_height ),
                                        ( short )( data.m_width ),
                                        IMPluginLib.EDigitizingVectorDirections.E_DIGITIZING_VECTOR_DIRECTION_OBJECT_TO_SCANNER,
                                        ref m_digitizingVector );
               
        // Change point formating to match format required by PolyWorks
        float scaleFactor = ( float ) m_settings.HostUnitsScalingFactor;
        Array matrixIndex = data.m_points.Keys.ToArray().SelectMany( gridPts_ => new[] { ( short ) gridPts_.X, ( short ) gridPts_.Y } ).ToArray();
        Array coords = data.m_points.Values.ToArray().SelectMany( pts_ => new[] { scaleFactor * pts_.Item1, scaleFactor * pts_.Item2, scaleFactor * pts_.Item3 } ).ToArray();
        
        // Add points to planar grid
        m_planarGridScan.GridPointsAdd( ref matrixIndex, ref coords, null, null, null );
        m_nbPointsRecorded += coords.Length;

        // Ask the dialog to update itself.
        if ( m_dialog != null && m_dialog.Created && m_host.HostApplication == IM.EHostApplication.IMALIGN )
        {
            m_dialog.BeginInvoke( new InvokeDelegate( m_dialog.DialogUpdate ) );
        }

        // ScanEnd is requested but we cannot perform it synchronously, it must be
        // triggered by the application. So we send MSCL commands on a secondary thread.
        var thread = new System.Threading.Thread (new System.Threading.ThreadStart( ScanEndRequest ) );
        thread.SetApartmentState( System.Threading.ApartmentState.STA );
        thread.Start();
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
        m_nbPointsRecorded = 0;
        // Ask the dialog to update itself.
        if ( m_dialog != null && m_dialog.Created )
        {
            m_dialog.BeginInvoke( new InvokeDelegate( m_dialog.DialogUpdate ) );
        }
        return true;
    }

    // =================================================================================================
    //   Start a scanning session from the stub and put them in a queue for the "writer" thread.
    //
    // Parameter : planarGrid_   : The planar scan object that allows to control the session and send grid points
    //                             Cannot be null.
    //
    // Return : true on success, false on failure.
    // -------------------------------------------------------------------------------------------------
    public bool ScanStart( IMPluginLib.IIMPlanarGrid planarGrid_ )
    {
        m_planarGridScan = planarGrid_;

        m_isScanning = m_stub.ScanStart();
        
        OnStateChange();
        return true;
    }

    // =================================================================================================
    //   Create a new device position if necessary
    //
    // Parameter : isVisibleInCommandHistory_ : true if called secretly (visible in Command History), false otherwise
    // -------------------------------------------------------------------------------------------------
    public void CreateNewDevicePositionIfNeeded( bool isVisibleInCommandHistory_ )
    {
        // Device position concept is only supported on PolyWorks|Inspector
        m_host.ExecuteCommand(
            IM.Utils.CommandBuild(Consts.CMD_DEVICE_POSITION_CREATE, String.Empty, m_NewDevicePositionIfNeededCMDArgArray),
            isVisibleInCommandHistory_,
            true,
            false);
        }

    // =================================================================================================B
    //   End a scanning session.
    // -------------------------------------------------------------------------------------------------
    public void ScanEnd()
    {
        if ( m_isScanning )
        {
            if ( m_planarGridScan != null )
            {
                m_planarGridScan.TransferEnd();
                // Setting view point
                if ( m_settings.UseAutoViewpoint && m_host.HostApplication == IM.EHostApplication.IMINSPECT ||
                     m_host.HostApplication == IM.EHostApplication.IMALIGN )
                {
                        ViewPointSet();
                }
                // Freeing planar grid COM object
                IM.Utils.COMObjectRelease( ref m_planarGridScan );
            }
            m_stub.ScanEnd();
            m_isScanning = false;
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
        if ( m_dialog == null )
        {
            if ( m_host.HostApplication == IM.EHostApplication.IMINSPECT )
            {
                m_dialog = new CDlgInspect( this );
                m_dialog.FormClosed += FormClosed;
            }
            else if ( m_host.HostApplication == IM.EHostApplication.IMALIGN )
            {
                m_dialog = new CDlgAlign( this );
                m_dialog.FormClosed += FormClosed;
            }
            else
            {
                return;
            }
        }

        if ( !m_dialog.Visible )
        {
            // Using the overload of Show that takes a parameter will use the "main window" when we
            // pass null. This way the plug-in window cannot end up hidden behind the main window.
            System.Windows.Forms.IWin32Window owner = null;
            m_dialog.Show( owner );
        }
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

        if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE )
        {
            m_surfaceScanNameCurrentChoice = currentChoice_;
            m_surfaceScanName.Clear();
            foreach( string name in objectNames_ )
            {
                m_surfaceScanName.Add( name );
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
    public string ScanningObjectsGet( EScanTypes scanType_, out List<string> objectNames_)
    {
        // Full copy not just reference so that caller cannot modify our list.
        objectNames_ = new List< string >();

        string result = "";

        if ( scanType_ == IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE )
        {
            objectNames_.AddRange( m_surfaceScanName );
            if ( m_surfaceScanNameCurrentChoice != null )
            {
                result = m_surfaceScanNameCurrentChoice;
            }
        }

        return result;
    }

    // =================================================================================================
    //   Execute the SCAN END command
    // -------------------------------------------------------------------------------------------------
    public void ScanEndRequest()
    {
        // Since this function may be called from a secondary thread, we register a message filter
        // so that a retry will be perform if the application is busy.
        using( var comMessageFilter = IM.CComMessageFilter.Create()  )
        {
            System.Diagnostics.Debug.Assert( comMessageFilter != null );
            m_host.ExecuteCommand( Consts.CMD_SCAN_END, true, true, false );
        }
    }

    // =================================================================================================
    // Changing camera view point
    // -------------------------------------------------------------------------------------------------
    private void ViewPointSet()
    {
        System.Diagnostics.Debug.Assert( m_digitizingVector.OfType<float>().Count() == 3 );
        var sceneCamera = m_planarGridScan as IMInspectLib.IIMSceneCamera;
        if (sceneCamera != null)
        {
            sceneCamera.ViewpointSet( ref m_digitizingVector );
        }
    }
}
}
