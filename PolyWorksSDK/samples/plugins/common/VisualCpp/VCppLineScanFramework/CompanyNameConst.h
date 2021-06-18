#pragma once

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

extern const wchar_t* const g_PluginName;

extern const wchar_t* const g_cmdAutoViewpointSet;
extern const wchar_t* const g_cmdAutoViewpointVerticalAxisSet;
extern const wchar_t* const g_cmdAutoViewpointCloseUpZoomSet;
extern const wchar_t* const g_cmdSharpEdgeMaxPointToPointDistSet;
extern const wchar_t* const g_cmdSharpEdgeMaxPointToPointDistGet;
extern const wchar_t* const g_cmdSharpEdgeMinAngleSet;
extern const wchar_t* const g_cmdSharpEdgeMinAngleGet;
extern const wchar_t* const g_cmdOptionsDlgPropertyGridLog;

extern const wchar_t* const g_cmdConfigModifyDefaultNameSurfaceScanGet;
extern const wchar_t* const g_cmdConfigModifyDefaultNameBoundaryScanGet;
extern const wchar_t* const g_cmdDigitizeDeviceScanSurfaceDataObjectName;
extern const wchar_t* const g_cmdDigitizeDeviceScanBoundaryDataObjectName;
extern const wchar_t* const g_cmdDigitizeDeviceScanTypeGet;
extern const wchar_t* const g_cmdDigitizeDeviceScanTypeSet;
extern const wchar_t* const g_cmdDigitizeClippingPlaneGet;
extern const wchar_t* const g_cmdDigitizeClippingPlaneSet;
extern const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMSet;
extern const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMGet;
extern const wchar_t* const g_cmdDigitizeLineScanSurfaceRQTMFinalDataObjCreate;
extern const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeGet;
extern const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeSet;
extern const wchar_t* const g_cmdDigitizeClippingPlaneDefinedDateTimeGet;
extern const wchar_t* const g_cmdDigitizeClippingPlaneDefinedGet;
extern const wchar_t* const g_cmdDigitizeClippingPlaneDefineShowWindow;

#define SCRIPT_VERSION_DECLARATION  L"version \"5.0\""
#define GIMBAL_LOCK_THRESHOLD       0.000001
#define NUMERIC_ERROR_THRESHOLD     1e-5
#define RAD_TO_DEG( rad_ )          ( ( rad_ ) * 180.0 / M_PI )
#define DEG_TO_RAD( deg_ )          ( ( deg_ ) * M_PI / 180.0 )

enum EEvents
{
    E_DATA_OBJECT_CHANGE,
    E_DISCONNECT,
    E_PASS_START,
    E_PASS_STOP,
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

enum EMatrixParamIndex
{
    MAT_ALPHA = 0,
    MAT_THETA,
    MAT_PHI
};

extern const std::wstring g_OnOffChoiceStrings[ E_OO_NB_VALUES ];
extern const std::wstring g_StandardAxes[ NB_STD_AXES ];

extern DWORD g_cookieCommandCenter;
extern DWORD g_cookieHost;
extern DWORD g_cookieScannerFeedback;

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

HRESULT GITGetInterfaceFromGlobal( DWORD dwCookie_, REFIID riid_, void** ppv_ );
HRESULT GITRegisterInterfaceInGlobal( IUnknown* pUnk_, REFIID riid_, DWORD* pdwCookie_ );
HRESULT GITRevokeInterfaceFromGlobal( DWORD& dwCookie_ );

EOnOffChoice OnOffConvertStringToEnum( const std::wstring& argValue );
std::wstring OnOffGetPossibleValuesString();
