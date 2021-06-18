/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 26 09:42:45 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMLineScanner.idl:
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

#ifndef __IIMLineScanner_h__
#define __IIMLineScanner_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMLineScanner_FWD_DEFINED__
#define __IIMLineScanner_FWD_DEFINED__
typedef interface IIMLineScanner IIMLineScanner;
#endif  /* __IIMLineScanner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMLineScan.h"
#include "IIMPointCloud.h"
#include "IIMScanner.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMLineScanner_INTERFACE_DEFINED__
#define __IIMLineScanner_INTERFACE_DEFINED__

/* interface IIMLineScanner */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMLineScanner;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "4B66387B-35EF-477a-B1A4-5A6B8669680E" )
IIMLineScanner : public IIMScanner
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningStart(
        /* [in] */ IIMLineScan * pLineScan_,
        /* [in] */ IIMPointCloud * pPointCloud_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningEnd(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanTypeGet(
        /* [retval][out] */ EScanTypes * pScanType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanTypeSet(
        /* [in] */ EScanTypes scanType_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsGet(
        /* [retval][out] */ VARIANT_BOOL * pExtractNormals_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsSet(
        /* [in] */ VARIANT_BOOL extractNormals_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsMinSearchDistGet(
        /* [retval][out] */ double* pMinSearchDist_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsMinSearchDistSet(
        /* [in] */ double minSearchDist_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsMaxSearchDistGet(
        /* [retval][out] */ double* pMaxSearchDist_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractNormalsMaxSearchDistSet(
        /* [in] */ double maxSearchDist_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractHoleBoundariesGet(
        /* [retval][out] */ VARIANT_BOOL * pExtractHoleBoundaries_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractHoleBoundariesSet(
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractHoleBoundariesMinWidthGet(
        /* [retval][out] */ double* pMinWidth_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ExtractHoleBoundariesMinWidthSet(
        /* [in] */ double minWidth_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TestModeGet(
        /* [retval][out] */ VARIANT_BOOL * pTestMode_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TestModeSet(
        /* [in] */ VARIANT_BOOL testMode_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMLineScannerVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMLineScanner * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMLineScanner * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMLineScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMLineScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMLineScanner * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMLineScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMLineScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMLineScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMLineScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMLineScanner * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMLineScanner * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMLineScanner * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMLineScanner * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningStart )(
        IIMLineScanner * This,
        /* [in] */ IIMLineScan* pLineScan_,
        /* [in] */ IIMPointCloud* pPointCloud_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningEnd )(
        IIMLineScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanTypeGet )(
        IIMLineScanner * This,
        /* [retval][out] */ EScanTypes* pScanType_ );

    HRESULT( STDMETHODCALLTYPE * ScanTypeSet )(
        IIMLineScanner * This,
        /* [in] */ EScanTypes scanType_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsGet )(
        IIMLineScanner * This,
        /* [retval][out] */ VARIANT_BOOL* pExtractNormals_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsSet )(
        IIMLineScanner * This,
        /* [in] */ VARIANT_BOOL extractNormals_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMinSearchDistGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pMinSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMinSearchDistSet )(
        IIMLineScanner * This,
        /* [in] */ double minSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMaxSearchDistGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pMaxSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractNormalsMaxSearchDistSet )(
        IIMLineScanner * This,
        /* [in] */ double maxSearchDist_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesGet )(
        IIMLineScanner * This,
        /* [retval][out] */ VARIANT_BOOL* pExtractHoleBoundaries_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesSet )(
        IIMLineScanner * This,
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesMinWidthGet )(
        IIMLineScanner * This,
        /* [retval][out] */ double* pMinWidth_ );

    HRESULT( STDMETHODCALLTYPE * ExtractHoleBoundariesMinWidthSet )(
        IIMLineScanner * This,
        /* [in] */ double minWidth_ );

    HRESULT( STDMETHODCALLTYPE * TestModeGet )(
        IIMLineScanner * This,
        /* [retval][out] */ VARIANT_BOOL* pTestMode_ );

    HRESULT( STDMETHODCALLTYPE * TestModeSet )(
        IIMLineScanner * This,
        /* [in] */ VARIANT_BOOL testMode_ );

    END_INTERFACE
} IIMLineScannerVtbl;

interface IIMLineScanner
{
    CONST_VTBL struct IIMLineScannerVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMLineScanner_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMLineScanner_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMLineScanner_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMLineScanner_ScanningDeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMLineScanner_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMLineScanner_ScanningConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMLineScanner_ScanningDlgShow( This )    \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMLineScanner_ScanningDlgClose( This )   \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMLineScanner_ScanNameDefaultGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMLineScanner_ScanNameSet( This, name_ )  \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMLineScanner_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMLineScanner_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )    \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMLineScanner_MeshInterpolationStepGet( This, pInterpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMLineScanner_MeshInterpolationStepSet( This, interpolationStep_ )    \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMLineScanner_MeshMaxAngleGet( This, pMaxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMLineScanner_MeshMaxAngleSet( This, maxAngle_ )  \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMLineScanner_ScanningStart( This, pLineScan_, pPointCloud_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningStart( This, pLineScan_, pPointCloud_, pReturnVal_ ) )

#define IIMLineScanner_ScanningEnd( This, pReturnVal_ )    \
    ( ( This )->lpVtbl->ScanningEnd( This, pReturnVal_ ) )

#define IIMLineScanner_ScanTypeGet( This, pScanType_ ) \
    ( ( This )->lpVtbl->ScanTypeGet( This, pScanType_ ) )

#define IIMLineScanner_ScanTypeSet( This, scanType_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanTypeSet( This, scanType_, pReturnVal_ ) )

#define IIMLineScanner_ExtractNormalsGet( This, pExtractNormals_ ) \
    ( ( This )->lpVtbl->ExtractNormalsGet( This, pExtractNormals_ ) )

#define IIMLineScanner_ExtractNormalsSet( This, extractNormals_ )  \
    ( ( This )->lpVtbl->ExtractNormalsSet( This, extractNormals_ ) )

#define IIMLineScanner_ExtractNormalsMinSearchDistGet( This, pMinSearchDist_ ) \
    ( ( This )->lpVtbl->ExtractNormalsMinSearchDistGet( This, pMinSearchDist_ ) )

#define IIMLineScanner_ExtractNormalsMinSearchDistSet( This, minSearchDist_ )  \
    ( ( This )->lpVtbl->ExtractNormalsMinSearchDistSet( This, minSearchDist_ ) )

#define IIMLineScanner_ExtractNormalsMaxSearchDistGet( This, pMaxSearchDist_ ) \
    ( ( This )->lpVtbl->ExtractNormalsMaxSearchDistGet( This, pMaxSearchDist_ ) )

#define IIMLineScanner_ExtractNormalsMaxSearchDistSet( This, maxSearchDist_ )  \
    ( ( This )->lpVtbl->ExtractNormalsMaxSearchDistSet( This, maxSearchDist_ ) )

#define IIMLineScanner_ExtractHoleBoundariesGet( This, pExtractHoleBoundaries_ )   \
    ( ( This )->lpVtbl->ExtractHoleBoundariesGet( This, pExtractHoleBoundaries_ ) )

#define IIMLineScanner_ExtractHoleBoundariesSet( This, extractHoleBoundaries_ )    \
    ( ( This )->lpVtbl->ExtractHoleBoundariesSet( This, extractHoleBoundaries_ ) )

#define IIMLineScanner_ExtractHoleBoundariesMinWidthGet( This, pMinWidth_ )    \
    ( ( This )->lpVtbl->ExtractHoleBoundariesMinWidthGet( This, pMinWidth_ ) )

#define IIMLineScanner_ExtractHoleBoundariesMinWidthSet( This, minWidth_ ) \
    ( ( This )->lpVtbl->ExtractHoleBoundariesMinWidthSet( This, minWidth_ ) )

#define IIMLineScanner_TestModeGet( This, pTestMode_ ) \
    ( ( This )->lpVtbl->TestModeGet( This, pTestMode_ ) )

#define IIMLineScanner_TestModeSet( This, testMode_ )  \
    ( ( This )->lpVtbl->TestModeSet( This, testMode_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMLineScanner_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMLineScanner_h__
