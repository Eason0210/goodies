// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameNotificationHandlerPlugin.h"

#include <PolyWorksSDK/COM/IIMCommandCenter.h>
#include <PolyWorksSDK/COM/IIMCommandCenter_i.c>
#include <PolyWorksSDK/COM/IIMHost_i.c>
#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <PolyWorksSDK/UI/FnIDialogZone.h>
#include <PolyWorksSDK/UI/IDialogZone.h>
#include <atlcomcli.h>
#include <sstream>
#include <time.h>

#include "CComCommandInfo.h"
#include "CComCommandParameter.h"
#include "CComCommandParameterEnum.h"
#include "CComCommandParameterInfo.h"
#include "CComMessageFilter.h"
#include "CompanyNameConst.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

#ifndef E_BUSY
#define E_BUSY              _HRESULT_TYPEDEF_( 0x800700AAL )
#endif // #ifndef E_BUSY

static const DWORD BUSY_TIMEOUT = 100;

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
//   See IGlobalInterfaceTable::GetInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    res = pGIT->GetInterfaceFromGlobal( dwCookie_, riid_, ppv_ );

    return res;
}

// =================================================================================================
//   See IGlobalInterfaceTable::RegisterInterfaceInGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    res = pGIT->RegisterInterfaceInGlobal( pUnk_, riid_, pdwCookie_ );

    return res;
}

// =================================================================================================
//   See IGlobalInterfaceTable::RevokeInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
static HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_, UINT retriesWhenBusy_ = 0 )
{
    if ( dwCookie_ == 0 )
    {
        return S_OK;
    }

    // Reset the cookie first
    DWORD cookie = dwCookie_;
    dwCookie_ = 0;

    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** )&pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    // Loop if ressource is busy
    res = E_FAIL;
    for ( ; ; --retriesWhenBusy_ )
    {
        res = pGIT->RevokeInterfaceFromGlobal( cookie );
        if ( res != S_OK )
        {
            if ( ( retriesWhenBusy_ > 0 ) && ( res == E_BUSY ) )
            {
                // Wait if the ressource is busy
                HANDLE hDummyEvent  = ::CreateEvent( nullptr, FALSE, FALSE, nullptr );
                DWORD  dummyEventID = 0;
                ::CoWaitForMultipleHandles( NULL, BUSY_TIMEOUT, 1, &hDummyEvent, &dummyEventID );
                ::CloseHandle( hDummyEvent );

                // Loop only in this case
                continue;
            }
        }

        // Don't loop otherwise
        break;
    }

    return res;
}

// =================================================================================================
// Constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameNotificationHandlerPlugin::CCompanyNameNotificationHandlerPlugin()
: m_dataObjectSink{ *this }
, m_referenceObjectSink{ *this }
, m_inspectorSink{ *this }
, m_dataObjectGroupSink{ *this }
{
}

CCompanyNameNotificationHandlerPlugin::~CCompanyNameNotificationHandlerPlugin() = default;

// #######################################################################
// IIMPlugin
// #######################################################################
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::PlgNameGet(
    /* [out] */ BSTR* pName_ )
{
    ::SysFreeString( *pName_ );

    *pName_ = ::SysAllocString( PLUGIN_NAME );

    return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
}


// =============================================================================
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::PlgVersionGet(
    /* [out] */ long* pMajor_,
    /* [out] */ long* pMinor_,
    /* [out] */ long* pDot_ )
{
    *pMajor_ = 1;
    *pMinor_ = 0;
    *pDot_   = 0;

    return S_OK;
}


// =============================================================================
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::Load(
    /* [in] */ IIMHost*       pIIMHost_,
    /* [retval][out] */ long* pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) || ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    // Check if the host application is PolyWorks|Inspector
    m_host = CComQIPtr< IIMInspect >( pIIMHost_ );
    if ( m_host != nullptr )
    {
        CComPtr< IIMCommandCenter >  pCommandCenter;
        CComPtr< IIMInspectProject > pIMInspectProject;

        if ( m_host->ProjectGetCurrent( &pIMInspectProject ) == S_OK &&
             pIMInspectProject != nullptr &&
             pIMInspectProject->CommandCenterCreate( &( pCommandCenter ) ) == S_OK &&
             pCommandCenter != nullptr )
        {
            GITRegisterInterfaceInGlobal( pCommandCenter, IID_IIMCommandCenter, &g_cookieCommandCenter );
        }

        // Create the dialog

        // Create dialog class
        m_pDlg = std::make_unique< CDlgCompanyNameNotificationViewer >( *this );

        if ( m_pDlg != nullptr )
        {
            *pReturnVal_ = 1;

            return S_OK;
        }
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::Unload(
    /* [retval][out] */ long* pReturnVal_ )
{
    // Release all connection pointss
    m_dataObjectSink.NotificationActivationSet( false, *m_host );
    m_referenceObjectSink.NotificationActivationSet( false, *m_host );
    m_inspectorSink.NotificationActivationSet( false, *m_host );
    m_dataObjectGroupSink.NotificationActivationSet( false, *m_host );

    // Release the IIMCommandCenter
    GITRevokeInterfaceFromGlobal( g_cookieCommandCenter, 5 );

    // Release the Host
    m_host.Release();

    *pReturnVal_ = 1;

    if ( m_pDlg->GetSafeHwnd() != nullptr )
    {
        m_pDlg->DestroyWindow();
    }

    // Clear the command in case unload was not called
    CommandsRemove();

    return S_OK;
}

// =================================================================================================
// Returns the number of MSCL command's registered by this plug-in.
//
// Parameter: pArgNb_ : Number of MSCL command's registered by this plug-in.
//
// Return: Always S_OK.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::CmdsGetNb( long* pArgNb_ )
{
    // Add commands to the command vector member variable.
    if ( m_commands.empty() )
    {
        CommandsAdd();
    }

    *pArgNb_ = static_cast< long >( m_commands.size() );
    return S_OK;
}

// =================================================================================================
// Returns a COM interface pointer to a MSCL command.
//
// Parameter: number_      : Index of the command to be returned
// Parameter: pIIMCommand_ : COM interface pointer.
//
// Return: S_OK    if everything went well
//         S_FALSE if something went wrong
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameNotificationHandlerPlugin::CmdGet( long number_, IIMCommand** pIIMCommand_ )
{
    if ( ( pIIMCommand_ != nullptr ) &&
         ( number_ >= 0 ) &&
         ( number_ < static_cast< long >( m_commands.size() ) ) )
    {
        *pIIMCommand_ = m_commands[ number_ ];
        ( *pIIMCommand_ )->AddRef();
        return S_OK;
    }

    return S_FALSE;
}

// =================================================================================================
// Set notification enabled state
// -------------------------------------------------------------------------------------------------
void CCompanyNameNotificationHandlerPlugin::NotificationActivationStateSet( ENotificationType notificationID_, bool activate_ )
{
    switch ( notificationID_ )
    {
        case ENotificationType::E_DATA_OBJECT:
            m_dataObjectSink.NotificationActivationSet( activate_, *m_host );
            break;
        case ENotificationType::E_REFERENCE_OBJECT:
            m_referenceObjectSink.NotificationActivationSet( activate_, *m_host );
            break;
        case ENotificationType::E_INSPECTOR_PROJECT:
            m_inspectorSink.NotificationActivationSet( activate_, *m_host );
            break;
        case ENotificationType::E_DATA_OBJECT_GROUP:
            m_dataObjectGroupSink.NotificationActivationSet( activate_, *m_host );
            break;
    }
}

// =================================================================================================
// Returns notification enabled state
// -------------------------------------------------------------------------------------------------
bool CCompanyNameNotificationHandlerPlugin::NotificationActivationStateGet( ENotificationType notificationID_ )
{
    switch ( notificationID_ )
    {
        case ENotificationType::E_DATA_OBJECT:
            return m_dataObjectSink.NotificationActivationGet();
        case ENotificationType::E_REFERENCE_OBJECT:
            return m_referenceObjectSink.NotificationActivationGet();
        case ENotificationType::E_INSPECTOR_PROJECT:
            return m_inspectorSink.NotificationActivationGet();
        case ENotificationType::E_DATA_OBJECT_GROUP:
            return m_dataObjectGroupSink.NotificationActivationGet();
    }
    return false;
}

// =================================================================================================
// Format Data and Reference Object notifications and display in dialog
// -------------------------------------------------------------------------------------------------
void CCompanyNameNotificationHandlerPlugin::OnObjectUniqueIDsReceived( std::vector< std::wstring >&& uniqueIDs_, std::wstring&& operationType_ )
{
    if ( !uniqueIDs_.empty() )
    {
        std::wstringstream os;
        for ( const std::wstring& uniqueID : uniqueIDs_ )
        {
            os << uniqueID << " ";
        }
        m_pDlg->OnNotificationReceived( operationType_, os.str() );
    }
}

// =================================================================================================
// Format Piece notifications and display in dialog
// -------------------------------------------------------------------------------------------------
void CCompanyNameNotificationHandlerPlugin::OnPieceUniqueIDReceived( std::wstring&& uniqueID_, std::wstring&& operationType_ )
{
    m_pDlg->OnNotificationReceived( operationType_, uniqueID_ );
}

// =================================================================================================
// Adds MSCL commands to the commands vector member variable.
// -------------------------------------------------------------------------------------------------
void CCompanyNameNotificationHandlerPlugin::CommandsAdd()
{
    if ( m_pDlg == nullptr )
    {
        return;
    }

    // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
    CComCommandInfo cmdInfoDlgPopUp( L"COMPANY_NAME NOTIFICATION_HANDLER DIALOG SHOW", L"Show or hide a dialog in the Dialog Zone." );
    // TODO: Replace "&CompanyName" by your company name
    cmdInfoDlgPopUp.MenuLocationSet( L"CompanyName\\Notification Handler..." );
    CComCommandParameterInfo param( L"Show dialog",
                                    E_PARAM_DIR_IN,
                                    E_PARAM_TYPE_STRING );
    param.ValuesSet( OnOffGetPossibleValuesString().c_str() );
    param.HasStringDefaultValueSet( true );
    param.StringDefaultValueSet( g_OnOffChoiceStrings[ E_OO_TOGGLE ].c_str() );
    cmdInfoDlgPopUp.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param ) );

    m_commands.push_back( new  CCmdCompanyNameDlgNotificationViewerShow{ cmdInfoDlgPopUp, *m_pDlg } );

    // TODO: Add any other relevant command

}

// =================================================================================================
// Releases any commands added in CommandsAdd.
// -------------------------------------------------------------------------------------------------
void CCompanyNameNotificationHandlerPlugin::CommandsRemove()
{
    m_commands.clear();
}
