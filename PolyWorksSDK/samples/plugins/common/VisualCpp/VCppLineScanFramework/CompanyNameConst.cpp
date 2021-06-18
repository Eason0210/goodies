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

#define CMD_PREFIX                  L"DIGITIZE DEVICE COMPANY_NAME LINE_SCANNER"

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

const wchar_t* const g_PluginName = L"CompanyName Line Scanner";  // The name should not be longer than 31 characters

const wchar_t* const g_cmdAutoViewpointSet                = L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT";
const wchar_t* const g_cmdAutoViewpointVerticalAxisSet    = L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT DEVICE_VERTICAL_AXIS";
const wchar_t* const g_cmdAutoViewpointCloseUpZoomSet     = L"DIGITIZE DISPLAY AUTOMATIC_VIEWPOINT CLOSE_UP SCAN_LINE_ZOOM";
const wchar_t* const g_cmdSharpEdgeMaxPointToPointDistSet = CMD_PREFIX L" SCAN BOUNDARY MAX_POINT_TO_POINT_DIST";
const wchar_t* const g_cmdSharpEdgeMaxPointToPointDistGet = CMD_PREFIX L" SCAN BOUNDARY MAX_POINT_TO_POINT_DIST GET";
const wchar_t* const g_cmdSharpEdgeMinAngleSet            = CMD_PREFIX L" SCAN BOUNDARY MIN_EDGE_ANGLE";
const wchar_t* const g_cmdSharpEdgeMinAngleGet            = CMD_PREFIX L" SCAN BOUNDARY MIN_EDGE_ANGLE GET";
const wchar_t* const g_cmdOptionsDlgPropertyGridLog       = CMD_PREFIX L" SCAN OPTIONS DLG PROPERTY_GRID LOG";

const wchar_t* const g_cmdConfigModifyDefaultNameSurfaceScanGet              = L"CONFIG MODIFY DEFAULT_NAME SURFACE_SCAN GET";
const wchar_t* const g_cmdConfigModifyDefaultNameBoundaryScanGet             = L"CONFIG MODIFY DEFAULT_NAME BOUNDARY_SCAN GET";
const wchar_t* const g_cmdDigitizeDeviceScanSurfaceDataObjectName            = L"DIGITIZE DEVICE SCAN SURFACE DATA_OBJECT NAME";
const wchar_t* const g_cmdDigitizeDeviceScanBoundaryDataObjectName           = L"DIGITIZE DEVICE SCAN BOUNDARY DATA_OBJECT NAME";
const wchar_t* const g_cmdDigitizeDeviceScanTypeGet                          = L"DIGITIZE DEVICE SCAN TYPE GET";
const wchar_t* const g_cmdDigitizeDeviceScanTypeSet                          = L"DIGITIZE DEVICE SCAN TYPE";
const wchar_t* const g_cmdDigitizeClippingPlaneGet                           = L"DIGITIZE LINE_SCAN SURFACE CLIPPING_PLANE GET";
const wchar_t* const g_cmdDigitizeClippingPlaneSet                           = L"DIGITIZE LINE_SCAN SURFACE CLIPPING_PLANE";
const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMSet                     = L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING";
const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMGet                     = L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING GET";
const wchar_t* const g_cmdDigitizeLineScanSurfaceRQTMFinalDataObjCreate      = L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING FINAL_DATA_OBJECT CREATE";
const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeGet = L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING FINAL_DATA_OBJECT DATA_TYPE GET";
const wchar_t* const g_cmdDigitizeLineScanSurfaceRTQMFinalDataObjDataTypeSet = L"DIGITIZE LINE_SCAN SURFACE REAL_TIME_QUALITY_MESHING FINAL_DATA_OBJECT DATA_TYPE";
const wchar_t* const g_cmdDigitizeClippingPlaneDefinedDateTimeGet            = L"DIGITIZE CLIPPING_PLANE DEFINED DATE_TIME GET";
const wchar_t* const g_cmdDigitizeClippingPlaneDefinedGet                    = L"DIGITIZE CLIPPING_PLANE DEFINED GET";
const wchar_t* const g_cmdDigitizeClippingPlaneDefineShowWindow              = L"DIGITIZE CLIPPING_PLANE DEFINE SHOW_WINDOW";

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
        // Some people reported compiler issues with toupper, so we use static_cast to remove any type ambiguity
        std::transform( firstStr_.begin(), firstStr_.end(), m_firstStr.begin(), static_cast< int ( * )( int ) >( toupper ) );
    }

    bool operator()( const TString& secondStr_ ) const
    {
        // Transform second string to upper case
        TString secondStr;
        secondStr.resize( secondStr_.size() );
        // Some people reported compiler issues with toupper, so we use static_cast to remove any type ambiguity
        std::transform( secondStr_.begin(), secondStr_.end(), secondStr.begin(), static_cast< int ( * )( int ) >( toupper ) );

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
