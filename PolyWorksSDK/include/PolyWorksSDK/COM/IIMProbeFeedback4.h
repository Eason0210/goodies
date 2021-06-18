/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:47:36 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbeFeedback4.idl:
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

#ifndef __IIMProbeFeedback4_h__
#define __IIMProbeFeedback4_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMProbeFeedback4_FWD_DEFINED__
#define __IIMProbeFeedback4_FWD_DEFINED__
typedef interface IIMProbeFeedback4 IIMProbeFeedback4;
#endif  /* __IIMProbeFeedback4_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMProbeFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMProbeFeedback4_INTERFACE_DEFINED__
#define __IIMProbeFeedback4_INTERFACE_DEFINED__

/* interface IIMProbeFeedback4 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMProbeFeedback4;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "E7012E4C-72F3-4bdd-BCD9-B4459C8F6D5D" )
IIMProbeFeedback4 : public IIMProbeFeedback3
{
public:
    virtual HRESULT STDMETHODCALLTYPE EnvironmentalParametersSourceSet(
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMProbeFeedback4Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMProbeFeedback4 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMProbeFeedback4 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * ConnectionEnd )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_ );

    HRESULT( STDMETHODCALLTYPE * DiameterSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double diameterInUnits_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordPositionSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double lastRecordX_,
        /* [in] */ double lastRecordY_,
        /* [in] */ double lastRecordZ_ );

    HRESULT( STDMETHODCALLTYPE * MeasurementStart )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * MeasurementStop )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * ModeSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ short modeNb_ );

    HRESULT( STDMETHODCALLTYPE * NbPointsSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ long nbPoints_ );

    HRESULT( STDMETHODCALLTYPE * ProbingEnd )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * ProbingEndAndRestart )(
        IIMProbeFeedback4 * This );

    HRESULT( STDMETHODCALLTYPE * UnitsSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double units_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousDistanceModeDistanceSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double distanceInUnits_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousModeEnabled )(
        IIMProbeFeedback4 * This,
        VARIANT_BOOL continuous_ );

    HRESULT( STDMETHODCALLTYPE * ContinuousTimeModeTimeSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ long time_ );

    HRESULT( STDMETHODCALLTYPE * CurrentProbePositionAndDirectionSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double currentProbeX_,
        /* [in] */ double currentProbeY_,
        /* [in] */ double currentProbeZ_,
        /* [in] */ double currentProbeI_,
        /* [in] */ double currentProbeJ_,
        /* [in] */ double currentProbeK_ );

    HRESULT( STDMETHODCALLTYPE * CompensationMethodSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ ECompensationMethods compensationMethod_ );

    HRESULT( STDMETHODCALLTYPE * TemperatureSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double temperature_ );

    HRESULT( STDMETHODCALLTYPE * RelativeHumiditySet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double humidity_ );

    HRESULT( STDMETHODCALLTYPE * AirPressureSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double airPressure_ );

    HRESULT( STDMETHODCALLTYPE * StatusSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ EDeviceStatus status_ );

    HRESULT( STDMETHODCALLTYPE * LastRecordDeviationSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ double stdDeviation_,
        /* [in] */ VARIANT_BOOL valueIsValid_ );

    HRESULT( STDMETHODCALLTYPE * ProbeTypeSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ EProbeTypes probeType_ );

    HRESULT( STDMETHODCALLTYPE * EnvironmentalParametersSourceSet )(
        IIMProbeFeedback4 * This,
        /* [in] */ EEnvironmentalParametersSources envParamsSource_ );

    END_INTERFACE
} IIMProbeFeedback4Vtbl;

interface IIMProbeFeedback4
{
    CONST_VTBL struct IIMProbeFeedback4Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMProbeFeedback4_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMProbeFeedback4_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMProbeFeedback4_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMProbeFeedback4_ConnectionEnd( This )   \
    ( ( This )->lpVtbl->ConnectionEnd( This ) )

#define IIMProbeFeedback4_CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ )    \
    ( ( This )->lpVtbl->CurrentProbePositionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_ ) )

#define IIMProbeFeedback4_DiameterSet( This, diameterInUnits_ )    \
    ( ( This )->lpVtbl->DiameterSet( This, diameterInUnits_ ) )

#define IIMProbeFeedback4_LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ )    \
    ( ( This )->lpVtbl->LastRecordPositionSet( This, lastRecordX_, lastRecordY_, lastRecordZ_ ) )

#define IIMProbeFeedback4_MeasurementStart( This )    \
    ( ( This )->lpVtbl->MeasurementStart( This ) )

#define IIMProbeFeedback4_MeasurementStop( This ) \
    ( ( This )->lpVtbl->MeasurementStop( This ) )

#define IIMProbeFeedback4_ModeSet( This, modeNb_ ) \
    ( ( This )->lpVtbl->ModeSet( This, modeNb_ ) )

#define IIMProbeFeedback4_NbPointsSet( This, nbPoints_ )   \
    ( ( This )->lpVtbl->NbPointsSet( This, nbPoints_ ) )

#define IIMProbeFeedback4_ProbingEnd( This )  \
    ( ( This )->lpVtbl->ProbingEnd( This ) )

#define IIMProbeFeedback4_ProbingEndAndRestart( This )    \
    ( ( This )->lpVtbl->ProbingEndAndRestart( This ) )

#define IIMProbeFeedback4_UnitsSet( This, units_ ) \
    ( ( This )->lpVtbl->UnitsSet( This, units_ ) )


#define IIMProbeFeedback4_ContinuousDistanceModeDistanceSet( This, distanceInUnits_ )  \
    ( ( This )->lpVtbl->ContinuousDistanceModeDistanceSet( This, distanceInUnits_ ) )

#define IIMProbeFeedback4_ContinuousModeEnabled( This, continuous_ )   \
    ( ( This )->lpVtbl->ContinuousModeEnabled( This, continuous_ ) )

#define IIMProbeFeedback4_ContinuousTimeModeTimeSet( This, time_ ) \
    ( ( This )->lpVtbl->ContinuousTimeModeTimeSet( This, time_ ) )

#define IIMProbeFeedback4_CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ )   \
    ( ( This )->lpVtbl->CurrentProbePositionAndDirectionSet( This, currentProbeX_, currentProbeY_, currentProbeZ_, currentProbeI_, currentProbeJ_, currentProbeK_ ) )


#define IIMProbeFeedback4_CompensationMethodSet( This, compensationMethod_ )   \
    ( ( This )->lpVtbl->CompensationMethodSet( This, compensationMethod_ ) )

#define IIMProbeFeedback4_TemperatureSet( This, temperature_ ) \
    ( ( This )->lpVtbl->TemperatureSet( This, temperature_ ) )

#define IIMProbeFeedback4_RelativeHumiditySet( This, humidity_ )   \
    ( ( This )->lpVtbl->RelativeHumiditySet( This, humidity_ ) )

#define IIMProbeFeedback4_AirPressureSet( This, airPressure_ ) \
    ( ( This )->lpVtbl->AirPressureSet( This, airPressure_ ) )

#define IIMProbeFeedback4_StatusSet( This, status_ )   \
    ( ( This )->lpVtbl->StatusSet( This, status_ ) )

#define IIMProbeFeedback4_LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ )  \
    ( ( This )->lpVtbl->LastRecordDeviationSet( This, stdDeviation_, valueIsValid_ ) )

#define IIMProbeFeedback4_ProbeTypeSet( This, probeType_ ) \
    ( ( This )->lpVtbl->ProbeTypeSet( This, probeType_ ) )


#define IIMProbeFeedback4_EnvironmentalParametersSourceSet( This, envParamsSource_ )   \
    ( ( This )->lpVtbl->EnvironmentalParametersSourceSet( This, envParamsSource_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMProbeFeedback4_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMProbeFeedback4_h__
