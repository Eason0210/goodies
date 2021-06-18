#pragma once

// =================================================================================================
//   Manages the plug-in's settings.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IMTypes.h>
#include <vector>

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
    EStdAxis                 DeviceVerticalAxisGet();
    double                   HostUnitsScalingFactorGet() const;
    double                   IMAInterpolationStepGet();
    double                   IMAMaxAngleGet();
    double                   IMAMaxEdgeLengthGet();
    long                     IMAWindowPositionXGet();
    long                     IMAWindowPositionYGet();
    long                     IMAOptionsWindowPositionXGet();
    long                     IMAOptionsWindowPositionYGet();
    bool                     IMIExtractNormalsGet();
    double                   IMIMaxSearchDistGet();
    double                   IMIMinSearchDistGet();
    double                   IMIMinHoleWidthGet();
    bool                     IMIRealTimeInspectionGet();
    bool                     IMIRealTimeMeshingGet();
    double                   IMISharpEdgeMaxPointToPointDistanceGet();
    double                   IMISharpEdgeMinAngleGet();
    long                     IMIWindowPositionXGet();
    long                     IMIWindowPositionYGet();
    long                     IMIOptionsWindowPositionXGet();
    long                     IMIOptionsWindowPositionYGet();
    long                     IMISaveAsWindowPositionXGet();
    long                     IMISaveAsWindowPositionYGet();
    EInvertDigitizingVectors InvertDigitizingVectorsGet();
    long                     NbLinesTransferredGet();
    long                     RefreshDelayGet();
    EScanTypes               ScanTypeGet();
    bool                     TestModeGet();
    bool                     UseAutoViewpointGet();

    // Set
    void AutoViewpointZoomCloseUpSet( long closeUpFct_ );
    void DeviceVerticalAxisSet( EStdAxis verticalAxis_ );
    bool HostUnitsScalingFactorSet( double scalingFactor_ );
    void IMAInterpolationStepSet( double step_ );
    void IMAMaxAngleSet( double maxAngle_ );
    void IMAMaxEdgeLengthSet( double maxEdgeLength_ );
    void IMAWindowPositionXSet( long position_ );
    void IMAWindowPositionYSet( long position_ );
    void IMAOptionsWindowPositionXSet( long position_ );
    void IMAOptionsWindowPositionYSet( long position_ );
    void IMIExtractNormalsSet( bool use_ );
    void IMIMaxSearchDistSet( double distance_ );
    void IMIMinSearchDistSet( double distance_ );
    void IMIMinHoleWidthSet( double distance_ );
    void IMIRealTimeInspectionSet( bool activate_ );
    void IMIRealTimeMeshingSet( bool use_ );
    void IMISharpEdgeMaxPointToPointDistanceSet( double distance_ );
    void IMISharpEdgeMinAngleSet( double angle_ );
    void IMIWindowPositionXSet( long position_ );
    void IMIWindowPositionYSet( long position_ );
    void IMIOptionsWindowPositionXSet( long position_ );
    void IMIOptionsWindowPositionYSet( long position_ );
    void IMISaveAsWindowPositionXSet( long position_ );
    void IMISaveAsWindowPositionYSet( long position_ );
    void InvertDigitizingVectorsSet( EInvertDigitizingVectors invert_ );
    void NbLinesTransferredSet( long nbLines_ );
    void RefreshDelaySet( long delay_ );
    void ScanTypeSet( EScanTypes scanType_ );
    void TestModeSet( bool use_ );
    void UseAutoViewpointSet( bool use_ );

    // Scanning profiles
    void ScanningProfileSettingsGet( TWStrings& profileSettings_ ) const;

    bool StandardScanningProfileDoubleSettingValueGet(
        EStandardScanningProfiles standardProfile_,
        const std::wstring&       setting_,
        double&                   value_ ) const;
    bool StandardScanningProfileLongSettingValueGet(
        EStandardScanningProfiles standardProfile_,
        const std::wstring&       setting_,
        long&                     value_ ) const;
    bool StandardScanningProfileStringSettingValueGet(
        EStandardScanningProfiles standardProfile_,
        const std::wstring&       setting_,
        std::wstring&             value_ ) const;

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
