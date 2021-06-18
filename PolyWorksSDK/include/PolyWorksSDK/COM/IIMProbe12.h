/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Sep 11 11:18:59 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe12.idl:
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

#ifndef __IIMProbe12_h__
#define __IIMProbe12_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe12_FWD_DEFINED__
#define __IIMProbe12_FWD_DEFINED__
typedef interface IIMProbe12 IIMProbe12;
#endif  /* __IIMProbe12_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe11.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe12_INTERFACE_DEFINED__
#define __IIMProbe12_INTERFACE_DEFINED__

/* interface IIMProbe12 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe12;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "83CA3FF7-5B2A-4348-9082-693990BCDC14" )
IIMProbe12 : public IIMProbe11
{
public:
    virtual HRESULT STDMETHODCALLTYPE IsCompensationMethodSupported(
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL * pIsSupported_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe12Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe12 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe12 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe12 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe12 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe12 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe12 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe12 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe12 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe12 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe12 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe12 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe12 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe12 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe12 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe12 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe12 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe12 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe12 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe12 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe12 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe12 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe12 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe12 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe12 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe12 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe12 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe12 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe12 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe12 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe12 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe12 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe12 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe12 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe12 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe12 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe12 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe12 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe12 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe12 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe12 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe12 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe12 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe12 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe12 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe12 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe12 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe12 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe12 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe12 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousMeasuringResumingOnTargetRecovery )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoveryGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pResumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * ResumeContinuousMeasuringOnTargetRecoverySet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL resumeMeasuring_ );

    HRESULT( STDMETHODCALLTYPE * HasMotorActivationState )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CanDeactivateMotors )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanDeactivateMotors_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateGet )(
        IIMProbe12 * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbe12 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClose )(
        IIMProbe12 * This );

    HRESULT( STDMETHODCALLTYPE * IsCompensationMethodSupported )(
        IIMProbe12 * This,
        /* [in] */ ECompensationMethods compensationMethod_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    END_INTERFACE
} IIMProbe12Vtbl;

interface IIMProbe12
{
    CONST_VTBL struct IIMProbe12Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe12_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe12_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe12_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe12_CanChangeUnits( This, pCanChangeUnits_ )    \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe12_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )    \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe12_CompensationMethodGet( This, pCompensationMethod_ ) \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe12_ConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe12_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe12_DeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe12_DiameterGet( This, pDiameterInUnits_ )  \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe12_HasPropertiesDlg( This, pHasPropertiesDlg_ )    \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe12_MeasurementStart( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe12_MeasurementStop( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe12_ModeGet( This, pModeNb_ )   \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe12_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe12_ModesGetNb( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe12_ModeNameGet( This, modeNb_, pModeName_ ) \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe12_NeedMeasurementButtons( This, pNeedButtons_ )   \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe12_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe12_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )   \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe12_PropertiesDlgShow( This )  \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe12_SharedMatrixNameGet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe12_SharedMatrixNameSet( This, pSharedMatrixName_ ) \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe12_TransformationMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe12_TransformationMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe12_UnitsGet( This, pUnits_ )   \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe12_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe12_UseAutoViewpointGet( This, pUseAutoViewpoint_ ) \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe12_UseAutoViewpointSet( This, useAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe12_UseDeviceAsMouseGet( This, pUseAsMouse_ )   \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe12_UseDeviceAsMouseSet( This, useAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe12_UseTransformationMatrixGet( This, pUseMatrix_ ) \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe12_UseTransformationMatrixSet( This, useMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe12_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe12_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe12_CanFindTarget( This, pCanFindTarget_ )  \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe12_CanGoHome( This, pCanGoHome_ )  \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe12_CanGoXYZ( This, pCanGoXYZ_ )    \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe12_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ )    \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe12_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe12_ContinuousTimeModeTimeGet( This, pTime_ )   \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe12_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe12_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe12_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe12_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )   \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe12_GoHome( This ) \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe12_GoXYZ( This, X_, Y_, Z_ ) \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe12_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe12_GoXYZCoordinatesSet( This, X_, Y_, Z_ )   \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe12_NextPointIsCompensationPoint( This )   \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe12_ProbingEnd2( This, probeLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe12_HasTemperature( This, pHasTemperature_ )    \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe12_HasRelativeHumidity( This, pHasHumidity_ )  \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe12_HasAirPressure( This, pHasAirPressure_ )    \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe12_HasStatus( This, pHasStatus_ )  \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe12_TemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe12_RelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe12_AirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe12_StatusGet( This, pStatus_ ) \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe12_ProbeTypeGet( This, pProbeType_ )   \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe12_ReflectorSet( This, reflectorName_, standardReflectorName_ ) \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe12_ReflectorGet( This, pReflectorName_ )   \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe12_StandardReflectorsGetNb( This, pReflectorNb_ )  \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe12_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )  \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe12_CanChangeCompensationMethod( This, pCanChangeMethod_ )  \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe12_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe12_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe12_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe12_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe12_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe12_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )   \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe12_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )   \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe12_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe12_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe12_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe12_ModeTypeGet( This, modeNb_, pModeType_ ) \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe12_NextProbingIsShankProbing( This )  \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe12_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe12_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe12_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )   \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe12_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe12_CanGoFront( This, pCanGoFront_ )    \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe12_GoFront( This )    \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe12_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )  \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe12_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe12_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe12_UserTemperatureGet( This, pTemperature_ )   \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe12_UserTemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe12_UserRelativeHumidityGet( This, pHumidity_ ) \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe12_UserRelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe12_UserAirPressureGet( This, pAirPressure_ )   \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe12_UserAirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe12_CanChangeFace( This, pCanChangeFace_ )  \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe12_FaceGet( This, pFace_ ) \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe12_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe12_HasShank( This, pHasShank_ )    \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe12_ShankDiameterGet( This, pShankDiameterInUnits_ )    \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe12_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ )    \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe12_CanPowerSearchTarget( This, pCanPowerSearchTarget_ )    \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe12_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe12_CanUseLaserPointer( This, pCanUseLaserPointer_ )    \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe12_CanUseTargetIllumination( This, pCanUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe12_CanUseTargetLock( This, pCanUseTargetLock_ )    \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe12_HasManualControlsDlg( This, pHasManualControlsDialog_ ) \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe12_ManualControlsDlgShow( This )  \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe12_NextProbingIsSingleDirectionProbing( This )    \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe12_SendRealTimePositionsGet( This, pSendRealTimePositions_ )   \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe12_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe12_PowerSearchTarget( This )  \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe12_StatusGet2( This, pDetails_, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe12_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )   \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe12_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe12_UseLaserPointerGet( This, pUseLaserPointer_ )   \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe12_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe12_UseTargetIlluminationGet( This, pUseTargetIllumination_ )   \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe12_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe12_UseTargetLockGet( This, pUseTargetLock_ )   \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe12_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbe12_CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ )    \
    ( ( This )->lpVtbl->CanChangeContinuousMeasuringResumingOnTargetRecovery( This, pCanChangeResumeMeasuring_ ) )

#define IIMProbe12_ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoveryGet( This, pResumeMeasuring_ ) )

#define IIMProbe12_ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ )  \
    ( ( This )->lpVtbl->ResumeContinuousMeasuringOnTargetRecoverySet( This, resumeMeasuring_ ) )


#define IIMProbe12_HasMotorActivationState( This, pHasActivationState_ )   \
    ( ( This )->lpVtbl->HasMotorActivationState( This, pHasActivationState_ ) )

#define IIMProbe12_CanDeactivateMotors( This, pCanDeactivateMotors_ )  \
    ( ( This )->lpVtbl->CanDeactivateMotors( This, pCanDeactivateMotors_ ) )

#define IIMProbe12_MotorActivationStateGet( This, pActivationState_ )  \
    ( ( This )->lpVtbl->MotorActivationStateGet( This, pActivationState_ ) )

#define IIMProbe12_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbe12_ManualControlsDlgClose( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClose( This ) )


#define IIMProbe12_IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ )    \
    ( ( This )->lpVtbl->IsCompensationMethodSupported( This, compensationMethod_, pIsSupported_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe12_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe12_h__
