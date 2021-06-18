

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMScanner5.idl:
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

#ifndef __IIMScanner5_h__
#define __IIMScanner5_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMScanner5_FWD_DEFINED__
#define __IIMScanner5_FWD_DEFINED__
typedef interface IIMScanner5 IIMScanner5;

#endif 	/* __IIMScanner5_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScanner4.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMScanner5_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMScanner5_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMScanner5_0000_0000_v0_0_s_ifspec;

#ifndef __IIMScanner5_INTERFACE_DEFINED__
#define __IIMScanner5_INTERFACE_DEFINED__

/* interface IIMScanner5 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMScanner5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8A64A9B-5619-45F6-899A-8E8100044F29")
    IIMScanner5 : public IIMScanner4
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HasScanningOptionsDlg( 
            /* [retval][out] */ VARIANT_BOOL *pHasOptionsDlg_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanningOptionsDlgShow( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMScanner5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMScanner5 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMScanner5 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMScanner5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDeviceNameGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ BSTR *pName_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningConnectionInit )( 
            IIMScanner5 * This,
            /* [in] */ IIMScannerFeedback *pScannerFeedback_,
            /* [retval][out] */ long *pReturnVal_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningConnectionEnd )( 
            IIMScanner5 * This,
            /* [retval][out] */ long *pReturnVal_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDlgShow )( 
            IIMScanner5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDlgClose )( 
            IIMScanner5 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanNameDefaultGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ BSTR *pName_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanNameSet )( 
            IIMScanner5 * This,
            /* [in] */ BSTR name_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxEdgeLengthGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ double *pMaxEdgeLength_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxEdgeLengthSet )( 
            IIMScanner5 * This,
            /* [in] */ double maxEdgeLength_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshInterpolationStepGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ double *pInterpolationStep_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshInterpolationStepSet )( 
            IIMScanner5 * This,
            /* [in] */ double interpolationStep_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxAngleGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ double *pMaxAngle_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxAngleSet )( 
            IIMScanner5 * This,
            /* [in] */ double maxAngle_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDeviceMenuLocationGet )( 
            IIMScanner5 * This,
            /* [retval][out] */ BSTR *pMenuPath_);
        
        HRESULT ( STDMETHODCALLTYPE *OnScanningEvent )( 
            IIMScanner5 * This,
            /* [in] */ EScanningEvents event_);
        
        HRESULT ( STDMETHODCALLTYPE *DeviceDeprecatedNamesGet )( 
            IIMScanner5 * This,
            /* [out][in] */ SAFEARRAY * *pNames_);
        
        HRESULT ( STDMETHODCALLTYPE *HasScanningOptionsDlg )( 
            IIMScanner5 * This,
            /* [retval][out] */ VARIANT_BOOL *pHasOptionsDlg_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningOptionsDlgShow )( 
            IIMScanner5 * This);
        
        END_INTERFACE
    } IIMScanner5Vtbl;

    interface IIMScanner5
    {
        CONST_VTBL struct IIMScanner5Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMScanner5_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMScanner5_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMScanner5_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMScanner5_ScanningDeviceNameGet(This,pName_)	\
    ( (This)->lpVtbl -> ScanningDeviceNameGet(This,pName_) ) 

#define IIMScanner5_ScanningConnectionInit(This,pScannerFeedback_,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningConnectionInit(This,pScannerFeedback_,pReturnVal_) ) 

#define IIMScanner5_ScanningConnectionEnd(This,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningConnectionEnd(This,pReturnVal_) ) 

#define IIMScanner5_ScanningDlgShow(This)	\
    ( (This)->lpVtbl -> ScanningDlgShow(This) ) 

#define IIMScanner5_ScanningDlgClose(This)	\
    ( (This)->lpVtbl -> ScanningDlgClose(This) ) 

#define IIMScanner5_ScanNameDefaultGet(This,pName_)	\
    ( (This)->lpVtbl -> ScanNameDefaultGet(This,pName_) ) 

#define IIMScanner5_ScanNameSet(This,name_)	\
    ( (This)->lpVtbl -> ScanNameSet(This,name_) ) 

#define IIMScanner5_MeshMaxEdgeLengthGet(This,pMaxEdgeLength_)	\
    ( (This)->lpVtbl -> MeshMaxEdgeLengthGet(This,pMaxEdgeLength_) ) 

#define IIMScanner5_MeshMaxEdgeLengthSet(This,maxEdgeLength_)	\
    ( (This)->lpVtbl -> MeshMaxEdgeLengthSet(This,maxEdgeLength_) ) 

#define IIMScanner5_MeshInterpolationStepGet(This,pInterpolationStep_)	\
    ( (This)->lpVtbl -> MeshInterpolationStepGet(This,pInterpolationStep_) ) 

#define IIMScanner5_MeshInterpolationStepSet(This,interpolationStep_)	\
    ( (This)->lpVtbl -> MeshInterpolationStepSet(This,interpolationStep_) ) 

#define IIMScanner5_MeshMaxAngleGet(This,pMaxAngle_)	\
    ( (This)->lpVtbl -> MeshMaxAngleGet(This,pMaxAngle_) ) 

#define IIMScanner5_MeshMaxAngleSet(This,maxAngle_)	\
    ( (This)->lpVtbl -> MeshMaxAngleSet(This,maxAngle_) ) 


#define IIMScanner5_ScanningDeviceMenuLocationGet(This,pMenuPath_)	\
    ( (This)->lpVtbl -> ScanningDeviceMenuLocationGet(This,pMenuPath_) ) 


#define IIMScanner5_OnScanningEvent(This,event_)	\
    ( (This)->lpVtbl -> OnScanningEvent(This,event_) ) 


#define IIMScanner5_DeviceDeprecatedNamesGet(This,pNames_)	\
    ( (This)->lpVtbl -> DeviceDeprecatedNamesGet(This,pNames_) ) 


#define IIMScanner5_HasScanningOptionsDlg(This,pHasOptionsDlg_)	\
    ( (This)->lpVtbl -> HasScanningOptionsDlg(This,pHasOptionsDlg_) ) 

#define IIMScanner5_ScanningOptionsDlgShow(This)	\
    ( (This)->lpVtbl -> ScanningOptionsDlgShow(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMScanner5_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


