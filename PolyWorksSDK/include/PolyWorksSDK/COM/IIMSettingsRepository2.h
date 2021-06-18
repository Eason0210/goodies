

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMSettingsRepository2.idl:
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

#ifndef __IIMSettingsRepository2_h__
#define __IIMSettingsRepository2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMSettingsRepository2_FWD_DEFINED__
#define __IIMSettingsRepository2_FWD_DEFINED__
typedef interface IIMSettingsRepository2 IIMSettingsRepository2;

#endif 	/* __IIMSettingsRepository2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMSettingsRepository.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIMSettingsRepository2_INTERFACE_DEFINED__
#define __IIMSettingsRepository2_INTERFACE_DEFINED__

/* interface IIMSettingsRepository2 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMSettingsRepository2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2969FBB5-213B-472D-8119-3FCC4269F4F8")
    IIMSettingsRepository2 : public IIMSettingsRepository
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GroupAdd( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GroupRemove( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GroupRename( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_,
            /* [string][in] */ const OLECHAR *pNewGroupName_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GroupNamesGet( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [retval][out] */ SAFEARRAY * *pNames_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatrixValueGet( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [retval][out] */ SAFEARRAY * *pValue_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatrixValueSet( 
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [in] */ SAFEARRAY * pValue_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMSettingsRepository2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMSettingsRepository2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMSettingsRepository2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMSettingsRepository2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleValueGet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [retval][out] */ double *pValue_);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleValueSet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [in] */ double value_);
        
        HRESULT ( STDMETHODCALLTYPE *LongValueGet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [retval][out] */ long *pValue_);
        
        HRESULT ( STDMETHODCALLTYPE *LongValueSet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [in] */ long value_);
        
        HRESULT ( STDMETHODCALLTYPE *StringValueGet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [retval][out] */ BSTR *pValue_);
        
        HRESULT ( STDMETHODCALLTYPE *StringValueSet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [string][in] */ const OLECHAR *pValue_);
        
        HRESULT ( STDMETHODCALLTYPE *SettingsSave )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pOwnerID_);
        
        HRESULT ( STDMETHODCALLTYPE *SettingsLoad )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pOwnerID_);
        
        HRESULT ( STDMETHODCALLTYPE *GroupAdd )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_);
        
        HRESULT ( STDMETHODCALLTYPE *GroupRemove )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_);
        
        HRESULT ( STDMETHODCALLTYPE *GroupRename )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pGroupName_,
            /* [string][in] */ const OLECHAR *pNewGroupName_);
        
        HRESULT ( STDMETHODCALLTYPE *GroupNamesGet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [retval][out] */ SAFEARRAY * *pNames_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixValueGet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [retval][out] */ SAFEARRAY * *pValue_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixValueSet )( 
            IIMSettingsRepository2 * This,
            /* [string][in] */ const OLECHAR *pPath_,
            /* [string][in] */ const OLECHAR *pSettingName_,
            /* [in] */ SAFEARRAY * pValue_);
        
        END_INTERFACE
    } IIMSettingsRepository2Vtbl;

    interface IIMSettingsRepository2
    {
        CONST_VTBL struct IIMSettingsRepository2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMSettingsRepository2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMSettingsRepository2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMSettingsRepository2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMSettingsRepository2_DoubleValueGet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> DoubleValueGet(This,pPath_,pSettingName_,pValue_) ) 

#define IIMSettingsRepository2_DoubleValueSet(This,pPath_,pSettingName_,value_)	\
    ( (This)->lpVtbl -> DoubleValueSet(This,pPath_,pSettingName_,value_) ) 

#define IIMSettingsRepository2_LongValueGet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> LongValueGet(This,pPath_,pSettingName_,pValue_) ) 

#define IIMSettingsRepository2_LongValueSet(This,pPath_,pSettingName_,value_)	\
    ( (This)->lpVtbl -> LongValueSet(This,pPath_,pSettingName_,value_) ) 

#define IIMSettingsRepository2_StringValueGet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> StringValueGet(This,pPath_,pSettingName_,pValue_) ) 

#define IIMSettingsRepository2_StringValueSet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> StringValueSet(This,pPath_,pSettingName_,pValue_) ) 

#define IIMSettingsRepository2_SettingsSave(This,pOwnerID_)	\
    ( (This)->lpVtbl -> SettingsSave(This,pOwnerID_) ) 

#define IIMSettingsRepository2_SettingsLoad(This,pOwnerID_)	\
    ( (This)->lpVtbl -> SettingsLoad(This,pOwnerID_) ) 


#define IIMSettingsRepository2_GroupAdd(This,pPath_,pGroupName_)	\
    ( (This)->lpVtbl -> GroupAdd(This,pPath_,pGroupName_) ) 

#define IIMSettingsRepository2_GroupRemove(This,pPath_,pGroupName_)	\
    ( (This)->lpVtbl -> GroupRemove(This,pPath_,pGroupName_) ) 

#define IIMSettingsRepository2_GroupRename(This,pPath_,pGroupName_,pNewGroupName_)	\
    ( (This)->lpVtbl -> GroupRename(This,pPath_,pGroupName_,pNewGroupName_) ) 

#define IIMSettingsRepository2_GroupNamesGet(This,pPath_,pNames_)	\
    ( (This)->lpVtbl -> GroupNamesGet(This,pPath_,pNames_) ) 

#define IIMSettingsRepository2_MatrixValueGet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> MatrixValueGet(This,pPath_,pSettingName_,pValue_) ) 

#define IIMSettingsRepository2_MatrixValueSet(This,pPath_,pSettingName_,pValue_)	\
    ( (This)->lpVtbl -> MatrixValueSet(This,pPath_,pSettingName_,pValue_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMSettingsRepository2_INTERFACE_DEFINED__ */


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


