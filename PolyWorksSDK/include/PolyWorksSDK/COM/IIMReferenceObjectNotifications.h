

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMReferenceObjectNotifications.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IIMReferenceObjectNotifications_h__
#define __IIMReferenceObjectNotifications_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMReferenceObjectNotifications_FWD_DEFINED__
#define __IIMReferenceObjectNotifications_FWD_DEFINED__
typedef interface IIMReferenceObjectNotifications IIMReferenceObjectNotifications;

#endif 	/* __IIMReferenceObjectNotifications_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMReferenceObjectNotifications_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMReferenceObjectNotifications_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMReferenceObjectNotifications_0000_0000_v0_0_s_ifspec;

#ifndef __IIMReferenceObjectNotifications_INTERFACE_DEFINED__
#define __IIMReferenceObjectNotifications_INTERFACE_DEFINED__

/* interface IIMReferenceObjectNotifications */
/* [helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IIMReferenceObjectNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43474968-ED4A-4414-97B7-667E3673AC69")
    IIMReferenceObjectNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnReferenceObjectsAdded( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReferenceObjectsDeleted( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReferenceObjectsEdited( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReferenceObjectsTransformed( 
            /* [in] */ SAFEARRAY * uniqueIDs_,
            /* [in] */ ETransformTypes transformationType_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMReferenceObjectNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMReferenceObjectNotifications * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMReferenceObjectNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMReferenceObjectNotifications * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnReferenceObjectsAdded )( 
            IIMReferenceObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnReferenceObjectsDeleted )( 
            IIMReferenceObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnReferenceObjectsEdited )( 
            IIMReferenceObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnReferenceObjectsTransformed )( 
            IIMReferenceObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_,
            /* [in] */ ETransformTypes transformationType_);
        
        END_INTERFACE
    } IIMReferenceObjectNotificationsVtbl;

    interface IIMReferenceObjectNotifications
    {
        CONST_VTBL struct IIMReferenceObjectNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMReferenceObjectNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMReferenceObjectNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMReferenceObjectNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMReferenceObjectNotifications_OnReferenceObjectsAdded(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnReferenceObjectsAdded(This,uniqueIDs_) ) 

#define IIMReferenceObjectNotifications_OnReferenceObjectsDeleted(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnReferenceObjectsDeleted(This,uniqueIDs_) ) 

#define IIMReferenceObjectNotifications_OnReferenceObjectsEdited(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnReferenceObjectsEdited(This,uniqueIDs_) ) 

#define IIMReferenceObjectNotifications_OnReferenceObjectsTransformed(This,uniqueIDs_,transformationType_)	\
    ( (This)->lpVtbl -> OnReferenceObjectsTransformed(This,uniqueIDs_,transformationType_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMReferenceObjectNotifications_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


