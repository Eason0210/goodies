/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:53:02 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMScannerFeedback.idl:
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

#ifndef __IIMScannerFeedback_h__
#define __IIMScannerFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScannerFeedback_FWD_DEFINED__
#define __IIMScannerFeedback_FWD_DEFINED__
typedef interface IIMScannerFeedback IIMScannerFeedback;
#endif  /* __IIMScannerFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScannerFeedback_INTERFACE_DEFINED__
#define __IIMScannerFeedback_INTERFACE_DEFINED__

/* interface IIMScannerFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScannerFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "461191C0-470E-4bcd-9CBC-73BC133A745F" )
IIMScannerFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningConnectionEnd( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMScannerFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScannerFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScannerFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScannerFeedback * This );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScannerFeedback * This );

    END_INTERFACE
} IIMScannerFeedbackVtbl;

interface IIMScannerFeedback
{
    CONST_VTBL struct IIMScannerFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScannerFeedback_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScannerFeedback_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScannerFeedback_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScannerFeedback_ScanningConnectionEnd( This )  \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScannerFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScannerFeedback_h__
