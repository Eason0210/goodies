/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Wed Jul 15 15:29:53 2015
 */
/* Compiler settings for ..\..\Interfaces\IIMScanner4.idl:
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

#ifndef __IIMScanner4_h__
#define __IIMScanner4_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMScanner4_FWD_DEFINED__
#define __IIMScanner4_FWD_DEFINED__
typedef interface IIMScanner4 IIMScanner4;
#endif  /* __IIMScanner4_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScanner3.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMScanner4_INTERFACE_DEFINED__
#define __IIMScanner4_INTERFACE_DEFINED__

/* interface IIMScanner4 */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMScanner4;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "5BD73280-0D69-4F1F-82B2-E6B012F84A26" )
IIMScanner4 : public IIMScanner3
{
public:
    virtual HRESULT STDMETHODCALLTYPE DeviceDeprecatedNamesGet(
        /* [out][in] */ SAFEARRAY * *pNames_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMScanner4Vtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMScanner4 * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMScanner4 * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMScanner4 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceNameGet )(
        IIMScanner4 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionInit )(
        IIMScanner4 * This,
        /* [in] */ IIMScannerFeedback* pScannerFeedback_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningConnectionEnd )(
        IIMScanner4 * This,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgShow )(
        IIMScanner4 * This );

    HRESULT( STDMETHODCALLTYPE * ScanningDlgClose )(
        IIMScanner4 * This );

    HRESULT( STDMETHODCALLTYPE * ScanNameDefaultGet )(
        IIMScanner4 * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * ScanNameSet )(
        IIMScanner4 * This,
        /* [in] */ BSTR name_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthGet )(
        IIMScanner4 * This,
        /* [retval][out] */ double* pMaxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxEdgeLengthSet )(
        IIMScanner4 * This,
        /* [in] */ double maxEdgeLength_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepGet )(
        IIMScanner4 * This,
        /* [retval][out] */ double* pInterpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshInterpolationStepSet )(
        IIMScanner4 * This,
        /* [in] */ double interpolationStep_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleGet )(
        IIMScanner4 * This,
        /* [retval][out] */ double* pMaxAngle_ );

    HRESULT( STDMETHODCALLTYPE * MeshMaxAngleSet )(
        IIMScanner4 * This,
        /* [in] */ double maxAngle_ );

    HRESULT( STDMETHODCALLTYPE * ScanningDeviceMenuLocationGet )(
        IIMScanner4 * This,
        /* [retval][out] */ BSTR* pMenuPath_ );

    HRESULT( STDMETHODCALLTYPE * OnScanningEvent )(
        IIMScanner4 * This,
        /* [in] */ EScanningEvents event_ );

    HRESULT( STDMETHODCALLTYPE * DeviceDeprecatedNamesGet )(
        IIMScanner4 * This,
        /* [out][in] */ SAFEARRAY** pNames_ );

    END_INTERFACE
} IIMScanner4Vtbl;

interface IIMScanner4
{
    CONST_VTBL struct IIMScanner4Vtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMScanner4_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMScanner4_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMScanner4_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMScanner4_ScanningDeviceNameGet( This, pName_ )  \
    ( ( This )->lpVtbl->ScanningDeviceNameGet( This, pName_ ) )

#define IIMScanner4_ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ )  \
    ( ( This )->lpVtbl->ScanningConnectionInit( This, pScannerFeedback_, pReturnVal_ ) )

#define IIMScanner4_ScanningConnectionEnd( This, pReturnVal_ ) \
    ( ( This )->lpVtbl->ScanningConnectionEnd( This, pReturnVal_ ) )

#define IIMScanner4_ScanningDlgShow( This )   \
    ( ( This )->lpVtbl->ScanningDlgShow( This ) )

#define IIMScanner4_ScanningDlgClose( This )  \
    ( ( This )->lpVtbl->ScanningDlgClose( This ) )

#define IIMScanner4_ScanNameDefaultGet( This, pName_ ) \
    ( ( This )->lpVtbl->ScanNameDefaultGet( This, pName_ ) )

#define IIMScanner4_ScanNameSet( This, name_ ) \
    ( ( This )->lpVtbl->ScanNameSet( This, name_ ) )

#define IIMScanner4_MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ )  \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthGet( This, pMaxEdgeLength_ ) )

#define IIMScanner4_MeshMaxEdgeLengthSet( This, maxEdgeLength_ )   \
    ( ( This )->lpVtbl->MeshMaxEdgeLengthSet( This, maxEdgeLength_ ) )

#define IIMScanner4_MeshInterpolationStepGet( This, pInterpolationStep_ )  \
    ( ( This )->lpVtbl->MeshInterpolationStepGet( This, pInterpolationStep_ ) )

#define IIMScanner4_MeshInterpolationStepSet( This, interpolationStep_ )   \
    ( ( This )->lpVtbl->MeshInterpolationStepSet( This, interpolationStep_ ) )

#define IIMScanner4_MeshMaxAngleGet( This, pMaxAngle_ )    \
    ( ( This )->lpVtbl->MeshMaxAngleGet( This, pMaxAngle_ ) )

#define IIMScanner4_MeshMaxAngleSet( This, maxAngle_ ) \
    ( ( This )->lpVtbl->MeshMaxAngleSet( This, maxAngle_ ) )


#define IIMScanner4_ScanningDeviceMenuLocationGet( This, pMenuPath_ )  \
    ( ( This )->lpVtbl->ScanningDeviceMenuLocationGet( This, pMenuPath_ ) )


#define IIMScanner4_OnScanningEvent( This, event_ )    \
    ( ( This )->lpVtbl->OnScanningEvent( This, event_ ) )


#define IIMScanner4_DeviceDeprecatedNamesGet( This, pNames_ )  \
    ( ( This )->lpVtbl->DeviceDeprecatedNamesGet( This, pNames_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMScanner4_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMScanner4_h__
