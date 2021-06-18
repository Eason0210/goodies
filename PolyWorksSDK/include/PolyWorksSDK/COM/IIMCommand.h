/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:45 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMCommand.idl:
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

#ifndef __IIMCommand_h__
#define __IIMCommand_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMCommand_FWD_DEFINED__
#define __IIMCommand_FWD_DEFINED__
typedef interface IIMCommand IIMCommand;
#endif  /* __IIMCommand_FWD_DEFINED__ */


#ifndef __IIMCommand2_FWD_DEFINED__
#define __IIMCommand2_FWD_DEFINED__
typedef interface IIMCommand2 IIMCommand2;
#endif  /* __IIMCommand2_FWD_DEFINED__ */


#ifndef __IIMCommandEnum_FWD_DEFINED__
#define __IIMCommandEnum_FWD_DEFINED__
typedef interface IIMCommandEnum IIMCommandEnum;
#endif  /* __IIMCommandEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMCommandArgument.h"
#include "IIMCommandParameter.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMCommand_INTERFACE_DEFINED__
#define __IIMCommand_INTERFACE_DEFINED__

/* interface IIMCommand */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommand;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb4-0fad-11d8-93da-00b0d0224d3a" )
IIMCommand : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CmdNameGet(
        /* [retval][out] */ BSTR * pCmdName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CmdDescGet(
        /* [retval][out] */ BSTR * pCmdDesc_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Execute(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MenuLocationGet(
        /* [retval][out] */ BSTR * pMenuPath_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MenuDescGet(
        /* [retval][out] */ BSTR * pMenuDesc_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommand * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommand * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommand * This );

    HRESULT( STDMETHODCALLTYPE * CmdNameGet )(
        IIMCommand * This,
        /* [retval][out] */ BSTR* pCmdName_ );

    HRESULT( STDMETHODCALLTYPE * CmdDescGet )(
        IIMCommand * This,
        /* [retval][out] */ BSTR* pCmdDesc_ );

    HRESULT( STDMETHODCALLTYPE * Execute )(
        IIMCommand * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MenuLocationGet )(
        IIMCommand * This,
        /* [retval][out] */ BSTR* pMenuPath_ );

    HRESULT( STDMETHODCALLTYPE * MenuDescGet )(
        IIMCommand * This,
        /* [retval][out] */ BSTR* pMenuDesc_ );

    END_INTERFACE
} IIMCommandVtbl;

interface IIMCommand
{
    CONST_VTBL struct IIMCommandVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommand_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommand_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommand_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommand_CmdNameGet( This, pCmdName_ )   \
    ( ( This )->lpVtbl->CmdNameGet( This, pCmdName_ ) )

#define IIMCommand_CmdDescGet( This, pCmdDesc_ )   \
    ( ( This )->lpVtbl->CmdDescGet( This, pCmdDesc_ ) )

#define IIMCommand_Execute( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->Execute( This, pReturnVal_ ) )

#define IIMCommand_MenuLocationGet( This, pMenuPath_ ) \
    ( ( This )->lpVtbl->MenuLocationGet( This, pMenuPath_ ) )

#define IIMCommand_MenuDescGet( This, pMenuDesc_ ) \
    ( ( This )->lpVtbl->MenuDescGet( This, pMenuDesc_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommand_INTERFACE_DEFINED__ */


#ifndef __IIMCommand2_INTERFACE_DEFINED__
#define __IIMCommand2_INTERFACE_DEFINED__

/* interface IIMCommand2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommand2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "0BFB6DE9-1BEC-49c8-A3FE-C153423FF355" )
IIMCommand2 : public IIMCommand
{
public:
    virtual HRESULT STDMETHODCALLTYPE ArgsTest(
        /* [in] */ IIMCommandArgumentEnum * pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes * pReturnCode_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CmdDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CmdIsObsolete(
        /* [out] */ VARIANT_BOOL * pIsObsolete_,
        /* [out] */ BSTR * pSupersedingCmd_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CmdNoteGet(
        /* [retval][out] */ BSTR * pCmdNote_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE Execute2(
        /* [in] */ IIMCommandArgumentEnum * pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes * pReturnCode_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamsGet(
        /* [out] */ IIMCommandParameterEnum * *pIIMCommandParameterEnum_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommand2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommand2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommand2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommand2 * This );

    HRESULT( STDMETHODCALLTYPE * CmdNameGet )(
        IIMCommand2 * This,
        /* [retval][out] */ BSTR* pCmdName_ );

    HRESULT( STDMETHODCALLTYPE * CmdDescGet )(
        IIMCommand2 * This,
        /* [retval][out] */ BSTR* pCmdDesc_ );

    HRESULT( STDMETHODCALLTYPE * Execute )(
        IIMCommand2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * MenuLocationGet )(
        IIMCommand2 * This,
        /* [retval][out] */ BSTR* pMenuPath_ );

    HRESULT( STDMETHODCALLTYPE * MenuDescGet )(
        IIMCommand2 * This,
        /* [retval][out] */ BSTR* pMenuDesc_ );

    HRESULT( STDMETHODCALLTYPE * ArgsTest )(
        IIMCommand2 * This,
        /* [in] */ IIMCommandArgumentEnum* pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

    HRESULT( STDMETHODCALLTYPE * CmdDeprecatedNamesGet )(
        IIMCommand2 * This,
        /* [out][in] */ SAFEARRAY** pNames_ );

    HRESULT( STDMETHODCALLTYPE * CmdIsObsolete )(
        IIMCommand2 * This,
        /* [out] */ VARIANT_BOOL* pIsObsolete_,
        /* [out] */ BSTR* pSupersedingCmd_ );

    HRESULT( STDMETHODCALLTYPE * CmdNoteGet )(
        IIMCommand2 * This,
        /* [retval][out] */ BSTR* pCmdNote_ );

    HRESULT( STDMETHODCALLTYPE * Execute2 )(
        IIMCommand2 * This,
        /* [in] */ IIMCommandArgumentEnum* pIIMCommandArgumentEnum_,
        /* [retval][out] */ ECommandReturnCodes* pReturnCode_ );

    HRESULT( STDMETHODCALLTYPE * ParamsGet )(
        IIMCommand2 * This,
        /* [out] */ IIMCommandParameterEnum** pIIMCommandParameterEnum_ );

    END_INTERFACE
} IIMCommand2Vtbl;

interface IIMCommand2
{
    CONST_VTBL struct IIMCommand2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommand2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommand2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommand2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommand2_CmdNameGet( This, pCmdName_ )  \
    ( ( This )->lpVtbl->CmdNameGet( This, pCmdName_ ) )

#define IIMCommand2_CmdDescGet( This, pCmdDesc_ )  \
    ( ( This )->lpVtbl->CmdDescGet( This, pCmdDesc_ ) )

#define IIMCommand2_Execute( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->Execute( This, pReturnVal_ ) )

#define IIMCommand2_MenuLocationGet( This, pMenuPath_ )    \
    ( ( This )->lpVtbl->MenuLocationGet( This, pMenuPath_ ) )

#define IIMCommand2_MenuDescGet( This, pMenuDesc_ )    \
    ( ( This )->lpVtbl->MenuDescGet( This, pMenuDesc_ ) )


#define IIMCommand2_ArgsTest( This, pIIMCommandArgumentEnum_, pReturnCode_ )    \
    ( ( This )->lpVtbl->ArgsTest( This, pIIMCommandArgumentEnum_, pReturnCode_ ) )

#define IIMCommand2_CmdDeprecatedNamesGet( This, pNames_ ) \
    ( ( This )->lpVtbl->CmdDeprecatedNamesGet( This, pNames_ ) )

#define IIMCommand2_CmdIsObsolete( This, pIsObsolete_, pSupersedingCmd_ )   \
    ( ( This )->lpVtbl->CmdIsObsolete( This, pIsObsolete_, pSupersedingCmd_ ) )

#define IIMCommand2_CmdNoteGet( This, pCmdNote_ )  \
    ( ( This )->lpVtbl->CmdNoteGet( This, pCmdNote_ ) )

#define IIMCommand2_Execute2( This, pIIMCommandArgumentEnum_, pReturnCode_ )    \
    ( ( This )->lpVtbl->Execute2( This, pIIMCommandArgumentEnum_, pReturnCode_ ) )

#define IIMCommand2_ParamsGet( This, pIIMCommandParameterEnum_ )   \
    ( ( This )->lpVtbl->ParamsGet( This, pIIMCommandParameterEnum_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommand2_INTERFACE_DEFINED__ */


#ifndef __IIMCommandEnum_INTERFACE_DEFINED__
#define __IIMCommandEnum_INTERFACE_DEFINED__

/* interface IIMCommandEnum */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandEnum;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "f0cfafb5-0fad-11d8-93da-00b0d0224d3a" )
IIMCommandEnum : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CmdsGetNb(
        /* [retval][out] */ long* pCmdNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE CmdGet(
        /* [in] */ long number_,
        /* [out] */ IIMCommand * *pIIMCommand_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandEnumVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandEnum * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandEnum * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandEnum * This );

    HRESULT( STDMETHODCALLTYPE * CmdsGetNb )(
        IIMCommandEnum * This,
        /* [retval][out] */ long* pCmdNb_ );

    HRESULT( STDMETHODCALLTYPE * CmdGet )(
        IIMCommandEnum * This,
        /* [in] */ long number_,
        /* [out] */ IIMCommand** pIIMCommand_ );

    END_INTERFACE
} IIMCommandEnumVtbl;

interface IIMCommandEnum
{
    CONST_VTBL struct IIMCommandEnumVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandEnum_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandEnum_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandEnum_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandEnum_CmdsGetNb( This, pCmdNb_ )  \
    ( ( This )->lpVtbl->CmdsGetNb( This, pCmdNb_ ) )

#define IIMCommandEnum_CmdGet( This, number_, pIIMCommand_ )    \
    ( ( This )->lpVtbl->CmdGet( This, number_, pIIMCommand_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandEnum_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMCommand_h__
