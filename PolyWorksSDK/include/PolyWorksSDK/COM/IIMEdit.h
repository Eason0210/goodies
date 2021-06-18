/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:55 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMEdit.idl:
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

#ifndef __IIMEdit_h__
#define __IIMEdit_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMEdit_FWD_DEFINED__
#define __IIMEdit_FWD_DEFINED__
typedef interface IIMEdit IIMEdit;
#endif  /* __IIMEdit_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMEditProject.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMEdit_INTERFACE_DEFINED__
#define __IIMEdit_INTERFACE_DEFINED__

/* interface IIMEdit */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMEdit;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "10976625-fc02-11d6-9394-00b0d0224d3a" )
IIMEdit : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Login(
        /* [string][in] */ const OLECHAR * pUserName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProjectGetCurrent(
        /* [out] */ IIMEditProject * *ppIIMEditProject_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMEditVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMEdit * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMEdit * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMEdit * This );

    HRESULT( STDMETHODCALLTYPE * Login )(
        IIMEdit * This,
        /* [string][in] */ const OLECHAR* pUserName_ );

    HRESULT( STDMETHODCALLTYPE * ProjectGetCurrent )(
        IIMEdit * This,
        /* [out] */ IIMEditProject** ppIIMEditProject_ );

    END_INTERFACE
} IIMEditVtbl;

interface IIMEdit
{
    CONST_VTBL struct IIMEditVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMEdit_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMEdit_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMEdit_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMEdit_Login( This, pUserName_ )  \
    ( ( This )->lpVtbl->Login( This, pUserName_ ) )

#define IIMEdit_ProjectGetCurrent( This, ppIIMEditProject_ )   \
    ( ( This )->lpVtbl->ProjectGetCurrent( This, ppIIMEditProject_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMEdit_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMEdit_h__
