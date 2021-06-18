// =================================================================================================
//   CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CCompanyNameComPlugin.h"

#include <PolyWorksSDK/COM/IIMInspect.h>
#include <PolyWorksSDK/COM/IIMInspect_i.c>
#include <atlcomcli.h>

#include "CComCommandInfo.h"
#include "CCompanyNameCommands.h"

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

// Make sure your plug-in name does not exceed 31 character
const wchar_t* g_pPluginName = L"CompanyName 3DSceneRendering";

// =================================================================================================
// =================================== FUNCTIONS PROTOTYPES ========================================

// =================================================================================================
// =================================== FUNCTIONS DEFINITIONS =======================================

// =================================================================================================
// ===================================== NO COM INTERFACE ==========================================

// =================================================================================================
// Constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameComPlugin::CCompanyNameComPlugin()
{
}


// =================================================================================================
// Destructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameComPlugin::~CCompanyNameComPlugin()
{
}


// =================================================================================================
// Adds MSCL commands to the commands vector member variable.
// -------------------------------------------------------------------------------------------------
void CCompanyNameComPlugin::CommandsAdd()
{
    // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
    CComCommandInfo cmdInfoStart( L"COMPANY_NAME DRAW START", L"Start drawing." );

    // TODO: Replace "&CompanyName" by your company name
    cmdInfoStart.MenuLocationSet( L"CompanyName\\Start drawing" );

    // Add the command to the command vector
    m_commands.push_back( new CCmdCompanyName3DSceneRenderingStart( cmdInfoStart ) );


    // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
    CComCommandInfo cmdInfoStop( L"COMPANY_NAME DRAW STOP", L"Stop drawing." );

    // TODO: Replace "&CompanyName" by your company name
    cmdInfoStop.MenuLocationSet( L"CompanyName\\Stop drawing" );

    // Add the command to the command vector
    m_commands.push_back( new CCmdCompanyName3DSceneRenderingStop( cmdInfoStop ) );
}


// =================================================================================================
// Releases any commands added in CommandsAdd.
// -------------------------------------------------------------------------------------------------
void CCompanyNameComPlugin::CommandsRemove()
{
    m_commands.clear();
}


// =================================================================================================
// ATL initial object construction.
//
// Return: Always S_OK.
// -------------------------------------------------------------------------------------------------
HRESULT CCompanyNameComPlugin::FinalConstruct()
{
    return S_OK;
}


// =================================================================================================
// ATL object destruction.
// -------------------------------------------------------------------------------------------------
void CCompanyNameComPlugin::FinalRelease()
{
}


// =================================================================================================
// ========================================= IIMPlugin =============================================

// =================================================================================================
// Returns the plug-in's name.
//
// Parameter: pName_ : Plug-in's name.
//
// Return: S_OK          if everything went well
//         E_OUTOFMEMORY if the string cannot be allocated
//         S_FALSE       if the name is invalid
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameComPlugin::PlgNameGet( /* [retval][out] */ BSTR* pName_ )
{
    if ( pName_ != nullptr )
    {
        ::SysFreeString( *pName_ );

        *pName_ = ::SysAllocString( g_pPluginName );

        return ( *pName_ != NULL ) ? S_OK : E_OUTOFMEMORY;
    }
    return S_FALSE;
}


// =================================================================================================
// Returns the plug-in's version in the form of major.minor.dot.
//
// Parameter: pMajor_ : Major component of the plug-in's version
// Parameter: pMinor_ : Minor component of the plug-in's version
// Parameter: pDot_   : Dot component of the plug-in's version
//
// Return: S_OK    if everything went well
//         S_FALSE if the version is invalid
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameComPlugin::PlgVersionGet(
    /* [out][in] */ long* pMajor_,
    /* [out][in] */ long* pMinor_,
    /* [out][in] */ long* pDot_ )
{
    if ( ( pMajor_ != nullptr ) && ( pMinor_ != nullptr ) && ( pDot_ != nullptr ) )
    {
        *pMajor_ = 1;
        *pMinor_ = 0;
        *pDot_   = 0;

        return S_OK;
    }

    return S_FALSE;
}


// =================================================================================================
// Called when the plug-in is loaded.
//
// Parameter: pIIMHost_   : Pointer to the host's application COM pointer.
// Parameter: pReturnVal_ : Return code
//
// Return: S_OK    if everything went well
//         S_FALSE if something went wrong
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameComPlugin::Load(
    /* [unique][in]  */ IIMHost* pIIMHost_,
    /* [retval][out] */ long*    pReturnVal_ )
{
    if ( ( pIIMHost_ == nullptr ) || ( pReturnVal_ == nullptr ) )
    {
        return S_FALSE;
    }

    *pReturnVal_ = 0;

    // 3D scene rendering functionalities are only supported in the PolyWorks|Inspector application.
    CComQIPtr< IIMInspect > pIMInspect( pIIMHost_ );
    if ( pIMInspect != nullptr )
    {
        *pReturnVal_ = 1;
    }

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}


// =================================================================================================
// Called when the plug-in is unloaded.
//
// Parameter: pReturnVal_ : Return code
//
// Return: S_OK    if everything went well
//         S_FALSE if something went wrong
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameComPlugin::Unload( /* [retval][out] */ long* pReturnVal_ )
{
    *pReturnVal_ = 1;

    AnnotationsRemoveAll();
    DrawNodesRemoveAll();

    CommandsRemove();

    return ( *pReturnVal_ == 1 ) ? S_OK : S_FALSE;
}


// =================================================================================================
// ====================================== IIMCommandEnum ===========================================

// =================================================================================================
// Returns the number of MSCL command's registered by this plug-in.
//
// Parameter: pArgNb_ : Number of MSCL command's registered by this plug-in.
//
// Return: Always S_OK.
// -------------------------------------------------------------------------------------------------
STDMETHODIMP CCompanyNameComPlugin::CmdsGetNb( /* [retval][out] */ long* pArgNb_ )
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
STDMETHODIMP CCompanyNameComPlugin::CmdGet(
    /* [in]  */ long         number_,
    /* [out] */ IIMCommand** pIIMCommand_ )
{
    if ( ( pIIMCommand_ != nullptr ) &&
         ( number_ >= 0 ) &&
         ( number_ <= static_cast< long >( m_commands.size() ) ) )
    {
        ( *pIIMCommand_ ) = m_commands[ number_ ];
        // adding this ref allows the command to be passed to inspector
        ( *pIIMCommand_ )->AddRef();
        return S_OK;
    }

    return S_FALSE;
}
