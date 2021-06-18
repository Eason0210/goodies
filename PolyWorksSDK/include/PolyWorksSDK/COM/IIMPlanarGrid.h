/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:50 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMPlanarGrid.idl:
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

#ifndef __IIMPlanarGrid_h__
#define __IIMPlanarGrid_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPlanarGrid_FWD_DEFINED__
#define __IIMPlanarGrid_FWD_DEFINED__
typedef interface IIMPlanarGrid IIMPlanarGrid;
#endif  /* __IIMPlanarGrid_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPlanarGrid_INTERFACE_DEFINED__
#define __IIMPlanarGrid_INTERFACE_DEFINED__

/* interface IIMPlanarGrid */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPlanarGrid;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "11D73E2B-9AE2-4121-A471-BE3B993D31BB" )
IIMPlanarGrid : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE TransferStart(
        /* [in] */ short matrixHeight_,
        /* [in] */ short matrixWidth_,
        /* [in] */ EDigitizingVectorDirections digitizingVectorDir_,
        /* [full][ref][in] */ SAFEARRAY * *digitizingVector_,
        /* [defaultvalue][in] */ float invalidZ_ = -1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE GridPointsAdd(
        /* [full][ref][in] */ SAFEARRAY * *pArrayMatrixIndices_,
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayColors_,
        /* [full][unique][in] */ SAFEARRAY * *pArrayLuminances_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransferEnd( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMPlanarGridVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPlanarGrid * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPlanarGrid * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPlanarGrid * This );

    HRESULT( STDMETHODCALLTYPE * TransferStart )(
        IIMPlanarGrid * This,
        /* [in] */ short matrixHeight_,
        /* [in] */ short matrixWidth_,
        /* [in] */ EDigitizingVectorDirections digitizingVectorDir_,
        /* [full][ref][in] */ SAFEARRAY** digitizingVector_,
        /* [defaultvalue][in] */ float invalidZ_ );

    HRESULT( STDMETHODCALLTYPE * GridPointsAdd )(
        IIMPlanarGrid * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayMatrixIndices_,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][unique][in] */ SAFEARRAY** pArrayNormals_,
        /* [full][unique][in] */ SAFEARRAY** pArrayColors_,
        /* [full][unique][in] */ SAFEARRAY** pArrayLuminances_ );

    HRESULT( STDMETHODCALLTYPE * TransferEnd )(
        IIMPlanarGrid * This );

    END_INTERFACE
} IIMPlanarGridVtbl;

interface IIMPlanarGrid
{
    CONST_VTBL struct IIMPlanarGridVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPlanarGrid_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPlanarGrid_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPlanarGrid_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPlanarGrid_TransferStart( This, matrixHeight_, matrixWidth_, digitizingVectorDir_, digitizingVector_, invalidZ_ )   \
    ( ( This )->lpVtbl->TransferStart( This, matrixHeight_, matrixWidth_, digitizingVectorDir_, digitizingVector_, invalidZ_ ) )

#define IIMPlanarGrid_GridPointsAdd( This, pArrayMatrixIndices_, pArrayCoords_, pArrayNormals_, pArrayColors_, pArrayLuminances_ ) \
    ( ( This )->lpVtbl->GridPointsAdd( This, pArrayMatrixIndices_, pArrayCoords_, pArrayNormals_, pArrayColors_, pArrayLuminances_ ) )

#define IIMPlanarGrid_TransferEnd( This ) \
    ( ( This )->lpVtbl->TransferEnd( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPlanarGrid_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPlanarGrid_h__
