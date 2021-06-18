// CInnovPlugin.h : Declaration of the CInnovPlugin

#ifndef __INNOVPLUGIN_H_
#define __INNOVPLUGIN_H_

#include <PolyWorksSDK/COM/IIMCommand.h>
#include <PolyWorksSDK/COM/IIMLanguage.h>
#include <PolyWorksSDK/COM/IIMMessageCenter.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMProbe.h>
#include <PolyWorksSDK/COM/IIMSettings.h>
#include <PolyWorksSDK/COM/IIMSoundCenter.h>
#include <PolyWorksSDK/COM/IIMUnitsUser.h>

#include "resource.h"       // main symbols
#include "VCppBasic.h"

/////////////////////////////////////////////////////////////////////////////
// CInnovPlugin
class ATL_NO_VTABLE CInnovPlugin :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CInnovPlugin, &CLSID_InnovPlugin >,
    public IDispatchImpl< IInnovPlugin, &IID_IInnovPlugin, &LIBID_VC6DLLLib >,
    public IIMPlugin,
    public IIMCommand,
    public IIMLanguage,
    public IIMProbe,
    public IIMSettings,
    public IIMUnitsUser
{
public:
    CInnovPlugin();

    DECLARE_REGISTRY_RESOURCEID( IDR_INNOVPLUGIN )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CInnovPlugin )
    COM_INTERFACE_ENTRY( IInnovPlugin )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMCommand )
    COM_INTERFACE_ENTRY( IIMLanguage )
    COM_INTERFACE_ENTRY( IIMProbe )
    COM_INTERFACE_ENTRY( IIMSettings )
    COM_INTERFACE_ENTRY( IIMUnitsUser )
    END_COM_MAP()

    // IInnovPlugin
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

private:

    // IIMCommand
public:
    STDMETHODIMP CmdNameGet(
        /* [out] */ BSTR __RPC_FAR* pCmdName_ );

    STDMETHODIMP CmdDescGet(
        /* [out] */ BSTR __RPC_FAR* pCmdDesc_ );

    STDMETHODIMP Execute(
        /* [retval][out] */ long __RPC_FAR* pReturnVal_ );

    STDMETHODIMP MenuLocationGet(
        /* [out] */ BSTR __RPC_FAR* pMenuLoc_ );

    STDMETHODIMP MenuDescGet(
        /* [out] */ BSTR __RPC_FAR* pMenuDesc_ );

    // IIMLanguage
public:
    STDMETHODIMP LanguageSet(
        /* [in] */ BSTR           pLanguage_,
        /* [in] */ BSTR           pFontName_,
        /* [in] */ ECharacterSets charSet_ );

    // IIMProbe
public:
    STDMETHODIMP CanChangeUnits(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    STDMETHODIMP CanUseDeviceAsMouse(
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    STDMETHODIMP CompensationMethodGet(
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    STDMETHODIMP ConnectionEnd(
        /* [retval][out] */ long* pReturnVal_ );

    STDMETHODIMP ConnectionInit(
        /* [in] */ IIMProbeFeedback* pFeedback_,
        /* [retval][out] */ long*    pReturnVal_ );

    STDMETHODIMP DeviceNameGet(
        /* [out] */ BSTR* pName_ );

    STDMETHODIMP DiameterGet(
        /* [retval][out] */ double* pDiameter_ );

    STDMETHODIMP HasPropertiesDlg(
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    STDMETHODIMP MeasurementStart(
        /* [ out, retval ] */ long* pReturnVal_ );

    STDMETHODIMP MeasurementStop(
        /* [ out, retval ] */ long* pReturnVal_ );

    STDMETHODIMP ModeSet(
        /* [in] */ short modeNb_ );

    STDMETHODIMP ModeGet(
        /* [out] */ short* pModeNb_ );

    STDMETHODIMP ModesGetNb(
        /* [retval][out] */ short* pModeNb_ );

    STDMETHODIMP ModeNameGet(
        /* [in] */ short  modeNb_,
        /* [out] */ BSTR* pName_ );

    STDMETHODIMP NeedMeasurementButtons(
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    STDMETHODIMP ProbingEnd();

    STDMETHODIMP ProbingStart(
        /* [in] */ IIMPointCloud* pCloud_,
        /* [in] */ VARIANT_BOOL   sendLastPoint_ );

    STDMETHODIMP PropertiesDlgShow();

    STDMETHODIMP SharedMatrixNameGet(
        /* [out] */ BSTR* pSharedMatrixName_ );

    STDMETHODIMP SharedMatrixNameSet(
        /* [in] */ BSTR pSharedMatrixName_ );

    STDMETHODIMP TransformationMatrixGet(
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    STDMETHODIMP TransformationMatrixSet(
        /* [in] */ SAFEARRAY** pTransMat_ );

    STDMETHODIMP UnitsGet(
        /* [out] */ double __RPC_FAR* pUnits_ );

    STDMETHODIMP UnitsSet(
        /* [in] */ double units_ );

    STDMETHODIMP UseAutoViewpointGet(
        /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAutoViewpoint_ );

    STDMETHODIMP UseAutoViewpointSet(
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    STDMETHODIMP UseDeviceAsMouseGet(
        /* [out] */ VARIANT_BOOL __RPC_FAR* pUseAsMouse_ );

    STDMETHODIMP UseDeviceAsMouseSet(
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    STDMETHODIMP UseTransformationMatrixGet(
        /* [out] */ VARIANT_BOOL __RPC_FAR* useMatrix_ );

    STDMETHODIMP UseTransformationMatrixSet(
        /* [in] */ VARIANT_BOOL useMatrix_ );

    // IIMSettings
public:
    STDMETHODIMP DoubleSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP DoubleSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ double __RPC_FAR*       pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    STDMETHODIMP LongSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP LongSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ long __RPC_FAR*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    STDMETHODIMP StringSettingsNbGet(
        /* [out] */ long __RPC_FAR* nbSettings_ );

    STDMETHODIMP StringSettingGet(
        /* [in] */ long                     settingIndex_,
        /* [out] */ BSTR __RPC_FAR*         pSettingName_,
        /* [out] */ BSTR __RPC_FAR*         pDefaultValue_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsUserSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsHostSpecific_,
        /* [out] */ VARIANT_BOOL __RPC_FAR* pIsProjectSetting_ );

    // IIMUnitsUser
public:
    STDMETHODIMP UnitsScalingFactorSet(
        /* [in] */ double scalingFactor_ );

private:
    CComPtr< IIMMessageCenter > m_pMessageCenter;
    CComPtr< IIMSoundCenter >   m_pSoundCenter;
};

#endif //__INNOVPLUGIN_H_
