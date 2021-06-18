

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMInspectorProjectNotifications.idl:
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

#ifndef __IIMInspectorProjectNotifications_h__
#define __IIMInspectorProjectNotifications_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMInspectorProjectNotifications_FWD_DEFINED__
#define __IIMInspectorProjectNotifications_FWD_DEFINED__
typedef interface IIMInspectorProjectNotifications IIMInspectorProjectNotifications;

#endif 	/* __IIMInspectorProjectNotifications_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMInspectorProjectNotifications_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMInspectorProjectNotifications_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMInspectorProjectNotifications_0000_0000_v0_0_s_ifspec;

#ifndef __IIMInspectorProjectNotifications_INTERFACE_DEFINED__
#define __IIMInspectorProjectNotifications_INTERFACE_DEFINED__

/* interface IIMInspectorProjectNotifications */
/* [helpstring][uuid][oleautomation][object] */ 


EXTERN_C const IID IID_IIMInspectorProjectNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA6E7599-FA1B-4257-8DE0-D2FB80D8E3AC")
    IIMInspectorProjectNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCurrentPieceChanged( 
            /* [in] */ BSTR uniqueID_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCurrentPieceSaved( 
            /* [in] */ BSTR uniqueID_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMInspectorProjectNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMInspectorProjectNotifications * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMInspectorProjectNotifications * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMInspectorProjectNotifications * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnCurrentPieceChanged )( 
            IIMInspectorProjectNotifications * This,
            /* [in] */ BSTR uniqueID_);
        
        HRESULT ( STDMETHODCALLTYPE *OnCurrentPieceSaved )( 
            IIMInspectorProjectNotifications * This,
            /* [in] */ BSTR uniqueID_);
        
        END_INTERFACE
    } IIMInspectorProjectNotificationsVtbl;

    interface IIMInspectorProjectNotifications
    {
        CONST_VTBL struct IIMInspectorProjectNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMInspectorProjectNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMInspectorProjectNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMInspectorProjectNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMInspectorProjectNotifications_OnCurrentPieceChanged(This,uniqueID_)	\
    ( (This)->lpVtbl -> OnCurrentPieceChanged(This,uniqueID_) ) 

#define IIMInspectorProjectNotifications_OnCurrentPieceSaved(This,uniqueID_)	\
    ( (This)->lpVtbl -> OnCurrentPieceSaved(This,uniqueID_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMInspectorProjectNotifications_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


