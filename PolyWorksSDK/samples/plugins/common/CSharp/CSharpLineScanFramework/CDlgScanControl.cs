// =================================================================================================
//   CDlgScanControl class
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
//   This class implements a very simple dialog with only 2 push buttons. This dialog is shown
// by the SDK stub while scanning is active. It simulates the 2 buttons that are on typical
// scanning devices. One button allows the user to start sending data (PassStart) and stop sending
// data (PassEnd). The other button allows the device to request a ScanEnd (equivalent to clicking
// the "End Scan" button in the main dialog.
//
// TODO : Remove this class in a real plug-in, it is only for simulation for the example.
// -------------------------------------------------------------------------------------------------
public partial class CDlgScanControl : Form
{
    private bool m_passIsStarted    = false;
    // Int instead of bool to use with Interlocked.
    private int  m_endScanRequested = 0;

    public CDlgScanControl()
    {
        InitializeComponent();
    }

    public bool PassIsStarted
    {
        get { return m_passIsStarted; }
    }

    public bool EndScanRequested
    {
        // This value is "clear on read" so that the signal is received only once by the stub.
        get { return System.Threading.Interlocked.Exchange( ref m_endScanRequested, 0 ) != 0; }
    }

    private void PassIsStartedSet( bool newValue_ )
    {
        m_passIsStarted = newValue_;

        m_pbPass.Text = m_passIsStarted ? "End Pass" : "Start Pass";
    }

    private void pbPassClick( object sender, EventArgs e )
    {
        PassIsStartedSet( !m_passIsStarted );
    }

    private void pbEndClick( object sender, EventArgs e )
    {
        System.Threading.Interlocked.Increment( ref m_endScanRequested );
    }

    private void FormVisibleChanged( object sender, EventArgs e )
    {
        if ( Visible )
        {
            PassIsStartedSet( false );
            System.Threading.Interlocked.Exchange( ref m_endScanRequested, 0 );
        }
    }
}

}
