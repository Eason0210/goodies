/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:54 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback9.idl:
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

#ifndef __IIMProbeFeedback9_h__
#define __IIMProbeFeedback9_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback9_FWD_DEFINED__
#define __IIMProbeFeedback9_FWD_DEFINED__
typedef interface IIMProbeFeedback9 IIMProbeFeedback9;
#endif  /* __IIMProbeFeedback9_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback8.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback9_INTERFACE_DEFINED__
#define __IIMProbeFeedback9_INTERFACE_DEFINED__

/* interface IIMProbeFeedback9 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback9;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "E79ED85F-48B5-48bf-8E12-91EC19B5C80C" )
IIMProbeFeedback9 : public IIMProbeFeedback8
{
public:
    virtual HRESULT STDMETHODCALLTYPE MotorActivationStateSet(
        /* [in] */ VARIANT_BOOL activationState_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ManualControlsDlgClosed( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback9Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback9 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback9 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback9 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback9 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShankSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL hasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double shankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionWithIndexSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionWithIndexSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet2 )(
        IIMProbeFeedback9 * This,
        /* [in] */ EDeviceStatus status_,
        BSTR details_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbeFeedback9 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClosed )(
        IIMProbeFeedback9 * This );

    END_INTERFACE
} IIMProbeFeedback9Vtbl;

interface IIMProbeFeedback9
{
    CONST_VTBL struct IIMProbeFeedback9Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback9_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback9_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback9_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback9_ConnectionEnd( This )   \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback9_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback9_DiameterSet( This, diameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback9_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )    \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback9_MeasurementStart( This )    \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback9_MeasurementStop( This ) \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback9_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback9_NbPointsSet( This, nbPoints_ )   \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback9_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback9_ProbingEndAndRestart( This )    \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback9_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback9_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback9_ContinuousModeEnabled( This, continuous_ )   \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback9_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback9_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback9_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback9_TemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback9_RelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback9_AirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback9_StatusSet( This, status_ )   \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback9_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ )  \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback9_ProbeTypeSet( This, probeType_ ) \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback9_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )


#define IIMProbeFeedback9_FaceSet( This, face_ )   \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbeFeedback9_HasShankSet( This, hasShank_ )   \
    ( ( This )->lpVtbl->HasShankSet( This, hasShank_ ) )

#define IIMProbeFeedback9_ShankDiameterSet( This, shankDiameterInUnits_ )  \
    ( ( This )->lpVtbl->ShankDiameterSet( This, shankDiameterInUnits_ ) )


#define IIMProbeFeedback9_CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ ) )

#define IIMProbeFeedback9_CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ ) )


#define IIMProbeFeedback9_SendRealTimePositionsSet( This, sendRealTimePositions_ ) \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbeFeedback9_StatusSet2( This, status_, details_ ) \
    ( ( This )->lpVtbl->StatusSet2( This, status_, details_ ) )

#define IIMProbeFeedback9_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbeFeedback9_UseLaserPointerSet( This, useLaserPointer_ ) \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbeFeedback9_UseTargetIlluminationSet( This, useTargetIllumination_ ) \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbeFeedback9_UseTargetLockSet( This, useTargetLock_ ) \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbeFeedback9_MotorActivationStateSet( This, activationState_ )    \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbeFeedback9_ManualControlsDlgClosed( This ) \
    ( ( This )->lpVtbl->ManualControlsDlgClosed( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback9_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback9_h__
