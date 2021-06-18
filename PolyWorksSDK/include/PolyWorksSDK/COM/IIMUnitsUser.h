/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:46:52 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMUnitsUser.idl:
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

#ifndef __IIMUnitsUser_h__
#define __IIMUnitsUser_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMUnitsUser_FWD_DEFINED__
#define __IIMUnitsUser_FWD_DEFINED__
typedef interface IIMUnitsUser IIMUnitsUser;
#endif  /* __IIMUnitsUser_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMUnitsUser_INTERFACE_DEFINED__
#define __IIMUnitsUser_INTERFACE_DEFINED__

/* interface IIMUnitsUser */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMUnitsUser;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2E4984B7-2359-4458-BB97-F7E20CCE2C3F" )
IIMUnitsUser : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE UnitsScalingFactorSet(
        /* [in] */ double scalingFactor_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMUnitsUserVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMUnitsUser * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMUnitsUser * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMUnitsUser * This );

    HRESULT( STDMETHODCALLTYPE * UnitsScalingFactorSet )(
        IIMUnitsUser * This,
        /* [in] */ double scalingFactor_ );

    END_INTERFACE
} IIMUnitsUserVtbl;

interface IIMUnitsUser
{
    CONST_VTBL struct IIMUnitsUserVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMUnitsUser_QueryInterface( This, riid, ppvObject )    \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMUnitsUser_AddRef( This )   \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMUnitsUser_Release( This )  \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMUnitsUser_UnitsScalingFactorSet( This, scalingFactor_ ) \
    ( ( This )->lpVtbl->UnitsScalingFactorSet( This, scalingFactor_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMUnitsUser_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMUnitsUser_h__
