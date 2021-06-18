// =================================================================================================
//   Small dialog to select a name to save a user scanning profile. Used by the "Save as"
// button in the main dialog.
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

partial class CDlgSaveAsProfile : Form
{
    private CReceiver m_receiver;

    // =================================================================================================
    //   Constructor used only by the designed.
    // -------------------------------------------------------------------------------------------------
    public CDlgSaveAsProfile()
    {
        InitializeComponent();
    }

    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : receiver_ : Access to the receiver.
    // -------------------------------------------------------------------------------------------------
    internal CDlgSaveAsProfile( CReceiver receiver_ )
    {
        InitializeComponent();

        m_receiver = receiver_;

        List< string > profileCmdArgNames;
        List< string > profileDisplayNames;
        List< string > profileAdditionalInfos;
        string         currentProfile;

        m_receiver.ScanningProfilesGet( out profileCmdArgNames,
                                        out profileDisplayNames,
                                        out profileAdditionalInfos,
                                        out currentProfile );

        if ( profileCmdArgNames.Count == profileDisplayNames.Count )
        {
            for( int i=0; i < profileCmdArgNames.Count; ++i )
            {
                // Display name is empty for user profile
                if ( profileDisplayNames[ i ].Length == 0 )
                {
                    m_cbUserProfile.Items.Add( profileCmdArgNames[ i ] );
                }
            }
        }
    }

    // =================================================================================================
    //   Event-handler for the Cancel button. Just closes the form.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbCancelClick( object sender, EventArgs e )
    {
        Close();
    }

    // =================================================================================================
    //   Event-handler for the OK button. Asks the receiver to save the profile with the selected name
    // and if this is a success, close the form.
    //
    // Parameter : sender : Not used
    // Parameter : e      : Not used
    // -------------------------------------------------------------------------------------------------
    private void pbOKClick( object sender, EventArgs e )
    {
        if ( m_receiver == null )
        {
            // This is not supposed to happen.
            System.Diagnostics.Debug.Assert( false );
            Close();
        }

        if ( m_receiver.UserScanningProfileSave( m_cbUserProfile.Text ) )
        {
            Close();
        }
    }
}

}
