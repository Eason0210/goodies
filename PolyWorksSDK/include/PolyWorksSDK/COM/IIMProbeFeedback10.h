/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Fri Sep 14 15:51:02 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback10.idl:
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

#ifndef __IIMProbeFeedback10_h__
#define __IIMProbeFeedback10_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback10_FWD_DEFINED__
#define __IIMProbeFeedback10_FWD_DEFINED__
typedef interface IIMProbeFeedback10 IIMProbeFeedback10;
#endif  /* __IIMProbeFeedback10_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback9.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback10_INTERFACE_DEFINED__
#define __IIMProbeFeedback10_INTERFACE_DEFINED__

/* interface IIMProbeFeedback10 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback10;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "ED849170-6248-4FDB-BB45-C3DBCBC7564C" )
IIMProbeFeedback10 : public IIMProbeFeedback9
{
public:
    virtual HRESULT STDMETHODCALLTYPE ApproachDirectionSet(
        /* [in] */ double directionI_,
        /* [in] */ double directionJ_,
        /* [in] */ double directionK_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback10Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback10 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback10 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback10 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShankSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL hasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double shankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionWithIndexSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionWithIndexSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * SendRealTimePositionsSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL sendRealTimePositions_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet2 )(
        IIMProbeFeedback10 * This,
        /* [in] */ EDeviceStatus status_,
        BSTR details_ );

    HRESULT( STDMETHODCALLTYPE * UseAutomaticTargetRecognitionSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL useAutomaticTargetRecognition_ );

    HRESULT( STDMETHODCALLTYPE * UseLaserPointerSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL useLaserPointer_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetIlluminationSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL useTargetIllumination_ );

    HRESULT( STDMETHODCALLTYPE * UseTargetLockSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL useTargetLock_ );

    HRESULT( STDMETHODCALLTYPE * MotorActivationStateSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * ManualControlsDlgClosed )(
        IIMProbeFeedback10 * This );

    HRESULT( STDMETHODCALLTYPE * ApproachDirectionSet )(
        IIMProbeFeedback10 * This,
        /* [in] */ double directionI_,
        /* [in] */ double directionJ_,
        /* [in] */ double directionK_ );

    END_INTERFACE
} IIMProbeFeedback10Vtbl;

interface IIMProbeFeedback10
{
    CONST_VTBL struct IIMProbeFeedback10Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback10_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback10_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback10_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback10_ConnectionEnd( This )  \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback10_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback10_DiameterSet( This, diameterInUnits_ )   \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback10_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )   \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback10_MeasurementStart( This )   \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback10_MeasurementStop( This )    \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback10_ModeSet( This, modeNb_ )    \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback10_NbPointsSet( This, nbPoints_ )  \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback10_ProbingEnd( This ) \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback10_ProbingEndAndRestart( This )   \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback10_UnitsSet( This, units_ )    \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback10_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback10_ContinuousModeEnabled( This, continuous_ )  \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback10_ContinuousTimeModeTimeSet( This, time_ )    \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback10_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )  \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback10_CompensationMethodSet( This, compensationMethod_ )  \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback10_TemperatureSet( This, temperature_ )    \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback10_RelativeHumiditySet( This, humidity_ )  \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback10_AirPressureSet( This, airPressure_ )    \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback10_StatusSet( This, status_ )  \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback10_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback10_ProbeTypeSet( This, probeType_ )    \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback10_EnvironmentalParametersSourceSet( This, envParamsSource_ )  \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )


#define IIMProbeFeedback10_FaceSet( This, face_ )  \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbeFeedback10_HasShankSet( This, hasShank_ )  \
    ( ( This )->lpVtbl->HasShankSet( This, hasShank_ ) )

#define IIMProbeFeedback10_ShankDiameterSet( This, shankDiameterInUnits_ ) \
    ( ( This )->lpVtbl->ShankDiameterSet( This, shankDiameterInUnits_ ) )


#define IIMProbeFeedback10_CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ ) )

#define IIMProbeFeedback10_CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ )  \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ ) )


#define IIMProbeFeedback10_SendRealTimePositionsSet( This, sendRealTimePositions_ )    \
    ( ( This )->lpVtbl->SendRealTimePositionsSet( This, sendRealTimePositions_ ) )

#define IIMProbeFeedback10_StatusSet2( This, status_, details_ )    \
    ( ( This )->lpVtbl->StatusSet2( This, status_, details_ ) )

#define IIMProbeFeedback10_UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ )    \
    ( ( This )->lpVtbl->UseAutomaticTargetRecognitionSet( This, useAutomaticTargetRecognition_ ) )

#define IIMProbeFeedback10_UseLaserPointerSet( This, useLaserPointer_ )    \
    ( ( This )->lpVtbl->UseLaserPointerSet( This, useLaserPointer_ ) )

#define IIMProbeFeedback10_UseTargetIlluminationSet( This, useTargetIllumination_ )    \
    ( ( This )->lpVtbl->UseTargetIlluminationSet( This, useTargetIllumination_ ) )

#define IIMProbeFeedback10_UseTargetLockSet( This, useTargetLock_ )    \
    ( ( This )->lpVtbl->UseTargetLockSet( This, useTargetLock_ ) )


#define IIMProbeFeedback10_MotorActivationStateSet( This, activationState_ )   \
    ( ( This )->lpVtbl->MotorActivationStateSet( This, activationState_ ) )

#define IIMProbeFeedback10_ManualControlsDlgClosed( This )    \
    ( ( This )->lpVtbl->ManualControlsDlgClosed( This ) )


#define IIMProbeFeedback10_ApproachDirectionSet( This, directionI_, directionJ_, directionK_ )   \
    ( ( This )->lpVtbl->ApproachDirectionSet( This, directionI_, directionJ_, directionK_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback10_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback10_h__
