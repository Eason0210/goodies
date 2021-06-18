// =================================================================================================
// Class describing a COM command parameter
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
    public class CComCommandParameterInfo
    {
        // =============================================================================
        // Constructor
        //
        // Parameter: desc_ : Description
        // Parameter: dir_  : Direction
        // Parameter: type_ : Type
        // -----------------------------------------------------------------------------
        public CComCommandParameterInfo(string desc_, 
                                        IMPluginLib.EParameterDirection dir_, 
                                        IMPluginLib.EParameterType type_)
        {
            m_impl = new CComCommandParameterInfoImpl(desc_, dir_, type_);
        }

        // =============================================================================
        // Copy constructor
        //
        // Parameter: info_ : Object to be copied
        // -----------------------------------------------------------------------------
        public CComCommandParameterInfo(CComCommandParameterInfo info_)
        {
            if (info_ != null)
            {
                m_impl = new CComCommandParameterInfoImpl(info_.DescGet(), 
                                                          info_.DirGet(), 
                                                          info_.TypeGet());
                ValuesSet(info_.ValuesGet());
                HasDoubleDefaultValueSet(info_.HasDoubleDefaultValueGet());
                DoubleDefaultValueSet(info_.DoubleDefaultValueGet());
                HasIntDefaultValueSet(info_.HasIntDefaultValueGet());
                IntDefaultValueSet(info_.IntDefaultValueGet());
                HasStringDefaultValueSet(info_.HasStringDefaultValueGet());
                StringDefaultValueSet(info_.StringDefaultValueGet());
            }
        }

        // ==============================================================================
        // Members access methods
        // ------------------------------------------------------------------------------
        #region Member access methods

        // Description 
        public string DescGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_desc;
            }
            return string.Empty;
        }
        public void DescSet(string desc_)
        {
            if (m_impl != null)
            {
                m_impl.m_desc = StrUtil.StrNonNull(desc_);
            }
        }

        // Possible values (in a string, separated by comas)
        public string ValuesGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_values;
            }
            return string.Empty;
        }
        public void ValuesSet(string values_)
        {
            if (m_impl != null)
            {
                m_impl.m_values = StrUtil.StrNonNull(values_);
            }
        }

        // Direction
        public IMPluginLib.EParameterDirection DirGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_dir;
            }
            return 0;
        }
        public void DirSet(IMPluginLib.EParameterDirection dir_)
        {
            if (m_impl != null)
            {
                m_impl.m_dir = dir_;
            }
        }

        // Type
        public IMPluginLib.EParameterType TypeGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_type;
            }
            return 0;
        }
        public void TypeSet(IMPluginLib.EParameterType type_)
        {
            if (m_impl != null)
            {
                m_impl.m_type = type_;
            }
        }

        // True if parameter have a default double value
        public bool HasDoubleDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_hasDoubleDefaultValue;
            }
            return false;
        }
        public void HasDoubleDefaultValueSet(bool hasValue_)
        {
            if (m_impl != null)
            {
                m_impl.m_hasDoubleDefaultValue = hasValue_;
            }
        }

        // Default value for double parameter
        public double DoubleDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_doubleDefaultValue;
            }
            return 0.0;
        }
        public void DoubleDefaultValueSet(double value_)
        {
            if (m_impl != null)
            {
                m_impl.m_doubleDefaultValue = value_;
            }
        }

        // True if parameter have a default integer value
        public bool HasIntDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_hasIntDefaultValue;
            }
            return false;
        }
        public void HasIntDefaultValueSet(bool hasValue_)
        {
            if (m_impl != null)
            {
                m_impl.m_hasIntDefaultValue = hasValue_;
            }
        }

        // Default value for integer parameter
        public int IntDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_intDefaultValue;
            }
            return 0;
        }
        public void IntDefaultValueSet(int value_)
        {
            if (m_impl != null)
            {
                m_impl.m_intDefaultValue = value_;
            }
        }

        // True if parameter have a default string value
        public bool HasStringDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_hasStringDefaultValue;
            }
            return false;
        }
        public void HasStringDefaultValueSet(bool hasValue_)
        {
            if (m_impl != null)
            {
                m_impl.m_hasStringDefaultValue = hasValue_;
            }
        }

        // Default value for string parameter
        public string StringDefaultValueGet()
        {
            if (m_impl != null)
            {
                return m_impl.m_stringDefaultValue;
            }
            return string.Empty;
        }
        public void StringDefaultValueSet(string value_)
        {
            if (m_impl != null)
            {
                m_impl.m_stringDefaultValue = StrUtil.StrNonNull(value_);
            }
        }

        #endregion

        private CComCommandParameterInfoImpl m_impl = null;
    }
}
