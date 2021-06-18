// =================================================================================================
// Class for COM command parameters enumeration
//
// Copyright © InnovMetric Logiciels Inc. 2009 All Rights Reserved
// -------------------------------------------------------------------------------------------------
namespace IM
{
    [System.Runtime.InteropServices.ComVisible(true)]
    [System.Runtime.InteropServices.ClassInterface(System.Runtime.InteropServices.ClassInterfaceType.None)]
    public class CComCommandParameterEnum : IMPluginLib.IIMCommandParameterEnum
    {
        /* *****************************************************************************
        *                            IIMCommandParameterEnum Interface
        * -------------------------------------------------------------------------- */
        #region IIMCommandParameterEnum

        public int ParamsGetNb()
        {
            if(m_impl != null)
            {
                return m_impl.ParamsGetNb();
            }
            return 0;
        }

        public void ParamGet(int number_, out IMPluginLib.IIMCommandParameter iIMCommandParameter_)
        {
            iIMCommandParameter_ = null;
            if (m_impl != null)
            {
                m_impl.ParamGet(number_, out iIMCommandParameter_);
            }
        }

        #endregion

        /* *****************************************************************************
        *              CComCommandParameterEnum specific methods
        * -------------------------------------------------------------------------- */
        #region CComCommandParameterEnum

        // =============================================================================
        // Constructor
        // -----------------------------------------------------------------------------
        public CComCommandParameterEnum()
        {
            m_impl = new CComCommandParameterEnumImpl();
        }

        // =============================================================================
        // Add an argument to the enumeration
        //
        // Parameter: pCommandParameter_ : Argument to add
        // -----------------------------------------------------------------------------
        public void CommandParameterAdd(IMPluginLib.IIMCommandParameter commandParameter_)
        {
            if (m_impl != null)
            {
                m_impl.CommandParameterAdd(commandParameter_);
            }
        }

        private CComCommandParameterEnumImpl m_impl = null;

        #endregion
    }
}
