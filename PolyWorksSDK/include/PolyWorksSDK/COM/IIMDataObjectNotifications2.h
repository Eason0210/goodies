

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMDataObjectNotifications2.idl:
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

#ifndef __IIMDataObjectNotifications2_h__
#define __IIMDataObjectNotifications2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMDataObjectNotifications2_FWD_DEFINED__
#define __IIMDataObjectNotifications2_FWD_DEFINED__
typedef interface IIMDataObjectNotifications2 IIMDataObjectNotifications2;

#endif 	/* __IIMDataObjectNotifications2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMDataObjectNotifications.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMDataObjectNotifications2_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectNotifications2_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMDataObjectNotifications2_0000_0000_v0_0_s_ifspec;

#ifndef __IIMDataObjectNotifications2_INTERFACE_DEFINED__
#define __IIMDataObjectNotifications2_INTERFACE_DEFINED__

/* interface IIMDataObjectNotifications2 */
/* [helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IIMDataObjectNotifications2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E58829AD-9E4A-4C12-8153-61E1AFA38D24")
    IIMDataObjectNotifications2 : public IIMDataObjectNotifications
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDataObjectsRenamed( 
            /* [in] */ SAFEARRAY * uniqueIDs_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMDataObjectNotifications2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMDataObjectNotifications2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMDataObjectNotifications2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsAdded )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsDeleted )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsEdited )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsTransformed )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ SAFEARRAY * uniqueIDs_,
            /* [in] */ ETransformTypes transformationType_);
        
        HRESULT ( STDMETHODCALLTYPE *OnDataObjectsRenamed )( 
            IIMDataObjectNotifications2 * This,
            /* [in] */ SAFEARRAY * uniqueIDs_);
        
        END_INTERFACE
    } IIMDataObjectNotifications2Vtbl;

    interface IIMDataObjectNotifications2
    {
        CONST_VTBL struct IIMDataObjectNotifications2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMDataObjectNotifications2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMDataObjectNotifications2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMDataObjectNotifications2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMDataObjectNotifications2_OnDataObjectsAdded(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsAdded(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications2_OnDataObjectsDeleted(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsDeleted(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications2_OnDataObjectsEdited(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsEdited(This,uniqueIDs_) ) 

#define IIMDataObjectNotifications2_OnDataObjectsTransformed(This,uniqueIDs_,transformationType_)	\
    ( (This)->lpVtbl -> OnDataObjectsTransformed(This,uniqueIDs_,transformationType_) ) 


#define IIMDataObjectNotifications2_OnDataObjectsRenamed(This,uniqueIDs_)	\
    ( (This)->lpVtbl -> OnDataObjectsRenamed(This,uniqueIDs_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMDataObjectNotifications2_INTERFACE_DEFINED__ */


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


