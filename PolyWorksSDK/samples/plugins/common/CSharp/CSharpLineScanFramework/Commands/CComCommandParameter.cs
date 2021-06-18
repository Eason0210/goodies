// =================================================================================================
// Class representing a COM command parameter
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    // =============================================================================
    // Classe used to implement a COM parameter
    //
    // Derive from IIMCommandParameter 
    // -----------------------------------------------------------------------------
    [System.Runtime.InteropServices.ComVisible(true)]
    [System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)]
    public class CComCommandParameter : IMPluginLib.IIMCommandParameter
    {
        /* *****************************************************************************
        *                           IIMCommandParameter Interface 
        * -------------------------------------------------------------------------- */
        #region IIMCommandParameter

        // =============================================================================
        // See IIMCommandParameter.ParamDescGet
        // -----------------------------------------------------------------------------
        public string ParamDescGet()
        {
            if (m_paramInfo != null)
            {
                return m_paramInfo.DescGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamPossibleValuesGet
        // -----------------------------------------------------------------------------
        public string ParamPossibleValuesGet()
        {
            if (m_paramInfo != null)
            {
                return m_paramInfo.ValuesGet();
            }
            return string.Empty;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamDirGet
        // -----------------------------------------------------------------------------
        public IMPluginLib.EParameterDirection ParamDirGet()
        {
            if (m_paramInfo != null)
            {
                return m_paramInfo.DirGet();
            }
            return 0;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamTypeGet
        // -----------------------------------------------------------------------------
        public IMPluginLib.EParameterType ParamTypeGet()
        {
            if (m_paramInfo != null)
            {
                return m_paramInfo.TypeGet();
            }
            return 0;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamDefaultDoubleValueGet
        // -----------------------------------------------------------------------------
        public int ParamDefaultDoubleValueGet(out double defaultValue_)
        {
            defaultValue_ = 0.0;
            if (m_paramInfo != null)
            {
                if (m_paramInfo.HasDoubleDefaultValueGet())
                {
                    defaultValue_ = m_paramInfo.DoubleDefaultValueGet();
                    return 1;
                }
            }
            return 0;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamDefaultIntValueGet
        // -----------------------------------------------------------------------------
        public int ParamDefaultIntValueGet(out int defaultValue_)
        {
            defaultValue_ = 0;
            if (m_paramInfo != null)
            {
                if (m_paramInfo.HasIntDefaultValueGet())
                {
                    defaultValue_ = m_paramInfo.IntDefaultValueGet();
                    return 1;
                }
            }
            return 0;
        }

        // =============================================================================
        // See IIMCommandParameter.ParamDefaultStringValueGet
        // -----------------------------------------------------------------------------
        public int ParamDefaultStringValueGet(out string defaultValue_)
        {
            defaultValue_ = string.Empty;
            if (m_paramInfo != null)
            {
                if (m_paramInfo.HasStringDefaultValueGet())
                {
                    defaultValue_ = m_paramInfo.StringDefaultValueGet();
                    return 1;
                }
            }
            return 0;
        }

        #endregion

        /* *****************************************************************************
         *              CComCommandParameter specific methods
        * -------------------------------------------------------------------------- */
        #region CComCommandParameter

        // =============================================================================
        // Constructor
        //
        // Parameter: info_ : Information used to construct parameter
        // -----------------------------------------------------------------------------
        public CComCommandParameter(CComCommandParameterInfo info_)
        {
            m_paramInfo = new CComCommandParameterInfo(info_);
        }

        private CComCommandParameterInfo m_paramInfo = null;

        #endregion
    }
}
