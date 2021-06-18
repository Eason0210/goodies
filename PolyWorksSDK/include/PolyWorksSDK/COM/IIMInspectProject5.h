/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:50:40 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectProject5.idl:
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

#ifndef __IIMInspectProject5_h__
#define __IIMInspectProject5_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInspectProject5_FWD_DEFINED__
#define __IIMInspectProject5_FWD_DEFINED__
typedef interface IIMInspectProject5 IIMInspectProject5;
#endif  /* __IIMInspectProject5_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInspectProject4.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInspectProject5_INTERFACE_DEFINED__
#define __IIMInspectProject5_INTERFACE_DEFINED__

/* interface IIMInspectProject5 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspectProject5;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "E173A0B8-C524-4460-AFC0-8A6340D21BCA" )
IIMInspectProject5 : public IIMInspectProject4
{
public:
    virtual HRESULT STDMETHODCALLTYPE DataCreateAsPlanarGrid2(
        /* [out] */ IIMPlanarGrid * *ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DataCreateAsLineScan2(
        /* [out] */ IIMLineScan * *ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_,
        /* [in] */ double minHoleWidth_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DataCreateAsPointCloud2(
        /* [out] */ IIMPointCloud * *ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [in] */ EPointCloudType ptCloudType_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectProject5Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspectProject5 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspectProject5 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspectProject5 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMInspectProject5 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * PointCloudCreateData )(
        IIMInspectProject5 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPlanarGrid )(
        IIMInspectProject5 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsLineScan )(
        IIMInspectProject5 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPointCloud )(
        IIMInspectProject5 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixGet )(
        IIMInspectProject5 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixSet )(
        IIMInspectProject5 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionCoordsConvert )(
        IIMInspectProject5 * This,
        /* [out][in] */ SAFEARRAY** pArrayCoords_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionNormalsConvert )(
        IIMInspectProject5 * This,
        /* [out][in] */ SAFEARRAY** pArrayNormals_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPlanarGrid2 )(
        IIMInspectProject5 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsLineScan2 )(
        IIMInspectProject5 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL extractHoleBoundaries_,
        /* [in] */ double minHoleWidth_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPointCloud2 )(
        IIMInspectProject5 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [in] */ EPointCloudType ptCloudType_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    END_INTERFACE
} IIMInspectProject5Vtbl;

interface IIMInspectProject5
{
    CONST_VTBL struct IIMInspectProject5Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspectProject5_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspectProject5_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspectProject5_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspectProject5_CommandCenterCreate( This, ppIIMCommandCenter_ )    \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#define IIMInspectProject5_PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ )   \
    ( ( This )->lpVtbl->PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ ) )


#define IIMInspectProject5_DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ ) )

#define IIMInspectProject5_DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) \
    ( ( This )->lpVtbl->DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) )

#define IIMInspectProject5_DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ ) )


#define IIMInspectProject5_ActiveDevicePositionMatrixGet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixGet( This, pTransMat_ ) )

#define IIMInspectProject5_ActiveDevicePositionMatrixSet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixSet( This, pTransMat_ ) )


#define IIMInspectProject5_ActiveDevicePositionCoordsConvert( This, pArrayCoords_, sourceCoordSystem_, destinationCoordSystem_ ) \
    ( ( This )->lpVtbl->ActiveDevicePositionCoordsConvert( This, pArrayCoords_, sourceCoordSystem_, destinationCoordSystem_ ) )

#define IIMInspectProject5_ActiveDevicePositionNormalsConvert( This, pArrayNormals_, sourceCoordSystem_, destinationCoordSystem_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionNormalsConvert( This, pArrayNormals_, sourceCoordSystem_, destinationCoordSystem_ ) )


#define IIMInspectProject5_DataCreateAsPlanarGrid2( This, ppIIMPlanarGrid_, pObjectName_, convertToPolygonal_, interactiveState_ )    \
    ( ( This )->lpVtbl->DataCreateAsPlanarGrid2( This, ppIIMPlanarGrid_, pObjectName_, convertToPolygonal_, interactiveState_ ) )

#define IIMInspectProject5_DataCreateAsLineScan2( This, ppIIMLineScan_, pObjectName_, extractNormals_, minSearchDist_, maxSearchDist_, extractHoleBoundaries_, minHoleWidth_, isTestingMode_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsLineScan2( This, ppIIMLineScan_, pObjectName_, extractNormals_, minSearchDist_, maxSearchDist_, extractHoleBoundaries_, minHoleWidth_, isTestingMode_, interactiveState_ ) )

#define IIMInspectProject5_DataCreateAsPointCloud2( This, ppIIMPointCloud_, pObjectName_, ptCloudType_, interactiveState_ )   \
    ( ( This )->lpVtbl->DataCreateAsPointCloud2( This, ppIIMPointCloud_, pObjectName_, ptCloudType_, interactiveState_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspectProject5_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInspectProject5_h__
