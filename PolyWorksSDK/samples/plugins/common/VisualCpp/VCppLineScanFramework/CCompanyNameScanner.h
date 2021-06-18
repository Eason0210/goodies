#pragma once

// =================================================================================================
//   Declaration of the CCompanyNameScanner.
//
// Copyright © InnovMetric Software Inc. 2014 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMLanguage.h>
#include <PolyWorksSDK/COM/IIMLineScan.h>
#include <PolyWorksSDK/COM/IIMLineScanner2.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMPointCloud.h>
#include <PolyWorksSDK/COM/IIMScanner5.h>
#include <PolyWorksSDK/COM/IIMScannerFeedback.h>
#include <PolyWorksSDK/COM/IIMScanningObjectsUser.h>
#include <PolyWorksSDK/COM/IIMScanningProfilesUser.h>
#include <PolyWorksSDK/COM/IIMSettings3.h>
#include <PolyWorksSDK/COM/IIMUnitsUser.h>
#include <atlcomcli.h>
#include <CompanyNameLineScanner.h>

#include "CCompanyNameScannerReceiver.h"
#include "resource.h"       // main symbols

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

class CComCommandParameterEnum;
class CComCommandParameter;

/////////////////////////////////////////////////////////////////////////////
// CCompanyNameScanner
class ATL_NO_VTABLE CCompanyNameScanner :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameScanner, &CLSID_CompanyNameLineScanner >,
    public IDispatchImpl< ICompanyNameLineScanner, &IID_ICompanyNameLineScanner, &LIBID_COMPANYNAMELINESCANNERLib >,
    public IIMPlugin,
    public IIMLineScanner2,
    public IIMScanner5,
    public IIMCommandEnum,
    public IIMLanguage,
    public IIMScanningObjectsUser,
    public IIMScanningProfilesUser,
    public IIMSettings3,
    public IIMUnitsUser
{
public:
    CCompanyNameScanner();

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMESCANNER )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameScanner )
    COM_INTERFACE_ENTRY( ICompanyNameLineScanner )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY2( IIMScanner, IIMLineScanner )      // To specify which inheritance branch to follow
    // to get to IIMScanner (it could also be IIMScanner2)
    COM_INTERFACE_ENTRY( IIMScanner2 )
    COM_INTERFACE_ENTRY( IIMScanner3 )
    COM_INTERFACE_ENTRY( IIMScanner4 )
    COM_INTERFACE_ENTRY( IIMScanner5 )
    COM_INTERFACE_ENTRY( IIMLineScanner )
    COM_INTERFACE_ENTRY( IIMLineScanner2 )
    COM_INTERFACE_ENTRY( IIMCommandEnum )
    COM_INTERFACE_ENTRY( IIMLanguage )
    COM_INTERFACE_ENTRY( IIMScanningObjectsUser )
    COM_INTERFACE_ENTRY( IIMScanningProfilesUser )
    COM_INTERFACE_ENTRY( IIMSettings )
    COM_INTERFACE_ENTRY( IIMSettings2 )
    COM_INTERFACE_ENTRY( IIMSettings3 )
    COM_INTERFACE_ENTRY( IIMUnitsUser )
    END_COM_MAP()

    void CommandsAdd();
    void CommandsRemove();

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

    // IIMLineScanner
public:
    STDMETHODIMP ScanningStart(
        /* [in] */ IIMLineScan*   pLineScan_,
        /* [in] */ IIMPointCloud* pPointCloud_,
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ScanTypeGet(
        /* [retval][out] */ EScanTypes* pScanType_ );

    STDMETHODIMP ScanTypeSet(
        /* [in] */ EScanTypes     scanType_,
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ExtractNormalsGet(
        /* [retval][out] */ VARIANT_BOOL* pExtractNormals_ );

    STDMETHODIMP ExtractNormalsSet(
        /* [in] */ VARIANT_BOOL extractNormals_ );

    STDMETHODIMP ExtractNormalsMinSearchDistGet(
        /* [retval][out] */ double* pMinSearchDist_ );

    STDMETHODIMP ExtractNormalsMinSearchDistSet(
        /* [in] */ double minSearchDist_ );

    STDMETHODIMP ExtractNormalsMaxSearchDistGet(
        /* [retval][out] */ double* pMaxSearchDist_ );

    STDMETHODIMP ExtractNormalsMaxSearchDistSet(
        /* [in] */ double maxSearchDist_ );

    STDMETHODIMP ExtractHoleBoundariesGet(
        /* [retval][out] */ VARIANT_BOOL* pExtractHoleBoundaries_ );

    STDMETHODIMP ExtractHoleBoundariesSet(
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_ );

    STDMETHODIMP ExtractHoleBoundariesMinWidthGet(
        /* [retval][out] */ double* pMinWidth_ );

    STDMETHODIMP ExtractHoleBoundariesMinWidthSet(
        /* [in] */ double minWidth_ );

    STDMETHODIMP TestModeGet(
        /* [retval][out] */ VARIANT_BOOL* pTestMode_ );

    STDMETHODIMP TestModeSet(
        /* [in] */ VARIANT_BOOL testMode_ );

    // IIMLineScanner2
    STDMETHODIMP RealTimeComparisonGet(
        /* [retval][out] */ VARIANT_BOOL* pRealTimeComp_ );

    STDMETHODIMP RealTimeComparisonSet(
        /* [in] */ VARIANT_BOOL realTimeComp_ );

    // IIMCommandEnum
public:
    STDMETHODIMP CmdsGetNb(
        /* [retval][out] */ long* pArgNb_ );

    STDMETHODIMP CmdGet(
        /* [in] */ long          number_,
        /* [out] */ IIMCommand** pIIMCommand_ );

    // IIMLanguage
public:
    STDMETHODIMP LanguageSet(
        /* [in] */ BSTR           pLanguage_,
        /* [in] */ BSTR           pFontName_,
        /* [in] */ ECharacterSets charSet_ );

    // IIMScanningObjectsUser
public:
    STDMETHODIMP ScanningObjectsSet(
        /* [in] */ EScanTypes  scanType_,
        /* [in] */ SAFEARRAY** pArrayObjects_,
        /* [in] */ BSTR        currentChoice_ );

    // IIMScanningProfilesUser
public:

    STDMETHODIMP ScanningProfileSettingsGet(
        /* [out][in] */ SAFEARRAY** pProfileSettings_ );

    STDMETHODIMP StandardScanningProfileDoubleSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR                      setting_,
        /* [out] */ double*                  pValue_ );

    STDMETHODIMP StandardScanningProfileLongSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR                      setting_,
        /* [out] */ long*                    pValue_ );

    STDMETHODIMP StandardScanningProfileStringSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR                      setting_,
        /* [out] */ BSTR*                    pValue_ );

    STDMETHODIMP ScanningProfilesSet(
        /* [in] */ SAFEARRAY** pCmdArgNames_,
        /* [in] */ SAFEARRAY** pDisplayNames_,
        /* [in] */ SAFEARRAY** pInfos_,
        /* [in] */ BSTR        current_ );

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

    // IIMUnitsUser
public:
    STDMETHODIMP UnitsScalingFactorSet(
        /* [in] */ double scalingFactor_ );

protected:

    // Protected member Functions
    ///////////////////////////////

    // Protected member variables
    ///////////////////////////////

private:

    typedef std::vector< CComPtr< IIMCommand2 > > TCommandsVector;

    // Private member functions
    /////////////////////////////

    // Private member variables
    /////////////////////////////

    TCommandsVector             m_commands;
    CCompanyNameScannerReceiver m_Receiver;
};


OBJECT_ENTRY_AUTO( __uuidof( CompanyNameLineScanner ), CCompanyNameScanner )

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
