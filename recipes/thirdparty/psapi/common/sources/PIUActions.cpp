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
//		PIUActions.cpp
//
//	Description:
//		Utility routines for playing actions and getting information about
//		items in the actions palette.
//
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
//	Includes
//-------------------------------------------------------------------------------

#include "PIUActions.h"
#include "PITerminology.h"


//-------------------------------------------------------------------------------
//
// PIUActionsPlayByName
//
// Play an action given the name of the set and the name of the action.
// Returns any errors immediately.
//-------------------------------------------------------------------------------
SPErr PIUActionsPlayByName(char* setName, char* actionName)
{
	SPErr error = kSPNoError;
	PIActionDescriptor result = NULL;
	PIActionDescriptor descriptor = NULL;
	PIActionReference reference = NULL;
	
	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutName(reference, 
 	                                    classAction, 
										actionName);
	if (error) goto returnError;

	error = sPSActionReference->PutName(reference, 
										classActionSet, 
										setName);
	if (error) goto returnError;

	error = sPSActionDescriptor->Make(&descriptor);
	if (error) goto returnError;

	error = sPSActionDescriptor->PutReference(descriptor, 
											  keyNull, 
											  reference);
	if (error) goto returnError;

	error = sPSActionControl->Play(&result, 
		                           eventPlay, 
								   descriptor, 
								   plugInDialogSilent);
	if (error) goto returnError;

	error = PIUCheckPlayResult(result);
	if (error) goto returnError;

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
// PIUActionsGetName
//
// Get the name and the length of the name given the set and action indexes.
// Returns any errors immediately.
//-------------------------------------------------------------------------------
SPErr PIUActionsGetName(uint32 setIndex, 
					    uint32 actionIndex, 
					    char* actionName, 
					    uint32* actionNameLength)
{
	SPErr error = kSPNoError;
	PIActionDescriptor result = NULL;
	PIActionReference reference = NULL;
	Boolean hasKey = false;

	if (!actionName || !actionNameLength)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutIndex(reference, 
		                                 classAction, 
										 actionIndex);
	if (error) goto returnError;

	error = sPSActionReference->PutIndex(reference, 
										 classActionSet, 
										 setIndex);
	if (error) goto returnError;

	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	error = sPSActionDescriptor->HasKey(result, 
										keyName,
										&hasKey);
	if (error || !hasKey) goto returnError;

	error = sPSActionDescriptor->GetStringLength(result, 
						                         keyName,
												 actionNameLength);
	if (error) goto returnError;

	error = sPSActionDescriptor->GetString(result, 
						                   keyName,
										   actionName,
										   (*actionNameLength)+1);
	if (error) goto returnError;

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}


//-------------------------------------------------------------------------------
//
// PIUActionsGetName
//
// Get the name and the length of the name given the set name and action index.
// Returns any errors immediately.
//-------------------------------------------------------------------------------
SPErr PIUActionsGetName(char* setName, 
					    uint32 actionIndex, 
					    char* actionName, 
					    uint32* actionNameLength)
{
	SPErr error = kSPNoError;
	PIActionDescriptor result = NULL;
	PIActionReference reference = NULL;
	Boolean hasKey = false;

	if (!actionName || !actionNameLength || !setName)
		error = kSPBadParameterError;
	if (error) goto returnError;

	error = sPSActionReference->Make(&reference);
	if (error) goto returnError;

	error = sPSActionReference->PutIndex(reference, 
		                                 classAction, 
										 actionIndex);
	if (error) goto returnError;

	error = sPSActionReference->PutName(reference, 
										classActionSet, 
										setName);
	if (error) goto returnError;

	error = sPSActionControl->Get(&result, reference);
	if (error) goto returnError;

	error = sPSActionDescriptor->HasKey(result, 
										keyName,
										&hasKey);
	if (error || !hasKey) goto returnError;

	error = sPSActionDescriptor->GetStringLength(result, 
						                         keyName,
												 actionNameLength);
	if (error) goto returnError;

	error = sPSActionDescriptor->GetString(result, 
						                   keyName,
										   actionName,
										   (*actionNameLength)+1);
	if (error) goto returnError;

returnError:
	if (reference != NULL)
		sPSActionReference->Free(reference);
	if (result != NULL)
		sPSActionDescriptor->Free(result);
	
	return error;
}
// end PIUActions.cpp