/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:51 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInputEventsReceiver.idl:
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

#ifndef __IIMInputEventsReceiver_h__
#define __IIMInputEventsReceiver_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInputEventsReceiver_FWD_DEFINED__
#define __IIMInputEventsReceiver_FWD_DEFINED__
typedef interface IIMInputEventsReceiver IIMInputEventsReceiver;
#endif  /* __IIMInputEventsReceiver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInputEventsReceiver_INTERFACE_DEFINED__
#define __IIMInputEventsReceiver_INTERFACE_DEFINED__

/* interface IIMInputEventsReceiver */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInputEventsReceiver;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "14280FEF-3746-4455-B478-B182437CCDDE" )
IIMInputEventsReceiver : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ButtonEvent(
        /* [in] */ EButtonEvents buttonEvent_,
        /* [in] */ long buttonNumber_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMInputEventsReceiverVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInputEventsReceiver * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInputEventsReceiver * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInputEventsReceiver * This );

    HRESULT( STDMETHODCALLTYPE * ButtonEvent )(
        IIMInputEventsReceiver * This,
        /* [in] */ EButtonEvents buttonEvent_,
        /* [in] */ long buttonNumber_ );

    END_INTERFACE
} IIMInputEventsReceiverVtbl;

interface IIMInputEventsReceiver
{
    CONST_VTBL struct IIMInputEventsReceiverVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInputEventsReceiver_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInputEventsReceiver_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInputEventsReceiver_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInputEventsReceiver_ButtonEvent( This, buttonEvent_, buttonNumber_ ) \
    ( ( This )->lpVtbl->ButtonEvent( This, buttonEvent_, buttonNumber_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInputEventsReceiver_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInputEventsReceiver_h__
