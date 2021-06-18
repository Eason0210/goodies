#pragma once

// =================================================================================================
//   Classes to show tooltip on each list item in a combo box
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Class to show tooltip on each item in a list box
// -------------------------------------------------------------------------------------------------
class CTooltipListBox : public CListBox
{
    // Construction
public:
    CTooltipListBox();
    void DestroyTooltip();
    void TooltipsSet( const TWStrings& tooltips_ ) { m_tooltips = tooltips_; }
    bool IsTootipVisible();

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL( CTooltipListBox )
protected:
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL

    // Implementation
protected:
    HWND     m_hWndToolTip;
    TOOLINFO m_ToolInfo;

    // Generated message map functions
protected:
    //{{AFX_MSG( CTooltipListBox )
    afx_msg void OnMouseMove( UINT nFlags_, CPoint point_ );
    afx_msg void OnTimer( UINT_PTR nIDEvent_ );
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()

private:
    int       m_currentItem;
    TWStrings m_tooltips;
};

// =================================================================================================
//   Class to show tooltip on each list item in a combo box
// -------------------------------------------------------------------------------------------------
class CTooltipComboBox : public CComboBox
{
    // Construction
public:
    CTooltipComboBox();
    virtual ~CTooltipComboBox();
    void TooltipsSet( const TWStrings& tooltips_ );
    bool IsTootipVisible();

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL( CTooltipComboBox )
    //}}AFX_VIRTUAL

    // Implementation
protected:
    CTooltipListBox m_listbox;

    // Generated message map functions
protected:
    //{{AFX_MSG( CTooltipComboBox )
    afx_msg HBRUSH OnCtlColor( CDC* pDC_, CWnd* pWnd_, UINT nCtlColor_ );
    afx_msg void   OnDestroy();
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
