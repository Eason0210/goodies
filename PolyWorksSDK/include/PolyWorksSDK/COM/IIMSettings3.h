

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMSettings3.idl:
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

#ifndef __IIMSettings3_h__
#define __IIMSettings3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMSettings3_FWD_DEFINED__
#define __IIMSettings3_FWD_DEFINED__
typedef interface IIMSettings3 IIMSettings3;

#endif 	/* __IIMSettings3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMSettings2.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIMSettings3_INTERFACE_DEFINED__
#define __IIMSettings3_INTERFACE_DEFINED__

/* interface IIMSettings3 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMSettings3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("df105bb5-0ca4-43d0-9bac-a0288fe2d45d")
    IIMSettings3 : public IIMSettings2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSettingsChange( 
            /* [in] */ SAFEARRAY * pSettingNames_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMSettings3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMSettings3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMSettings3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMSettings3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleSettingsNbGet )( 
            IIMSettings3 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *DoubleSettingGet )( 
            IIMSettings3 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ double *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *LongSettingsNbGet )( 
            IIMSettings3 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *LongSettingGet )( 
            IIMSettings3 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ long *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *StringSettingsNbGet )( 
            IIMSettings3 * This,
            /* [retval][out] */ long *nbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *StringSettingGet )( 
            IIMSettings3 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ BSTR *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixSettingsNbGet )( 
            IIMSettings3 * This,
            /* [retval][out] */ long *pNbSettings_);
        
        HRESULT ( STDMETHODCALLTYPE *MatrixSettingGet )( 
            IIMSettings3 * This,
            /* [in] */ long settingIndex_,
            /* [out][in] */ BSTR *pSettingName_,
            /* [out][in] */ SAFEARRAY * *pDefaultValue_,
            /* [out][in] */ VARIANT_BOOL *pIsUserSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsHostSpecific_,
            /* [out][in] */ VARIANT_BOOL *pIsProjectSetting_);
        
        HRESULT ( STDMETHODCALLTYPE *OnSettingsChange )( 
            IIMSettings3 * This,
            /* [in] */ SAFEARRAY * pSettingNames_);
        
        END_INTERFACE
    } IIMSettings3Vtbl;

    interface IIMSettings3
    {
        CONST_VTBL struct IIMSettings3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMSettings3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMSettings3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMSettings3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMSettings3_DoubleSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> DoubleSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings3_DoubleSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> DoubleSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 

#define IIMSettings3_LongSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> LongSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings3_LongSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> LongSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 

#define IIMSettings3_StringSettingsNbGet(This,nbSettings_)	\
    ( (This)->lpVtbl -> StringSettingsNbGet(This,nbSettings_) ) 

#define IIMSettings3_StringSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> StringSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 


#define IIMSettings3_MatrixSettingsNbGet(This,pNbSettings_)	\
    ( (This)->lpVtbl -> MatrixSettingsNbGet(This,pNbSettings_) ) 

#define IIMSettings3_MatrixSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_)	\
    ( (This)->lpVtbl -> MatrixSettingGet(This,settingIndex_,pSettingName_,pDefaultValue_,pIsUserSpecific_,pIsHostSpecific_,pIsProjectSetting_) ) 


#define IIMSettings3_OnSettingsChange(This,pSettingNames_)	\
    ( (This)->lpVtbl -> OnSettingsChange(This,pSettingNames_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMSettings3_INTERFACE_DEFINED__ */


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


