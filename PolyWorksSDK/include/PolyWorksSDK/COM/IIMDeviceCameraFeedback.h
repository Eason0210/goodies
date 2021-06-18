/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:53 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMDeviceCameraFeedback.idl:
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

#ifndef __IIMDeviceCameraFeedback_h__
#define __IIMDeviceCameraFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMDeviceCameraFeedback_FWD_DEFINED__
#define __IIMDeviceCameraFeedback_FWD_DEFINED__
typedef interface IIMDeviceCameraFeedback IIMDeviceCameraFeedback;
#endif  /* __IIMDeviceCameraFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMDeviceCameraFeedback_INTERFACE_DEFINED__
#define __IIMDeviceCameraFeedback_INTERFACE_DEFINED__

/* interface IIMDeviceCameraFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMDeviceCameraFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "544B5E59-3CBF-41b7-A6E6-8039F9C5A9F6" )
IIMDeviceCameraFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CameraActivationStateSet(
        /* [in] */ VARIANT_BOOL activationState_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewHandleSet(
        /* [in] */ long cameraViewHandle_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewDlgClosed( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CameraViewClickBehaviorSet(
        /* [in] */ ECameraViewClickBehavior clickBehavior_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMDeviceCameraFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMDeviceCameraFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMDeviceCameraFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMDeviceCameraFeedback * This );

    HRESULT( STDMETHODCALLTYPE * CameraActivationStateSet )(
        IIMDeviceCameraFeedback * This,
        /* [in] */ VARIANT_BOOL activationState_ );

    HRESULT( STDMETHODCALLTYPE * CameraViewHandleSet )(
        IIMDeviceCameraFeedback * This,
        /* [in] */ long cameraViewHandle_ );

    HRESULT( STDMETHODCALLTYPE * CameraViewDlgClosed )(
        IIMDeviceCameraFeedback * This );

    HRESULT( STDMETHODCALLTYPE * CameraViewClickBehaviorSet )(
        IIMDeviceCameraFeedback * This,
        /* [in] */ ECameraViewClickBehavior clickBehavior_ );

    END_INTERFACE
} IIMDeviceCameraFeedbackVtbl;

interface IIMDeviceCameraFeedback
{
    CONST_VTBL struct IIMDeviceCameraFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMDeviceCameraFeedback_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMDeviceCameraFeedback_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMDeviceCameraFeedback_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMDeviceCameraFeedback_CameraActivationStateSet( This, activationState_ ) \
    ( ( This )->lpVtbl->CameraActivationStateSet( This, activationState_ ) )

#define IIMDeviceCameraFeedback_CameraViewHandleSet( This, cameraViewHandle_ ) \
    ( ( This )->lpVtbl->CameraViewHandleSet( This, cameraViewHandle_ ) )

#define IIMDeviceCameraFeedback_CameraViewDlgClosed( This )   \
    ( ( This )->lpVtbl->CameraViewDlgClosed( This ) )

#define IIMDeviceCameraFeedback_CameraViewClickBehaviorSet( This, clickBehavior_ ) \
    ( ( This )->lpVtbl->CameraViewClickBehaviorSet( This, clickBehavior_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMDeviceCameraFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMDeviceCameraFeedback_h__
