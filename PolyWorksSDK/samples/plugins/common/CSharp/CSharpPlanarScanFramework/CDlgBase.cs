// =================================================================================================
//   Base class and support classes for shared dialog interface between PolyWorks|Inspector and 
//   PolyWorks|Align
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------
using System.Windows.Forms;

namespace CompanyNameCsPlanarScanner
{
internal partial class CDlgBase : Form
{
    protected IM.CIMHost m_host;
    protected CReceiver m_receiver;
    protected CSettings m_settings;

    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgBase()
    {
        InitializeComponent();
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : receiver_ : Access to the receiver.
    // -------------------------------------------------------------------------------------------------
    public CDlgBase( CReceiver receiver_ )
    {
        InitializeComponent();
        m_receiver = receiver_;
        m_host = receiver_.Host;
        m_settings = receiver_.Settings;
        m_receiver.StateChanged += ReceiverStateChanged;
    }

    // =================================================================================================
    //   Event-handler called when something happens in the receiver that may require refreshing the
    // dialog.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void ReceiverStateChanged( object sender, System.EventArgs e )
    {
        EnableScanControls();
    }

    // =================================================================================================
    //   Updates the dialog
    // -------------------------------------------------------------------------------------------------
    public virtual void DialogUpdate()
    {
    }

    // =================================================================================================
    //   Event-handler called when the Start/End Scan push button is clicked. If scanning is started
    // the command to end the scan will be called. Otherwise the command to start scanning will be
    // called.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void m_btnScan_Click( object sender, System.EventArgs e )
    {
        if (m_receiver.IsScanning)
        {
            m_receiver.ScanEndRequest();
        }
        else
        {
            if (m_host.HostApplication == IM.EHostApplication.IMINSPECT && m_settings.CreateNewDevicePositionOnScan )
            {
                m_receiver.CreateNewDevicePositionIfNeeded( true );
            }
            m_host.ExecuteCommand( "DIGITIZE DEVICE SCAN START", true, true, false );
        }
        EnableScanControls();
    }

    // =================================================================================================
    //   Update the enabled state of all controls according to current status.
    // -------------------------------------------------------------------------------------------------
    protected virtual void EnableScanControls()
    {
    }

    // =================================================================================================
    //   Event-handler called when the window is moved. The new position is stored in settings.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected virtual void Moved( object sender, System.EventArgs e )
    {
    }

    // =================================================================================================
    //   Event-handler called when the window is first showned. The window is moved to its last saved
    // position.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    protected virtual void Showned( object sender, System.EventArgs e )
    {
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
    protected void DataObjectsUpdate( TextBox name_, IMPluginLib.EScanTypes scanType_ )
    {
        System.Collections.Generic.List< string > names;

        // Get the application Data Object names
        string currentChoice = m_receiver.ScanningObjectsGet( scanType_, out names );

        names.Insert( 0, "(Create New)" );

        name_.Text = currentChoice;
    }

    // =================================================================================================
    //   Update the label of start/end scan button
    // -------------------------------------------------------------------------------------------------
    protected void SetScanBtnLabel( bool scanIsEnabled_ )
    {
        if (scanIsEnabled_)
        {
            m_btnScan.Text = "Start Scan";
        }
        else
        {
            m_btnScan.Text = "End Scan";
        }
    }

    // =================================================================================================
    //   Event-handler called when the close push button is clicked. Close the dialog
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void m_btnClose_Click( object sender, System.EventArgs e )
    {
        Close();
    }
}
}