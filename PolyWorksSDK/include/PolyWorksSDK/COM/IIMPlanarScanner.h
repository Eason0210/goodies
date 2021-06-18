/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 26 09:42:46 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMPlanarScanner.idl:
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

#ifndef __IIMPlanarScanner_h__
#define __IIMPlanarScanner_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPlanarScanner_FWD_DEFINED__
#define __IIMPlanarScanner_FWD_DEFINED__
typedef interface IIMPlanarScanner IIMPlanarScanner;
#endif  /* __IIMPlanarScanner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMPlanarGrid.h"
#include "IIMScanner.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPlanarScanner_INTERFACE_DEFINED__
#define __IIMPlanarScanner_INTERFACE_DEFINED__

/* interface IIMPlanarScanner */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPlanarScanner;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "E9B87CEE-EF67-44de-BFAB-15B6767CE78C" )
IIMPlanarScanner : public IIMScanner
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningStart(
        /* [in] */ IIMPlanarGrid * pPlanarGrid_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ConvertToPolygonalModelGet(
        /* [retval][out] */ VARIANT_BOOL * pConvertToPolygonalModel_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ConvertToPolygonalModelSet(
        /* [in] */ VARIANT_BOOL convertToPolygonalModel_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPlanarScannerVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPlanarScanner * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPlanarScanner * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPlanarScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMPlanarScanner * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMPlanarScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMPlanarScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMPlanarScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMPlanarScanner * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMPlanarScanner * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMPlanarScanner * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMPlanarScanner * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningStart )(
        IIMPlanarScanner * This,
        /* [in] */ IIMPlanarGrid* pPlanarGrid_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningEnd )(
        IIMPlanarScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ConvertToPolygonalModelGet )(
        IIMPlanarScanner * This,
        /* [retval][out] */ VARIANT_BOOL* pConvertToPolygonalModel_ );

    HRESULT( STDMETHODCALLTYPE * ConvertToPolygonalModelSet )(
        IIMPlanarScanner * This,
        /* [in] */ VARIANT_BOOL convertToPolygonalModel_ );

    END_INTERFACE
} IIMPlanarScannerVtbl;

interface IIMPlanarScanner
{
    CONST_VTBL struct IIMPlanarScannerVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPlanarScanner_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPlanarScanner_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPlanarScanner_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPlanarScanner_ScanningDeviceNameGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMPlanarScanner_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMPlanarScanner_ScanningConnectionEnd( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMPlanarScanner_ScanningDlgShow( This )  \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMPlanarScanner_ScanningDlgClose( This ) \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMPlanarScanner_ScanNameDefaultGet( This, pName_ )    \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMPlanarScanner_ScanNameSet( This, name_ )    \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMPlanarScanner_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMPlanarScanner_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMPlanarScanner_MeshInterpolationStepGet( This, pInterpolationStep_ ) \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMPlanarScanner_MeshInterpolationStepSet( This, interpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMPlanarScanner_MeshMaxAngleGet( This, pMaxAngle_ )   \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMPlanarScanner_MeshMaxAngleSet( This, maxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMPlanarScanner_ScanningStart( This, pPlanarGrid_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScanningStart( This, pPlanarGrid_, pReturnVal_ ) )

#define IIMPlanarScanner_ScanningEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningEnd( This, pReturnVal_ ) )

#define IIMPlanarScanner_ConvertToPolygonalModelGet( This, pConvertToPolygonalModel_ ) \
    ( ( This )->lpVtbl->ConvertToPolygonalModelGet( This, pConvertToPolygonalModel_ ) )

#define IIMPlanarScanner_ConvertToPolygonalModelSet( This, convertToPolygonalModel_ )  \
    ( ( This )->lpVtbl->ConvertToPolygonalModelSet( This, convertToPolygonalModel_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPlanarScanner_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPlanarScanner_h__
