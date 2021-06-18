﻿/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:43 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMRealTimeInspector.idl:
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

#ifndef __IIMRealTimeInspector_h__
#define __IIMRealTimeInspector_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMRealTimeInspector_FWD_DEFINED__
#define __IIMRealTimeInspector_FWD_DEFINED__
typedef interface IIMRealTimeInspector IIMRealTimeInspector;
#endif  /* __IIMRealTimeInspector_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMRealTimeInspector_INTERFACE_DEFINED__
#define __IIMRealTimeInspector_INTERFACE_DEFINED__

/* interface IIMRealTimeInspector */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMRealTimeInspector;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "1EE5AD8B-D95C-11d7-93CE-00B0D0224D3A" )
IIMRealTimeInspector : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE RealTimeInspectionEnable(
        /* [in] */ VARIANT_BOOL inspectionState_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMRealTimeInspectorVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMRealTimeInspector * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMRealTimeInspector * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMRealTimeInspector * This );

    HRESULT( STDMETHODCALLTYPE * RealTimeInspectionEnable )(
        IIMRealTimeInspector * This,
        /* [in] */ VARIANT_BOOL inspectionState_,
        /* [retval][out] */ long* pReturnVal_ );

    END_INTERFACE
} IIMRealTimeInspectorVtbl;

interface IIMRealTimeInspector
{
    CONST_VTBL struct IIMRealTimeInspectorVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMRealTimeInspector_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMRealTimeInspector_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMRealTimeInspector_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMRealTimeInspector_RealTimeInspectionEnable( This, inspectionState_, pReturnVal_ )    \
    ( ( This )->lpVtbl->RealTimeInspectionEnable( This, inspectionState_, pReturnVal_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMRealTimeInspector_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMRealTimeInspector_h__
