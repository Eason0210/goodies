/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 26 09:36:09 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMScanner.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555
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

#ifndef __IIMScanner_h__
#define __IIMScanner_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanner_FWD_DEFINED__
#define __IIMScanner_FWD_DEFINED__
typedef interface IIMScanner IIMScanner;
#endif  /* __IIMScanner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScannerFeedback.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanner_INTERFACE_DEFINED__
#define __IIMScanner_INTERFACE_DEFINED__

/* interface IIMScanner */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanner;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "C683B927-E601-4aad-BB20-19288B90B9BA" )
IIMScanner : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ScanningDeviceNameGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningConnectionInit(
        /* [in] */ IIMScannerFeedback * pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningConnectionEnd(
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningDlgShow( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanningDlgClose( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanNameDefaultGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ScanNameSet(
        /* [in] */ BSTR name_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshMaxEdgeLengthGet(
        /* [retval][out] */ double* pMaxEdgeLength_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshMaxEdgeLengthSet(
        /* [in] */ double maxEdgeLength_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshInterpolationStepGet(
        /* [retval][out] */ double* pInterpolationStep_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshInterpolationStepSet(
        /* [in] */ double interpolationStep_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshMaxAngleGet(
        /* [retval][out] */ double* pMaxAngle_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE MeshMaxAngleSet(
        /* [in] */ double maxAngle_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScannerVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanner * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanner * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMScanner * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScanner * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMScanner * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMScanner * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMScanner * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMScanner * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMScanner * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMScanner * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMScanner * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMScanner * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMScanner * This,
        /* [in] */ double maxAngle_ );

    END_INTERFACE
} IIMScannerVtbl;

interface IIMScanner
{
    CONST_VTBL struct IIMScannerVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanner_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanner_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanner_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanner_ScanningDeviceNameGet( This, pName_ )   \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMScanner_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )   \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMScanner_ScanningConnectionEnd( This, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMScanner_ScanningDlgShow( This )    \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMScanner_ScanningDlgClose( This )   \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMScanner_ScanNameDefaultGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMScanner_ScanNameSet( This, name_ )  \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMScanner_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMScanner_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )    \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMScanner_MeshInterpolationStepGet( This, pInterpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMScanner_MeshInterpolationStepSet( This, interpolationStep_ )    \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMScanner_MeshMaxAngleGet( This, pMaxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMScanner_MeshMaxAngleSet( This, maxAngle_ )  \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanner_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScanner_h__
