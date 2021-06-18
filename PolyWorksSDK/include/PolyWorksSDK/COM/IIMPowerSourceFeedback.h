/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:49:03 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMPowerSourceFeedback.idl:
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

#ifndef __IIMPowerSourceFeedback_h__
#define __IIMPowerSourceFeedback_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMPowerSourceFeedback_FWD_DEFINED__
#define __IIMPowerSourceFeedback_FWD_DEFINED__
typedef interface IIMPowerSourceFeedback IIMPowerSourceFeedback;
#endif  /* __IIMPowerSourceFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMPowerSourceFeedback_INTERFACE_DEFINED__
#define __IIMPowerSourceFeedback_INTERFACE_DEFINED__

/* interface IIMPowerSourceFeedback */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMPowerSourceFeedback;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "4DC9C178-B854-4e2f-AF3B-A238346D7ED6" )
IIMPowerSourceFeedback : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE PowerStatusSet(
        /* [in] */ EPowerSources source_,
        /* [in] */ short batteryLevelPercentage_,
        /* [in] */ BSTR details_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMPowerSourceFeedbackVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMPowerSourceFeedback * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMPowerSourceFeedback * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMPowerSourceFeedback * This );

    HRESULT( STDMETHODCALLTYPE * PowerStatusSet )(
        IIMPowerSourceFeedback * This,
        /* [in] */ EPowerSources source_,
        /* [in] */ short batteryLevelPercentage_,
        /* [in] */ BSTR details_ );

    END_INTERFACE
} IIMPowerSourceFeedbackVtbl;

interface IIMPowerSourceFeedback
{
    CONST_VTBL struct IIMPowerSourceFeedbackVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMPowerSourceFeedback_QueryInterface( This, riid, ppvObject )  \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMPowerSourceFeedback_AddRef( This ) \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMPowerSourceFeedback_Release( This )    \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMPowerSourceFeedback_PowerStatusSet( This, source_, batteryLevelPercentage_, details_ )    \
    ( ( This )->lpVtbl->PowerStatusSet( This, source_, batteryLevelPercentage_, details_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMPowerSourceFeedback_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMPowerSourceFeedback_h__
