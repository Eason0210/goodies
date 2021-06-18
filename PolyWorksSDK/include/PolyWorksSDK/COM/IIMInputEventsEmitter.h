/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:47 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInputEventsEmitter.idl:
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

#ifndef __IIMInputEventsEmitter_h__
#define __IIMInputEventsEmitter_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInputEventsEmitter_FWD_DEFINED__
#define __IIMInputEventsEmitter_FWD_DEFINED__
typedef interface IIMInputEventsEmitter IIMInputEventsEmitter;
#endif  /* __IIMInputEventsEmitter_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInputEventsReceiver.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInputEventsEmitter_INTERFACE_DEFINED__
#define __IIMInputEventsEmitter_INTERFACE_DEFINED__

/* interface IIMInputEventsEmitter */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInputEventsEmitter;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "21227EA9-F3E8-4011-ADFC-002F1B270557" )
IIMInputEventsEmitter : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE TransmissionEnable(
        /* [in] */ IIMInputEventsReceiver * pInputEventsReceiver_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransmissionDisable( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMInputEventsEmitterVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInputEventsEmitter * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInputEventsEmitter * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInputEventsEmitter * This );

    HRESULT( STDMETHODCALLTYPE * TransmissionEnable )(
        IIMInputEventsEmitter * This,
        /* [in] */ IIMInputEventsReceiver* pInputEventsReceiver_ );

    HRESULT( STDMETHODCALLTYPE * TransmissionDisable )(
        IIMInputEventsEmitter * This );

    END_INTERFACE
} IIMInputEventsEmitterVtbl;

interface IIMInputEventsEmitter
{
    CONST_VTBL struct IIMInputEventsEmitterVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInputEventsEmitter_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInputEventsEmitter_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInputEventsEmitter_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInputEventsEmitter_TransmissionEnable( This, pInputEventsReceiver_ )    \
    ( ( This )->lpVtbl->TransmissionEnable( This, pInputEventsReceiver_ ) )

#define IIMInputEventsEmitter_TransmissionDisable( This ) \
    ( ( This )->lpVtbl->TransmissionDisable( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInputEventsEmitter_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInputEventsEmitter_h__
