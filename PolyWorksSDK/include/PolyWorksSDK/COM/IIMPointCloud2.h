/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jul 17 08:46:13 2014
 */
/* Compiler settings for ..\..\Interfaces\IIMPointCloud2.idl:
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

#ifndef __IIMPointCloud2_h__
#define __IIMPointCloud2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPointCloud2_FWD_DEFINED__
#define __IIMPointCloud2_FWD_DEFINED__
typedef interface IIMPointCloud2 IIMPointCloud2;
#endif  /* __IIMPointCloud2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMPointCloud.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPointCloud2_INTERFACE_DEFINED__
#define __IIMPointCloud2_INTERFACE_DEFINED__

/* interface IIMPointCloud2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPointCloud2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "C74D1680-59A5-4FF9-9FC2-188FB8B37BAF" )
IIMPointCloud2 : public IIMPointCloud
{
public:
    virtual HRESULT STDMETHODCALLTYPE PointsAdd2(
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayColors_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayTimestamps_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayApproachDirs_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPointCloud2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPointCloud2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPointCloud2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPointCloud2 * This );

    HRESULT( STDMETHODCALLTYPE * PointsAdd )(
        IIMPointCloud2 * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY** pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY** pArrayColors_ );

    HRESULT( STDMETHODCALLTYPE * PointsGetNb )(
        IIMPointCloud2 * This,
        /* [retval][out] */ long* pNbPoints_ );

    HRESULT( STDMETHODCALLTYPE * PointsAdd2 )(
        IIMPointCloud2 * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY** pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY** pArrayColors_,
        /* [full][unique][in] */ SAFEARRAY** pArrayTimestamps_,
        /* [full][unique][in] */ SAFEARRAY** pArrayApproachDirs_ );

    END_INTERFACE
} IIMPointCloud2Vtbl;

interface IIMPointCloud2
{
    CONST_VTBL struct IIMPointCloud2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPointCloud2_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPointCloud2_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPointCloud2_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPointCloud2_PointsAdd( This, pArrayCoords_, pArrayNormals_, pArrayColors_ )   \
    ( ( This )->lpVtbl->PointsAdd( This, pArrayCoords_, pArrayNormals_, pArrayColors_ ) )

#define IIMPointCloud2_PointsGetNb( This, pNbPoints_ ) \
    ( ( This )->lpVtbl->PointsGetNb( This, pNbPoints_ ) )


#define IIMPointCloud2_PointsAdd2( This, pArrayCoords_, pArrayNormals_, pArrayColors_, pArrayTimestamps_, pArrayApproachDirs_ )    \
    ( ( This )->lpVtbl->PointsAdd2( This, pArrayCoords_, pArrayNormals_, pArrayColors_, pArrayTimestamps_, pArrayApproachDirs_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPointCloud2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPointCloud2_h__
