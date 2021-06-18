// =================================================================================================
// Implementation of the class describing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    // =================================================================================
    // COM command parameter class description implementation
    // A description, a direction and a type must at least be specified
    // Otherwise, only needed members require initialisation
    // ---------------------------------------------------------------------------------
    public class CComCommandParameterInfoImpl
    {
        // =============================================================================
        // Constructor
        //
        // Parameter: desc_ : Description
        // Parameter: dir_  : Direction
        // Parameter: type_ : Type
        // -----------------------------------------------------------------------------
        public CComCommandParameterInfoImpl(string desc_, 
                                            IMPluginLib.EParameterDirection dir_, 
                                            IMPluginLib.EParameterType type_)
        {
            m_desc = desc_;
            m_dir  = dir_;
            m_type = type_;
        }

        // =============================================================================
        // Copy constructor
        //
        // Parameter: info_ : Object to be copied
        // -----------------------------------------------------------------------------
        public CComCommandParameterInfoImpl(CComCommandParameterInfoImpl info_)
        {
            if (info_ != null)
            {
                m_desc                  = info_.m_desc;
                m_values                = info_.m_values;
                m_dir                   = info_.m_dir;
                m_type                  = info_.m_type;
                m_hasDoubleDefaultValue = info_.m_hasDoubleDefaultValue;
                m_doubleDefaultValue    = info_.m_doubleDefaultValue;
                m_hasIntDefaultValue    = info_.m_hasIntDefaultValue;
                m_intDefaultValue       = info_.m_intDefaultValue;
                m_hasStringDefaultValue = info_.m_hasStringDefaultValue;
                m_stringDefaultValue    = info_.m_stringDefaultValue;
            }
        }

        public string                          m_desc;                              // Description 
        public string                          m_values = string.Empty;             // Possible values (in a string, separated by comas)
        public IMPluginLib.EParameterDirection m_dir;                               // Direction
        public IMPluginLib.EParameterType      m_type;                              // Type
        public bool                            m_hasDoubleDefaultValue;             // True if parameter have a default double value
        public double                          m_doubleDefaultValue;                // Default value for double parameter
        public bool                            m_hasIntDefaultValue;                // True if parameter have a default integer value
        public int                             m_intDefaultValue;                   // Default value for integer parameter
        public bool                            m_hasStringDefaultValue;             // True if parameter have a default string value
        public string                          m_stringDefaultValue = string.Empty; // Default value for string parameter
    }
}
