/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Wed Mar 12 16:55:07 2014
 */
/* Compiler settings for ..\..\Interfaces\IIMScanner3.idl:
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

#ifndef __IIMScanner3_h__
#define __IIMScanner3_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanner3_FWD_DEFINED__
#define __IIMScanner3_FWD_DEFINED__
typedef interface IIMScanner3 IIMScanner3;
#endif  /* __IIMScanner3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScanner2.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanner3_INTERFACE_DEFINED__
#define __IIMScanner3_INTERFACE_DEFINED__

/* interface IIMScanner3 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanner3;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "48EBD6D6-D4E7-466F-9F27-A00C4BEE05AB" )
IIMScanner3 : public IIMScanner2
{
public:
    virtual HRESULT STDMETHODCALLTYPE OnScanningEvent(
        /* [in] */ EScanningEvents event_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScanner3Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanner3 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanner3 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanner3 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMScanner3 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMScanner3 * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScanner3 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMScanner3 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMScanner3 * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMScanner3 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMScanner3 * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMScanner3 * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMScanner3 * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMScanner3 * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMScanner3 * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMScanner3 * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMScanner3 * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceMenuLocationGet )(
        IIMScanner3 * This,
        /* [retval][out] */ BSTR* pMenuPath_ );

    HRESULT( STDMETHODCALLTYPE * OnScanningEvent )(
        IIMScanner3 * This,
        /* [in] */ EScanningEvents event_ );

    END_INTERFACE
} IIMScanner3Vtbl;

interface IIMScanner3
{
    CONST_VTBL struct IIMScanner3Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanner3_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanner3_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanner3_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanner3_ScanningDeviceNameGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMScanner3_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMScanner3_ScanningConnectionEnd( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMScanner3_ScanningDlgShow( This )   \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMScanner3_ScanningDlgClose( This )  \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMScanner3_ScanNameDefaultGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMScanner3_ScanNameSet( This, name_ ) \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMScanner3_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMScanner3_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMScanner3_MeshInterpolationStepGet( This, pInterpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMScanner3_MeshInterpolationStepSet( This, interpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMScanner3_MeshMaxAngleGet( This, pMaxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMScanner3_MeshMaxAngleSet( This, maxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMScanner3_ScanningDeviceMenuLocationGet( This, pMenuPath_ )  \
    ( ( This )->lpVtbl->ScanningDeviceMenuLocationGet( This, pMenuPath_ ) )


#define IIMScanner3_OnScanningEvent( This, event_ )    \
    ( ( This )->lpVtbl->OnScanningEvent( This, event_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanner3_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScanner3_h__
