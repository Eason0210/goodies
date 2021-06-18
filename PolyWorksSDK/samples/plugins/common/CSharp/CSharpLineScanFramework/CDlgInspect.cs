// =================================================================================================
//   CDlgInspect class
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CompanyNameCsLineScanner
{

// =================================================================================================
//   Class implementing the main plug-in dialog in Inspector mode.
// -------------------------------------------------------------------------------------------------
internal partial class CDlgInspect : Form
{
    private const string   SCAN_TYPE_SURFACE    = "Surface";
    private const string   SCAN_TYPE_BOUNDARY   = "Surface and Boundary";
    private const string   SCAN_TYPE_SHARP_EDGE = "Sharp Edge";

    private const string   DATA_TYPE_POLYGONAL   = "Polygonal Model";
    private const string   DATA_TYPE_POINT_CLOUD = "Point Cloud from Mesh";

    private IM.CIMHost        m_host;
    private CReceiver      m_receiver;
    private CSettings      m_settings;
    private List< string > m_profileCmdArgNames;
    private bool           m_synchronizingProfiles = false;

    // =================================================================================================
    //   Ask the application to return the current scan type and convert the answer from the MSCL
    // string to the COM enum.
    //
    // Return : The current scan type.
    // -------------------------------------------------------------------------------------------------
    private IMPluginLib.EScanTypes IMIScanTypeGet()
    {
        string scanType = m_host.ValueStrGet( Consts.CMD_SCAN_TYPE + Consts.CMD_GET_SUFFIX, "", false );

        if ( scanType == SCAN_TYPE_SHARP_EDGE )
        {
            return IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE;
        }
        else if ( scanType == SCAN_TYPE_BOUNDARY )
        {
            return IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE_AND_BOUNDARY;
        }

        return IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE;
    }

    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgInspect()
    {
        InitializeComponent();
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : receiver_ : Access to the receiver.
    // -------------------------------------------------------------------------------------------------
    public CDlgInspect( CReceiver receiver_ )
    {
        InitializeComponent();

        m_receiver = receiver_;
        m_host = m_receiver.Host;
        m_settings = m_receiver.Settings;
        DialogUpdate();
        m_receiver.EnableRealTimeMeshing( m_settings.IMIRealTimeMeshing );
        m_receiver.StateChanged += ReceiverStateChanged;
    }

    // =================================================================================================
    //   Update the status of a pair of combobox/textbox controlling the name of the data object where
    // scanlines are stored. Since there are 2 pairs (surface and boundary), the controls are passed as
    // parameters.
    //
    // Parameter : name_     : The textbox control to update.
    // Parameter : objects_  : The combobox control to update.
    // Parameter : scanType_ : The scan type to use to retrieve the list of names.
    // -------------------------------------------------------------------------------------------------
    private void DataObjectsUpdate( TextBox name_, ComboBox objects_, IMPluginLib.EScanTypes scanType_ )
    {
        List< string > names;

        // Get the application Data Object names
        string currentChoice = m_receiver.ScanningObjectsGet( scanType_, out names );

        names.Insert( 0, "(Create New)" );

        IM.Utils.ComboAndListSynchronize( objects_, names, currentChoice, 0 );

        name_.Enabled = objects_.SelectedIndex == 0;

        name_.Text = currentChoice;
    }

    // =================================================================================================
    //   Update the enabled state of all controls according to current status.
    // -------------------------------------------------------------------------------------------------
    private void EnableScanControls()
    {
        bool enable = !m_receiver.IsScanning;

        m_rbSurface.Enabled = enable;
        m_rbSurfaceAndBoundary.Enabled = enable;
        m_rbSharpEdge.Enabled = enable;

        bool useRTM = m_cbRTQM.Checked;
        bool isSharpEdge = m_rbSharpEdge.Checked;
        bool isCreatingNewDataObject = m_cbSurface.SelectedIndex == 0;

        m_cbSurface.Enabled = enable && !isSharpEdge;
        m_tbSurfaceName.Enabled = enable && !isSharpEdge && isCreatingNewDataObject;
        m_cbRTQM.Enabled = enable && !isSharpEdge && isCreatingNewDataObject;
        m_lbDataType.Enabled = enable && !isSharpEdge && useRTM;
        m_rbPointCloud.Enabled = enable && !isSharpEdge && useRTM;
        m_rbPolygonal.Enabled  = enable && !isSharpEdge && useRTM;

        m_cbTestMode.Enabled = enable;
        m_pbOptions.Enabled = enable;
        m_pbClose.Enabled = enable;

        bool isBoundary = m_rbSurfaceAndBoundary.Checked;
        isCreatingNewDataObject = m_cbBoundary.SelectedIndex == 0;
        m_cbBoundary.Enabled = enable && ( isBoundary || isSharpEdge );
        m_tbBoundaryName.Enabled = enable && ( isBoundary || isSharpEdge ) && isCreatingNewDataObject;

        m_cbComparison.Enabled = enable && !isSharpEdge && !useRTM;

        bool clippingPlane = m_cbClippingPlane.Checked;
        m_cbClippingPlane.Enabled = enable && !isSharpEdge;
        m_tbClippingPlane.Enabled = enable && !isSharpEdge && clippingPlane;
        m_pbClippingPlane.Enabled = enable && !isSharpEdge && clippingPlane;

        m_lbProfile.Enabled = enable;
        m_cbProfile.Enabled = enable;
        m_pbSave.Enabled    = enable;
        m_pbDeleteProfile.Enabled  = enable;

        if ( enable )
        { 
            m_pbStart.Text = "Start Scan";
        }
        else
        {
            m_pbStart.Text = "End Scan";
        }
    }

    // =================================================================================================
    //   Event-handler called when the Clipping plane checkbox changes. The new value is sent to the
    // application and the dialog is updated.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbClippingPlaneCheckedChanged( object sender, EventArgs e )
    {
        m_host.ValueSet( Consts.CMD_CLIPPING_PLANE, m_cbClippingPlane.Checked, true, false );

        EnableScanControls();
    }

    // =================================================================================================
    //   Event-handler called when the Real-time comparison checkbox changes. The new value is written
    // in the corresponding setting.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbComparisonCheckedChanged( object sender, EventArgs e )
    {
        m_settings.IMIRealTimeInspection = m_cbComparison.Checked;
    }

    // =================================================================================================
    //   Event-handler called when the selection in the scanning profile combobox changes. The new
    // selection is sent to the application.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbProfileSelectedIndexChanged( object sender, EventArgs e )
    {
        // When synchronizing the combobox with the profile list reported by the application,
        // the selected index may change more than once. We want to avoid calling the command
        // with temporary selections.
        if ( !m_synchronizingProfiles )
        {
            int selection = m_cbProfile.SelectedIndex;

            if ( ( selection >= 0 ) && ( selection < m_profileCmdArgNames.Count ) )
            {
                m_host.ExecuteCommand( IM.Utils.CommandBuild( "DIGITIZE DEVICE SCAN PROFILE",
                                                              IM.Utils.Quote( m_profileCmdArgNames[ selection ] ) ),
                                       true, true, true );
            }
            else
            {
                System.Diagnostics.Debug.Assert( false );
            }
        }
    }

    // =================================================================================================
    //   Event-handler called when the Real-time quality meshing checkbox changes. The new value is
    // sent to the receiver.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbRTQMCheckedChanged( object sender, EventArgs e )
    {
        m_receiver.EnableRealTimeMeshing( m_cbRTQM.Checked );
        m_cbComparison.Checked = false;
    }

    // =================================================================================================
    //   Event-handler called when the selection in the Boundary object name combobox changes.
    // If the selection is "Create new" we make sure the name used is unique and the textbox is enabled.
    // Otherwise we set the name in the application to the current selection and disable the textbox. 
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbBoundarySelectedIndexChanged( object sender, EventArgs e )
    {
        string name;

        if ( m_cbBoundary.SelectedIndex == 0 )
        {
            m_tbBoundaryName.Enabled = true;

            name = m_host.ValueStrGet( "CONFIG MODIFY DEFAULT_NAME BOUNDARY_SCAN GET", "", false );
            name = m_host.ObtainUniqueName( name );
        }
        else if ( m_cbBoundary.SelectedItem != null )
        {
            m_tbBoundaryName.Enabled = false;

            name = m_cbBoundary.SelectedItem.ToString();
        }
        else
        {
            return;
        }

        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_BOUNDARY_OBJECT_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when the selection in the Surface object name combobox changes.
    // If the selection is "Create new" we make sure the name used is unique and the textbox is enabled.
    // Otherwise we set the name in the application to the current selection and disable the textbox. 
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbSurfaceSelectedIndexChanged( object sender, EventArgs e )
    {
        string name;

        if ( m_cbSurface.SelectedIndex == 0 )
        {
            m_tbSurfaceName.Enabled = true;

            name = m_host.ValueStrGet( "CONFIG MODIFY DEFAULT_NAME SURFACE_SCAN GET", "", false );
            name = m_host.ObtainUniqueName( name );
        }
        else if ( m_cbSurface.SelectedItem != null )
        {
            m_tbSurfaceName.Enabled = false;

            name = m_cbSurface.SelectedItem.ToString();
        }
        else
        {
            return;
        }

        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_OBJECT_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when the Test mode checkbox changes. We write the current value in the
    // corresponding setting.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void cbTestModeCheckedChanged( object sender, EventArgs e )
    {
        m_settings.TestMode = m_cbTestMode.Checked;
    }

    // =================================================================================================
    //   Event-handler called when the Clipping plane push button is clicked. We call the command to
    // define the clipping plane which will show an application dialog.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbClippingPlaneClick( object sender, EventArgs e )
    {
        m_host.ExecuteCommand( "DIGITIZE CLIPPING_PLANE DEFINE SHOW_WINDOW", true, true, true );
    }

    // =================================================================================================
    //   Event-handler called when the Close push button is clicked. Simply closes the window.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbCloseClick( object sender, EventArgs e )
    {
        Close();
    }

    // =================================================================================================
    //   Event-handler called when the Delete (profile) push button is clicked. We call the command
    // that performs the deletion (the application will display a confirmation message).
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbDeleteProfileClick( object sender, EventArgs e )
    {
        int selection = m_cbProfile.SelectedIndex;

        if ( ( selection >= 0 ) && ( selection < m_profileCmdArgNames.Count ) )
        {
            m_host.ExecuteCommand( IM.Utils.CommandBuild( "DIGITIZE DEVICE SCAN PROFILE DELETE",
                                   IM.Utils.Quote( m_profileCmdArgNames[ selection ] ) ),
                                   true, true, true );
        }
        else
        {
            System.Diagnostics.Debug.Assert( false );
        }
    }

    // =================================================================================================
    //   Event-handler called when the Options push button is clicked. We simply show the Options
    // dialog box.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbOptionsClick( object sender, EventArgs e )
    {
        CDlgOptions dialog = new CDlgOptions( m_host );

        dialog.ShowDialog( this );
    }

    // =================================================================================================
    //   Event-handler called when the Save (profile) push button is clicked. Show the save dialog.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbSaveClick( object sender, EventArgs e )
    {
        CDlgSaveAsProfile dialog = new CDlgSaveAsProfile( m_receiver );

        dialog.ShowDialog( this );
    }

    // =================================================================================================
    //   Event-handler called when the Start/End Scan push button is clicked. If scanning is started
    // the command to end the scan will be called. Otherwise the command to start scanning will be
    // called.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbStartClick( object sender, EventArgs e )
    {
        if ( m_receiver.IsScanning )
        { 
            m_receiver.ScanEndRequest();
        }
        else
        { 
            m_host.ExecuteCommand( "DIGITIZE DEVICE SCAN START", true, true, false );
        }

        EnableScanControls();
    }

    // =================================================================================================
    //   Event-handler called when the one of the RTQM data type radio buttons is selected. We call
    // the command to inform the application of the new selection.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void rbPolygonalCheckedChanged( object sender, EventArgs e )
    {
        string type = DATA_TYPE_POINT_CLOUD;

        if ( m_rbPolygonal.Checked )
        {
            type = DATA_TYPE_POLYGONAL;
        }

        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_RTQM_DATA_TYPE, IM.Utils.Quote( type ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when one of the Scan Type radio buttons is selected. We inform the
    // application of the new value and update the controls accordingly.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void rbScanTypeCheckedChanged( object sender, EventArgs e )
    {
        string scanTypeStr = "";

        if ( m_rbSurface.Checked )
        {
            scanTypeStr = SCAN_TYPE_SURFACE;
        }
        else if ( m_rbSurfaceAndBoundary.Checked )
        {
            scanTypeStr = SCAN_TYPE_BOUNDARY;
        }
        else if ( m_rbSharpEdge.Checked )
        {
            scanTypeStr = SCAN_TYPE_SHARP_EDGE;
        }
        else
        {
            System.Diagnostics.Debug.Assert( false );
        }

        m_host.ValueSet( Consts.CMD_SCAN_TYPE, IM.Utils.Quote( scanTypeStr ), true, false );

        EnableScanControls();
    }

    // =================================================================================================
    //   Event-handler called when the Boundary textbox loses focus. We send the object name to the
    // application.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void tbBoundaryNameLeave( object sender, EventArgs e )
    {
        string name = m_tbBoundaryName.Text;
        name = m_host.ObtainUniqueName( name );
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_BOUNDARY_OBJECT_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when the Surface textbox loses focus. We send the object name to the
    // application.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void tbSurfaceNameLeave( object sender, EventArgs e )
    {
        string name = m_tbSurfaceName.Text;
        name = m_host.ObtainUniqueName( name );
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_OBJECT_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when the window is moved. The new position is stored in settings.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void Moved( object sender, EventArgs e )
    {
        // We must update the settings when the form is moved only once it is visible. Otherwise
        // we will modify the setting before "Showned" is called and the initial position is set.
        if ( Visible )
        {
            m_settings.IMIWindowPositionX = Left;
            m_settings.IMIWindowPositionY = Top;
        }
    }

    // =================================================================================================
    //   Event-handler called when something happens in the receiver that may require refreshing the
    // dialog.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void ReceiverStateChanged( object sender, EventArgs e )
    {
        EnableScanControls();
    }

    // =================================================================================================
    //   Event-handler called when the window is first showned. The window is moved to its last saved
    // position.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void Showned( object sender, EventArgs e )
    {
        DesktopLocation = new Point( m_settings.IMIWindowPositionX,
                                     m_settings.IMIWindowPositionY );
    }

    // =================================================================================================
    //   Updates the dialog
    // -------------------------------------------------------------------------------------------------
    public void DialogUpdate()
    {
        switch( IMIScanTypeGet() )
        {
            case IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE:
                m_rbSurface.Checked = true;
                break;
            case IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE_AND_BOUNDARY:
                m_rbSurfaceAndBoundary.Checked = true;
                break;
            case IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE:
                m_rbSharpEdge.Checked = true;
                break;
            default:
                // Scan type not suppported by this example.
                System.Diagnostics.Debug.Assert( false );
                break;
        }

        // Get RTM activation state from the application because it may have changed
        bool? useRTM = m_host.ValueBoolGet( Consts.CMD_DIGITIZE_LINESCAN_SURFACE_RTQM_GET, false );
        if ( useRTM.HasValue )
        {
            m_cbRTQM.Checked = useRTM.Value;
            m_settings.IMIRealTimeMeshing = useRTM.Value;
        }
        bool? useclippingPlane =  m_host.ValueBoolGet( Consts.CMD_CLIPPING_PLANE + Consts.CMD_GET_SUFFIX, false ).Value;
        if ( useclippingPlane.HasValue )
        {
            m_cbClippingPlane.Checked = useclippingPlane.Value;
        }
        string clippingPlaneDateTime = "Undefined";
        bool? isClippingPlaneDefined = m_host.ValueBoolGet("DIGITIZE CLIPPING_PLANE DEFINED GET", false);
        if ( isClippingPlaneDefined.HasValue && isClippingPlaneDefined.Value )
        {
            clippingPlaneDateTime = m_host.ValueDateTimeGet( "DIGITIZE CLIPPING_PLANE DEFINED DATE_TIME GET", false );
        }
        m_tbClippingPlane.Text = clippingPlaneDateTime;

        string rtqmDataType    = m_host.ValueStrGet( Consts.CMD_RTQM_DATA_TYPE + Consts.CMD_GET_SUFFIX, "", false );
        bool   isPolModel      = rtqmDataType == DATA_TYPE_POLYGONAL;
        m_rbPointCloud.Checked = !isPolModel;
        m_rbPolygonal.Checked  = isPolModel;
            
        DataObjectsUpdate( m_tbSurfaceName,  m_cbSurface,  IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE );
        DataObjectsUpdate( m_tbBoundaryName, m_cbBoundary, IMPluginLib.EScanTypes.E_SCAN_TYPE_SHARP_EDGE );

        m_cbComparison.Checked = m_settings.IMIRealTimeInspection;
        m_cbTestMode.Checked   = m_settings.TestMode;

        EnableScanControls();
    }

    // =================================================================================================
    //   Update the state of "scanning profiles" related controls after a change.
    // -------------------------------------------------------------------------------------------------
    public void ProfilesControlUpdate()
    {
        List< string > profileDisplayNames;
        List< string > profileAdditionalInfos;
        string         currentProfile;

        m_receiver.ScanningProfilesGet( out m_profileCmdArgNames,
                                        out profileDisplayNames,
                                        out profileAdditionalInfos,
                                        out currentProfile );

        if ( m_profileCmdArgNames.Count != profileDisplayNames.Count )
        {
            System.Diagnostics.Debug.Assert( false );
            return;
        }

        List< string > items = new List< string >();

        for( int i=0; i < m_profileCmdArgNames.Count; ++i )
        {
            if ( profileDisplayNames[ i ].Length > 0 )
            {
                items.Add( profileDisplayNames[ i ] );
            }
            else
            {
                items.Add( m_profileCmdArgNames[ i ] );
            }
        }

        try
        {
            m_synchronizingProfiles = true;
            IM.Utils.ComboAndListSynchronize( m_cbProfile, items, currentProfile, -1 );
        }
        finally
        {
            m_synchronizingProfiles = false;
        }

        EnableScanControls();
    }
}

}
