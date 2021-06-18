/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:53 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMAlignProject.idl:
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

#ifndef __IIMAlignProject_h__
#define __IIMAlignProject_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMAlignProject_FWD_DEFINED__
#define __IIMAlignProject_FWD_DEFINED__
typedef interface IIMAlignProject IIMAlignProject;
#endif  /* __IIMAlignProject_FWD_DEFINED__ */


#ifndef __IIMAlignProject2_FWD_DEFINED__
#define __IIMAlignProject2_FWD_DEFINED__
typedef interface IIMAlignProject2 IIMAlignProject2;
#endif  /* __IIMAlignProject2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMPlanarGrid.h"
#include "IIMLineScan.h"
#include "IIMCommandCenter.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMAlignProject_INTERFACE_DEFINED__
#define __IIMAlignProject_INTERFACE_DEFINED__

/* interface IIMAlignProject */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMAlignProject;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "bc73d74e-4842-11d7-93aa-00b0d0224d3a" )
IIMAlignProject : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CommandCenterCreate(
        /* [out] */ IIMCommandCenter * *ppIIMCommandCenter_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMAlignProjectVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMAlignProject * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMAlignProject * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMAlignProject * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMAlignProject * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    END_INTERFACE
} IIMAlignProjectVtbl;

interface IIMAlignProject
{
    CONST_VTBL struct IIMAlignProjectVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMAlignProject_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMAlignProject_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMAlignProject_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMAlignProject_CommandCenterCreate( This, ppIIMCommandCenter_ )   \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMAlignProject_INTERFACE_DEFINED__ */


#ifndef __IIMAlignProject2_INTERFACE_DEFINED__
#define __IIMAlignProject2_INTERFACE_DEFINED__

/* interface IIMAlignProject2 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMAlignProject2;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "8F34B679-1F5B-47d0-9BFB-0E5550AB91A5" )
IIMAlignProject2 : public IIMAlignProject
{
public:
    virtual HRESULT STDMETHODCALLTYPE ImageCreateAsPlanarGrid(
        /* [out] */ IIMPlanarGrid * *ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR * pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR * pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ = ( VARIANT_BOOL )-1 ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ImageCreateAsLineScan(
        /* [out] */ IIMLineScan * *ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR * pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR * pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isTestingMode_ = ( VARIANT_BOOL )0,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ = ( VARIANT_BOOL )-1 ) = 0;

};

#else   /* C style interface */

typedef struct IIMAlignProject2Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMAlignProject2 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMAlignProject2 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMAlignProject2 * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMAlignProject2 * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    HRESULT( STDMETHODCALLTYPE * ImageCreateAsPlanarGrid )(
        IIMAlignProject2 * This,
        /* [out] */ IIMPlanarGrid** ppIIMPlanarGrid_,
        /* [full][unique][string][in] */ const OLECHAR* pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ );

    HRESULT( STDMETHODCALLTYPE * ImageCreateAsLineScan )(
        IIMAlignProject2 * This,
        /* [out] */ IIMLineScan** ppIIMLineScan_,
        /* [full][unique][string][in] */ const OLECHAR* pImagesBaseName_,
        /* [full][unique][string][in] */ const OLECHAR* pSharedMatrixName_,
        /* [in] */ double maxEdgeLength_,
        /* [in] */ double step_,
        /* [in] */ double maxAngle_,
        /* [defaultvalue][in] */ VARIANT_BOOL isTestingMode_,
        /* [defaultvalue][in] */ VARIANT_BOOL isInteractive_ );

    END_INTERFACE
} IIMAlignProject2Vtbl;

interface IIMAlignProject2
{
    CONST_VTBL struct IIMAlignProject2Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMAlignProject2_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMAlignProject2_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMAlignProject2_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMAlignProject2_CommandCenterCreate( This, ppIIMCommandCenter_ )  \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )


#define IIMAlignProject2_ImageCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isInteractive_ )   \
    ( ( This )->lpVtbl->ImageCreateAsPlanarGrid( This, ppIIMPlanarGrid_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isInteractive_ ) )

#define IIMAlignProject2_ImageCreateAsLineScan( This, ppIIMLineScan_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isTestingMode_, isInteractive_ )    \
    ( ( This )->lpVtbl->ImageCreateAsLineScan( This, ppIIMLineScan_, pImagesBaseName_, pSharedMatrixName_, maxEdgeLength_, step_, maxAngle_, isTestingMode_, isInteractive_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMAlignProject2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMAlignProject_h__
