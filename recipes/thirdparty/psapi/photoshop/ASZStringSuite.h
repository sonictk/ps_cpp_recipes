/*
 * Name:
 *	ASZStringSuite.h
 *
 * Copyright 1986-1998 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Purpose:
 *	ZString handling suite.
 *
 * Distribution:
 *	PUBLIC
 *
 * Version history:
 *	1.0.0 1/26/1996	DL	First version.
 *		Created by Dave Lazarony.
 */

#ifndef _ASZSTRING_H_
#define _ASZSTRING_H_


#ifndef __ASTypes__
#include "ASTypes.h"
#endif

#ifndef __SPPlugins__
#include "SPPlugs.h"
#endif

#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

/*
 * Constants
 */

#define kASZStringSuite					"AS ZString Suite"
#define kASZStringDictionarySuite		"AS ZString Dictionary Suite"


#define kASUnknownErr				'UNK '
#define kASBufferTooSmallErr		'BUFF'
#define kASMemoryErr				'MEM '

/*
 * Types
 */

// aja 4.5.98 moved this into PIActions.h to accommodate SuspendHistory
#ifndef ASZString_defined
#define ASZString_defined
struct ASZByteRun;
typedef struct ASZByteRun* ASZString;
#endif

// ASUnicode is now defined in ASTypes.h
// NOTE : The definition is ASTypes.h is slightly different (unsigned instead of signed).
//typedef int16 ASUnicode;

/*
 * ZString Suite
 */

/******************************************************************************/

#define kASZStringSuiteVersion1	1

typedef struct ASZStringSuite
{
	
	ASErr ASAPI(*MakeFromUnicode)(ASUnicode* src, size_t charCount, ASZString* newZString);
	ASErr ASAPI(*MakeFromCString)(const char* src, size_t byteCount, ASZString* newZString);
	ASErr ASAPI(*MakeFromPascalString)(const unsigned char* src, size_t byteCount, 
										ASZString* newZString);

	ASErr ASAPI (*MakeRomanizationOfInteger)(ASInt32 value, ASZString* newZString);
	ASErr ASAPI (*MakeRomanizationOfFixed)(ASInt32 value, ASInt16 places, ASBoolean trim,
											ASBoolean isSigned, ASZString* newZString);
	ASErr ASAPI (*MakeRomanizationOfDouble)(real64 value, ASZString* newZString);
	ASZString ASAPI (*GetEmpty)();

	ASErr ASAPI (*Copy)(ASZString source, ASZString* copy);
	ASErr ASAPI (*Replace)(ASZString zstr, ASUInt32 index, ASZString replacement);
	ASErr ASAPI (*TrimEllipsis)(ASZString zstr);
	ASErr ASAPI (*TrimSpaces)(ASZString zstr);
	ASErr ASAPI (*RemoveAccelerators)(ASZString zstr);

	/* These functions support reference counting of ASZStrings.  When the 
	 * ASZString is created its reference count is one.  When the reference 
	 * count goes to zero, the ASZString referred to is deleted.
	 */
	ASErr ASAPI (*AddRef)(ASZString zstr);
	ASErr ASAPI (*Release)(ASZString zstr);



	ASBoolean ASAPI (*IsAllWhiteSpace)(ASZString zstr);
	ASBoolean ASAPI (*IsEmpty)(ASZString zstr);
	
	ASBoolean ASAPI (*WillReplace)(ASZString zstr, ASUInt32 index);

	ASUInt32 ASAPI (*LengthAsUnicodeCString)(ASZString zstr);
	ASErr ASAPI (*AsUnicodeCString)(ASZString zstr, ASUnicode* str, ASUInt32 strSize, 
		ASBoolean checkStrSize);

	ASUInt32 ASAPI (*LengthAsCString)(ASZString zstr);
	ASErr ASAPI (*AsCString)(ASZString zstr, char* str, ASUInt32 strSize, 
		ASBoolean checkStrSize);

	ASUInt32 ASAPI (*LengthAsPascalString)(ASZString zstr);
	ASErr ASAPI (*AsPascalString)(ASZString zstr, char* str, ASUInt32 strBufferSize, 
		ASBoolean checkBufferSize);

} ASZStringSuite1;


#define kASZStringSuiteVersion2	2

typedef struct ASZStringSuite2
{
	ASErr ASAPI(*MakeFromUnicode)(const ASUnicode* src, size_t byteCount, ASZString* newZString);
	ASErr ASAPI(*MakeFromUTF8String)(const unsigned char* src, ASZString* newZString);

	ASErr ASAPI (*MakeRomanizationOfInteger)(ASInt32 value, ASZString* newZString);
	ASErr ASAPI (*MakeRomanizationOfFixed)(ASInt32 value, ASInt16 places, ASBoolean trim,
											ASBoolean isSigned, ASZString* newZString);
	ASErr ASAPI (*MakeRomanizationOfDouble)(real64 value, ASZString* newZString);
	ASZString ASAPI (*GetEmpty)();

	ASErr ASAPI (*Copy)(ASZString source, ASZString* copy);
	ASErr ASAPI (*Replace)(ASZString zstr, ASUInt32 index, ASZString replacement);
	ASErr ASAPI (*TrimEllipsis)(ASZString zstr);
	ASErr ASAPI (*TrimSpaces)(ASZString zstr);
	ASErr ASAPI (*RemoveAccelerators)(ASZString zstr);

	/* These functions support reference counting of ASZStrings.  When the 
	 * ASZString is created its reference count is one.  When the reference 
	 * count goes to zero, the ASZString referred to is deleted.
	 */
	ASErr ASAPI (*AddRef)(ASZString zstr);
	ASErr ASAPI (*Release)(ASZString zstr);

	ASBoolean ASAPI (*IsAllWhiteSpace)(ASZString zstr);
	ASBoolean ASAPI (*IsEmpty)(ASZString zstr);
	
	ASBoolean ASAPI (*WillReplace)(ASZString zstr, ASUInt32 index);

	ASUInt32 ASAPI (*LengthAsUnicodeCString)(ASZString zstr);
	ASErr ASAPI (*AsUnicodeCString)(ASZString zstr, ASUnicode* str, ASUInt32 strSize, 
		ASBoolean checkStrSize);

    /* Return the length of a UTF8 encoding of the string including a terminating 0
    */
	ASUInt32 ASAPI (*LengthAsUTF8String)(ASZString zstr);
	ASErr ASAPI (*AsUTF8String)(ASZString zstr, unsigned char* str, ASUInt32 bufferSize,
		ASBoolean checkStrSize);
} ASZStringSuite2;


/******************************************************************************/

#define kASZStringDictionarySuiteVersion1		1

typedef struct 
{
	/* This functions set up the ZString tag-value pairs dictionary.  The 
	 * dictionary is scoped by the SPPluginRef to reduce naming conflicts 
	 * between plug-ins.
	 */
	ASErr ASAPI (*DictionaryAddTags)(SPPluginRef context, const char* tags);
	ASErr ASAPI (*DictionaryAddTagsRsrc)(SPPluginRef context, ASUInt32 rsrcType, ASInt16 rsrcID);
	ASErr ASAPI (*MakeFromTag)(SPPluginRef context, const char* tag, ASZString* newZString);
	
} ASZStringDictionarySuite1;



#ifdef __cplusplus
}
#endif

#endif /* _ASZSTRING_H_ */
