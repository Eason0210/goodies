/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:40 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMMessageCenter.idl:
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

#ifndef __IIMMessageCenter_h__
#define __IIMMessageCenter_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMMessageCenter_FWD_DEFINED__
#define __IIMMessageCenter_FWD_DEFINED__
typedef interface IIMMessageCenter IIMMessageCenter;
#endif  /* __IIMMessageCenter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMMessageQuery.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMMessageCenter_INTERFACE_DEFINED__
#define __IIMMessageCenter_INTERFACE_DEFINED__

/* interface IIMMessageCenter */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMMessageCenter;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "395CB4F7-4ADF-41f6-9CC1-C0ABE2B6054A" )
IIMMessageCenter : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE MessageBox(
        /* [in] */ EMessageTypes type_,
        /* [in] */ BSTR pMessage_,
        /* [defaultvalue][in] */ BSTR pDetails_                      = L"",
        /* [defaultvalue][in] */ BSTR pTitle_                        = L"",
        /* [defaultvalue][in] */ long parentWindowHandle_            = 0,
        /* [defaultvalue][in] */ VARIANT_BOOL blocking_              = ( VARIANT_BOOL )-1,
        /* [defaultvalue][in] */ IIMMessageQuery * pIIMMessageQuery_ = 0,
        /* [defaultvalue][in] */ long defaultButtonId_               = 0,
        /* [defaultvalue][retval][out] */ long* pSelectedButtonId_   = 0 ) = 0;

};

#else   /* C style interface */

typedef struct IIMMessageCenterVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMMessageCenter * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMMessageCenter * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMMessageCenter * This );

    HRESULT( STDMETHODCALLTYPE * MessageBox )(
        IIMMessageCenter * This,
        /* [in] */ EMessageTypes type_,
        /* [in] */ BSTR pMessage_,
        /* [defaultvalue][in] */ BSTR pDetails_,
        /* [defaultvalue][in] */ BSTR pTitle_,
        /* [defaultvalue][in] */ long parentWindowHandle_,
        /* [defaultvalue][in] */ VARIANT_BOOL blocking_,
        /* [defaultvalue][in] */ IIMMessageQuery* pIIMMessageQuery_,
        /* [defaultvalue][in] */ long defaultButtonId_,
        /* [defaultvalue][retval][out] */ long* pSelectedButtonId_ );

    END_INTERFACE
} IIMMessageCenterVtbl;

interface IIMMessageCenter
{
    CONST_VTBL struct IIMMessageCenterVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMMessageCenter_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMMessageCenter_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMMessageCenter_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMMessageCenter_MessageBox( This, type_, pMessage_, pDetails_, pTitle_, parentWindowHandle_, blocking_, pIIMMessageQuery_, defaultButtonId_, pSelectedButtonId_ ) \
    ( ( This )->lpVtbl->MessageBox( This, type_, pMessage_, pDetails_, pTitle_, parentWindowHandle_, blocking_, pIIMMessageQuery_, defaultButtonId_, pSelectedButtonId_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMMessageCenter_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMMessageCenter_h__
