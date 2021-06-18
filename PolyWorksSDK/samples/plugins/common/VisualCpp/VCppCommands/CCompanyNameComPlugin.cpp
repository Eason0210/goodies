﻿// =================================================================================================
// CCompanyNameComPlugin class.
//
// Copyright © InnovMetric Logiciels Inc. 2008 All Rights Reserved
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
const wchar_t* g_pPluginName = L"CompanyName VCppCommands";

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
    // MENU command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfo( L"COMPANY_NAME COMMAND_ACTION", L"Command action description." );

        // TODO: Replace "&CompanyName" by your company name
        cmdInfo.MenuLocationSet( L"CompanyName\\Menu Item Action Name" );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameAction( cmdInfo ) );
    }

    // DOUBLE setting value SET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoDoubleValueSet( L"COMPANY_NAME DOUBLE_SETTING", L"Sets a double value setting." );

        CComCommandParameterInfo param01(  L"Double setting", E_PARAM_DIR_IN, E_PARAM_TYPE_DOUBLE );
        cmdInfoDoubleValueSet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameDoubleSet( cmdInfoDoubleValueSet ) );
    }

    // DOUBLE setting value GET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoDoubleValueGet( L"COMPANY_NAME DOUBLE_SETTING GET", L"Gets a double value setting." );

        CComCommandParameterInfo param01(  L"Double setting", E_PARAM_DIR_OUT, E_PARAM_TYPE_DOUBLE );
        cmdInfoDoubleValueGet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameDoubleGet( cmdInfoDoubleValueGet ) );
    }

    // INTEGER setting value SET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoIntegerValueSet( L"COMPANY_NAME INTEGER_SETTING", L"Sets an integer value setting." );

        CComCommandParameterInfo param01(  L"Integer setting", E_PARAM_DIR_IN, E_PARAM_TYPE_INTEGER );
        cmdInfoIntegerValueSet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameIntegerSet( cmdInfoIntegerValueSet ) );
    }

    // INTEGER setting value GET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoIntegerValueGet( L"COMPANY_NAME INTEGER_SETTING GET", L"Gets an integer value setting." );

        CComCommandParameterInfo param01(  L"Double setting", E_PARAM_DIR_OUT, E_PARAM_TYPE_INTEGER );
        cmdInfoIntegerValueGet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameIntegerGet( cmdInfoIntegerValueGet ) );
    }

    // STRING setting value SET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoStringValueSet( L"COMPANY_NAME STRING_SETTING", L"Sets an string value setting." );

        CComCommandParameterInfo param01(  L"String setting", E_PARAM_DIR_IN, E_PARAM_TYPE_STRING );
        cmdInfoStringValueSet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameStringSet( cmdInfoStringValueSet ) );
    }

    // STRING setting value GET command

    {
        // TODO: Replace COMPANY_NAME by your company name, give the command good name and a good description.
        CComCommandInfo cmdInfoStringValueGet( L"COMPANY_NAME STRING_SETTING GET", L"Gets an string value setting." );

        CComCommandParameterInfo param01(  L"Double setting", E_PARAM_DIR_OUT, E_PARAM_TYPE_STRING );
        cmdInfoStringValueGet.ParameterEnumGet().CommandParameterAdd( new CComCommandParameter( param01 ) );

        // Add the command to the command vector
        m_commands.push_back( new CCmdCompanyNameStringGet( cmdInfoStringValueGet ) );
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
         ( number_ < static_cast< long >( m_commands.size() ) ) )
    {
        ( *pIIMCommand_ ) = m_commands[ number_ ];
        // adding this ref allows the command to be passed to inspector
        ( *pIIMCommand_ )->AddRef();

        return S_OK;
    }

    return S_FALSE;
}
