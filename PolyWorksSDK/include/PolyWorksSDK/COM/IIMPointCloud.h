/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:50 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMPointCloud.idl:
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

#ifndef __IIMPointCloud_h__
#define __IIMPointCloud_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPointCloud_FWD_DEFINED__
#define __IIMPointCloud_FWD_DEFINED__
typedef interface IIMPointCloud IIMPointCloud;
#endif  /* __IIMPointCloud_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPointCloud_INTERFACE_DEFINED__
#define __IIMPointCloud_INTERFACE_DEFINED__

/* interface IIMPointCloud */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPointCloud;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "159faa0c-1461-11d7-9397-00b0d0224d3a" )
IIMPointCloud : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE PointsAdd(
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayColors_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PointsGetNb(
        /* [retval][out] */ long* pNbPoints_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPointCloudVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPointCloud * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPointCloud * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPointCloud * This );

    HRESULT( STDMETHODCALLTYPE * PointsAdd )(
        IIMPointCloud * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY** pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY** pArrayColors_ );

    HRESULT( STDMETHODCALLTYPE * PointsGetNb )(
        IIMPointCloud * This,
        /* [retval][out] */ long* pNbPoints_ );

    END_INTERFACE
} IIMPointCloudVtbl;

interface IIMPointCloud
{
    CONST_VTBL struct IIMPointCloudVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPointCloud_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPointCloud_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPointCloud_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPointCloud_PointsAdd( This, pArrayCoords_, pArrayNormals_, pArrayColors_ )    \
    ( ( This )->lpVtbl->PointsAdd( This, pArrayCoords_, pArrayNormals_, pArrayColors_ ) )

#define IIMPointCloud_PointsGetNb( This, pNbPoints_ )  \
    ( ( This )->lpVtbl->PointsGetNb( This, pNbPoints_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPointCloud_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPointCloud_h__
