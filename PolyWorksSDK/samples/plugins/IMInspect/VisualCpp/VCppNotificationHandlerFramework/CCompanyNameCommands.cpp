// =================================================================================================
//   Plug-in's commands.
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CCompanyNameCommands.h"

#include <PolyWorksSDK/UI/IDialogZone.h>

#include "CDlgCompanyNameNotificationViewer.h"
#include "CompanyNameConst.h"
#include "Resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

static const IM::CWString COMPANY_NAME_DLG_NAME = L"CCompanyNameNotificationHandlerDialog";

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

// =================================================================================================
// Commands constructor. This constructor is only called one time when the command is registered to
// the application.
//
// Parameter: info_ : Parameters necessary to build the commmand.
// -------------------------------------------------------------------------------------------------
CCmdCompanyNameDlgNotificationViewerShow::CCmdCompanyNameDlgNotificationViewerShow( CComCommandInfo& info_, CDlgCompanyNameNotificationViewer& dlg_ )
: CComCommand( info_ )
, m_pDlg{ &dlg_ }
{}

// =================================================================================================
// Retrieve a string argument from IIMCommandArgumentEnum
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
//
// -------------------------------------------------------------------------------------------------
static std::wstring ArgumentValueGet( IIMCommandArgumentEnum& iIMCommandArgumentEnum_ )
{
    IM::CWString stringValue;
    long         nbArg = 0;

    // Checking argument count validity
    if ( ( iIMCommandArgumentEnum_.ArgsGetNb( &nbArg ) == S_OK ) &&
         ( nbArg > 0 ) )
    {
        CComPtr< IIMCommandArgument > pArgument;
        // Checking availability of first argument
        if ( ( iIMCommandArgumentEnum_.ArgGet( 0, &pArgument ) == S_OK ) &&
             pArgument != nullptr )
        {
            long     retVal = 0;
            CComBSTR argValue;

            // Checking and retrieving argument value if of valid type
            if ( ( pArgument->ArgValueGetAsString( 1, &argValue, &retVal ) == S_OK ) &&
                 ( retVal == 1 ) )
            {
                stringValue = argValue;
            }
        }
    }
    return std::wstring{ stringValue };
}

// =================================================================================================
// Shows or hides dialog
//
// Parameter: pIIMCommandArgumentEnum_ : Arguments passed to the command
// Parameter: pReturnCode_             : Error code associated with your action result.
//
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCmdCompanyNameDlgNotificationViewerShow::Execute2(
    /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
    /* [retval][out] */ ECommandReturnCodes* pReturnCode_ )
{
    *pReturnCode_ = E_CMD_FAILED;
    if ( pIIMCommandArgumentEnum_ != nullptr )
    {
        EOnOffChoice param{ OnOffConvertStringToEnum( ArgumentValueGet( *pIIMCommandArgumentEnum_ ) ) };
        switch ( param )
        {
            case  E_OO_TOGGLE:
                *pReturnCode_ = ( m_pDlg->IsVisibleGet() ? InterfacePopdown() : InterfacePopup() );
                break;
            case E_OO_ON:
                *pReturnCode_ = InterfacePopup();
                break;
            case E_OO_OFF:
                *pReturnCode_ = InterfacePopdown();
                break;
            default:
                break;

        }
    }
    return S_OK;
}

// =================================================================================================
// Shows dialog
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
ECommandReturnCodes CCmdCompanyNameDlgNotificationViewerShow::InterfacePopup()
{
    bool      success     = true;
    HINSTANCE oldInstance = AfxGetResourceHandle();
    AfxSetResourceHandle( g_afxExtensionModule.hResource );

    // Create the dialog
    if ( m_pDlg->GetSafeHwnd() == nullptr )
    {
        success = m_pDlg->Create( IDD_COMPANYNAMENOTIFICATIONHANDLERDIALOG );
    }

    if ( ( m_pDlg != nullptr ) && m_pDlg->IsVisibleGet() )
    {
        return E_CMD_FAILED;
    }

    // Populate dlg with notification name
    m_pDlg->FillNotificationDropdown();

    AfxSetResourceHandle( oldInstance );

    // Add the dialog to the Dialog Zone and set it to foreground
    success &= IM::DialogZoneGet()->DialogAdd( m_pDlg->GetSafeHwnd(), COMPANY_NAME_DLG_NAME );
    IM::DialogZoneGet()->DialogSetForeground( COMPANY_NAME_DLG_NAME );

    if ( success )
    {
        m_pDlg->IsVisibleSet( true );
        return E_CMD_SUCCEEDED;
    }
    return E_CMD_FAILED;
}

// =================================================================================================
// Hides dialog
// Return: COM error code.
// -------------------------------------------------------------------------------------------------
ECommandReturnCodes CCmdCompanyNameDlgNotificationViewerShow::InterfacePopdown()
{
    // Remove the dialog from the Dialog Zone. When calling this, the dialog is not destroyed.
    IM::DialogZoneGet()->DialogRemove( COMPANY_NAME_DLG_NAME );
    m_pDlg->IsVisibleSet( false );
    return E_CMD_SUCCEEDED;
}
