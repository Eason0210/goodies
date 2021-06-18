/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:49:02 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMDeviceLevelFeedback.idl:
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

#ifndef __IIMDeviceLevelFeedback_h__
#define __IIMDeviceLevelFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMDeviceLevelFeedback_FWD_DEFINED__
#define __IIMDeviceLevelFeedback_FWD_DEFINED__
typedef interface IIMDeviceLevelFeedback IIMDeviceLevelFeedback;
#endif  /* __IIMDeviceLevelFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMDeviceLevel.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMDeviceLevelFeedback_INTERFACE_DEFINED__
#define __IIMDeviceLevelFeedback_INTERFACE_DEFINED__

/* interface IIMDeviceLevelFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMDeviceLevelFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "6F3E9EED-DFC5-44dc-88D4-5F04833910F2" )
IIMDeviceLevelFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE LevelCompensationStatusSet(
        /* [in] */ ELevelCompensationStatus status_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UseLevelCompensationSet(
        /* [in] */ VARIANT_BOOL useLevelCompensation_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMDeviceLevelFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMDeviceLevelFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMDeviceLevelFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMDeviceLevelFeedback * This );

    HRESULT( STDMETHODCALLTYPE * LevelCompensationStatusSet )(
        IIMDeviceLevelFeedback * This,
        /* [in] */ ELevelCompensationStatus status_ );

    HRESULT( STDMETHODCALLTYPE * UseLevelCompensationSet )(
        IIMDeviceLevelFeedback * This,
        /* [in] */ VARIANT_BOOL useLevelCompensation_ );

    END_INTERFACE
} IIMDeviceLevelFeedbackVtbl;

interface IIMDeviceLevelFeedback
{
    CONST_VTBL struct IIMDeviceLevelFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMDeviceLevelFeedback_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMDeviceLevelFeedback_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMDeviceLevelFeedback_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMDeviceLevelFeedback_LevelCompensationStatusSet( This, status_ ) \
    ( ( This )->lpVtbl->LevelCompensationStatusSet( This, status_ ) )

#define IIMDeviceLevelFeedback_UseLevelCompensationSet( This, useLevelCompensation_ )  \
    ( ( This )->lpVtbl->UseLevelCompensationSet( This, useLevelCompensation_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMDeviceLevelFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMDeviceLevelFeedback_h__
