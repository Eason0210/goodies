#ifndef _COMPANYNAMECONST_MONDAY_APRIL042020_090246_H_
#define _COMPANYNAMECONST_MONDAY_APRIL042020_090246_H_
// =================================================================================================
//   Constants used by the plug-in declaration.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <string>

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

extern const wchar_t* const PLUGIN_NAME;


#define SCRIPT_VERSION_DECLARATION  L"version \"5.0\""

enum EOnOffChoice
{
    E_OO_INVALID = -1,
    E_OO_ON,
    E_OO_OFF,
    E_OO_TOGGLE,
    E_OO_NB_VALUES
};

extern const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ];

extern DWORD g_cookieCommandCenter;

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

EOnOffChoice OnOffConvertStringToEnum( const std::wstring& argValue );
std::wstring OnOffGetPossibleValuesString();


#endif // _COMPANYNAMECONST_MONDAY_APRIL042020_090246_H_
