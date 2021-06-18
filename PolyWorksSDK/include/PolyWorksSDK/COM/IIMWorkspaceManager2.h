

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMWorkspaceManager2.idl:
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

#ifndef __IIMWorkspaceManager2_h__
#define __IIMWorkspaceManager2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMWorkspaceManager2_FWD_DEFINED__
#define __IIMWorkspaceManager2_FWD_DEFINED__
typedef interface IIMWorkspaceManager2 IIMWorkspaceManager2;

#endif 	/* __IIMWorkspaceManager2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMWorkspaceManager.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIMWorkspaceManager2_INTERFACE_DEFINED__
#define __IIMWorkspaceManager2_INTERFACE_DEFINED__

/* interface IIMWorkspaceManager2 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMWorkspaceManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C2A13346-A194-4A07-BDE4-95FCA4FA1B67")
    IIMWorkspaceManager2 : public IIMWorkspaceManager
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ModuleGet( 
            /* [full][string][in] */ const OLECHAR *pPwkPath_,
            /* [full][string][in] */ const OLECHAR *pProjectName_,
            /* [retval][out] */ IUnknown **ppIIMModule_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ModuleStart( 
            /* [in] */ EPWModuleTypes pwModuleType_,
            /* [full][string][in] */ const OLECHAR *pPwkPath_,
            /* [full][string][in] */ const OLECHAR *pProjectName_,
            /* [retval][out] */ IUnknown **ppIIMModule_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RunningModulesGet( 
            /* [in] */ EPWModuleTypes pwModuleType_,
            /* [out] */ SAFEARRAY * *ppPwkPaths_,
            /* [out] */ SAFEARRAY * *ppProjectNames_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMWorkspaceManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMWorkspaceManager2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMWorkspaceManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMWorkspaceManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CommandCenterCreate )( 
            IIMWorkspaceManager2 * This,
            /* [out] */ IIMCommandCenter **ppIIMCommandCenter_);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleGet )( 
            IIMWorkspaceManager2 * This,
            /* [full][string][in] */ const OLECHAR *pPwkPath_,
            /* [full][string][in] */ const OLECHAR *pProjectName_,
            /* [retval][out] */ IUnknown **ppIIMModule_);
        
        HRESULT ( STDMETHODCALLTYPE *ModuleStart )( 
            IIMWorkspaceManager2 * This,
            /* [in] */ EPWModuleTypes pwModuleType_,
            /* [full][string][in] */ const OLECHAR *pPwkPath_,
            /* [full][string][in] */ const OLECHAR *pProjectName_,
            /* [retval][out] */ IUnknown **ppIIMModule_);
        
        HRESULT ( STDMETHODCALLTYPE *RunningModulesGet )( 
            IIMWorkspaceManager2 * This,
            /* [in] */ EPWModuleTypes pwModuleType_,
            /* [out] */ SAFEARRAY * *ppPwkPaths_,
            /* [out] */ SAFEARRAY * *ppProjectNames_);
        
        END_INTERFACE
    } IIMWorkspaceManager2Vtbl;

    interface IIMWorkspaceManager2
    {
        CONST_VTBL struct IIMWorkspaceManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMWorkspaceManager2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMWorkspaceManager2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMWorkspaceManager2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMWorkspaceManager2_CommandCenterCreate(This,ppIIMCommandCenter_)	\
    ( (This)->lpVtbl -> CommandCenterCreate(This,ppIIMCommandCenter_) ) 


#define IIMWorkspaceManager2_ModuleGet(This,pPwkPath_,pProjectName_,ppIIMModule_)	\
    ( (This)->lpVtbl -> ModuleGet(This,pPwkPath_,pProjectName_,ppIIMModule_) ) 

#define IIMWorkspaceManager2_ModuleStart(This,pwModuleType_,pPwkPath_,pProjectName_,ppIIMModule_)	\
    ( (This)->lpVtbl -> ModuleStart(This,pwModuleType_,pPwkPath_,pProjectName_,ppIIMModule_) ) 

#define IIMWorkspaceManager2_RunningModulesGet(This,pwModuleType_,ppPwkPaths_,ppProjectNames_)	\
    ( (This)->lpVtbl -> RunningModulesGet(This,pwModuleType_,ppPwkPaths_,ppProjectNames_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMWorkspaceManager2_INTERFACE_DEFINED__ */


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


