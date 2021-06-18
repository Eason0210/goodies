#ifndef _CDLGVCPPDIALOG_THURSDAY_AUGUST09_145845_H_
#define _CDLGVCPPDIALOG_THURSDAY_AUGUST09_145845_H_
// =================================================================================================
//   CDlgVCppDialog class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include <afxcmn.h>

#include "resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   Simple class used to show how to put a plug-in dialog in the Dialog Zone.
// -------------------------------------------------------------------------------------------------
class CDlgVCppDialog : public CDialog
{
    DECLARE_DYNAMIC( CDlgVCppDialog )
    DECLARE_MESSAGE_MAP()

public:

    CDlgVCppDialog( CWnd* pParent_ = nullptr );
    virtual ~CDlgVCppDialog();

    // Dialog Data
    enum { IDD = IDD_VCPPDIALOG };

    virtual void DoDataExchange( CDataExchange* pDX_ );

    virtual BOOL OnCommand( WPARAM wParam_, LPARAM lParam_ );
    virtual BOOL OnInitDialog();
    virtual void OnCancel();
    virtual void OnOK();

    afx_msg void OnDestroy();

private:
    int    m_check1;
    double m_edit1;
};


// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CDLGVCPPDIALOG_THURSDAY_AUGUST09_145845_H_
