// =================================================================================================
// Class describing a COM command
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    // =============================================================================
    // COM command class description implementation
    // A description and a name must at least be specified
    // Otherwise, only needed members require initialisation
    // -----------------------------------------------------------------------------
    public class CComCommandInfo
    {
        // =============================================================================
        // Constructor
        //
        // Parameter: name_    : Name 
        // Parameter: desc_    : Description 
        // -----------------------------------------------------------------------------
        public CComCommandInfo(string name_, string desc_)
        {
            m_name = name_;
            m_desc = desc_;
        }

        // =============================================================================
        // Copy constructor
        //
        // Parameter: info_ : Object to be copied
        // -----------------------------------------------------------------------------
        public CComCommandInfo(CComCommandInfo info_)
        {
            if (info_ != null)
            {
                m_name               = StrUtil.StrNonNull(info_.NameGet());
                m_desc               = StrUtil.StrNonNull(info_.DescGet());
                m_note               = StrUtil.StrNonNull(info_.NoteGet());
                m_menuLocation       = StrUtil.StrNonNull(info_.MenuLocationGet());
                m_menuDesc           = StrUtil.StrNonNull(info_.MenuDescGet());
                m_isObsolete         = info_.IsObsoleteGet();
                m_supersedingCommand = StrUtil.StrNonNull(info_.SupersedingCommandGet());

                // Copying old names
                uint nbNames = info_.DeprecatedNamesGetNb();
                for (uint iName = 0; iName < nbNames; iName++)
                {
                    DeprecatedNameAdd(StrUtil.StrNonNull(info_.DeprecatedNameGet(iName)));
                }

                // Copying parameters   
                CComCommandParameterEnum paramEnum = info_.ParameterEnumGet();
                if (paramEnum != null)
                {
                    IMPluginLib.IIMCommandParameter param = null;
                    int nbParams = paramEnum.ParamsGetNb();
                    for (int iParam = 0; iParam < nbParams; iParam++)
                    {
                        paramEnum.ParamGet(iParam, out param);
                        if (param != null)
                        {
                            m_parameterEnum.CommandParameterAdd(param);
                        }
                    }
                }
            }
        }

        // =============================================================================
        // Members access methods
        // -----------------------------------------------------------------------------
        #region Members access methods

        // Name
        public string NameGet()
        {
            return m_name;
        }
        public void NameSet(string name_)
        {
            m_name = StrUtil.StrNonNull(name_);
        }

        // Description 
        public string DescGet()
        {
            return m_desc;
        }
        public void DescSet(string desc_)
        {
            m_desc = StrUtil.StrNonNull(desc_);
        }

        // Note to be added to description
        public string NoteGet()
        {
            return m_note;
        }
        public void NoteSet(string note_)
        {
            m_note = StrUtil.StrNonNull(note_);
        }

        // Menu item location
        public string MenuLocationGet()
        {
            return m_menuLocation;
        }
        public void MenuLocationSet(string menuLocation_)
        {
            m_menuLocation = StrUtil.StrNonNull(menuLocation_);
        }

        // Menu item description
        // (if empty, command description is used)
        public string MenuDescGet()
        {
            return m_menuDesc;
        }
        public void MenuDescSet(string menuDesc_)
        {
            m_menuDesc = StrUtil.StrNonNull(menuDesc_);
        }

        // Deprecated names of the command
        // (as long as parameter list have not changed)
        public uint DeprecatedNamesGetNb()
        {
            return (uint)m_deprecatedNames.Count;
        }
        public string DeprecatedNameGet(uint index_)
        {
            if ( index_ < DeprecatedNamesGetNb() )
            {
                return m_deprecatedNames[(int)index_];
            }
            return string.Empty;
        }
        public void DeprecatedNameAdd(string deprecatedName_)
        {
            // Making sure we have a valid string
            if (!string.IsNullOrEmpty(deprecatedName_))
            {
                m_deprecatedNames.Add(deprecatedName_);
            }
        }

        // True if the command is obsolete
        public bool IsObsoleteGet()
        {
            return m_isObsolete;
        }
        public void IsObsoleteSet(bool isObsolete_)
        {
            m_isObsolete = isObsolete_;
        }

        // Indicate which command have replaced this obsolete command
        // (empty if no command replace this obsolete command)
        public string SupersedingCommandGet()
        {
            return m_supersedingCommand;
        }
        public void SupersedingCommandSet(string cmdName_)
        {
            m_supersedingCommand = StrUtil.StrNonNull(cmdName_);
        }

        // Enumeration of command parameters
        public CComCommandParameterEnum ParameterEnumGet()
        {
            return m_parameterEnum;

        }

        #endregion

        private string m_name;                                         // Name
        private string m_desc;                                         // Description
        private string m_note = string.Empty;                          // Note to be added to description
        private string m_menuLocation = string.Empty;                  // Menu item location
        private string m_menuDesc = string.Empty;                      // Menu item description
                                                                       // (if empty, command description is used)
        private bool   m_isObsolete;                                   // True if the command is obsolete
        private string m_supersedingCommand = string.Empty;            // Indicate which command have replaced this obsolete command
                                                                       // (empty if no command replace this obsolete command)

        private System.Collections.Generic.List<string> m_deprecatedNames = new System.Collections.Generic.List<string>();     // Deprecated names of the command
                                                                                                                               // (as long as parameter list have not changed)

        private CComCommandParameterEnum m_parameterEnum = new CComCommandParameterEnum();        // Enumeration of command parameters 
    }
}
