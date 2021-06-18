/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:48 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe.idl:
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

#ifndef __IIMProbe_h__
#define __IIMProbe_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbe_FWD_DEFINED__
#define __IIMProbe_FWD_DEFINED__
typedef interface IIMProbe IIMProbe;
#endif  /* __IIMProbe_FWD_DEFINED__ */


#ifndef __IIMProbe2_FWD_DEFINED__
#define __IIMProbe2_FWD_DEFINED__
typedef interface IIMProbe2 IIMProbe2;
#endif  /* __IIMProbe2_FWD_DEFINED__ */


#ifndef __IIMProbe3_FWD_DEFINED__
#define __IIMProbe3_FWD_DEFINED__
typedef interface IIMProbe3 IIMProbe3;
#endif  /* __IIMProbe3_FWD_DEFINED__ */


#ifndef __IIMProbe4_FWD_DEFINED__
#define __IIMProbe4_FWD_DEFINED__
typedef interface IIMProbe4 IIMProbe4;
#endif  /* __IIMProbe4_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMPointCloud.h"
#include "IIMProbeFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbe_INTERFACE_DEFINED__
#define __IIMProbe_INTERFACE_DEFINED__

/* interface IIMProbe */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "d31aade0-0a1d-11d8-93da-00b0d0224d3a" )
IIMProbe : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanChangeUnits(
        /* [retval][out] */ VARIANT_BOOL * pCanChangeUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanUseDeviceAsMouse(
        /* [retval][out] */ VARIANT_BOOL * pCanUseAsMouse_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CompensationMethodGet(
        /* [retval][out] */ ECompensationMethods * pCompensationMethod_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ConnectionEnd(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ConnectionInit(
        /* [in] */ IIMProbeFeedback * pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DeviceNameGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DiameterGet(
        /* [retval][out] */ double* pDiameterInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HasPropertiesDlg(
        /* [retval][out] */ VARIANT_BOOL * pHasPropertiesDlg_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementStart(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeasurementStop(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModeGet(
        /* [retval][out] */ short* pModeNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModeSet(
        /* [in] */ short modeNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModesGetNb(
        /* [retval][out] */ short* pModeNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ModeNameGet(
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR * pModeName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE NeedMeasurementButtons(
        /* [retval][out] */ VARIANT_BOOL * pNeedButtons_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProbingEnd( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProbingStart(
        /* [in] */ IIMPointCloud * pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PropertiesDlgShow( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixNameGet(
        /* [retval][out] */ BSTR * pSharedMatrixName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixNameSet(
        /* [in] */ BSTR pSharedMatrixName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransformationMatrixGet(
        /* [out][in] */ SAFEARRAY * *pTransMat_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransformationMatrixSet(
        /* [in] */ SAFEARRAY * *pTransMat_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnitsGet(
        /* [retval][out] */ double* pUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnitsSet(
        /* [in] */ double units_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseAutoViewpointGet(
        /* [retval][out] */ VARIANT_BOOL * pUseAutoViewpoint_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseAutoViewpointSet(
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseDeviceAsMouseGet(
        /* [retval][out] */ VARIANT_BOOL * pUseAsMouse_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseDeviceAsMouseSet(
        /* [in] */ VARIANT_BOOL useAsMouse_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTransformationMatrixGet(
        /* [retval][out] */ VARIANT_BOOL * pUseMatrix_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTransformationMatrixSet(
        /* [in] */ VARIANT_BOOL useMatrix_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    END_INTERFACE
} IIMProbeVtbl;

interface IIMProbe
{
    CONST_VTBL struct IIMProbeVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe_CanChangeUnits( This, pCanChangeUnits_ )  \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe_CanUseDeviceAsMouse( This, pCanUseAsMouse_ )  \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe_CompensationMethodGet( This, pCompensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe_ConnectionEnd( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )    \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe_DeviceNameGet( This, pName_ ) \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe_DiameterGet( This, pDiameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe_HasPropertiesDlg( This, pHasPropertiesDlg_ )  \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe_MeasurementStart( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe_MeasurementStop( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe_ModeGet( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe_ModeSet( This, modeNb_ )  \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe_ModesGetNb( This, pModeNb_ )  \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe_ModeNameGet( This, modeNb_, pModeName_ )   \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe_NeedMeasurementButtons( This, pNeedButtons_ ) \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe_ProbingEnd( This )   \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe_PropertiesDlgShow( This )    \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe_SharedMatrixNameGet( This, pSharedMatrixName_ )   \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe_SharedMatrixNameSet( This, pSharedMatrixName_ )   \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe_TransformationMatrixGet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe_TransformationMatrixSet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe_UnitsGet( This, pUnits_ ) \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe_UnitsSet( This, units_ )  \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe_UseAutoViewpointGet( This, pUseAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe_UseAutoViewpointSet( This, useAutoViewpoint_ )    \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe_UseDeviceAsMouseGet( This, pUseAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe_UseDeviceAsMouseSet( This, useAsMouse_ )  \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe_UseTransformationMatrixGet( This, pUseMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe_UseTransformationMatrixSet( This, useMatrix_ )    \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe_INTERFACE_DEFINED__ */


#ifndef __IIMProbe2_INTERFACE_DEFINED__
#define __IIMProbe2_INTERFACE_DEFINED__

/* interface IIMProbe2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "4DA18293-F6F4-42c4-8B32-07C5B940B875" )
IIMProbe2 : public IIMProbe
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanChangeContinuousDistanceModeDistance(
        /* [retval][out] */ VARIANT_BOOL * pCanChangeDistance_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanChangeContinuousTimeModeTime(
        /* [retval][out] */ VARIANT_BOOL * pCanChangeTime_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanFindTarget(
        /* [retval][out] */ VARIANT_BOOL * pCanFindTarget_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanGoHome(
        /* [retval][out] */ VARIANT_BOOL * pCanGoHome_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanGoXYZ(
        /* [retval][out] */ VARIANT_BOOL * pCanGoXYZ_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ContinuousDistanceModeDistanceGet(
        /* [retval][out] */ double* pDistanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ContinuousDistanceModeDistanceSet(
        /* [in] */ double distanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ContinuousTimeModeTimeGet(
        /* [retval][out] */ long* pTime_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ContinuousTimeModeTimeSet(
        /* [in] */ long time_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE FindTarget(
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE FindTargetParametersGet(
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE FindTargetParametersSet(
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GoHome( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GoXYZ(
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GoXYZCoordinatesGet(
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GoXYZCoordinatesSet(
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE NextPointIsCompensationPoint( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProbingEnd2(
        /* [in] */ VARIANT_BOOL probeLastPoint_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe2 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe2 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe2 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe2 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe2 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe2 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe2 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe2 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe2 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe2 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe2 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe2 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe2 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe2 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe2 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe2 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe2 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe2 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe2 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe2 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe2 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe2 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe2 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe2 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe2 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe2 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe2 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe2 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe2 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe2 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe2 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe2 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe2 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe2 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    END_INTERFACE
} IIMProbe2Vtbl;

interface IIMProbe2
{
    CONST_VTBL struct IIMProbe2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe2_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe2_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe2_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe2_CanChangeUnits( This, pCanChangeUnits_ ) \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe2_CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe2_CompensationMethodGet( This, pCompensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe2_ConnectionEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe2_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe2_DeviceNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe2_DiameterGet( This, pDiameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe2_HasPropertiesDlg( This, pHasPropertiesDlg_ ) \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe2_MeasurementStart( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe2_MeasurementStop( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe2_ModeGet( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe2_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe2_ModesGetNb( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe2_ModeNameGet( This, modeNb_, pModeName_ )  \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe2_NeedMeasurementButtons( This, pNeedButtons_ )    \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe2_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe2_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe2_PropertiesDlgShow( This )   \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe2_SharedMatrixNameGet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe2_SharedMatrixNameSet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe2_TransformationMatrixGet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe2_TransformationMatrixSet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe2_UnitsGet( This, pUnits_ )    \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe2_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe2_UseAutoViewpointGet( This, pUseAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe2_UseAutoViewpointSet( This, useAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe2_UseDeviceAsMouseGet( This, pUseAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe2_UseDeviceAsMouseSet( This, useAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe2_UseTransformationMatrixGet( This, pUseMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe2_UseTransformationMatrixSet( This, useMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe2_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe2_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe2_CanFindTarget( This, pCanFindTarget_ )   \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe2_CanGoHome( This, pCanGoHome_ )   \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe2_CanGoXYZ( This, pCanGoXYZ_ ) \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe2_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe2_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe2_ContinuousTimeModeTimeGet( This, pTime_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe2_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe2_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe2_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ )  \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe2_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe2_GoHome( This )  \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe2_GoXYZ( This, X_, Y_, Z_ )  \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe2_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe2_GoXYZCoordinatesSet( This, X_, Y_, Z_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe2_NextPointIsCompensationPoint( This )    \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe2_ProbingEnd2( This, probeLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe2_INTERFACE_DEFINED__ */


#ifndef __IIMProbe3_INTERFACE_DEFINED__
#define __IIMProbe3_INTERFACE_DEFINED__

/* interface IIMProbe3 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe3;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "661CC020-C3FD-42f8-A015-E4C3E8409859" )
IIMProbe3 : public IIMProbe2
{
public:
    virtual HRESULT STDMETHODCALLTYPE HasTemperature(
        /* [retval][out] */ VARIANT_BOOL * pHasTemperature_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HasRelativeHumidity(
        /* [retval][out] */ VARIANT_BOOL * pHasHumidity_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HasAirPressure(
        /* [retval][out] */ VARIANT_BOOL * pHasAirPressure_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HasStatus(
        /* [retval][out] */ VARIANT_BOOL * pHasStatus_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TemperatureGet(
        /* [retval][out] */ double* pTemperature_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE RelativeHumidityGet(
        /* [retval][out] */ double* pHumidity_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE AirPressureGet(
        /* [retval][out] */ double* pAirPressure_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StatusGet(
        /* [retval][out] */ EDeviceStatus * pStatus_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProbeTypeGet(
        /* [retval][out] */ EProbeTypes * pProbeType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReflectorSet(
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ = L"" ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReflectorGet(
        /* [retval][out] */ BSTR * pReflectorName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardReflectorsGetNb(
        /* [retval][out] */ short* pReflectorNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardReflectorInfoGet(
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR * pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe3Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe3 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe3 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe3 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe3 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe3 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe3 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe3 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe3 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe3 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe3 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe3 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe3 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe3 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe3 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe3 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe3 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe3 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe3 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe3 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe3 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe3 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe3 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe3 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe3 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe3 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe3 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe3 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe3 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe3 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe3 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe3 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe3 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe3 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe3 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe3 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe3 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe3 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe3 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe3 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe3 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe3 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe3 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe3 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe3 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    END_INTERFACE
} IIMProbe3Vtbl;

interface IIMProbe3
{
    CONST_VTBL struct IIMProbe3Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe3_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe3_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe3_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe3_CanChangeUnits( This, pCanChangeUnits_ ) \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe3_CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe3_CompensationMethodGet( This, pCompensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe3_ConnectionEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe3_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe3_DeviceNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe3_DiameterGet( This, pDiameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe3_HasPropertiesDlg( This, pHasPropertiesDlg_ ) \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe3_MeasurementStart( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe3_MeasurementStop( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe3_ModeGet( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe3_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe3_ModesGetNb( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe3_ModeNameGet( This, modeNb_, pModeName_ )  \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe3_NeedMeasurementButtons( This, pNeedButtons_ )    \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe3_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe3_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe3_PropertiesDlgShow( This )   \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe3_SharedMatrixNameGet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe3_SharedMatrixNameSet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe3_TransformationMatrixGet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe3_TransformationMatrixSet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe3_UnitsGet( This, pUnits_ )    \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe3_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe3_UseAutoViewpointGet( This, pUseAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe3_UseAutoViewpointSet( This, useAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe3_UseDeviceAsMouseGet( This, pUseAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe3_UseDeviceAsMouseSet( This, useAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe3_UseTransformationMatrixGet( This, pUseMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe3_UseTransformationMatrixSet( This, useMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe3_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe3_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe3_CanFindTarget( This, pCanFindTarget_ )   \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe3_CanGoHome( This, pCanGoHome_ )   \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe3_CanGoXYZ( This, pCanGoXYZ_ ) \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe3_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe3_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe3_ContinuousTimeModeTimeGet( This, pTime_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe3_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe3_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe3_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ )  \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe3_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe3_GoHome( This )  \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe3_GoXYZ( This, X_, Y_, Z_ )  \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe3_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe3_GoXYZCoordinatesSet( This, X_, Y_, Z_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe3_NextPointIsCompensationPoint( This )    \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe3_ProbingEnd2( This, probeLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe3_HasTemperature( This, pHasTemperature_ ) \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe3_HasRelativeHumidity( This, pHasHumidity_ )   \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe3_HasAirPressure( This, pHasAirPressure_ ) \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe3_HasStatus( This, pHasStatus_ )   \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe3_TemperatureGet( This, pTemperature_ )    \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe3_RelativeHumidityGet( This, pHumidity_ )  \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe3_AirPressureGet( This, pAirPressure_ )    \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe3_StatusGet( This, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe3_ProbeTypeGet( This, pProbeType_ )    \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe3_ReflectorSet( This, reflectorName_, standardReflectorName_ )  \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe3_ReflectorGet( This, pReflectorName_ )    \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe3_StandardReflectorsGetNb( This, pReflectorNb_ )   \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe3_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )   \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe3_INTERFACE_DEFINED__ */


#ifndef __IIMProbe4_INTERFACE_DEFINED__
#define __IIMProbe4_INTERFACE_DEFINED__

/* interface IIMProbe4 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbe4;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "9A9CF135-F297-4590-9D5C-7787938AE49E" )
IIMProbe4 : public IIMProbe3
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanChangeCompensationMethod(
        /* [retval][out] */ VARIANT_BOOL * pCanChangeMethod_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CompensationMethodSet(
        /* [in] */ ECompensationMethods compensationMethod_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CompensationPointAutomaticTriggerDistanceGet(
        /* [retval][out] */ double* pDistanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CompensationPointAutomaticTriggerDistanceSet(
        /* [in] */ double distanceInUnits_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseCompensationPointAutomaticTriggerGet(
        /* [retval][out] */ VARIANT_BOOL * pUseAutomaticTrigger_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseCompensationPointAutomaticTriggerSet(
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbe4Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbe4 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbe4 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbe4 * This );

    HRESULT( STDMETHODCALLTYPE * CanChangeUnits )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanUseDeviceAsMouse )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodGet )(
        IIMProbe4 * This,
        /* [retval][out] */ ECompensationMethods* pCompensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbe4 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConnectionInit )(
        IIMProbe4 * This,
        /* [in] */ IIMProbeFeedback* pIIMProbeFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * DeviceNameGet )(
        IIMProbe4 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * DiameterGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * HasPropertiesDlg )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasPropertiesDlg_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbe4 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbe4 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ModeGet )(
        IIMProbe4 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbe4 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModesGetNb )(
        IIMProbe4 * This,
        /* [retval][out] */ short* pModeNb_ );

    HRESULT( STDMETHODCALLTYPE * ModeNameGet )(
        IIMProbe4 * This,
        /* [in] */ short modeNb_,
        /* [retval][out] */ BSTR* pModeName_ );

    HRESULT( STDMETHODCALLTYPE * NeedMeasurementButtons )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pNeedButtons_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbe4 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingStart )(
        IIMProbe4 * This,
        /* [in] */ IIMPointCloud* pIIMPtCloud_,
        /* [defaultvalue][in] */ VARIANT_BOOL sendLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * PropertiesDlgShow )(
        IIMProbe4 * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameGet )(
        IIMProbe4 * This,
        /* [retval][out] */ BSTR* pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixNameSet )(
        IIMProbe4 * This,
        /* [in] */ BSTR pSharedMatrixName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMProbe4 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMProbe4 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * UnitsGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pUnits_ );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbe4 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointGet )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseAutoViewpointSet )(
        IIMProbe4 * This,
        /* [in] */ VARIANT_BOOL useAutoViewpoint_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseGet )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseDeviceAsMouseSet )(
        IIMProbe4 * This,
        /* [in] */ VARIANT_BOOL useAsMouse_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixGet )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseMatrix_ );

    HRESULT( STDMETHODCALLTYPE * UseTransformationMatrixSet )(
        IIMProbe4 * This,
        /* [in] */ VARIANT_BOOL useMatrix_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousDistanceModeDistance )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeDistance_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeContinuousTimeModeTime )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeTime_ );

    HRESULT( STDMETHODCALLTYPE * CanFindTarget )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanFindTarget_ );

    HRESULT( STDMETHODCALLTYPE * CanGoHome )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoHome_ );

    HRESULT( STDMETHODCALLTYPE * CanGoXYZ )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanGoXYZ_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbe4 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeGet )(
        IIMProbe4 * This,
        /* [retval][out] */ long* pTime_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbe4 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * FindTarget )(
        IIMProbe4 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersGet )(
        IIMProbe4 * This,
        /* [out] */ double* pSearchRadiusInUnits_,
        /* [out] */ double* pApproximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * FindTargetParametersSet )(
        IIMProbe4 * This,
        /* [in] */ double searchRadiusInUnits_,
        /* [in] */ double approximateDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * GoHome )(
        IIMProbe4 * This );

    HRESULT( STDMETHODCALLTYPE * GoXYZ )(
        IIMProbe4 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesGet )(
        IIMProbe4 * This,
        /* [out] */ double* pX_,
        /* [out] */ double* pY_,
        /* [out] */ double* pZ_ );

    HRESULT( STDMETHODCALLTYPE * GoXYZCoordinatesSet )(
        IIMProbe4 * This,
        /* [in] */ double X_,
        /* [in] */ double Y_,
        /* [in] */ double Z_ );

    HRESULT( STDMETHODCALLTYPE * NextPointIsCompensationPoint )(
        IIMProbe4 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd2 )(
        IIMProbe4 * This,
        /* [in] */ VARIANT_BOOL probeLastPoint_ );

    HRESULT( STDMETHODCALLTYPE * HasTemperature )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasTemperature_ );

    HRESULT( STDMETHODCALLTYPE * HasRelativeHumidity )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasHumidity_ );

    HRESULT( STDMETHODCALLTYPE * HasAirPressure )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * HasStatus )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pHasStatus_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pTemperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumidityGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pHumidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pAirPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusGet )(
        IIMProbe4 * This,
        /* [retval][out] */ EDeviceStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeGet )(
        IIMProbe4 * This,
        /* [retval][out] */ EProbeTypes* pProbeType_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorSet )(
        IIMProbe4 * This,
        /* [in] */ BSTR reflectorName_,
        /* [defaultvalue][in] */ BSTR standardReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * ReflectorGet )(
        IIMProbe4 * This,
        /* [retval][out] */ BSTR* pReflectorName_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorsGetNb )(
        IIMProbe4 * This,
        /* [retval][out] */ short* pReflectorNb_ );

    HRESULT( STDMETHODCALLTYPE * StandardReflectorInfoGet )(
        IIMProbe4 * This,
        /* [in] */ short reflectorIndex_,
        /* [out] */ BSTR* pReflectorName_,
        /* [out] */ double* pReflectorOffsetInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CanChangeCompensationMethod )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanChangeMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbe4 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceGet )(
        IIMProbe4 * This,
        /* [retval][out] */ double* pDistanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CompensationPointAutomaticTriggerDistanceSet )(
        IIMProbe4 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerGet )(
        IIMProbe4 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseAutomaticTrigger_ );

    HRESULT( STDMETHODCALLTYPE * UseCompensationPointAutomaticTriggerSet )(
        IIMProbe4 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTrigger_ );

    END_INTERFACE
} IIMProbe4Vtbl;

interface IIMProbe4
{
    CONST_VTBL struct IIMProbe4Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbe4_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbe4_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbe4_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbe4_CanChangeUnits( This, pCanChangeUnits_ ) \
    ( ( This )->lpVtbl->CanChangeUnits( This, pCanChangeUnits_ ) )

#define IIMProbe4_CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) \
    ( ( This )->lpVtbl->CanUseDeviceAsMouse( This, pCanUseAsMouse_ ) )

#define IIMProbe4_CompensationMethodGet( This, pCompensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodGet( This, pCompensationMethod_ ) )

#define IIMProbe4_ConnectionEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionEnd( This, pReturnVal_ ) )

#define IIMProbe4_ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ConnectionInit( This, pIIMProbeFeedback_, pReturnVal_ ) )

#define IIMProbe4_DeviceNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->DeviceNameGet( This, pName_ ) )

#define IIMProbe4_DiameterGet( This, pDiameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterGet( This, pDiameterInUnits_ ) )

#define IIMProbe4_HasPropertiesDlg( This, pHasPropertiesDlg_ ) \
    ( ( This )->lpVtbl->HasPropertiesDlg( This, pHasPropertiesDlg_ ) )

#define IIMProbe4_MeasurementStart( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->MeasurementStart( This, pReturnVal_ ) )

#define IIMProbe4_MeasurementStop( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->MeasurementStop( This, pReturnVal_ ) )

#define IIMProbe4_ModeGet( This, pModeNb_ )    \
    ( ( This )->lpVtbl->ModeGet( This, pModeNb_ ) )

#define IIMProbe4_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbe4_ModesGetNb( This, pModeNb_ ) \
    ( ( This )->lpVtbl->ModesGetNb( This, pModeNb_ ) )

#define IIMProbe4_ModeNameGet( This, modeNb_, pModeName_ )  \
    ( ( This )->lpVtbl->ModeNameGet( This, modeNb_, pModeName_ ) )

#define IIMProbe4_NeedMeasurementButtons( This, pNeedButtons_ )    \
    ( ( This )->lpVtbl->NeedMeasurementButtons( This, pNeedButtons_ ) )

#define IIMProbe4_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbe4_ProbingStart( This, pIIMPtCloud_, sendLastPoint_ )    \
    ( ( This )->lpVtbl->ProbingStart( This, pIIMPtCloud_, sendLastPoint_ ) )

#define IIMProbe4_PropertiesDlgShow( This )   \
    ( ( This )->lpVtbl->PropertiesDlgShow( This ) )

#define IIMProbe4_SharedMatrixNameGet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameGet( This, pSharedMatrixName_ ) )

#define IIMProbe4_SharedMatrixNameSet( This, pSharedMatrixName_ )  \
    ( ( This )->lpVtbl->SharedMatrixNameSet( This, pSharedMatrixName_ ) )

#define IIMProbe4_TransformationMatrixGet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMProbe4_TransformationMatrixSet( This, pTransMat_ )  \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_ ) )

#define IIMProbe4_UnitsGet( This, pUnits_ )    \
    ( ( This )->lpVtbl->UnitsGet( This, pUnits_ ) )

#define IIMProbe4_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )

#define IIMProbe4_UseAutoViewpointGet( This, pUseAutoViewpoint_ )  \
    ( ( This )->lpVtbl->UseAutoViewpointGet( This, pUseAutoViewpoint_ ) )

#define IIMProbe4_UseAutoViewpointSet( This, useAutoViewpoint_ )   \
    ( ( This )->lpVtbl->UseAutoViewpointSet( This, useAutoViewpoint_ ) )

#define IIMProbe4_UseDeviceAsMouseGet( This, pUseAsMouse_ )    \
    ( ( This )->lpVtbl->UseDeviceAsMouseGet( This, pUseAsMouse_ ) )

#define IIMProbe4_UseDeviceAsMouseSet( This, useAsMouse_ ) \
    ( ( This )->lpVtbl->UseDeviceAsMouseSet( This, useAsMouse_ ) )

#define IIMProbe4_UseTransformationMatrixGet( This, pUseMatrix_ )  \
    ( ( This )->lpVtbl->UseTransformationMatrixGet( This, pUseMatrix_ ) )

#define IIMProbe4_UseTransformationMatrixSet( This, useMatrix_ )   \
    ( ( This )->lpVtbl->UseTransformationMatrixSet( This, useMatrix_ ) )


#define IIMProbe4_CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousDistanceModeDistance( This, pCanChangeDistance_ ) )

#define IIMProbe4_CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) \
    ( ( This )->lpVtbl->CanChangeContinuousTimeModeTime( This, pCanChangeTime_ ) )

#define IIMProbe4_CanFindTarget( This, pCanFindTarget_ )   \
    ( ( This )->lpVtbl->CanFindTarget( This, pCanFindTarget_ ) )

#define IIMProbe4_CanGoHome( This, pCanGoHome_ )   \
    ( ( This )->lpVtbl->CanGoHome( This, pCanGoHome_ ) )

#define IIMProbe4_CanGoXYZ( This, pCanGoXYZ_ ) \
    ( ( This )->lpVtbl->CanGoXYZ( This, pCanGoXYZ_ ) )

#define IIMProbe4_ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe4_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe4_ContinuousTimeModeTimeGet( This, pTime_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeGet( This, pTime_ ) )

#define IIMProbe4_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbe4_FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) \
    ( ( This )->lpVtbl->FindTarget( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe4_FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ )  \
    ( ( This )->lpVtbl->FindTargetParametersGet( This, pSearchRadiusInUnits_, pApproximateDistanceInUnits_ ) )

#define IIMProbe4_FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ )    \
    ( ( This )->lpVtbl->FindTargetParametersSet( This, searchRadiusInUnits_, approximateDistanceInUnits_ ) )

#define IIMProbe4_GoHome( This )  \
    ( ( This )->lpVtbl->GoHome( This ) )

#define IIMProbe4_GoXYZ( This, X_, Y_, Z_ )  \
    ( ( This )->lpVtbl->GoXYZ( This, X_, Y_, Z_ ) )

#define IIMProbe4_GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) \
    ( ( This )->lpVtbl->GoXYZCoordinatesGet( This, pX_, pY_, pZ_ ) )

#define IIMProbe4_GoXYZCoordinatesSet( This, X_, Y_, Z_ )    \
    ( ( This )->lpVtbl->GoXYZCoordinatesSet( This, X_, Y_, Z_ ) )

#define IIMProbe4_NextPointIsCompensationPoint( This )    \
    ( ( This )->lpVtbl->NextPointIsCompensationPoint( This ) )

#define IIMProbe4_ProbingEnd2( This, probeLastPoint_ ) \
    ( ( This )->lpVtbl->ProbingEnd2( This, probeLastPoint_ ) )


#define IIMProbe4_HasTemperature( This, pHasTemperature_ ) \
    ( ( This )->lpVtbl->HasTemperature( This, pHasTemperature_ ) )

#define IIMProbe4_HasRelativeHumidity( This, pHasHumidity_ )   \
    ( ( This )->lpVtbl->HasRelativeHumidity( This, pHasHumidity_ ) )

#define IIMProbe4_HasAirPressure( This, pHasAirPressure_ ) \
    ( ( This )->lpVtbl->HasAirPressure( This, pHasAirPressure_ ) )

#define IIMProbe4_HasStatus( This, pHasStatus_ )   \
    ( ( This )->lpVtbl->HasStatus( This, pHasStatus_ ) )

#define IIMProbe4_TemperatureGet( This, pTemperature_ )    \
    ( ( This )->lpVtbl->TemperatureGet( This, pTemperature_ ) )

#define IIMProbe4_RelativeHumidityGet( This, pHumidity_ )  \
    ( ( This )->lpVtbl->RelativeHumidityGet( This, pHumidity_ ) )

#define IIMProbe4_AirPressureGet( This, pAirPressure_ )    \
    ( ( This )->lpVtbl->AirPressureGet( This, pAirPressure_ ) )

#define IIMProbe4_StatusGet( This, pStatus_ )  \
    ( ( This )->lpVtbl->StatusGet( This, pStatus_ ) )

#define IIMProbe4_ProbeTypeGet( This, pProbeType_ )    \
    ( ( This )->lpVtbl->ProbeTypeGet( This, pProbeType_ ) )

#define IIMProbe4_ReflectorSet( This, reflectorName_, standardReflectorName_ )  \
    ( ( This )->lpVtbl->ReflectorSet( This, reflectorName_, standardReflectorName_ ) )

#define IIMProbe4_ReflectorGet( This, pReflectorName_ )    \
    ( ( This )->lpVtbl->ReflectorGet( This, pReflectorName_ ) )

#define IIMProbe4_StandardReflectorsGetNb( This, pReflectorNb_ )   \
    ( ( This )->lpVtbl->StandardReflectorsGetNb( This, pReflectorNb_ ) )

#define IIMProbe4_StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ )   \
    ( ( This )->lpVtbl->StandardReflectorInfoGet( This, reflectorIndex_, pReflectorName_, pReflectorOffsetInUnits_ ) )


#define IIMProbe4_CanChangeCompensationMethod( This, pCanChangeMethod_ )   \
    ( ( This )->lpVtbl->CanChangeCompensationMethod( This, pCanChangeMethod_ ) )

#define IIMProbe4_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbe4_CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ )  \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceGet( This, pDistanceInUnits_ ) )

#define IIMProbe4_CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ )   \
    ( ( This )->lpVtbl->CompensationPointAutomaticTriggerDistanceSet( This, distanceInUnits_ ) )

#define IIMProbe4_UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ )   \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerGet( This, pUseAutomaticTrigger_ ) )

#define IIMProbe4_UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ )    \
    ( ( This )->lpVtbl->UseCompensationPointAutomaticTriggerSet( This, useAutomaticTrigger_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbe4_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbe_h__
