/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:54 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMCommandCenter.idl:
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

#ifndef __IIMCommandCenter_h__
#define __IIMCommandCenter_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMCommandCenter_FWD_DEFINED__
#define __IIMCommandCenter_FWD_DEFINED__
typedef interface IIMCommandCenter IIMCommandCenter;
#endif  /* __IIMCommandCenter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMCommandCenter_INTERFACE_DEFINED__
#define __IIMCommandCenter_INTERFACE_DEFINED__

/* interface IIMCommandCenter */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandCenter;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "214c846e-fbfd-11d6-9394-00b0d0224d3a" )
IIMCommandCenter : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CommandExecute(
        /* [string][in] */ const OLECHAR * pCommand_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReturnValueGetAsString(
        /* [in] */ long retCode_,
        /* [retval][out] */ BSTR * pStringCode_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReturnValueIsSuccess(
        /* [in] */ long retCode_,
        /* [retval][out] */ long* pIsSuccess_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptExecuteFromBuffer(
        /* [string][in] */ const OLECHAR * pScriptBuf_,
        /* [unique][string][in] */ const OLECHAR * arguments_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptExecuteFromFile(
        /* [string][in] */ const OLECHAR * pFileName_,
        /* [unique][string][in] */ const OLECHAR * arguments_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptVariableGetValueAsFloat(
        /* [string][in] */ const OLECHAR * pVarName_,
        /* [in] */ int index_,
        /* [out] */ float* pValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptVariableGetValueAsInt(
        /* [string][in] */ const OLECHAR * pVarName_,
        /* [in] */ int index_,
        /* [out] */ int* pValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptVariableGetValueAsString(
        /* [string][in] */ const OLECHAR * pVarName_,
        /* [in] */ int index_,
        /* [out] */ BSTR * pStringValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScriptVariableGetNbValues(
        /* [string][in] */ const OLECHAR * pVarName_,
        /* [retval][out] */ long* pNbValue_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandCenterVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandCenter * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandCenter * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandCenter * This );

    HRESULT( STDMETHODCALLTYPE * CommandExecute )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pCommand_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ReturnValueGetAsString )(
        IIMCommandCenter * This,
        /* [in] */ long retCode_,
        /* [retval][out] */ BSTR* pStringCode_ );

    HRESULT( STDMETHODCALLTYPE * ReturnValueIsSuccess )(
        IIMCommandCenter * This,
        /* [in] */ long retCode_,
        /* [retval][out] */ long* pIsSuccess_ );

    HRESULT( STDMETHODCALLTYPE * ScriptExecuteFromBuffer )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pScriptBuf_,
        /* [unique][string][in] */ const OLECHAR* arguments_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScriptExecuteFromFile )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pFileName_,
        /* [unique][string][in] */ const OLECHAR* arguments_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScriptVariableGetValueAsFloat )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pVarName_,
        /* [in] */ int index_,
        /* [out] */ float* pValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScriptVariableGetValueAsInt )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pVarName_,
        /* [in] */ int index_,
        /* [out] */ int* pValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScriptVariableGetValueAsString )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pVarName_,
        /* [in] */ int index_,
        /* [out] */ BSTR* pStringValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScriptVariableGetNbValues )(
        IIMCommandCenter * This,
        /* [string][in] */ const OLECHAR* pVarName_,
        /* [retval][out] */ long* pNbValue_ );

    END_INTERFACE
} IIMCommandCenterVtbl;

interface IIMCommandCenter
{
    CONST_VTBL struct IIMCommandCenterVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandCenter_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandCenter_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandCenter_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandCenter_CommandExecute( This, pCommand_, pReturnVal_ ) \
    ( ( This )->lpVtbl->CommandExecute( This, pCommand_, pReturnVal_ ) )

#define IIMCommandCenter_ReturnValueGetAsString( This, retCode_, pStringCode_ ) \
    ( ( This )->lpVtbl->ReturnValueGetAsString( This, retCode_, pStringCode_ ) )

#define IIMCommandCenter_ReturnValueIsSuccess( This, retCode_, pIsSuccess_ )    \
    ( ( This )->lpVtbl->ReturnValueIsSuccess( This, retCode_, pIsSuccess_ ) )

#define IIMCommandCenter_ScriptExecuteFromBuffer( This, pScriptBuf_, arguments_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScriptExecuteFromBuffer( This, pScriptBuf_, arguments_, pReturnVal_ ) )

#define IIMCommandCenter_ScriptExecuteFromFile( This, pFileName_, arguments_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScriptExecuteFromFile( This, pFileName_, arguments_, pReturnVal_ ) )

#define IIMCommandCenter_ScriptVariableGetValueAsFloat( This, pVarName_, index_, pValue_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScriptVariableGetValueAsFloat( This, pVarName_, index_, pValue_, pReturnVal_ ) )

#define IIMCommandCenter_ScriptVariableGetValueAsInt( This, pVarName_, index_, pValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScriptVariableGetValueAsInt( This, pVarName_, index_, pValue_, pReturnVal_ ) )

#define IIMCommandCenter_ScriptVariableGetValueAsString( This, pVarName_, index_, pStringValue_, pReturnVal_ )    \
    ( ( This )->lpVtbl->ScriptVariableGetValueAsString( This, pVarName_, index_, pStringValue_, pReturnVal_ ) )

#define IIMCommandCenter_ScriptVariableGetNbValues( This, pVarName_, pNbValue_ )    \
    ( ( This )->lpVtbl->ScriptVariableGetNbValues( This, pVarName_, pNbValue_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandCenter_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMCommandCenter_h__
