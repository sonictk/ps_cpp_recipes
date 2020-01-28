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
//-------------------------------------------------------------------------------
//
//	File:
//		PIUSelect.cpp
//
//	Description:
//		Utility routines to select objects in Photoshop
//
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------
#include "PIUSelect.h"
#include "PITerminology.h"


//-------------------------------------------------------------------------------
//
//	PIUSelectByName
//
// Given a class and a "string" name. This routine will force focus on that Object.
//
//-------------------------------------------------------------------------------
SPErr PIUSelectByName(DescriptorClassID desiredClass, char *cstrValue)
{
	SPErr error = kSPNoError;
	PIActionReference reference = NULL;
	PIActionDescriptor descriptor = NULL;
	PIActionDescriptor result = NULL;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutName(reference,
										desiredClass,
										cstrValue);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->Make(&descriptor);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->PutReference(descriptor, 
		                                      keyNull, 
											  reference);
	if (error) goto returnError;
	
	error = sPSActionControl->Play(&result,
								   eventSelect,
								   descriptor, 
								   plugInDialogSilent);
	if (error) goto returnError;
	
	error = PIUCheckPlayResult(result);

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (descriptor != NULL)
		sPSActionDescriptor->Free(descriptor);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//
//	PIUSelectByIndex
//
// Given a class and an index. This routine will force focus on that Object.
//
//-------------------------------------------------------------------------------
SPErr PIUSelectByIndex(DescriptorClassID desiredClass, uint32 value)
{
	SPErr error = kSPNoError;
	PIActionReference reference = NULL;
	PIActionDescriptor descriptor = NULL;
	PIActionDescriptor result = NULL;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutIndex(reference,
										 desiredClass,
										 value);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->Make(&descriptor);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->PutReference(descriptor, 
		                                      keyNull, 
											  reference);
	if (error) goto returnError;
	
	error = sPSActionControl->Play(&result,
								   eventSelect,
								   descriptor, 
								   plugInDialogSilent);
	if (error) goto returnError;
	
	error = PIUCheckPlayResult(result);

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (descriptor != NULL)
		sPSActionDescriptor->Free(descriptor);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//
//	PIUSelectByID
//
// Given a class and an ID. This routine will force focus on that Object.
//
//-------------------------------------------------------------------------------
SPErr PIUSelectByID(DescriptorClassID desiredClass, uint32 value)
{
	SPErr error = kSPNoError;
	PIActionReference reference = NULL;
	PIActionDescriptor descriptor = NULL;
	PIActionDescriptor result = NULL;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutIdentifier(reference,
											  desiredClass,
											  value);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->Make(&descriptor);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->PutReference(descriptor, 
		                                      keyNull, 
											  reference);
	if (error) goto returnError;
	
	error = sPSActionControl->Play(&result,
								   eventSelect,
								   descriptor, 
								   plugInDialogSilent);
	if (error) goto returnError;
	
	error = PIUCheckPlayResult(result);

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (descriptor != NULL)
		sPSActionDescriptor->Free(descriptor);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}



//-------------------------------------------------------------------------------
//
//	PIUSelectByOffset
//
// Given a class and an offset. This routine will force focus on that Object.
//
//-------------------------------------------------------------------------------
SPErr PIUSelectByOffset(DescriptorClassID desiredClass, int32 value)
{
	SPErr error = kSPNoError;
	PIActionReference reference = NULL;
	PIActionDescriptor descriptor = NULL;
	PIActionDescriptor result = NULL;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutOffset(reference,
										  desiredClass,
										  value);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->Make(&descriptor);
	if (error) goto returnError;
	
	error = sPSActionDescriptor->PutReference(descriptor, 
		                                      keyNull, 
											  reference);
	if (error) goto returnError;
	
	error = sPSActionControl->Play(&result,
								   eventSelect,
								   descriptor, 
								   plugInDialogSilent);
	if (error) goto returnError;
	
	error = PIUCheckPlayResult(result);

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (descriptor != NULL)
		sPSActionDescriptor->Free(descriptor);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}

// end PIUSelect.cpp
