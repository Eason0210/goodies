/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:49 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSettings.idl:
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

#ifndef __IIMSettings_h__
#define __IIMSettings_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSettings_FWD_DEFINED__
#define __IIMSettings_FWD_DEFINED__
typedef interface IIMSettings IIMSettings;
#endif  /* __IIMSettings_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSettings_INTERFACE_DEFINED__
#define __IIMSettings_INTERFACE_DEFINED__

/* interface IIMSettings */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSettings;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "81F17600-DA06-492a-B9A4-588307387424" )
IIMSettings : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE DoubleSettingsNbGet(
        /* [retval][out] */ long* nbSettings_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DoubleSettingGet(
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR * pSettingName_,
        /* [out][in] */ double* pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL * pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsProjectSetting_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LongSettingsNbGet(
        /* [retval][out] */ long* nbSettings_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LongSettingGet(
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR * pSettingName_,
        /* [out][in] */ long* pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL * pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsProjectSetting_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StringSettingsNbGet(
        /* [retval][out] */ long* nbSettings_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StringSettingGet(
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR * pSettingName_,
        /* [out][in] */ BSTR * pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL * pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL * pIsProjectSetting_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSettingsVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSettings * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSettings * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSettings * This );

    HRESULT( STDMETHODCALLTYPE * DoubleSettingsNbGet )(
        IIMSettings * This,
        /* [retval][out] */ long* nbSettings_ );

    HRESULT( STDMETHODCALLTYPE * DoubleSettingGet )(
        IIMSettings * This,
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR* pSettingName_,
        /* [out][in] */ double* pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    HRESULT( STDMETHODCALLTYPE * LongSettingsNbGet )(
        IIMSettings * This,
        /* [retval][out] */ long* nbSettings_ );

    HRESULT( STDMETHODCALLTYPE * LongSettingGet )(
        IIMSettings * This,
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR* pSettingName_,
        /* [out][in] */ long* pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    HRESULT( STDMETHODCALLTYPE * StringSettingsNbGet )(
        IIMSettings * This,
        /* [retval][out] */ long* nbSettings_ );

    HRESULT( STDMETHODCALLTYPE * StringSettingGet )(
        IIMSettings * This,
        /* [in] */ long settingIndex_,
        /* [out][in] */ BSTR* pSettingName_,
        /* [out][in] */ BSTR* pDefaultValue_,
        /* [out][in] */ VARIANT_BOOL* pIsUserSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsHostSpecific_,
        /* [out][in] */ VARIANT_BOOL* pIsProjectSetting_ );

    END_INTERFACE
} IIMSettingsVtbl;

interface IIMSettings
{
    CONST_VTBL struct IIMSettingsVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSettings_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSettings_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSettings_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSettings_DoubleSettingsNbGet( This, nbSettings_ )   \
    ( ( This )->lpVtbl->DoubleSettingsNbGet( This, nbSettings_ ) )

#define IIMSettings_DoubleSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ )  \
    ( ( This )->lpVtbl->DoubleSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ ) )

#define IIMSettings_LongSettingsNbGet( This, nbSettings_ ) \
    ( ( This )->lpVtbl->LongSettingsNbGet( This, nbSettings_ ) )

#define IIMSettings_LongSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ )    \
    ( ( This )->lpVtbl->LongSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ ) )

#define IIMSettings_StringSettingsNbGet( This, nbSettings_ )   \
    ( ( This )->lpVtbl->StringSettingsNbGet( This, nbSettings_ ) )

#define IIMSettings_StringSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ )  \
    ( ( This )->lpVtbl->StringSettingGet( This, settingIndex_, pSettingName_, pDefaultValue_, pIsUserSpecific_, pIsHostSpecific_, pIsProjectSetting_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSettings_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSettings_h__
