

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for ..\winsupp\OLEActions.IDL:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0620 
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
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_PhotoshopTypeLibrary,0x4B0AB3E1,0x80F1,0x11cf,0x86,0xB4,0x44,0x45,0x53,0x54,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IActionReference,0xb249c0b1,0xa004,0x11d1,0xb0,0x36,0x00,0xc0,0x4f,0xd7,0xec,0x47);


MIDL_DEFINE_GUID(IID, IID_IActionList,0xb249c0b0,0xa004,0x11d1,0xb0,0x36,0x00,0xc0,0x4f,0xd7,0xec,0x47);


MIDL_DEFINE_GUID(IID, IID_IActionDescriptor,0x7ca9de40,0x9eb3,0x11d1,0xb0,0x33,0x00,0xc0,0x4f,0xd7,0xec,0x47);


MIDL_DEFINE_GUID(IID, IID_IActionControl,0x38fb4290,0x9df6,0x11d1,0xb0,0x32,0x00,0xc0,0x4f,0xd7,0xec,0x47);


MIDL_DEFINE_GUID(IID, IID_IAutoPSDoc,0x9077D1E1,0x8959,0x11cf,0x86,0xB4,0x44,0x45,0x53,0x54,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IAction,0x90CED626,0x8D78,0x11cf,0x86,0xB4,0x44,0x45,0x53,0x54,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IActions,0x90CED625,0x8D78,0x11cf,0x86,0xB4,0x44,0x45,0x53,0x54,0x00,0x00);


MIDL_DEFINE_GUID(IID, IID_IPhotoshopApplication,0x9414F179,0xC905,0x11d1,0x92,0xCC,0x00,0x60,0x08,0x08,0xFC,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_PhotoshopApplication,0x6DECC242,0x87EF,0x11cf,0x86,0xB4,0x44,0x45,0x53,0x54,0x00,0x00);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



