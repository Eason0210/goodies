/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:49:00 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMDeviceLevel2.idl:
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

#ifndef __IIMDeviceLevel2_h__
#define __IIMDeviceLevel2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMDeviceLevel2_FWD_DEFINED__
#define __IIMDeviceLevel2_FWD_DEFINED__
typedef interface IIMDeviceLevel2 IIMDeviceLevel2;
#endif  /* __IIMDeviceLevel2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMDeviceLevel.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMDeviceLevel2_INTERFACE_DEFINED__
#define __IIMDeviceLevel2_INTERFACE_DEFINED__

/* interface IIMDeviceLevel2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMDeviceLevel2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "797A47E6-C20B-4d72-BB41-7E0C2D06631B" )
IIMDeviceLevel2 : public IIMDeviceLevel
{
public:
    virtual HRESULT STDMETHODCALLTYPE CanUseLevelCompensation(
        /* [retval][out] */ VARIANT_BOOL * pCanUseLevelCompensation_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LevelCompensationStatusGet(
        /* [retval][out] */ ELevelCompensationStatus * pStatus_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLevelCompensationGet(
        /* [retval][out] */ VARIANT_BOOL * pUseLevelCompensation_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLevelCompensationSet(
        /* [in] */ VARIANT_BOOL useLevelCompensation_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMDeviceLevel2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMDeviceLevel2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMDeviceLevel2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMDeviceLevel2 * This );

    HRESULT( STDMETHODCALLTYPE * CanProvideGravityDirection )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanProvideGravityDirection_ );

    HRESULT( STDMETHODCALLTYPE * CanProvideRealTimeAngles )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanProvideRealTimeAngles_ );

    HRESULT( STDMETHODCALLTYPE * GravityDirectionGet )(
        IIMDeviceLevel2 * This,
        /* [out] */ double* pI_,
        /* [out] */ double* pJ_,
        /* [out] */ double* pK_ );

    HRESULT( STDMETHODCALLTYPE * RealTimeAnglesGet )(
        IIMDeviceLevel2 * This,
        /* [out] */ double* pAngleX_,
        /* [out] */ double* pAngleY_,
        /* [out] */ double* pAngleZ_,
        /* [out] */ ELevelAngleStatus* pStatusX_,
        /* [out] */ ELevelAngleStatus* pStatusY_,
        /* [out] */ ELevelAngleStatus* pStatusZ_ );

    HRESULT( STDMETHODCALLTYPE * StabilityToleranceGet )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ double* pTolerance_ );

    HRESULT( STDMETHODCALLTYPE * StabilityToleranceSet )(
        IIMDeviceLevel2 * This,
        /* [in] */ double tolerance_ );

    HRESULT( STDMETHODCALLTYPE * CanUseLevelCompensation )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ VARIANT_BOOL* pCanUseLevelCompensation_ );

    HRESULT( STDMETHODCALLTYPE * LevelCompensationStatusGet )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ ELevelCompensationStatus* pStatus_ );

    HRESULT( STDMETHODCALLTYPE * UseLevelCompensationGet )(
        IIMDeviceLevel2 * This,
        /* [retval][out] */ VARIANT_BOOL* pUseLevelCompensation_ );

    HRESULT( STDMETHODCALLTYPE * UseLevelCompensationSet )(
        IIMDeviceLevel2 * This,
        /* [in] */ VARIANT_BOOL useLevelCompensation_ );

    END_INTERFACE
} IIMDeviceLevel2Vtbl;

interface IIMDeviceLevel2
{
    CONST_VTBL struct IIMDeviceLevel2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMDeviceLevel2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMDeviceLevel2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMDeviceLevel2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMDeviceLevel2_CanProvideGravityDirection( This, pCanProvideGravityDirection_ )   \
    ( ( This )->lpVtbl->CanProvideGravityDirection( This, pCanProvideGravityDirection_ ) )

#define IIMDeviceLevel2_CanProvideRealTimeAngles( This, pCanProvideRealTimeAngles_ )   \
    ( ( This )->lpVtbl->CanProvideRealTimeAngles( This, pCanProvideRealTimeAngles_ ) )

#define IIMDeviceLevel2_GravityDirectionGet( This, pI_, pJ_, pK_ )   \
    ( ( This )->lpVtbl->GravityDirectionGet( This, pI_, pJ_, pK_ ) )

#define IIMDeviceLevel2_RealTimeAnglesGet( This, pAngleX_, pAngleY_, pAngleZ_, pStatusX_, pStatusY_, pStatusZ_ )    \
    ( ( This )->lpVtbl->RealTimeAnglesGet( This, pAngleX_, pAngleY_, pAngleZ_, pStatusX_, pStatusY_, pStatusZ_ ) )

#define IIMDeviceLevel2_StabilityToleranceGet( This, pTolerance_ ) \
    ( ( This )->lpVtbl->StabilityToleranceGet( This, pTolerance_ ) )

#define IIMDeviceLevel2_StabilityToleranceSet( This, tolerance_ )  \
    ( ( This )->lpVtbl->StabilityToleranceSet( This, tolerance_ ) )


#define IIMDeviceLevel2_CanUseLevelCompensation( This, pCanUseLevelCompensation_ ) \
    ( ( This )->lpVtbl->CanUseLevelCompensation( This, pCanUseLevelCompensation_ ) )

#define IIMDeviceLevel2_LevelCompensationStatusGet( This, pStatus_ )   \
    ( ( This )->lpVtbl->LevelCompensationStatusGet( This, pStatus_ ) )

#define IIMDeviceLevel2_UseLevelCompensationGet( This, pUseLevelCompensation_ )    \
    ( ( This )->lpVtbl->UseLevelCompensationGet( This, pUseLevelCompensation_ ) )

#define IIMDeviceLevel2_UseLevelCompensationSet( This, useLevelCompensation_ ) \
    ( ( This )->lpVtbl->UseLevelCompensationSet( This, useLevelCompensation_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMDeviceLevel2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMDeviceLevel2_h__
