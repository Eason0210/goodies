// =================================================================================================
// Implementation of the class for COM command parameters enumeration
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{    
    public class CComCommandParameterEnumImpl
    {
        /* *****************************************************************************
        *                           IIMCommandParameterEnum Interface
        * -------------------------------------------------------------------------- */
        #region IIMCommandParameterEnum

        // =============================================================================
        // See CComCommandParameterEnum.ParamsGetNb
        // -----------------------------------------------------------------------------
        public int ParamsGetNb()
        {
            if(m_parameters != null)
            {
                return m_parameters.Count;
            }
            return 0;
        }

        // =============================================================================
        // See CComCommandParameterEnum.ParamGet
        // -----------------------------------------------------------------------------
        public void ParamGet(int number_, out IMPluginLib.IIMCommandParameter iIMCommandParameter_)
        {
            iIMCommandParameter_ = null;

            if( m_parameters == null)
            {
                return;
            }

            if( number_ >= 0 && number_ < m_parameters.Count)
            {
                iIMCommandParameter_ = m_parameters[number_];
            }
        }

        #endregion

        /* *****************************************************************************
         *              CComCommandParameterEnumImpl specific methods
        * -------------------------------------------------------------------------- */
        #region CComCommandParameterEnumImpl

        // =============================================================================
        // Add an argument to the enumeration
        //
        // Parameter: pCommandParameter_ : Argument to add
        // -----------------------------------------------------------------------------
        public void CommandParameterAdd(IMPluginLib.IIMCommandParameter commandParameter_)
        {
            if (m_parameters != null)
            {
                m_parameters.Add(commandParameter_);
            }
        }

        private System.Collections.Generic.List<IMPluginLib.IIMCommandParameter> m_parameters = new System.Collections.Generic.List<IMPluginLib.IIMCommandParameter>();

        #endregion
    }
}
