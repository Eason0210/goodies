/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Thu Jul 17 08:54:11 2014
 */
/* Compiler settings for ..\..\Interfaces\IIMLineScanner2.idl:
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

#ifndef __IIMLineScanner2_h__
#define __IIMLineScanner2_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMLineScanner2_FWD_DEFINED__
#define __IIMLineScanner2_FWD_DEFINED__
typedef interface IIMLineScanner2 IIMLineScanner2;
#endif  /* __IIMLineScanner2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMLineScanner.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMLineScanner2_INTERFACE_DEFINED__
#define __IIMLineScanner2_INTERFACE_DEFINED__

/* interface IIMLineScanner2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMLineScanner2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "6C3C55BD-C2D1-4C9D-9068-1EF9F15F9ACC" )
IIMLineScanner2 : public IIMLineScanner
{
public:
    virtual HRESULT STDMETHODCALLTYPE RealTimeComparisonGet(
        /* [retval][out] */ VARIANT_BOOL * pRealTimeComparison_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE RealTimeComparisonSet(
        /* [in] */ VARIANT_BOOL realTimeComparison_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMLineScanner2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMLineScanner2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMLineScanner2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMLineScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMLineScanner2 * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMLineScanner2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMLineScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMLineScanner2 * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMLineScanner2 * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMLineScanner2 * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMLineScanner2 * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMLineScanner2 * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningStart )(
        IIMLineScanner2 * This,
        /* [in] */ IIMLineScan* pLineScan_,
        /* [in] */ IIMPointCloud* pPointCloud_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningEnd )(
        IIMLineScanner2 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanTypeGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ EScanTypes* pScanType_ );

    HRESULT( STDMETHODCALLTYPE * ScanTypeSet )(
        IIMLineScanner2 * This,
        /* [in] */ EScanTypes scanType_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ VARIANT_BOOL* pExtractNormals_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsSet )(
        IIMLineScanner2 * This,
        /* [in] */ VARIANT_BOOL extractNormals_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMinSearchDistGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pMinSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMinSearchDistSet )(
        IIMLineScanner2 * This,
        /* [in] */ double minSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMaxSearchDistGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pMaxSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMaxSearchDistSet )(
        IIMLineScanner2 * This,
        /* [in] */ double maxSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ VARIANT_BOOL* pExtractHoleBoundaries_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesSet )(
        IIMLineScanner2 * This,
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesMinWidthGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ double* pMinWidth_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesMinWidthSet )(
        IIMLineScanner2 * This,
        /* [in] */ double minWidth_ );

    HRESULT( STDMETHODCALLTYPE * TestModeGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ VARIANT_BOOL* pTestMode_ );

    HRESULT( STDMETHODCALLTYPE * TestModeSet )(
        IIMLineScanner2 * This,
        /* [in] */ VARIANT_BOOL testMode_ );

    HRESULT( STDMETHODCALLTYPE * RealTimeComparisonGet )(
        IIMLineScanner2 * This,
        /* [retval][out] */ VARIANT_BOOL* pRealTimeComparison_ );

    HRESULT( STDMETHODCALLTYPE * RealTimeComparisonSet )(
        IIMLineScanner2 * This,
        /* [in] */ VARIANT_BOOL realTimeComparison_ );

    END_INTERFACE
} IIMLineScanner2Vtbl;

interface IIMLineScanner2
{
    CONST_VTBL struct IIMLineScanner2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMLineScanner2_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMLineScanner2_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMLineScanner2_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMLineScanner2_ScanningDeviceNameGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMLineScanner2_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMLineScanner2_ScanningConnectionEnd( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMLineScanner2_ScanningDlgShow( This )   \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMLineScanner2_ScanningDlgClose( This )  \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMLineScanner2_ScanNameDefaultGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMLineScanner2_ScanNameSet( This, name_ ) \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMLineScanner2_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMLineScanner2_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMLineScanner2_MeshInterpolationStepGet( This, pInterpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMLineScanner2_MeshInterpolationStepSet( This, interpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMLineScanner2_MeshMaxAngleGet( This, pMaxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMLineScanner2_MeshMaxAngleSet( This, maxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMLineScanner2_ScanningStart( This, pLineScan_, pPointCloud_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningStart( This, pLineScan_, pPointCloud_, pReturnVal_ ) )

#define IIMLineScanner2_ScanningEnd( This, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScanningEnd( This, pReturnVal_ ) )

#define IIMLineScanner2_ScanTypeGet( This, pScanType_ )    \
    ( ( This )->lpVtbl->ScanTypeGet( This, pScanType_ ) )

#define IIMLineScanner2_ScanTypeSet( This, scanType_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanTypeSet( This, scanType_, pReturnVal_ ) )

#define IIMLineScanner2_ExtractNormalsGet( This, pExtractNormals_ )    \
    ( ( This )->lpVtbl->ExtractNormalsGet( This, pExtractNormals_ ) )

#define IIMLineScanner2_ExtractNormalsSet( This, extractNormals_ ) \
    ( ( This )->lpVtbl->ExtractNormalsSet( This, extractNormals_ ) )

#define IIMLineScanner2_ExtractNormalsMinSearchDistGet( This, pMinSearchDist_ )    \
    ( ( This )->lpVtbl->ExtractNormalsMinSearchDistGet( This, pMinSearchDist_ ) )

#define IIMLineScanner2_ExtractNormalsMinSearchDistSet( This, minSearchDist_ ) \
    ( ( This )->lpVtbl->ExtractNormalsMinSearchDistSet( This, minSearchDist_ ) )

#define IIMLineScanner2_ExtractNormalsMaxSearchDistGet( This, pMaxSearchDist_ )    \
    ( ( This )->lpVtbl->ExtractNormalsMaxSearchDistGet( This, pMaxSearchDist_ ) )

#define IIMLineScanner2_ExtractNormalsMaxSearchDistSet( This, maxSearchDist_ ) \
    ( ( This )->lpVtbl->ExtractNormalsMaxSearchDistSet( This, maxSearchDist_ ) )

#define IIMLineScanner2_ExtractHoleBoundariesGet( This, pExtractHoleBoundaries_ )  \
    ( ( This )->lpVtbl->ExtractHoleBoundariesGet( This, pExtractHoleBoundaries_ ) )

#define IIMLineScanner2_ExtractHoleBoundariesSet( This, extractHoleBoundaries_ )   \
    ( ( This )->lpVtbl->ExtractHoleBoundariesSet( This, extractHoleBoundaries_ ) )

#define IIMLineScanner2_ExtractHoleBoundariesMinWidthGet( This, pMinWidth_ )   \
    ( ( This )->lpVtbl->ExtractHoleBoundariesMinWidthGet( This, pMinWidth_ ) )

#define IIMLineScanner2_ExtractHoleBoundariesMinWidthSet( This, minWidth_ )    \
    ( ( This )->lpVtbl->ExtractHoleBoundariesMinWidthSet( This, minWidth_ ) )

#define IIMLineScanner2_TestModeGet( This, pTestMode_ )    \
    ( ( This )->lpVtbl->TestModeGet( This, pTestMode_ ) )

#define IIMLineScanner2_TestModeSet( This, testMode_ ) \
    ( ( This )->lpVtbl->TestModeSet( This, testMode_ ) )


#define IIMLineScanner2_RealTimeComparisonGet( This, pRealTimeComparison_ )    \
    ( ( This )->lpVtbl->RealTimeComparisonGet( This, pRealTimeComparison_ ) )

#define IIMLineScanner2_RealTimeComparisonSet( This, realTimeComparison_ ) \
    ( ( This )->lpVtbl->RealTimeComparisonSet( This, realTimeComparison_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMLineScanner2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMLineScanner2_h__
