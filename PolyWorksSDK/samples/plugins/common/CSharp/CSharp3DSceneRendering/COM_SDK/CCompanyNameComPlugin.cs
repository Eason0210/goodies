// =================================================================================================
// CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2010 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharp3DSceneRendering
{
    // =============================================================================================
    // Plug-in's COM object interface used to connect to a PolyWorks module.
    // ---------------------------------------------------------------------------------------------
    [System.Runtime.InteropServices.ComVisible(true)]
    [System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)]
    [System.Runtime.InteropServices.Guid("3E3F6D14-53FC-46F7-A134-C6D55143EE35")]
    public class CCompanyNameComPlugin : IMPluginLib.IIMPlugin, IMPluginLib.IIMCommandEnum
    {
        // Make sure your plug-in name does not exceed 31 character
        private string m_pluginName = "CompanyName C# Rendering";

        private System.Collections.Generic.List<IMPluginLib.IIMCommand2> m_commands = new System.Collections.Generic.List<IMPluginLib.IIMCommand2>();

        // =========================================================================================
        // Adds MSCL commands to the commands vector member variable.
        // -----------------------------------------------------------------------------------------
        public void CommandsAdd()
        {
            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command a good name and a good description.
            IM.CComCommandInfo cmdInfoStart = new IM.CComCommandInfo( "COMPANY_NAME_CSHARP DRAW START", "Start drawing.");

            // TODO: Replace "CompanyName CSharp3DSceneRendering" by your company name
            cmdInfoStart.MenuLocationSet("CompanyName CSharp3DSceneRendering\\Start drawing");

            // Add the command to the command vector
            m_commands.Add( new CCmdCompanyName3DSceneRenderingStart( cmdInfoStart ) );

            // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command a good name and a good description.
            IM.CComCommandInfo cmdInfoStop = new IM.CComCommandInfo( "COMPANY_NAME_CSHARP DRAW STOP", "Stop drawing.");

            // TODO: Replace "CompanyName CSharp3DSceneRendering" by your company name
            cmdInfoStop.MenuLocationSet("CompanyName CSharp3DSceneRendering\\Stop drawing");

            // Add the command to the command vector
            m_commands.Add( new CCmdCompanyName3DSceneRenderingStop( cmdInfoStop ) );
        }

        // =========================================================================================
        // Releases any commands added in CommandsAdd.
        // -----------------------------------------------------------------------------------------
        public void CommandsRemove()
        {
            m_commands.Clear();
        }

        // =========================================================================================
        // ========================================= IIMPlugin =====================================
        #region IIMPlugin

        // =========================================================================================
        // Returns the plug-in's name.
        //
        // Return: Plug-in's name.
        // -----------------------------------------------------------------------------------------
        public string PlgNameGet()
        {
            return m_pluginName;
        }

        // =========================================================================================
        // Returns the plug-in's version in the form of major.minor.dot.
        //
        // Parameter: major_ : Major component of the plug-in's version
        // Parameter: minor_ : Minor component of the plug-in's version
        // Parameter: dot_   : Dot component of the plug-in's version
        //
        // -----------------------------------------------------------------------------------------
        public void PlgVersionGet(ref int major_, ref int minor_, ref int dot_)
        {
            major_ = 1;
            minor_ = 0;
            dot_ = 0;
        }

        // =========================================================================================
        // Called when the plug-in is loaded.
        //
        // Parameter: iIMHost_ : Host's application.
        //
        // Return: 1 if everything went well.
        //         0 if something went wrong.
        // -----------------------------------------------------------------------------------------
        public int Load(IMPluginLib.IIMHost iIMHost_)
        {
            if ( iIMHost_ == null )
            {
                return 0;
            }

            // 3D scene rendering functionalities are only supported in the PolyWorks|Inspector application.
            if ( !(iIMHost_ is IMInspectLib.IMInspect) )
            {
                System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMHost_);
                return 0;
            }

            bool canLoad = IMM.FnDotNetPlugin.DotNetPluginConnect( PlgNameGet(), 
                                                                   new IMM.DSDKVersionGet(Connection.SDKVersionGet), 
                                                                   new IMM.DInterfaceGet(Connection.PluginInterfaceGet) );

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMHost_);

            if ( canLoad ) 
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // =========================================================================================
        // Called when the plug-in is unloaded.
        //
        // Return: 1 if everything went well.
        //         0 if something went wrong.
        // -----------------------------------------------------------------------------------------
        public int Unload()
        {
            Functions.AnnotationsRemoveAll();
            Functions.DrawNodesRemoveAll();

            CommandsRemove();

            return 1;
        }

        #endregion

        // =========================================================================================
        // ====================================== IIMCommandEnum ===================================
        #region IIMCommandEnum

        // =========================================================================================
        // Returns the number of MSCL command's registered by this plug-in.  
        //
        // Return: Number of MSCL command's registered by this plug-in.
        // -----------------------------------------------------------------------------------------
        public int CmdsGetNb()
        {
            if (m_commands.Count == 0)
            {
                CommandsAdd();
            }

            return m_commands.Count;
        }

        // =========================================================================================
        // Returns a COM interface pointer to a MSCL command.
        //
        // Parameter: number_     : Index of the command to be returned
        // Parameter: iIMCommand_ : COM interface object.
        //
        // -----------------------------------------------------------------------------------------
        public void CmdGet(int number_, out IMPluginLib.IIMCommand iIMCommand_)
        {
            iIMCommand_ = null;

            if (number_ >= 0 && number_ < m_commands.Count)
            {
                iIMCommand_ = m_commands[number_];
            }
        }

        #endregion
    }
}
