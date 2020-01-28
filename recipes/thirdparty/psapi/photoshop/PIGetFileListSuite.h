// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2005 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
/**
 * \file PIGetFileListSuite.h
 *
 * \brief This file contains all the public definitions and
 *	structures for GetFileList Suite.
 *
 * \details
 *	Use the GetFileList Suite :
 *	1) To get a list of file handles from FSSpec.
 *	If the second parameter is true (recursive ), it will go through all the folders and subfolders and 
 *	put all the files in a list and sort them and remove the duplicate entries.  The return value
 *	PIActionDescriptor will have PIActionList which contains all the file handles 
 *	in the right order.
 *	2) To get a list of browser names in the Helper\\Preview In folder.  All the 
 *	browser names will be ZStrings in PIActionList.
 *	3) Browse a given url with a given index for the browsers in the "Preview In" folder.
 *	   The index parameter is zero based.
 *	4) Browse a url with the default browser.
 *	5) Get the browser's SPPlatformFileSpecification using GetBrowserFileSpec method.  The method
 *	   takes the zero_based index for the browser.
 *	
 *
 * Distribution:
 *	PUBLIC
 *
 */

/**
* @defgroup PicaGetFileListSuite  Get File List Suite 
* Provides a plug-in with some file and browser functionality.
* The Get File List Suite is available in Adobe Photoshop 5.5 and later.
*
* The plug-in can use the Get File List Suite to:
*	- Get a list of file handles from FSSpec.
*	- Get a list of browser names in the Helper\\Preview In folder.  
*	- Browse a given url with a given index for the browsers in the "Preview In" folder.
*	- Browse a url with the default browser.
*	- Get the \c SPPlatformFileSpecification for the browser.  
*
* <b> Accessing the Suite </b> \n\n
* The Get File List suite is referred to as:
* @code
  #define kPSGetFileListSuite 			"Photoshop GetFileList Suite for Plug-ins"
@endcode
* There are six versions of the Get File List suite:
* @code
  #define kPSGetFileListSuiteVersion1		1
  #define kPSGetFileListSuiteVersion2		2
  #define kPSGetFileListSuiteVersion3		3
  #define kPSGetFileListSuiteVersion4		4
  #define kPSGetFileListSuiteVersion5		5
  #define kPSGetFileListSuiteVersion6		6
@endcode
* The suite is acquired as follows:
* @code
  PSGetFileListSuite6 *sPSGetFileList;

  // Use most recent version.
  error = sSPBasic->AcquireSuite(kPSGetFileListSuite,
  								 kPSGetFileListSuiteVersion6, 	 
  								 &sPSGetFileList);

  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/


#ifndef __PIGetFileListSuite__
#define __PIGetFileListSuite__

//-------------------------------------------------------------------------------
//	Includes.
//-------------------------------------------------------------------------------
#include "PIGeneral.h"

#if MSWindows && defined(__PSWorld__)
#endif

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------------------------------------------------
//	UI GetFileList suite.
//-------------------------------------------------------------------------------

/// Unique identifier for the Get File List Suite.
#define kPSGetFileListSuite 			"Photoshop GetFileList Suite for Plug-ins"

//-------------------------------------------------------------------------------
//	
//-------------------------------------------------------------------------------

/**
* Gets a list of file handles from \c fileSpec.  Optionally recurses subfolders 
* of \c fileSpec, depending on the value of \c recurse.
* @param des [OUT] The list of file handles, returned.  This \c PIActionDescriptor 
* contains a \c PIActionList, which consists of all the file handles in the right order.
* Action descriptors are read with
* the @ref PicaActionDescriptorSuite "Action Descriptor Suite."  Action lists are
* read with the @ref PicaActionListSuite "Action List Suite."
* @param fileSpec The specification from which to retrieve the file handles. 
* @param recurse Indicates whether to recurse through subfolders of \c fileSpec. If TRUE, 
* this routine goes through all folders and subfolders, puts all the files in a list
* and sorts them to remove the duplicate entries.  
* @returns Non-zero error if failure.
*/
#if Macintosh && __LP64__
typedef FSRef PIGetFileListHandleType;
#else
typedef FSSpec PIGetFileListHandleType;
#endif

typedef SPAPI SPErr (*GetFileHandleListProc) (PIActionDescriptor& des, PIGetFileListHandleType* fileSpec, bool recurse);

/**
* Gets a list of file handles from \c xPlatFileSpec as above.
*/
typedef SPAPI SPErr (*GetXPlatFileHandleListProc) (PIActionDescriptor& des, XPlatFileSpec* fileSpec, bool recurse);

/**
* Gets a list of browser names in the Helper\\Preview In folder.  
* @param des [OUT] The browser names, returned in a  \c PIActionDescriptor as 
* ZStrings in a \c PIActionList.  Action descriptors are read with
* the @ref PicaActionDescriptorSuite "Action Descriptor Suite."  Action lists are
* read with the @ref PicaActionListSuite "Action List Suite."
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*GetBrowserNameListProc) (PIActionDescriptor& des);

/**
* Browses a URL with a browser from the "Preview In" folder; the browser is chosen based on
* \c index.
* @param url The URL to browse.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*BrowseUrlWithIndexBrowserProc) (uint16 index, const char* url);

/**
* Browses a url with the default browser.
* @param url The URL to browse.
*/
typedef SPAPI SPErr (*BrowseUrlProc) (const char* url);

/**
* Gets the \c SPPlatformFileSpecification for a browser. The browser is
* selected from the list of browsers available in the "Preview In" folder based on \c index. 
* @param index The index of the browser for which to get the file specification. The index is zero-based.
* @param fileSpec [OUT] The platform file specification, returned.
* @returns Non-zero error if failure.
*/
typedef SPAPI SPErr (*GetBrowserFileSpecProc)(uint16 index, SPPlatformFileSpecification* fileSpec);
typedef SPAPI SPErr (*GetXPlatBrowserFileSpecProc)(uint16 index, XPlatFileSpec* fileSpec);

typedef	SPAPI SPErr (*GetDefaultSystemScriptProc)(int16& script);

typedef SPAPI SPErr (*HasDoubleByteInStringProc)(const char* charString, bool& hasDoubleByte);

typedef SPAPI SPErr (*GetWebTemplateFolderSpecProc)(SPPlatformFileSpecification* fileSpec);
typedef SPAPI SPErr (*GetXPlatWebTemplateFolderSpecProc)(XPlatFileSpec* fileSpec);

typedef SPAPI SPErr (*GetWebTemplateListProc) (PIActionDescriptor& styleList, bool recurse);

typedef SPAPI SPErr (*GetWindowsFileTypesProc) (char * fileTypeList, int32 bufferSize);

typedef SPAPI SPErr (*GetMacFileTypesProc) (OSType * typeList, int32 &numTypes, int32 bufferSize);

typedef SPAPI SPErr (*GetPresetsFolderSpecProc) (SPPlatformFileSpecification *fileSpec);
typedef SPAPI SPErr (*GetXPlatPresetsFolderSpecProc) (XPlatFileSpec *fileSpec);

typedef SPAPI SPErr (*InvalidateFileBrowserCacheProc) (const SPPlatformFileSpecification *fileSpec);
typedef SPAPI SPErr (*InvalidateXPlatFileBrowserCacheProc) (const XPlatFileSpec *fileSpec);

typedef SPAPI SPErr (*GetChewableFolderSpecProc) (SPPlatformFileSpecification *folderSpec);
typedef SPAPI SPErr (*GetXPlatChewableFolderSpecProc) (XPlatFileSpec *folderSpec);

typedef SPAPI SPErr (*GetChewableFreeSpaceProc) (int64& freeSpace);

//-------------------------------------------------------------------------------
//	 GetFileList suite version 1.
//-------------------------------------------------------------------------------

#define kPSGetFileListSuiteVersion1		1	 /**< Get File List Suite Version 1. */
#define kPSGetFileListSuiteVersion2		2	 /**< Get File List Suite Version 2. */
#define kPSGetFileListSuiteVersion3		3	 /**< Get File List Suite Version 3. */
#define kPSGetFileListSuiteVersion4		4	 /**< Get File List Suite Version 4. */
#define kPSGetFileListSuiteVersion5		5	 /**< Get File List Suite Version 5. */
#define kPSGetFileListSuiteVersion6		6	 /**< Get File List Suite Version 6. */
#define kPSGetFileListSuiteVersion7		7	 /**< Get File List Suite Version 7. XPlatFileSpec version. */

/** The set of routines available in Version 1 of the Get File List Suite. */
typedef struct 
	{
	GetFileHandleListProc 			GetFileHandleList;			/**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			/**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	/**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					/**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			/**< Function pointer to \c GetBrowserFileSpecProc. */
	} PSGetFileListSuite1;

/** The set of routines available in Version 2 of the Get File List Suite. */
typedef struct 
	{
	GetFileHandleListProc 			GetFileHandleList;			/**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			/**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	/**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					/**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			/**< Function pointer to \c GetBrowserFileSpecProc. */
	GetDefaultSystemScriptProc		GetDefaultSystemScript;		/**< Function pointer to \c GetDefaultSystemScriptProc. */
	} PSGetFileListSuite2;

/** The set of routines available in Version 3 of the Get File List Suite. */
typedef struct 
	{
	GetFileHandleListProc 			GetFileHandleList;			/**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			/**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	/**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					/**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			/**< Function pointer to \c GetBrowserFileSpecProc. */
	GetDefaultSystemScriptProc		GetDefaultSystemScript;		/**< Function pointer to \c GetDefaultSystemScriptProc. */
	HasDoubleByteInStringProc		HasDoubleByteInString;		/**< Function pointer to \c HasDoubleByteInStringProc. */			
	} PSGetFileListSuite3;

/** The set of routines available in Version 4 of the Get File List Suite. */
typedef struct 
	{
	GetFileHandleListProc 			GetFileHandleList;			/**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			/**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	/**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					/**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			/**< Function pointer to \c GetBrowserFileSpecProc. */
	GetDefaultSystemScriptProc		GetDefaultSystemScript;		/**< Function pointer to \c GetDefaultSystemScriptProc. */
	HasDoubleByteInStringProc		HasDoubleByteInString;		/**< Function pointer to \c HasDoubleByteInStringProc. */		
	GetWebTemplateFolderSpecProc	GetWebTemplateFolderSpec;	/**< Function pointer to \c GetWebTemplateFolderSpecProc. */
	GetWebTemplateListProc			GetWebTemplateList;			/**< Function pointer to \c GetWebTemplateListProc. */	
	} PSGetFileListSuite4;

/** The set of routines available in Version 5 of the Get File List Suite. */
typedef struct 
{
	GetFileHandleListProc 			GetFileHandleList;			 /**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			 /**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	 /**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					 /**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			 /**< Function pointer to \c GetBrowserFileSpecProc. */
	GetDefaultSystemScriptProc		GetDefaultSystemScript;		 /**< Function pointer to \c GetDefaultSystemScriptProc. */
	HasDoubleByteInStringProc		HasDoubleByteInString;		 /**< Function pointer to \c HasDoubleByteInStringProc. */		
	GetWebTemplateFolderSpecProc	GetWebTemplateFolderSpec;	 /**< Function pointer to \c GetWebTemplateFolderSpecProc. */
	GetWebTemplateListProc			GetWebTemplateList;			 /**< Function pointer to \c GetWebTemplateListProc. */	
	GetWindowsFileTypesProc			GetWindowsFileTypes;		 /**< Function pointer to \c GetWindowsFileTypesProc. */
	GetMacFileTypesProc				GetMacFileTypes;			 /**< Function pointer to \c GetMacFileTypesProc. */
	GetPresetsFolderSpecProc		GetPresetsFolderSpec;		 /**< Function pointer to \c GetPresetsFolderSpecProc. */
	InvalidateFileBrowserCacheProc	InvalidateFileBrowserCache;	 /**< Function pointer to \c InvalidateFileBrowserCacheProc. */
} PSGetFileListSuite5;

/** The set of routines available in Version 6 of the Get File List Suite. */
typedef struct 
{
	GetFileHandleListProc 			GetFileHandleList;			 /**< Function pointer to \c GetFileHandleListProc. */
	GetBrowserNameListProc			GetBrowserNameList;			 /**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc	BrowseUrlWithIndexBrowser;	 /**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc					BrowseUrl;					 /**< Function pointer to \c BrowseUrlProc. */
	GetBrowserFileSpecProc			GetBrowserFileSpec;			 /**< Function pointer to \c GetBrowserFileSpecProc. */
	GetDefaultSystemScriptProc		GetDefaultSystemScript;		 /**< Function pointer to \c GetDefaultSystemScriptProc. */
	HasDoubleByteInStringProc		HasDoubleByteInString;		 /**< Function pointer to \c HasDoubleByteInStringProc. */		
	GetWebTemplateFolderSpecProc	GetWebTemplateFolderSpec;	 /**< Function pointer to \c GetWebTemplateFolderSpecProc. */
	GetWebTemplateListProc			GetWebTemplateList;			 /**< Function pointer to \c GetWebTemplateListProc. */	
	GetWindowsFileTypesProc			GetWindowsFileTypes;		 /**< Function pointer to \c GetWindowsFileTypesProc. */
	GetMacFileTypesProc				GetMacFileTypes;			 /**< Function pointer to \c GetMacFileTypesProc. */
	GetPresetsFolderSpecProc		GetPresetsFolderSpec;		 /**< Function pointer to \c GetPresetsFolderSpecProc. */
	InvalidateFileBrowserCacheProc	InvalidateFileBrowserCache;	 /**< Function pointer to \c InvalidateFileBrowserCacheProc. */
	GetChewableFolderSpecProc       GetChewableFolderSpec;		 /**< Function pointer to \c GetChewableFolderSpecProc. */
	GetChewableFreeSpaceProc		GetChewableFreeSpace;		 /**< Function pointer to \c GetChewableFreeSpaceProc. */
} PSGetFileListSuite6;

/** The set of routines available in Version 7 of the Get File List Suite. */
typedef struct 
{
	GetXPlatFileHandleListProc			GetXPlatFileHandleList;			/**< Function pointer to \c GetXPlatFileHandleListProc. */
	GetBrowserNameListProc				GetBrowserNameList;				/**< Function pointer to \c GetBrowserNameListProc. */
	BrowseUrlWithIndexBrowserProc		BrowseUrlWithIndexBrowser;		/**< Function pointer to \c BrowseUrlWithIndexBrowserProc. */
	BrowseUrlProc						BrowseUrl;						/**< Function pointer to \c BrowseUrlProc. */
	GetXPlatBrowserFileSpecProc			GetXPlatBrowserFileSpec;		/**< Function pointer to \c GetXPlatBrowserFileSpecProc. */
	GetDefaultSystemScriptProc			GetDefaultSystemScript;			/**< Function pointer to \c GetDefaultSystemScriptProc. */
	HasDoubleByteInStringProc			HasDoubleByteInString;			/**< Function pointer to \c HasDoubleByteInStringProc. */		
	GetXPlatWebTemplateFolderSpecProc	GetXPlatWebTemplateFolderSpec;	/**< Function pointer to \c GetXPlatWebTemplateFolderSpecProc. */
	GetWebTemplateListProc				GetWebTemplateList;				/**< Function pointer to \c GetWebTemplateListProc. */	
	GetWindowsFileTypesProc				GetWindowsFileTypes;			/**< Function pointer to \c GetWindowsFileTypesProc. */
	GetMacFileTypesProc					GetMacFileTypes;				/**< Function pointer to \c GetMacFileTypesProc. */
	GetXPlatPresetsFolderSpecProc		GetXPlatPresetsFolderSpec;		/**< Function pointer to \c GetXPlatPresetsFolderSpecProc. */
	InvalidateXPlatFileBrowserCacheProc	InvalidateXPlatFileBrowserCache;/**< Function pointer to \c InvalidateXPlatFileBrowserCacheProc. */
	GetXPlatChewableFolderSpecProc		GetXPlatChewableFolderSpec;		/**< Function pointer to \c GetXPlatChewableFolderSpecProc. */
	GetChewableFreeSpaceProc			GetChewableFreeSpace;			/**< Function pointer to \c GetChewableFreeSpaceProc. */
} PSGetFileListSuite7;

//-------------------------------------------------------------------------------
//	C++ wrapper.
//-------------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

//-------------------------------------------------------------------------------
#endif	// PIGetFileListSuite

/** @} */