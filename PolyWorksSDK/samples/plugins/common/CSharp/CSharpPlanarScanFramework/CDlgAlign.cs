// =================================================================================================
//   CDlgAlign class and support classes for dialog interface example in PolyWorks|Align
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CompanyNameCsPlanarScanner
{
internal partial class CDlgAlign : CDlgBase
{
    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgAlign()
    {
        InitializeComponent();
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : receiver_ : Access to the receiver.
    // -------------------------------------------------------------------------------------------------
    public CDlgAlign( CReceiver receiver_ ) : base( receiver_ )
    {
        InitializeComponent();
        m_internalLayout.Controls.Add( m_mainDlgSection );
        PerformLayout();
        DialogUpdate();
    }

    // =================================================================================================
    //   Updates the dialog
    // -------------------------------------------------------------------------------------------------
    public override void DialogUpdate()
    {
        DataObjectsUpdate( m_txtScanName, IMPluginLib.EScanTypes.E_SCAN_TYPE_SURFACE );
        // Display number of points
        m_txtlNbPts.Text = m_receiver.NbPointsRecorded.ToString();
        EnableScanControls();
    }

    // =================================================================================================
    //   Update the enabled state of all controls according to current status.
    // -------------------------------------------------------------------------------------------------
    protected override void EnableScanControls()
    {
        bool enable = !m_receiver.IsScanning;
        m_txtScanName.Enabled = enable;
        m_lblNbPts.Enabled = false;
        m_btnOption.Enabled = enable;
        SetScanBtnLabel(enable);
    }

    // =================================================================================================
    //   Event-handler called when the option push button is clicked. show the dialog window
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void m_btnOption_Click( object sender, System.EventArgs e )
    {
        CDlgOptions dialog = new CDlgOptions( m_host, m_settings );
        dialog.ShowDialog( this );
    }

    // =================================================================================================
    //   Event-handler called when the Surface textbox loses focus. We send the object name to the
    // application.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void txtScanName_Leave( object sender, System.EventArgs e )
    {
        string name = m_txtScanName.Text;
        name = m_host.ObtainUniqueName( name );
        m_host.ExecuteCommand( IM.Utils.CommandBuild( Consts.CMD_SCAN_SURFACE_IMAGE_NAME, IM.Utils.Quote( name ) ), true, false, true );
    }

    // =================================================================================================
    //   Event-handler called when the window is moved. The new position is stored in settings.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected override void Moved( object sender, System.EventArgs e )
    {
        // We must update the settings when the form is moved only once it is visible. Otherwise
        // we will modify the setting before "Showned" is called and the initial position is set.
        if ( Visible )
        {
            m_settings.IMAWindowPositionX = Left;
            m_settings.IMAWindowPositionY = Top;
        }
    }

    // =================================================================================================
    //   Event-handler called when the window is first showned. The window is moved to its last saved
    // position.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected override void Showned( object sender, System.EventArgs e )
    {
        DesktopLocation = new System.Drawing.Point( m_settings.IMAWindowPositionX,
                                                    m_settings.IMAWindowPositionY );
    }
}
}
