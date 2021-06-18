

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:44 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMSharedMatrix.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IIMSharedMatrix,0x99BE6AD2,0x387E,0x4309,0x9A,0x96,0x5B,0xA7,0xBE,0xCC,0xFD,0xFC);


MIDL_DEFINE_GUID(IID, IID_IIMSharedMatrixUser,0xB0B521A7,0xD9BA,0x47b4,0x87,0x5F,0x7E,0x83,0x62,0x01,0x0D,0xEB);


MIDL_DEFINE_GUID(IID, IID_IIMSharedMatrixRepository,0x2B0FE9CB,0xDE60,0x4494,0xAF,0xD3,0x83,0xB5,0x11,0x59,0x41,0x27);


MIDL_DEFINE_GUID(IID, IID_IIMSharedMatrixRepositoryClient,0x1F338643,0x35CE,0x42e4,0xA5,0x25,0xEE,0x3A,0x40,0xDB,0xC3,0x1A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



