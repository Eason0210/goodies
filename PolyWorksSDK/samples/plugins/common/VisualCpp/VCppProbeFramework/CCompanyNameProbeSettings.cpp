// =================================================================================================
//   User configuration setting management
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameProbeSettings.h"

#include <PolyWorksSDK/COM/IIMSettingsRepository.h>
#include <assert.h>

#include "CCompanyNameProbe.h"
#include "CTSetting.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================
#define SETTINGS_REPOSITORY_DO( function_call )                                         \
    {                                                                                   \
        CComPtr < IIMSettingsRepository > pSettings;                                    \
        if ( ( GITGetInterfaceFromGlobal( theCompanyNameProbe().m_cookieHost,           \
                                          IID_IIMSettingsRepository,                    \
                                          ( void** )&pSettings ) == S_OK ) &&           \
             ( pSettings != nullptr ) )                                                 \
        {                                                                               \
            pSettings->function_call;                                                   \
        }                                                                               \
    }

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================
extern const wchar_t* PLUGIN_NAME;

// ===========================================================================
//                                                             1111111111222222222233
// Parameter names (max 31 characters)                1234567890123456789012345678901
// Double
static const wchar_t* _automaticTriggerDistanceStr = L"AUTOMATIC_TRIGGER_DISTANCE_MM";
static const wchar_t* _continuousDistanceDistStr   = L"CONTINUOUS_DISTANCE_DIST_MM";
static const wchar_t* _measAutoTriggerToleranceStr = L"MEAS_AUTO_TRIGGER_TOLERANCE_MM";

static const int NB_DOUBLE_SETTINGS = 3;

// Long
static const wchar_t* _compensationMethodStr   = L"COMPENSATION_METHOD";
static const wchar_t* _continuousTimeDelayStr  = L"CONTINUOUS_TIME_DELAY_MS";
static const wchar_t* _measAutoTriggerDelayStr = L"MEAS_AUTO_TRIGGER_DELAY_MS";
static const wchar_t* _probingModeStr          = L"PROBING_MODE";
static const wchar_t* _useAutomaticTrigger     = L"USE_AUTOMATIC_TRIGGER";
static const wchar_t* _useMeasAutoTriggerStr   = L"USE_MEAS_AUTO_TRIGGER";
static const wchar_t* _useProbeAsMouseStr      = L"USE_PROBE_AS_MOUSE";

static const int NB_LONG_SETTINGS = 7;

// Strings
static const int NB_STRING_SETTINGS = 0;

// Matrices
static const int NB_MATRIX_SETTINGS = 0;

// Parameters default values
static CTSetting< double > _doubleSettings[ NB_DOUBLE_SETTINGS ] =
{
    //                   Name                          Def      User  Host
    CTSetting< double >( _automaticTriggerDistanceStr, 2.0, true, false ),
    CTSetting< double >( _continuousDistanceDistStr,   1.0, true, false ),
    CTSetting< double >( _measAutoTriggerToleranceStr, 0.2, true, false )
};

static CTSetting< long > _longSettings[ NB_LONG_SETTINGS ] =
{
    //                 Name                            Def                                User  Host
    // TODO: Set the default value of the compensation method to fit with the method you want to use
    CTSetting< long >( _compensationMethodStr,   E_COMP_METHOD_FIRST_POINT_VECTOR, true, false ),
    CTSetting< long >( _continuousTimeDelayStr,  100,                              true, false ),
    CTSetting< long >( _measAutoTriggerDelayStr, 1000,                             true, false ),
    CTSetting< long >( _probingModeStr,          E_FIRST_USER_MODE,                true, false ),
    CTSetting< long >( _useAutomaticTrigger,     0,                                true, false ),
    CTSetting< long >( _useMeasAutoTriggerStr,   0,                                true, false ),
    CTSetting< long >( _useProbeAsMouseStr,      0,                                true, false ),
};

// TODO: Uncomment following code if you define string settings
/*
   static CTSetting<std::wstring> _stringSettings[ NB_STRING_SETTINGS ] =
   {
    //                       Name                    Def         User  Host   Project
   };
 */

// TODO: Uncomment following code if you define matrix settings
/*
   static CTSetting<Matrix4D> _matrixSettings[ NB_MATRIX_SETTINGS ] =
   {
    //                       Name                    Def         User  Host   Project
   };
 */

// =================================================================================================
// ================================ TYPES, CLASSES, STRUCTURES =====================================

// =================================================================================================
// ================================== STATIC MEMBER VARIABLES ======================================

// =================================================================================================
// ===================================== GLOBAL VARIABLES ==========================================

// =================================================================================================
// ===================================== FUNCTION DEFINITIONS ======================================

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

    // On ajoute les éléments
    double* pDirectAccess = nullptr;
    assert( SUCCEEDED( ::SafeArrayAccessData( *pArrayMatrix_, ( void** ) &pDirectAccess ) ) );
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

// Singleton
CCompanyNameProbeSettings& theCompanyNameProbeSettings()
{
    static CCompanyNameProbeSettings settings;
    return settings;
}

// =================================================================================================
//   Constructor
// -------------------------------------------------------------------------------------------------
CCompanyNameProbeSettings::CCompanyNameProbeSettings()
: m_hostUnitsScalingFactor( 1.0 )
{
}

// =================================================================================================
double CCompanyNameProbeSettings::AutomaticTriggerDistanceGet()
{
    double automaticTriggerDistance = 0.0;
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueGet( PLUGIN_NAME, _automaticTriggerDistanceStr, &automaticTriggerDistance ) );
    return automaticTriggerDistance;
}

// =================================================================================================
void CCompanyNameProbeSettings::AutomaticTriggerDistanceSet( double automaticTriggerDistance_ )
{
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueSet( PLUGIN_NAME, _automaticTriggerDistanceStr, automaticTriggerDistance_ ) );
}

// =================================================================================================
ECompMethods CCompanyNameProbeSettings::CompensationMethodGet()
{
    long method = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _compensationMethodStr, ( long* ) &method ) );
    return static_cast< ECompMethods >( method );
}

// =================================================================================================
void CCompanyNameProbeSettings::CompensationMethodSet( ECompMethods method_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _compensationMethodStr, static_cast< long >( method_ ) ) );
}

// =============================================================================
double CCompanyNameProbeSettings::ContinuousDistanceDistGet()
{
    double dist = 0.0;
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueGet( PLUGIN_NAME, _continuousDistanceDistStr, &dist ) );
    return dist;
}

// =============================================================================
void CCompanyNameProbeSettings::ContinuousDistanceDistSet( double dist_ )
{
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueSet( PLUGIN_NAME, _continuousDistanceDistStr, dist_ ) );
}

// =============================================================================
long CCompanyNameProbeSettings::ContinuousTimeDelayGet()
{
    long delay = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _continuousTimeDelayStr, ( long* ) &delay ) );
    return delay;
}

// =============================================================================
void CCompanyNameProbeSettings::ContinuousTimeDelaySet( long delay_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _continuousTimeDelayStr, delay_ ) );
}

// =================================================================================================
// Returns scaling factor for application units usage
// -------------------------------------------------------------------------------------------------
double CCompanyNameProbeSettings::HostUnitsScalingFactorGet() const
{
    if ( m_hostUnitsScalingFactor > 0.0 )
    {
        return m_hostUnitsScalingFactor;
    }

    return 1.0;
}

// =================================================================================================
// Assigns scaling factor for application units usage
// -------------------------------------------------------------------------------------------------
bool CCompanyNameProbeSettings::HostUnitsScalingFactorSet( double scalingFactor_ )
{
    if ( scalingFactor_ <= 0.0 )
    {
        return false;
    }

    // Recording new scaling factor
    m_hostUnitsScalingFactor = scalingFactor_;

    return true;
}

// =============================================================================
long CCompanyNameProbeSettings::MeasurementAutomaticTriggerStabilityDelayGet()
{
    long delay = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _measAutoTriggerDelayStr, &delay ) );
    return delay;
}

// =============================================================================
void CCompanyNameProbeSettings::MeasurementAutomaticTriggerStabilityDelaySet( long delay_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _measAutoTriggerDelayStr, delay_ ) );
}

// =============================================================================
double CCompanyNameProbeSettings::MeasurementAutomaticTriggerStabilityToleranceGet()
{
    double tolerance = 0.0;
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueGet( PLUGIN_NAME, _measAutoTriggerToleranceStr, &tolerance ) );
    return tolerance;
}

// =============================================================================
void CCompanyNameProbeSettings::MeasurementAutomaticTriggerStabilityToleranceSet( double tolerance_ )
{
    // This value is units-dependent, it is saved in millimeters, the reference units
    SETTINGS_REPOSITORY_DO( DoubleValueSet( PLUGIN_NAME, _measAutoTriggerToleranceStr, tolerance_ ) );
}

// =============================================================================
ERecordModes CCompanyNameProbeSettings::ModeGet()
{
    ERecordModes mode = E_FIRST_USER_MODE;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _probingModeStr, ( long* ) &mode ) );
    return mode;
}

// =============================================================================
void CCompanyNameProbeSettings::ModeSet( ERecordModes mode_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _probingModeStr, ( long ) mode_ ) );

    // Transmit the value to the Probe
    theCompanyNameProbe().ModeSet( mode_ );
}

// =================================================================================================
bool CCompanyNameProbeSettings::UseAutomaticTriggerGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _useAutomaticTrigger, &useL ) );
    return ( useL == 1 ) ? true : false;
}

// =================================================================================================
void CCompanyNameProbeSettings::UseAutomaticTriggerSet( bool use_ )
{
    long useL = use_ ? 1 : 0;
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _useAutomaticTrigger, useL ) );
}

// =============================================================================
bool CCompanyNameProbeSettings::UseMeasurementAutomaticTriggerGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _useMeasAutoTriggerStr, &useL ) );
    return ( useL == 1 ) ? true : false;
}

// =============================================================================
void CCompanyNameProbeSettings::UseMeasurementAutomaticTriggerSet( bool use_ )
{
    long useL = use_ ? 1 : 0;
    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _useMeasAutoTriggerStr, useL ) );
}

// =============================================================================
bool CCompanyNameProbeSettings::UseProbeAsMouseGet()
{
    long useL = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( PLUGIN_NAME, _useProbeAsMouseStr, &useL ) );
    return ( useL == 1 ) ? true : false;
}

// =============================================================================
void CCompanyNameProbeSettings::UseProbeAsMouseSet( bool use_ )
{
    long useL = use_ ? 1 : 0;

    SETTINGS_REPOSITORY_DO( LongValueSet( PLUGIN_NAME, _useProbeAsMouseStr, useL ) );

    // Transmit the value to the Probe
    theCompanyNameProbe().UseProbeAsMouseSet( use_ );
}

// #######################################################################
// IIMSettings
// #######################################################################

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::DoubleSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = NB_DOUBLE_SETTINGS;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::DoubleSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ double __RPC_FAR*       pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );
    *pSettingName_      = ::SysAllocString( _doubleSettings[ settingIndex_ ].m_name.c_str() );
    *pDefaultValue_     = _doubleSettings[ settingIndex_ ].m_defaultValue;
    *pIsUserSpecific_   = _doubleSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
    *pIsHostSpecific_   = _doubleSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
    *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::LongSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = NB_LONG_SETTINGS;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::LongSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ long __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    ::SysFreeString( *pSettingName_ );
    *pSettingName_      = ::SysAllocString( _longSettings[ settingIndex_ ].m_name.c_str() );
    *pDefaultValue_     = _longSettings[ settingIndex_ ].m_defaultValue;
    *pIsUserSpecific_   = _longSettings[ settingIndex_ ].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
    *pIsHostSpecific_   = _longSettings[ settingIndex_ ].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
    *pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.

    return S_OK;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::StringSettingsNbGet(
    /* [out] */ long __RPC_FAR* nbSettings_ )
{
    if ( nbSettings_ != nullptr )
    {
        *nbSettings_ = NB_STRING_SETTINGS;
        return S_OK;
    }
    return S_FALSE;
}

// =============================================================================
STDMETHODIMP CCompanyNameProbeSettings::StringSettingGet(
    /* [in] */ long                     settingIndex_,
    /* [out] */ BSTR __RPC_FAR*         pSettingName_,
    /* [out] */ BSTR __RPC_FAR*         pDefaultValue_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
    /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ )
{
    if ( ( pSettingName_ == nullptr ) || ( pDefaultValue_ == nullptr ) || ( pIsUserSpecific_ == nullptr ) ||
         ( pIsHostSpecific_ == nullptr ) || ( pIsProjectSetting_ == nullptr ) )
    {
        return S_FALSE;
    }

    // TODO: Uncomment following code if you define string settings
    /*
       ::SysFreeString( *pSettingName_ );
     * pSettingName_ = ::SysAllocString( _stringSettings[settingIndex_].m_name.c_str() );
       ::SysFreeString( *pDefaultValue_ );
     * pDefaultValue_ = ::SysAllocString( _stringSettings[settingIndex_].m_defaultValue.c_str() );
     * pIsUserSpecific_ = _stringSettings[settingIndex_].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
     * pIsHostSpecific_ = _stringSettings[settingIndex_].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
     * pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
     */

    return S_OK;
}

//////////////// IIMSettings2 ////////////////////////

STDMETHODIMP CCompanyNameProbeSettings::MatrixSettingsNbGet(
    /* [retval][out] */ long* pNbSettings_ )
{
    if ( pNbSettings_ != nullptr )
    {
        *pNbSettings_ = NB_MATRIX_SETTINGS;

        return S_OK;
    }
    return S_FALSE;
}

// -------------------------------------------------------------------------------------------------

STDMETHODIMP CCompanyNameProbeSettings::MatrixSettingGet(
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

    // TODO: Uncomment following code if you define matrix settings
    /*
       ::SysFreeString( *pSettingName_ );

       if ( ( settingIndex_ >= 0 ) &&
         ( settingIndex_ < NB_MATRIX_SETTINGS ) )
       {
     * pSettingName_ = ::SysAllocString( _matrixSettings[settingIndex_].m_name.c_str() );
        assert( SafeArrayMatrixSet( _matrixSettings[settingIndex_].m_defaultValue, pDefaultValue_ ) );
     * pIsUserSpecific_ = _matrixSettings[settingIndex_].m_isUserSpecific ? VARIANT_TRUE : VARIANT_FALSE;
     * pIsHostSpecific_ = _matrixSettings[settingIndex_].m_isHostSpecific ? VARIANT_TRUE : VARIANT_FALSE;
     * pIsProjectSetting_ = VARIANT_FALSE;    // Project settings are not currently supported when using the IIMSettings2 interface.
       }
       else
       {
        assert( 0 );  // Invalid index
        return S_FALSE;
       }
     */

    return S_OK;
}
