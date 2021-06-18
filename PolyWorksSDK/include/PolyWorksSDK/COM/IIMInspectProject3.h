/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:46:53 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectProject3.idl:
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

#ifndef __IIMInspectProject3_h__
#define __IIMInspectProject3_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMInspectProject3_FWD_DEFINED__
#define __IIMInspectProject3_FWD_DEFINED__
typedef interface IIMInspectProject3 IIMInspectProject3;
#endif  /* __IIMInspectProject3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMInspectProject.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMInspectProject3_INTERFACE_DEFINED__
#define __IIMInspectProject3_INTERFACE_DEFINED__

/* interface IIMInspectProject3 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMInspectProject3;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "6CF6EC51-59EF-4238-98C3-989A62B9E23E" )
IIMInspectProject3 : public IIMInspectProject2
{
public:
    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionMatrixGet(
        /* [out][in] */ SAFEARRAY * *pTransMat_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionMatrixSet(
        /* [in] */ SAFEARRAY * *pTransMat_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMInspectProject3Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMInspectProject3 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMInspectProject3 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMInspectProject3 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMInspectProject3 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * PointCloudCreateData )(
        IIMInspectProject3 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [defaultvalue][in] */ long interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPlanarGrid )(
        IIMInspectProject3 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL convertToPolygonal_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsLineScan )(
        IIMInspectProject3 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ VARIANT_BOOL extractNormals_,
        /* [in] */ double minSearchDist_,
        /* [in] */ double maxSearchDist_,
        /* [in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * DataCreateAsPointCloud )(
        IIMInspectProject3 * This,
        /* [out] */ IIMPointCloud** ppIIMPointCloud_,
        /* [full][unique][string][in] */ const OLECHAR* pObjectName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [defaultvalue][in] */ VARIANT_BOOL interactiveState_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixGet )(
        IIMInspectProject3 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixSet )(
        IIMInspectProject3 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    END_INTERFACE
} IIMInspectProject3Vtbl;

interface IIMInspectProject3
{
    CONST_VTBL struct IIMInspectProject3Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMInspectProject3_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMInspectProject3_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMInspectProject3_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMInspectProject3_CommandCenterCreate( This, ppIIMCommandCenter_ )    \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#define IIMInspectProject3_PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ )   \
    ( ( This )->lpVtbl->PointCloudCreateData( This, ppIIMPointCloud_, pObjectName_, interactiveState_ ) )


#define IIMInspectProject3_DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pObjectName_, pSharedMatrixName_, convertToPolygonal_, interactiveState_ ) )

#define IIMInspectProject3_DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) \
    ( ( This )->lpVtbl->DataCreateAsLineScan( This, ppIIMLineScan_, pObjectName_, pSharedMatrixName_, extractNormals_, minSearchDist_, maxSearchDist_, isTestingMode_, interactiveState_ ) )

#define IIMInspectProject3_DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ )  \
    ( ( This )->lpVtbl->DataCreateAsPointCloud( This, ppIIMPointCloud_, pObjectName_, pSharedMatrixName_, interactiveState_ ) )


#define IIMInspectProject3_ActiveDevicePositionMatrixGet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixGet( This, pTransMat_ ) )

#define IIMInspectProject3_ActiveDevicePositionMatrixSet( This, pTransMat_ )   \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixSet( This, pTransMat_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMInspectProject3_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMInspectProject3_h__
