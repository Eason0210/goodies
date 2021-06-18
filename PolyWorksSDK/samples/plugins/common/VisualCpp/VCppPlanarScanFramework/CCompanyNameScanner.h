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
#include <PolyWorksSDK/COM/IIMPlanarScanner.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMScanner5.h>
#include <PolyWorksSDK/COM/IIMScanningObjectsUser.h>
#include <PolyWorksSDK/COM/IIMSettings3.h>
#include <PolyWorksSDK/COM/IIMUnitsUser.h>
#include <CompanyNamePlanarScanner.h>

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
    public CComCoClass< CCompanyNameScanner, &CLSID_CompanyNamePlanarScanner >,
    public IDispatchImpl< ICompanyNamePlanarScanner, &IID_ICompanyNamePlanarScanner, &LIBID_COMPANYNAMEPLANARSCANNERLib >,
    public IIMPlugin,
    public IIMPlanarScanner,
    public IIMScanner5,
    public IIMCommandEnum,
    public IIMLanguage,
    public IIMScanningObjectsUser,
    public IIMSettings3,
    public IIMUnitsUser
{
public:
    CCompanyNameScanner();

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMESCANNER )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameScanner )
    COM_INTERFACE_ENTRY( ICompanyNamePlanarScanner )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY2( IIMScanner, IIMPlanarScanner )      // To specify which inheritance branch to follow
    COM_INTERFACE_ENTRY( IIMPlanarScanner )
    COM_INTERFACE_ENTRY( IIMScanner2 )
    COM_INTERFACE_ENTRY( IIMScanner3 )
    COM_INTERFACE_ENTRY( IIMScanner4 )
    COM_INTERFACE_ENTRY( IIMScanner5 )
    COM_INTERFACE_ENTRY( IIMCommandEnum )
    COM_INTERFACE_ENTRY( IIMLanguage )
    COM_INTERFACE_ENTRY( IIMScanningObjectsUser )
    COM_INTERFACE_ENTRY( IIMSettings )
    COM_INTERFACE_ENTRY( IIMSettings2 )
    COM_INTERFACE_ENTRY( IIMSettings3 )
    COM_INTERFACE_ENTRY( IIMUnitsUser )
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

    // IIMPlanarScanner
public:
    STDMETHODIMP ScanningStart(
        /* [in] */ IIMPlanarGrid* pPlanarGrid_,
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ConvertToPolygonalModelGet(
        /* [retval][out] */ VARIANT_BOOL* pConvertToPolygonalModel_ );

    STDMETHODIMP ConvertToPolygonalModelSet(
        /* [in] */ VARIANT_BOOL convertToPolygonalModel_ );

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

    // Private member functions
    /////////////////////////////

    // Private member variables
    /////////////////////////////

    CCompanyNameScannerReceiver m_Receiver;
};


/////////////////////////////////////////////////////////////////////////////
// CCompanyNameCmd
class CCompanyNameCmd : public IIMCommand2
{
public:
    CCompanyNameCmd( CCompanyNameScannerReceiver& receiver_ )
    : m_nRefCount( 0 )
    , m_Receiver( receiver_ )
    {
    }

    // Interface IUnknown
    STDMETHODIMP QueryInterface( REFIID riid_, void** ppObj_ ) override;
    STDMETHODIMP_( ULONG ) AddRef() override;
    STDMETHODIMP_( ULONG ) Release() override;

    // IIMCommand
public:
    STDMETHODIMP CmdNameGet(
        /* [out] */ BSTR* pCmdName_ ) override;

    STDMETHODIMP CmdDescGet(
        /* [out] */ BSTR* pCmdDesc_ ) override;

    STDMETHODIMP Execute(
        /* [retval][out] */ long* pReturnVal_ ) override;

    STDMETHODIMP MenuLocationGet(
        /* [out] */ BSTR* pMenuLoc_ ) override;

    STDMETHODIMP MenuDescGet(
        /* [out] */ BSTR* pMenuDesc_ ) override;

    // IIMCommand2
public:
    STDMETHODIMP ArgsTest(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override;

    STDMETHODIMP CmdDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY** pNames_ ) override;

    STDMETHODIMP CmdIsObsolete(
        /* [out] */ VARIANT_BOOL* pIsObsolete_,
        /* [out] */ BSTR*         pSupersedingCmd_ ) override;

    STDMETHODIMP CmdNoteGet(
        /* [retval][out] */ BSTR* pCmdNote_ ) override;

    STDMETHODIMP Execute2(
        /* [in] */ IIMCommandArgumentEnum*       pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ ) override = 0;

    STDMETHODIMP ParamsGet(
        /* [out] */ IIMCommandParameterEnum** pIIMCommandParameterEnum_ ) override;

protected:

    // Protected member Functions
    ///////////////////////////////

    virtual const wchar_t* CmdNameStrGet() = 0;
    virtual const wchar_t* DescStrGet()    = 0;
    virtual const wchar_t* MenuLocationStrGet() { return nullptr; }

    // Protected member variables
    ///////////////////////////////

    CCompanyNameScannerReceiver& m_Receiver;

private:

    // Private member functions
    /////////////////////////////

    // Private member variables
    /////////////////////////////

    long m_nRefCount;
};

OBJECT_ENTRY_AUTO( __uuidof( CompanyNamePlanarScanner ), CCompanyNameScanner )

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================
