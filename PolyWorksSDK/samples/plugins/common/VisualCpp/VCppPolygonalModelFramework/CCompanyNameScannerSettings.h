#pragma once

// =================================================================================================
// Manages the plug-in's settings.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>

#include "CTSetting.h"
#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CCompanyNameScannerSettings
{

public:

    // Public member functions
    ////////////////////////////

    CCompanyNameScannerSettings();
    virtual ~CCompanyNameScannerSettings() { }

    // IIMSettings
    STDMETHODIMP DoubleSettingsNbGet(
        /* [out] */ long* nbSettings_ );

    STDMETHODIMP DoubleSettingGet(
        /* [in] */ long           settingIndex_,
        /* [out] */ BSTR*         pSettingName_,
        /* [out] */ double*       pDefaultValue_,
        /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL* pIsProjectSetting_ );

    STDMETHODIMP LongSettingsNbGet(
        /* [out] */ long* nbSettings_ );

    STDMETHODIMP LongSettingGet(
        /* [in] */ long           settingIndex_,
        /* [out] */ BSTR*         pSettingName_,
        /* [out] */ long*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL* pIsProjectSetting_ );

    STDMETHODIMP StringSettingsNbGet(
        /* [out] */ long* nbSettings_ );

    STDMETHODIMP StringSettingGet(
        /* [in] */ long           settingIndex_,
        /* [out] */ BSTR*         pSettingName_,
        /* [out] */ BSTR*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL* pIsProjectSetting_ );

    // IIMSettings2
    STDMETHODIMP MatrixSettingsNbGet(
        /* [retval][out] */ long* pNbSettings_ );

    STDMETHODIMP MatrixSettingGet(
        /* [in] */ long               settingIndex_,
        /* [out][in] */ BSTR*         pSettingName_,
        /* [out][in] */ SAFEARRAY**   pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    // Get
    double HostUnitsScalingFactorGet() const;
    bool   NewDevicePositionCreateOnScanGet() const;
    long   WindowPositionXGet() const;
    long   WindowPositionYGet() const;

    // Set
    bool HostUnitsScalingFactorSet( double scalingFactor_ );
    void NewDevicePositionCreateOnScanSet( bool value_ );
    void WindowPositionXSet( long position_ );
    void WindowPositionYSet( long position_ );

    void SettingsAdd();
    void SettingsReload();
    void SettingsSave();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    virtual void SettingsDoubleAdd();
    virtual void SettingsLongAdd();
    virtual void SettingsStringAdd();
    virtual void SettingsMatrixAdd();

    // Protected member variables
    ///////////////////////////////

    using TDoubleVector  = std::vector< CTSetting< double > >;
    using TLongVector    = std::vector< CTSetting< long > >;
    using TWStringVector = std::vector< CTSetting< std::wstring > >;
    using TMatrixVector  = std::vector< CTSetting< Matrix4D > >;

    TDoubleVector  m_doubleSettings;
    TLongVector    m_longSettings;
    TWStringVector m_stringSettings;
    TMatrixVector  m_matrixSettings;

private:

    // Private member functions
    /////////////////////////////

    // Private member variables
    /////////////////////////////

    double m_hostUnitsScalingFactor = 1.0;           // Conversion factor from mm to application units
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
