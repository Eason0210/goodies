#pragma once

// =================================================================================================
//   Constants used by the plug-in declaration.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
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

enum EEvents
{
    E_DATA_OBJECT_CHANGE,
    E_DISCONNECT,
    E_SCAN_START,
    E_SCAN_END
};

enum EOnOffChoice
{
    E_OO_INVALID = -1,
    E_OO_ON,
    E_OO_OFF,
    E_OO_NB_VALUES
};

// Identify the vertical axis
enum EStdAxis
{
    E_AXIS_INVALID = -1,

    E_X_POS        = 0,
    E_X_NEG,
    E_Y_POS,
    E_Y_NEG,
    E_Z_POS,
    E_Z_NEG,

    NB_STD_AXES
};

extern const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ];
extern const std::wstring g_StandardAxes[ NB_STD_AXES ];

extern DWORD g_cookieCommandCenter;
extern DWORD g_cookieHost;
extern DWORD g_cookieScannerFeedback;

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

struct SPlanarGridPoint
{
    SPlanarGridPoint( float x_, float y_, float z_, short row_, short col_ )
    : m_coordinate( x_, y_, z_ )
    , m_row( row_ )
    , m_col( col_ ) {}

    PointF m_coordinate;
    short  m_row = 0;
    short  m_col = 0;
};

struct SScanData
{
    SScanData( float i_, float j_, float k_, short width_, short height_ )
    : m_A( i_ )
    , m_B( j_ )
    , m_C( k_ )
    , m_width( width_ )
    , m_height( height_ ) {}

    float                           m_A      = 0.0;
    float                           m_B      = 0.0;
    float                           m_C      = 0.0;
    short                           m_width  = 0;
    short                           m_height = 0;
    std::vector< SPlanarGridPoint > m_points;
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ );
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ );
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_ );

EOnOffChoice OnOffConvertStringToEnum( const std::wstring& argValue );
std::wstring OnOffGetPossibleValuesString();
