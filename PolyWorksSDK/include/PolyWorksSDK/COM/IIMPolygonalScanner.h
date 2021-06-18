

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMPolygonalScanner.idl:
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

#ifndef __IIMPolygonalScanner_h__
#define __IIMPolygonalScanner_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMPolygonalScanner_FWD_DEFINED__
#define __IIMPolygonalScanner_FWD_DEFINED__
typedef interface IIMPolygonalScanner IIMPolygonalScanner;

#endif 	/* __IIMPolygonalScanner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMScanner5.h"
#include "IIMPolygonalModel.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMPolygonalScanner_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMPolygonalScanner_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMPolygonalScanner_0000_0000_v0_0_s_ifspec;

#ifndef __IIMPolygonalScanner_INTERFACE_DEFINED__
#define __IIMPolygonalScanner_INTERFACE_DEFINED__

/* interface IIMPolygonalScanner */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMPolygonalScanner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09FCED15-ECCE-4F4C-A6C5-F859DC6361D4")
    IIMPolygonalScanner : public IIMScanner5
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ScanningStart( 
            /* [in] */ IIMPolygonalModel *pPolygonalModel_,
            /* [retval][out] */ long *pReturnVal_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanningEnd( 
            /* [retval][out] */ long *pReturnVal_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMPolygonalScannerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMPolygonalScanner * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMPolygonalScanner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMPolygonalScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDeviceNameGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ BSTR *pName_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningConnectionInit )( 
            IIMPolygonalScanner * This,
            /* [in] */ IIMScannerFeedback *pScannerFeedback_,
            /* [retval][out] */ long *pReturnVal_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningConnectionEnd )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ long *pReturnVal_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDlgShow )( 
            IIMPolygonalScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDlgClose )( 
            IIMPolygonalScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanNameDefaultGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ BSTR *pName_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanNameSet )( 
            IIMPolygonalScanner * This,
            /* [in] */ BSTR name_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxEdgeLengthGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ double *pMaxEdgeLength_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxEdgeLengthSet )( 
            IIMPolygonalScanner * This,
            /* [in] */ double maxEdgeLength_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshInterpolationStepGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ double *pInterpolationStep_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshInterpolationStepSet )( 
            IIMPolygonalScanner * This,
            /* [in] */ double interpolationStep_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxAngleGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ double *pMaxAngle_);
        
        HRESULT ( STDMETHODCALLTYPE *MeshMaxAngleSet )( 
            IIMPolygonalScanner * This,
            /* [in] */ double maxAngle_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningDeviceMenuLocationGet )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ BSTR *pMenuPath_);
        
        HRESULT ( STDMETHODCALLTYPE *OnScanningEvent )( 
            IIMPolygonalScanner * This,
            /* [in] */ EScanningEvents event_);
        
        HRESULT ( STDMETHODCALLTYPE *DeviceDeprecatedNamesGet )( 
            IIMPolygonalScanner * This,
            /* [out][in] */ SAFEARRAY * *pNames_);
        
        HRESULT ( STDMETHODCALLTYPE *HasScanningOptionsDlg )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ VARIANT_BOOL *pHasOptionsDlg_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningOptionsDlgShow )( 
            IIMPolygonalScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningStart )( 
            IIMPolygonalScanner * This,
            /* [in] */ IIMPolygonalModel *pPolygonalModel_,
            /* [retval][out] */ long *pReturnVal_);
        
        HRESULT ( STDMETHODCALLTYPE *ScanningEnd )( 
            IIMPolygonalScanner * This,
            /* [retval][out] */ long *pReturnVal_);
        
        END_INTERFACE
    } IIMPolygonalScannerVtbl;

    interface IIMPolygonalScanner
    {
        CONST_VTBL struct IIMPolygonalScannerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMPolygonalScanner_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMPolygonalScanner_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMPolygonalScanner_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMPolygonalScanner_ScanningDeviceNameGet(This,pName_)	\
    ( (This)->lpVtbl -> ScanningDeviceNameGet(This,pName_) ) 

#define IIMPolygonalScanner_ScanningConnectionInit(This,pScannerFeedback_,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningConnectionInit(This,pScannerFeedback_,pReturnVal_) ) 

#define IIMPolygonalScanner_ScanningConnectionEnd(This,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningConnectionEnd(This,pReturnVal_) ) 

#define IIMPolygonalScanner_ScanningDlgShow(This)	\
    ( (This)->lpVtbl -> ScanningDlgShow(This) ) 

#define IIMPolygonalScanner_ScanningDlgClose(This)	\
    ( (This)->lpVtbl -> ScanningDlgClose(This) ) 

#define IIMPolygonalScanner_ScanNameDefaultGet(This,pName_)	\
    ( (This)->lpVtbl -> ScanNameDefaultGet(This,pName_) ) 

#define IIMPolygonalScanner_ScanNameSet(This,name_)	\
    ( (This)->lpVtbl -> ScanNameSet(This,name_) ) 

#define IIMPolygonalScanner_MeshMaxEdgeLengthGet(This,pMaxEdgeLength_)	\
    ( (This)->lpVtbl -> MeshMaxEdgeLengthGet(This,pMaxEdgeLength_) ) 

#define IIMPolygonalScanner_MeshMaxEdgeLengthSet(This,maxEdgeLength_)	\
    ( (This)->lpVtbl -> MeshMaxEdgeLengthSet(This,maxEdgeLength_) ) 

#define IIMPolygonalScanner_MeshInterpolationStepGet(This,pInterpolationStep_)	\
    ( (This)->lpVtbl -> MeshInterpolationStepGet(This,pInterpolationStep_) ) 

#define IIMPolygonalScanner_MeshInterpolationStepSet(This,interpolationStep_)	\
    ( (This)->lpVtbl -> MeshInterpolationStepSet(This,interpolationStep_) ) 

#define IIMPolygonalScanner_MeshMaxAngleGet(This,pMaxAngle_)	\
    ( (This)->lpVtbl -> MeshMaxAngleGet(This,pMaxAngle_) ) 

#define IIMPolygonalScanner_MeshMaxAngleSet(This,maxAngle_)	\
    ( (This)->lpVtbl -> MeshMaxAngleSet(This,maxAngle_) ) 


#define IIMPolygonalScanner_ScanningDeviceMenuLocationGet(This,pMenuPath_)	\
    ( (This)->lpVtbl -> ScanningDeviceMenuLocationGet(This,pMenuPath_) ) 


#define IIMPolygonalScanner_OnScanningEvent(This,event_)	\
    ( (This)->lpVtbl -> OnScanningEvent(This,event_) ) 


#define IIMPolygonalScanner_DeviceDeprecatedNamesGet(This,pNames_)	\
    ( (This)->lpVtbl -> DeviceDeprecatedNamesGet(This,pNames_) ) 


#define IIMPolygonalScanner_HasScanningOptionsDlg(This,pHasOptionsDlg_)	\
    ( (This)->lpVtbl -> HasScanningOptionsDlg(This,pHasOptionsDlg_) ) 

#define IIMPolygonalScanner_ScanningOptionsDlgShow(This)	\
    ( (This)->lpVtbl -> ScanningOptionsDlgShow(This) ) 


#define IIMPolygonalScanner_ScanningStart(This,pPolygonalModel_,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningStart(This,pPolygonalModel_,pReturnVal_) ) 

#define IIMPolygonalScanner_ScanningEnd(This,pReturnVal_)	\
    ( (This)->lpVtbl -> ScanningEnd(This,pReturnVal_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMPolygonalScanner_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


