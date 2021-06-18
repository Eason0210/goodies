

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ..\..\Interfaces\IIMPointCloud3.idl:
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

#ifndef __IIMPointCloud3_h__
#define __IIMPointCloud3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IIMPointCloud3_FWD_DEFINED__
#define __IIMPointCloud3_FWD_DEFINED__
typedef interface IIMPointCloud3 IIMPointCloud3;

#endif 	/* __IIMPointCloud3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMPointCloud2.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IIMPointCloud3_INTERFACE_DEFINED__
#define __IIMPointCloud3_INTERFACE_DEFINED__

/* interface IIMPointCloud3 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IIMPointCloud3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E09EC8D-41E9-4B9F-9E2B-7447F425C599")
    IIMPointCloud3 : public IIMPointCloud2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PointsAdd3( 
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayNormals_,
            /* [full][in] */ SAFEARRAY * *pArrayColors_,
            /* [full][in] */ SAFEARRAY * *pArrayTimestamps_,
            /* [full][in] */ SAFEARRAY * *pArrayApproachDirs_) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIMPointCloud3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIMPointCloud3 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIMPointCloud3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIMPointCloud3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *PointsAdd )( 
            IIMPointCloud3 * This,
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayNormals_,
            /* [full][in] */ SAFEARRAY * *pArrayColors_);
        
        HRESULT ( STDMETHODCALLTYPE *PointsGetNb )( 
            IIMPointCloud3 * This,
            /* [retval][out] */ long *pNbPoints_);
        
        HRESULT ( STDMETHODCALLTYPE *PointsAdd2 )( 
            IIMPointCloud3 * This,
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayNormals_,
            /* [full][in] */ SAFEARRAY * *pArrayColors_,
            /* [full][in] */ SAFEARRAY * *pArrayTimestamps_,
            /* [full][in] */ SAFEARRAY * *pArrayApproachDirs_);
        
        HRESULT ( STDMETHODCALLTYPE *PointsAdd3 )( 
            IIMPointCloud3 * This,
            /* [full][in] */ SAFEARRAY * *pArrayCoords_,
            /* [full][in] */ SAFEARRAY * *pArrayNormals_,
            /* [full][in] */ SAFEARRAY * *pArrayColors_,
            /* [full][in] */ SAFEARRAY * *pArrayTimestamps_,
            /* [full][in] */ SAFEARRAY * *pArrayApproachDirs_);
        
        END_INTERFACE
    } IIMPointCloud3Vtbl;

    interface IIMPointCloud3
    {
        CONST_VTBL struct IIMPointCloud3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIMPointCloud3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIMPointCloud3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIMPointCloud3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIMPointCloud3_PointsAdd(This,pArrayCoords_,pArrayNormals_,pArrayColors_)	\
    ( (This)->lpVtbl -> PointsAdd(This,pArrayCoords_,pArrayNormals_,pArrayColors_) ) 

#define IIMPointCloud3_PointsGetNb(This,pNbPoints_)	\
    ( (This)->lpVtbl -> PointsGetNb(This,pNbPoints_) ) 


#define IIMPointCloud3_PointsAdd2(This,pArrayCoords_,pArrayNormals_,pArrayColors_,pArrayTimestamps_,pArrayApproachDirs_)	\
    ( (This)->lpVtbl -> PointsAdd2(This,pArrayCoords_,pArrayNormals_,pArrayColors_,pArrayTimestamps_,pArrayApproachDirs_) ) 


#define IIMPointCloud3_PointsAdd3(This,pArrayCoords_,pArrayNormals_,pArrayColors_,pArrayTimestamps_,pArrayApproachDirs_)	\
    ( (This)->lpVtbl -> PointsAdd3(This,pArrayCoords_,pArrayNormals_,pArrayColors_,pArrayTimestamps_,pArrayApproachDirs_) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIMPointCloud3_INTERFACE_DEFINED__ */


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


