// =================================================================================================
// CInnovPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharpBasic
{
    // =============================================================================================
    //   Plug-in's COM object interface used to connect to a PolyWorks module.
    // ---------------------------------------------------------------------------------------------
    [ System.Runtime.InteropServices.ComVisible( true ) ]
    [ System.Runtime.InteropServices.ClassInterface( System.Runtime.InteropServices.ClassInterfaceType.None ) ]
    [ System.Runtime.InteropServices.Guid( "941D520B-F95C-487F-BC20-5566D76153BF" ) ]
public class CInnovPlugin : IMPluginLib.IIMPlugin, IMPluginLib.IIMCommand, IMPluginLib.IIMSettings
    {
#region IIMPlugin

        // =========================================================================================
        // ========================================= IIMPlugin =====================================

        // =========================================================================================
        // Returns the plug-in's name.
        //
        // Return: Plug-in's name.
        // -----------------------------------------------------------------------------------------
        public string PlgNameGet()
        {
            // The name should not be longer than 31 characters
            return "CSharpBasic";
        }

        // =========================================================================================
        // Returns the plug-in's version in the form of major.minor.dot.
        //
        // Parameter: major_ : Major component of the plug-in's version
        // Parameter: minor_ : Minor component of the plug-in's version
        // Parameter: dot_   : Dot component of the plug-in's version
        // -----------------------------------------------------------------------------------------
        public void PlgVersionGet( ref int major_, ref int minor_, ref int dot_ )
        {
            major_ = 1;
            minor_ = 0;
            dot_   = 0;
        }

        // =========================================================================================
        // Called when the plug-in is loaded.
        //
        // Parameter: iIMHost_ : Host's application.
        //
        // Return: 1 if everything went well.
        //         0 if something went wrong.
        // -----------------------------------------------------------------------------------------
        public int Load( IMPluginLib.IIMHost iIMHost_ )
        {
            if (iIMHost_ == null)
            {
                return 0;
            }

            // Do nothing to accept all hosts (IMAlign, PolyWorks|Inspector, PolyWorks|Modeler, etc...)
            // or do the following to accept only specific hosts (PolyWorks|Inspector in this case)

            IMInspectLib.IMInspect imInspect = iIMHost_ as IMInspectLib.IMInspect;
            if (imInspect == null)
            {
                // Release the host
                System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMHost_);
                return 0;
            }

            // Obtain the command center interface
            IMInspectLib.IIMInspectProject imInspectProject = null;
            imInspect.ProjectGetCurrent(out imInspectProject);

            if (imInspectProject != null)
            {
                imInspectProject.CommandCenterCreate(out m_imCommandCenter);
                System.Runtime.InteropServices.Marshal.ReleaseComObject(imInspectProject);
                imInspectProject = null;
            }

            if (m_imCommandCenter == null)
            {
                // Release the host
                System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMHost_);
                return 0;
            }

            // Keep a reference to the host's application
            m_imHost = iIMHost_;

            return 1;
        }

        // =========================================================================================
        // Called when the plug-in is unloaded.
        //
        // Return: 1 if everything went well.
        //         0 if something went wrong.
        // -----------------------------------------------------------------------------------------
        public int Unload()
        {
            // Release the host
            System.Runtime.InteropServices.Marshal.ReleaseComObject(m_imHost);
            m_imHost = null;

            // Release the command center
            System.Runtime.InteropServices.Marshal.ReleaseComObject(m_imCommandCenter);
            m_imCommandCenter = null;

            return 1;
        }

#endregion

#region IIMCommand

        // =========================================================================================
        // ======================================== IIMCommand =====================================

        // =========================================================================================
        // See IIMCommand.CmdNameGet
        // -----------------------------------------------------------------------------------------
        public string CmdNameGet()
        {
            return "CSHARP_PLUGIN SHOW_MESSAGE";
        }

        // =========================================================================================
        // See IIMCommand.CmdDescGet
        // -----------------------------------------------------------------------------------------
        public string CmdDescGet()
        {
            return "Shows a message from the CSharp sample plug-in";
        }

        // =========================================================================================
        // See IIMCommand.Execute
        // -----------------------------------------------------------------------------------------
        public int Execute()
        {
            // Obtain the message center interface
            IMInspectLib.IIMMessageCenter imMessageCenter = m_imHost as IMInspectLib.IIMMessageCenter;

            // Obtain the sound center interface
            IMInspectLib.IIMSoundCenter imSoundCenter = m_imHost as IMInspectLib.IIMSoundCenter;
            
            if ( imMessageCenter == null || imSoundCenter == null )
            {
                return 0;
            }

            // Display a message using IMInspectLib.IIMMessageCenter COM interface
            imMessageCenter.MessageBox(IMInspectLib.EMessageTypes.E_MESSAGE_TYPE_INFORMATION,
                                          "CSharp sample plug-in command invoked",
                                          "", "CSharpBasic", 0, true, null, 0);

            // Play a sound using IMInspectLib.IIMSoundCenter COM interface
            imSoundCenter.Play("Error", false);

            // Call MSCL commands using IMInspectLib.IIMCommandCenter COM interface
            ExecuteCommandOnApp("MACRO PAUSE( \"Message\", \"Check Command History\" )");
            ExecuteCommandOnApp("MACRO ECHO( \"Calling a command from the plug-in\" )");

            return 1;
        }

        // =========================================================================================
        // See IIMCommand.MenuLocationGet
        // -----------------------------------------------------------------------------------------
        public string MenuLocationGet()
        {
            return "CSharp sample\\Show Message";
        }

        // =========================================================================================
        // See IIMCommand.MenuDescGet
        // -----------------------------------------------------------------------------------------
        public string MenuDescGet()
        {
            return CmdDescGet();
        }

#endregion

#region IIMSettings

        // =========================================================================================
        // ======================================= IIMSettings =====================================

        // =========================================================================================
        // See IIMSettings.DoubleSettingsNbGet
        // -----------------------------------------------------------------------------------------
        public int DoubleSettingsNbGet()
        {
            return 1;
        }

        // =========================================================================================
        // See IIMSettings.DoubleSettingGet
        // -----------------------------------------------------------------------------------------
        public void DoubleSettingGet( int settingIndex_, ref string settingName_, ref double defaultValue_, ref bool isUserSpecific_, ref bool isHostSpecific_, ref bool isProjectSetting_ )
        {
            // settingIndex_ should be validated, and if more than one setting is available,
            // settingIndex_ should be used to give the info about the right setting

            settingName_ = "CSHARP_SAMPLE_DOUBLE_SETTING";

            defaultValue_ = 5264.463;

            // These are the recommended values for those parameters:
            isUserSpecific_ = true;     // True means the setting be saved in the user's config
                                        // False would save it globally for everyone that uses the same Polyworks installation

            isHostSpecific_ = false;    // False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                        // True would reserve a different value for each software

            // PolyWorks|Inspector only:
            isProjectSetting_ = false;  // False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                        // True would include it in PolyWorks|PolyWorks|Inspector application settings when saving the project
                                        // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work
        }

        // =========================================================================================
        // See IIMSettings.LongSettingsNbGet
        // -----------------------------------------------------------------------------------------
        public int LongSettingsNbGet()
        {
            return 1;
        }

        // =========================================================================================
        // See IIMSettings.LongSettingGet
        // -----------------------------------------------------------------------------------------
        public void LongSettingGet( int settingIndex_, ref string settingName_, ref int defaultValue_, ref bool isUserSpecific_, ref bool isHostSpecific_, ref bool isProjectSetting_ )
        {
            // settingIndex_ should be validated, and if more than one setting is available,
            // settingIndex_ should be used to give the info about the right setting

            settingName_ = "CSHARP_SAMPLE_LONG_SETTING";

            defaultValue_ = 867;

            // These are the recommended values for those parameters:
            isUserSpecific_ = true;     // True means the setting be saved in the user's config
                                        // False would save it globally for everyone that uses the same Polyworks installation

            isHostSpecific_ = false;    // False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                        // True would reserve a different value for each software

            // PolyWorks|Inspector only:
            isProjectSetting_ = false;  // False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                        // True would include it in PolyWorks|Inspector application settings when saving the project
                                        // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work
        }

        // =========================================================================================
        // See IIMSettings.StringSettingsNbGet
        // -----------------------------------------------------------------------------------------
        public int StringSettingsNbGet()
        {
            return 1;
        }

        // =========================================================================================
        // See IIMSettings.StringSettingGet
        // -----------------------------------------------------------------------------------------
        public void StringSettingGet( int settingIndex_, ref string settingName_, ref string defaultValue_, ref bool isUserSpecific_, ref bool isHostSpecific_, ref bool isProjectSetting_ )
        {
            // settingIndex_ should be validated, and if more than one setting is available,
            // settingIndex_ should be used to give the info about the right setting

            settingName_ = "CSHARP_SAMPLE_STRING_SETTING";

            defaultValue_ = "Sample string setting";

            // These are the recommended values for those parameters:
            isUserSpecific_ = true;     // True means the setting be saved in the user's config
                                        // False would save it globally for everyone that uses the same Polyworks installation


            isHostSpecific_ = false;    // False means the settings applies and is shared by any software that uses this plug-in (PolyWorks|Inspector, IMAlign, etc.)
                                        // True would reserve a different value for each software

            // PolyWorks|Inspector only:
            isProjectSetting_ = false;  // False means that the settings won't be saved in a PolyWorks|Inspector project along with other application settings
                                        // True would include it in PolyWorks|Inspector application settings when saving the project
                                        // NOTE: pIsHostSpecific_ and pIsProjectSetting_ must both be True for such a saving to work
        }

#endregion

        // =========================================================================================
        // ======================================== Utilities ======================================
        public bool ExecuteCommandOnApp( string command_ ) 
        {
            // Execute the command
            int returnValue = m_imCommandCenter.CommandExecute( command_ );

            if ( m_imCommandCenter.ReturnValueIsSuccess( returnValue ) == 1 )
            {
                return true;
            }

            return false;
        }

        private IMInspectLib.IIMCommandCenter m_imCommandCenter = null;
        private IMPluginLib.IIMHost m_imHost = null;
    }
}
