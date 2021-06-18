// =================================================================================================
//   Manages the plug-in's settings.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScannerSettings.h"

#include <PolyWorksSDK/COM/IIMSettingsRepository2.h>
#include <PolyWorksSDK/COM/IIMSettingsRepository2_i.c>
#include <assert.h>

#include "CTSetting.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

#define SETTINGS_REPOSITORY_DO( function_call )                               \
    {                                                                         \
        CComPtr< IIMSettingsRepository2 > pSettings;                          \
        if ( ( GITGetInterfaceFromGlobal( g_cookieHost,                       \
                                          IID_IIMSettingsRepository2,         \
                                          ( void** )&pSettings ) == S_OK ) && \
             ( pSettings != nullptr ) )                                       \
        {                                                                     \
            pSettings->function_call;                                         \
        }                                                                     \
    }

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// Parameter names                                      1234567890123456789012345678901  // 31 chars max
// Double
static const wchar_t* _IMAMaxEdgeLengthStr     = L"IMA_MAX_EDGE_LENGTH";
static const wchar_t* _IMAInterpolationStepStr = L"IMA_INTERPOLATION_STEP";
static const wchar_t* _IMAMaxAngleStr          = L"IMA_MAX_ANGLE";

static const wchar_t* _IMIMinSearchDistStr = L"IMI_MIN_SEARCH_DISTANCE";
static const wchar_t* _IMIMaxSearchDistStr = L"IMI_MAX_SEARCH_DISTANCE";
static const wchar_t* _IMIMinHoleWidthStr  = L"IMI_MIN_HOLE_WIDTH";

// Long
static const wchar_t* _testModeStr           = L"TEST_MODE";
static const wchar_t* _nbLinesTransferredStr = L"NB_LINES_TRANSFERRED";
static const wchar_t* _refreshDelayStr       = L"REFRESH_DELAY";

static const wchar_t* _autoViewpointEnableStr    = L"AUTO_VIEWPOINT_ENABLE";
static const wchar_t* _autoViewpointZoomClsupStr = L"AUTO_VIEWPOINT_ZOOM_CLSUP";

static const wchar_t* _invertDigitizingVectorStr = L"INVERT_DIGITIZING_VECTORS";

static const wchar_t* _deviceVerticalAxisStr = L"DEVICE_VERTICAL_AXIS";

static const wchar_t* _IMAWindowPositionXStr        = L"IMA_WINDOW_POS_X";
static const wchar_t* _IMAWindowPositionYStr        = L"IMA_WINDOW_POS_Y";
static const wchar_t* _IMAOptionsWindowPositionXStr = L"IMA_OPT_WINDOW_POS_X";
static const wchar_t* _IMAOptionsWindowPositionYStr = L"IMA_OPT_WINDOW_POS_Y";

static const wchar_t* _IMIExtractNormalsStr         = L"IMI_EXTRACT_NORMALS";
static const wchar_t* _IMIRealTimeInspectionStr     = L"IMI_REAL_TIME_INSPECTION";
static const wchar_t* _IMIScanTypeStr               = L"IMI_SCAN_TYPE";
static const wchar_t* _IMIWindowPositionXStr        = L"IMI_WINDOW_POS_X";
static const wchar_t* _IMIWindowPositionYStr        = L"IMI_WINDOW_POS_Y";
static const wchar_t* _IMIOptionsWindowPositionXStr = L"IMI_OPT_WINDOW_POS_X";
static const wchar_t* _IMIOptionsWindowPositionYStr = L"IMI_OPT_WINDOW_POS_Y";
static const wchar_t* _IMISaveAsWindowPositionXStr  = L"IMI_SAVEAS_WINDOW_POS_X";
static const wchar_t* _IMISaveAsWindowPositionYStr  = L"IMI_SAVEAS_WINDOW_POS_Y";
static const wchar_t* _IMIRealTimeMeshing           = L"IMI_RTM";
static const wchar_t* _IMISharpEdgeMaxPtToPtDistStr = L"IMI_EDGE_MAX_PT_TO_PT_DIST";
static const wchar_t* _IMISharpEdgeMinAngleStr      = L"IMI_EDGE_MIN_ANGLE";

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

// =================================================================================================
// Gets a vector that assigns the same value to all scanning profiles
//
// Paramètre : value_ : Value to assign to all scanning profiles
//
// Note: Matrix settings are not supported as profile settings
// -------------------------------------------------------------------------------------------------
template< typename T >
std::vector< T > ProfileValuesGet( const T& value_ )
{
    std::vector< T > profileValues;
    profileValues.reserve( E_LAST_STD_SCAN_PROFILE + 1 );

    for ( int iProfile = E_FIRST_STD_SCAN_PROFILE; iProfile <= E_LAST_STD_SCAN_PROFILE; ++iProfile )
    {
        profileValues.push_back( value_ );
    }

    return profileValues;
}

// =============================================================================
// Inserts the 16 double elements of a 4x4 matrix in a safe array.
//
// Parameter: matrix_       : matrix to add
// Parameter: pArrayMatrix_ : safe array to fill (will first be created if it is a nullptr)
//
// Return: bool : true on success, otherwise false
// -----------------------------------------------------------------------------
static bool SafeArrayMatrixSet(
    const Matrix4D& matrix_,
    SAFEARRAY**     pArrayMatrix_ )
{
    if ( !( pArrayMatrix_ != nullptr ) )
    {
        return false;
    }

    LONG       index           = 0;
    const long nbRows          = 4;
    const long nbColumns       = 4;
    const long nbItemsInMatrix = nbRows * nbColumns;

    if ( *pArrayMatrix_ == nullptr )
    {
        *pArrayMatrix_ = SafeArrayCreateVector( VT_R8, 0, nbItemsInMatrix );
    }
    else
    {
        VARTYPE varType = VT_EMPTY;
        SafeArrayGetVartype( *pArrayMatrix_, &varType );

        // Elements must be of the same type
        if ( !( varType == VT_R8 ) )
        {
            return false;
        }

        SafeArrayGetUBound( *pArrayMatrix_, 1, &index );
        index++;    // To get actual element count

        // Preparing to add elements
        SAFEARRAYBOUND saBound;
        saBound.lLbound   = 0;
        saBound.cElements = index + nbItemsInMatrix;
        SafeArrayRedim( *pArrayMatrix_, &saBound );
    }

    // Add the elements
    double* pDirectAccess = nullptr;
    HRESULT hr            = ::SafeArrayAccessData( *pArrayMatrix_, ( void** ) &pDirectAccess );
    assert( SUCCEEDED( hr ) );

    for ( int iRow = 0; iRow < nbRows; iRow++ )
    {
        for ( int iCol = 0; iCol < nbColumns; iCol++ )
        {
            pDirectAccess[ index++ ] = matrix_( iRow, iCol );
        }
    }
    ::SafeArrayUnaccessData( *pArrayMatrix_ );

    return true;
}


// =================================================================================================
//   Return singleton of the class.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerSettings& theCompanyNameScannerSettings()
{
    static CCompanyNameScannerSettings settings;
    return settings;
}

// =================================================================================================
//   Constructor.
// -------------------------------------------------------------------------------------------------
CCompanyNameScannerSettings::CCompanyNameScannerSettings()
: m_hostApplication( E_APPLICATION_UNKNOWN )
, m_hostUnitsScalingFactor( 1.0 )
{
}


// =================================================================================================
// Add the plug-in settings
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::SettingsAdd()
{
    SettingsDoubleAdd();
    SettingsLongAdd();
    SettingsStringAdd();
    SettingsMatrixAdd();

    switch ( m_hostApplication )
    {
        case E_APPLICATION_IMALIGN:
            SettingsIMADoubleAdd();
            SettingsIMALongAdd();
            SettingsIMAStringAdd();
            SettingsIMAMatrixAdd();
            break;

        case E_APPLICATION_IMINSPECT:
            SettingsIMIDoubleAdd();
            SettingsIMILongAdd();
            SettingsIMIStringAdd();
            SettingsIMIMatrixAdd();
            break;

        default:
            assert( 0 ); // Unknown host application!
            break;
    }
}

void CCompanyNameScannerSettings::SettingsDoubleAdd()
{
    //                             Name                      Default value/Profile values       User  Host
}

void CCompanyNameScannerSettings::SettingsIMADoubleAdd()
{
    //                             Name                      Default value   User  Host
    m_doubleSettings.emplace_back( _IMAMaxEdgeLengthStr,     4.0,  true, true );
    m_doubleSettings.emplace_back( _IMAInterpolationStepStr, 0.4,  true, true );
    m_doubleSettings.emplace_back( _IMAMaxAngleStr,          75.0, true, true );
}

void CCompanyNameScannerSettings::SettingsIMIDoubleAdd()
{
    //                             Name                           Default value/Profile values  User  Host
    m_doubleSettings.emplace_back( _IMIMinSearchDistStr,          0.4,                     true, true );
    m_doubleSettings.emplace_back( _IMIMaxSearchDistStr,          4.0,                     true, true );
    m_doubleSettings.emplace_back( _IMIMinHoleWidthStr,           ProfileValuesGet( 4.0 ), true, true );
    m_doubleSettings.emplace_back( _IMISharpEdgeMaxPtToPtDistStr, 4.0,                     true, true );
    m_doubleSettings.emplace_back( _IMISharpEdgeMinAngleStr,      45.0,                    true, true );
}


void CCompanyNameScannerSettings::SettingsLongAdd()
{
    //                           Name                           Default value/Profile values                        User  Host
    m_longSettings.emplace_back( _testModeStr,           0,                        true, false );
    m_longSettings.emplace_back( _nbLinesTransferredStr, 4,                        true, false );
    m_longSettings.emplace_back( _refreshDelayStr,       ProfileValuesGet( 500L ), true, false );

    m_longSettings.emplace_back( _autoViewpointEnableStr,    1,  true, false );
    m_longSettings.emplace_back( _autoViewpointZoomClsupStr, 40, true, false );

    m_longSettings.emplace_back( _invertDigitizingVectorStr, ProfileValuesGet( 0L ), true, false );

    m_longSettings.emplace_back( _deviceVerticalAxisStr, ProfileValuesGet( static_cast< long >( E_Z_POS ) ), true, false );
}


void CCompanyNameScannerSettings::SettingsIMALongAdd()
{
    //                           Name                           Def      User  Host
    m_longSettings.emplace_back( _IMAWindowPositionXStr,        50,  true, true );
    m_longSettings.emplace_back( _IMAWindowPositionYStr,        50,  true, true );
    m_longSettings.emplace_back( _IMAOptionsWindowPositionXStr, 100, true, true );
    m_longSettings.emplace_back( _IMAOptionsWindowPositionYStr, 100, true, true );
}


void CCompanyNameScannerSettings::SettingsIMILongAdd()
{
    //                           Name                            Default value/Profile values     User  Host
    m_longSettings.emplace_back( _IMIExtractNormalsStr,         1,                   true, true );
    m_longSettings.emplace_back( _IMIRealTimeInspectionStr,     0,                   true, true );
    m_longSettings.emplace_back( _IMIScanTypeStr,               E_SCAN_TYPE_SURFACE, true, true );
    m_longSettings.emplace_back( _IMIWindowPositionXStr,        50,                  true, true );
    m_longSettings.emplace_back( _IMIWindowPositionYStr,        50,                  true, true );
    m_longSettings.emplace_back( _IMIOptionsWindowPositionXStr, 100,                 true, true );
    m_longSettings.emplace_back( _IMIOptionsWindowPositionYStr, 100,                 true, true );
    m_longSettings.emplace_back( _IMISaveAsWindowPositionXStr,  100,                 true, true );
    m_longSettings.emplace_back( _IMISaveAsWindowPositionYStr,  100,                 true, true );

    m_longSettings.emplace_back( _IMIRealTimeMeshing, 1, true, true );
}


void CCompanyNameScannerSettings::SettingsStringAdd()
{
    //                                         Name                   Default value/Profile values   User  Host
}


void CCompanyNameScannerSettings::SettingsIMAStringAdd()
{
    //                                         Name                   Default value    User  Host
}


void CCompanyNameScannerSettings::SettingsIMIStringAdd()
{
    //                                         Name                   Default value/Profile values   User  Host
}


// Note: Matrix settings are not supported as profile settings
void CCompanyNameScannerSettings::SettingsMatrixAdd()
{
    //                                         Name                   Default value    User  Host
}


void CCompanyNameScannerSettings::SettingsIMAMatrixAdd()
{
    //                                         Name                   Default value    User  Host
}


void CCompanyNameScannerSettings::SettingsIMIMatrixAdd()
{
    //                                         Name                   Default value    User  Host
}

// =================================================================================================
//   Returns Auto Viewpoint Zoom Close Up.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::AutoViewpointZoomCloseUpGet()
{
    long closeUpFct = 1;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _autoViewpointZoomClsupStr, &closeUpFct ) );
    return closeUpFct;
}


// =================================================================================================
//   Assigns Auto Viewpoint Zoom Close Up.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::AutoViewpointZoomCloseUpSet( long closeUpFct_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _autoViewpointZoomClsupStr, closeUpFct_ ) );
}


// =================================================================================================
//   Returns cursor segments max distance.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::CursorSegmentsMaxDistGet()
{
    double maxDist = 0;

    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        maxDist = theCompanyNameScannerSettings().IMIMaxSearchDistGet();
    }
    else if ( m_hostApplication == E_APPLICATION_IMALIGN )
    {
        maxDist = theCompanyNameScannerSettings().IMAMaxEdgeLengthGet();
    }

    return maxDist;
}

// =================================================================================================
//   Returns device vertical axis.
// -------------------------------------------------------------------------------------------------
EStdAxis CCompanyNameScannerSettings::DeviceVerticalAxisGet()
{
    EStdAxis verticalAxis = E_Z_POS;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _deviceVerticalAxisStr, ( long* ) &verticalAxis ) );
    return verticalAxis;
}

// =================================================================================================
//   Assigns device vertical axis.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::DeviceVerticalAxisSet( EStdAxis verticalAxis_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _deviceVerticalAxisStr, ( long ) verticalAxis_ ) );
}

// =================================================================================================
//   Returns host application.
// -------------------------------------------------------------------------------------------------
EHostApplication CCompanyNameScannerSettings::HostApplicationGet()
{
    return m_hostApplication;
}

// =================================================================================================
//   Returns scaling factor for application units usage.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::HostUnitsScalingFactorGet() const
{
    if ( m_hostUnitsScalingFactor > 0.0 )
    {
        return m_hostUnitsScalingFactor;
    }

    return 1.0;
}

// =================================================================================================
//   Assigns scaling factor for application units usage,
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::HostUnitsScalingFactorSet( double scalingFactor_ )
{
    if ( scalingFactor_ <= 0.0 )
    {
        return false;
    }

    // Recording new scaling factor
    m_hostUnitsScalingFactor = scalingFactor_;

    return true;
}

// =================================================================================================
//   Returns interpolation step.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMAInterpolationStepGet()
{
    double step = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMAInterpolationStepStr, &step ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return step;
}


// =================================================================================================
//   Assigns interpolation step.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAInterpolationStepSet( double step_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMAInterpolationStepStr, step_ ) );
}


// =================================================================================================
//   Returns Max Angle.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMAMaxAngleGet()
{
    double maxAngle = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMAMaxAngleStr, &maxAngle ) );
    return maxAngle;
}


// =================================================================================================
//   Assigns Max Angle.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAMaxAngleSet( double maxAngle_ )
{
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMAMaxAngleStr, maxAngle_ ) );
}


// =================================================================================================
//   Returns Max Edge Length.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMAMaxEdgeLengthGet()
{
    double maxEdgeLength = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMAMaxEdgeLengthStr, &maxEdgeLength ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return maxEdgeLength;
}


// =================================================================================================
//   Assigns Max Edge Length.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAMaxEdgeLengthSet( double maxEdgeLength_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMAMaxEdgeLengthStr, maxEdgeLength_ ) );
}


// =================================================================================================
//   Returns Window X Position for IMAlign.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMAWindowPositionXGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMAWindowPositionXStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Window X Position for IMAlign.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAWindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMAWindowPositionXStr, position_ ) );
}


// =================================================================================================
//   Returns Window Y Position for IMAlign.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMAWindowPositionYGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMAWindowPositionYStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Window Y Position for IMAlign.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAWindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMAWindowPositionYStr, position_ ) );
}


// =================================================================================================
//   Returns Options Window X Position for IMAlign.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMAOptionsWindowPositionXGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMAOptionsWindowPositionXStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Options Window X Position for IMAlign.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAOptionsWindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMAOptionsWindowPositionXStr, position_ ) );
}


// =================================================================================================
//   Returns Options Window Y Position for IMAlign.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMAOptionsWindowPositionYGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMAOptionsWindowPositionYStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Options Window Y Position for IMAlign.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMAOptionsWindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMAOptionsWindowPositionYStr, position_ ) );
}


// =================================================================================================
//   Returns extract normals state.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::IMIExtractNormalsGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIExtractNormalsStr, &useL ) );
    return ( useL == 1 ) ? true : false;
}


// =================================================================================================
//   Assigns extract normals state.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIExtractNormalsSet( bool use_ )
{
    long useL = use_ ? 1 : 0;

    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIExtractNormalsStr, useL ) );
}


// =================================================================================================
//   Returns Max Search Distance.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMIMaxSearchDistGet()
{
    double distance = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMIMaxSearchDistStr, &distance ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return distance;
}


// =================================================================================================
//   Assigns Max Search Distance.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIMaxSearchDistSet( double distance_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMIMaxSearchDistStr, distance_ ) );
}


// =================================================================================================
//   Returns Min Search Distance.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMIMinSearchDistGet()
{
    double distance = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMIMinSearchDistStr, &distance ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return distance;
}


// =================================================================================================
//   Assigns Min Search Distance.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIMinSearchDistSet( double distance_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMIMinSearchDistStr, distance_ ) );
}

// =================================================================================================
//   Returns Min Hole Width.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMIMinHoleWidthGet()
{
    double distance = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMIMinHoleWidthStr, &distance ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return distance;
}


// =================================================================================================
//   Assigns Min Hole Width.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIMinHoleWidthSet( double distance_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMIMinHoleWidthStr, distance_ ) );
}


// =================================================================================================
//   Returns Real-Time Inspection state,
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::IMIRealTimeInspectionGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIRealTimeInspectionStr, &useL ) );
    return ( useL == 1 ) ? true : false;
}


// =================================================================================================
//   Assigns Real-Time Inspection state.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIRealTimeInspectionSet( bool use_ )
{
    long useL = use_ ? 1 : 0;

    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIRealTimeInspectionStr, useL ) );
}


// =================================================================================================
//   Returns Real-Time Meshing state.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::IMIRealTimeMeshingGet()
{
    bool rtm = false;
    // Real-time meshing can only be configured in PolyWorks|Inspector
    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        long useL = 0;
        SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIRealTimeMeshing, &useL ) );
        rtm = ( useL == 1 );
    }
    return rtm;
}

// =================================================================================================
//   Assigns Real-Time Meshing state.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIRealTimeMeshingSet( bool use_ )
{
    // Real-time meshing can only be configured in PolyWorks|Inspector
    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        long useL = use_ ? 1 : 0;
        SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIRealTimeMeshing, useL ) );
    }
}

// =================================================================================================
//   Returns Sharp Edge Max Point To Point Distance.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMISharpEdgeMaxPointToPointDistanceGet()
{
    double distance = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMISharpEdgeMaxPtToPtDistStr, &distance ) );
    // TODO: This value is units-dependent, so if you saved it in a reference units (i.e. millimeters),
    //       you might want to apply a units scaling factor to it
    return distance;
}

// =================================================================================================
//   Assigns Sharp Edge Max Point To Point Distance.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMISharpEdgeMaxPointToPointDistanceSet( double distance_ )
{
    // TODO: This value is units-dependent, so you might want to scale it back to a reference units
    //       (i.e. millimeters) before saving it
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMISharpEdgeMaxPtToPtDistStr, distance_ ) );
}

// =================================================================================================
//   Returns Sharp Edge Minimum angle.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::IMISharpEdgeMinAngleGet()
{
    double angle = 0;
    SETTINGS_REPOSITORY_DO( DoubleValueGet( g_PluginName, _IMISharpEdgeMinAngleStr, &angle ) );
    return angle;
}

// =================================================================================================
//   Assigns Sharp Edge Minimum angle.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMISharpEdgeMinAngleSet( double angle_ )
{
    SETTINGS_REPOSITORY_DO( DoubleValueSet( g_PluginName, _IMISharpEdgeMinAngleStr, angle_ ) );
}

// =================================================================================================
//   Returns Scan Type.
// -------------------------------------------------------------------------------------------------
EScanTypes CCompanyNameScannerSettings::ScanTypeGet()
{
    EScanTypes scanType = E_SCAN_TYPE_SURFACE;

    // The scan type can only be configured in PolyWorks|Inspector, while in IMAlign it is always Surface
    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIScanTypeStr, ( long* ) &scanType ) );
    }
    return scanType;
}


// =================================================================================================
//   Assigns Scan Type.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::ScanTypeSet( EScanTypes scanType_ )
{
    // The scan type can only be configured in PolyWorks|Inspector, while in IMAlign it is always Surface
    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIScanTypeStr, ( long ) scanType_ ) );
    }
}


// =================================================================================================
//   Returns Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMIWindowPositionXGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIWindowPositionXStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIWindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIWindowPositionXStr, position_ ) );
}


// =================================================================================================
//   Returns Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMIWindowPositionYGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIWindowPositionYStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIWindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIWindowPositionYStr, position_ ) );
}


// =================================================================================================
//   Returns Options Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMIOptionsWindowPositionXGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIOptionsWindowPositionXStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Options Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIOptionsWindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIOptionsWindowPositionXStr, position_ ) );
}


// =================================================================================================
//   Returns Options Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMIOptionsWindowPositionYGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMIOptionsWindowPositionYStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Options Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMIOptionsWindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMIOptionsWindowPositionYStr, position_ ) );
}


// =================================================================================================
//   Returns Save As Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMISaveAsWindowPositionXGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMISaveAsWindowPositionXStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Save As Window X Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMISaveAsWindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMISaveAsWindowPositionXStr, position_ ) );
}


// =================================================================================================
//   Returns Save As Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::IMISaveAsWindowPositionYGet()
{
    long pos = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _IMISaveAsWindowPositionYStr, &pos ) );
    return pos;
}


// =================================================================================================
//   Assigns Save As Window Y Position for PolyWorks|Inspector.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::IMISaveAsWindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _IMISaveAsWindowPositionYStr, position_ ) );
}


// =================================================================================================
//   Initialize settings for the application.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::Initialize( const EHostApplication application_ )
{
    if ( ( application_ != E_APPLICATION_UNKNOWN ) &&
         ( m_hostApplication == E_APPLICATION_UNKNOWN ) )
    {
        m_hostApplication = application_;
        SettingsAdd();
    }
    else
    {
        assert( 0 );
    }
}


// =================================================================================================
//   Indicates if application is initialized.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::IsInitialized()
{
    return m_hostApplication != E_APPLICATION_UNKNOWN;
}


// =================================================================================================
//   Returns Invert Digitizing Vectors.
// -------------------------------------------------------------------------------------------------
EInvertDigitizingVectors CCompanyNameScannerSettings::InvertDigitizingVectorsGet()
{
    long invert = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _invertDigitizingVectorStr, &invert ) );
    return ( EInvertDigitizingVectors ) invert;
}


// =================================================================================================
//   Assigns Invert Digitizing Vectors.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::InvertDigitizingVectorsSet( EInvertDigitizingVectors invert_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _invertDigitizingVectorStr, ( long ) invert_ ) );
}


// =================================================================================================
//   Returns Number of Lines transferred.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::NbLinesTransferredGet()
{
    long nbLines = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _nbLinesTransferredStr, &nbLines ) );
    return nbLines;
}


// =================================================================================================
//   Assigns Number of Lines transferred.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::NbLinesTransferredSet( long nbLines_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _nbLinesTransferredStr, nbLines_ ) );
}


// =================================================================================================
//   Returns Refresh Delay.
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::RefreshDelayGet()
{
    long delay = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _refreshDelayStr, &delay ) );
    return delay;
}


// =================================================================================================
//   Assigns Refresh Delay.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::RefreshDelaySet( long delay_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _refreshDelayStr, delay_ ) );
}

// =================================================================================================
//   Gets scanning profile settings
//
// Parameter : profileSettings_ : [OUT] Profile settings
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::ScanningProfileSettingsGet( TWStrings& profileSettings_ ) const
{
    for ( const auto& doubleSetting : m_doubleSettings )
    {
        if ( doubleSetting.IsProfileSetting() )
        {
            profileSettings_.emplace_back( doubleSetting.m_name );
        }
    }

    for ( const auto& longSetting : m_longSettings )
    {
        if ( longSetting.IsProfileSetting() )
        {
            profileSettings_.emplace_back( longSetting.m_name );
        }
    }

    for ( const auto& stringSetting : m_stringSettings )
    {
        if ( stringSetting.IsProfileSetting() )
        {
            profileSettings_.emplace_back( stringSetting.m_name );
        }
    }

    for ( const auto& matrixSetting : m_matrixSettings )
    {
        if ( matrixSetting.IsProfileSetting() )
        {
            profileSettings_.emplace_back( matrixSetting.m_name );
        }
    }
}

// =================================================================================================
//   Gets standard scanning profile double value.
//
// Parameter : standardProfile_ : [IN]  Standard profile name
// Parameter : setting_         : [IN]  Setting name
// Parameter : value_           : [OUT] Value
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::StandardScanningProfileDoubleSettingValueGet(
    EStandardScanningProfiles standardProfile_,
    const std::wstring&       setting_,
    double&                   value_ ) const
{
    for ( const auto& doubleSetting : m_doubleSettings )
    {
        if ( ( std::wstring( doubleSetting.m_name ) == setting_ ) && ( doubleSetting.IsProfileSetting() ) )
        {
            if ( !( ( standardProfile_ >= 0 ) &&
                    ( static_cast< size_t >( standardProfile_ ) < doubleSetting.m_stdProfileValues.size() ) ) )
            {
                break;
            }

            value_ = doubleSetting.m_stdProfileValues[ standardProfile_ ];
            return true;
        }
    }

    assert( 0 );
    value_ = 0.0;

    return false;
}

// =================================================================================================
//   Gets standard scanning profile long value.
//
// Parameter : standardProfile_ : [IN]  Standard profile name
// Parameter : setting_         : [IN]  Setting name
// Parameter : value_           : [OUT] Value
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::StandardScanningProfileLongSettingValueGet(
    EStandardScanningProfiles standardProfile_,
    const std::wstring&       setting_,
    long&                     value_ ) const
{
    for ( const auto& longSetting : m_longSettings )
    {
        if ( ( std::wstring( longSetting.m_name ) == setting_ ) && ( longSetting.IsProfileSetting() ) )
        {
            if ( !( ( standardProfile_ >= 0 ) &&
                    ( static_cast< size_t >( standardProfile_ ) < longSetting.m_stdProfileValues.size() ) ) )
            {
                break;
            }

            value_ = longSetting.m_stdProfileValues[ standardProfile_ ];
            return true;
        }
    }

    assert( 0 );
    value_ = 0;

    return false;
}

// =================================================================================================
//   Gets standard scanning profile string value.
//
// Parameter : standardProfile_ : [IN]  Standard profile name
// Parameter : setting_         : [IN]  Setting name
// Parameter : value_           : [OUT] Value
//
// Return : true if success, false otherwise
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::StandardScanningProfileStringSettingValueGet(
    EStandardScanningProfiles standardProfile_,
    const std::wstring&       setting_,
    std::wstring&             value_ ) const
{
    for ( const auto& stringSetting : m_stringSettings )
    {
        if ( ( std::wstring( stringSetting.m_name ) == setting_ ) && ( stringSetting.IsProfileSetting() ) )
        {
            if ( !( ( standardProfile_ >= 0 ) &&
                    ( static_cast< size_t >( standardProfile_ ) < stringSetting.m_stdProfileValues.size() ) ) )
            {
                break;
            }

            value_ = stringSetting.m_stdProfileValues[ standardProfile_ ];
            return true;
        }
    }

    assert( 0 );
    value_ = L"";

    return false;
}


// =================================================================================================
//   Returns Test Mode state.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::TestModeGet()
{
    long useL = 0;
    if ( m_hostApplication == E_APPLICATION_IMINSPECT )
    {
        SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _testModeStr, &useL ) );
    }
    return ( useL == 1 ) ? true : false;
}


// =================================================================================================
//   Assigns Test Mode state.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::TestModeSet( bool use_ )
{
    long useL = use_ ? 1 : 0;

    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _testModeStr, useL ) );
}


// =================================================================================================
//   Returns Auto Viewpoint state.
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::UseAutoViewpointGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, _autoViewpointEnableStr, &useL ) );
    return ( useL == 1 ) ? true : false;
}


// =================================================================================================
//   Assigns Auto Viewpoint state.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::UseAutoViewpointSet( bool use_ )
{
    long useL = use_ ? 1 : 0;

    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, _autoViewpointEnableStr, useL ) );
}


//////////////// IIMSettings ////////////////////////

STDMETHODIMP CCompanyNameScannerSettings::DoubleSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = ( long )m_doubleSettings.size();

        return S_OK;
    }
    return S_FALSE;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::DoubleSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ double*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );
    if ( ( settingIndex_ >= 0 ) &&
         ( settingIndex_ < ( long )m_doubleSettings.size() ) )
    {
        *pSettingName_      = ::SysAllocString( m_doubleSettings[ settingIndex_ ].m_name.c_str() );
        *pDefaultValue_     = m_doubleSettings[ settingIndex_ ].m_defaultValue;
        *pIsUserSpecific_   = m_doubleSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsHostSpecific_   = m_doubleSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
    }
    else
    {
        assert( 0 );  // Invalid index
        return S_FALSE;
    }

    return S_OK;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::LongSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = ( long )m_longSettings.size();

        return S_OK;
    }
    return S_FALSE;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::LongSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ long*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );
    if ( ( settingIndex_ >= 0 ) &&
         ( settingIndex_ < ( long )m_longSettings.size() ) )
    {
        *pSettingName_      = ::SysAllocString( m_longSettings[ settingIndex_ ].m_name.c_str() );
        *pDefaultValue_     = m_longSettings[ settingIndex_ ].m_defaultValue;
        *pIsUserSpecific_   = m_longSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsHostSpecific_   = m_longSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
    }
    else
    {
        assert( 0 );  // Invalid index
        return S_FALSE;
    }

    return S_OK;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::StringSettingsNbGet(
    /* [out] */ long* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = ( long )m_stringSettings.size();

        return S_OK;
    }
    return S_FALSE;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::StringSettingGet(
    /* [in] */ long           settingIndex_,
    /* [out] */ BSTR*         pSettingName_,
    /* [out] */ BSTR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );
    ::SysFreeString( *pDefaultValue_ );
    if ( ( settingIndex_ >= 0 ) &&
         ( settingIndex_ < ( long )m_stringSettings.size() ) )
    {
        *pSettingName_      = ::SysAllocString( m_stringSettings[ settingIndex_ ].m_name.c_str() );
        *pDefaultValue_     = ::SysAllocString( m_stringSettings[ settingIndex_ ].m_defaultValue.c_str() );
        *pIsUserSpecific_   = m_stringSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsHostSpecific_   = m_stringSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
    }
    else
    {
        assert( 0 );  // Invalid index
        return S_FALSE;
    }

    return S_OK;
}

//////////////// IIMSettings2 ////////////////////////

STDMETHODIMP CCompanyNameScannerSettings::MatrixSettingsNbGet(
    /* [retval][out] */ long* pNbSettings_ )
{
    if ( pNbSettings_ != nullptr )
    {
        *pNbSettings_ = ( long )m_matrixSettings.size();

        return S_OK;
    }
    return S_FALSE;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameScannerSettings::MatrixSettingGet(
    /* [in] */ long               settingIndex_,
    /* [out][in] */ BSTR*         pSettingName_,
    /* [out][in] */ SAFEARRAY**   pDefaultValue_,
    /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
    /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
    /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );

    if ( ( settingIndex_ >= 0 ) &&
         ( settingIndex_ < ( long )m_matrixSettings.size() ) )
    {
        *pSettingName_ = ::SysAllocString( m_matrixSettings[ settingIndex_ ].m_name.c_str() );
        bool result = SafeArrayMatrixSet( m_matrixSettings[ settingIndex_ ].m_defaultValue, pDefaultValue_ );
        assert( result );
        *pIsUserSpecific_   = m_matrixSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsHostSpecific_   = m_matrixSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
        *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
    }
    else
    {
        assert( 0 );  // Invalid index
        return S_FALSE;
    }

    return S_OK;
}
