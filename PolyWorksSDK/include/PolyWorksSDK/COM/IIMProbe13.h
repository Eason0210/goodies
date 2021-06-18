/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jan 31 07:27:42 2013
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe13.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555
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

#ifndef __IIMProbe13_h__
#define __IIMProbe13_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe13_FWD_DEFINED__
#define __IIMProbe13_FWD_DEFINED__
typedef interface IIMProbe13 IIMProbe13;
#endif  /* __IIMProbe13_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe12.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe13_INTERFACE_DEFINED__
#define __IIMProbe13_INTERFACE_DEFINED__

/* interface IIMProbe13 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe13;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "0CD70C30-BA46-49C6-959F-0441A3871BA8" )
IIMProbe13 : public IIMProbe12
{
public:
    virtual HRESULT STDMETHODCALLTYPE LocalizationProbeSelectionDlgShow( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LocalizationProbeNameGet(
        BSTR * pProbeName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LocalizationProbeActivate(
        VARIANT_BOOL activate_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe13Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe13 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe13 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe13 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe13 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe13 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe13 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe13 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe13 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe13 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe13 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe13 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe13 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe13 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe13 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe13 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe13 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe13 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe13 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe13 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe13 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe13 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe13 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe13 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe13 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe13 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe13 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe13 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe13 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe13 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe13 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe13 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe13 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe13 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe13 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe13 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe13 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe13 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe13 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe13 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe13 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe13 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe13 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe13 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe13 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe13 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe13 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe13 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe13 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe13 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousMeasuringResumingOnTargetRecovery )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoveryGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoverySet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * HasMotorActivationState )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CanDeactivateMotors )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateGet )(
        IIMProbe13 * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbe13 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClose )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * IsCompensationMethodSupported )(
        IIMProbe13 * This,
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeSelectionDlgShow )(
        IIMProbe13 * This );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeNameGet )(
        IIMProbe13 * This,
        BSTR* pProbeName_ );

    HRESULT( STDMETHODCALLTYPE * LocalizationProbeActivate )(
        IIMProbe13 * This,
        VARIANT_BOOL activate_ );

    END_INTERFACE
} IIMProbe13Vtbl;

interface IIMProbe13
{
    CONST_VTBL struct IIMProbe13Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe13_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe13_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe13_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe13_CanChangeUnits( This, pCanChangeUnits_ )    \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe13_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )    \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe13_CompensationMethodGet( This, pCompensationMethod_ ) \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe13_ConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe13_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe13_DeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe13_DiameterGet( This, pDiameterInUnits_ )  \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe13_HasPropertiesDlg( This, pHasPropertiesDlg_ )    \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe13_MeasurementStart( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe13_MeasurementStop( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe13_ModeGet( This, pModeNb_ )   \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe13_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe13_ModesGetNb( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe13_ModeNameGet( This, modeNb_, pModeName_ ) \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe13_NeedMeasurementButtons( This, pNeedButtons_ )   \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe13_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe13_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )   \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe13_PropertiesDlgShow( This )  \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe13_SharedMatrixNameGet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe13_SharedMatrixNameSet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe13_TransformationMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe13_TransformationMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe13_UnitsGet( This, pUnits_ )   \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe13_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe13_UseAutoViewpointGet( This, pUseAutoViewpoint_ ) \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe13_UseAutoViewpointSet( This, useAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe13_UseDeviceAsMouseGet( This, pUseAsMouse_ )   \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe13_UseDeviceAsMouseSet( This, useAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe13_UseTransformationMatrixGet( This, pUseMatrix_ ) \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe13_UseTransformationMatrixSet( This, useMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe13_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe13_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe13_CanFindTarget( This, pCanFindTarget_ )  \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe13_CanGoHome( This, pCanGoHome_ )  \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe13_CanGoXYZ( This, pCanGoXYZ_ )    \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe13_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ )    \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe13_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe13_ContinuousTimeModeTimeGet( This, pTime_ )   \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe13_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe13_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe13_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe13_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )   \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe13_GoHome( This ) \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe13_GoXYZ( This, X_, Y_, Z_ ) \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe13_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe13_GoXYZCoordinatesSet( This, X_, Y_, Z_ )   \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe13_NextPointIsCompensationPoint( This )   \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe13_ProbingEnd2( This, probeLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe13_HasTemperature( This, pHasTemperature_ )    \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe13_HasRelativeHumidity( This, pHasHumidity_ )  \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe13_HasAirPressure( This, pHasAirPressure_ )    \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe13_HasStatus( This, pHasStatus_ )  \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe13_TemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe13_RelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe13_AirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe13_StatusGet( This, pStatus_ ) \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe13_ProbeTypeGet( This, pProbeType_ )   \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe13_ReflectorSet( This, reflectorName_, standardReflectorName_ ) \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe13_ReflectorGet( This, pReflectorName_ )   \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe13_StandardReflectorsGetNb( This, pReflectorNb_ )  \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe13_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe13_CanChangeCompensationMethod( This, pCanChangeMethod_ )  \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe13_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe13_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe13_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe13_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe13_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe13_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )   \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe13_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )   \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe13_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe13_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe13_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe13_ModeTypeGet( This, modeNb_, pModeType_ ) \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe13_NextProbingIsShankProbing( This )  \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe13_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe13_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe13_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )   \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe13_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe13_CanGoFront( This, pCanGoFront_ )    \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe13_GoFront( This )    \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe13_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )  \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe13_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe13_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe13_UserTemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe13_UserTemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe13_UserRelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe13_UserRelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe13_UserAirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe13_UserAirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe13_CanChangeFace( This, pCanChangeFace_ )  \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe13_FaceGet( This, pFace_ ) \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe13_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe13_HasShank( This, pHasShank_ )    \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe13_ShankDiameterGet( This, pShankDiameterInUnits_ )    \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe13_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ )    \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe13_CanPowerSearchTarget( This, pCanPowerSearchTarget_ )    \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe13_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe13_CanUseLaserPointer( This, pCanUseLaserPointer_ )    \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe13_CanUseTargetIllumination( This, pCanUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe13_CanUseTargetLock( This, pCanUseTargetLock_ )    \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe13_HasManualControlsDlg( This, pHasManualControlsDialog_ ) \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe13_ManualControlsDlgShow( This )  \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe13_NextProbingIsSingleDirectionProbing( This )    \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe13_SendRealTimePositionsGet( This, pSendRealTimePositions_ )   \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe13_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe13_PowerSearchTarget( This )  \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe13_StatusGet2( This, pDetails_, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe13_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )   \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe13_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe13_UseLaserPointerGet( This, pUseLaserPointer_ )   \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe13_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe13_UseTargetIlluminationGet( This, pUseTargetIllumination_ )   \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe13_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe13_UseTargetLockGet( This, pUseTargetLock_ )   \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe13_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbe13_CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ ) )

#define IIMProbe13_ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) )

#define IIMProbe13_ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ )  \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ ) )


#define IIMProbe13_HasMotorActivationState( This, pHasActivationState_ )   \
    ( ( This )->lpVtbl->HasMotorActivationState( This, pHasActivationState_ ) )

#define IIMProbe13_CanDeactivateMotors( This, pCanDeactivateMotors_ )  \
    ( ( This )->lpVtbl->CanDeactivateMotors( This, pCanDeactivateMotors_ ) )

#define IIMProbe13_MotorActivationStateGet( This, pActivationState_ )  \
    ( ( This )->lpVtbl->MotorActivationStateGet( This, pActivationState_ ) )

#define IIMProbe13_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbe13_ManualControlsDlgClose( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClose( This ) )


#define IIMProbe13_IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ ) )


#define IIMProbe13_LocalizationProbeSelectionDlgShow( This )  \
    ( ( This )->lpVtbl->LocalizationProbeSelectionDlgShow( This ) )

#define IIMProbe13_LocalizationProbeNameGet( This, pProbeName_ )   \
    ( ( This )->lpVtbl->LocalizationProbeNameGet( This, pProbeName_ ) )

#define IIMProbe13_LocalizationProbeActivate( This, activate_ )    \
    ( ( This )->lpVtbl->LocalizationProbeActivate( This, activate_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */



HRESULT STDMETHODCALLTYPE IIMProbe13_LocalizationProbeNameGet_Proxy(
    IIMProbe13* This,
    BSTR*       pProbeName_ );


void __RPC_STUB IIMProbe13_LocalizationProbeNameGet_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );


HRESULT STDMETHODCALLTYPE IIMProbe13_LocalizationProbeActivate_Proxy(
    IIMProbe13*  This,
    VARIANT_BOOL activate_ );


void __RPC_STUB IIMProbe13_LocalizationProbeActivate_Stub(
    IRpcStubBuffer*    This,
    IRpcChannelBuffer* _pRpcChannelBuffer,
    PRPC_MESSAGE       _pRpcMessage,
    DWORD*             _pdwStubPhase );



#endif  /* __IIMProbe13_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe13_h__
