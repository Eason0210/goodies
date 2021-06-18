/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jul 15 15:30:07 2015
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe15.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data
    VC __declspec() decoration level:
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
 */
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IIMProbe15_h__
#define __IIMProbe15_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe15_FWD_DEFINED__
#define __IIMProbe15_FWD_DEFINED__
typedef interface IIMProbe15 IIMProbe15;
#endif  /* __IIMProbe15_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe14.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe15_INTERFACE_DEFINED__
#define __IIMProbe15_INTERFACE_DEFINED__

/* interface IIMProbe15 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe15;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "CD8D3501-9307-4982-8BF9-CADE1EADCA3D" )
IIMProbe15 : public IIMProbe14
{
public:
    virtual HRESULT STDMETHODCALLTYPE DeviceDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModeDeprecatedNamesGet(
        /* [in] */ short modeIndex_,
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardReflectorDeprecatedNamesGet(
        /* [in] */ short reflectorIndex_,
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardProbeDeprecatedNamesGet(
        /* [in] */ short probeIndex_,
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe15Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe15 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe15 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe15 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe15 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe15 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe15 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe15 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe15 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe15 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe15 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe15 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe15 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe15 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe15 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe15 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe15 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe15 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe15 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe15 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe15 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe15 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe15 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe15 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe15 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe15 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe15 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe15 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe15 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe15 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe15 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe15 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe15 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe15 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe15 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe15 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe15 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe15 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe15 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe15 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe15 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe15 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe15 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe15 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe15 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe15 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe15 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe15 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe15 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe15 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousMeasuringResumingOnTargetRecovery )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoveryGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoverySet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * HasMotorActivationState )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CanDeactivateMotors )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateGet )(
        IIMProbe15 * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbe15 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClose )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * IsCompensationMethodSupported )(
        IIMProbe15 * This,
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeSelectionDlgShow )(
        IIMProbe15 * This );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeNameGet )(
        IIMProbe15 * This,
        BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeActivate )(
        IIMProbe15 * This,
        VARIANT_BOOL activate_ );

    HRESULT( STDMETHODCALLTYPE * ProbeGet )(
        IIMProbe15 * This,
        /* [retval][out] */ BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * ProbeSet )(
        IIMProbe15 * This,
        /* [in] */ BSTR probeName_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbesGetNb )(
        IIMProbe15 * This,
        /* [retval][out] */ short* pProbeNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeInfoGet )(
        IIMProbe15 * This,
        /* [in] */ short probeIndex_,
        /* [out] */ BSTR* pProbeName_,
        /* [out] */ double* pProbeDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * DeviceDeprecatedNamesGet )(
        IIMProbe15 * This,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * ModeDeprecatedNamesGet )(
        IIMProbe15 * This,
        /* [in] */ short modeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorDeprecatedNamesGet )(
        IIMProbe15 * This,
        /* [in] */ short reflectorIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeDeprecatedNamesGet )(
        IIMProbe15 * This,
        /* [in] */ short probeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    END_INTERFACE
} IIMProbe15Vtbl;

interface IIMProbe15
{
    CONST_VTBL struct IIMProbe15Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe15_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe15_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe15_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe15_CanChangeUnits( This, pCanChangeUnits_ )    \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe15_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )    \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe15_CompensationMethodGet( This, pCompensationMethod_ ) \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe15_ConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe15_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe15_DeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe15_DiameterGet( This, pDiameterInUnits_ )  \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe15_HasPropertiesDlg( This, pHasPropertiesDlg_ )    \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe15_MeasurementStart( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe15_MeasurementStop( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe15_ModeGet( This, pModeNb_ )   \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe15_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe15_ModesGetNb( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe15_ModeNameGet( This, modeNb_, pModeName_ ) \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe15_NeedMeasurementButtons( This, pNeedButtons_ )   \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe15_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe15_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )   \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe15_PropertiesDlgShow( This )  \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe15_SharedMatrixNameGet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe15_SharedMatrixNameSet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe15_TransformationMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe15_TransformationMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe15_UnitsGet( This, pUnits_ )   \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe15_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe15_UseAutoViewpointGet( This, pUseAutoViewpoint_ ) \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe15_UseAutoViewpointSet( This, useAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe15_UseDeviceAsMouseGet( This, pUseAsMouse_ )   \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe15_UseDeviceAsMouseSet( This, useAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe15_UseTransformationMatrixGet( This, pUseMatrix_ ) \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe15_UseTransformationMatrixSet( This, useMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe15_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe15_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe15_CanFindTarget( This, pCanFindTarget_ )  \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe15_CanGoHome( This, pCanGoHome_ )  \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe15_CanGoXYZ( This, pCanGoXYZ_ )    \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe15_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ )    \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe15_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe15_ContinuousTimeModeTimeGet( This, pTime_ )   \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe15_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe15_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe15_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe15_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )   \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe15_GoHome( This ) \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe15_GoXYZ( This, X_, Y_, Z_ ) \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe15_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe15_GoXYZCoordinatesSet( This, X_, Y_, Z_ )   \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe15_NextPointIsCompensationPoint( This )   \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe15_ProbingEnd2( This, probeLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe15_HasTemperature( This, pHasTemperature_ )    \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe15_HasRelativeHumidity( This, pHasHumidity_ )  \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe15_HasAirPressure( This, pHasAirPressure_ )    \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe15_HasStatus( This, pHasStatus_ )  \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe15_TemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe15_RelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe15_AirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe15_StatusGet( This, pStatus_ ) \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe15_ProbeTypeGet( This, pProbeType_ )   \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe15_ReflectorSet( This, reflectorName_, standardReflectorName_ ) \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe15_ReflectorGet( This, pReflectorName_ )   \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe15_StandardReflectorsGetNb( This, pReflectorNb_ )  \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe15_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe15_CanChangeCompensationMethod( This, pCanChangeMethod_ )  \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe15_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe15_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe15_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe15_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe15_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe15_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )   \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe15_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )   \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe15_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe15_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe15_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe15_ModeTypeGet( This, modeNb_, pModeType_ ) \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe15_NextProbingIsShankProbing( This )  \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe15_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe15_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe15_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )   \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe15_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe15_CanGoFront( This, pCanGoFront_ )    \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe15_GoFront( This )    \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe15_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )  \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe15_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe15_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe15_UserTemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe15_UserTemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe15_UserRelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe15_UserRelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe15_UserAirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe15_UserAirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe15_CanChangeFace( This, pCanChangeFace_ )  \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe15_FaceGet( This, pFace_ ) \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe15_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe15_HasShank( This, pHasShank_ )    \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe15_ShankDiameterGet( This, pShankDiameterInUnits_ )    \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe15_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ )    \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe15_CanPowerSearchTarget( This, pCanPowerSearchTarget_ )    \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe15_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe15_CanUseLaserPointer( This, pCanUseLaserPointer_ )    \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe15_CanUseTargetIllumination( This, pCanUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe15_CanUseTargetLock( This, pCanUseTargetLock_ )    \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe15_HasManualControlsDlg( This, pHasManualControlsDialog_ ) \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe15_ManualControlsDlgShow( This )  \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe15_NextProbingIsSingleDirectionProbing( This )    \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe15_SendRealTimePositionsGet( This, pSendRealTimePositions_ )   \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe15_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe15_PowerSearchTarget( This )  \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe15_StatusGet2( This, pDetails_, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe15_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )   \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe15_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe15_UseLaserPointerGet( This, pUseLaserPointer_ )   \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe15_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe15_UseTargetIlluminationGet( This, pUseTargetIllumination_ )   \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe15_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe15_UseTargetLockGet( This, pUseTargetLock_ )   \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe15_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbe15_CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ ) )

#define IIMProbe15_ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) )

#define IIMProbe15_ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ )  \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ ) )


#define IIMProbe15_HasMotorActivationState( This, pHasActivationState_ )   \
    ( ( This )->lpVtbl->HasMotorActivationState( This, pHasActivationState_ ) )

#define IIMProbe15_CanDeactivateMotors( This, pCanDeactivateMotors_ )  \
    ( ( This )->lpVtbl->CanDeactivateMotors( This, pCanDeactivateMotors_ ) )

#define IIMProbe15_MotorActivationStateGet( This, pActivationState_ )  \
    ( ( This )->lpVtbl->MotorActivationStateGet( This, pActivationState_ ) )

#define IIMProbe15_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbe15_ManualControlsDlgClose( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClose( This ) )


#define IIMProbe15_IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ ) )


#define IIMProbe15_LocalizationProbeSelectionDlgShow( This )  \
    ( ( This )->lpVtbl->LocalizationProbeSelectionDlgShow( This ) )

#define IIMProbe15_LocalizationProbeNameGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->LocalizationProbeNameGet( This, pProbeName_ ) )

#define IIMProbe15_LocalizationProbeActivate( This, activate_ )    \
    ( ( This )->lpVtbl->LocalizationProbeActivate( This, activate_ ) )


#define IIMProbe15_ProbeGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->ProbeGet( This, pProbeName_ ) )

#define IIMProbe15_ProbeSet( This, probeName_ )    \
    ( ( This )->lpVtbl->ProbeSet( This, probeName_ ) )

#define IIMProbe15_StandardProbesGetNb( This, pProbeNb_ )  \
    ( ( This )->lpVtbl->StandardProbesGetNb( This, pProbeNb_ ) )

#define IIMProbe15_StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ )    \
    ( ( This )->lpVtbl->StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ ) )


#define IIMProbe15_DeviceDeprecatedNamesGet( This, pNames_ )   \
    ( ( This )->lpVtbl->DeviceDeprecatedNamesGet( This, pNames_ ) )

#define IIMProbe15_ModeDeprecatedNamesGet( This, modeIndex_, pNames_ )  \
    ( ( This )->lpVtbl->ModeDeprecatedNamesGet( This, modeIndex_, pNames_ ) )

#define IIMProbe15_StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ ) )

#define IIMProbe15_StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */



HRESULT STDMETHODCALLTYPE IIMProbe15_DeviceDeprecatedNamesGet_Proxy(
    IIMProbe15*                 This,
    /* [out][in] */ SAFEARRAY** pNames_ );


void __RPC_STUB IIMProbe15_DeviceDeprecatedNamesGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe15_ModeDeprecatedNamesGet_Proxy(
    IIMProbe15*                 This,
    /* [in] */ short            modeIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ );


void __RPC_STUB IIMProbe15_ModeDeprecatedNamesGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe15_StandardReflectorDeprecatedNamesGet_Proxy(
    IIMProbe15*                 This,
    /* [in] */ short            reflectorIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ );


void __RPC_STUB IIMProbe15_StandardReflectorDeprecatedNamesGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe15_StandardProbeDeprecatedNamesGet_Proxy(
    IIMProbe15*                 This,
    /* [in] */ short            probeIndex_,
    /* [out][in] */ SAFEARRAY** pNames_ );


void __RPC_STUB IIMProbe15_StandardProbeDeprecatedNamesGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );



#endif  /* __IIMProbe15_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe15_h__
