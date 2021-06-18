/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Fri Jul 17 09:09:42 2015
 */
/* Compiler settings for ..\..\Interfaces\IIMSphericalScanner.idl:
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

#ifndef __IIMSphericalScanner_h__
#define __IIMSphericalScanner_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSphericalScanner_FWD_DEFINED__
#define __IIMSphericalScanner_FWD_DEFINED__
typedef interface IIMSphericalScanner IIMSphericalScanner;
#endif  /* __IIMSphericalScanner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMSphericalGrid.h"
#include "IIMScanner.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMSphericalScanner_INTERFACE_DEFINED__
#define __IIMSphericalScanner_INTERFACE_DEFINED__

/* interface IIMSphericalScanner */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSphericalScanner;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "4F973B70-9ABE-4BB6-9747-7C0FFD1D250F" )
IIMSphericalScanner : public IIMScanner
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningStart(
        /* [in] */ IIMSphericalGrid * pSphericalGrid_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSphericalScannerVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSphericalScanner * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSphericalScanner * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSphericalScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMSphericalScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMSphericalScanner * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMSphericalScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMSphericalScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMSphericalScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMSphericalScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMSphericalScanner * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMSphericalScanner * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMSphericalScanner * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMSphericalScanner * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMSphericalScanner * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMSphericalScanner * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMSphericalScanner * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningStart )(
        IIMSphericalScanner * This,
        /* [in] */ IIMSphericalGrid* pSphericalGrid_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningEnd )(
        IIMSphericalScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    END_INTERFACE
} IIMSphericalScannerVtbl;

interface IIMSphericalScanner
{
    CONST_VTBL struct IIMSphericalScannerVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSphericalScanner_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSphericalScanner_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSphericalScanner_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSphericalScanner_ScanningDeviceNameGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMSphericalScanner_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMSphericalScanner_ScanningConnectionEnd( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMSphericalScanner_ScanningDlgShow( This )   \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMSphericalScanner_ScanningDlgClose( This )  \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMSphericalScanner_ScanNameDefaultGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMSphericalScanner_ScanNameSet( This, name_ ) \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMSphericalScanner_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMSphericalScanner_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMSphericalScanner_MeshInterpolationStepGet( This, pInterpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMSphericalScanner_MeshInterpolationStepSet( This, interpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMSphericalScanner_MeshMaxAngleGet( This, pMaxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMSphericalScanner_MeshMaxAngleSet( This, maxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMSphericalScanner_ScanningStart( This, pSphericalGrid_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningStart( This, pSphericalGrid_, pReturnVal_ ) )

#define IIMSphericalScanner_ScanningEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScanningEnd( This, pReturnVal_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSphericalScanner_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSphericalScanner_h__
