/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:44 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMVisualFeedback.idl:
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

#ifndef __IIMVisualFeedback_h__
#define __IIMVisualFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMVisualFeedback_FWD_DEFINED__
#define __IIMVisualFeedback_FWD_DEFINED__
typedef interface IIMVisualFeedback IIMVisualFeedback;
#endif  /* __IIMVisualFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMVisualFeedback_INTERFACE_DEFINED__
#define __IIMVisualFeedback_INTERFACE_DEFINED__

/* interface IIMVisualFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMVisualFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "CC8EE2C2-A5CE-48a3-8C83-19BD8E255682" )
IIMVisualFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE PolylineDraw(
        /* [full][ref][in] */ SAFEARRAY * *pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY * *pArraySegmentSizes_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMVisualFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMVisualFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMVisualFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMVisualFeedback * This );

    HRESULT( STDMETHODCALLTYPE * PolylineDraw )(
        IIMVisualFeedback * This,
        /* [full][ref][in] */ SAFEARRAY** pArrayCoords_,
        /* [full][ref][in] */ SAFEARRAY** pArraySegmentSizes_ );

    END_INTERFACE
} IIMVisualFeedbackVtbl;

interface IIMVisualFeedback
{
    CONST_VTBL struct IIMVisualFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMVisualFeedback_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMVisualFeedback_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMVisualFeedback_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMVisualFeedback_PolylineDraw( This, pArrayCoords_, pArraySegmentSizes_ )  \
    ( ( This )->lpVtbl->PolylineDraw( This, pArrayCoords_, pArraySegmentSizes_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMVisualFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMVisualFeedback_h__
