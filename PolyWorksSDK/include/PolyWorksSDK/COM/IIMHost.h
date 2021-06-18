/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:51 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMHost.idl:
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

#ifndef __IIMHost_h__
#define __IIMHost_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMHost_FWD_DEFINED__
#define __IIMHost_FWD_DEFINED__
typedef interface IIMHost IIMHost;
#endif  /* __IIMHost_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMSharedMatrix.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMHost_INTERFACE_DEFINED__
#define __IIMHost_INTERFACE_DEFINED__

/* interface IIMHost */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMHost;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb3-0fad-11d8-93da-00b0d0224d3a" )
IIMHost : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE HostNameGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE HostVersionGet(
        /* [out][in] */ long* pMajor_,
        /* [out][in] */ long* pMinor_,
        /* [out][in] */ long* pDot_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixRepositoryGet(
        /* [out][in] */ IIMSharedMatrixRepository * *ppSharedMatrixRepository_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE WindowStyleSet(
        /* [in] */ long* windowHandle_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMHostVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMHost * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMHost * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMHost * This );

    HRESULT( STDMETHODCALLTYPE * HostNameGet )(
        IIMHost * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * HostVersionGet )(
        IIMHost * This,
        /* [out][in] */ long* pMajor_,
        /* [out][in] */ long* pMinor_,
        /* [out][in] */ long* pDot_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixRepositoryGet )(
        IIMHost * This,
        /* [out][in] */ IIMSharedMatrixRepository** ppSharedMatrixRepository_ );

    HRESULT( STDMETHODCALLTYPE * WindowStyleSet )(
        IIMHost * This,
        /* [in] */ long* windowHandle_ );

    END_INTERFACE
} IIMHostVtbl;

interface IIMHost
{
    CONST_VTBL struct IIMHostVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMHost_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMHost_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMHost_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMHost_HostNameGet( This, pName_ )    \
    ( ( This )->lpVtbl->HostNameGet( This, pName_ ) )

#define IIMHost_HostVersionGet( This, pMajor_, pMinor_, pDot_ )  \
    ( ( This )->lpVtbl->HostVersionGet( This, pMajor_, pMinor_, pDot_ ) )

#define IIMHost_SharedMatrixRepositoryGet( This, ppSharedMatrixRepository_ )   \
    ( ( This )->lpVtbl->SharedMatrixRepositoryGet( This, ppSharedMatrixRepository_ ) )

#define IIMHost_WindowStyleSet( This, windowHandle_ )  \
    ( ( This )->lpVtbl->WindowStyleSet( This, windowHandle_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMHost_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMHost_h__
