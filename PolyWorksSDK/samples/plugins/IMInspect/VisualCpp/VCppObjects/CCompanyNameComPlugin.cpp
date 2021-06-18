// =================================================================================================
//   CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2007 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================= INCLUDED FILES ==========================================

#include "stdafx.h"

#include "CCompanyNameComPlugin.h"

#include "CComCommandInfo.h"
#include "CComCommandParameter.h"
#include "CComCommandParameterEnum.h"
#include "CComCommandParameterInfo.h"
#include "CCompanyNameCommands.h"
#include "Diagnostics.h"

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
static const wchar_t* const _pPluginName = L"CompanyName VCppObjects";

extern bool g_diagnostics;

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
    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfo( L"COMPANY_NAME IPWOBJECT READ", L"Gives information about the selected objects." );

        CComCommandParameterInfo param( L"Log file name. If empty, information will be displayed in a message box", E_PARAM_DIR_IN, E_PARAM_TYPE_STRING );
        param.HasStringDefaultValueSet( true );
        param.StringDefaultValueSet( L"" );
        cmdInfo.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param ) );

        // TODO: Replace "&CompanyName" by your company name
        cmdInfo.MenuLocationSet( L"CompanyName\\Read IPWObject objects Information" );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNamePolyWorksObjectRead( cmdInfo ) );
    }

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfo( L"COMPANY_NAME IPWOBJECT ILINESCAN ADD_PASS", L"Duplicates the first pass of the selected ILineScan objects." );

        // TODO: Replace "&CompanyName" by your company name
        cmdInfo.MenuLocationSet( L"CompanyName\\Add Pass to ILineScan Objects" );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNamePolyWorksObjectILineScanAddLine( cmdInfo ) );
    }

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfo( L"COMPANY_NAME IPWOBJECT IPOINTCLOUD ADD_NOISE", L"Add noise to each point of the selected IPointCloud objects." );

        // TODO: Replace "&CompanyName" by your company name
        cmdInfo.MenuLocationSet( L"CompanyName\\Add Noise to IPointCloud Objects" );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNamePolyWorksObjectIPointCloudAddNoise( cmdInfo ) );
    }

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfo( L"COMPANY_NAME IPWOBJECT IPOINTCLOUD SUBSAMPLE", L"Apply a 1:10 subsampling to the selected IPointCloud objects." );

        // TODO: Replace "&CompanyName" by your company name
        cmdInfo.MenuLocationSet( L"CompanyName\\Subsample selected IPointCloud Objects" );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNamePolyWorksObjectIPointCloudSubsample( cmdInfo ) );
    }
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

        *pName_ = ::SysAllocString( _pPluginName );

        return ( *pName_ != nullptr ) ? S_OK : E_OUTOFMEMORY;
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

    // Configure diagnostics
    DiagnosticConfigurationUpdate();

    // TODO Using the g_diagnostics value, implement special case to diagnose the plug-in
    if ( g_diagnostics )
    {
        // The diagnostic is enabled, let the user know.
        const wchar_t* pMessage = L"Diagnostics are activated for this plug-in.\n\nDiagnostics can be deactivated on the Plug-ins page of the Workspace Manager options.";
        ::MessageBoxW( nullptr, pMessage, L"Diagnostics", MB_OK );
    }

    *pReturnVal_ = 1;

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
        ( *pIIMCommand_ )->AddRef();
        return S_OK;
    }

    return S_FALSE;
}
