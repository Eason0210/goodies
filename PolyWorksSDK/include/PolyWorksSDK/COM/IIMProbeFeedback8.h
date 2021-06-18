/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:40 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback8.idl:
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

#ifndef __IIMProbeFeedback8_h__
#define __IIMProbeFeedback8_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback8_FWD_DEFINED__
#define __IIMProbeFeedback8_FWD_DEFINED__
typedef interface IIMProbeFeedback8 IIMProbeFeedback8;
#endif  /* __IIMProbeFeedback8_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback7.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback8_INTERFACE_DEFINED__
#define __IIMProbeFeedback8_INTERFACE_DEFINED__

/* interface IIMProbeFeedback8 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback8;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "C4E793A1-BBF9-4ae5-B550-77EE8C766DDF" )
IIMProbeFeedback8 : public IIMProbeFeedback7
{
public:
    virtual HRESULT STDMETHODCALLTYPE SendRealTimePositionsSet(
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StatusSet2(
        /* [in] */ EDeviceStatus status_,
        BSTR details_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseAutomaticTargetRecognitionSet(
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLaserPointerSet(
        /* [in] */ VARIANT_BOOL useLaserPointer_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetIlluminationSet(
        /* [in] */ VARIANT_BOOL useTargetIllumination_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseTargetLockSet(
        /* [in] */ VARIANT_BOOL useTargetLock_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback8Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback8 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback8 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback8 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback8 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShankSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL hasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double shankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionWithIndexSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionWithIndexSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet2 )(
        IIMProbeFeedback8 * This,
        /* [in] */ EDeviceStatus status_,
        BSTR details_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbeFeedback8 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    END_INTERFACE
} IIMProbeFeedback8Vtbl;

interface IIMProbeFeedback8
{
    CONST_VTBL struct IIMProbeFeedback8Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback8_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback8_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback8_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback8_ConnectionEnd( This )   \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback8_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback8_DiameterSet( This, diameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback8_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )    \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback8_MeasurementStart( This )    \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback8_MeasurementStop( This ) \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback8_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback8_NbPointsSet( This, nbPoints_ )   \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback8_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback8_ProbingEndAndRestart( This )    \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback8_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback8_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback8_ContinuousModeEnabled( This, continuous_ )   \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback8_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback8_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback8_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback8_TemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback8_RelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback8_AirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback8_StatusSet( This, status_ )   \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback8_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ )  \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback8_ProbeTypeSet( This, probeType_ ) \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback8_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )


#define IIMProbeFeedback8_FaceSet( This, face_ )   \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbeFeedback8_HasShankSet( This, hasShank_ )   \
    ( ( This )->lpVtbl->HasShankSet( This, hasShank_ ) )

#define IIMProbeFeedback8_ShankDiameterSet( This, shankDiameterInUnits_ )  \
    ( ( This )->lpVtbl->ShankDiameterSet( This, shankDiameterInUnits_ ) )


#define IIMProbeFeedback8_CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ ) )

#define IIMProbeFeedback8_CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ ) )


#define IIMProbeFeedback8_SendRealTimePositionsSet( This, sendRealTimePositions_ ) \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbeFeedback8_StatusSet2( This, status_, details_ ) \
    ( ( This )->lpVtbl->StatusSet2( This, status_, details_ ) )

#define IIMProbeFeedback8_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbeFeedback8_UseLaserPointerSet( This, useLaserPointer_ ) \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbeFeedback8_UseTargetIlluminationSet( This, useTargetIllumination_ ) \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbeFeedback8_UseTargetLockSet( This, useTargetLock_ ) \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback8_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback8_h__
