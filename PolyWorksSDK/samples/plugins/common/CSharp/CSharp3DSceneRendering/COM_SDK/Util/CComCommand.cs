// =================================================================================================
// Class representing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    // =============================================================================
    // Base class for a COM command
    // Method Execute2 must at least be redefined
    // If command parameters can be validated, ArgsTest should also be redefined
    // All other stuff is managed automatically based on CComCommandInfo content
    // This does not prevent any other method redefinition for particular needs
    //
    // Derive from IIMCommand2 
    // -----------------------------------------------------------------------------
    [System.Runtime.InteropServices.ComVisible(true)]
    [System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)]
    public abstract class CComCommand : IMPluginLib.IIMCommand2
    {
        /* *****************************************************************************
        *                            IIMCommand Interface
        * -------------------------------------------------------------------------- */
        #region IIMCommand

        // =============================================================================
        // See IIMCommand.CmdNameGet
        // -----------------------------------------------------------------------------
        public string CmdNameGet()
        {
            if (m_commandInfo != null)
            {
                return m_commandInfo.NameGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommand.CmdDescGet
        // -----------------------------------------------------------------------------
        public string CmdDescGet()
        {
            if (m_commandInfo != null)
            {
                return m_commandInfo.DescGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommand.Execute
        // -----------------------------------------------------------------------------
        public int Execute()
        {
            if (Execute2(null) == IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED)
            {
                return 1;
            }
            return 0;
        }

        // =============================================================================
        // See IIMCommand.MenuLocationGet
        // -----------------------------------------------------------------------------
        public string MenuLocationGet()
        {
            if (m_commandInfo != null)
            {
                return m_commandInfo.MenuLocationGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommand.MenuDescGet
        // -----------------------------------------------------------------------------
        public string MenuDescGet()
        {
            if (m_commandInfo != null)
            {
                // If a menu description exist, we take it, otherwise, command description is used
                string menuDesc = StrUtil.StrNonNull(m_commandInfo.MenuDescGet());
                if (!string.IsNullOrEmpty(menuDesc))
                {
                    return menuDesc;
                }
                return m_commandInfo.DescGet();
            }
            return string.Empty;
        }

        #endregion

        /* *****************************************************************************
        *                            IIMCommand2 Interface
        * -------------------------------------------------------------------------- */
        #region IIMCommand2

        // =============================================================================
        // See IIMCommand2.ArgsTest
        //
        // A simple check for argument count corresponding to parameter count is performed here
        // -----------------------------------------------------------------------------
        public virtual IMPluginLib.ECommandReturnCodes ArgsTest(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_)
        {
            if (iIMCommandArgumentEnum_ != null)
            {
                int nbArgs = iIMCommandArgumentEnum_.ArgsGetNb();

                int nbParams = m_commandInfo.ParameterEnumGet().ParamsGetNb();

                if(nbArgs == nbParams)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);
                    return IMPluginLib.ECommandReturnCodes.E_CMD_SUCCEEDED;
                }
            }
            System.Runtime.InteropServices.Marshal.ReleaseComObject(iIMCommandArgumentEnum_);
            return IMPluginLib.ECommandReturnCodes.E_CMD_FAILED;
        }

        // =============================================================================
        // See IIMCommand2.CmdDeprecatedNamesGet
        // -----------------------------------------------------------------------------
        public void CmdDeprecatedNamesGet(ref System.Array names_)
        {
            uint nbNames = m_commandInfo.DeprecatedNamesGetNb();
            if (nbNames > 0)
            {
                System.Collections.ArrayList deprecatedNames = new System.Collections.ArrayList();
                for (uint iName = 0; iName < nbNames; iName++)
                {
                    string name = StrUtil.StrNonNull(m_commandInfo.DeprecatedNameGet(iName));
                    if (!string.IsNullOrEmpty(name))
                    {
                        deprecatedNames.Add(name);
                    }
                }

                if (deprecatedNames.Count > 0)
                {
                    names_ = new string[deprecatedNames.Count];
                    deprecatedNames.CopyTo(names_);
                }
            }
        }

        // =============================================================================
        // See IIMCommand.CmdIsObsolete
        // -----------------------------------------------------------------------------
        public void CmdIsObsolete(out bool pIsObsolete_, out string pSupersedingCmd_)
        {
            pIsObsolete_ = false;
            pSupersedingCmd_ = null;

            if (m_commandInfo != null)
            {
                pIsObsolete_ = m_commandInfo.IsObsoleteGet();

                if (pIsObsolete_ == true)
                {
                    pSupersedingCmd_ = m_commandInfo.SupersedingCommandGet();
                }
            }
        }

        // =============================================================================
        // See IIMCommand2.CmdNoteGet
        // -----------------------------------------------------------------------------
        public string CmdNoteGet()
        {
            if (m_commandInfo != null)
            {
                return m_commandInfo.NoteGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommand2.Execute2
        // -----------------------------------------------------------------------------
        public abstract IMPluginLib.ECommandReturnCodes Execute2(IMPluginLib.IIMCommandArgumentEnum iIMCommandArgumentEnum_);

        // =============================================================================
        // See IIMCommand2.ParamsGet
        // -----------------------------------------------------------------------------
        public void ParamsGet(out IMPluginLib.IIMCommandParameterEnum iIMCommandParameterEnum_)
        {
            iIMCommandParameterEnum_ = null;
            
            if(m_commandInfo != null)
            {
                iIMCommandParameterEnum_ = m_commandInfo.ParameterEnumGet();
            }
        }

        #endregion

        /* *****************************************************************************
        *              CComCommand specific methods
        * -------------------------------------------------------------------------- */
        #region CComCommand

        // =============================================================================
        // Constructor
        //
        // Parameter: info_ : Information used to construct command
        // -----------------------------------------------------------------------------
        public CComCommand(CComCommandInfo info_)
        {
            m_commandInfo = new CComCommandInfo(info_);
        }

        protected CComCommandInfo m_commandInfo = null;

        #endregion
    }
}
