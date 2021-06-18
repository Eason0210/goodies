

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMRotaryTableFeedback.idl:
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

#ifndef __IIMRotaryTableFeedback_h__
#define __IIMRotaryTableFeedback_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMRotaryTableFeedback_FWD_DEFINED__
#define __IIMRotaryTableFeedback_FWD_DEFINED__
typedef interface IIMRotaryTableFeedback IIMRotaryTableFeedback;

#endif 	/* __IIMRotaryTableFeedback_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMRotaryTableFeedback_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMRotaryTableFeedback_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMRotaryTableFeedback_0000_0000_v0_0_s_ifspec;

#ifndef __IIMRotaryTableFeedback_INTERFACE_DEFINED__
#define __IIMRotaryTableFeedback_INTERFACE_DEFINED__

/* interface IIMRotaryTableFeedback */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMRotaryTableFeedback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C7BAC77-EBD3-4248-B006-D1DAA82CDF72")
    IIMRotaryTableFeedback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RotaryTableStatusSet( 
            /* [in] */ EDeviceStatus status_,
            BSTR details_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableConnectionEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableCurrentAngleSet( 
            /* [in] */ double angle_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableRotationCompleted( 
            /* [in] */ ERotaryTableCommandStatus status_,
            BSTR details_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableHomingCompleted( 
            /* [in] */ ERotaryTableCommandStatus status_,
            BSTR details_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMRotaryTableFeedbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMRotaryTableFeedback * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMRotaryTableFeedback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMRotaryTableFeedback * This);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableStatusSet )( 
            IIMRotaryTableFeedback * This,
            /* [in] */ EDeviceStatus status_,
            BSTR details_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableConnectionEnd )( 
            IIMRotaryTableFeedback * This);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableCurrentAngleSet )( 
            IIMRotaryTableFeedback * This,
            /* [in] */ double angle_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableRotationCompleted )( 
            IIMRotaryTableFeedback * This,
            /* [in] */ ERotaryTableCommandStatus status_,
            BSTR details_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableHomingCompleted )( 
            IIMRotaryTableFeedback * This,
            /* [in] */ ERotaryTableCommandStatus status_,
            BSTR details_);
        
        END_INTERFACE
    } IIMRotaryTableFeedbackVtbl;

    interface IIMRotaryTableFeedback
    {
        CONST_VTBL struct IIMRotaryTableFeedbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMRotaryTableFeedback_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMRotaryTableFeedback_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMRotaryTableFeedback_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMRotaryTableFeedback_RotaryTableStatusSet(This,status_,details_)	\
    ( (This)->lpVtbl -> RotaryTableStatusSet(This,status_,details_) ) 

#define IIMRotaryTableFeedback_RotaryTableConnectionEnd(This)	\
    ( (This)->lpVtbl -> RotaryTableConnectionEnd(This) ) 

#define IIMRotaryTableFeedback_RotaryTableCurrentAngleSet(This,angle_)	\
    ( (This)->lpVtbl -> RotaryTableCurrentAngleSet(This,angle_) ) 

#define IIMRotaryTableFeedback_RotaryTableRotationCompleted(This,status_,details_)	\
    ( (This)->lpVtbl -> RotaryTableRotationCompleted(This,status_,details_) ) 

#define IIMRotaryTableFeedback_RotaryTableHomingCompleted(This,status_,details_)	\
    ( (This)->lpVtbl -> RotaryTableHomingCompleted(This,status_,details_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMRotaryTableFeedback_INTERFACE_DEFINED__ */


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


