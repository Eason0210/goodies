/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:33 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback7.idl:
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

#ifndef __IIMProbeFeedback7_h__
#define __IIMProbeFeedback7_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback7_FWD_DEFINED__
#define __IIMProbeFeedback7_FWD_DEFINED__
typedef interface IIMProbeFeedback7 IIMProbeFeedback7;
#endif  /* __IIMProbeFeedback7_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback6.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback7_INTERFACE_DEFINED__
#define __IIMProbeFeedback7_INTERFACE_DEFINED__

/* interface IIMProbeFeedback7 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback7;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "7B5F6223-58CB-4d3c-AF23-C14151F32C69" )
IIMProbeFeedback7 : public IIMProbeFeedback6
{
public:
    virtual HRESULT STDMETHODCALLTYPE CurrentProbePositionWithIndexSet(
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ short currentProbeIndex_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CurrentProbePositionAndDirectionWithIndexSet(
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_,
        /* [in] */ short currentProbeIndex_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback7Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback7 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback7 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback7 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback7 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShankSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ VARIANT_BOOL hasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double shankDiameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionWithIndexSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ short currentProbeIndex_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionWithIndexSet )(
        IIMProbeFeedback7 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_,
        /* [in] */ short currentProbeIndex_ );

    END_INTERFACE
} IIMProbeFeedback7Vtbl;

interface IIMProbeFeedback7
{
    CONST_VTBL struct IIMProbeFeedback7Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback7_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback7_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback7_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback7_ConnectionEnd( This )   \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback7_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback7_DiameterSet( This, diameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback7_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )    \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback7_MeasurementStart( This )    \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback7_MeasurementStop( This ) \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback7_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback7_NbPointsSet( This, nbPoints_ )   \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback7_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback7_ProbingEndAndRestart( This )    \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback7_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback7_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback7_ContinuousModeEnabled( This, continuous_ )   \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback7_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback7_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback7_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback7_TemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback7_RelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback7_AirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback7_StatusSet( This, status_ )   \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback7_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ )  \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback7_ProbeTypeSet( This, probeType_ ) \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback7_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )


#define IIMProbeFeedback7_FaceSet( This, face_ )   \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbeFeedback7_HasShankSet( This, hasShank_ )   \
    ( ( This )->lpVtbl->HasShankSet( This, hasShank_ ) )

#define IIMProbeFeedback7_ShankDiameterSet( This, shankDiameterInUnits_ )  \
    ( ( This )->lpVtbl->ShankDiameterSet( This, shankDiameterInUnits_ ) )


#define IIMProbeFeedback7_CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeIndex_ ) )

#define IIMProbeFeedback7_CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionWithIndexSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_, currentProbeIndex_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback7_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback7_h__
