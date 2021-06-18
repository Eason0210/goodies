#pragma once

// =================================================================================================
// Declaration of the CCompanyNameScanner.
//
// Copyright © InnovMetric Software Inc. 2020 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IIMLanguage.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMPolygonalScanner.h>
#include <PolyWorksSDK/COM/IIMScanner5.h>
#include <PolyWorksSDK/COM/IIMScanningObjectsUser.h>
#include <PolyWorksSDK/COM/IIMSettings3.h>
#include <PolyWorksSDK/COM/IIMUnitsUser.h>
#include <CompanyNamePolygonalModelScanner.h>

#include "CCompanyNameProxy.h"
#include "CCompanyNameScannerSettings.h"
#include "CDlgCompanyName.h"
#include "CMessageOnlyWindow.h"
#include "ICompanyNameScanner.h"
#include "resource.h"       // main symbols

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
// Plugin main class
//
// -------------------------------------------------------------------------------------------------
class ATL_NO_VTABLE CCompanyNameScanner :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameScanner, &CLSID_CompanyNamePolygonalModelScanner >,
    public IDispatchImpl< ICompanyNamePolygonalModelScanner, &IID_ICompanyNamePolygonalModelScanner, &LIBID_COMPANYNAMEPOLYGONALMODELSCANNERLib >,
    public IIMPlugin,
    public IIMLanguage,
    public IIMUnitsUser,
    public IIMScanningObjectsUser,
    public IIMSettings3,
    public IIMPolygonalScanner,
    public ICompanyNameScanner
{
public:
    CCompanyNameScanner();
    virtual ~CCompanyNameScanner() = default;

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMESCANNER )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameScanner )
    COM_INTERFACE_ENTRY( ICompanyNamePolygonalModelScanner )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMLanguage )
    COM_INTERFACE_ENTRY( IIMUnitsUser )
    COM_INTERFACE_ENTRY( IIMSettings )
    COM_INTERFACE_ENTRY( IIMSettings2 )
    COM_INTERFACE_ENTRY( IIMSettings3 )
    COM_INTERFACE_ENTRY2( IIMScanner, IIMPolygonalScanner )      // To specify which inheritance branch to follow
    COM_INTERFACE_ENTRY( IIMPolygonalScanner )
    COM_INTERFACE_ENTRY( IIMScanner2 )
    COM_INTERFACE_ENTRY( IIMScanner3 )
    COM_INTERFACE_ENTRY( IIMScanner4 )
    COM_INTERFACE_ENTRY( IIMScanner5 )
    COM_INTERFACE_ENTRY( IIMScanningObjectsUser )
    END_COM_MAP()

    // ICompanyNameScanner
public:

    // IIMPlugin
public:
    STDMETHODIMP PlgNameGet(
        /* [out] */ BSTR* pName_ );

    STDMETHODIMP PlgVersionGet(
        /* [out] */ long* pMajor_,
        /* [out] */ long* pMinor_,
        /* [out] */ long* pDot_ );

    STDMETHODIMP Load(
        /* [in] */ IIMHost*       pIIMHost_,
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP Unload(
        /* [retval][out] */ long* pReturnVal_ );

    // IIMLanguage
public:
    STDMETHODIMP LanguageSet(
        /* [in] */ BSTR           pLanguage_,
        /* [in] */ BSTR           pFontName_,
        /* [in] */ ECharacterSets charSet_ );

    // IIMUnitsUser
public:
    STDMETHODIMP UnitsScalingFactorSet(
        /* [in] */ double scalingFactor_ );

    // IIMScanningObjectsUser
public:
    STDMETHODIMP ScanningObjectsSet(
        /* [in] */ EScanTypes  scanType_,
        /* [in] */ SAFEARRAY** pArrayObjects_,
        /* [in] */ BSTR        currentChoice_ );

    // IIMSettings
public:
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
public:
    STDMETHODIMP MatrixSettingsNbGet(
        /* [retval][out] */ long* pNbSettings_ );

    STDMETHODIMP MatrixSettingGet(
        /* [in] */ long               settingIndex_,
        /* [out][in] */ BSTR*         pSettingName_,
        /* [out][in] */ SAFEARRAY**   pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    // IIMSettings3
public:
    STDMETHODIMP OnSettingsChange(
        /* [in] */ SAFEARRAY* pSettingNames_ );

    // IIMScanner
public:
    STDMETHODIMP ScanningDeviceNameGet(
        /* [retval][out] */ BSTR* pName_ );

    STDMETHODIMP ScanningConnectionInit(
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long*      pReturnVal_ );

    STDMETHODIMP ScanningConnectionEnd(
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ScanningDlgShow();

    STDMETHODIMP ScanningDlgClose();

    STDMETHODIMP ScanNameDefaultGet(
        /* [retval][out] */ BSTR* pName_ );

    STDMETHODIMP ScanNameSet(
        /* [in] */ BSTR name_ );

    STDMETHODIMP MeshMaxEdgeLengthGet(
        /* [retval][out] */ double* pMaxEdgeLength_ );

    STDMETHODIMP MeshMaxEdgeLengthSet(
        /* [in] */ double maxEdgeLength_ );

    STDMETHODIMP MeshInterpolationStepGet(
        /* [retval][out] */ double* pInterpolationStep_ );

    STDMETHODIMP MeshInterpolationStepSet(
        /* [in] */ double interpolationStep_ );

    STDMETHODIMP MeshMaxAngleGet(
        /* [retval][out] */ double* pMaxAngle_ );

    STDMETHODIMP MeshMaxAngleSet(
        /* [in] */ double maxAngle_ );

    // IIMScanner2
public:
    STDMETHODIMP ScanningDeviceMenuLocationGet(
        /* [retval][out] */ BSTR* pName_ );

    // IIMScanner3
public:
    STDMETHODIMP OnScanningEvent(
        /* [in] */ EScanningEvents event_ );

    // IIMScanner4
public:
    STDMETHODIMP DeviceDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY** pNames_ );

    // IIMScanner5
public:
    STDMETHODIMP ScanningOptionsDlgShow();

    STDMETHODIMP HasScanningOptionsDlg(
        /* [retval][out] */ VARIANT_BOOL* pHasOptionsDlg_ );

    // IIMPolygonalScanner
public:

    STDMETHODIMP ScanningStart(
        /* [in] */ IIMPolygonalModel* pPolygonalModel_,
        /* [retval][out] */ long*     pReturnVal_ );

    STDMETHODIMP ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ );


// ICompanyNameScanner
    std::wstring ObjectNameGet() const override { return m_objectName; }
    void         PolygonalModelReplace( TUniqueID uniqueId_ ) override;
    void         ScanningEndInMainThreadRequest() override;
    void         ScanningDlgCloseRequest() override;
    void         ScanningDlgClosed() override;

protected:
    // ---------------- Protected Methods ----------------------------------------------------------

private:
    // ---------------- Private Methods ------------------------------------------------------------

    // ---------------- Private Member Variables ---------------------------------------------------
    // Flag to prevent multiple scanning to execute in parallel
    bool m_isScanningEndInProgress = false;

    // Hidden window to allow thread to send operation to be executed in the main thread
    CMessageOnlyWindow m_messageWindow;

    // Last data object name
    std::wstring m_objectName;

    // Scaling factor to convert to application units
    double m_hostUnitsScalingFactor = -1.0;

    // Scanner cookie feedback
    DWORD m_cookieScannerFeedback = 0;

    // Proxy, class to intereact with the scanning device
    CCompanyNameProxy m_proxy;

    // Settings
    CCompanyNameScannerSettings m_settings;

    // User interface
    std::unique_ptr< CDlgCompanyName > m_pDlgCompanyName;
};

OBJECT_ENTRY_AUTO( __uuidof( CompanyNamePolygonalModelScanner ), CCompanyNameScanner )

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
