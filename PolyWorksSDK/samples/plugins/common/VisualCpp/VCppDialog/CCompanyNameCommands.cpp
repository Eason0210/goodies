// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CCompanyNameCommands.h"

#include <PolyWorksSDK/UI/IDialogZone.h>

#include "CDlgVCppDialog.h"

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

static const IM::CWString COMPANY_NAME_DLG_NAME = L"CCompanyNameCDlgVCppDialog";

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDialogPopUp::CCmdCompanyNameDialogPopUp( CComCommandInfo& info_ )
: CComCommand( info_ )
{
    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );
    m_pDlgVCppDialog = new CDlgVCppDialog;
    AfxSetResourceHandle( oldInstance );
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDialogPopUp::~CCmdCompanyNameDialogPopUp()
{
    if ( m_pDlgVCppDialog->GetSafeHwnd() != NULL )
    {
        m_pDlgVCppDialog->DestroyWindow();
    }
    delete m_pDlgVCppDialog;
}


// =================================================================================================
// Pops up a plug-ins dialog into the Dialog Zone.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameDialogPopUp::Execute2( /* [in] */ IIMCommandArgumentEnum*,
                                                   /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    // Create the dialog
    if ( m_pDlgVCppDialog->GetSafeHwnd() == NULL )
    {
        m_pDlgVCppDialog->Create( IDD_VCPPDIALOG );
    }

    AfxSetResourceHandle( oldInstance );

    // Add the dialog to the Dialog Zone and set it to foreground
    IM::DialogZoneGet()->DialogAdd( m_pDlgVCppDialog->GetSafeHwnd(), COMPANY_NAME_DLG_NAME );
    IM::DialogZoneGet()->DialogSetForeground( COMPANY_NAME_DLG_NAME );

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}


// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDialogPopDown::CCmdCompanyNameDialogPopDown( CComCommandInfo& info_ )
: CComCommand( info_ )
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDialogPopDown::~CCmdCompanyNameDialogPopDown()
{
}


// =================================================================================================
// Pops down a plug-ins dialog into the Dialog Zone.
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameDialogPopDown::Execute2( /* [in] */ IIMCommandArgumentEnum*,
                                                     /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    // Remove the dialog from the Dialog Zone. When calling this, the dialog is not destroyed.
    IM::DialogZoneGet()->DialogRemove( COMPANY_NAME_DLG_NAME );

    *pReturnCode_ = E_CMD_SUCCEEDED;

    return S_OK;
}
