/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:52 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMDeviceCamera.idl:
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

#ifndef __IIMDeviceCamera_h__
#define __IIMDeviceCamera_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMDeviceCamera_FWD_DEFINED__
#define __IIMDeviceCamera_FWD_DEFINED__
typedef interface IIMDeviceCamera IIMDeviceCamera;
#endif  /* __IIMDeviceCamera_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMDeviceCameraFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMDeviceCamera_INTERFACE_DEFINED__
#define __IIMDeviceCamera_INTERFACE_DEFINED__

/* interface IIMDeviceCamera */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMDeviceCamera;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "58E47F50-00C5-4725-90FF-98218D02B39D" )
IIMDeviceCamera : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE HasCamera(
        /* [retval][out] */ VARIANT_BOOL * pHasCamera_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraActivationStateGet(
        /* [retval][out] */ VARIANT_BOOL * pActivationState_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraActivationStateSet(
        /* [in] */ VARIANT_BOOL activationState_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewDlgShow( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewDlgClose( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewIsClickBehaviorSupported(
        /* [in] */ ECameraViewClickBehavior clickBehavior_,
        /* [retval][out] */ VARIANT_BOOL * pIsSupported_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewClickBehaviorGet(
        /* [retval][out] */ ECameraViewClickBehavior * pClickBehavior_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewClickBehaviorSet(
        /* [in] */ ECameraViewClickBehavior clickBehavior_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMDeviceCameraVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMDeviceCamera * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMDeviceCamera * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMDeviceCamera * This );

    HRESULT( STDMETHODCALLTYPE * HasCamera )(
        IIMDeviceCamera * This,
        /* [retval][out] */ VARIANT_BOOL* pHasCamera_ );

    HRESULT( STDMETHODCALLTYPE * CameraActivationStateGet )(
        IIMDeviceCamera * This,
        /* [retval][out] */ VARIANT_BOOL* pActivationState_ );

    HRESULT( STDMETHODCALLTYPE * CameraActivationStateSet )(
        IIMDeviceCamera * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * CameraViewDlgShow )(
        IIMDeviceCamera * This );

    HRESULT( STDMETHODCALLTYPE * CameraViewDlgClose )(
        IIMDeviceCamera * This );

    HRESULT( STDMETHODCALLTYPE * CameraViewIsClickBehaviorSupported )(
        IIMDeviceCamera * This,
        /* [in] */ ECameraViewClickBehavior clickBehavior_,
        /* [retval][out] */ VARIANT_BOOL* pIsSupported_ );

    HRESULT( STDMETHODCALLTYPE * CameraViewClickBehaviorGet )(
        IIMDeviceCamera * This,
        /* [retval][out] */ ECameraViewClickBehavior* pClickBehavior_ );

    HRESULT( STDMETHODCALLTYPE * CameraViewClickBehaviorSet )(
        IIMDeviceCamera * This,
        /* [in] */ ECameraViewClickBehavior clickBehavior_ );

    END_INTERFACE
} IIMDeviceCameraVtbl;

interface IIMDeviceCamera
{
    CONST_VTBL struct IIMDeviceCameraVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMDeviceCamera_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMDeviceCamera_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMDeviceCamera_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMDeviceCamera_HasCamera( This, pHasCamera_ ) \
    ( ( This )->lpVtbl->HasCamera( This, pHasCamera_ ) )

#define IIMDeviceCamera_CameraActivationStateGet( This, pActivationState_ )    \
    ( ( This )->lpVtbl->CameraActivationStateGet( This, pActivationState_ ) )

#define IIMDeviceCamera_CameraActivationStateSet( This, activationState_ ) \
    ( ( This )->lpVtbl->CameraActivationStateSet( This, activationState_ ) )

#define IIMDeviceCamera_CameraViewDlgShow( This ) \
    ( ( This )->lpVtbl->CameraViewDlgShow( This ) )

#define IIMDeviceCamera_CameraViewDlgClose( This )    \
    ( ( This )->lpVtbl->CameraViewDlgClose( This ) )

#define IIMDeviceCamera_CameraViewIsClickBehaviorSupported( This, clickBehavior_, pIsSupported_ )   \
    ( ( This )->lpVtbl->CameraViewIsClickBehaviorSupported( This, clickBehavior_, pIsSupported_ ) )

#define IIMDeviceCamera_CameraViewClickBehaviorGet( This, pClickBehavior_ )    \
    ( ( This )->lpVtbl->CameraViewClickBehaviorGet( This, pClickBehavior_ ) )

#define IIMDeviceCamera_CameraViewClickBehaviorSet( This, clickBehavior_ ) \
    ( ( This )->lpVtbl->CameraViewClickBehaviorSet( This, clickBehavior_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMDeviceCamera_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMDeviceCamera_h__
