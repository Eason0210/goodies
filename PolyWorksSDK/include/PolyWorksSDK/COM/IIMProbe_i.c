

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Jun 19 09:45:48 2012
 */
/* Compiler settings for ..\..\Interfaces\IIMProbe.idl:
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

MIDL_DEFINE_GUID(IID, IID_IIMProbe,0xd31aade0,0x0a1d,0x11d8,0x93,0xda,0x00,0xb0,0xd0,0x22,0x4d,0x3a);


MIDL_DEFINE_GUID(IID, IID_IIMProbe2,0x4DA18293,0xF6F4,0x42c4,0x8B,0x32,0x07,0xC5,0xB9,0x40,0xB8,0x75);


MIDL_DEFINE_GUID(IID, IID_IIMProbe3,0x661CC020,0xC3FD,0x42f8,0xA0,0x15,0xE4,0xC3,0xE8,0x40,0x98,0x59);


MIDL_DEFINE_GUID(IID, IID_IIMProbe4,0x9A9CF135,0xF297,0x4590,0x9D,0x5C,0x77,0x87,0x93,0x8A,0xE4,0x9E);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



