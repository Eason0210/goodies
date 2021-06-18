/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 8.00.0603 */
/* at Wed Dec 09 11:00:48 2015
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe16.idl:
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

#ifndef __IIMProbe16_h__
#define __IIMProbe16_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe16_FWD_DEFINED__
#define __IIMProbe16_FWD_DEFINED__
typedef interface IIMProbe16 IIMProbe16;

#endif  /* __IIMProbe16_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe15.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe16_INTERFACE_DEFINED__
#define __IIMProbe16_INTERFACE_DEFINED__

/* interface IIMProbe16 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe16;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "B51151EC-E691-44D3-9372-DCBFEE8D7597" )
IIMProbe16 : public IIMProbe15
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanFindTargetUsingCamera(
        /* [retval][out] */ VARIANT_BOOL * pCanFindTargetUsingCamera_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE FindTargetUsingCamera( void ) = 0;

};


#else   /* C style interface */

typedef struct IIMProbe16Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe16 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        _COM_Outptr_  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe16 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe16 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe16 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe16 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe16 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe16 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe16 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe16 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe16 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe16 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe16 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe16 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe16 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe16 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe16 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe16 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe16 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe16 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe16 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe16 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe16 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe16 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe16 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe16 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe16 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe16 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe16 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe16 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe16 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe16 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe16 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe16 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe16 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe16 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe16 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe16 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe16 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe16 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe16 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe16 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe16 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe16 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe16 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe16 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe16 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe16 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe16 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe16 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousMeasuringResumingOnTargetRecovery )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoveryGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoverySet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * HasMotorActivationState )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CanDeactivateMotors )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateGet )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbe16 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClose )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * IsCompensationMethodSupported )(
        IIMProbe16 * This,
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeSelectionDlgShow )(
        IIMProbe16 * This );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeNameGet )(
        IIMProbe16 * This,
        BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeActivate )(
        IIMProbe16 * This,
        VARIANT_BOOL activate_ );

    HRESULT( STDMETHODCALLTYPE * ProbeGet )(
        IIMProbe16 * This,
        /* [retval][out] */ BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * ProbeSet )(
        IIMProbe16 * This,
        /* [in] */ BSTR probeName_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbesGetNb )(
        IIMProbe16 * This,
        /* [retval][out] */ short* pProbeNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeInfoGet )(
        IIMProbe16 * This,
        /* [in] */ short probeIndex_,
        /* [out] */ BSTR* pProbeName_,
        /* [out] */ double* pProbeDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * DeviceDeprecatedNamesGet )(
        IIMProbe16 * This,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * ModeDeprecatedNamesGet )(
        IIMProbe16 * This,
        /* [in] */ short modeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorDeprecatedNamesGet )(
        IIMProbe16 * This,
        /* [in] */ short reflectorIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * StandardProbeDeprecatedNamesGet )(
        IIMProbe16 * This,
        /* [in] */ short probeIndex_,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTargetUsingCamera )(
        IIMProbe16 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTargetUsingCamera_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetUsingCamera )(
        IIMProbe16 * This );

    END_INTERFACE
} IIMProbe16Vtbl;

interface IIMProbe16
{
    CONST_VTBL struct IIMProbe16Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe16_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe16_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe16_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe16_CanChangeUnits( This, pCanChangeUnits_ )    \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe16_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )    \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe16_CompensationMethodGet( This, pCompensationMethod_ ) \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe16_ConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe16_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe16_DeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe16_DiameterGet( This, pDiameterInUnits_ )  \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe16_HasPropertiesDlg( This, pHasPropertiesDlg_ )    \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe16_MeasurementStart( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe16_MeasurementStop( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe16_ModeGet( This, pModeNb_ )   \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe16_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe16_ModesGetNb( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe16_ModeNameGet( This, modeNb_, pModeName_ ) \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe16_NeedMeasurementButtons( This, pNeedButtons_ )   \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe16_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe16_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )   \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe16_PropertiesDlgShow( This )  \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe16_SharedMatrixNameGet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe16_SharedMatrixNameSet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe16_TransformationMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe16_TransformationMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe16_UnitsGet( This, pUnits_ )   \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe16_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe16_UseAutoViewpointGet( This, pUseAutoViewpoint_ ) \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe16_UseAutoViewpointSet( This, useAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe16_UseDeviceAsMouseGet( This, pUseAsMouse_ )   \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe16_UseDeviceAsMouseSet( This, useAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe16_UseTransformationMatrixGet( This, pUseMatrix_ ) \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe16_UseTransformationMatrixSet( This, useMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe16_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe16_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe16_CanFindTarget( This, pCanFindTarget_ )  \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe16_CanGoHome( This, pCanGoHome_ )  \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe16_CanGoXYZ( This, pCanGoXYZ_ )    \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe16_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ )    \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe16_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe16_ContinuousTimeModeTimeGet( This, pTime_ )   \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe16_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe16_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe16_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe16_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )   \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe16_GoHome( This ) \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe16_GoXYZ( This, X_, Y_, Z_ ) \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe16_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe16_GoXYZCoordinatesSet( This, X_, Y_, Z_ )   \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe16_NextPointIsCompensationPoint( This )   \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe16_ProbingEnd2( This, probeLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe16_HasTemperature( This, pHasTemperature_ )    \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe16_HasRelativeHumidity( This, pHasHumidity_ )  \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe16_HasAirPressure( This, pHasAirPressure_ )    \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe16_HasStatus( This, pHasStatus_ )  \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe16_TemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe16_RelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe16_AirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe16_StatusGet( This, pStatus_ ) \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe16_ProbeTypeGet( This, pProbeType_ )   \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe16_ReflectorSet( This, reflectorName_, standardReflectorName_ ) \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe16_ReflectorGet( This, pReflectorName_ )   \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe16_StandardReflectorsGetNb( This, pReflectorNb_ )  \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe16_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe16_CanChangeCompensationMethod( This, pCanChangeMethod_ )  \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe16_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe16_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe16_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe16_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe16_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe16_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )   \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe16_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )   \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe16_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe16_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe16_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe16_ModeTypeGet( This, modeNb_, pModeType_ ) \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe16_NextProbingIsShankProbing( This )  \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe16_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe16_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe16_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )   \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe16_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe16_CanGoFront( This, pCanGoFront_ )    \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe16_GoFront( This )    \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe16_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )  \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe16_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe16_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe16_UserTemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe16_UserTemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe16_UserRelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe16_UserRelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe16_UserAirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe16_UserAirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe16_CanChangeFace( This, pCanChangeFace_ )  \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe16_FaceGet( This, pFace_ ) \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe16_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe16_HasShank( This, pHasShank_ )    \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe16_ShankDiameterGet( This, pShankDiameterInUnits_ )    \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe16_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ )    \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe16_CanPowerSearchTarget( This, pCanPowerSearchTarget_ )    \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe16_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe16_CanUseLaserPointer( This, pCanUseLaserPointer_ )    \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe16_CanUseTargetIllumination( This, pCanUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe16_CanUseTargetLock( This, pCanUseTargetLock_ )    \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe16_HasManualControlsDlg( This, pHasManualControlsDialog_ ) \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe16_ManualControlsDlgShow( This )  \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe16_NextProbingIsSingleDirectionProbing( This )    \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe16_SendRealTimePositionsGet( This, pSendRealTimePositions_ )   \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe16_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe16_PowerSearchTarget( This )  \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe16_StatusGet2( This, pDetails_, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe16_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )   \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe16_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe16_UseLaserPointerGet( This, pUseLaserPointer_ )   \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe16_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe16_UseTargetIlluminationGet( This, pUseTargetIllumination_ )   \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe16_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe16_UseTargetLockGet( This, pUseTargetLock_ )   \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe16_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbe16_CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ ) )

#define IIMProbe16_ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) )

#define IIMProbe16_ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ )  \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ ) )


#define IIMProbe16_HasMotorActivationState( This, pHasActivationState_ )   \
    ( ( This )->lpVtbl->HasMotorActivationState( This, pHasActivationState_ ) )

#define IIMProbe16_CanDeactivateMotors( This, pCanDeactivateMotors_ )  \
    ( ( This )->lpVtbl->CanDeactivateMotors( This, pCanDeactivateMotors_ ) )

#define IIMProbe16_MotorActivationStateGet( This, pActivationState_ )  \
    ( ( This )->lpVtbl->MotorActivationStateGet( This, pActivationState_ ) )

#define IIMProbe16_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbe16_ManualControlsDlgClose( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClose( This ) )


#define IIMProbe16_IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ ) )


#define IIMProbe16_LocalizationProbeSelectionDlgShow( This )  \
    ( ( This )->lpVtbl->LocalizationProbeSelectionDlgShow( This ) )

#define IIMProbe16_LocalizationProbeNameGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->LocalizationProbeNameGet( This, pProbeName_ ) )

#define IIMProbe16_LocalizationProbeActivate( This, activate_ )    \
    ( ( This )->lpVtbl->LocalizationProbeActivate( This, activate_ ) )


#define IIMProbe16_ProbeGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->ProbeGet( This, pProbeName_ ) )

#define IIMProbe16_ProbeSet( This, probeName_ )    \
    ( ( This )->lpVtbl->ProbeSet( This, probeName_ ) )

#define IIMProbe16_StandardProbesGetNb( This, pProbeNb_ )  \
    ( ( This )->lpVtbl->StandardProbesGetNb( This, pProbeNb_ ) )

#define IIMProbe16_StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ )    \
    ( ( This )->lpVtbl->StandardProbeInfoGet( This, probeIndex_, pProbeName_, pProbeDiameterInUnits_ ) )


#define IIMProbe16_DeviceDeprecatedNamesGet( This, pNames_ )   \
    ( ( This )->lpVtbl->DeviceDeprecatedNamesGet( This, pNames_ ) )

#define IIMProbe16_ModeDeprecatedNamesGet( This, modeIndex_, pNames_ )  \
    ( ( This )->lpVtbl->ModeDeprecatedNamesGet( This, modeIndex_, pNames_ ) )

#define IIMProbe16_StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardReflectorDeprecatedNamesGet( This, reflectorIndex_, pNames_ ) )

#define IIMProbe16_StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ )    \
    ( ( This )->lpVtbl->StandardProbeDeprecatedNamesGet( This, probeIndex_, pNames_ ) )


#define IIMProbe16_CanFindTargetUsingCamera( This, pCanFindTargetUsingCamera_ )    \
    ( ( This )->lpVtbl->CanFindTargetUsingCamera( This, pCanFindTargetUsingCamera_ ) )

#define IIMProbe16_FindTargetUsingCamera( This )  \
    ( ( This )->lpVtbl->FindTargetUsingCamera( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */



HRESULT STDMETHODCALLTYPE IIMProbe16_CanFindTargetUsingCamera_Proxy(
    IIMProbe16*                       This,
    /* [retval][out] */ VARIANT_BOOL* pCanFindTargetUsingCamera_ );


void __RPC_STUB IIMProbe16_CanFindTargetUsingCamera_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe16_FindTargetUsingCamera_Proxy(
    IIMProbe16* This );


void __RPC_STUB IIMProbe16_FindTargetUsingCamera_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );



#endif  /* __IIMProbe16_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe16_h__
