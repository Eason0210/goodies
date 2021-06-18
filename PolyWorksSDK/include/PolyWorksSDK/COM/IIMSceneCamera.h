/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:43 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSceneCamera.idl:
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

#ifndef __IIMSceneCamera_h__
#define __IIMSceneCamera_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSceneCamera_FWD_DEFINED__
#define __IIMSceneCamera_FWD_DEFINED__
typedef interface IIMSceneCamera IIMSceneCamera;
#endif  /* __IIMSceneCamera_FWD_DEFINED__ */


#ifndef __IIMSceneCamera2_FWD_DEFINED__
#define __IIMSceneCamera2_FWD_DEFINED__
typedef interface IIMSceneCamera2 IIMSceneCamera2;
#endif  /* __IIMSceneCamera2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSceneCamera_INTERFACE_DEFINED__
#define __IIMSceneCamera_INTERFACE_DEFINED__

/* interface IIMSceneCamera */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSceneCamera;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "D5D86100-79FF-4fed-B178-9BB55A3BBF87" )
IIMSceneCamera : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE RefreshTriggerSetTimeDelay(
        /* [in] */ long timeDelay_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ViewpointSet(
        /* [full][ref][in] */ SAFEARRAY * *viewpointVector_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ClippingPlanesOffsetSet(
        /* [in] */ double farClippingPlaneOffset_,
        /* [in] */ double nearClippingPlaneOffset_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSceneCameraVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSceneCamera * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSceneCamera * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSceneCamera * This );

    HRESULT( STDMETHODCALLTYPE * RefreshTriggerSetTimeDelay )(
        IIMSceneCamera * This,
        /* [in] */ long timeDelay_ );

    HRESULT( STDMETHODCALLTYPE * ViewpointSet )(
        IIMSceneCamera * This,
        /* [full][ref][in] */ SAFEARRAY** viewpointVector_ );

    HRESULT( STDMETHODCALLTYPE * ClippingPlanesOffsetSet )(
        IIMSceneCamera * This,
        /* [in] */ double farClippingPlaneOffset_,
        /* [in] */ double nearClippingPlaneOffset_ );

    END_INTERFACE
} IIMSceneCameraVtbl;

interface IIMSceneCamera
{
    CONST_VTBL struct IIMSceneCameraVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSceneCamera_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSceneCamera_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSceneCamera_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSceneCamera_RefreshTriggerSetTimeDelay( This, timeDelay_ )  \
    ( ( This )->lpVtbl->RefreshTriggerSetTimeDelay( This, timeDelay_ ) )

#define IIMSceneCamera_ViewpointSet( This, viewpointVector_ )  \
    ( ( This )->lpVtbl->ViewpointSet( This, viewpointVector_ ) )

#define IIMSceneCamera_ClippingPlanesOffsetSet( This, farClippingPlaneOffset_, nearClippingPlaneOffset_ )   \
    ( ( This )->lpVtbl->ClippingPlanesOffsetSet( This, farClippingPlaneOffset_, nearClippingPlaneOffset_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSceneCamera_INTERFACE_DEFINED__ */


#ifndef __IIMSceneCamera2_INTERFACE_DEFINED__
#define __IIMSceneCamera2_INTERFACE_DEFINED__

/* interface IIMSceneCamera2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSceneCamera2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "AC9E9792-8A59-4a0c-B63A-8A18E9A42C50" )
IIMSceneCamera2 : public IIMSceneCamera
{
public:
    virtual HRESULT STDMETHODCALLTYPE PositionAndOrientationSet(
        /* [in] */ double xPosition_,
        /* [in] */ double yPosition_,
        /* [in] */ double zPosition_,
        /* [in] */ double xDirection_,
        /* [in] */ double yDirection_,
        /* [in] */ double zDirection_,
        /* [in] */ double xUp_,
        /* [in] */ double yUp_,
        /* [in] */ double zUp_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PositionAndOrientationGet(
        /* [out] */ double* xPosition_,
        /* [out] */ double* yPosition_,
        /* [out] */ double* zPosition_,
        /* [out] */ double* xDirection_,
        /* [out] */ double* yDirection_,
        /* [out] */ double* zDirection_,
        /* [out] */ double* xUp_,
        /* [out] */ double* yUp_,
        /* [out] */ double* zUp_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SceneBoundingBoxGet(
        /* [out] */ double* xMin_,
        /* [out] */ double* yMin_,
        /* [out] */ double* zMin_,
        /* [out] */ double* xMax_,
        /* [out] */ double* yMax_,
        /* [out] */ double* zMax_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSceneCamera2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSceneCamera2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSceneCamera2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSceneCamera2 * This );

    HRESULT( STDMETHODCALLTYPE * RefreshTriggerSetTimeDelay )(
        IIMSceneCamera2 * This,
        /* [in] */ long timeDelay_ );

    HRESULT( STDMETHODCALLTYPE * ViewpointSet )(
        IIMSceneCamera2 * This,
        /* [full][ref][in] */ SAFEARRAY** viewpointVector_ );

    HRESULT( STDMETHODCALLTYPE * ClippingPlanesOffsetSet )(
        IIMSceneCamera2 * This,
        /* [in] */ double farClippingPlaneOffset_,
        /* [in] */ double nearClippingPlaneOffset_ );

    HRESULT( STDMETHODCALLTYPE * PositionAndOrientationSet )(
        IIMSceneCamera2 * This,
        /* [in] */ double xPosition_,
        /* [in] */ double yPosition_,
        /* [in] */ double zPosition_,
        /* [in] */ double xDirection_,
        /* [in] */ double yDirection_,
        /* [in] */ double zDirection_,
        /* [in] */ double xUp_,
        /* [in] */ double yUp_,
        /* [in] */ double zUp_ );

    HRESULT( STDMETHODCALLTYPE * PositionAndOrientationGet )(
        IIMSceneCamera2 * This,
        /* [out] */ double* xPosition_,
        /* [out] */ double* yPosition_,
        /* [out] */ double* zPosition_,
        /* [out] */ double* xDirection_,
        /* [out] */ double* yDirection_,
        /* [out] */ double* zDirection_,
        /* [out] */ double* xUp_,
        /* [out] */ double* yUp_,
        /* [out] */ double* zUp_ );

    HRESULT( STDMETHODCALLTYPE * SceneBoundingBoxGet )(
        IIMSceneCamera2 * This,
        /* [out] */ double* xMin_,
        /* [out] */ double* yMin_,
        /* [out] */ double* zMin_,
        /* [out] */ double* xMax_,
        /* [out] */ double* yMax_,
        /* [out] */ double* zMax_ );

    END_INTERFACE
} IIMSceneCamera2Vtbl;

interface IIMSceneCamera2
{
    CONST_VTBL struct IIMSceneCamera2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSceneCamera2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSceneCamera2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSceneCamera2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSceneCamera2_RefreshTriggerSetTimeDelay( This, timeDelay_ ) \
    ( ( This )->lpVtbl->RefreshTriggerSetTimeDelay( This, timeDelay_ ) )

#define IIMSceneCamera2_ViewpointSet( This, viewpointVector_ ) \
    ( ( This )->lpVtbl->ViewpointSet( This, viewpointVector_ ) )

#define IIMSceneCamera2_ClippingPlanesOffsetSet( This, farClippingPlaneOffset_, nearClippingPlaneOffset_ )  \
    ( ( This )->lpVtbl->ClippingPlanesOffsetSet( This, farClippingPlaneOffset_, nearClippingPlaneOffset_ ) )


#define IIMSceneCamera2_PositionAndOrientationSet( This, xPosition_, yPosition_, zPosition_, xDirection_, yDirection_, zDirection_, xUp_, yUp_, zUp_ ) \
    ( ( This )->lpVtbl->PositionAndOrientationSet( This, xPosition_, yPosition_, zPosition_, xDirection_, yDirection_, zDirection_, xUp_, yUp_, zUp_ ) )

#define IIMSceneCamera2_PositionAndOrientationGet( This, xPosition_, yPosition_, zPosition_, xDirection_, yDirection_, zDirection_, xUp_, yUp_, zUp_ ) \
    ( ( This )->lpVtbl->PositionAndOrientationGet( This, xPosition_, yPosition_, zPosition_, xDirection_, yDirection_, zDirection_, xUp_, yUp_, zUp_ ) )

#define IIMSceneCamera2_SceneBoundingBoxGet( This, xMin_, yMin_, zMin_, xMax_, yMax_, zMax_ )   \
    ( ( This )->lpVtbl->SceneBoundingBoxGet( This, xMin_, yMin_, zMin_, xMax_, yMax_, zMax_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSceneCamera2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSceneCamera_h__
