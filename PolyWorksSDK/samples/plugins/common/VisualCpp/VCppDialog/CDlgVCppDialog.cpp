// =================================================================================================
//   CDlgVCppDialog class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CDlgVCppDialog.h"

#include <PolyWorksSDK/UI/FnDialog.h>
#include <PolyWorksSDK/UI/IDialogZone.h>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

IMPLEMENT_DYNAMIC( CDlgVCppDialog, CDialog )

// =================================================================================================
// Constructor.
//
// Parameter: pParent_ : Parent window. NULL by default
// -------------------------------------------------------------------------------------------------
CDlgVCppDialog::CDlgVCppDialog( CWnd* pParent_ /*=nullptr*/ )
: CDialog( CDlgVCppDialog::IDD, pParent_ )
, m_check1( BST_CHECKED )
, m_edit1( 1.62 )
{
}


// =================================================================================================
// Destructor
// -------------------------------------------------------------------------------------------------
CDlgVCppDialog::~CDlgVCppDialog()
{
}


// =================================================================================================
// Message map.
// -------------------------------------------------------------------------------------------------
BEGIN_MESSAGE_MAP( CDlgVCppDialog, CDialog )
    ON_WM_DESTROY()
END_MESSAGE_MAP()

// =================================================================================================
// MSDN Documentation:
// Called by the framework to exchange and validate dialog data.
//
// Parameter: pDX_ : A pointer to a CDataExchange object
// -------------------------------------------------------------------------------------------------
void CDlgVCppDialog::DoDataExchange( CDataExchange* pDX_ )
{
    CDialog::DoDataExchange( pDX_ );
    DDX_Check( pDX_, IDC_CHECK1, m_check1 );
    DDX_Text( pDX_, IDC_EDIT1, m_edit1 );
}

// =================================================================================================
// MSDN Documentation:
// The framework calls this member function when the user selects an item from a menu, when a child
// control sends a notification message, or when an accelerator keystroke is translated.
//
// Parameter: wParam_ : The low-order word of wParam identifies the command ID of the menu item,
//                      control, or accelerator. The high-order word of wParam specifies the
//                      notification message if the message is from a control. If the message is
//                      from an accelerator, the high-order word is 1.
//                      If the message is from a menu, the high-order word is 0.
// Parameter: lParam_ : Identifies the control that sends the message if the message is from a control.
//                      Otherwise, lParam is 0.
//
// Return: An application returns nonzero if it processes this message; otherwise 0
// -------------------------------------------------------------------------------------------------
BOOL CDlgVCppDialog::OnCommand( WPARAM wParam_, LPARAM lParam_ )
{
    // We call the Red Labels' OnCommand so that the framework will automatically mark modified
    // controls and trace their respective red label red or black.
    IM::DialogRedLabelsOnCommand( GetSafeHwnd(), wParam_, lParam_ );

    return CDialog::OnCommand( wParam_, lParam_ );
}

// =================================================================================================
// MSDN Documentation:
// The framework calls this member function to inform the CWnd object that it is being destroyed.
// -------------------------------------------------------------------------------------------------
void CDlgVCppDialog::OnDestroy()
{
    // Uninitialize the red label tool.
    IM::DialogRedLabelsUninit( GetSafeHwnd() );
}

// =================================================================================================
// Initializes the dialog. If you want to add a dialog into the Dialog Zone, you must do it in
// the OnInitDialog.
//
// Return: Always TRUE.
// -------------------------------------------------------------------------------------------------
BOOL CDlgVCppDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    HWND hDlg = GetSafeHwnd();

    // Uses the automatic red label attribution for IDC_CHECK1 and IDC_RADIO1
    IM::DialogRedLabelsControlAddAuto( hDlg, ::GetDlgItem( hDlg, IDC_CHECK1 ) );
    IM::DialogRedLabelsControlAddAuto( hDlg, ::GetDlgItem( hDlg, IDC_RADIO1 ) );

    // Uses the manual red label attribution because IDC_STATIC1 is not the control preceeding IDC_EDIT1
    // in the tab order.
    IM::DialogRedLabelsControlAdd( hDlg, ::GetDlgItem( hDlg, IDC_EDIT1 ), ::GetDlgItem( hDlg, IDC_STATIC1 ) );

    AfxSetResourceHandle( oldInstance );

    return TRUE;
}

// =================================================================================================
// Destroys the dialog when the user clics on the Cancel button.
// -------------------------------------------------------------------------------------------------
void CDlgVCppDialog::OnCancel()
{
    HWND hDlg = GetSafeHwnd();

    // If one or more control is marked as modified, we confirm with the user that he really
    // wants to discard his changes.
    if ( IM::DialogRedLabelsControlIsModified( hDlg, ::GetDlgItem( hDlg, IDC_CHECK1 ) ) ||
         IM::DialogRedLabelsControlIsModified( hDlg, ::GetDlgItem( hDlg, IDC_RADIO1 ) ) ||
         IM::DialogRedLabelsControlIsModified( hDlg, ::GetDlgItem( hDlg, IDC_EDIT1 ) ) )
    {
        int ret = AfxMessageBox( L"One of more control is modified, are you sure you want to close this dialog box?", MB_ICONQUESTION | MB_YESNO );
        if ( IDNO == ret )
        {
            return;
        }
    }
    DestroyWindow();
}

// =================================================================================================
// Act as an Apply button
// -------------------------------------------------------------------------------------------------
void CDlgVCppDialog::OnOK()
{
    UpdateData( TRUE );
    HWND hDlg = GetSafeHwnd();
    IM::DialogRedLabelsControlModifiedSet( hDlg, ::GetDlgItem( hDlg, IDC_CHECK1 ), false );
    IM::DialogRedLabelsControlModifiedSet( hDlg, ::GetDlgItem( hDlg, IDC_RADIO1 ), false );
    IM::DialogRedLabelsControlModifiedSet( hDlg, ::GetDlgItem( hDlg, IDC_EDIT1 ),  false );
}
