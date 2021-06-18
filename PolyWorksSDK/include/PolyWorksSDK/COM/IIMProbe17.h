/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jan 29 10:07:36 2016
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe17.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603
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

#ifndef __IIMProbe17_h__
#define __IIMProbe17_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe17_FWD_DEFINED__
#define __IIMProbe17_FWD_DEFINED__
typedef interface IIMProbe17 IIMProbe17;

#endif  /* __IIMProbe17_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe16.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe17_INTERFACE_DEFINED__
#define __IIMProbe17_INTERFACE_DEFINED__

/* interface IIMProbe17 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe17;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "0FC92941-8D2B-4B59-949D-E520A40B1E17" )
IIMProbe17 : public IIMProbe16
{
public:
    virtual HRESULT STDMETHODCALLTYPE DeviceTypeGet(
        /* [retval][out] */ EDeviceTypes * pDeviceType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE IsToolTypeSupported(
        /* [in] */ EProbeTypes toolType_,
        /* [retval][out] */ VARIANT_BOOL * pIsSupported_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardReflectorInfosSet(
        /* [in] */ SAFEARRAY * *pNames_,
        /* [in] */ SAFEARRAY * *pOffsetInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardProbeInfosSet(
        /* [in] */ SAFEARRAY * *pNames_,
        /* [in] */ SAFEARRAY * *pDiametersInUnits_ ) = 0;

};


#else   /* C style interface */

typedef struct IIMProbe17Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe17 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        _COM_Outptr_  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe17 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe17 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe17 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe17 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe17 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe17 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe17 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe17 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe17 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe17 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe17 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe17 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe17 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe17 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe17 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe17 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe17 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe17 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe17 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe17 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe17 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe17 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe17 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe17 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe17 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe17 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe17 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe17 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe17 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe17 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe17 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe17 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe17 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe17 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe17 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe17 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe17 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe17 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe17 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe17 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe17 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe17 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe17 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe17 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe17 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe17 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe17 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe17 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousMeasuringResumingOnTargetRecovery )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoveryGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoverySet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * HasMotorActivationState )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CanDeactivateMotors )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateGet )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbe17 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClose )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * IsCompensationMethodSupported )(
        IIMProbe17 * This,
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeSelectionDlgShow )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeNameGet )(
        IIMProbe17 * This,
        BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeActivate )(
        IIMProbe17 * This,
        VARIANT_BOOL activate_ );

    HRESULT( STDMETHODCALLTYPE * ProbeGet )(
        IIMProbe17 * This,
        /* [retval][out] */ BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * ProbeSet )(
        IIMProbe17 * This,
        /* [in] */ BSTR probeName_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbesGetNb )(
        IIMProbe17 * This,
        /* [retval][out] */ short* pProbeNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeInfoGet )(
        IIMProbe17 * This,
        /* [in] */ short probeIndex_,
        /* [out] */ BSTR* pProbeName_,
        /* [out] */ double* pProbeDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * DeviceDeprecatedNamesGet )(
        IIMProbe17 * This,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * ModeDeprecatedNamesGet )(
        IIMProbe17 * This,
        /* [in] */ short modeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorDeprecatedNamesGet )(
        IIMProbe17 * This,
        /* [in] */ short reflectorIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeDeprecatedNamesGet )(
        IIMProbe17 * This,
        /* [in] */ short probeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTargetUsingCamera )(
        IIMProbe17 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTargetUsingCamera_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetUsingCamera )(
        IIMProbe17 * This );

    HRESULT( STDMETHODCALLTYPE * DeviceTypeGet )(
        IIMProbe17 * This,
        /* [retval][out] */ EDeviceTypes* pDeviceType_ );

    HRESULT( STDMETHODCALLTYPE * IsToolTypeSupported )(
        IIMProbe17 * This,
        /* [in] */ EProbeTypes toolType_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfosSet )(
        IIMProbe17 * This,
        /* [in] */ SAFEARRAY** pNames_,
        /* [in] */ SAFEARRAY** pOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeInfosSet )(
        IIMProbe17 * This,
        /* [in] */ SAFEARRAY** pNames_,
        /* [in] */ SAFEARRAY** pDiametersInUnits_ );

    END_INTERFACE
} IIMProbe17Vtbl;

interface IIMProbe17
{
    CONST_VTBL struct IIMProbe17Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe17_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe17_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe17_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe17_CanChangeUnits( This, pCanChangeUnits_ )    \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe17_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )    \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe17_CompensationMethodGet( This, pCompensationMethod_ ) \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe17_ConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe17_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe17_DeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe17_DiameterGet( This, pDiameterInUnits_ )  \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe17_HasPropertiesDlg( This, pHasPropertiesDlg_ )    \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe17_MeasurementStart( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe17_MeasurementStop( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe17_ModeGet( This, pModeNb_ )   \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe17_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe17_ModesGetNb( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe17_ModeNameGet( This, modeNb_, pModeName_ ) \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe17_NeedMeasurementButtons( This, pNeedButtons_ )   \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe17_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe17_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )   \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe17_PropertiesDlgShow( This )  \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe17_SharedMatrixNameGet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe17_SharedMatrixNameSet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe17_TransformationMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe17_TransformationMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe17_UnitsGet( This, pUnits_ )   \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe17_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe17_UseAutoViewpointGet( This, pUseAutoViewpoint_ ) \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe17_UseAutoViewpointSet( This, useAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe17_UseDeviceAsMouseGet( This, pUseAsMouse_ )   \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe17_UseDeviceAsMouseSet( This, useAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe17_UseTransformationMatrixGet( This, pUseMatrix_ ) \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe17_UseTransformationMatrixSet( This, useMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe17_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe17_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe17_CanFindTarget( This, pCanFindTarget_ )  \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe17_CanGoHome( This, pCanGoHome_ )  \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe17_CanGoXYZ( This, pCanGoXYZ_ )    \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe17_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ )    \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe17_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe17_ContinuousTimeModeTimeGet( This, pTime_ )   \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe17_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe17_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe17_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe17_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )   \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe17_GoHome( This ) \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe17_GoXYZ( This, X_, Y_, Z_ ) \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe17_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe17_GoXYZCoordinatesSet( This, X_, Y_, Z_ )   \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe17_NextPointIsCompensationPoint( This )   \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe17_ProbingEnd2( This, probeLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe17_HasTemperature( This, pHasTemperature_ )    \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe17_HasRelativeHumidity( This, pHasHumidity_ )  \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe17_HasAirPressure( This, pHasAirPressure_ )    \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe17_HasStatus( This, pHasStatus_ )  \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe17_TemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe17_RelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe17_AirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe17_StatusGet( This, pStatus_ ) \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe17_ProbeTypeGet( This, pProbeType_ )   \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe17_ReflectorSet( This, reflectorName_, standardReflectorName_ ) \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe17_ReflectorGet( This, pReflectorName_ )   \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe17_StandardReflectorsGetNb( This, pReflectorNb_ )  \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe17_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe17_CanChangeCompensationMethod( This, pCanChangeMethod_ )  \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe17_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe17_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe17_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe17_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe17_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe17_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )   \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe17_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )   \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe17_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe17_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe17_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe17_ModeTypeGet( This, modeNb_, pModeType_ ) \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe17_NextProbingIsShankProbing( This )  \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe17_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe17_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe17_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )   \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe17_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe17_CanGoFront( This, pCanGoFront_ )    \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe17_GoFront( This )    \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe17_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )  \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe17_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe17_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe17_UserTemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe17_UserTemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe17_UserRelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe17_UserRelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe17_UserAirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe17_UserAirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe17_CanChangeFace( This, pCanChangeFace_ )  \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe17_FaceGet( This, pFace_ ) \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe17_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe17_HasShank( This, pHasShank_ )    \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe17_ShankDiameterGet( This, pShankDiameterInUnits_ )    \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe17_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ )    \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe17_CanPowerSearchTarget( This, pCanPowerSearchTarget_ )    \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe17_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe17_CanUseLaserPointer( This, pCanUseLaserPointer_ )    \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe17_CanUseTargetIllumination( This, pCanUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe17_CanUseTargetLock( This, pCanUseTargetLock_ )    \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe17_HasManualControlsDlg( This, pHasManualControlsDialog_ ) \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe17_ManualControlsDlgShow( This )  \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe17_NextProbingIsSingleDirectionProbing( This )    \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe17_SendRealTimePositionsGet( This, pSendRealTimePositions_ )   \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe17_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe17_PowerSearchTarget( This )  \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe17_StatusGet2( This, pDetails_, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe17_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )   \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe17_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe17_UseLaserPointerGet( This, pUseLaserPointer_ )   \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe17_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe17_UseTargetIlluminationGet( This, pUseTargetIllumination_ )   \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe17_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe17_UseTargetLockGet( This, pUseTargetLock_ )   \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe17_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbe17_CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ ) )

#define IIMProbe17_ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) )

#define IIMProbe17_ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ )  \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ ) )


#define IIMProbe17_HasMotorActivationState( This, pHasActivationState_ )   \
    ( ( This )->lpVtbl->HasMotorActivationState( This, pHasActivationState_ ) )

#define IIMProbe17_CanDeactivateMotors( This, pCanDeactivateMotors_ )  \
    ( ( This )->lpVtbl->CanDeactivateMotors( This, pCanDeactivateMotors_ ) )

#define IIMProbe17_MotorActivationStateGet( This, pActivationState_ )  \
    ( ( This )->lpVtbl->MotorActivationStateGet( This, pActivationState_ ) )

#define IIMProbe17_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbe17_ManualControlsDlgClose( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClose( This ) )


#define IIMProbe17_IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ ) )


#define IIMProbe17_LocalizationProbeSelectionDlgShow( This )  \
    ( ( This )->lpVtbl->LocalizationProbeSelectionDlgShow( This ) )

#define IIMProbe17_LocalizationProbeNameGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->LocalizationProbeNameGet( This, pProbeName_ ) )

#define IIMProbe17_LocalizationProbeActivate( This, activate_ )    \
    ( ( This )->lpVtbl->LocalizationProbeActivate( This, activate_ ) )


#define IIMProbe17_ProbeGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->ProbeGet( This, pProbeName_ ) )

#define IIMProbe17_ProbeSet( This, probeName_ )    \
    ( ( This )->lpVtbl->ProbeSet( This, probeName_ ) )

#define IIMProbe17_StandardProbesGetNb( This, pProbeNb_ )  \
    ( ( This )->lpVtbl->StandardProbesGetNb( This, pProbeNb_ ) )

#define IIMProbe17_StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ )    \
    ( ( This )->lpVtbl->StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ ) )


#define IIMProbe17_DeviceDeprecatedNamesGet( This, pNames_ )   \
    ( ( This )->lpVtbl->DeviceDeprecatedNamesGet( This, pNames_ ) )

#define IIMProbe17_ModeDeprecatedNamesGet( This, modeIndex_, pNames_ )  \
    ( ( This )->lpVtbl->ModeDeprecatedNamesGet( This, modeIndex_, pNames_ ) )

#define IIMProbe17_StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ ) )

#define IIMProbe17_StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ ) )


#define IIMProbe17_CanFindTargetUsingCamera( This, pCanFindTargetUsingCamera_ )    \
    ( ( This )->lpVtbl->CanFindTargetUsingCamera( This, pCanFindTargetUsingCamera_ ) )

#define IIMProbe17_FindTargetUsingCamera( This )  \
    ( ( This )->lpVtbl->FindTargetUsingCamera( This ) )


#define IIMProbe17_DeviceTypeGet( This, pDeviceType_ ) \
    ( ( This )->lpVtbl->DeviceTypeGet( This, pDeviceType_ ) )

#define IIMProbe17_IsToolTypeSupported( This, toolType_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsToolTypeSupported( This, toolType_, pIsSupported_ ) )

#define IIMProbe17_StandardReflectorInfosSet( This, pNames_, pOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfosSet( This, pNames_, pOffsetInUnits_ ) )

#define IIMProbe17_StandardProbeInfosSet( This, pNames_, pDiametersInUnits_ )   \
    ( ( This )->lpVtbl->StandardProbeInfosSet( This, pNames_, pDiametersInUnits_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */



HRESULT STDMETHODCALLTYPE IIMProbe17_DeviceTypeGet_Proxy(
    IIMProbe17*                       This,
    /* [retval][out] */ EDeviceTypes* pDeviceType_ );


void __RPC_STUB IIMProbe17_DeviceTypeGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe17_IsToolTypeSupported_Proxy(
    IIMProbe17*                       This,
    /* [in] */ EProbeTypes            toolType_,
    /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );


void __RPC_STUB IIMProbe17_IsToolTypeSupported_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe17_StandardReflectorInfosSet_Proxy(
    IIMProbe17*            This,
    /* [in] */ SAFEARRAY** pNames_,
    /* [in] */ SAFEARRAY** pOffsetInUnits_ );


void __RPC_STUB IIMProbe17_StandardReflectorInfosSet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe17_StandardProbeInfosSet_Proxy(
    IIMProbe17*            This,
    /* [in] */ SAFEARRAY** pNames_,
    /* [in] */ SAFEARRAY** pDiametersInUnits_ );


void __RPC_STUB IIMProbe17_StandardProbeInfosSet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );



#endif  /* __IIMProbe17_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe17_h__
