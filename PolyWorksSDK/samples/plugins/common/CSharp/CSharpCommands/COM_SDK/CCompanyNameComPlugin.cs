// =================================================================================================
// CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2011 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace CSharpCommands
{
    // =============================================================================================
    //   Plug-in's COM object interface used to connect to a PolyWorks module.
    // ---------------------------------------------------------------------------------------------
    [System.Runtime.InteropServices.ComVisible(true)]
    [System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)]
    [System.Runtime.InteropServices.Guid("6C080F5C-A480-451A-8481-A1CAE104CED6")]
    public class CCompanyNameComPlugin : IMPluginLib.IIMPlugin, IMPluginLib.IIMCommandEnum
    {
        // Make sure your plug-in name does not exceed 31 character
        private string m_pluginName = "CompanyName CSharpCommands";

        private System.Collections.Generic.List<IMPluginLib.IIMCommand2> m_commands = new System.Collections.Generic.List<IMPluginLib.IIMCommand2>();

        // =========================================================================================
        // Adds MSCL commands to the commands vector member variable.
        // -----------------------------------------------------------------------------------------
        public void CommandsAdd()
        {
            // MENU command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfo = new IM.CComCommandInfo("COMPANY_NAME_CSHARP COMMAND_ACTION", 
                                                                    "Command action description.");

                // TODO: Replace "CompanyName CSharpCommands" by your company name
                cmdInfo.MenuLocationSet("CompanyName CSharpCommands\\Menu Item Action Name");

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameAction(cmdInfo));
            }

            // DOUBLE setting value SET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoDoubleValueSet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP DOUBLE_SETTING", 
                                                                                  "Sets a double value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("Double setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE);

                cmdInfoDoubleValueSet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameDoubleSet(cmdInfoDoubleValueSet));
            }

            // DOUBLE setting value GET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoDoubleValueGet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP DOUBLE_SETTING GET", 
                                                                                  "Gets a double value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("Double setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_DOUBLE);

                cmdInfoDoubleValueGet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameDoubleGet(cmdInfoDoubleValueGet));
            }

            // INTEGER setting value SET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoIntegerValueSet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP INTEGER_SETTING", 
                                                                                   "Sets an integer value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("Integer setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_INTEGER);

                cmdInfoIntegerValueSet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameIntegerSet(cmdInfoIntegerValueSet));
            }

            // INTEGER setting value GET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoIntegerValueGet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP INTEGER_SETTING GET", 
                                                                                   "Gets an integer value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("Double setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_INTEGER);

                cmdInfoIntegerValueGet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameIntegerGet(cmdInfoIntegerValueGet));
            }

            // STRING setting value SET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoStringValueSet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP STRING_SETTING", 
                                                                                  "Sets an string value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("String setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_IN, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_STRING);

                cmdInfoStringValueSet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameStringSet(cmdInfoStringValueSet));
            }

            // STRING setting value GET command

            {
                // TODO: Replace COMPANY_NAME_CSHARP by your company name, give the command good name and a good description.
                IM.CComCommandInfo cmdInfoStringValueGet = new IM.CComCommandInfo("COMPANY_NAME_CSHARP STRING_SETTING GET", 
                                                                                  "Gets an string value setting.");

                IM.CComCommandParameterInfo param01 = new IM.CComCommandParameterInfo("Double setting", 
                                                                                      IMPluginLib.EParameterDirection.E_PARAM_DIR_OUT, 
                                                                                      IMPluginLib.EParameterType.E_PARAM_TYPE_STRING);

                cmdInfoStringValueGet.ParameterEnumGet().CommandParameterAdd(new IM.CComCommandParameter(param01));

                // Add the command to the command vector
                m_commands.Add(new CCmdCompanyNameStringGet(cmdInfoStringValueGet));
            }
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
            if (iIMHost_ == null)
            {
                return 0;
            }

            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMHost_);

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
