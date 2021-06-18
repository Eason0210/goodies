

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for IMAlign.idl:
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


#ifndef __IMAlign_h__
#define __IMAlign_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMAlign_FWD_DEFINED__
#define __IMAlign_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMAlign IMAlign;
#else
typedef struct IMAlign IMAlign;
#endif /* __cplusplus */

#endif 	/* __IMAlign_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IIMAlign.h"
#include "IIMAlignProject5.h"
#include "IIMHost.h"
#include "IIMMessageCenter.h"
#include "IIMSceneCamera.h"
#include "IIMScannerFeedback2.h"
#include "IIMSettingsRepository2.h"
#include "IIMSoundCenter.h"
#include "IIMVisualFeedback2.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IMAlign_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IMAlign_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IMAlign_0000_0000_v0_0_s_ifspec;


#ifndef __IMAlignLib_LIBRARY_DEFINED__
#define __IMAlignLib_LIBRARY_DEFINED__

/* library IMAlignLib */
/* [helpstring][version][uuid] */ 





















EXTERN_C const IID LIBID_IMAlignLib;

EXTERN_C const CLSID CLSID_IMAlign;

#ifdef __cplusplus

class DECLSPEC_UUID("7E056424-CA81-49A3-9AC8-358E682C9E3B")
IMAlign;
#endif
#endif /* __IMAlignLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


