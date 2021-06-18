// =================================================================================================
//   Logging diagnostics information
//
// Copyright © InnovMetric Software Inc. 2018 All Rights Reserved
// -------------------------------------------------------------------------------------------------

namespace IM
{

// =================================================================================================
//   Dummy class for static diagnostics utility functions.
// -------------------------------------------------------------------------------------------------
class Diagnostics
{
    private static bool m_diagnosticActive = false;

    // =================================================================================================
    //  Verify and display if diagnostics are activated when plug-in is loaded
    // -------------------------------------------------------------------------------------------------
    public static void DiagnosticConfigurationUpdate()
    {
        string pluginsInDiagnostic = System.Environment.GetEnvironmentVariable( "PW_PLUGIN_DIAGNOSTICS" );

        // Can happen when diagnostics is not activated on any plug-in.
        if ( pluginsInDiagnostic == null )
        {
            return;
        }

        string pathAndName       = System.Reflection.Assembly.GetExecutingAssembly().Location;
        string pluginProductName = System.Diagnostics.FileVersionInfo.GetVersionInfo( pathAndName ).ProductName;

        string[] splittedPlugins = pluginsInDiagnostic.Split( ';' );

        foreach( string pluginName in splittedPlugins )
        {
            if ( pluginName == pluginProductName )
            {
                m_diagnosticActive = true;
                break;
            }
        }

        if ( m_diagnosticActive )
        {
            System.Windows.Forms.MessageBox.Show( "Diagnostics are activated for this plug-in.\n\nDiagnostics can be deactivated on the Plug-ins page of the Workspace Manager options.",
                                                  "Diagnostics" );
        }
    }

    // TODO: Once m_diagnosticActive is "computed", you can add functions here to perform
    //       diagnostic information logging in a way/format that is convenient for you.
}

}
