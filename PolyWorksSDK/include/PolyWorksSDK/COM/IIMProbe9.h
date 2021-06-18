/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:40 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe9.idl:
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

#ifndef __IIMProbe9_h__
#define __IIMProbe9_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe9_FWD_DEFINED__
#define __IIMProbe9_FWD_DEFINED__
typedef interface IIMProbe9 IIMProbe9;
#endif  /* __IIMProbe9_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe8.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe9_INTERFACE_DEFINED__
#define __IIMProbe9_INTERFACE_DEFINED__

/* interface IIMProbe9 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe9;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "B57489D5-28FD-4b0d-B51F-86CA956ADE57" )
IIMProbe9 : public IIMProbe8
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanChangeRealTimePositionSending(
        /* [retval][out] */ VARIANT_BOOL * pCanChangeRealTimePositionSending_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanPowerSearchTarget(
        /* [retval][out] */ VARIANT_BOOL * pCanPowerSearchTarget_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanUseAutomaticTargetRecognition(
        /* [retval][out] */ VARIANT_BOOL * pCanUseAutomaticTargetRecognition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanUseLaserPointer(
        /* [retval][out] */ VARIANT_BOOL * pCanUseLaserPointer_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanUseTargetIllumination(
        /* [retval][out] */ VARIANT_BOOL * pCanUseTargetIllumination_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanUseTargetLock(
        /* [retval][out] */ VARIANT_BOOL * pCanUseTargetLock_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HasManualControlsDlg(
        /* [retval][out] */ VARIANT_BOOL * pHasManualControlsDialog_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ManualControlsDlgShow( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE NextProbingIsSingleDirectionProbing( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SendRealTimePositionsGet(
        /* [retval][out] */ VARIANT_BOOL * pSendRealTimePositions_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SendRealTimePositionsSet(
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PowerSearchTarget( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StatusGet2(
        /* [out] */ BSTR * pDetails_,
        /* [retval][out] */ EDeviceStatus * pStatus_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseAutomaticTargetRecognitionGet(
        /* [retval][out] */ VARIANT_BOOL * pUseAutomaticTargetRecognition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseAutomaticTargetRecognitionSet(
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLaserPointerGet(
        /* [retval][out] */ VARIANT_BOOL * pUseLaserPointer_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLaserPointerSet(
        /* [in] */ VARIANT_BOOL useLaserPointer_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetIlluminationGet(
        /* [retval][out] */ VARIANT_BOOL * pUseTargetIllumination_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetIlluminationSet(
        /* [in] */ VARIANT_BOOL useTargetIllumination_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetLockGet(
        /* [retval][out] */ VARIANT_BOOL * pUseTargetLock_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetLockSet(
        /* [in] */ VARIANT_BOOL useTargetLock_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe9Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe9 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe9 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe9 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe9 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe9 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe9 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe9 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe9 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe9 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe9 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe9 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe9 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe9 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe9 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe9 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe9 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe9 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe9 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe9 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe9 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe9 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe9 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe9 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe9 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe9 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe9 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe9 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe9 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe9 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe9 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe9 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe9 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe9 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe9 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe9 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe9 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe9 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe9 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe9 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe9 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pFindTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetOnGoXYZSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL findTargetOnGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * CanGoFront )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoFront_ );

    HRESULT( STDMETHODCALLTYPE * GoFront )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * HasUserEnvironmentalParameters )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasUserEnvParams_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceGet )(
        IIMProbe9 * This,
        /* [retval][out] */ EEnvironmentalParametersSources* pEnvParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbe9 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * UserTemperatureSet )(
        IIMProbe9 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumidityGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * UserRelativeHumiditySet )(
        IIMProbe9 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * UserAirPressureSet )(
        IIMProbe9 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeFace )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceGet )(
        IIMProbe9 * This,
        /* [retval][out] */ short* pFace_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbe9 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShank )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterGet )(
        IIMProbe9 * This,
        /* [retval][out] */ double* pShankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeRealTimePositionSending )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeRealTimePositionSending_ );

    HRESULT( STDMETHODCALLTYPE * CanPowerSearchTarget )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanPowerSearchTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanUseAutomaticTargetRecognition )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLaserPointer )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetIllumination )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * CanUseTargetLock )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * HasManualControlsDlg )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasManualControlsDialog_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgShow )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsSingleDirectionProbing )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pSendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * PowerSearchTarget )(
        IIMProbe9 * This );

    HRESULT( STDMETHODCALLTYPE * StatusGet2 )(
        IIMProbe9 * This,
        /* [out] */ BSTR* pDetails_,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockGet )(
        IIMProbe9 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbe9 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    END_INTERFACE
} IIMProbe9Vtbl;

interface IIMProbe9
{
    CONST_VTBL struct IIMProbe9Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe9_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe9_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe9_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe9_CanChangeUnits( This, pCanChangeUnits_ ) \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe9_CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe9_CompensationMethodGet( This, pCompensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe9_ConnectionEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe9_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe9_DeviceNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe9_DiameterGet( This, pDiameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe9_HasPropertiesDlg( This, pHasPropertiesDlg_ ) \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe9_MeasurementStart( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe9_MeasurementStop( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe9_ModeGet( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe9_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe9_ModesGetNb( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe9_ModeNameGet( This, modeNb_, pModeName_ )  \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe9_NeedMeasurementButtons( This, pNeedButtons_ )    \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe9_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe9_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe9_PropertiesDlgShow( This )   \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe9_SharedMatrixNameGet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe9_SharedMatrixNameSet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe9_TransformationMatrixGet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe9_TransformationMatrixSet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe9_UnitsGet( This, pUnits_ )    \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe9_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe9_UseAutoViewpointGet( This, pUseAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe9_UseAutoViewpointSet( This, useAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe9_UseDeviceAsMouseGet( This, pUseAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe9_UseDeviceAsMouseSet( This, useAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe9_UseTransformationMatrixGet( This, pUseMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe9_UseTransformationMatrixSet( This, useMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe9_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe9_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe9_CanFindTarget( This, pCanFindTarget_ )   \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe9_CanGoHome( This, pCanGoHome_ )   \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe9_CanGoXYZ( This, pCanGoXYZ_ ) \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe9_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe9_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe9_ContinuousTimeModeTimeGet( This, pTime_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe9_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe9_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe9_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ )  \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe9_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe9_GoHome( This )  \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe9_GoXYZ( This, X_, Y_, Z_ )  \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe9_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe9_GoXYZCoordinatesSet( This, X_, Y_, Z_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe9_NextPointIsCompensationPoint( This )    \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe9_ProbingEnd2( This, probeLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe9_HasTemperature( This, pHasTemperature_ ) \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe9_HasRelativeHumidity( This, pHasHumidity_ )   \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe9_HasAirPressure( This, pHasAirPressure_ ) \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe9_HasStatus( This, pHasStatus_ )   \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe9_TemperatureGet( This, pTemperature_ )    \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe9_RelativeHumidityGet( This, pHumidity_ )  \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe9_AirPressureGet( This, pAirPressure_ )    \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe9_StatusGet( This, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe9_ProbeTypeGet( This, pProbeType_ )    \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe9_ReflectorSet( This, reflectorName_, standardReflectorName_ )  \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe9_ReflectorGet( This, pReflectorName_ )    \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe9_StandardReflectorsGetNb( This, pReflectorNb_ )   \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe9_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )   \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe9_CanChangeCompensationMethod( This, pCanChangeMethod_ )   \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe9_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe9_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe9_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )   \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe9_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe9_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe9_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )    \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe9_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe9_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe9_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe9_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ )  \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe9_ModeTypeGet( This, modeNb_, pModeType_ )  \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe9_NextProbingIsShankProbing( This )   \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe9_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe9_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe9_FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ )    \
    ( ( This )->lpVtbl->FindTargetOnGoXYZGet( This, pFindTargetOnGoXYZ_ ) )

#define IIMProbe9_FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) \
    ( ( This )->lpVtbl->FindTargetOnGoXYZSet( This, findTargetOnGoXYZ_ ) )

#define IIMProbe9_CanGoFront( This, pCanGoFront_ ) \
    ( ( This )->lpVtbl->CanGoFront( This, pCanGoFront_ ) )

#define IIMProbe9_GoFront( This ) \
    ( ( This )->lpVtbl->GoFront( This ) )

#define IIMProbe9_HasUserEnvironmentalParameters( This, pHasUserEnvParams_ )   \
    ( ( This )->lpVtbl->HasUserEnvironmentalParameters( This, pHasUserEnvParams_ ) )

#define IIMProbe9_EnvironmentalParametersSourceGet( This, pEnvParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceGet( This, pEnvParamsSource_ ) )

#define IIMProbe9_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#define IIMProbe9_UserTemperatureGet( This, pTemperature_ )    \
    ( ( This )->lpVtbl->UserTemperatureGet( This, pTemperature_ ) )

#define IIMProbe9_UserTemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->UserTemperatureSet( This, temperature_ ) )

#define IIMProbe9_UserRelativeHumidityGet( This, pHumidity_ )  \
    ( ( This )->lpVtbl->UserRelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe9_UserRelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->UserRelativeHumiditySet( This, humidity_ ) )

#define IIMProbe9_UserAirPressureGet( This, pAirPressure_ )    \
    ( ( This )->lpVtbl->UserAirPressureGet( This, pAirPressure_ ) )

#define IIMProbe9_UserAirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->UserAirPressureSet( This, airPressure_ ) )


#define IIMProbe9_CanChangeFace( This, pCanChangeFace_ )   \
    ( ( This )->lpVtbl->CanChangeFace( This, pCanChangeFace_ ) )

#define IIMProbe9_FaceGet( This, pFace_ )  \
    ( ( This )->lpVtbl->FaceGet( This, pFace_ ) )

#define IIMProbe9_FaceSet( This, face_ )   \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbe9_HasShank( This, pHasShank_ ) \
    ( ( This )->lpVtbl->HasShank( This, pHasShank_ ) )

#define IIMProbe9_ShankDiameterGet( This, pShankDiameterInUnits_ ) \
    ( ( This )->lpVtbl->ShankDiameterGet( This, pShankDiameterInUnits_ ) )


#define IIMProbe9_CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) \
    ( ( This )->lpVtbl->CanChangeRealTimePositionSending( This, pCanChangeRealTimePositionSending_ ) )

#define IIMProbe9_CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) \
    ( ( This )->lpVtbl->CanPowerSearchTarget( This, pCanPowerSearchTarget_ ) )

#define IIMProbe9_CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) \
    ( ( This )->lpVtbl->CanUseAutomaticTargetRecognition( This, pCanUseAutomaticTargetRecognition_ ) )

#define IIMProbe9_CanUseLaserPointer( This, pCanUseLaserPointer_ ) \
    ( ( This )->lpVtbl->CanUseLaserPointer( This, pCanUseLaserPointer_ ) )

#define IIMProbe9_CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) \
    ( ( This )->lpVtbl->CanUseTargetIllumination( This, pCanUseTargetIllumination_ ) )

#define IIMProbe9_CanUseTargetLock( This, pCanUseTargetLock_ ) \
    ( ( This )->lpVtbl->CanUseTargetLock( This, pCanUseTargetLock_ ) )

#define IIMProbe9_HasManualControlsDlg( This, pHasManualControlsDialog_ )  \
    ( ( This )->lpVtbl->HasManualControlsDlg( This, pHasManualControlsDialog_ ) )

#define IIMProbe9_ManualControlsDlgShow( This )   \
    ( ( This )->lpVtbl->ManualControlsDlgShow( This ) )

#define IIMProbe9_NextProbingIsSingleDirectionProbing( This ) \
    ( ( This )->lpVtbl->NextProbingIsSingleDirectionProbing( This ) )

#define IIMProbe9_SendRealTimePositionsGet( This, pSendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsGet( This, pSendRealTimePositions_ ) )

#define IIMProbe9_SendRealTimePositionsSet( This, sendRealTimePositions_ ) \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbe9_PowerSearchTarget( This )   \
    ( ( This )->lpVtbl->PowerSearchTarget( This ) )

#define IIMProbe9_StatusGet2( This, pDetails_, pStatus_ )   \
    ( ( This )->lpVtbl->StatusGet2( This, pDetails_, pStatus_ ) )

#define IIMProbe9_UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionGet( This, pUseAutomaticTargetRecognition_ ) )

#define IIMProbe9_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbe9_UseLaserPointerGet( This, pUseLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerGet( This, pUseLaserPointer_ ) )

#define IIMProbe9_UseLaserPointerSet( This, useLaserPointer_ ) \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbe9_UseTargetIlluminationGet( This, pUseTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationGet( This, pUseTargetIllumination_ ) )

#define IIMProbe9_UseTargetIlluminationSet( This, useTargetIllumination_ ) \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbe9_UseTargetLockGet( This, pUseTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockGet( This, pUseTargetLock_ ) )

#define IIMProbe9_UseTargetLockSet( This, useTargetLock_ ) \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe9_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe9_h__
