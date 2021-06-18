/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:47 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMLanguage.idl:
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

#ifndef __IIMLanguage_h__
#define __IIMLanguage_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMLanguage_FWD_DEFINED__
#define __IIMLanguage_FWD_DEFINED__
typedef interface IIMLanguage IIMLanguage;
#endif  /* __IIMLanguage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMLanguage_INTERFACE_DEFINED__
#define __IIMLanguage_INTERFACE_DEFINED__

/* interface IIMLanguage */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMLanguage;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "A41E791A-AE01-402a-9154-EDDD9E7822FD" )
IIMLanguage : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE LanguageSet(
        /* [in] */ BSTR pLanguage_,
        /* [in] */ BSTR pFontName_,
        /* [in] */ ECharacterSets charSet_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMLanguageVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMLanguage * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMLanguage * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMLanguage * This );

    HRESULT( STDMETHODCALLTYPE * LanguageSet )(
        IIMLanguage * This,
        /* [in] */ BSTR pLanguage_,
        /* [in] */ BSTR pFontName_,
        /* [in] */ ECharacterSets charSet_ );

    END_INTERFACE
} IIMLanguageVtbl;

interface IIMLanguage
{
    CONST_VTBL struct IIMLanguageVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMLanguage_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMLanguage_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMLanguage_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMLanguage_LanguageSet( This, pLanguage_, pFontName_, charSet_ )    \
    ( ( This )->lpVtbl->LanguageSet( This, pLanguage_, pFontName_, charSet_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMLanguage_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMLanguage_h__
