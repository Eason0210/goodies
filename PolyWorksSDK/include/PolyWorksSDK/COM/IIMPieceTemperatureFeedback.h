/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Wed Apr 24 12:28:58 2013
 */
/* Compiler settings for ..\..\Interfaces\IIMPieceTemperatureFeedback.idl:
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

#ifndef __IIMPieceTemperatureFeedback_h__
#define __IIMPieceTemperatureFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPieceTemperatureFeedback_FWD_DEFINED__
#define __IIMPieceTemperatureFeedback_FWD_DEFINED__
typedef interface IIMPieceTemperatureFeedback IIMPieceTemperatureFeedback;
#endif  /* __IIMPieceTemperatureFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPieceTemperatureFeedback_INTERFACE_DEFINED__
#define __IIMPieceTemperatureFeedback_INTERFACE_DEFINED__

/* interface IIMPieceTemperatureFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPieceTemperatureFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "1C8B3FBB-6012-4BAC-9F76-6E6E1A0E27AC" )
IIMPieceTemperatureFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE PieceTemperatureSet(
        /* [in] */ double pieceTemperature_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPieceTemperatureFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPieceTemperatureFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPieceTemperatureFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPieceTemperatureFeedback * This );

    HRESULT( STDMETHODCALLTYPE * PieceTemperatureSet )(
        IIMPieceTemperatureFeedback * This,
        /* [in] */ double pieceTemperature_ );

    END_INTERFACE
} IIMPieceTemperatureFeedbackVtbl;

interface IIMPieceTemperatureFeedback
{
    CONST_VTBL struct IIMPieceTemperatureFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPieceTemperatureFeedback_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPieceTemperatureFeedback_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPieceTemperatureFeedback_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPieceTemperatureFeedback_PieceTemperatureSet( This, pieceTemperature_ ) \
    ( ( This )->lpVtbl->PieceTemperatureSet( This, pieceTemperature_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPieceTemperatureFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPieceTemperatureFeedback_h__
