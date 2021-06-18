// =================================================================================================
//   Constants used by the plug-in implementation.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CompanyNameConst.h"

#include <algorithm>

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

const wchar_t* const g_PluginName = L"CompanyName Planar Scanner";                  // The name should not be longer than 31 characters

const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ] =
{
    L"On",
    L"Off",
};

const std::wstring g_StandardAxes[ NB_STD_AXES ] =
{
    L"+X",
    L"-X",
    L"+Y",
    L"-Y",
    L"+Z",
    L"-Z",
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

template< class TString >
class CTCaseInsensitiveComparator
{
public:
    CTCaseInsensitiveComparator( const TString& firstStr_ )
    {
        // Transform first string to upper case
        m_firstStr.resize( firstStr_.size() );
        std::transform( firstStr_.begin(), firstStr_.end(), m_firstStr.begin(), toupper );
    }

    bool operator()( const TString& secondStr_ ) const
    {
        // Transform second string to upper case
        TString secondStr;
        secondStr.resize( secondStr_.size() );
        std::transform( secondStr_.begin(), secondStr_.end(), secondStr.begin(), toupper );

        // Compare strings
        return m_firstStr == secondStr;
    }

private:
    TString m_firstStr;
};

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

DWORD g_cookieCommandCenter   = 0;
DWORD g_cookieHost            = 0;
DWORD g_cookieScannerFeedback = 0;

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
//   See IGlobalInterfaceTable::GetInterfaceFromGlobal
// -------------------------------------------------------------------------------------------------
HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** ) &pGIT );

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
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ )
{
    CComPtr< IGlobalInterfaceTable > pGIT;
    HRESULT res = CoCreateInstance(
        CLSID_StdGlobalInterfaceTable,
        nullptr,
        CLSCTX_INPROC_SERVER,
        IID_IGlobalInterfaceTable,
        ( void** ) &pGIT );

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
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_ )
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
        ( void** ) &pGIT );

    if ( res != S_OK )
    {
        return res;
    }

    if ( pGIT == nullptr )
    {
        return S_FALSE;
    }

    res = pGIT->RevokeInterfaceFromGlobal( cookie );

    return res;
}


// =================================================================================================
//   OnOffConvertStringToEnum
//
// Parameter: argValue : On/Off string to convert
//
// Return : On/Off Choice
// -------------------------------------------------------------------------------------------------
EOnOffChoice OnOffConvertStringToEnum( const std::wstring& argValue )
{
    EOnOffChoice choiceToReturn = E_OO_INVALID;
    CTCaseInsensitiveComparator< std::wstring > caseInsensitiveComparator( argValue );
    for ( int iValue = 0; iValue < E_OO_NB_VALUES; iValue++ )
    {
        if ( caseInsensitiveComparator( g_OnOffChoiceStrings[ iValue ] ) )
        {
            choiceToReturn = static_cast< EOnOffChoice >( iValue );
            break;
        }
    }

    return choiceToReturn;
}


// =================================================================================================
//   OnOffGetPossibleValuesString
//
// Return : On/Off string
// -------------------------------------------------------------------------------------------------
std::wstring OnOffGetPossibleValuesString()
{
    std::wstring values = L"\"";
    for ( int iValue = 0; iValue < E_OO_NB_VALUES; iValue++ )
    {
        values += g_OnOffChoiceStrings[ iValue ];
        values += L"\"";
        if ( iValue != E_OO_NB_VALUES - 1 )
        {
            values += L", \"";
        }
    }

    return values;
}
