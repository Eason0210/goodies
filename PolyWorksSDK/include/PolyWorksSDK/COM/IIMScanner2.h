/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Wed Aug 08 14:46:09 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMScanner2.idl:
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

#ifndef __IIMScanner2_h__
#define __IIMScanner2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanner2_FWD_DEFINED__
#define __IIMScanner2_FWD_DEFINED__
typedef interface IIMScanner2 IIMScanner2;
#endif  /* __IIMScanner2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScanner.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanner2_INTERFACE_DEFINED__
#define __IIMScanner2_INTERFACE_DEFINED__

/* interface IIMScanner2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanner2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "48289DE6-8CD6-427F-94E1-5D5406805307" )
IIMScanner2 : public IIMScanner
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningDeviceMenuLocationGet(
        /* [retval][out] */ BSTR * pMenuPath_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScanner2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanner2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanner2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMScanner2 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMScanner2 * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScanner2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMScanner2 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMScanner2 * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMScanner2 * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMScanner2 * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMScanner2 * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMScanner2 * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMScanner2 * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMScanner2 * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceMenuLocationGet )(
        IIMScanner2 * This,
        /* [retval][out] */ BSTR* pMenuPath_ );

    END_INTERFACE
} IIMScanner2Vtbl;

interface IIMScanner2
{
    CONST_VTBL struct IIMScanner2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanner2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanner2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanner2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanner2_ScanningDeviceNameGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMScanner2_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMScanner2_ScanningConnectionEnd( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMScanner2_ScanningDlgShow( This )   \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMScanner2_ScanningDlgClose( This )  \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMScanner2_ScanNameDefaultGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMScanner2_ScanNameSet( This, name_ ) \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMScanner2_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMScanner2_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMScanner2_MeshInterpolationStepGet( This, pInterpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMScanner2_MeshInterpolationStepSet( This, interpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMScanner2_MeshMaxAngleGet( This, pMaxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMScanner2_MeshMaxAngleSet( This, maxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMScanner2_ScanningDeviceMenuLocationGet( This, pMenuPath_ )  \
    ( ( This )->lpVtbl->ScanningDeviceMenuLocationGet( This, pMenuPath_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanner2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScanner2_h__
