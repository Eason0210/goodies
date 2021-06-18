/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:30 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback6.idl:
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

#ifndef __IIMProbeFeedback6_h__
#define __IIMProbeFeedback6_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback6_FWD_DEFINED__
#define __IIMProbeFeedback6_FWD_DEFINED__
typedef interface IIMProbeFeedback6 IIMProbeFeedback6;
#endif  /* __IIMProbeFeedback6_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback5.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback6_INTERFACE_DEFINED__
#define __IIMProbeFeedback6_INTERFACE_DEFINED__

/* interface IIMProbeFeedback6 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback6;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "61DD3D08-17C0-4d33-B4BA-7F1727200355" )
IIMProbeFeedback6 : public IIMProbeFeedback5
{
public:
    virtual HRESULT STDMETHODCALLTYPE HasShankSet(
        /* [in] */ VARIANT_BOOL hasShank_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ShankDiameterSet(
        /* [in] */ double shankDiameterInUnits_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback6Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback6 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback6 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback6 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback6 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    HRESULT( STDMETHODCALLTYPE * FaceSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ short face_ );

    HRESULT( STDMETHODCALLTYPE * HasShankSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ VARIANT_BOOL hasShank_ );

    HRESULT( STDMETHODCALLTYPE * ShankDiameterSet )(
        IIMProbeFeedback6 * This,
        /* [in] */ double shankDiameterInUnits_ );

    END_INTERFACE
} IIMProbeFeedback6Vtbl;

interface IIMProbeFeedback6
{
    CONST_VTBL struct IIMProbeFeedback6Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback6_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback6_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback6_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback6_ConnectionEnd( This )   \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback6_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback6_DiameterSet( This, diameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback6_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )    \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback6_MeasurementStart( This )    \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback6_MeasurementStop( This ) \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback6_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback6_NbPointsSet( This, nbPoints_ )   \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback6_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback6_ProbingEndAndRestart( This )    \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback6_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback6_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback6_ContinuousModeEnabled( This, continuous_ )   \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback6_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback6_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback6_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback6_TemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback6_RelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback6_AirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback6_StatusSet( This, status_ )   \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback6_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ )  \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback6_ProbeTypeSet( This, probeType_ ) \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback6_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )


#define IIMProbeFeedback6_FaceSet( This, face_ )   \
    ( ( This )->lpVtbl->FaceSet( This, face_ ) )


#define IIMProbeFeedback6_HasShankSet( This, hasShank_ )   \
    ( ( This )->lpVtbl->HasShankSet( This, hasShank_ ) )

#define IIMProbeFeedback6_ShankDiameterSet( This, shankDiameterInUnits_ )  \
    ( ( This )->lpVtbl->ShankDiameterSet( This, shankDiameterInUnits_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback6_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback6_h__
