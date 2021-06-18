/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:49 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMLineScan.idl:
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

#ifndef __IIMLineScan_h__
#define __IIMLineScan_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMLineScan_FWD_DEFINED__
#define __IIMLineScan_FWD_DEFINED__
typedef interface IIMLineScan IIMLineScan;
#endif  /* __IIMLineScan_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMLineScan_INTERFACE_DEFINED__
#define __IIMLineScan_INTERFACE_DEFINED__

/* interface IIMLineScan */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMLineScan;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "DFF90530-2F7B-4d7f-A386-B1A97FAFC0BB" )
IIMLineScan : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE TransferStart(
        /* [in] */ EDigitizingVectorDirections digitizingVectorDir_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PassStart( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LineAdd(
        /* [full][ref][in] */ SAFEARRAY * *digitizingVector_,
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE LinesAdd(
        /* [full][ref][in] */ SAFEARRAY * *pArrayDigitizingVectors_,
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY * *pArrayLineSizes_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PassEnd( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransferEnd( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMLineScanVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMLineScan * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMLineScan * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMLineScan * This );

    HRESULT( STDMETHODCALLTYPE * TransferStart )(
        IIMLineScan * This,
        /* [in] */ EDigitizingVectorDirections digitizingVectorDir_ );

    HRESULT( STDMETHODCALLTYPE * PassStart )(
        IIMLineScan * This );

    HRESULT( STDMETHODCALLTYPE * LineAdd )(
        IIMLineScan * This,
        /* [full][ref][in] */ SAFEARRAY** digitizingVector_,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_ );

    HRESULT( STDMETHODCALLTYPE * LinesAdd )(
        IIMLineScan * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayDigitizingVectors_,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY** pArrayLineSizes_ );

    HRESULT( STDMETHODCALLTYPE * PassEnd )(
        IIMLineScan * This );

    HRESULT( STDMETHODCALLTYPE * TransferEnd )(
        IIMLineScan * This );

    END_INTERFACE
} IIMLineScanVtbl;

interface IIMLineScan
{
    CONST_VTBL struct IIMLineScanVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMLineScan_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMLineScan_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMLineScan_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMLineScan_TransferStart( This, digitizingVectorDir_ )    \
    ( ( This )->lpVtbl->TransferStart( This, digitizingVectorDir_ ) )

#define IIMLineScan_PassStart( This ) \
    ( ( This )->lpVtbl->PassStart( This ) )

#define IIMLineScan_LineAdd( This, digitizingVector_, pArrayCoords_ )   \
    ( ( This )->lpVtbl->LineAdd( This, digitizingVector_, pArrayCoords_ ) )

#define IIMLineScan_LinesAdd( This, pArrayDigitizingVectors_, pArrayCoords_, pArrayLineSizes_ )  \
    ( ( This )->lpVtbl->LinesAdd( This, pArrayDigitizingVectors_, pArrayCoords_, pArrayLineSizes_ ) )

#define IIMLineScan_PassEnd( This )   \
    ( ( This )->lpVtbl->PassEnd( This ) )

#define IIMLineScan_TransferEnd( This )   \
    ( ( This )->lpVtbl->TransferEnd( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMLineScan_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMLineScan_h__
