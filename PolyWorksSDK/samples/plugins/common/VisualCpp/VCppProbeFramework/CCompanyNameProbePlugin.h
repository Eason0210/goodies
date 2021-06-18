#ifndef _CCOMPANYNAMEPROBEPLUGIN_FRIDAY_OCTOBER252013_093938_H_
#define _CCOMPANYNAMEPROBEPLUGIN_FRIDAY_OCTOBER252013_093938_H_
// =================================================================================================
//   Polyworks SDK interface implementation
//
// Copyright © InnovMetric Logiciels Inc. 2013 All Rights Reserved
// -------------------------------------------------------------------------------------------------

// =================================================================================================
// ======================================== INCLUDED FILES =========================================

#include <PolyWorksSDK/COM/IIMDeviceCamera.h>
#include <PolyWorksSDK/COM/IIMDeviceLevel2.h>
#include <PolyWorksSDK/COM/IIMInputEventsEmitter.h>
#include <PolyWorksSDK/COM/IIMLanguage.h>
#include <PolyWorksSDK/COM/IIMPieceTemperature.h>
#include <PolyWorksSDK/COM/IIMPlugin.h>
#include <PolyWorksSDK/COM/IIMPowerSource.h>
#include <PolyWorksSDK/COM/IIMProbe17.h>
#include <PolyWorksSDK/COM/IIMSettings3.h>
#include <PolyWorksSDK/COM/IIMUnitsUser.h>

#include "CompanyNameProbe.h"
#include "resource.h"

// =================================================================================================
// ========================================= NAMESPACES ============================================

// =================================================================================================
// ==================================== FORWARD DECLARATIONS =======================================

// =================================================================================================
// ====================================== CONSTANTS, ENUMS =========================================

// =================================================================================================
// ================================= TYPES, CLASSES, STRUCTURES ====================================

// =================================================================================================
//   CCompanyNameProbePlugin
// -------------------------------------------------------------------------------------------------
class ATL_NO_VTABLE CCompanyNameProbePlugin :
    public CComObjectRootEx< CComSingleThreadModel >,
    public CComCoClass< CCompanyNameProbePlugin, &CLSID_CompanyNameProbePlugin >,
    public IDispatchImpl< ICompanyNameProbePlugin, &IID_ICompanyNameProbePlugin, &LIBID_COMPANYNAMEPROBELib >,
    public IIMDeviceCamera,
    public IIMDeviceLevel2,
    public IIMInputEventsEmitter,
    public IIMLanguage,
    public IIMPieceTemperature,
    public IIMPlugin,
    public IIMPowerSource,
    public IIMProbe17,
    public IIMSettings3,
    public IIMUnitsUser
{
public:
    CCompanyNameProbePlugin() {}

    DECLARE_REGISTRY_RESOURCEID( IDR_COMPANYNAMEPROBEPLUGIN )

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP( CCompanyNameProbePlugin )
    COM_INTERFACE_ENTRY( ICompanyNameProbePlugin )
    COM_INTERFACE_ENTRY( IDispatch )
    COM_INTERFACE_ENTRY( IIMDeviceCamera )
    COM_INTERFACE_ENTRY( IIMDeviceLevel )
    COM_INTERFACE_ENTRY( IIMDeviceLevel2 )
    COM_INTERFACE_ENTRY( IIMInputEventsEmitter )
    COM_INTERFACE_ENTRY( IIMLanguage )
    COM_INTERFACE_ENTRY( IIMPieceTemperature )
    COM_INTERFACE_ENTRY( IIMPlugin )
    COM_INTERFACE_ENTRY( IIMPowerSource )
    COM_INTERFACE_ENTRY( IIMProbe )
    COM_INTERFACE_ENTRY( IIMProbe2 )
    COM_INTERFACE_ENTRY( IIMProbe3 )
    COM_INTERFACE_ENTRY( IIMProbe4 )
    COM_INTERFACE_ENTRY( IIMProbe5 )
    COM_INTERFACE_ENTRY( IIMProbe6 )
    COM_INTERFACE_ENTRY( IIMProbe7 )
    COM_INTERFACE_ENTRY( IIMProbe8 )
    COM_INTERFACE_ENTRY( IIMProbe9 )
    COM_INTERFACE_ENTRY( IIMProbe10 )
    COM_INTERFACE_ENTRY( IIMProbe11 )
    COM_INTERFACE_ENTRY( IIMProbe12 )
    COM_INTERFACE_ENTRY( IIMProbe13 )
    COM_INTERFACE_ENTRY( IIMProbe14 )
    COM_INTERFACE_ENTRY( IIMProbe16 )
    COM_INTERFACE_ENTRY( IIMProbe17 )
    COM_INTERFACE_ENTRY( IIMSettings )
    COM_INTERFACE_ENTRY( IIMSettings2 )
    COM_INTERFACE_ENTRY( IIMSettings3 )
    COM_INTERFACE_ENTRY( IIMUnitsUser )
    END_COM_MAP()

    // ICompanyNameProbePlugin
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

    // IIMDeviceCamera
public:
    STDMETHODIMP HasCamera(
        /* [retval][out] */ VARIANT_BOOL* pHasCamera_ );

    STDMETHODIMP CameraActivationStateGet(
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    STDMETHODIMP CameraActivationStateSet(
        /* [in] */ VARIANT_BOOL activationState_ );

    STDMETHODIMP CameraViewDlgShow();

    STDMETHODIMP CameraViewDlgClose();

    STDMETHODIMP CameraViewIsClickBehaviorSupported(
        /* [in] */ ECameraViewClickBehavior clickBehavior_,
        /* [retval][out] */ VARIANT_BOOL*   pIsSupported_ );

    STDMETHODIMP CameraViewClickBehaviorGet(
        /* [retval][out] */ ECameraViewClickBehavior* pClickBehavior_ );

    STDMETHODIMP CameraViewClickBehaviorSet(
        /* [in] */ ECameraViewClickBehavior clickBehavior_ );

    // IIMDeviceLevel
public:
    STDMETHODIMP CanProvideGravityDirection(
        /* [retval][out] */ VARIANT_BOOL* pCanProvideGravityDirection_ );

    STDMETHODIMP CanProvideRealTimeAngles(
        /* [retval][out] */ VARIANT_BOOL* pCanProvideRealTimeAngles_ );

    STDMETHODIMP GravityDirectionGet(
        /* [out] */ double* pI_,
        /* [out] */ double* pJ_,
        /* [out] */ double* pK_ );

    STDMETHODIMP RealTimeAnglesGet(
        /* [out] */ double*            pAngleX_,
        /* [out] */ double*            pAngleY_,
        /* [out] */ double*            pAngleZ_,
        /* [out] */ ELevelAngleStatus* pStatusX_,
        /* [out] */ ELevelAngleStatus* pStatusY_,
        /* [out] */ ELevelAngleStatus* pStatusZ_ );

    STDMETHODIMP StabilityToleranceGet(
        /* [retval][out] */ double* pTolerance_ );

    STDMETHODIMP StabilityToleranceSet(
        /* [in] */ double tolerance_ );

    // IIMDeviceLevel2
public:
    STDMETHODIMP CanUseLevelCompensation(
        /* [retval][out] */ VARIANT_BOOL* pCanUseLevelCompensation_ );

    STDMETHODIMP LevelCompensationStatusGet(
        /* [retval][out] */ ELevelCompensationStatus* pStatus_ );

    STDMETHODIMP UseLevelCompensationGet(
        /* [retval][out] */ VARIANT_BOOL* pUseLevelCompensation_ );

    STDMETHODIMP UseLevelCompensationSet(
        /* [in] */ VARIANT_BOOL useLevelCompensation_ );

    // IIMInputEventsEmitter
public:
    STDMETHODIMP TransmissionEnable(
        /* [in] */ IIMInputEventsReceiver* pInputEventsReceiver_ );

    STDMETHODIMP TransmissionDisable();

    // IIMLanguage
public:
    STDMETHODIMP LanguageSet(
        /* [in] */ BSTR           pLanguage_,
        /* [in] */ BSTR           pFontName_,
        /* [in] */ ECharacterSets charSet_ );

    // IIMPowerSource
public:
    STDMETHODIMP CanProvidePowerStatus(
        /* [retval][out] */ VARIANT_BOOL* pCanProvidePowerStatus_ );

    STDMETHODIMP PowerStatusGet (
        /* [ out ] */ EPowerSources* pSource_,
        /* [ out ] */ short*         pBatteryLevelPercentage_,
        /* [ out ] */ BSTR*          pDetails_ );

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

    // IIMProbe2
public:
    STDMETHODIMP CanChangeContinuousDistanceModeDistance(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    STDMETHODIMP CanChangeContinuousTimeModeTime(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    STDMETHODIMP CanFindTarget(
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    STDMETHODIMP CanGoHome(
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    STDMETHODIMP CanGoXYZ(
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    STDMETHODIMP ContinuousDistanceModeDistanceGet(
        /* [retval][out] */ double* pDistance_ );

    STDMETHODIMP ContinuousDistanceModeDistanceSet(
        /* [in] */ double distance_ );

    STDMETHODIMP ContinuousTimeModeTimeGet(
        /* [retval][out] */ long* pTime_ );

    STDMETHODIMP ContinuousTimeModeTimeSet(
        /* [in] */ long time_ );

    STDMETHODIMP FindTarget(
        /* [in] */ double searchRadius_,
        /* [in] */ double approximateDistance_ );

    STDMETHODIMP FindTargetParametersGet(
        /* [out] */ double* pSearchRadius_,
        /* [out] */ double* pApproximateDistance_ );

    STDMETHODIMP FindTargetParametersSet(
        /* [in] */ double searchRadius_,
        /* [in] */ double approximateDistance_ );

    STDMETHODIMP GoHome( void );

    STDMETHODIMP GoXYZ(
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    STDMETHODIMP GoXYZCoordinatesGet(
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    STDMETHODIMP GoXYZCoordinatesSet(
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    STDMETHODIMP NextPointIsCompensationPoint();

    STDMETHODIMP ProbingEnd2(
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    // IIMProbe3
public:
    STDMETHODIMP HasTemperature(
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    STDMETHODIMP HasRelativeHumidity(
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    STDMETHODIMP HasAirPressure(
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    STDMETHODIMP HasStatus(
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    STDMETHODIMP TemperatureGet(
        /* [retval][out] */ double* pTemperature_ );

    STDMETHODIMP RelativeHumidityGet(
        /* [retval][out] */ double* pHumidity_ );

    STDMETHODIMP AirPressureGet(
        /* [retval][out] */ double* pAirPressure_ );

    STDMETHODIMP StatusGet(
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    STDMETHODIMP ReflectorSet(
        /* [in] */ BSTR               reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ = L"" );

    STDMETHODIMP ReflectorGet(
        /* [ out ] */ BSTR* pReflectorName_ );

    STDMETHODIMP StandardReflectorsGetNb(
        /* [ retval ][ out ] */ short* pReflectorNb_ );

    STDMETHODIMP StandardReflectorInfoGet(
        /* [ in ]  */ short   reflectorIndex_,
        /* [ out ] */ BSTR*   pReflectorName_,
        /* [ out ] */ double* pReflectorOffset_ );

    STDMETHODIMP ProbeTypeGet(
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    // IIMProbe4
public:
    STDMETHODIMP CanChangeCompensationMethod(
        /* [ retval ][ out ] */ VARIANT_BOOL* pCanChangeMethod_ );

    STDMETHODIMP CompensationMethodSet(
        /* [ in ] */ ECompensationMethods compensationMethod_ );

    STDMETHODIMP CompensationPointAutomaticTriggerDistanceGet(
        /* [ retval ][ out ] */ double* pDistanceInUnits_ );

    STDMETHODIMP CompensationPointAutomaticTriggerDistanceSet(
        /* [ in ] */ double distanceInUnits_ );

    STDMETHODIMP UseCompensationPointAutomaticTriggerGet(
        /* [ retval ][ out ] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    STDMETHODIMP UseCompensationPointAutomaticTriggerSet(
        /* [ in ] */ VARIANT_BOOL useAutomaticTrigger_ );

    // IIMProbe5
public:
    STDMETHODIMP UseMeasurementAutomaticTriggerGet(
        /* [ retval ][ out ] */ VARIANT_BOOL* pUseMeasurementAutomaticTrigger_ );

    STDMETHODIMP UseMeasurementAutomaticTriggerSet(
        /* [ in ] */ VARIANT_BOOL useMeasurementAutomaticTrigger_ );

    STDMETHODIMP MeasurementAutomaticTriggerStabilityDelayGet(
        /* [ retval ][ out ] */ long* pDelay_ );

    STDMETHODIMP MeasurementAutomaticTriggerStabilityDelaySet(
        /* [ in ] */ long delay_ );

    STDMETHODIMP MeasurementAutomaticTriggerStabilityToleranceGet(
        /* [ retval ][ out ] */ double* pToleranceInUnits_ );

    STDMETHODIMP MeasurementAutomaticTriggerStabilityToleranceSet(
        /* [ in ] */ double toleranceInUnits_ );

    STDMETHODIMP ModeTypeGet(
        /* [in] */ short               modeNb_,
        /* [out] */ EProbingModeTypes* pType_ );

    STDMETHODIMP NextProbingIsShankProbing();

    STDMETHODIMP GoXYZ2(
        /* [in] */ double       X_,
        /* [in] */ double       Y_,
        /* [in] */ double       Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    // IIMProbe6
public:
    STDMETHODIMP FindTargetOnGoXYZGet(
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    STDMETHODIMP FindTargetOnGoXYZSet(
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    STDMETHODIMP CanGoFront(
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    STDMETHODIMP GoFront( void );

    STDMETHODIMP HasUserEnvironmentalParameters(
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    STDMETHODIMP EnvironmentalParametersSourceGet(
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    STDMETHODIMP EnvironmentalParametersSourceSet(
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    STDMETHODIMP UserTemperatureGet(
        /* [retval][out] */ double* pTemperature_ );

    STDMETHODIMP UserTemperatureSet(
        /* [in] */ double temperature_ );

    STDMETHODIMP UserRelativeHumiditySet(
        /* [in] */ double humidity_ );

    STDMETHODIMP UserRelativeHumidityGet(
        /* [retval][out] */ double* pHumidity_ );

    STDMETHODIMP UserAirPressureGet(
        /* [retval][out] */ double* pAirPressure_ );

    STDMETHODIMP UserAirPressureSet(
        /* [in] */ double airPressure_ );

    // IIMProbe7
public:
    STDMETHODIMP CanChangeFace(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    STDMETHODIMP FaceGet(
        /* [retval][out] */ short* pFace_ );

    STDMETHODIMP FaceSet(
        /* [ in ] */ short face_ );

    // IIMProbe8
public:
    STDMETHODIMP HasShank(
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    STDMETHODIMP ShankDiameterGet(
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    // IIMProbe9
public:
    STDMETHODIMP CanChangeRealTimePositionSending(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    STDMETHODIMP CanPowerSearchTarget(
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    STDMETHODIMP CanUseAutomaticTargetRecognition(
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    STDMETHODIMP CanUseLaserPointer(
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    STDMETHODIMP CanUseTargetIllumination(
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    STDMETHODIMP CanUseTargetLock(
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    STDMETHODIMP HasManualControlsDlg(
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    STDMETHODIMP ManualControlsDlgShow( void );

    STDMETHODIMP NextProbingIsSingleDirectionProbing( void );

    STDMETHODIMP SendRealTimePositionsGet(
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    STDMETHODIMP SendRealTimePositionsSet(
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    STDMETHODIMP PowerSearchTarget( void );

    STDMETHODIMP StatusGet2(
        /* [out] */ BSTR*                  pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    STDMETHODIMP UseAutomaticTargetRecognitionGet(
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    STDMETHODIMP UseAutomaticTargetRecognitionSet(
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    STDMETHODIMP UseLaserPointerGet(
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    STDMETHODIMP UseLaserPointerSet(
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    STDMETHODIMP UseTargetIlluminationGet(
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    STDMETHODIMP UseTargetIlluminationSet(
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    STDMETHODIMP UseTargetLockGet(
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    STDMETHODIMP UseTargetLockSet(
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    // IIMProbe10
public:
    STDMETHODIMP CanChangeContinuousMeasuringResumingOnTargetRecovery(
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    STDMETHODIMP ResumeContinuousMeasuringOnTargetRecoveryGet(
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    STDMETHODIMP ResumeContinuousMeasuringOnTargetRecoverySet(
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    // IIMProbe11
public:
    STDMETHODIMP HasMotorActivationState(
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    STDMETHODIMP CanDeactivateMotors(
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    STDMETHODIMP MotorActivationStateGet(
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    STDMETHODIMP MotorActivationStateSet(
        /* [in] */ VARIANT_BOOL activationState_ );

    STDMETHODIMP ManualControlsDlgClose();

    // IIMProbe12
public:
    STDMETHODIMP IsCompensationMethodSupported(
        /* [in] */ ECompensationMethods   compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    // IIMProbe13
public:
    STDMETHODIMP LocalizationProbeSelectionDlgShow();

    STDMETHODIMP LocalizationProbeNameGet(
        /* [retval][out] */ BSTR* pProbeName_ );

    STDMETHODIMP LocalizationProbeActivate(
        /* [in] */ VARIANT_BOOL activate_ );

    // IIMProbe14
public:
    STDMETHODIMP ProbeGet(
        /* [retval][out] */ BSTR* pProbeName_ );

    STDMETHODIMP ProbeSet(
        /* [in] */ BSTR probeName_ );

    STDMETHODIMP StandardProbesGetNb(
        /* [retval][out] */ short* pProbeNb_ );

    STDMETHODIMP StandardProbeInfoGet(
        /* [in] */ short    probeIndex_,
        /* [out] */ BSTR*   pProbeName_,
        /* [out] */ double* pProbeDiameterInUnits_ );

    // IIMProbe15
public://
    STDMETHODIMP DeviceDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY** pNames_ );

    STDMETHODIMP ModeDeprecatedNamesGet(
        /* [in] */ short            modeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    STDMETHODIMP StandardReflectorDeprecatedNamesGet(
        /* [in] */ short            reflectorIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    STDMETHODIMP StandardProbeDeprecatedNamesGet(
        /* [in] */ short            probeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    // IIMProbe16
public://
    STDMETHODIMP CanFindTargetUsingCamera(
        /* [retval][out] */ VARIANT_BOOL* pCanFindTargetUsingCamera_ );

    STDMETHODIMP FindTargetUsingCamera();

    // IIMProbe17
public://
    STDMETHODIMP DeviceTypeGet(
        /* [retval][out] */ EDeviceTypes* pDeviceType_ );

    STDMETHODIMP IsToolTypeSupported(
        /* [in] */ EProbeTypes            probeType_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    STDMETHODIMP StandardReflectorInfosSet(
        /* [in] */ SAFEARRAY** pNames_,
        /* [in] */ SAFEARRAY** pDiameters_ );

    STDMETHODIMP StandardProbeInfosSet(
        /* [in] */ SAFEARRAY** pNames_,
        /* [in] */ SAFEARRAY** pDiameters_ );

    // IIMPieceTemperature
public:
    STDMETHODIMP HasPieceTemperature(
        /* [retval][out] */ VARIANT_BOOL* pHasPieceTemperature_ );

    STDMETHODIMP PieceTemperatureGet(
        /* [retval][out] */ double* pPieceTemperature_ );

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
        /* [in] */ SAFEARRAY* pSettingNames_ ) override;

    // IIMUnitsUser
public:
    STDMETHODIMP UnitsScalingFactorSet(
        /* [in] */ double scalingFactor_ );
};

// =================================================================================================
// ===================================== FUNCTION PROTOTYPES =======================================

#endif // _CCOMPANYNAMEPROBEPLUGIN_FRIDAY_OCTOBER252013_093938_H_
