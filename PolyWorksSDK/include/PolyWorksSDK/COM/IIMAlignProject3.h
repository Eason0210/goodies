/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:46:53 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMAlignProject3.idl:
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

#ifndef __IIMAlignProject3_h__
#define __IIMAlignProject3_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMAlignProject3_FWD_DEFINED__
#define __IIMAlignProject3_FWD_DEFINED__
typedef interface IIMAlignProject3 IIMAlignProject3;
#endif  /* __IIMAlignProject3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMAlignProject.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMAlignProject3_INTERFACE_DEFINED__
#define __IIMAlignProject3_INTERFACE_DEFINED__

/* interface IIMAlignProject3 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMAlignProject3;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "D3A667EB-5473-4e6b-82FC-9EF334692C78" )
IIMAlignProject3 : public IIMAlignProject2
{
public:
    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionMatrixGet(
        /* [out][in] */ SAFEARRAY * *pTransMat_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ActiveDevicePositionMatrixSet(
        /* [in] */ SAFEARRAY * *pTransMat_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMAlignProject3Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMAlignProject3 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMAlignProject3 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMAlignProject3 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMAlignProject3 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * ImageCreateAsPlanarGrid )(
        IIMAlignProject3 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ );

    HRESULT( STDMETHODCALLTYPE * ImageCreateAsLineScan )(
        IIMAlignProject3 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixGet )(
        IIMAlignProject3 * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * ActiveDevicePositionMatrixSet )(
        IIMAlignProject3 * This,
        /* [in] */ SAFEARRAY** pTransMat_ );

    END_INTERFACE
} IIMAlignProject3Vtbl;

interface IIMAlignProject3
{
    CONST_VTBL struct IIMAlignProject3Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMAlignProject3_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMAlignProject3_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMAlignProject3_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMAlignProject3_CommandCenterCreate( This, ppIIMCommandCenter_ )  \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )


#define IIMAlignProject3_ImageCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isInteractive_ )   \
    ( ( This )->lpVtbl->ImageCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isInteractive_ ) )

#define IIMAlignProject3_ImageCreateAsLineScan( This, ppIIMLineScan_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isTestingMode_, isInteractive_ )    \
    ( ( This )->lpVtbl->ImageCreateAsLineScan( This, ppIIMLineScan_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isTestingMode_, isInteractive_ ) )


#define IIMAlignProject3_ActiveDevicePositionMatrixGet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixGet( This, pTransMat_ ) )

#define IIMAlignProject3_ActiveDevicePositionMatrixSet( This, pTransMat_ ) \
    ( ( This )->lpVtbl->ActiveDevicePositionMatrixSet( This, pTransMat_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMAlignProject3_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMAlignProject3_h__
