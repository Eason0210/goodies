// =================================================================================================
// Manages the plug-in's settings.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include "stdafx.h"

#include "CCompanyNameScannerSettings.h"

#include <PolyWorksSDK/COM/IIMSettingsRepository2.h>
#include <PolyWorksSDK/COM/IIMSettingsRepository2_i.c>

#include "CompanyNameConst.h"
#include "CTSetting.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// =========================================== MACROS ==============================================

#define SETTINGS_REPOSITORY_DO( function_call )                               \
    {                                                                         \
        CComPtr < IIMSettingsRepository > pSettings;                          \
        if ( ( GITGetInterfaceFromGlobal( g_cookieHost,                       \
                                          IID_IIMSettingsRepository2,         \
                                          (void**)& pSettings ) == S_OK ) &&  \
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

// Long
static const wchar_t* g_newDevicePositionOnScan = L"NEW_DEV_POS_ON_SCAN";
static const wchar_t* g_windowPositionXStr      = L"WINDOW_POS_X";
static const wchar_t* g_windowPositionYStr      = L"WINDOW_POS_Y";

// Strings

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
: m_hostUnitsScalingFactor( 1.0 )
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
}

void CCompanyNameScannerSettings::SettingsDoubleAdd()
{
    //                                             Name                      Default value/Profile values       User  Host
}

void CCompanyNameScannerSettings::SettingsLongAdd()
{
    //                           Name                           Default value/Profile values    User  Host
    m_longSettings.emplace_back( g_newDevicePositionOnScan, 0,  true, true );
    m_longSettings.emplace_back( g_windowPositionXStr,      50, true, true );
    m_longSettings.emplace_back( g_windowPositionYStr,      50, true, true );
}

void CCompanyNameScannerSettings::SettingsStringAdd()
{
    //                           Name                   Default value/Profile values   User  Host
}

// Note: Matrix settings are not supported as profile settings
void CCompanyNameScannerSettings::SettingsMatrixAdd()
{
    //                           Name                   Default value    User  Host
}

// =================================================================================================
//   Returns scaling factor for application units usage.
// -------------------------------------------------------------------------------------------------
double CCompanyNameScannerSettings::HostUnitsScalingFactorGet() const
{
    return m_hostUnitsScalingFactor;
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
//   Load settings.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::SettingsReload()
{
    SETTINGS_REPOSITORY_DO( SettingsLoad( g_PluginName ) );
}


// =================================================================================================
//   Save settings.
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::SettingsSave()
{
    SETTINGS_REPOSITORY_DO( SettingsSave( g_PluginName ) );
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
        assert( SafeArrayMatrixSet( m_matrixSettings[ settingIndex_ ].m_defaultValue, pDefaultValue_ ) );
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

// =================================================================================================
// Returns whether a new position will be created during a scan
// -------------------------------------------------------------------------------------------------
bool CCompanyNameScannerSettings::NewDevicePositionCreateOnScanGet() const
{
    long value = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, g_newDevicePositionOnScan, &value ) );
    return value != 0;
}

// =================================================================================================
// Specifies whether a new position will be created during a scan
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::NewDevicePositionCreateOnScanSet( bool value_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, g_newDevicePositionOnScan, value_ ? 1 : 0 ) );
}

// =================================================================================================
//   Returns Window X Position
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::WindowPositionXGet() const
{
    long position = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, g_windowPositionXStr, &position ) );
    return position;
}

// =================================================================================================
//   Assigns Window X Position
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::WindowPositionXSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, g_windowPositionXStr, position_ ) );
}

// =================================================================================================
//   Returns Window Y Position
// -------------------------------------------------------------------------------------------------
long CCompanyNameScannerSettings::WindowPositionYGet() const
{
    long position = 0;
    SETTINGS_REPOSITORY_DO( LongValueGet( g_PluginName, g_windowPositionYStr, &position ) );
    return position;
}

// =================================================================================================
//   Assigns Window Y Position
// -------------------------------------------------------------------------------------------------
void CCompanyNameScannerSettings::WindowPositionYSet( long position_ )
{
    SETTINGS_REPOSITORY_DO( LongValueSet( g_PluginName, g_windowPositionYStr, position_ ) );
}
