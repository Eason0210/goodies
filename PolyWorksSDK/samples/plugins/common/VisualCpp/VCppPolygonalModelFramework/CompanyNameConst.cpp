// =================================================================================================
// Constants used by the plug-in implementation.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
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

const wchar_t* const g_PluginName = L"CompanyName Polygonal Model Scanner";                  // The name should not be longer than 31 characters

const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ] =
{
    L"On",
    L"Off",
};

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

DWORD g_cookieCommandCenter = 0;
DWORD g_cookieHost          = 0;

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
