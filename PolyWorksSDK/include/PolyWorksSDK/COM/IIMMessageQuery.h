/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:41 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMMessageQuery.idl:
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

#ifndef __IIMMessageQuery_h__
#define __IIMMessageQuery_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMMessageQuery_FWD_DEFINED__
#define __IIMMessageQuery_FWD_DEFINED__
typedef interface IIMMessageQuery IIMMessageQuery;
#endif  /* __IIMMessageQuery_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMMessageQuery_INTERFACE_DEFINED__
#define __IIMMessageQuery_INTERFACE_DEFINED__

/* interface IIMMessageQuery */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMMessageQuery;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "FDC1766E-E9BA-4b83-8AA8-3F25037FA2CF" )
IIMMessageQuery : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE AutoCloseConditionMet(
        /* [retval][out] */ VARIANT_BOOL * pShouldBeClosed_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMMessageQueryVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMMessageQuery * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMMessageQuery * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMMessageQuery * This );

    HRESULT( STDMETHODCALLTYPE * AutoCloseConditionMet )(
        IIMMessageQuery * This,
        /* [retval][out] */ VARIANT_BOOL* pShouldBeClosed_ );

    END_INTERFACE
} IIMMessageQueryVtbl;

interface IIMMessageQuery
{
    CONST_VTBL struct IIMMessageQueryVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMMessageQuery_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMMessageQuery_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMMessageQuery_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMMessageQuery_AutoCloseConditionMet( This, pShouldBeClosed_ )    \
    ( ( This )->lpVtbl->AutoCloseConditionMet( This, pShouldBeClosed_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMMessageQuery_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMMessageQuery_h__
