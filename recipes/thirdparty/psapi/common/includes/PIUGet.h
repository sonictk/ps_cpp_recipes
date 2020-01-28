// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------------------

#ifndef __PIUGet_H__		// Has this not been defined yet?
#define __PIUGet_H__		// Only include this once by predefining it

#include "PITypes.h"
#include "PIGeneral.h"
#include "SPBasic.h"
#include "PIActions.h"
#include "PIUSuites.h"

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/**	Given a class and an optional property PIUGetInfo will return the data 
	requested in returnData. The returnExtraData will hold unit or string length.
	If you are requesting a string you must pass in the max string length.
	Valid classes are classApplication, classDocument, classLayer, classPath,
	classHistoryState, classActionSet, classAction, classBackgroundLayer,
	classPath, et. al. When asking for the entire descriptor, setting
	desiredKey to 0, free the descriptor when finished.


	@param
		DescriptorClassID desiredClass	object request is about
	@param
		DescriptorKeyID desiredKey		specific key from object
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetInfo(DescriptorClassID desiredClass,
				 DescriptorKeyID desiredKey,
				 void * returnData,
				 void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** This routine is like PIUGetInfo but uses an index into an Object: Document,
	Layer, Channel, Path and get the information without having to select it 
	first. When asking for the entire descriptor, setting desiredKey to 0, 
	free the descriptor when finished. If you are requesting a string you must 
	pass in the max string length.

	NOTE:
	Some things like Paths have to be selected before actually getting the
	information.


	@param
		uint32 index					index, 3rd document for example
	@param
		DescriptorClassID desiredClass	object request is about
	@param
		DescriptorKeyID desiredKey		specific key from object
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetInfoByIndex(uint32 index,
						DescriptorClassID desiredClass,
						DescriptorKeyID desiredKey,
						void * returnData,
						void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** This routine is like PIUGetInfo but uses an index into an index. The third 
	layer of the second document. They just keep getting better. Object: 
	Document, Layer, Channel, Path and get the information without having to 
	select it first. When asking for the entire descriptor, setting desiredKey 
	to 0, free the descriptor when finished. If you are requesting a string you 
	must pass in the max string length.

	NOTE:
	Some things like Paths have to be selected before actually getting the
	information.


  	@param
		uint32 indexChild				index, 3rd layer for example
  	@param
		uint32 indexParent				index, 3rd document for example
	@param
		DescriptorClassID desiredClassChild	object of the child
	@param
		DescriptorClassID desiredClassParent	object of the parent
	@param
		DescriptorKeyID desiredKey		specific key from object
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetInfoByIndexIndex(uint32 indexChild,
							 uint32 indexParent,
							 DescriptorClassID desiredClassChild,
							 DescriptorClassID desiredClassParent,
							 DescriptorKeyID desiredKey,
							 void * returnData,
							 void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** Pull a single thing out of a descriptor. Use PIUGetInfo to retrieve the
	entire descriptor. Then use this routine to pull out specific items. If you 
	are requesting a string you must pass in the max string length.


	@param
		PIActionDescriptor result		descriptor to pull information from
	@param
		DescriptorKeyID desiredKey		specific key from result
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetSingleItemFromDescriptor(PIActionDescriptor result, 
								     DescriptorKeyID desiredKey, 
								     void * returnData,
								     void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** Pulls an error string out of your descriptor, useful for debugging.


	@param
		PIActionDescriptor descriptor	descriptor to pull information from
	@param
		char * stringPtr				pointer for error string
	@param
		uint32 maxLength				maximum length to copy into stringPtr
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetErrorStringFromDescriptor(PIActionDescriptor descriptor,
								      char * stringPtr,
									  uint32 maxLength);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** Get information out of the background layer. The background layer is a layer 
	that isn't really a layer so you need this special get call. If you are 
	requesting a string you must pass in the max string length.


	@param
		DescriptorKeyID desiredKey		specific key from result
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetBackgroundInfo(DescriptorKeyID desiredKey, 
						   void * returnData,
						   void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** This routine is like PIUGetInfo but uses an ID of an Object: Document,
	Layer, Channel, Path and get the information without having to select it 
	first. When asking for the entire descriptor, setting desiredKey to 0, 
	free the descriptor when finished. If you are requesting a string you must 
	pass in the max string length.

	IDs are far more reliable when trying to keep track of an object. 

	NOTE:
	Some things like Paths have to be selected before actually getting the
	information.


	@param
		uint32 ID						ID of the object
	@param
		DescriptorClassID desiredClass	object request is about
	@param
		DescriptorKeyID desiredKey		specific key from object
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetInfoByID(uint32 ID,
					 DescriptorClassID desiredClass,
					 DescriptorKeyID desiredKey,
					 void * returnData,
					 void * returnExtraData);


//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/** This routine is like PIUGetInfo but uses IDs of objects. Object: 
	Document, Layer, Channel, Path and get the information without having to 
	select it first. When asking for the entire descriptor, setting desiredKey 
	to 0, free the descriptor when finished. If you are requesting a string you 
	must pass in the max string length.

	NOTE:
	Some things like Paths have to be selected before actually getting the
	information.


  	@param
		uint32 IDChild					ID of the child
  	@param
		uint32 IDParent					ID of the parent
	@param
		DescriptorClassID desiredClassChild		object of the child
	@param
		DescriptorClassID desiredClassParent	object of the parent
	@param
		DescriptorKeyID desiredKey		specific key from object
	@param
		void * returnData				pointer to stuff information in
	@param
		void * returnExtraData			pointer to stuff extra information
	@return
		SPErr							error value of request. 0 = OK
*/
SPErr PIUGetInfoByIDID(uint32 IDChild,
					   uint32 IDParent,
					   DescriptorClassID desiredClassChild,
					   DescriptorClassID desiredClassParent,
					   DescriptorKeyID desiredKey,
					   void * returnData,
					   void * returnExtraData);
#endif
// end PIUGet.h
