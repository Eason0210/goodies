/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:44 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSharedMatrix.idl:
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

#ifndef __IIMSharedMatrix_h__
#define __IIMSharedMatrix_h__

#if defined( _MSC_VER ) && ( _MSC_VER >= 1020 )
#pragma once
#endif

/* Forward Declarations */

#ifndef __IIMSharedMatrix_FWD_DEFINED__
#define __IIMSharedMatrix_FWD_DEFINED__
typedef interface IIMSharedMatrix IIMSharedMatrix;
#endif  /* __IIMSharedMatrix_FWD_DEFINED__ */


#ifndef __IIMSharedMatrixUser_FWD_DEFINED__
#define __IIMSharedMatrixUser_FWD_DEFINED__
typedef interface IIMSharedMatrixUser IIMSharedMatrixUser;
#endif  /* __IIMSharedMatrixUser_FWD_DEFINED__ */


#ifndef __IIMSharedMatrixRepository_FWD_DEFINED__
#define __IIMSharedMatrixRepository_FWD_DEFINED__
typedef interface IIMSharedMatrixRepository IIMSharedMatrixRepository;
#endif  /* __IIMSharedMatrixRepository_FWD_DEFINED__ */


#ifndef __IIMSharedMatrixRepositoryClient_FWD_DEFINED__
#define __IIMSharedMatrixRepositoryClient_FWD_DEFINED__
typedef interface IIMSharedMatrixRepositoryClient IIMSharedMatrixRepositoryClient;
#endif  /* __IIMSharedMatrixRepositoryClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif


/* interface __MIDL_itf_IIMSharedMatrix_0000_0000 */
/* [local] */





extern RPC_IF_HANDLE __MIDL_itf_IIMSharedMatrix_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMSharedMatrix_0000_0000_v0_0_s_ifspec;

#ifndef __IIMSharedMatrix_INTERFACE_DEFINED__
#define __IIMSharedMatrix_INTERFACE_DEFINED__

/* interface IIMSharedMatrix */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSharedMatrix;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "99BE6AD2-387E-4309-9A96-5BA7BECCFDFC" )
IIMSharedMatrix : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE NameGet(
        /* [retval][out] */ BSTR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE NameSet(
        /* [full][unique][string][in] */ const OLECHAR * pName_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransformationMatrixGet(
        /* [out][in] */ SAFEARRAY * *pTransMat_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE TransformationMatrixSet(
        /* [in] */ SAFEARRAY * *pTransMat_,
        /* [in] */ VARIANT_BOOL updateUsers_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UserAdd(
        /* [in] */ IIMSharedMatrixUser * pUser_,
        /* [retval][out] */ long* pUserID_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UserGet(
        /* [in] */ long userIndex_,
        /* [out][in] */ IIMSharedMatrixUser * *ppUser_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UserRemove(
        /* [in] */ long userID_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UsersGetNb(
        /* [retval][out] */ long* pNbUsers_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UsersUpdateEnableGet(
        /* [retval][out] */ VARIANT_BOOL * pEnable_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UsersUpdateEnableSet(
        /* [in] */ VARIANT_BOOL enable_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSharedMatrixVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSharedMatrix * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSharedMatrix * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSharedMatrix * This );

    HRESULT( STDMETHODCALLTYPE * NameGet )(
        IIMSharedMatrix * This,
        /* [retval][out] */ BSTR* pName_ );

    HRESULT( STDMETHODCALLTYPE * NameSet )(
        IIMSharedMatrix * This,
        /* [full][unique][string][in] */ const OLECHAR* pName_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixGet )(
        IIMSharedMatrix * This,
        /* [out][in] */ SAFEARRAY** pTransMat_ );

    HRESULT( STDMETHODCALLTYPE * TransformationMatrixSet )(
        IIMSharedMatrix * This,
        /* [in] */ SAFEARRAY** pTransMat_,
        /* [in] */ VARIANT_BOOL updateUsers_ );

    HRESULT( STDMETHODCALLTYPE * UserAdd )(
        IIMSharedMatrix * This,
        /* [in] */ IIMSharedMatrixUser* pUser_,
        /* [retval][out] */ long* pUserID_ );

    HRESULT( STDMETHODCALLTYPE * UserGet )(
        IIMSharedMatrix * This,
        /* [in] */ long userIndex_,
        /* [out][in] */ IIMSharedMatrixUser** ppUser_ );

    HRESULT( STDMETHODCALLTYPE * UserRemove )(
        IIMSharedMatrix * This,
        /* [in] */ long userID_ );

    HRESULT( STDMETHODCALLTYPE * UsersGetNb )(
        IIMSharedMatrix * This,
        /* [retval][out] */ long* pNbUsers_ );

    HRESULT( STDMETHODCALLTYPE * UsersUpdateEnableGet )(
        IIMSharedMatrix * This,
        /* [retval][out] */ VARIANT_BOOL* pEnable_ );

    HRESULT( STDMETHODCALLTYPE * UsersUpdateEnableSet )(
        IIMSharedMatrix * This,
        /* [in] */ VARIANT_BOOL enable_ );

    END_INTERFACE
} IIMSharedMatrixVtbl;

interface IIMSharedMatrix
{
    CONST_VTBL struct IIMSharedMatrixVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSharedMatrix_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSharedMatrix_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSharedMatrix_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSharedMatrix_NameGet( This, pName_ )    \
    ( ( This )->lpVtbl->NameGet( This, pName_ ) )

#define IIMSharedMatrix_NameSet( This, pName_ )    \
    ( ( This )->lpVtbl->NameSet( This, pName_ ) )

#define IIMSharedMatrix_TransformationMatrixGet( This, pTransMat_ )    \
    ( ( This )->lpVtbl->TransformationMatrixGet( This, pTransMat_ ) )

#define IIMSharedMatrix_TransformationMatrixSet( This, pTransMat_, updateUsers_ )   \
    ( ( This )->lpVtbl->TransformationMatrixSet( This, pTransMat_, updateUsers_ ) )

#define IIMSharedMatrix_UserAdd( This, pUser_, pUserID_ )   \
    ( ( This )->lpVtbl->UserAdd( This, pUser_, pUserID_ ) )

#define IIMSharedMatrix_UserGet( This, userIndex_, ppUser_ )    \
    ( ( This )->lpVtbl->UserGet( This, userIndex_, ppUser_ ) )

#define IIMSharedMatrix_UserRemove( This, userID_ )    \
    ( ( This )->lpVtbl->UserRemove( This, userID_ ) )

#define IIMSharedMatrix_UsersGetNb( This, pNbUsers_ )  \
    ( ( This )->lpVtbl->UsersGetNb( This, pNbUsers_ ) )

#define IIMSharedMatrix_UsersUpdateEnableGet( This, pEnable_ ) \
    ( ( This )->lpVtbl->UsersUpdateEnableGet( This, pEnable_ ) )

#define IIMSharedMatrix_UsersUpdateEnableSet( This, enable_ )  \
    ( ( This )->lpVtbl->UsersUpdateEnableSet( This, enable_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSharedMatrix_INTERFACE_DEFINED__ */


#ifndef __IIMSharedMatrixUser_INTERFACE_DEFINED__
#define __IIMSharedMatrixUser_INTERFACE_DEFINED__

/* interface IIMSharedMatrixUser */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSharedMatrixUser;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "B0B521A7-D9BA-47b4-875F-7E8362010DEB" )
IIMSharedMatrixUser : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE SharedMatrixGet(
        /* [out][in] */ IIMSharedMatrix * *ppMatrix_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixSet(
        /* [in] */ IIMSharedMatrix * pMatrix_,
        /* [in] */ VARIANT_BOOL updatePosition_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UpdatePosition( void ) = 0;

    virtual HRESULT STDMETHODCALLTYPE UpdateName( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMSharedMatrixUserVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSharedMatrixUser * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSharedMatrixUser * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSharedMatrixUser * This );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixGet )(
        IIMSharedMatrixUser * This,
        /* [out][in] */ IIMSharedMatrix** ppMatrix_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixSet )(
        IIMSharedMatrixUser * This,
        /* [in] */ IIMSharedMatrix* pMatrix_,
        /* [in] */ VARIANT_BOOL updatePosition_ );

    HRESULT( STDMETHODCALLTYPE * UpdatePosition )(
        IIMSharedMatrixUser * This );

    HRESULT( STDMETHODCALLTYPE * UpdateName )(
        IIMSharedMatrixUser * This );

    END_INTERFACE
} IIMSharedMatrixUserVtbl;

interface IIMSharedMatrixUser
{
    CONST_VTBL struct IIMSharedMatrixUserVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSharedMatrixUser_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSharedMatrixUser_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSharedMatrixUser_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSharedMatrixUser_SharedMatrixGet( This, ppMatrix_ ) \
    ( ( This )->lpVtbl->SharedMatrixGet( This, ppMatrix_ ) )

#define IIMSharedMatrixUser_SharedMatrixSet( This, pMatrix_, updatePosition_ )  \
    ( ( This )->lpVtbl->SharedMatrixSet( This, pMatrix_, updatePosition_ ) )

#define IIMSharedMatrixUser_UpdatePosition( This )    \
    ( ( This )->lpVtbl->UpdatePosition( This ) )

#define IIMSharedMatrixUser_UpdateName( This )    \
    ( ( This )->lpVtbl->UpdateName( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSharedMatrixUser_INTERFACE_DEFINED__ */


#ifndef __IIMSharedMatrixRepository_INTERFACE_DEFINED__
#define __IIMSharedMatrixRepository_INTERFACE_DEFINED__

/* interface IIMSharedMatrixRepository */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSharedMatrixRepository;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "2B0FE9CB-DE60-4494-AFD3-83B511594127" )
IIMSharedMatrixRepository : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE ClientAdd(
        /* [in] */ IIMSharedMatrixRepositoryClient * pClient_,
        /* [retval][out] */ long* pClientID_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE ClientRemove(
        /* [in] */ long clientID_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatricesGetNb(
        /* [retval][out] */ long* pNbMatrices_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixGetByIndex(
        /* [in] */ long matrixIndex_,
        /* [out][in] */ IIMSharedMatrix * *ppSharedMatrix_ ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SharedMatrixGetByName(
        /* [string][in] */ const OLECHAR * pMatrixName_,
        /* [out][in] */ IIMSharedMatrix * *ppSharedMatrix_ ) = 0;

};

#else   /* C style interface */

typedef struct IIMSharedMatrixRepositoryVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSharedMatrixRepository * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSharedMatrixRepository * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSharedMatrixRepository * This );

    HRESULT( STDMETHODCALLTYPE * ClientAdd )(
        IIMSharedMatrixRepository * This,
        /* [in] */ IIMSharedMatrixRepositoryClient* pClient_,
        /* [retval][out] */ long* pClientID_ );

    HRESULT( STDMETHODCALLTYPE * ClientRemove )(
        IIMSharedMatrixRepository * This,
        /* [in] */ long clientID_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatricesGetNb )(
        IIMSharedMatrixRepository * This,
        /* [retval][out] */ long* pNbMatrices_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixGetByIndex )(
        IIMSharedMatrixRepository * This,
        /* [in] */ long matrixIndex_,
        /* [out][in] */ IIMSharedMatrix** ppSharedMatrix_ );

    HRESULT( STDMETHODCALLTYPE * SharedMatrixGetByName )(
        IIMSharedMatrixRepository * This,
        /* [string][in] */ const OLECHAR* pMatrixName_,
        /* [out][in] */ IIMSharedMatrix** ppSharedMatrix_ );

    END_INTERFACE
} IIMSharedMatrixRepositoryVtbl;

interface IIMSharedMatrixRepository
{
    CONST_VTBL struct IIMSharedMatrixRepositoryVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSharedMatrixRepository_QueryInterface( This, riid, ppvObject )   \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSharedMatrixRepository_AddRef( This )  \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSharedMatrixRepository_Release( This ) \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSharedMatrixRepository_ClientAdd( This, pClient_, pClientID_ )   \
    ( ( This )->lpVtbl->ClientAdd( This, pClient_, pClientID_ ) )

#define IIMSharedMatrixRepository_ClientRemove( This, clientID_ )  \
    ( ( This )->lpVtbl->ClientRemove( This, clientID_ ) )

#define IIMSharedMatrixRepository_SharedMatricesGetNb( This, pNbMatrices_ )    \
    ( ( This )->lpVtbl->SharedMatricesGetNb( This, pNbMatrices_ ) )

#define IIMSharedMatrixRepository_SharedMatrixGetByIndex( This, matrixIndex_, ppSharedMatrix_ ) \
    ( ( This )->lpVtbl->SharedMatrixGetByIndex( This, matrixIndex_, ppSharedMatrix_ ) )

#define IIMSharedMatrixRepository_SharedMatrixGetByName( This, pMatrixName_, ppSharedMatrix_ )  \
    ( ( This )->lpVtbl->SharedMatrixGetByName( This, pMatrixName_, ppSharedMatrix_ ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSharedMatrixRepository_INTERFACE_DEFINED__ */


#ifndef __IIMSharedMatrixRepositoryClient_INTERFACE_DEFINED__
#define __IIMSharedMatrixRepositoryClient_INTERFACE_DEFINED__

/* interface IIMSharedMatrixRepositoryClient */
/* [helpstring][uuid][object] */


EXTERN_C const IID IID_IIMSharedMatrixRepositoryClient;

#if defined( __cplusplus ) && !defined( CINTERFACE )

MIDL_INTERFACE( "1F338643-35CE-42e4-A525-EE3A40DBC31A" )
IIMSharedMatrixRepositoryClient : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE Update( void ) = 0;

};

#else   /* C style interface */

typedef struct IIMSharedMatrixRepositoryClientVtbl
{
    BEGIN_INTERFACE HRESULT ( STDMETHODCALLTYPE* QueryInterface )(
        IIMSharedMatrixRepositoryClient * This,
        /* [in] */ REFIID riid,
        /* [annotation][iid_is][out] */
        __RPC__deref_out  void** ppvObject );

    ULONG( STDMETHODCALLTYPE * AddRef )(
        IIMSharedMatrixRepositoryClient * This );

    ULONG( STDMETHODCALLTYPE * Release )(
        IIMSharedMatrixRepositoryClient * This );

    HRESULT( STDMETHODCALLTYPE * Update )(
        IIMSharedMatrixRepositoryClient * This );

    END_INTERFACE
} IIMSharedMatrixRepositoryClientVtbl;

interface IIMSharedMatrixRepositoryClient
{
    CONST_VTBL struct IIMSharedMatrixRepositoryClientVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define IIMSharedMatrixRepositoryClient_QueryInterface( This, riid, ppvObject ) \
    ( ( This )->lpVtbl->QueryInterface( This, riid, ppvObject ) )

#define IIMSharedMatrixRepositoryClient_AddRef( This )    \
    ( ( This )->lpVtbl->AddRef( This ) )

#define IIMSharedMatrixRepositoryClient_Release( This )   \
    ( ( This )->lpVtbl->Release( This ) )


#define IIMSharedMatrixRepositoryClient_Update( This )    \
    ( ( This )->lpVtbl->Update( This ) )

#endif /* COBJMACROS */


#endif  /* C style interface */




#endif  /* __IIMSharedMatrixRepositoryClient_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long __RPC_USER  BSTR_UserSize(     unsigned long*, unsigned long, BSTR* );
unsigned char* __RPC_USER BSTR_UserMarshal(  unsigned long*, unsigned char*, BSTR* );
unsigned char* __RPC_USER BSTR_UserUnmarshal( unsigned long*, unsigned char*, BSTR* );
void __RPC_USER           BSTR_UserFree(     unsigned long*, BSTR* );

unsigned long __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long*, unsigned long, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserMarshal(  unsigned long*, unsigned char*, LPSAFEARRAY* );
unsigned char* __RPC_USER LPSAFEARRAY_UserUnmarshal( unsigned long*, unsigned char*, LPSAFEARRAY* );
void __RPC_USER           LPSAFEARRAY_UserFree(     unsigned long*, LPSAFEARRAY* );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif // ifndef __IIMSharedMatrix_h__
