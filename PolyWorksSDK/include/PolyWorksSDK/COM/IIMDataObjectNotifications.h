

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMDataObjectNotifications.idl:
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

#ifndef __IIMDataObjectNotifications_h__
#define __IIMDataObjectNotifications_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMDataObjectNotifications_FWD_DEFINED__
#define __IIMDataObjectNotifications_FWD_DEFINED__
typedef interface IIMDataObjectNotifications IIMDataObjectNotifications;

#endif 	/* __IIMDataObjectNotifications_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMDataObjectNotifications_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectNotifications_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectNotifications_0000_0000_v0_0_s_ifspec;

#ifndef __IIMDataObjectNotifications_INTERFACE_DEFINED__
#define __IIMDataObjectNotifications_INTERFACE_DEFINED__

/* interface IIMDataObjectNotifications */
/* [helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IIMDataObjectNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8CB31456-7EBC-4F27-84FE-AF7E1474E6B0")
    IIMDataObjectNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectsAdded( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectsDeleted( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectsEdited( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectsTransformed( 
            /* [in] */ SAFEARRAY * uniqueIDs_,
            /* [in] */ ETransformTypes transformationType_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMDataObjectNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMDataObjectNotifications * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMDataObjectNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMDataObjectNotifications * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsAdded )( 
            IIMDataObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsDeleted )( 
            IIMDataObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsEdited )( 
            IIMDataObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsTransformed )( 
            IIMDataObjectNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_,
            /* [in] */ ETransformTypes transformationType_);
        
        END_INTERFACE
    } IIMDataObjectNotificationsVtbl;

    interface IIMDataObjectNotifications
    {
        CONST_VTBL struct IIMDataObjectNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMDataObjectNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMDataObjectNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMDataObjectNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMDataObjectNotifications_OnDataObjectsAdded(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsAdded(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications_OnDataObjectsDeleted(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsDeleted(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications_OnDataObjectsEdited(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsEdited(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications_OnDataObjectsTransformed(This,uniqueIDs_,transformationType_)	\
    ( (This)->lpVtbl -> OnDataObjectsTransformed(This,uniqueIDs_,transformationType_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMDataObjectNotifications_INTERFACE_DEFINED__ */


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


