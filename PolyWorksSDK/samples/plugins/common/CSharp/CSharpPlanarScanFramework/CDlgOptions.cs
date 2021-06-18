// =================================================================================================
//   CDlgOptions class and support classes for example in PolyWorks|Align
//
// Copyright © InnovMetric Software Inc. 2019 All Rights Reserved
// -------------------------------------------------------------------------------------------------

using System;
using System.Windows.Forms;

namespace CompanyNameCsPlanarScanner
{

// =================================================================================================
//   Class implementing the options dialog in Inspector mode.
// -------------------------------------------------------------------------------------------------
partial class CDlgOptions : Form
{
    private IM.CIMHost m_host;
    private CSettings m_settings;
    // =================================================================================================
    //   Constructor used only by the designer.
    // -------------------------------------------------------------------------------------------------
    public CDlgOptions()
    {
        InitializeComponent(); 
    }
    
    // =================================================================================================
    //   Real constructor used when we create the dialog at runtime.
    //
    // Parameter : host_ : Access to host application functionalities.
    // -------------------------------------------------------------------------------------------------
    public CDlgOptions( IM.CIMHost host_, CSettings settings_ )
    {
        m_host = host_;
        m_settings = settings_;
        InitializeComponent();
        // Clickin on ok button generates validation event
        m_txtMaxAngle.DataBindings.Add("Text", m_settings, "IMAMaxAngle", true, DataSourceUpdateMode.Never);
        m_txtInterpolationStep.DataBindings.Add("Text", m_settings, "IMAInterpolationStep", true, DataSourceUpdateMode.Never);
        m_txtMaxEdgeLength.DataBindings.Add("Text", m_settings, "IMAMaxEdgeLength", true, DataSourceUpdateMode.Never);
    }

    private void m_btnOk_Click(object sender, EventArgs e)
    {
        m_settings.IMAInterpolationStep = Convert.ToDouble( m_txtInterpolationStep.Text );
        m_settings.IMAMaxAngle = Convert.ToDouble( m_txtMaxAngle.Text );
        m_settings.IMAMaxEdgeLength = Convert.ToDouble( m_txtMaxEdgeLength.Text );
        Close();
    }

    private void m_btnCancel_Click(object sender, EventArgs e)
    {
        Close();
    }
}
}