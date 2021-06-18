

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectProject7.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IIMInspectProject7_h__
#define __IIMInspectProject7_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMInspectProject7_FWD_DEFINED__
#define __IIMInspectProject7_FWD_DEFINED__
typedef interface IIMInspectProject7 IIMInspectProject7;

#endif 	/* __IIMInspectProject7_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInspectProject6.h"
#include "IIMPolygonalModel.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMInspectProject7_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMInspectProject7_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMInspectProject7_0000_0000_v0_0_s_ifspec;

#ifndef __IIMInspectProject7_INTERFACE_DEFINED__
#define __IIMInspectProject7_INTERFACE_DEFINED__

/* interface IIMInspectProject7 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMInspectProject7;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4731DAD1-138E-45CE-B92C-0FC6B975A15A")
    IIMInspectProject7 : public IIMInspectProject6
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DataCreateAsPolygonalModel( 
            /* [out] */ IIMPolygonalModel **ppIIMPolygonalModel_,
            /* [full][string][in] */ const OLECHAR *pObjectName_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DataObtainAsPolygonalModel( 
            /* [full][string][in] */ const OLECHAR *pUniqueID_,
            /* [out] */ IIMPolygonalModel **ppIIMPolygonalModel_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMInspectProject7Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMInspectProject7 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMInspectProject7 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMInspectProject7 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CommandCenterCreate )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMCommandCenter **ppIIMCommandCenter_);
        
        HRESULT ( STDMETHODCALLTYPE *PointCloudCreateData )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPointCloud **ppIIMPointCloud_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [defaultvalue][in] */ long interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsPlanarGrid )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPlanarGrid **ppIIMPlanarGrid_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [full][string][in] */ const OLECHAR *pSharedMatrixName_,
            /* [in] */ VARIANT_BOOL convertToPolygonal_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsLineScan )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMLineScan **ppIIMLineScan_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [full][string][in] */ const OLECHAR *pSharedMatrixName_,
            /* [in] */ VARIANT_BOOL extractNormals_,
            /* [in] */ double minSearchDist_,
            /* [in] */ double maxSearchDist_,
            /* [in] */ VARIANT_BOOL isTestingMode_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsPointCloud )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPointCloud **ppIIMPointCloud_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [full][string][in] */ const OLECHAR *pSharedMatrixName_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *ActiveDevicePositionMatrixGet )( 
            IIMInspectProject7 * This,
            /* [out][in] */ SAFEARRAY * *pTransMat_);
        
        HRESULT ( STDMETHODCALLTYPE *ActiveDevicePositionMatrixSet )( 
            IIMInspectProject7 * This,
            /* [in] */ SAFEARRAY * *pTransMat_);
        
        HRESULT ( STDMETHODCALLTYPE *ActiveDevicePositionCoordsConvert )( 
            IIMInspectProject7 * This,
            /* [out][in] */ SAFEARRAY * *pArrayCoords_,
            /* [in] */ ECoordinateSystem sourceCoordSystem_,
            /* [in] */ ECoordinateSystem destinationCoordSystem_);
        
        HRESULT ( STDMETHODCALLTYPE *ActiveDevicePositionNormalsConvert )( 
            IIMInspectProject7 * This,
            /* [out][in] */ SAFEARRAY * *pArrayNormals_,
            /* [in] */ ECoordinateSystem sourceCoordSystem_,
            /* [in] */ ECoordinateSystem destinationCoordSystem_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsPlanarGrid2 )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPlanarGrid **ppIIMPlanarGrid_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [in] */ VARIANT_BOOL convertToPolygonal_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsLineScan2 )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMLineScan **ppIIMLineScan_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [in] */ VARIANT_BOOL extractNormals_,
            /* [in] */ double minSearchDist_,
            /* [in] */ double maxSearchDist_,
            /* [in] */ VARIANT_BOOL extractHoleBoundaries_,
            /* [in] */ double minHoleWidth_,
            /* [in] */ VARIANT_BOOL isTestingMode_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsPointCloud2 )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPointCloud **ppIIMPointCloud_,
            /* [full][string][in] */ const OLECHAR *pObjectName_,
            /* [in] */ EPointCloudType ptCloudType_,
            /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_);
        
        HRESULT ( STDMETHODCALLTYPE *ActiveDevicePositionDimensionsConvert )( 
            IIMInspectProject7 * This,
            /* [out][in] */ SAFEARRAY * *pArrayDimensions_,
            /* [in] */ ECoordinateSystem sourceCoordSystem_,
            /* [in] */ ECoordinateSystem destinationCoordSystem_);
        
        HRESULT ( STDMETHODCALLTYPE *DataCreateAsPolygonalModel )( 
            IIMInspectProject7 * This,
            /* [out] */ IIMPolygonalModel **ppIIMPolygonalModel_,
            /* [full][string][in] */ const OLECHAR *pObjectName_);
        
        HRESULT ( STDMETHODCALLTYPE *DataObtainAsPolygonalModel )( 
            IIMInspectProject7 * This,
            /* [full][string][in] */ const OLECHAR *pUniqueID_,
            /* [out] */ IIMPolygonalModel **ppIIMPolygonalModel_);
        
        END_INTERFACE
    } IIMInspectProject7Vtbl;

    interface IIMInspectProject7
    {
        CONST_VTBL struct IIMInspectProject7Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMInspectProject7_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMInspectProject7_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMInspectProject7_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMInspectProject7_CommandCenterCreate(This,ppIIMCommandCenter_)	\
    ( (This)->lpVtbl -> CommandCenterCreate(This,ppIIMCommandCenter_) ) 

#define IIMInspectProject7_PointCloudCreateData(This,ppIIMPointCloud_,pObjectName_,interactiveState_)	\
    ( (This)->lpVtbl -> PointCloudCreateData(This,ppIIMPointCloud_,pObjectName_,interactiveState_) ) 


#define IIMInspectProject7_DataCreateAsPlanarGrid(This,ppIIMPlanarGrid_,pObjectName_,pSharedMatrixName_,convertToPolygonal_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsPlanarGrid(This,ppIIMPlanarGrid_,pObjectName_,pSharedMatrixName_,convertToPolygonal_,interactiveState_) ) 

#define IIMInspectProject7_DataCreateAsLineScan(This,ppIIMLineScan_,pObjectName_,pSharedMatrixName_,extractNormals_,minSearchDist_,maxSearchDist_,isTestingMode_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsLineScan(This,ppIIMLineScan_,pObjectName_,pSharedMatrixName_,extractNormals_,minSearchDist_,maxSearchDist_,isTestingMode_,interactiveState_) ) 

#define IIMInspectProject7_DataCreateAsPointCloud(This,ppIIMPointCloud_,pObjectName_,pSharedMatrixName_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsPointCloud(This,ppIIMPointCloud_,pObjectName_,pSharedMatrixName_,interactiveState_) ) 


#define IIMInspectProject7_ActiveDevicePositionMatrixGet(This,pTransMat_)	\
    ( (This)->lpVtbl -> ActiveDevicePositionMatrixGet(This,pTransMat_) ) 

#define IIMInspectProject7_ActiveDevicePositionMatrixSet(This,pTransMat_)	\
    ( (This)->lpVtbl -> ActiveDevicePositionMatrixSet(This,pTransMat_) ) 


#define IIMInspectProject7_ActiveDevicePositionCoordsConvert(This,pArrayCoords_,sourceCoordSystem_,destinationCoordSystem_)	\
    ( (This)->lpVtbl -> ActiveDevicePositionCoordsConvert(This,pArrayCoords_,sourceCoordSystem_,destinationCoordSystem_) ) 

#define IIMInspectProject7_ActiveDevicePositionNormalsConvert(This,pArrayNormals_,sourceCoordSystem_,destinationCoordSystem_)	\
    ( (This)->lpVtbl -> ActiveDevicePositionNormalsConvert(This,pArrayNormals_,sourceCoordSystem_,destinationCoordSystem_) ) 


#define IIMInspectProject7_DataCreateAsPlanarGrid2(This,ppIIMPlanarGrid_,pObjectName_,convertToPolygonal_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsPlanarGrid2(This,ppIIMPlanarGrid_,pObjectName_,convertToPolygonal_,interactiveState_) ) 

#define IIMInspectProject7_DataCreateAsLineScan2(This,ppIIMLineScan_,pObjectName_,extractNormals_,minSearchDist_,maxSearchDist_,extractHoleBoundaries_,minHoleWidth_,isTestingMode_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsLineScan2(This,ppIIMLineScan_,pObjectName_,extractNormals_,minSearchDist_,maxSearchDist_,extractHoleBoundaries_,minHoleWidth_,isTestingMode_,interactiveState_) ) 

#define IIMInspectProject7_DataCreateAsPointCloud2(This,ppIIMPointCloud_,pObjectName_,ptCloudType_,interactiveState_)	\
    ( (This)->lpVtbl -> DataCreateAsPointCloud2(This,ppIIMPointCloud_,pObjectName_,ptCloudType_,interactiveState_) ) 


#define IIMInspectProject7_ActiveDevicePositionDimensionsConvert(This,pArrayDimensions_,sourceCoordSystem_,destinationCoordSystem_)	\
    ( (This)->lpVtbl -> ActiveDevicePositionDimensionsConvert(This,pArrayDimensions_,sourceCoordSystem_,destinationCoordSystem_) ) 


#define IIMInspectProject7_DataCreateAsPolygonalModel(This,ppIIMPolygonalModel_,pObjectName_)	\
    ( (This)->lpVtbl -> DataCreateAsPolygonalModel(This,ppIIMPolygonalModel_,pObjectName_) ) 

#define IIMInspectProject7_DataObtainAsPolygonalModel(This,pUniqueID_,ppIIMPolygonalModel_)	\
    ( (This)->lpVtbl -> DataObtainAsPolygonalModel(This,pUniqueID_,ppIIMPolygonalModel_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMInspectProject7_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


