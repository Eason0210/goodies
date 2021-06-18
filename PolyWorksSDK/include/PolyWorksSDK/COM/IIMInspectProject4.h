/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:49:08 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectProject4.idl:
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

#ifndef __IIMInspectProject4_h__
#define __IIMInspectProject4_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInspectProject4_FWD_DEFINED__
#define __IIMInspectProject4_FWD_DEFINED__
typedef interface IIMInspectProject4 IIMInspectProject4;
#endif  /* __IIMInspectProject4_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInspectProject3.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInspectProject4_INTERFACE_DEFINED__
#define __IIMInspectProject4_INTERFACE_DEFINED__

/* interface IIMInspectProject4 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspectProject4;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "71768544-A229-49dd-8764-47B5BF5C1C0A" )
IIMInspectProject4 : public IIMInspectProject3
{
public:
    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionCoordsConvert(
        /* [out][in] */ SAFEARRAY * *pArrayCoords_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionNormalsConvert(
        /* [out][in] */ SAFEARRAY * *pArrayNormals_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectProject4Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspectProject4 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspectProject4 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspectProject4 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMInspectProject4 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * PointCloudCreateData )(
        IIMInspectProject4 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPlanarGrid )(
        IIMInspectProject4 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsLineScan )(
        IIMInspectProject4 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPointCloud )(
        IIMInspectProject4 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixGet )(
        IIMInspectProject4 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixSet )(
        IIMInspectProject4 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionCoordsConvert )(
        IIMInspectProject4 * This,
        /* [out][in] */ SAFEARRAY** pArrayCoords_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionNormalsConvert )(
        IIMInspectProject4 * This,
        /* [out][in] */ SAFEARRAY** pArrayNormals_,
        /* [in] */ ECoordinateSystem sourceCoordSystem_,
        /* [in] */ ECoordinateSystem destinationCoordSystem_ );

    END_INTERFACE
} IIMInspectProject4Vtbl;

interface IIMInspectProject4
{
    CONST_VTBL struct IIMInspectProject4Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspectProject4_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspectProject4_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspectProject4_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspectProject4_CommandCenterCreate( This, ppIIMCommandCenter_ )    \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#define IIMInspectProject4_PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ )   \
    ( ( This )->lpVtbl->PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ ) )


#define IIMInspectProject4_DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ ) )

#define IIMInspectProject4_DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) \
    ( ( This )->lpVtbl->DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) )

#define IIMInspectProject4_DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ ) )


#define IIMInspectProject4_ActiveDevicePositionMatrixGet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixGet( This, pTransMat_ ) )

#define IIMInspectProject4_ActiveDevicePositionMatrixSet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixSet( This, pTransMat_ ) )


#define IIMInspectProject4_ActiveDevicePositionCoordsConvert( This, pArrayCoords_, sourceCoordSystem_, destinationCoordSystem_ ) \
    ( ( This )->lpVtbl->ActiveDevicePositionCoordsConvert( This, pArrayCoords_, sourceCoordSystem_, destinationCoordSystem_ ) )

#define IIMInspectProject4_ActiveDevicePositionNormalsConvert( This, pArrayNormals_, sourceCoordSystem_, destinationCoordSystem_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionNormalsConvert( This, pArrayNormals_, sourceCoordSystem_, destinationCoordSystem_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspectProject4_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInspectProject4_h__
