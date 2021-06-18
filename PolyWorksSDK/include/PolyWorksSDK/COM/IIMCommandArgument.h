/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:46 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMCommandArgument.idl:
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

#ifndef __IIMCommandArgument_h__
#define __IIMCommandArgument_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMCommandArgument_FWD_DEFINED__
#define __IIMCommandArgument_FWD_DEFINED__
typedef interface IIMCommandArgument IIMCommandArgument;
#endif  /* __IIMCommandArgument_FWD_DEFINED__ */


#ifndef __IIMCommandArgumentEnum_FWD_DEFINED__
#define __IIMCommandArgumentEnum_FWD_DEFINED__
typedef interface IIMCommandArgumentEnum IIMCommandArgumentEnum;
#endif  /* __IIMCommandArgumentEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMCommandArgument_INTERFACE_DEFINED__
#define __IIMCommandArgument_INTERFACE_DEFINED__

/* interface IIMCommandArgument */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandArgument;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb6-0fad-11d8-93da-00b0d0224d3a" )
IIMCommandArgument : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ArgValuesGetNb(
        /* [retval][out] */ long* pNbArgValues_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueGetType(
        /* [in] */ long index_,
        /* [retval][out] */ EArgumentValueType * pArgValueType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueGetAsDouble(
        /* [in] */ long index_,
        /* [out] */ double* pArgValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueSetFromDouble(
        /* [in] */ long index_,
        /* [in] */ double argValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueGetAsInt(
        /* [in] */ long index_,
        /* [out] */ int* pArgValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueSetFromInt(
        /* [in] */ long index_,
        /* [in] */ int argValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueGetAsString(
        /* [in] */ long index_,
        /* [out] */ BSTR * pArgValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgValueSetFromString(
        /* [in] */ long index_,
        /* [full][unique][string][in] */ const OLECHAR * argValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandArgumentVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandArgument * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandArgument * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandArgument * This );

    HRESULT( STDMETHODCALLTYPE * ArgValuesGetNb )(
        IIMCommandArgument * This,
        /* [retval][out] */ long* pNbArgValues_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueGetType )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [retval][out] */ EArgumentValueType* pArgValueType_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueGetAsDouble )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [out] */ double* pArgValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueSetFromDouble )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [in] */ double argValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueGetAsInt )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [out] */ int* pArgValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueSetFromInt )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [in] */ int argValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueGetAsString )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [out] */ BSTR* pArgValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ArgValueSetFromString )(
        IIMCommandArgument * This,
        /* [in] */ long index_,
        /* [full][unique][string][in] */ const OLECHAR* argValue_,
        /* [retval][out] */ long* pReturnVal_ );

    END_INTERFACE
} IIMCommandArgumentVtbl;

interface IIMCommandArgument
{
    CONST_VTBL struct IIMCommandArgumentVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandArgument_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandArgument_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandArgument_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandArgument_ArgValuesGetNb( This, pNbArgValues_ )   \
    ( ( This )->lpVtbl->ArgValuesGetNb( This, pNbArgValues_ ) )

#define IIMCommandArgument_ArgValueGetType( This, index_, pArgValueType_ )  \
    ( ( This )->lpVtbl->ArgValueGetType( This, index_, pArgValueType_ ) )

#define IIMCommandArgument_ArgValueGetAsDouble( This, index_, pArgValue_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ArgValueGetAsDouble( This, index_, pArgValue_, pReturnVal_ ) )

#define IIMCommandArgument_ArgValueSetFromDouble( This, index_, argValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ArgValueSetFromDouble( This, index_, argValue_, pReturnVal_ ) )

#define IIMCommandArgument_ArgValueGetAsInt( This, index_, pArgValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ArgValueGetAsInt( This, index_, pArgValue_, pReturnVal_ ) )

#define IIMCommandArgument_ArgValueSetFromInt( This, index_, argValue_, pReturnVal_ )    \
    ( ( This )->lpVtbl->ArgValueSetFromInt( This, index_, argValue_, pReturnVal_ ) )

#define IIMCommandArgument_ArgValueGetAsString( This, index_, pArgValue_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ArgValueGetAsString( This, index_, pArgValue_, pReturnVal_ ) )

#define IIMCommandArgument_ArgValueSetFromString( This, index_, argValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ArgValueSetFromString( This, index_, argValue_, pReturnVal_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandArgument_INTERFACE_DEFINED__ */


#ifndef __IIMCommandArgumentEnum_INTERFACE_DEFINED__
#define __IIMCommandArgumentEnum_INTERFACE_DEFINED__

/* interface IIMCommandArgumentEnum */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandArgumentEnum;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb7-0fad-11d8-93da-00b0d0224d3a" )
IIMCommandArgumentEnum : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ArgsGetNb(
        /* [retval][out] */ long* pArgNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ArgGet(
        /* [in] */ long number_,
        /* [out] */ IIMCommandArgument * *pIIMCommandArgument_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandArgumentEnumVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandArgumentEnum * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandArgumentEnum * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandArgumentEnum * This );

    HRESULT( STDMETHODCALLTYPE * ArgsGetNb )(
        IIMCommandArgumentEnum * This,
        /* [retval][out] */ long* pArgNb_ );

    HRESULT( STDMETHODCALLTYPE * ArgGet )(
        IIMCommandArgumentEnum * This,
        /* [in] */ long number_,
        /* [out] */ IIMCommandArgument** pIIMCommandArgument_ );

    END_INTERFACE
} IIMCommandArgumentEnumVtbl;

interface IIMCommandArgumentEnum
{
    CONST_VTBL struct IIMCommandArgumentEnumVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandArgumentEnum_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandArgumentEnum_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandArgumentEnum_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandArgumentEnum_ArgsGetNb( This, pArgNb_ )  \
    ( ( This )->lpVtbl->ArgsGetNb( This, pArgNb_ ) )

#define IIMCommandArgumentEnum_ArgGet( This, number_, pIIMCommandArgument_ )    \
    ( ( This )->lpVtbl->ArgGet( This, number_, pIIMCommandArgument_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandArgumentEnum_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMCommandArgument_h__
