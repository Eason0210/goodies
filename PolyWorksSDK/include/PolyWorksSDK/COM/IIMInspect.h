/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:56 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInspect.idl:
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

#ifndef __IIMInspect_h__
#define __IIMInspect_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInspect_FWD_DEFINED__
#define __IIMInspect_FWD_DEFINED__
typedef interface IIMInspect IIMInspect;
#endif  /* __IIMInspect_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInspectProject.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInspect_INTERFACE_DEFINED__
#define __IIMInspect_INTERFACE_DEFINED__

/* interface IIMInspect */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspect;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "10976620-fc02-11d6-9394-00b0d0224d3a" )
IIMInspect : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Login(
        /* [string][in] */ const OLECHAR * pUserName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProjectGetCurrent(
        /* [out] */ IIMInspectProject * *ppIIMInspectProject_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspect * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspect * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspect * This );

    HRESULT( STDMETHODCALLTYPE * Login )(
        IIMInspect * This,
        /* [string][in] */ const OLECHAR* pUserName_ );

    HRESULT( STDMETHODCALLTYPE * ProjectGetCurrent )(
        IIMInspect * This,
        /* [out] */ IIMInspectProject** ppIIMInspectProject_ );

    END_INTERFACE
} IIMInspectVtbl;

interface IIMInspect
{
    CONST_VTBL struct IIMInspectVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspect_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspect_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspect_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspect_Login( This, pUserName_ )   \
    ( ( This )->lpVtbl->Login( This, pUserName_ ) )

#define IIMInspect_ProjectGetCurrent( This, ppIIMInspectProject_ ) \
    ( ( This )->lpVtbl->ProjectGetCurrent( This, ppIIMInspectProject_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspect_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInspect_h__
