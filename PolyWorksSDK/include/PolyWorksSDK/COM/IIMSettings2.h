

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMSettings2.idl:
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

#ifndef __IIMSettings2_h__
#define __IIMSettings2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMSettings2_FWD_DEFINED__
#define __IIMSettings2_FWD_DEFINED__
typedef interface IIMSettings2 IIMSettings2;

#endif 	/* __IIMSettings2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMSettings.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIMSettings2_INTERFACE_DEFINED__
#define __IIMSettings2_INTERFACE_DEFINED__

/* interface IIMSettings2 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMSettings2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20F6B09E-642B-4D4C-91A9-A9D3312291F4")
    IIMSettings2 : public IIMSettings
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MatrixSettingsNbGet( 
            /* [retval][out] */ long *pNbSettings_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatrixSettingGet( 
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ SAFEARRAY * *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMSettings2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMSettings2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMSettings2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMSettings2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleSettingsNbGet )( 
            IIMSettings2 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleSettingGet )( 
            IIMSettings2 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ double *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *LongSettingsNbGet )( 
            IIMSettings2 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *LongSettingGet )( 
            IIMSettings2 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ long *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *StringSettingsNbGet )( 
            IIMSettings2 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *StringSettingGet )( 
            IIMSettings2 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ BSTR *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixSettingsNbGet )( 
            IIMSettings2 * This,
            /* [retval][out] */ long *pNbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixSettingGet )( 
            IIMSettings2 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ SAFEARRAY * *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        END_INTERFACE
    } IIMSettings2Vtbl;

    interface IIMSettings2
    {
        CONST_VTBL struct IIMSettings2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMSettings2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMSettings2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMSettings2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMSettings2_DoubleSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> DoubleSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings2_DoubleSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> DoubleSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 

#define IIMSettings2_LongSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> LongSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings2_LongSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> LongSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 

#define IIMSettings2_StringSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> StringSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings2_StringSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> StringSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 


#define IIMSettings2_MatrixSettingsNbGet(This,pNbSettings_)	\
    ( (This)->lpVtbl -> MatrixSettingsNbGet(This,pNbSettings_) ) 

#define IIMSettings2_MatrixSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> MatrixSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMSettings2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


