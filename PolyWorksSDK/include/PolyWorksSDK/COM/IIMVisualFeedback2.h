/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:52:54 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMVisualFeedback2.idl:
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

#ifndef __IIMVisualFeedback2_h__
#define __IIMVisualFeedback2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMVisualFeedback2_FWD_DEFINED__
#define __IIMVisualFeedback2_FWD_DEFINED__
typedef interface IIMVisualFeedback2 IIMVisualFeedback2;
#endif  /* __IIMVisualFeedback2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMVisualFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMVisualFeedback2_INTERFACE_DEFINED__
#define __IIMVisualFeedback2_INTERFACE_DEFINED__

/* interface IIMVisualFeedback2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMVisualFeedback2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "36F7006D-D5E2-4ca5-9732-DF33E195013B" )
IIMVisualFeedback2 : public IIMVisualFeedback
{
public:
    virtual HRESULT STDMETHODCALLTYPE PolylineDraw2(
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY * *pArraySegmentSizes_,
        /* [full][ref][in] */ SAFEARRAY * *pArraySignificantSegments_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMVisualFeedback2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMVisualFeedback2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMVisualFeedback2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMVisualFeedback2 * This );

    HRESULT( STDMETHODCALLTYPE * PolylineDraw )(
        IIMVisualFeedback2 * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY** pArraySegmentSizes_ );

    HRESULT( STDMETHODCALLTYPE * PolylineDraw2 )(
        IIMVisualFeedback2 * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY** pArraySegmentSizes_,
        /* [full][ref][in] */ SAFEARRAY** pArraySignificantSegments_ );

    END_INTERFACE
} IIMVisualFeedback2Vtbl;

interface IIMVisualFeedback2
{
    CONST_VTBL struct IIMVisualFeedback2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMVisualFeedback2_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMVisualFeedback2_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMVisualFeedback2_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMVisualFeedback2_PolylineDraw( This, pArrayCoords_, pArraySegmentSizes_ ) \
    ( ( This )->lpVtbl->PolylineDraw( This, pArrayCoords_, pArraySegmentSizes_ ) )


#define IIMVisualFeedback2_PolylineDraw2( This, pArrayCoords_, pArraySegmentSizes_, pArraySignificantSegments_ ) \
    ( ( This )->lpVtbl->PolylineDraw2( This, pArrayCoords_, pArraySegmentSizes_, pArraySignificantSegments_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMVisualFeedback2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMVisualFeedback2_h__
