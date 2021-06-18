/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:58 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMWorkspaceManager.idl:
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

#ifndef __IIMWorkspaceManager_h__
#define __IIMWorkspaceManager_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMWorkspaceManager_FWD_DEFINED__
#define __IIMWorkspaceManager_FWD_DEFINED__
typedef interface IIMWorkspaceManager IIMWorkspaceManager;
#endif  /* __IIMWorkspaceManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMCommandCenter.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMWorkspaceManager_INTERFACE_DEFINED__
#define __IIMWorkspaceManager_INTERFACE_DEFINED__

/* interface IIMWorkspaceManager */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMWorkspaceManager;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "8FE51247-3886-4BD5-B2F2-746AC21A8FD2" )
IIMWorkspaceManager : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE CommandCenterCreate(
        /* [out] */ IIMCommandCenter * *ppIIMCommandCenter_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMWorkspaceManagerVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMWorkspaceManager * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMWorkspaceManager * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMWorkspaceManager * This );

    HRESULT( STDMETHODCALLTYPE * CommandCenterCreate )(
        IIMWorkspaceManager * This,
        /* [out] */ IIMCommandCenter** ppIIMCommandCenter_ );

    END_INTERFACE
} IIMWorkspaceManagerVtbl;

interface IIMWorkspaceManager
{
    CONST_VTBL struct IIMWorkspaceManagerVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMWorkspaceManager_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMWorkspaceManager_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMWorkspaceManager_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMWorkspaceManager_CommandCenterCreate( This, ppIIMCommandCenter_ )   \
    ( ( This )->lpVtbl->CommandCenterCreate( This, ppIIMCommandCenter_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMWorkspaceManager_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMWorkspaceManager_h__
