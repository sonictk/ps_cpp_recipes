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
 *	\file PIAcquire.h		
 *
 *	\brief This file describes Photoshop's Acquisition/Import module interface.	
 *
 *	Distribution:
 *		PUBLIC
 *
 */		

/** @defgroup ImportModule Import Modules
* Import plug-in modules are used to capture images from add-on hardware, such as scanners
* or video cameras, and put these images into new Photoshop document windows.
* Import modules can also be used to read images from unsupported file formats, although file
* format modules often are better suited for this purpose. File format modules are accessed 
* directly from the @b Open command, while Import modules use the @b Import sub-menu.  
*
* Prior to Photoshop version 4.0 these modules were called Acquire modules. Most of the
* internal nomenclature and function calls reflect the old naming conventions, to stay compatible 
* with previous versions.   
*
* The file type for format modules for Mac OS is 8BAM, the extension for Windows is .8BA.
* 
* Please also see @ref PGImportModule "Writing Import Plug-ins"
*/

/** @defgroup StackRendererModule Stack Renderer Modules
* <!-- Bug in doxygen was skipping the first sentence of this defgroup. (But no others!)
*      Fix for now means including the bogus extra "." at the beginning of the description.
* -->
* Stack Renderer plug-in modules are used to render a stack of images (defined as a smart object)
* into a single image. A typical application includes stacking multiple low exposure images
* and rendering into a single clearer image.
*
* Stack Renderer plug-in modules are built on top of Import (Acquire) modules. This means
* that you define the plug-in through the PiPL resource as an Import module <tt> (Kind {Acquire});  </tt>
* but then additionally include the <tt> StackRenderer </tt> PiPL property to identify the plug-in to
* Photoshop as a Stack Renderer plug-in.
*
* Hence, Stack Renderer plug-ins share all data stuctures and selectors with @ref ImportModule
* "Import Modules". The relevant data structures and selectors include:  <br>
* - AcquireRecord, 
* - @ref acquireSelectorAbout,  
* - @ref acquireSelectorPrepare,
* - @ref acquireSelectorStart,
* - @ref acquireSelectorContinue, and
* - @ref acquireSelectorFinish.
*
* In particular, see the new field \c AcquireRecord::documentInfo, in which Photoshop provides the 
* plug-in with access to the image stack information.
*
* Please also see @ref PGStackRendererModule "Writing Stack Renderer Plug-ins"
*/


#ifndef __PIAcquire__
#define __PIAcquire__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"

/* Operation selectors */
///@name Import Module Selectors 
//@{

/** @ingroup ImportModule 
* @{
*/
/**  
* Allows the plug-in to display an about box for the Import Module. For this
* selector, the host does not pass the standard parameter block into the plug-in 
* main routine.  Instead it passes an \c AboutRecord.
*
* See @ref PGAboutBoxes	"About Boxes" for more information.
*/
#define acquireSelectorAbout	0

/**
* Allows the plug-in to indicate to the host the mode, size and resolution of the 
* image being returned, so it can allocate and initialize its data structures. In the
* handler for this selector, the plug-in can update its parameters based on the 
* passed scripting parameters, and show the user 
* interface, if requested.  \n\n
* During this call, the plug-in module should set \c AcquireRecord::imageMode, 
* \c AcquireRecord::imageSize 
* or \c AcquireRecord::imageSize32, 
* \c AcquireRecord::depth, \c AcquireRecord::planes, \c AcquireRecord::imageHRes and 
* \c AcquireRecord::imageVRes. 
* If an indexed color image is being returned, the plug-in 
* should also set \c AcquireRecord::redLUT, \c AcquireRecord::greenLUT and \c AcquireRecord::blueLUT. 
* If a duotone mode image is being returned, 
* you should also set \c AcquireRecord::duotoneInfo.  \n\n
* The plug-in host can loop back to \c acquireSelectorStart after completing \c acquireSelectorFinish
* to begin importing another image for multi-image importing.  See @ref PGMultipleImport 
* "Multiple Import" for	more information. 
*/
#define acquireSelectorStart	1

/**
* Returns an area of the image to the plug-in host. Photoshop continues 
* to call this routine until it either returns an error, or the plug-in module sets the 
* \c AcquireRecord::data field to NULL.  For a discussion of using \c AdvanceStateProc
* in the handler for this selector, see 
* @ref PGImportAdvanceState "Advance State and Import Modules."\n\n
* The area of the image the plug-in returns is specified by \c AcquireRecord::theRect or 
* \c AcquireRecord::theRect32, \c AcquireRecord::loPlane and \c AcquireRecord::hiPlane.
* If the 
* resolution of the imported image is always going to be very small (for example, NTSC frame 
* grabbers), the plug-in can simply set \c AcquireRecord::theRect or \c AcquireRecord::theRect32 to the 
* entire image area. However, 
* if you are working with large images, the plug-in must use the \c theRect or \c theRect32 field to 
* return the image in several pieces.  \n\n
* There are no restrictions on how the pieces tile the image; horizontal and vertical strips 
* are allowed as are a grid of tiles. Each piece should contain no more than \c AcquireRecord::maxData 
* bytes, less the size of any large tables or scratch areas allocated by the plug-in.
* These restrictions don’t apply if the buffer for the image data was allocated using the 
* Buffer or Handle suites.	\n\n
* The \c AcquireRecord::data field should point to the actual data being returned. The fields 
* \c AcquireRecord::colBytes, \c AcquireRecord::rowBytes 
* and \c AcquireRecord::planeBytes specify the organization of the data.\n\n
* The \c data field contains a pointer to the data being returned. The plug-in can allocate a buffer 
* for the data using:
* - the Mac OS \c NewPtr trap,
* - the Windows \c GlobalAlloc function, or
* - through the @ref PicaBufferSuite.
*
* The plug-in module is responsible for freeing this buffer in its @ref acquireSelectorFinish 
* handler.	\n\n
* @note Be careful processing user-cancel events during \c acquireSelectorContinue. Normally your 
* plug-in would be expecting another \c acquireSelectorContinue call. If the user cancels, the next 
* call is @ref acquireSelectorFinish, not \c acquireSelectorContinue!	
* 
* Photoshop is very flexible in the format in which image data can be returned. 
* 
* For example, to return just the red plane of an RGB color image, 
* use the following parameter values:
* 	<TABLE border="1"
* 	     summary="Return red plane of RGB.">
* 	<CAPTION><EM>Return red plane of RGB</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>0
* 	<TR><TH>colBytes<TD>1
* 	<TR><TH>rowBytes<TD>width of the area being returned
* 	<TR><TH>planeBytes<TD>ignored, since loPlane=hiPlane
* 	</TABLE> \n\n
* If you wish to return the RGB data in interleaved form (RGBRGB...), 
* use the following values:.
* Return RGB data in interleaved form
* 	<TABLE border="1"
* 	     summary="Return RGB values in interleaved form.">
* 	<CAPTION><EM>Return RGB values in interleaved form</EM></CAPTION>
* 	<TR><TH>Parameter<TH>Value
* 	<TR><TH>loPlane<TD>0
* 	<TR><TH>hiPlane<TD>2
* 	<TR><TH>colBytes<TD>3
* 	<TR><TH>rowBytes<TD>3 * width of the area being returned
* 	<TR><TH>planeBytes<TD>1
* 	</TABLE> 
*/
#define acquireSelectorContinue 2


/**
* Allows the plug-in to clean up after an image import. This call is made if and 
* only if the @ref acquireSelectorStart routine returns without error, even if the 
* @ref acquireSelectorContinue routine returns an error.
* Most plug-ins at least need to free the buffer used to return the image data.
* If Photoshop detects \e Command-period in the Mac OS or \e Escape in Windows while processing the 
* results of an \c acquireSelectorContinue call, it calls \c acquireSelectorFinish.	 \n\n
* For scripting issues related to \c acquireSelectorFinish, see 
* @ref PGImportScriptingFinish "Scripting at importSelectorFinish" \n\n
* The plug-in host can loop back to \c acquireSelectorStart after completing \c acquireSelectorFinish
* to begin importing another image for multi-image importing.  See @ref PGMultipleImport 
* "Multiple Import" for	more information. 
* @note If @ref acquireSelectorStart succeeds, 
* then Photoshop guarantees that acquireSelectorFinish is called.
*/
#define acquireSelectorFinish	3
/**
* Allows a plug-in module to adjust the Photoshop memory allocation 
* algorithm. Photoshop sets \c AcquireRecord::maxData to the maximum number of bytes it can allocate 
* to the plug-in. For Import modules to perform efficiently, you should reduce 
* \c maxData to permit 
* Photoshop to process the imported image in RAM. 
* Please see @ref PGMemoryMgmtStrategies "Memory Management Strategies". \n\n
*/
#define acquireSelectorPrepare	4

/**
* Allows the plug-in to do any final cleanup, and is typically used in the case where a 
* plug-in module is acquiring multiple images during a single invocation.
* If your plug-in is using finalization (the host set \c AcquireRecord::canFinalize and the plug-in set 
* \c AcquireRecord::wantFinalize) then the host makes this call after all possible looping is complete. 
* \n\n
* If your plug-in is scripting-aware and the plug-in has changed any initial parameters, 
* it should pass a complete descriptor back to the scripting system in the 
* @ref PIDescriptorParameters structure.
* @note If @ref acquireSelectorPrepare succeeds, i.e., the result value is zero, and \c wantFinalize=TRUE, 
* then Photoshop guarantees that \c acquireSelectorFinalize is called.
*/
#define acquireSelectorFinalize 5
/** @} */ // end ingroup
///@}


/*	Error return values. The plug-in module may also return standard Macintosh
	operating system error codes, or report its own errors, in which case it
	can return any positive integer. */

/** @defgroup ImportErrors Import Error Return Values
* The plug-in module can return standard operating system
* error codes, or report its own errors, in which case it
* can return any positive integer. 
* 
* @note In the event of any error during import, the document being imported is discarded.
*/
///@name Import Error Return Values
//@{
/** @ingroup ImportModule
* @{ 
*/
#define acquireBadParameters	-30000	/**< An error with the interface.
											 See @ref PGImportErrorHandling "Error Handling for Import Plug-ins." 
										*/
#define acquireNoScanner		-30001	/**< No scanner installed. 
											 See @ref PGImportErrorHandling "Error Handling for Import Plug-ins." 
										*/
#define acquireScannerProblem	-30002	/**< A problem with the scanner. 
											 See @ref PGImportErrorHandling "Error Handling for Import Plug-ins." 
										*/
/** @} */
//@}


/******************************************************************************/

#if PRAGMA_STRUCT_ALIGN
#pragma options align=mac68k
#endif

/** @ingroup ImportModule 
*/
/** This structure is passed to the plug-in module through the parameter block.
* See @ref PGPluginEntryPoint "Plug-in Entry Point" for an explanation of how the 
* host calls a plug-in.
*/
typedef struct AcquireRecord
	{

	int32			serialNumber;	/**< \deprecated Formerly the host serial number.
									   	 The host now reports
									     zero for the \c serialNumber. Plug-ins should use 
									     the @ref PropertySuite through the @ref AcquireRecord::propertyProcs field
									     and specify \c propSerialString2
									     to get the serial string. */

	TestAbortProc	abortProc;		/**< A pointer to the \c TestAbortProc callback. */

	ProgressProc	progressProc;	/**< A pointer the the \c ProgressProc callback. */

	int32			maxData;		/**< The maximum number of bytes Photoshop can free up for a plug-in
								         to use. The plug-in can reduce this 
										 value during in the handler for @ref acquireSelectorPrepare.  
										 The @ref acquireSelectorContinue handlers should process 
										 the image in pieces no larger than \c maxData, less 
										 the size of any large tables or scratch areas it 
										 has allocated. */

	int16			imageMode;		/**< The mode of the image being imported (grayscale, 
										 RGB Color, and so on). The plug-in should set this field 
										 during the @ref acquireSelectorStart handler. 
										 See @ref ImageModes for possible values. */

	Point			imageSize;		/**< \deprecated Use \c AcquireRecord::imageSize32. 
										 The size of the image. The plug-in should 
										 should set this field in the @ref acquireSelectorStart 
										 handler to inform Photoshop of the width, 
										 imageSize.h and height, imageSize.v of the image in pixels. 
										 For large document support, see @ref AcquireRecord::imageSize32 */
	
	int16			depth;			/**< The resolution of the image in bits per pixel per plane. 
										 The plug-in should set this field in the 
										 @ref acquireSelectorStart handler. The valid 
										 settings are 1, 8, 16, or 32. */	

	int16			planes; 		/**< The number of channels in the image. 
										 The plug-in should set this field in the 
										 @ref acquireSelectorStart handler. 
										 For example, if an RGB image without alpha channels is 
										 being returned, this field should be set to 3. Even 
										 though Import modules can create documents with up to 
										 24 channels, because of the implementation of 
										 the plane map, Import and Format modules should never 
										 try to work with more than 16 planes at a time. */

	Fixed			imageHRes;		/**< The horizontal resolution of the image in terms
										 of pixels per inch. This is a fixed point 
										 number (16 binary digits). Photoshop initializes this field 
										 to 72 pixels per inch. The plug-in should set this field 
										 in the @ref acquireSelectorStart handler. */

	Fixed			imageVRes;		/**< The vertical resolution of the image in terms
										 of pixels per inch. This is a fixed point 
										 number (16 binary digits). Photoshop initializes this field 
										 to 72 pixels per inch. The plug-in should set this field 
										 in the @ref acquireSelectorStart handler.  
										 @note The current version of Photoshop only supports square 
										 pixels, so it ignores the \c imageVRes field. Plug-ins 
										 should set both \c imageHRes and \c imageVRes anyway in case
										 future versions of Photoshop support non-square pixels. */

	LookUpTable		redLUT; 		/**< The red color table of the image. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref acquireSelectorStart handler. */

	LookUpTable		greenLUT;		/**< The green color table of the image. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref acquireSelectorStart handler. */

	LookUpTable		blueLUT;		/**< The blue color table of the image. If an indexed color mode 
										 image is being returned, the plug-in should set this field
										 in the @ref acquireSelectorStart handler. */

	void *			data;			/**< The buffer where image data is stored.
										 The plug-in should return a pointer to this buffer in the
										 @ref acquireSelectorContinue handlers. After the entire image 
										 has been processed, the continue selector handler should set 
										 this field to NULL. \n\n The plug-in is responsible for 
										 freeing any memory pointed to by this field.  This is a 
										 change from previous versions of the Photoshop Import 
										 interface. */

	Rect			theRect;		/**< \deprecated Use \c AcquireRecord::theRect32. The area of the image being returned. The plug-in should 
										 set this field in the @ref acquireSelectorContinue handler. 
										 See @ref AcquireRecord::theRect32 for large document support. */
	
	int16			loPlane;		/**< The first plane being returned. The plug-in should 
										 set this field in the @ref acquireSelectorContinue handler. 
										 For example, if interleaved RGB data is being 
										 used, it should be set to 0. */
	
	int16			hiPlane;		/**< The last plane being returned. The plug-in should 
										 set this field in the @ref acquireSelectorContinue handler. 
										 For example, if interleaved RGB data is being 
										 used, it should be set to 2. */

	int16			colBytes;		/**< The offset in bytes between columns of data in the buffer.
										 The @ref acquireSelectorContinue handler should set this field. 
										 This is usually 1 for non-interleaved data, or 
										 \c hiPlane-loPlane+1 for interleaved data.*/

	int32			rowBytes;		/**< The offset in bytes between rows of data in the buffer.
										 The @ref acquireSelectorContinue handler should set this 
										 field. */
	int32			planeBytes; 	/**< The offset in bytes between planes of data in the buffers.
										 The @ref acquireSelectorContinue handler should set this field. 
										 This field is ignored if \c loPlane=hiPlane. It should be set to 
										 1 for interleaved data. */

	Str255 			filename;		/**< Document file name. By default, Photoshop opens newly imported 
										 images as "Untitled-..." . For file-importing Import modules, 
										 set this field to the filename in the @ref acquireSelectorStart 
										 routine. Photoshop will display the correct window title. 
										 Scanning modules should ignore this field. */
	int16			vRefNum;		/**< \deprecated Volume reference number. Should be set to zero.*/
	Boolean 		dirty;			/**< Indicates whether the user is prompted to save the image
							 		     when closing the window.  By default, newly imported images 
							 		     are marked as dirty, meaning that the user is prompted to save 
							 		     the image when closing the window. Set this field to FALSE to 
							 		     prevent this. This does not reflect whether there are unsaved 
							 		     changes in the current document. */

	OSType			hostSig;		/**< The signature of the host, provided by the host.
	                                     The signature for Photoshop is signature is 8BIM. */
	HostProc		hostProc;		/**< A pointer to a host-defined callback procedure. 
									     May be NULL. */

	int32			hostModes;		/**< The image modes supported by the host. 
										 If the corresponding bit is 1, (where LSB = bit 0), 
										 the mode is supported. This field can be used by plug-ins to 
										 disable features such as color scanning if not supported by the host. 
										 See @ref ImageModes for supported current modes. */

	PlaneMap		planeMap;		/**< Maps plug-in plane (channel) numbers to host plane numbers.
										 The host initializes it to a linear map:  
									     \c planeMap[i]=i. The plug-in may change this mapping if
										 it sees the data in a different order. 
										 \n\n For example, Photoshop stores RGB images with an 
										 alpha channel in the order RGBA,  whereas most frame buffers 
										 store the data in ARGB order. To  work with the data in this 
										 order, the plug-in should set \c planeMap[0]=3, 
										 \c  planeMap[1]=0, \c planeMap[2]=1, 
									     and \c planeMap[3]=2. \n\n
									     @note Attempting to index past the end of a \c planeMap results 
									     in the identity map used for the indexing. */

	Boolean 		canTranspose;	/**< Indicates whether the host supports transposing images 
										 during or after scanning. When
										 TRUE, the host supports transposing. Photoshop always sets 
										 this field to TRUE. */
	Boolean 		needTranspose;	/**< Indicates whether the plug-in needs the image transposed.
									     Initialized by the host to FALSE. If the plug-in wishes 
										 to transpose the image, and \c canTranspose=TRUE, it should 
										 set this field to TRUE in the @ref acquireSelectorContinue 
										 handler.\n\n 
										 The logical effect is to transpose the image after scanning 
										 is complete, although some hosts may find it more efficient 
										 to transpose the data during scanning.	\n\n
										 This feature was added to the plug-in specification because 
										 versions of Photoshop prior to Photoshop 2.5 had a strong bias 
										 toward horizontal strips. Using this routine, a plug-in could 
										 import an image in vertical strips by passing Photoshop 
										 horizontal strips and then having Photoshop transpose the 
										 data when it was done. */

	Handle			duotoneInfo;	/**< A handle for duotone information. If your plug-in module is 
										 acquiring a duotone mode image, it should allocate a handle and 
										 return the duotone information in this field. 
										 The format of the information is the same as that provided by 
										 export modules.\n\n Your plug-in is responsible for freeing the 
										 handle in its @ref acquireSelectorFinish handler. */

	int32			diskSpace;		/**< \deprecated Use \c AcquireRecord::diskSpace64. The number of free bytes on the host’s scratch disk or disks. 
								         If the plug-in host does not use a scratch disk, this is -1.
								         See @ref AcquireRecord::diskSpace64 for large document support. */

	SpaceProc		spaceProc;		/**< A pointer to the \c SpaceProc callback. May be NULL. */

	PlugInMonitor	monitor;		/**< Monitor setup information for the host. */

	void *			platformData;	/**< Platform specific information. Not used under Mac OS.
									     See PlatformData in PITypes.h. */

	BufferProcs *	bufferProcs;	/**< A pointer to the Buffer suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See @ref BufferSuite. */
	
	ResourceProcs *	resourceProcs;	/**< A pointer to the Pseudo-Resource suite 
	                                     if it is supported by the host, otherwise NULL. 
	                                     See chapter @ref ResourceSuite. */
	
	ProcessEventProc processEvent;	/**< A pointer to the \c ProcessEventProc callback 
	                                     if it is supported by the host, otherwise NULL. */

	Boolean 		canReadBack;	/**< Indicates whether host supports reading back image data
								         for further processing, set to TRUE if it does. Photoshop
								         always sets this field to TRUE. */

	Boolean 		wantReadBack;	/**< Indicates whether the plug-in wants to read the data back.
										 If the plug-in module sets this flag and the host supports 
										 image read back, then the host ignores the contents of 
										 the buffer it is passed and  instead fills the buffer with 
										 the image data. It stores the data in the format described 
										 by @ref loPlane, @ref hiPlane, @ref colBytes, @ref rowBytes, 
										 @ref planeBytes, and @ref planeMap. If @ref theRect exceeds 
										 the bounds of the image, those portions of the buffer are 
										 left untouched. */

	Boolean 		acquireAgain;	/**< Indicates that the plug-in wants to acquire another image once
								         it has completed importing an image. If you want your plug-in 
								         to be called again to import another image, set this flag in 
								         the @ref acquireSelectorFinish handler. Plug-in hosts that support 
								         multiple image imports should start the import process again with 
								         a call to @ref acquireSelectorStart. \n\n
										 If you do not want to put up a user interface for each import, 
										 you should display your interface during the 
										 @ref acquireSelectorPrepare 
										 handler. With the addition of @ref acquireSelectorFinalize, 
										 import plug-in modules can now put up an interface that remains 
										 active across multiple imports.  \n\n
										 A plug-in module should not count on being called again just 
										 because it sets this flag; \c acquireSelectorFinish should still 
										 do all of the necessary cleanup.	\n\n
										 @note Plug-in hosts can choose to treat \c acquireAgain as FALSE. */

	Boolean 		canFinalize;	/**< Indicates whether the host can invoke the finalize selector; TRUE if
								         it can. */
	
	DisplayPixelsProc displayPixels; /**< A pointer to the \c DisplayPixelsProc callback 
	                                      if it is supported by the host, otherwise NULL.  */
	
	HandleProcs		*handleProcs;	/**< A pointer to the Handle callback suite 
	                                     if it is supported by the host, otherwise NULL.  
	                                     See @ref HandleSuite. */
	
	///@name New in 3.0
	//@{
	
	Boolean			wantFinalize;	/**< Indicates that the plug-in wants an @ref 
										 acquireSelectorFinalize call if the host provides the newer 
										 protocol. See @ref canFinalize. */

	char			reserved1[3];	/**< Provides alignment to a four byte boundary. */

	ColorServicesProc colorServices; /**< A pointer to the ColorServices callback 
	                                     if it is supported by the host, otherwise NULL. */
	
	AdvanceStateProc advanceState;	/**< \c AdvanceState callback.  Valid to call only
	                                   within an @ref acquireSelectorContinue
									   call. */
	//@}
	/* New in 3.0.4. */
	///@name New in 3.0.4 
	//@{
	ImageServicesProcs *imageServicesProcs;
									/**< Image Services callback suite. */
	
	int16			tileWidth;		/**< The width of the tiles provided by the host. This
										 is the best unit to work with, if possible. Zero if not set. */
	int16			tileHeight;		/**< The height of the tiles provided by the host. This
										 is the best unit to work with, if possible. Zero if not set. */
	
	Point			tileOrigin;		/**< The origin point of the tiling system. */

	PropertyProcs	*propertyProcs;	/**< Property callback suite. The plug-in needs to
									     dispose of the handle returned for	complex properties. The 
									     plug-in also maintains ownership of handles for
										 set properties. */
	//@}
	///@name New in 4.0
	//@{
	PIDescriptorParameters	*descriptorParameters;	/**< Descriptor callback suite.  */
	Str255					*errorString;			/**< An error reporting string to return to Photoshop.
	                                                 If the plug-in returns with result=errReportString then 
	                                                 this string is displayed as: 
	                                                 "Cannot complete operation because " + \c errorString. */
	//@}
	///@name New in 4.0.1
	//@{
	Boolean			isFirstAlphaTransparency;	/**< Indicates whether the first alpha channel contains 
													 transparency; TRUE if it does. */
	char			padding0;					/**< Fill character. */
	char			padding1;					/**< Fill character. */
	char			padding2;					/**< Fill character. */
	//@}
	///@name New in 5.0 
	//@{
	int32			maxValue;	/**< Maximum value of data; only used for 16 bit data. */

	SPBasicSuite	*sSPBasic; 	/**< PICA basic suite.  Provides the mechanism to access 
								     all PICA suites. */
	void			*plugInRef;	/**< Plug-in reference used by PICA. */
	
	int32			transparentIndex; /**< If IndexedColor, and < 256, this is the index of the 
											 transparent color (for GIF).] */
	
	Handle			iCCprofileData;		/**< Handle containing the ICC profile for the image;  
										     NULL if none. \n
										     The handle must be allocated using the Photoshop handle suite.
										     Photoshop uses the data after the Finish call
										     and then frees the handle. */

	int32			iCCprofileSize;		/**< Size of \c iCCprofileData. */
	
	int32			canUseICCProfiles;	/**< Indicates if the host uses ICC Profiles. Non-zero if 
										     the host can accept or export ICC profiles.
											 If this is zero, don't set or dereference 
											 \c iCCprofileData. */
	
	char			*pushDataSource;	/**< Pointer to c-string that contains TWAIN data source name.
											 Used for push scanning on Windows. */

	//@}										
	///@name New in 5.5 
	//@{
	int32			lutCount;			/**< Number of entries in the indexed color table. This 
									         should include the transparent index if any. Plug-ins 
									         should pad out the color table with black for backward 
									         compatibility.	*/
	
	//@}
	///@name New in 6.0 
	//@{
	int32			convertMode;		/**< Indicates whether the host supports conversion after reading; 
										     0 if it does not, -1 if it does. The plug-in can set this field
										     to the index of a color mode and this is treated by the host
										     as a request to automatically convert to that mode. Hosts can
										     ignore this request but they will make the host+plug-in 
										     combination appear broken. */
	//@}
	///@name New in 8.0 
	//@{
	int32		HostSupports32BitCoordinates;	/**< Indicates whether the host supports 32 bit plug-in 
												     API. */
	
	int32		PluginUsing32BitCoordinates;	/**< Indicates whether the plug-in is using the 32-bit 
													 fields; set to nonzero by the plug-in if it is. */
	
	VPoint		imageSize32;					/**< Size of image in 32 bit coordinates. 
													 Replaces @ref AcquireRecord::imageSize */
	
	VRect		theRect32;						/**< Rectangle being returned in 32 bit coordinates. 
													 Replaces @ref AcquireRecord::theRect */

	int64		diskSpace64;					/**< Free disk space on the host's scratch disk or
												     disks.  Set to a negative number if host does
												     not use a scratch disk. Replaces @ref AcquireRecord::diskSpace which
												     has a maximum of 2 GB */
												   
	uint16		*unicodeFilename;				/**< Null terminated UTF16 filename set by the plug-in.
	                                                 Plug-in needs to allocate and dispose the memory for  
	                                                 this string. Photoshop makes a copy of this 
	                                                 string. If this field is not NULL, Photoshop ignores 
	                                                 the @ref filename field. */
	//@}
	///@name New in 10.0 
	//@{
	ChannelPortProcs *channelPortProcs;			/**< Suite for passing pixels through channel ports,
												     used for the Stack Renderer plug-in. (NULL otherwise) */

	ReadImageDocumentDesc *documentInfo;		/**< Source document pixel data; used for the Stack Renderer
											         plug-in. (NULL otherwise) */

	//@}
	/* Reserved Space for Expansion -- decrement when you add stuff */
	///@name Reserved Space for Expansion
	//@{
	char			reserved [100]; 		   /**< Reserved for future use. Set to zero */
	//@}
	}
AcquireRecord, *AcquireRecordPtr;

#if PRAGMA_STRUCT_ALIGN
#pragma options align=reset
#endif

/******************************************************************************/

#endif	// __PIAcquire_h__
