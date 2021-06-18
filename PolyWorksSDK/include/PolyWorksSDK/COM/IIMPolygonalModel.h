

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMPolygonalModel.idl:
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

#ifndef __IIMPolygonalModel_h__
#define __IIMPolygonalModel_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMPolygonalModel_FWD_DEFINED__
#define __IIMPolygonalModel_FWD_DEFINED__
typedef interface IIMPolygonalModel IIMPolygonalModel;

#endif 	/* __IIMPolygonalModel_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IMTypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IIMPolygonalModel_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IIMPolygonalModel_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IIMPolygonalModel_0000_0000_v0_0_s_ifspec;

#ifndef __IIMPolygonalModel_INTERFACE_DEFINED__
#define __IIMPolygonalModel_INTERFACE_DEFINED__

/* interface IIMPolygonalModel */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMPolygonalModel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("73D4E075-A06E-496E-9EDD-8041E3964E47")
    IIMPolygonalModel : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PointsAndTrianglesGet( 
            /* [out][in] */ SAFEARRAY * *pArrayCoords_,
            /* [out][in] */ SAFEARRAY * *pArrayTriangles_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PointsAndTrianglesTransfer( 
            /* [in] */ EDigitizingVectorDirections digitizingVectorDir_,
            /* [full][in] */ SAFEARRAY * *digitizingVector_,
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayTriangles_) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UniqueIDGet( 
            /* [out] */ BSTR *pUniqueID_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMPolygonalModelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMPolygonalModel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMPolygonalModel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMPolygonalModel * This);
        
        HRESULT ( STDMETHODCALLTYPE *PointsAndTrianglesGet )( 
            IIMPolygonalModel * This,
            /* [out][in] */ SAFEARRAY * *pArrayCoords_,
            /* [out][in] */ SAFEARRAY * *pArrayTriangles_);
        
        HRESULT ( STDMETHODCALLTYPE *PointsAndTrianglesTransfer )( 
            IIMPolygonalModel * This,
            /* [in] */ EDigitizingVectorDirections digitizingVectorDir_,
            /* [full][in] */ SAFEARRAY * *digitizingVector_,
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayTriangles_);
        
        HRESULT ( STDMETHODCALLTYPE *UniqueIDGet )( 
            IIMPolygonalModel * This,
            /* [out] */ BSTR *pUniqueID_);
        
        END_INTERFACE
    } IIMPolygonalModelVtbl;

    interface IIMPolygonalModel
    {
        CONST_VTBL struct IIMPolygonalModelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMPolygonalModel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMPolygonalModel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMPolygonalModel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMPolygonalModel_PointsAndTrianglesGet(This,pArrayCoords_,pArrayTriangles_)	\
    ( (This)->lpVtbl -> PointsAndTrianglesGet(This,pArrayCoords_,pArrayTriangles_) ) 

#define IIMPolygonalModel_PointsAndTrianglesTransfer(This,digitizingVectorDir_,digitizingVector_,pArrayCoords_,pArrayTriangles_)	\
    ( (This)->lpVtbl -> PointsAndTrianglesTransfer(This,digitizingVectorDir_,digitizingVector_,pArrayCoords_,pArrayTriangles_) ) 

#define IIMPolygonalModel_UniqueIDGet(This,pUniqueID_)	\
    ( (This)->lpVtbl -> UniqueIDGet(This,pUniqueID_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMPolygonalModel_INTERFACE_DEFINED__ */


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


