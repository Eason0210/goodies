// =================================================================================================
//   CDlgInspect class and support classes for dialog interface example in PolyWorks|Inspector
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;

namespace CompanyNameCsPlanarScanner
{
internal partial class CDlgInspect : CDlgBase
{
    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgInspect()
    {
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : receiver_ : Access to the receiver.
    // -------------------------------------------------------------------------------------------------
    public CDlgInspect( CReceiver receiver_ ) : base( receiver_ )
    {
        InitializeComponent();
        this.m_internalLayout.RowCount = 2;
        this.m_internalLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
        this.m_internalLayout.RowStyles.Add(new System.Windows.Forms.RowStyle());
        this.m_internalLayout.Controls.Add(this.m_dataObjectSection, 0, 0);
        this.m_internalLayout.Controls.Add(this.m_parametersSection, 0, 1);
        PerformLayout();
        DialogUpdate();
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
    //   Updates the dialog
    // -------------------------------------------------------------------------------------------------
    public override void DialogUpdate()
    {
        bool? automaticViewpoint = m_host.ValueBoolGet( Consts.CMD_AUTO_VIEWPOINT_SET + Consts.CMD_GET_SUFFIX, false );
        if ( automaticViewpoint.HasValue )
        {   
            m_chkBoxAutomaticViewpoint.Checked = automaticViewpoint.Value;
        }
        m_chkBoxCreateNewDevicePosition.Checked = m_settings.CreateNewDevicePositionOnScan;
        bool convertToPolygonal = m_settings.IMIConvertToPolygonal;
        m_rdBtnPointcloud.Checked = !convertToPolygonal;
        m_rdBtnPolygonalModel.Checked = convertToPolygonal;

        DataObjectsUpdate( m_txtScanName, IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE );
        EnableScanControls();
    }

    // =================================================================================================
    //   Event-handler called when the Create new device position on scan checkbox changes. 
    // Corresponding setting is updated.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void m_chkBoxCreateNewDevicePosition_CheckedChanged( object sender, EventArgs e )
    {
        m_settings.CreateNewDevicePositionOnScan = m_chkBoxCreateNewDevicePosition.Checked;
    }
	
    // =================================================================================================
    //   Event-handler called when the Start/End Scan push button is clicked. If scanning is started
    // the command to end the scan will be called. Otherwise the command to start scanning will be
    // called.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void m_btnScan_Click( object sender, EventArgs e )
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
    //   Update the enabled state of all controls according to current status.
    // -------------------------------------------------------------------------------------------------
    protected override void EnableScanControls()
    {
        bool enable = !m_receiver.IsScanning;
        m_rdBtnPointcloud.Enabled = enable;
        m_rdBtnPolygonalModel.Enabled = enable;
        m_txtScanName.Enabled = enable;
        m_chkBoxAutomaticViewpoint.Enabled = enable;
        m_chkBoxCreateNewDevicePosition.Enabled = enable;
        SetScanBtnLabel( enable );
    }

    // =================================================================================================
    //   Event-handler called when the Automatic viewpoint checkbox changes. We call a command that
    // changes corresponding application setting.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void chkBoxAutomaticViewpoint_CheckedChanged( object sender, EventArgs e )
    {
        m_host.ValueSet(Consts.CMD_AUTO_VIEWPOINT_SET, m_chkBoxAutomaticViewpoint.Checked, true, false);
    }

    // =================================================================================================
    //   Event-handler called when when the one of the data type radio buttons is selected. We call
    // the command to inform the application of the new selection.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void rdBtnPointcloud_CheckedChanged( object sender, EventArgs e )
    {
        m_settings.IMIConvertToPolygonal = false;
        // Get default name from application
        string name = m_host.ValueStrGet( Consts.CMD_SCAN_DEFAULT_SURFACE_OBJECT_NAME, "", false );
        if ( name == null )
        {
            return;
        }

        // Make sure object name is unique
        name = m_host.ObtainUniqueName( name );

        // Send new data object name to application
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_OBJECT_NAME, IM.Utils.Quote( name ) ), false, true, true );
    }

    // =================================================================================================
    //   Event-handler called when when the one of the data type radio buttons is selected. We call
    // the command to inform the application of the new selection.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void rdBtnPolygonalModel_CheckedChanged( object sender, EventArgs e )
    {
        m_settings.IMIConvertToPolygonal = true;

        // Get default name from application
        string name = m_host.ValueStrGet( Consts.CMD_SCAN_DEFAULT_SURFACE_OBJECT_NAME, "", false );
        if (name == null)
        {
            return;
        }

        // Make sure object name is unique
        name = m_host.ObtainUniqueName( name );

        // Send new data object name to application
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_OBJECT_NAME, IM.Utils.Quote( name ) ), false, true, true );
    }
        
    // =================================================================================================
    //   Event-handler called when the Surface textbox loses focus. We send the object name to the
    // application.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void txtScanName_Leave( object sender, EventArgs e )
    {
        string name = m_txtScanName.Text;
        name = m_host.ObtainUniqueName( name );
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_OBJECT_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }
        
    // =================================================================================================
    //   Event-handler called when the window is moved. The new position is stored in settings.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected override void Moved( object sender, EventArgs e )
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
    //   Event-handler called when the window is first showned. The window is moved to its last saved
    // position.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected override void Showned( object sender, EventArgs e )
    {
        DesktopLocation = new System.Drawing.Point(m_settings.IMIWindowPositionX, m_settings.IMIWindowPositionY);
    }
}
}