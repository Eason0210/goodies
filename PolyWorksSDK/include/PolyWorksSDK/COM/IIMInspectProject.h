/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:56 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectProject.idl:
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

#ifndef __IIMInspectProject_h__
#define __IIMInspectProject_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInspectProject_FWD_DEFINED__
#define __IIMInspectProject_FWD_DEFINED__
typedef interface IIMInspectProject IIMInspectProject;
#endif  /* __IIMInspectProject_FWD_DEFINED__ */


#ifndef __IIMInspectProject2_FWD_DEFINED__
#define __IIMInspectProject2_FWD_DEFINED__
typedef interface IIMInspectProject2 IIMInspectProject2;
#endif  /* __IIMInspectProject2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMCommandCenter.h"
#include "IIMPlanarGrid.h"
#include "IIMLineScan.h"
#include "IIMPointCloud.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInspectProject_INTERFACE_DEFINED__
#define __IIMInspectProject_INTERFACE_DEFINED__

/* interface IIMInspectProject */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspectProject;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2d90e82a-1460-11d7-9397-00b0d0224d3a" )
IIMInspectProject : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CommandCenterCreate(
        /* [out] */ IIMCommandCenter * *ppIIMCommandCenter_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE PointCloudCreateData(
        /* [out] */ IIMPointCloud * *ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ = 1 ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectProjectVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspectProject * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspectProject * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspectProject * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMInspectProject * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * PointCloudCreateData )(
        IIMInspectProject * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ );

    END_INTERFACE
} IIMInspectProjectVtbl;

interface IIMInspectProject
{
    CONST_VTBL struct IIMInspectProjectVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspectProject_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspectProject_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspectProject_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspectProject_CommandCenterCreate( This, ppIIMCommandCenter_ ) \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#define IIMInspectProject_PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ )    \
    ( ( This )->lpVtbl->PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspectProject_INTERFACE_DEFINED__ */


#ifndef __IIMInspectProject2_INTERFACE_DEFINED__
#define __IIMInspectProject2_INTERFACE_DEFINED__

/* interface IIMInspectProject2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspectProject2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2F23629A-AF73-4c2e-97D2-6888F655F7EE" )
IIMInspectProject2 : public IIMInspectProject
{
public:
    virtual HRESULT STDMETHODCALLTYPE DataCreateAsPlanarGrid(
        /* [out] */ IIMPlanarGrid * *ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR * pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DataCreateAsLineScan(
        /* [out] */ IIMLineScan * *ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR * pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DataCreateAsPointCloud(
        /* [out] */ IIMPointCloud * *ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR * pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR * pSharedMatrixName_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ = ( VARIANT_BOOL )-1 ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectProject2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspectProject2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspectProject2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspectProject2 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMInspectProject2 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * PointCloudCreateData )(
        IIMInspectProject2 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPlanarGrid )(
        IIMInspectProject2 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsLineScan )(
        IIMInspectProject2 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPointCloud )(
        IIMInspectProject2 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    END_INTERFACE
} IIMInspectProject2Vtbl;

interface IIMInspectProject2
{
    CONST_VTBL struct IIMInspectProject2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspectProject2_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspectProject2_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspectProject2_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspectProject2_CommandCenterCreate( This, ppIIMCommandCenter_ )    \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#define IIMInspectProject2_PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ )   \
    ( ( This )->lpVtbl->PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ ) )


#define IIMInspectProject2_DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ ) )

#define IIMInspectProject2_DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) \
    ( ( This )->lpVtbl->DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) )

#define IIMInspectProject2_DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspectProject2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInspectProject_h__
