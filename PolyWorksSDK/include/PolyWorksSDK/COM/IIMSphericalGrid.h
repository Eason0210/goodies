/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 8.00.0603 */
/* at Tue Nov 17 08:54:01 2015
 */
/* Compiler settings for ..\..\Interfaces\IIMSphericalGrid.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603
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

#ifndef __IIMSphericalGrid_h__
#define __IIMSphericalGrid_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSphericalGrid_FWD_DEFINED__
#define __IIMSphericalGrid_FWD_DEFINED__
typedef interface IIMSphericalGrid IIMSphericalGrid;

#endif  /* __IIMSphericalGrid_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSphericalGrid_INTERFACE_DEFINED__
#define __IIMSphericalGrid_INTERFACE_DEFINED__

/* interface IIMSphericalGrid */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSphericalGrid;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2F528DC2-A4B0-4A2B-AA43-F6A4C37FC82D" )
IIMSphericalGrid : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE TransferStart(
        /* [in] */ long matrixHeight_,
        /* [in] */ long matrixWidth_,
        /* [full][in] */ SAFEARRAY * *pCamPosition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GridPointsAdd(
        /* [full][in] */ SAFEARRAY * *pArrayMatrixIndices_,
        /* [full][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][in] */ SAFEARRAY * *pArrayColors_,
        /* [full][in] */ SAFEARRAY * *pArrayLuminances_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransferEnd( void ) = 0;

};


#else   /* C style interface */

typedef struct IIMSphericalGridVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSphericalGrid * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        _COM_Outptr_  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSphericalGrid * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSphericalGrid * This );

    HRESULT( STDMETHODCALLTYPE * TransferStart )(
        IIMSphericalGrid * This,
        /* [in] */ long matrixHeight_,
        /* [in] */ long matrixWidth_,
        /* [full][in] */ SAFEARRAY** pCamPosition_ );

    HRESULT( STDMETHODCALLTYPE * GridPointsAdd )(
        IIMSphericalGrid * This,
        /* [full][in] */ SAFEARRAY** pArrayMatrixIndices_,
        /* [full][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][in] */ SAFEARRAY** pArrayColors_,
        /* [full][in] */ SAFEARRAY** pArrayLuminances_ );

    HRESULT( STDMETHODCALLTYPE * TransferEnd )(
        IIMSphericalGrid * This );

    END_INTERFACE
} IIMSphericalGridVtbl;

interface IIMSphericalGrid
{
    CONST_VTBL struct IIMSphericalGridVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSphericalGrid_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSphericalGrid_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSphericalGrid_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSphericalGrid_TransferStart( This, matrixHeight_, matrixWidth_, pCamPosition_ )   \
    ( ( This )->lpVtbl->TransferStart( This, matrixHeight_, matrixWidth_, pCamPosition_ ) )

#define IIMSphericalGrid_GridPointsAdd( This, pArrayMatrixIndices_, pArrayCoords_, pArrayColors_, pArrayLuminances_ ) \
    ( ( This )->lpVtbl->GridPointsAdd( This, pArrayMatrixIndices_, pArrayCoords_, pArrayColors_, pArrayLuminances_ ) )

#define IIMSphericalGrid_TransferEnd( This )  \
    ( ( This )->lpVtbl->TransferEnd( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSphericalGrid_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSphericalGrid_h__
