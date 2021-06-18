#pragma once

// =================================================================================================
// Constants used by the plug-in declaration.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <string>
#include <vector>

#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

extern const wchar_t* const g_PluginName;

#define SCRIPT_VERSION_DECLARATION L"version \"5.0\""

extern DWORD g_cookieCommandCenter;
extern DWORD g_cookieHost;

enum EOnOffChoice
{
    E_OO_INVALID = -1,
    E_OO_ON,
    E_OO_OFF,
    E_OO_NB_VALUES
};
extern const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ];

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ );
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ );
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_ );

