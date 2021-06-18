

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for IMInspect.idl:
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


#ifndef __IMInspect_h__
#define __IMInspect_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMInspect_FWD_DEFINED__
#define __IMInspect_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMInspect IMInspect;
#else
typedef struct IMInspect IMInspect;
#endif /* __cplusplus */

#endif 	/* __IMInspect_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMBuildInspectQueryInternal.h"
#include "IIMDeviceCameraFeedback.h"
#include "IIMDeviceLevelFeedback.h"
#include "IIMHost.h"
#include "IIMInspect.h"
#include "IIMInspectProject7.h"
#include "IIMMessageCenter.h"
#include "IIMPowerSourceFeedback.h"
#include "IIMProbeFeedback10.h"
#include "IIMRealTimeInspector2.h"
#include "IIMScannerFeedback2.h"
#include "IIMSceneCamera.h"
#include "IIMSettingsRepository2.h"
#include "IIMSoundCenter.h"
#include "IIMViewingTool.h"
#include "IIMVisualFeedback2.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IMInspect_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IMInspect_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IMInspect_0000_0000_v0_0_s_ifspec;


#ifndef __IMInspectLib_LIBRARY_DEFINED__
#define __IMInspectLib_LIBRARY_DEFINED__

/* library IMInspectLib */
/* [helpstring][version][uuid] */ 









































EXTERN_C const IID LIBID_IMInspectLib;

EXTERN_C const CLSID CLSID_IMInspect;

#ifdef __cplusplus

class DECLSPEC_UUID("F0520546-B16B-4299-B707-B5FA5B4AC635")
IMInspect;
#endif
#endif /* __IMInspectLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


