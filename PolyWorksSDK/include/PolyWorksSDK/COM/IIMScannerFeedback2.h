/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Fri Sep 07 16:23:32 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMScannerFeedback2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555
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

#ifndef __IIMScannerFeedback2_h__
#define __IIMScannerFeedback2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScannerFeedback2_FWD_DEFINED__
#define __IIMScannerFeedback2_FWD_DEFINED__
typedef interface IIMScannerFeedback2 IIMScannerFeedback2;
#endif  /* __IIMScannerFeedback2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScannerFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScannerFeedback2_INTERFACE_DEFINED__
#define __IIMScannerFeedback2_INTERFACE_DEFINED__

/* interface IIMScannerFeedback2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScannerFeedback2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "DB37DF39-3023-4B61-847B-15475B0EB52A" )
IIMScannerFeedback2 : public IIMScannerFeedback
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningDlgClosed( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMScannerFeedback2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScannerFeedback2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScannerFeedback2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScannerFeedback2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScannerFeedback2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClosed )(
        IIMScannerFeedback2 * This );

    END_INTERFACE
} IIMScannerFeedback2Vtbl;

interface IIMScannerFeedback2
{
    CONST_VTBL struct IIMScannerFeedback2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScannerFeedback2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScannerFeedback2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScannerFeedback2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScannerFeedback2_ScanningConnectionEnd( This ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This ) )


#define IIMScannerFeedback2_ScanningDlgClosed( This ) \
    ( ( This )->lpVtbl->ScanningDlgClosed( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScannerFeedback2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScannerFeedback2_h__
