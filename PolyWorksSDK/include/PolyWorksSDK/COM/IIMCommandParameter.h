/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:46 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMCommandParameter.idl:
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

#ifndef __IIMCommandParameter_h__
#define __IIMCommandParameter_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMCommandParameter_FWD_DEFINED__
#define __IIMCommandParameter_FWD_DEFINED__
typedef interface IIMCommandParameter IIMCommandParameter;
#endif  /* __IIMCommandParameter_FWD_DEFINED__ */


#ifndef __IIMCommandParameterEnum_FWD_DEFINED__
#define __IIMCommandParameterEnum_FWD_DEFINED__
typedef interface IIMCommandParameterEnum IIMCommandParameterEnum;
#endif  /* __IIMCommandParameterEnum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifndef __IIMCommandParameter_INTERFACE_DEFINED__
#define __IIMCommandParameter_INTERFACE_DEFINED__

/* interface IIMCommandParameter */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandParameter;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "4962BF3D-E83F-4d1d-BF58-FF75DE33EBCF" )
IIMCommandParameter : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ParamDescGet(
        /* [retval][out] */ BSTR * pParamDesc_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamPossibleValuesGet(
        /* [retval][out] */ BSTR * pPossibleValuesList_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamDirGet(
        /* [retval][out] */ EParameterDirection * pParamDir_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamTypeGet(
        /* [retval][out] */ EParameterType * pParamType_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamDefaultDoubleValueGet(
        /* [out] */ double* pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamDefaultIntValueGet(
        /* [out] */ int* pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamDefaultStringValueGet(
        /* [out] */ BSTR * pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandParameterVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandParameter * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandParameter * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandParameter * This );

    HRESULT( STDMETHODCALLTYPE * ParamDescGet )(
        IIMCommandParameter * This,
        /* [retval][out] */ BSTR* pParamDesc_ );

    HRESULT( STDMETHODCALLTYPE * ParamPossibleValuesGet )(
        IIMCommandParameter * This,
        /* [retval][out] */ BSTR* pPossibleValuesList_ );

    HRESULT( STDMETHODCALLTYPE * ParamDirGet )(
        IIMCommandParameter * This,
        /* [retval][out] */ EParameterDirection* pParamDir_ );

    HRESULT( STDMETHODCALLTYPE * ParamTypeGet )(
        IIMCommandParameter * This,
        /* [retval][out] */ EParameterType* pParamType_ );

    HRESULT( STDMETHODCALLTYPE * ParamDefaultDoubleValueGet )(
        IIMCommandParameter * This,
        /* [out] */ double* pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ParamDefaultIntValueGet )(
        IIMCommandParameter * This,
        /* [out] */ int* pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ );

    HRESULT( STDMETHODCALLTYPE * ParamDefaultStringValueGet )(
        IIMCommandParameter * This,
        /* [out] */ BSTR* pDefaultValue_,
        /* [retval][out] */ long* pReturnVal_ );

    END_INTERFACE
} IIMCommandParameterVtbl;

interface IIMCommandParameter
{
    CONST_VTBL struct IIMCommandParameterVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandParameter_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandParameter_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandParameter_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandParameter_ParamDescGet( This, pParamDesc_ )  \
    ( ( This )->lpVtbl->ParamDescGet( This, pParamDesc_ ) )

#define IIMCommandParameter_ParamPossibleValuesGet( This, pPossibleValuesList_ )   \
    ( ( This )->lpVtbl->ParamPossibleValuesGet( This, pPossibleValuesList_ ) )

#define IIMCommandParameter_ParamDirGet( This, pParamDir_ )    \
    ( ( This )->lpVtbl->ParamDirGet( This, pParamDir_ ) )

#define IIMCommandParameter_ParamTypeGet( This, pParamType_ )  \
    ( ( This )->lpVtbl->ParamTypeGet( This, pParamType_ ) )

#define IIMCommandParameter_ParamDefaultDoubleValueGet( This, pDefaultValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ParamDefaultDoubleValueGet( This, pDefaultValue_, pReturnVal_ ) )

#define IIMCommandParameter_ParamDefaultIntValueGet( This, pDefaultValue_, pReturnVal_ )    \
    ( ( This )->lpVtbl->ParamDefaultIntValueGet( This, pDefaultValue_, pReturnVal_ ) )

#define IIMCommandParameter_ParamDefaultStringValueGet( This, pDefaultValue_, pReturnVal_ ) \
    ( ( This )->lpVtbl->ParamDefaultStringValueGet( This, pDefaultValue_, pReturnVal_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandParameter_INTERFACE_DEFINED__ */


#ifndef __IIMCommandParameterEnum_INTERFACE_DEFINED__
#define __IIMCommandParameterEnum_INTERFACE_DEFINED__

/* interface IIMCommandParameterEnum */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMCommandParameterEnum;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "75DE1FD0-BCE3-4bff-910F-E22034ED27D1" )
IIMCommandParameterEnum : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ParamsGetNb(
        /* [retval][out] */ long* pParamNb_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ParamGet(
        /* [in] */ long number_,
        /* [out] */ IIMCommandParameter * *pIIMCommandParameter_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMCommandParameterEnumVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMCommandParameterEnum * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMCommandParameterEnum * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMCommandParameterEnum * This );

    HRESULT( STDMETHODCALLTYPE * ParamsGetNb )(
        IIMCommandParameterEnum * This,
        /* [retval][out] */ long* pParamNb_ );

    HRESULT( STDMETHODCALLTYPE * ParamGet )(
        IIMCommandParameterEnum * This,
        /* [in] */ long number_,
        /* [out] */ IIMCommandParameter** pIIMCommandParameter_ );

    END_INTERFACE
} IIMCommandParameterEnumVtbl;

interface IIMCommandParameterEnum
{
    CONST_VTBL struct IIMCommandParameterEnumVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMCommandParameterEnum_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMCommandParameterEnum_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMCommandParameterEnum_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMCommandParameterEnum_ParamsGetNb( This, pParamNb_ ) \
    ( ( This )->lpVtbl->ParamsGetNb( This, pParamNb_ ) )

#define IIMCommandParameterEnum_ParamGet( This, number_, pIIMCommandParameter_ )    \
    ( ( This )->lpVtbl->ParamGet( This, number_, pIIMCommandParameter_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMCommandParameterEnum_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMCommandParameter_h__
