/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:48 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMPlugin.idl:
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

#ifndef __IIMPlugin_h__
#define __IIMPlugin_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPlugin_FWD_DEFINED__
#define __IIMPlugin_FWD_DEFINED__
typedef interface IIMPlugin IIMPlugin;
#endif  /* __IIMPlugin_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMHost.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPlugin_INTERFACE_DEFINED__
#define __IIMPlugin_INTERFACE_DEFINED__

/* interface IIMPlugin */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPlugin;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb2-0fad-11d8-93da-00b0d0224d3a" )
IIMPlugin : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE PlgNameGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PlgVersionGet(
        /* [out][in] */ long* pMajor_,
        /* [out][in] */ long* pMinor_,
        /* [out][in] */ long* pDot_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Load(
        /* [unique][in] */ IIMHost * pIIMHost_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Unload(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPluginVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPlugin * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPlugin * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPlugin * This );

    HRESULT( STDMETHODCALLTYPE * PlgNameGet )(
        IIMPlugin * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * PlgVersionGet )(
        IIMPlugin * This,
        /* [out][in] */ long* pMajor_,
        /* [out][in] */ long* pMinor_,
        /* [out][in] */ long* pDot_ );

    HRESULT( STDMETHODCALLTYPE * Load )(
        IIMPlugin * This,
        /* [unique][in] */ IIMHost* pIIMHost_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * Unload )(
        IIMPlugin * This,
        /* [retval][out] */ long* pReturnVal_ );

    END_INTERFACE
} IIMPluginVtbl;

interface IIMPlugin
{
    CONST_VTBL struct IIMPluginVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPlugin_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPlugin_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPlugin_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPlugin_PlgNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->PlgNameGet( This, pName_ ) )

#define IIMPlugin_PlgVersionGet( This, pMajor_, pMinor_, pDot_ ) \
    ( ( This )->lpVtbl->PlgVersionGet( This, pMajor_, pMinor_, pDot_ ) )

#define IIMPlugin_Load( This, pIIMHost_, pReturnVal_ )  \
    ( ( This )->lpVtbl->Load( This, pIIMHost_, pReturnVal_ ) )

#define IIMPlugin_Unload( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->Unload( This, pReturnVal_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPlugin_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPlugin_h__
