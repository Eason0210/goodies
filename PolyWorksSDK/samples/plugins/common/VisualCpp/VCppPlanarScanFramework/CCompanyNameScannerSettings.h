#pragma once

// =================================================================================================
//   Manages the plug-in's settings.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>

#include "CompanyNameConst.h"
#include "CTSetting.h"
#include "Types.h"

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

enum EHostApplication
{
    E_APPLICATION_UNKNOWN,
    E_APPLICATION_IMALIGN,
    E_APPLICATION_IMEDIT,
    E_APPLICATION_IMINSPECT
};

enum EInvertDigitizingVectors
{
    E_INVERT_FIRST_CHOICE = 0,
    E_DO_NOT_INVERT       = E_INVERT_FIRST_CHOICE,
    E_INVERT,
    E_NB_INVERT_CHOICES
};

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CCompanyNameScannerSettings
{

public:

    // Public member functions
    ////////////////////////////

    EHostApplication HostApplicationGet();
    void             Initialize( EHostApplication application_ );
    bool             IsInitialized();

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

    void SettingsAdd();

    virtual ~CCompanyNameScannerSettings() { }

    // Get
    long                     AutoViewpointZoomCloseUpGet();
    double                   CursorSegmentsMaxDistGet();
    bool                     CreateNewDevicePositionOnScanGet();
    EStdAxis                 DeviceVerticalAxisGet();
    double                   HostUnitsScalingFactorGet() const;
    double                   IMAInterpolationStepGet();
    double                   IMAMaxAngleGet();
    double                   IMAMaxEdgeLengthGet();
    long                     IMAWindowPositionXGet();
    long                     IMAWindowPositionYGet();
    long                     IMAOptionsWindowPositionXGet();
    long                     IMAOptionsWindowPositionYGet();
    bool                     IMIConvertToPolygonalGet();
    long                     IMIWindowPositionXGet();
    long                     IMIWindowPositionYGet();
    long                     IMIOptionsWindowPositionXGet();
    long                     IMIOptionsWindowPositionYGet();
    EInvertDigitizingVectors InvertDigitizingVectorsGet();
    EScanTypes               ScanTypeGet();
    bool                     UseAutoViewpointGet();

    // Set
    void AutoViewpointZoomCloseUpSet( long closeUpFct_ );
    void CreateNewDevicePositionOnScanSet( bool enable_ );
    void DeviceVerticalAxisSet( EStdAxis verticalAxis_ );
    bool HostUnitsScalingFactorSet( double scalingFactor_ );
    void IMAInterpolationStepSet( double step_ );
    void IMAMaxAngleSet( double maxAngle_ );
    void IMAMaxEdgeLengthSet( double maxEdgeLength_ );
    void IMAWindowPositionXSet( long position_ );
    void IMAWindowPositionYSet( long position_ );
    void IMAOptionsWindowPositionXSet( long position_ );
    void IMAOptionsWindowPositionYSet( long position_ );
    void IMIMinHoleWidthSet( double distance_ );
    void IMIConvertToPolygonalSet( bool use_ );
    void IMIWindowPositionXSet( long position_ );
    void IMIWindowPositionYSet( long position_ );
    void IMIOptionsWindowPositionXSet( long position_ );
    void IMIOptionsWindowPositionYSet( long position_ );
    void InvertDigitizingVectorsSet( EInvertDigitizingVectors invert_ );
    void ScanTypeSet( EScanTypes scanType_ );
    void UseAutoViewpointSet( bool use_ );

    void SettingsReload();
    void SettingsSave();

    // Public member variables
    ////////////////////////////

protected:

    // Protected member Functions
    ///////////////////////////////

    virtual void SettingsDoubleAdd();
    virtual void SettingsIMADoubleAdd();
    virtual void SettingsIMIDoubleAdd();

    virtual void SettingsLongAdd();
    virtual void SettingsIMALongAdd();
    virtual void SettingsIMILongAdd();

    virtual void SettingsStringAdd();
    virtual void SettingsIMAStringAdd();
    virtual void SettingsIMIStringAdd();

    virtual void SettingsMatrixAdd();
    virtual void SettingsIMAMatrixAdd();
    virtual void SettingsIMIMatrixAdd();

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

    friend CCompanyNameScannerSettings& theCompanyNameScannerSettings();
    CCompanyNameScannerSettings();

    // Private member variables
    /////////////////////////////

    EHostApplication m_hostApplication;
    double           m_hostUnitsScalingFactor; // Conversion factor from mm to application units
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

CCompanyNameScannerSettings& theCompanyNameScannerSettings();
