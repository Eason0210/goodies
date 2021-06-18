/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Fri Aug 15 13:46:33 2014
 */
/* Compiler settings for ..\..\Interfaces\IIMScanningProfilesUser.idl:
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

#ifndef __IIMScanningProfilesUser_h__
#define __IIMScanningProfilesUser_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanningProfilesUser_FWD_DEFINED__
#define __IIMScanningProfilesUser_FWD_DEFINED__
typedef interface IIMScanningProfilesUser IIMScanningProfilesUser;
#endif  /* __IIMScanningProfilesUser_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanningProfilesUser_INTERFACE_DEFINED__
#define __IIMScanningProfilesUser_INTERFACE_DEFINED__

/* interface IIMScanningProfilesUser */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanningProfilesUser;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "45C5D8F9-033A-4572-ABFC-875C713B2921" )
IIMScanningProfilesUser : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningProfileSettingsGet(
        /* [out][in] */ SAFEARRAY * *pProfileSettings_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardScanningProfileDoubleSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ double* pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardScanningProfileLongSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ long* pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StandardScanningProfileStringSettingValueGet(
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ BSTR * pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningProfilesSet(
        /* [in] */ SAFEARRAY * *pCmdArgNames_,
        /* [in] */ SAFEARRAY * *pDisplayNames_,
        /* [in] */ SAFEARRAY * *pInfos_,
        /* [in] */ BSTR current_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScanningProfilesUserVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanningProfilesUser * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanningProfilesUser * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanningProfilesUser * This );

    HRESULT( STDMETHODCALLTYPE * ScanningProfileSettingsGet )(
        IIMScanningProfilesUser * This,
        /* [out][in] */ SAFEARRAY** pProfileSettings_ );

    HRESULT( STDMETHODCALLTYPE * StandardScanningProfileDoubleSettingValueGet )(
        IIMScanningProfilesUser * This,
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ double* pValue_ );

    HRESULT( STDMETHODCALLTYPE * StandardScanningProfileLongSettingValueGet )(
        IIMScanningProfilesUser * This,
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ long* pValue_ );

    HRESULT( STDMETHODCALLTYPE * StandardScanningProfileStringSettingValueGet )(
        IIMScanningProfilesUser * This,
        /* [in] */ EStandardScanningProfiles standardProfile_,
        /* [in] */ BSTR setting_,
        /* [out] */ BSTR* pValue_ );

    HRESULT( STDMETHODCALLTYPE * ScanningProfilesSet )(
        IIMScanningProfilesUser * This,
        /* [in] */ SAFEARRAY** pCmdArgNames_,
        /* [in] */ SAFEARRAY** pDisplayNames_,
        /* [in] */ SAFEARRAY** pInfos_,
        /* [in] */ BSTR current_ );

    END_INTERFACE
} IIMScanningProfilesUserVtbl;

interface IIMScanningProfilesUser
{
    CONST_VTBL struct IIMScanningProfilesUserVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanningProfilesUser_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanningProfilesUser_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanningProfilesUser_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanningProfilesUser_ScanningProfileSettingsGet( This, pProfileSettings_ )  \
    ( ( This )->lpVtbl->ScanningProfileSettingsGet( This, pProfileSettings_ ) )

#define IIMScanningProfilesUser_StandardScanningProfileDoubleSettingValueGet( This, standardProfile_, setting_, pValue_ )    \
    ( ( This )->lpVtbl->StandardScanningProfileDoubleSettingValueGet( This, standardProfile_, setting_, pValue_ ) )

#define IIMScanningProfilesUser_StandardScanningProfileLongSettingValueGet( This, standardProfile_, setting_, pValue_ )  \
    ( ( This )->lpVtbl->StandardScanningProfileLongSettingValueGet( This, standardProfile_, setting_, pValue_ ) )

#define IIMScanningProfilesUser_StandardScanningProfileStringSettingValueGet( This, standardProfile_, setting_, pValue_ )    \
    ( ( This )->lpVtbl->StandardScanningProfileStringSettingValueGet( This, standardProfile_, setting_, pValue_ ) )

#define IIMScanningProfilesUser_ScanningProfilesSet( This, pCmdArgNames_, pDisplayNames_, pInfos_, current_ ) \
    ( ( This )->lpVtbl->ScanningProfilesSet( This, pCmdArgNames_, pDisplayNames_, pInfos_, current_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanningProfilesUser_INTERFACE_DEFINED__ */


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

#endif // ifndef __IIMScanningProfilesUser_h__
