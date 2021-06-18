/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Fri Sep 07 16:23:35 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMScanningObjectsUser.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555
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

#ifndef __IIMScanningObjectsUser_h__
#define __IIMScanningObjectsUser_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanningObjectsUser_FWD_DEFINED__
#define __IIMScanningObjectsUser_FWD_DEFINED__
typedef interface IIMScanningObjectsUser IIMScanningObjectsUser;
#endif  /* __IIMScanningObjectsUser_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanningObjectsUser_INTERFACE_DEFINED__
#define __IIMScanningObjectsUser_INTERFACE_DEFINED__

/* interface IIMScanningObjectsUser */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanningObjectsUser;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "551A3132-795D-49AE-8765-882E9BD84BBE" )
IIMScanningObjectsUser : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningObjectsSet(
        /* [in] */ EScanTypes scanType_,
        /* [in] */ SAFEARRAY * *pArrayObjects_,
        /* [in] */ BSTR currentChoice_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScanningObjectsUserVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanningObjectsUser * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanningObjectsUser * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanningObjectsUser * This );

    HRESULT( STDMETHODCALLTYPE * ScanningObjectsSet )(
        IIMScanningObjectsUser * This,
        /* [in] */ EScanTypes scanType_,
        /* [in] */ SAFEARRAY** pArrayObjects_,
        /* [in] */ BSTR currentChoice_ );

    END_INTERFACE
} IIMScanningObjectsUserVtbl;

interface IIMScanningObjectsUser
{
    CONST_VTBL struct IIMScanningObjectsUserVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanningObjectsUser_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanningObjectsUser_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanningObjectsUser_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanningObjectsUser_ScanningObjectsSet( This, scanType_, pArrayObjects_, currentChoice_ ) \
    ( ( This )->lpVtbl->ScanningObjectsSet( This, scanType_, pArrayObjects_, currentChoice_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanningObjectsUser_INTERFACE_DEFINED__ */


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

#endif // ifndef __IIMScanningObjectsUser_h__
