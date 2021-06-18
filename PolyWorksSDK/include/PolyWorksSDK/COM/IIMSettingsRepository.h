/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:52 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSettingsRepository.idl:
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

#ifndef __IIMSettingsRepository_h__
#define __IIMSettingsRepository_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSettingsRepository_FWD_DEFINED__
#define __IIMSettingsRepository_FWD_DEFINED__
typedef interface IIMSettingsRepository IIMSettingsRepository;
#endif  /* __IIMSettingsRepository_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSettingsRepository_INTERFACE_DEFINED__
#define __IIMSettingsRepository_INTERFACE_DEFINED__

/* interface IIMSettingsRepository */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSettingsRepository;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2FBDDDD2-7511-4cab-A78F-06B74EF5BEED" )
IIMSettingsRepository : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE DoubleValueGet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [retval][out] */ double* pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DoubleValueSet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [in] */ double value_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LongValueGet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [retval][out] */ long* pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LongValueSet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [in] */ long value_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StringValueGet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [retval][out] */ BSTR * pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE StringValueSet(
        /* [string][in] */ const OLECHAR * pOwnerID_,
        /* [string][in] */ const OLECHAR * pSettingName_,
        /* [string][in] */ const OLECHAR * pValue_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SettingsSave(
        /* [string][in] */ const OLECHAR * pOwnerID_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SettingsLoad(
        /* [string][in] */ const OLECHAR * pOwnerID_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSettingsRepositoryVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSettingsRepository * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSettingsRepository * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSettingsRepository * This );

    HRESULT( STDMETHODCALLTYPE * DoubleValueGet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [retval][out] */ double* pValue_ );

    HRESULT( STDMETHODCALLTYPE * DoubleValueSet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [in] */ double value_ );

    HRESULT( STDMETHODCALLTYPE * LongValueGet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [retval][out] */ long* pValue_ );

    HRESULT( STDMETHODCALLTYPE * LongValueSet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [in] */ long value_ );

    HRESULT( STDMETHODCALLTYPE * StringValueGet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [retval][out] */ BSTR* pValue_ );

    HRESULT( STDMETHODCALLTYPE * StringValueSet )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_,
        /* [string][in] */ const OLECHAR* pSettingName_,
        /* [string][in] */ const OLECHAR* pValue_ );

    HRESULT( STDMETHODCALLTYPE * SettingsSave )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_ );

    HRESULT( STDMETHODCALLTYPE * SettingsLoad )(
        IIMSettingsRepository * This,
        /* [string][in] */ const OLECHAR* pOwnerID_ );

    END_INTERFACE
} IIMSettingsRepositoryVtbl;

interface IIMSettingsRepository
{
    CONST_VTBL struct IIMSettingsRepositoryVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSettingsRepository_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSettingsRepository_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSettingsRepository_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSettingsRepository_DoubleValueGet( This, pOwnerID_, pSettingName_, pValue_ )  \
    ( ( This )->lpVtbl->DoubleValueGet( This, pOwnerID_, pSettingName_, pValue_ ) )

#define IIMSettingsRepository_DoubleValueSet( This, pOwnerID_, pSettingName_, value_ )   \
    ( ( This )->lpVtbl->DoubleValueSet( This, pOwnerID_, pSettingName_, value_ ) )

#define IIMSettingsRepository_LongValueGet( This, pOwnerID_, pSettingName_, pValue_ )    \
    ( ( This )->lpVtbl->LongValueGet( This, pOwnerID_, pSettingName_, pValue_ ) )

#define IIMSettingsRepository_LongValueSet( This, pOwnerID_, pSettingName_, value_ ) \
    ( ( This )->lpVtbl->LongValueSet( This, pOwnerID_, pSettingName_, value_ ) )

#define IIMSettingsRepository_StringValueGet( This, pOwnerID_, pSettingName_, pValue_ )  \
    ( ( This )->lpVtbl->StringValueGet( This, pOwnerID_, pSettingName_, pValue_ ) )

#define IIMSettingsRepository_StringValueSet( This, pOwnerID_, pSettingName_, pValue_ )  \
    ( ( This )->lpVtbl->StringValueSet( This, pOwnerID_, pSettingName_, pValue_ ) )

#define IIMSettingsRepository_SettingsSave( This, pOwnerID_ )  \
    ( ( This )->lpVtbl->SettingsSave( This, pOwnerID_ ) )

#define IIMSettingsRepository_SettingsLoad( This, pOwnerID_ )  \
    ( ( This )->lpVtbl->SettingsLoad( This, pOwnerID_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSettingsRepository_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSettingsRepository_h__
