/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:46:51 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe5.idl:
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

#ifndef __IIMProbe5_h__
#define __IIMProbe5_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe5_FWD_DEFINED__
#define __IIMProbe5_FWD_DEFINED__
typedef interface IIMProbe5 IIMProbe5;
#endif  /* __IIMProbe5_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbe.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe5_INTERFACE_DEFINED__
#define __IIMProbe5_INTERFACE_DEFINED__

/* interface IIMProbe5 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe5;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "E9E97AEC-1F8A-4f4e-B85B-828315F6C374" )
IIMProbe5 : public IIMProbe4
{
public:
    virtual HRESULT STDMETHODCALLTYPE GoXYZ2(
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementAutomaticTriggerStabilityDelayGet(
        /* [retval][out] */ long* pDelay_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementAutomaticTriggerStabilityDelaySet(
        /* [in] */ long delay_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementAutomaticTriggerStabilityToleranceGet(
        /* [retval][out] */ double* pToleranceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementAutomaticTriggerStabilityToleranceSet(
        /* [in] */ double toleranceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModeTypeGet(
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes * pModeType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE NextProbingIsShankProbing( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseMeasurementAutomaticTriggerGet(
        /* [retval][out] */ VARIANT_BOOL * pUseAutomaticTrigger_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseMeasurementAutomaticTriggerSet(
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe5Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe5 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe5 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe5 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe5 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe5 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe5 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe5 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe5 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe5 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe5 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe5 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe5 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe5 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe5 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe5 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe5 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe5 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe5 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe5 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe5 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe5 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe5 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe5 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe5 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe5 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe5 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe5 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe5 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe5 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe5 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe5 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe5 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe5 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe5 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe5 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZ2 )(
        IIMProbe5 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_,
        /* [in] */ VARIANT_BOOL searchForTarget_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelayGet )(
        IIMProbe5 * This,
        /* [retval][out] */ long* pDelay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityDelaySet )(
        IIMProbe5 * This,
        /* [in] */ long delay_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceGet )(
        IIMProbe5 * This,
        /* [retval][out] */ double* pToleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementAutomaticTriggerStabilityToleranceSet )(
        IIMProbe5 * This,
        /* [in] */ double toleranceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ModeTypeGet )(
        IIMProbe5 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ EProbingModeTypes* pModeType_ );

    HRESULT( STDMETHODCALLTYPE * NextProbingIsShankProbing )(
        IIMProbe5 * This );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerGet )(
        IIMProbe5 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseMeasurementAutomaticTriggerSet )(
        IIMProbe5 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    END_INTERFACE
} IIMProbe5Vtbl;

interface IIMProbe5
{
    CONST_VTBL struct IIMProbe5Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe5_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe5_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe5_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe5_CanChangeUnits( This, pCanChangeUnits_ ) \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe5_CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe5_CompensationMethodGet( This, pCompensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe5_ConnectionEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe5_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe5_DeviceNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe5_DiameterGet( This, pDiameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe5_HasPropertiesDlg( This, pHasPropertiesDlg_ ) \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe5_MeasurementStart( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe5_MeasurementStop( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe5_ModeGet( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe5_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe5_ModesGetNb( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe5_ModeNameGet( This, modeNb_, pModeName_ )  \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe5_NeedMeasurementButtons( This, pNeedButtons_ )    \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe5_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe5_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe5_PropertiesDlgShow( This )   \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe5_SharedMatrixNameGet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe5_SharedMatrixNameSet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe5_TransformationMatrixGet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe5_TransformationMatrixSet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe5_UnitsGet( This, pUnits_ )    \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe5_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe5_UseAutoViewpointGet( This, pUseAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe5_UseAutoViewpointSet( This, useAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe5_UseDeviceAsMouseGet( This, pUseAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe5_UseDeviceAsMouseSet( This, useAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe5_UseTransformationMatrixGet( This, pUseMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe5_UseTransformationMatrixSet( This, useMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe5_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe5_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe5_CanFindTarget( This, pCanFindTarget_ )   \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe5_CanGoHome( This, pCanGoHome_ )   \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe5_CanGoXYZ( This, pCanGoXYZ_ ) \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe5_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe5_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe5_ContinuousTimeModeTimeGet( This, pTime_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe5_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe5_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe5_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ )  \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe5_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe5_GoHome( This )  \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe5_GoXYZ( This, X_, Y_, Z_ )  \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe5_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe5_GoXYZCoordinatesSet( This, X_, Y_, Z_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe5_NextPointIsCompensationPoint( This )    \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe5_ProbingEnd2( This, probeLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe5_HasTemperature( This, pHasTemperature_ ) \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe5_HasRelativeHumidity( This, pHasHumidity_ )   \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe5_HasAirPressure( This, pHasAirPressure_ ) \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe5_HasStatus( This, pHasStatus_ )   \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe5_TemperatureGet( This, pTemperature_ )    \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe5_RelativeHumidityGet( This, pHumidity_ )  \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe5_AirPressureGet( This, pAirPressure_ )    \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe5_StatusGet( This, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe5_ProbeTypeGet( This, pProbeType_ )    \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe5_ReflectorSet( This, reflectorName_, standardReflectorName_ )  \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe5_ReflectorGet( This, pReflectorName_ )    \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe5_StandardReflectorsGetNb( This, pReflectorNb_ )   \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe5_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )   \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe5_CanChangeCompensationMethod( This, pCanChangeMethod_ )   \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe5_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe5_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe5_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )   \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe5_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe5_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )


#define IIMProbe5_GoXYZ2( This, X_, Y_, Z_, searchForTarget_ )    \
    ( ( This )->lpVtbl->GoXYZ2( This, X_, Y_, Z_, searchForTarget_ ) )

#define IIMProbe5_MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ )    \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelayGet( This, pDelay_ ) )

#define IIMProbe5_MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityDelaySet( This, delay_ ) )

#define IIMProbe5_MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceGet( This, pToleranceInUnits_ ) )

#define IIMProbe5_MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ )  \
    ( ( This )->lpVtbl->MeasurementAutomaticTriggerStabilityToleranceSet( This, toleranceInUnits_ ) )

#define IIMProbe5_ModeTypeGet( This, modeNb_, pModeType_ )  \
    ( ( This )->lpVtbl->ModeTypeGet( This, modeNb_, pModeType_ ) )

#define IIMProbe5_NextProbingIsShankProbing( This )   \
    ( ( This )->lpVtbl->NextProbingIsShankProbing( This ) )

#define IIMProbe5_UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe5_UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ )  \
    ( ( This )->lpVtbl->UseMeasurementAutomaticTriggerSet( This, useAutomaticTrigger_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe5_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe5_h__
