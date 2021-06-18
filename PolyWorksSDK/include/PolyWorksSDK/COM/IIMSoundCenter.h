/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:41 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSoundCenter.idl:
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

#ifndef __IIMSoundCenter_h__
#define __IIMSoundCenter_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSoundCenter_FWD_DEFINED__
#define __IIMSoundCenter_FWD_DEFINED__
typedef interface IIMSoundCenter IIMSoundCenter;
#endif  /* __IIMSoundCenter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSoundCenter_INTERFACE_DEFINED__
#define __IIMSoundCenter_INTERFACE_DEFINED__

/* interface IIMSoundCenter */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSoundCenter;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "0CC140CC-ED2A-4790-BC63-45D2DEC439C4" )
IIMSoundCenter : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Play(
        /* [in] */ BSTR soundFileName_,
        /* [defaultvalue][in] */ VARIANT_BOOL skipDuplicates_ = ( VARIANT_BOOL )-1 ) = 0;

};

#else   /* C style interface */

typedef struct IIMSoundCenterVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSoundCenter * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSoundCenter * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSoundCenter * This );

    HRESULT( STDMETHODCALLTYPE * Play )(
        IIMSoundCenter * This,
        /* [in] */ BSTR soundFileName_,
        /* [defaultvalue][in] */ VARIANT_BOOL skipDuplicates_ );

    END_INTERFACE
} IIMSoundCenterVtbl;

interface IIMSoundCenter
{
    CONST_VTBL struct IIMSoundCenterVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSoundCenter_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSoundCenter_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSoundCenter_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSoundCenter_Play( This, soundFileName_, skipDuplicates_ )    \
    ( ( This )->lpVtbl->Play( This, soundFileName_, skipDuplicates_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSoundCenter_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSoundCenter_h__
