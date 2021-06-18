/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:48:50 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMDeviceLevel.idl:
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

#ifndef __IIMDeviceLevel_h__
#define __IIMDeviceLevel_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMDeviceLevel_FWD_DEFINED__
#define __IIMDeviceLevel_FWD_DEFINED__
typedef interface IIMDeviceLevel IIMDeviceLevel;
#endif  /* __IIMDeviceLevel_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMDeviceLevel_INTERFACE_DEFINED__
#define __IIMDeviceLevel_INTERFACE_DEFINED__

/* interface IIMDeviceLevel */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMDeviceLevel;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "6037DAC6-2841-4e2e-99B5-688B6B40F31B" )
IIMDeviceLevel : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanProvideGravityDirection(
        /* [retval][out] */ VARIANT_BOOL * pCanProvideGravityDirection_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CanProvideRealTimeAngles(
        /* [retval][out] */ VARIANT_BOOL * pCanProvideRealTimeAngles_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GravityDirectionGet(
        /* [out] */ double* pI_,
        /* [out] */ double* pJ_,
        /* [out] */ double* pK_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE RealTimeAnglesGet(
        /* [out] */ double* pAngleX_,
        /* [out] */ double* pAngleY_,
        /* [out] */ double* pAngleZ_,
        /* [out] */ ELevelAngleStatus * pStatusX_,
        /* [out] */ ELevelAngleStatus * pStatusY_,
        /* [out] */ ELevelAngleStatus * pStatusZ_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StabilityToleranceGet(
        /* [retval][out] */ double* pTolerance_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StabilityToleranceSet(
        /* [in] */ double tolerance_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMDeviceLevelVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMDeviceLevel * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMDeviceLevel * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMDeviceLevel * This );

    HRESULT( STDMETHODCALLTYPE * CanProvideGravityDirection )(
        IIMDeviceLevel * This,
        /* [retval][out] */ VARIANT_BOOL* pCanProvideGravityDirection_ );

    HRESULT( STDMETHODCALLTYPE * CanProvideRealTimeAngles )(
        IIMDeviceLevel * This,
        /* [retval][out] */ VARIANT_BOOL* pCanProvideRealTimeAngles_ );

    HRESULT( STDMETHODCALLTYPE * GravityDirectionGet )(
        IIMDeviceLevel * This,
        /* [out] */ double* pI_,
        /* [out] */ double* pJ_,
        /* [out] */ double* pK_ );

    HRESULT( STDMETHODCALLTYPE * RealTimeAnglesGet )(
        IIMDeviceLevel * This,
        /* [out] */ double* pAngleX_,
        /* [out] */ double* pAngleY_,
        /* [out] */ double* pAngleZ_,
        /* [out] */ ELevelAngleStatus* pStatusX_,
        /* [out] */ ELevelAngleStatus* pStatusY_,
        /* [out] */ ELevelAngleStatus* pStatusZ_ );

    HRESULT( STDMETHODCALLTYPE * StabilityToleranceGet )(
        IIMDeviceLevel * This,
        /* [retval][out] */ double* pTolerance_ );

    HRESULT( STDMETHODCALLTYPE * StabilityToleranceSet )(
        IIMDeviceLevel * This,
        /* [in] */ double tolerance_ );

    END_INTERFACE
} IIMDeviceLevelVtbl;

interface IIMDeviceLevel
{
    CONST_VTBL struct IIMDeviceLevelVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMDeviceLevel_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMDeviceLevel_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMDeviceLevel_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMDeviceLevel_CanProvideGravityDirection( This, pCanProvideGravityDirection_ )    \
    ( ( This )->lpVtbl->CanProvideGravityDirection( This, pCanProvideGravityDirection_ ) )

#define IIMDeviceLevel_CanProvideRealTimeAngles( This, pCanProvideRealTimeAngles_ )    \
    ( ( This )->lpVtbl->CanProvideRealTimeAngles( This, pCanProvideRealTimeAngles_ ) )

#define IIMDeviceLevel_GravityDirectionGet( This, pI_, pJ_, pK_ )    \
    ( ( This )->lpVtbl->GravityDirectionGet( This, pI_, pJ_, pK_ ) )

#define IIMDeviceLevel_RealTimeAnglesGet( This, pAngleX_, pAngleY_, pAngleZ_, pStatusX_, pStatusY_, pStatusZ_ ) \
    ( ( This )->lpVtbl->RealTimeAnglesGet( This, pAngleX_, pAngleY_, pAngleZ_, pStatusX_, pStatusY_, pStatusZ_ ) )

#define IIMDeviceLevel_StabilityToleranceGet( This, pTolerance_ )  \
    ( ( This )->lpVtbl->StabilityToleranceGet( This, pTolerance_ ) )

#define IIMDeviceLevel_StabilityToleranceSet( This, tolerance_ )   \
    ( ( This )->lpVtbl->StabilityToleranceSet( This, tolerance_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMDeviceLevel_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMDeviceLevel_h__
