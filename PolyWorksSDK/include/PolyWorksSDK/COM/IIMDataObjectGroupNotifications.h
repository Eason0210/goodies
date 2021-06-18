

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMDataObjectGroupNotifications.idl:
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

#ifndef __IIMDataObjectGroupNotifications_h__
#define __IIMDataObjectGroupNotifications_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMDataObjectGroupNotifications_FWD_DEFINED__
#define __IIMDataObjectGroupNotifications_FWD_DEFINED__
typedef interface IIMDataObjectGroupNotifications IIMDataObjectGroupNotifications;

#endif 	/* __IIMDataObjectGroupNotifications_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMDataObjectGroupNotifications_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectGroupNotifications_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectGroupNotifications_0000_0000_v0_0_s_ifspec;

#ifndef __IIMDataObjectGroupNotifications_INTERFACE_DEFINED__
#define __IIMDataObjectGroupNotifications_INTERFACE_DEFINED__

/* interface IIMDataObjectGroupNotifications */
/* [helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IIMDataObjectGroupNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8EDD63E1-A760-4639-AD8B-6AF3F6253311")
    IIMDataObjectGroupNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectGroupsAdded( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectGroupsDeleted( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectGroupsRenamed( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMDataObjectGroupNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMDataObjectGroupNotifications * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMDataObjectGroupNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMDataObjectGroupNotifications * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectGroupsAdded )( 
            IIMDataObjectGroupNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectGroupsDeleted )( 
            IIMDataObjectGroupNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectGroupsRenamed )( 
            IIMDataObjectGroupNotifications * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        END_INTERFACE
    } IIMDataObjectGroupNotificationsVtbl;

    interface IIMDataObjectGroupNotifications
    {
        CONST_VTBL struct IIMDataObjectGroupNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMDataObjectGroupNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMDataObjectGroupNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMDataObjectGroupNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMDataObjectGroupNotifications_OnDataObjectGroupsAdded(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectGroupsAdded(This,uniqueIDs_) ) 

#define IIMDataObjectGroupNotifications_OnDataObjectGroupsDeleted(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectGroupsDeleted(This,uniqueIDs_) ) 

#define IIMDataObjectGroupNotifications_OnDataObjectGroupsRenamed(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectGroupsRenamed(This,uniqueIDs_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMDataObjectGroupNotifications_INTERFACE_DEFINED__ */


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


