

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMRotaryTable.idl:
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

#ifndef __IIMRotaryTable_h__
#define __IIMRotaryTable_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMRotaryTable_FWD_DEFINED__
#define __IIMRotaryTable_FWD_DEFINED__
typedef interface IIMRotaryTable IIMRotaryTable;

#endif 	/* __IIMRotaryTable_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"
#include "IIMRotaryTableFeedback.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMRotaryTable_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMRotaryTable_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMRotaryTable_0000_0000_v0_0_s_ifspec;

#ifndef __IIMRotaryTable_INTERFACE_DEFINED__
#define __IIMRotaryTable_INTERFACE_DEFINED__

/* interface IIMRotaryTable */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMRotaryTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D72AD545-77FB-4DA0-9F54-4FF782A3F6F6")
    IIMRotaryTable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RotaryTableNameGet( 
            /* [retval][out] */ BSTR *pName_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableConnectionInit( 
            /* [in] */ IIMRotaryTableFeedback *pIIMRotaryTableFeedback_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableConnectionEnd( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableDefaultStepGet( 
            /* [retval][out] */ double *pStep_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableCanChangeSpeed( 
            /* [retval][out] */ VARIANT_BOOL *pCanChangeSpeed_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableDefaultSpeedGet( 
            /* [retval][out] */ double *pSpeed_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableMaximumSpeedGet( 
            /* [retval][out] */ double *pSpeed_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableMinimumSpeedGet( 
            /* [retval][out] */ double *pSpeed_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableSpeedSet( 
            /* [in] */ double speed_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableCanChangeAcceleration( 
            /* [retval][out] */ VARIANT_BOOL *pCanChangeAcceleration_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableDefaultAccelerationGet( 
            /* [retval][out] */ double *pAcceleration_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableMaximumAccelerationGet( 
            /* [retval][out] */ double *pAcceleration_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableMinimumAccelerationGet( 
            /* [retval][out] */ double *pAcceleration_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableAccelerationSet( 
            /* [in] */ double acceleration_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableAngleGet( 
            /* [retval][out] */ double *pAngle_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableStatusGet( 
            /* [out] */ EDeviceStatus *pStatus_,
            /* [out] */ BSTR *pDetails_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableHomingIsRequired( 
            /* [retval][out] */ VARIANT_BOOL *pIsHomingRequired_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableRotateHome( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableRotate( 
            /* [in] */ double angle_,
            /* [in] */ ERotationDirection direction_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableCanStop( 
            /* [retval][out] */ VARIANT_BOOL *pCanStop_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RotaryTableStop( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMRotaryTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMRotaryTable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMRotaryTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMRotaryTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableNameGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ BSTR *pName_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableConnectionInit )( 
            IIMRotaryTable * This,
            /* [in] */ IIMRotaryTableFeedback *pIIMRotaryTableFeedback_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableConnectionEnd )( 
            IIMRotaryTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableDefaultStepGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pStep_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableCanChangeSpeed )( 
            IIMRotaryTable * This,
            /* [retval][out] */ VARIANT_BOOL *pCanChangeSpeed_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableDefaultSpeedGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pSpeed_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableMaximumSpeedGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pSpeed_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableMinimumSpeedGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pSpeed_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableSpeedSet )( 
            IIMRotaryTable * This,
            /* [in] */ double speed_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableCanChangeAcceleration )( 
            IIMRotaryTable * This,
            /* [retval][out] */ VARIANT_BOOL *pCanChangeAcceleration_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableDefaultAccelerationGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pAcceleration_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableMaximumAccelerationGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pAcceleration_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableMinimumAccelerationGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pAcceleration_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableAccelerationSet )( 
            IIMRotaryTable * This,
            /* [in] */ double acceleration_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableAngleGet )( 
            IIMRotaryTable * This,
            /* [retval][out] */ double *pAngle_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableStatusGet )( 
            IIMRotaryTable * This,
            /* [out] */ EDeviceStatus *pStatus_,
            /* [out] */ BSTR *pDetails_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableHomingIsRequired )( 
            IIMRotaryTable * This,
            /* [retval][out] */ VARIANT_BOOL *pIsHomingRequired_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableRotateHome )( 
            IIMRotaryTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableRotate )( 
            IIMRotaryTable * This,
            /* [in] */ double angle_,
            /* [in] */ ERotationDirection direction_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableCanStop )( 
            IIMRotaryTable * This,
            /* [retval][out] */ VARIANT_BOOL *pCanStop_);
        
        HRESULT ( STDMETHODCALLTYPE *RotaryTableStop )( 
            IIMRotaryTable * This);
        
        END_INTERFACE
    } IIMRotaryTableVtbl;

    interface IIMRotaryTable
    {
        CONST_VTBL struct IIMRotaryTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMRotaryTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMRotaryTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMRotaryTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMRotaryTable_RotaryTableNameGet(This,pName_)	\
    ( (This)->lpVtbl -> RotaryTableNameGet(This,pName_) ) 

#define IIMRotaryTable_RotaryTableConnectionInit(This,pIIMRotaryTableFeedback_)	\
    ( (This)->lpVtbl -> RotaryTableConnectionInit(This,pIIMRotaryTableFeedback_) ) 

#define IIMRotaryTable_RotaryTableConnectionEnd(This)	\
    ( (This)->lpVtbl -> RotaryTableConnectionEnd(This) ) 

#define IIMRotaryTable_RotaryTableDefaultStepGet(This,pStep_)	\
    ( (This)->lpVtbl -> RotaryTableDefaultStepGet(This,pStep_) ) 

#define IIMRotaryTable_RotaryTableCanChangeSpeed(This,pCanChangeSpeed_)	\
    ( (This)->lpVtbl -> RotaryTableCanChangeSpeed(This,pCanChangeSpeed_) ) 

#define IIMRotaryTable_RotaryTableDefaultSpeedGet(This,pSpeed_)	\
    ( (This)->lpVtbl -> RotaryTableDefaultSpeedGet(This,pSpeed_) ) 

#define IIMRotaryTable_RotaryTableMaximumSpeedGet(This,pSpeed_)	\
    ( (This)->lpVtbl -> RotaryTableMaximumSpeedGet(This,pSpeed_) ) 

#define IIMRotaryTable_RotaryTableMinimumSpeedGet(This,pSpeed_)	\
    ( (This)->lpVtbl -> RotaryTableMinimumSpeedGet(This,pSpeed_) ) 

#define IIMRotaryTable_RotaryTableSpeedSet(This,speed_)	\
    ( (This)->lpVtbl -> RotaryTableSpeedSet(This,speed_) ) 

#define IIMRotaryTable_RotaryTableCanChangeAcceleration(This,pCanChangeAcceleration_)	\
    ( (This)->lpVtbl -> RotaryTableCanChangeAcceleration(This,pCanChangeAcceleration_) ) 

#define IIMRotaryTable_RotaryTableDefaultAccelerationGet(This,pAcceleration_)	\
    ( (This)->lpVtbl -> RotaryTableDefaultAccelerationGet(This,pAcceleration_) ) 

#define IIMRotaryTable_RotaryTableMaximumAccelerationGet(This,pAcceleration_)	\
    ( (This)->lpVtbl -> RotaryTableMaximumAccelerationGet(This,pAcceleration_) ) 

#define IIMRotaryTable_RotaryTableMinimumAccelerationGet(This,pAcceleration_)	\
    ( (This)->lpVtbl -> RotaryTableMinimumAccelerationGet(This,pAcceleration_) ) 

#define IIMRotaryTable_RotaryTableAccelerationSet(This,acceleration_)	\
    ( (This)->lpVtbl -> RotaryTableAccelerationSet(This,acceleration_) ) 

#define IIMRotaryTable_RotaryTableAngleGet(This,pAngle_)	\
    ( (This)->lpVtbl -> RotaryTableAngleGet(This,pAngle_) ) 

#define IIMRotaryTable_RotaryTableStatusGet(This,pStatus_,pDetails_)	\
    ( (This)->lpVtbl -> RotaryTableStatusGet(This,pStatus_,pDetails_) ) 

#define IIMRotaryTable_RotaryTableHomingIsRequired(This,pIsHomingRequired_)	\
    ( (This)->lpVtbl -> RotaryTableHomingIsRequired(This,pIsHomingRequired_) ) 

#define IIMRotaryTable_RotaryTableRotateHome(This)	\
    ( (This)->lpVtbl -> RotaryTableRotateHome(This) ) 

#define IIMRotaryTable_RotaryTableRotate(This,angle_,direction_)	\
    ( (This)->lpVtbl -> RotaryTableRotate(This,angle_,direction_) ) 

#define IIMRotaryTable_RotaryTableCanStop(This,pCanStop_)	\
    ( (This)->lpVtbl -> RotaryTableCanStop(This,pCanStop_) ) 

#define IIMRotaryTable_RotaryTableStop(This)	\
    ( (This)->lpVtbl -> RotaryTableStop(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMRotaryTable_INTERFACE_DEFINED__ */


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


