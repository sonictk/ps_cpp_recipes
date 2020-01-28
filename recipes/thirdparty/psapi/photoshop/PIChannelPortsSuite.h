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
 * \file PIChannelPortsSuite.h
 *
 * \brief This file describes Photoshop's Channel Ports Suite for plug-ins
 *
 * \details
 * Copyright 1986-2000 Adobe Systems Incorporated.
 * All Rights Reserved.
 *
 * Distribution:
 *	PUBLIC
 *
 */


/** @defgroup PicaChannelPortsSuite  Channel Ports Suite Callbacks 
* Channel Ports are access points for reading and writing data from Photoshop internal 
* channel data structures. There are two types of ports: read ports and write ports. 
* You can retrieve a read port corresponding to a write port, but you cannot retrieve 
* a write port from a read port. The API does allow for write-only ports, although none 
* exist as of this version of the suite. \n\n
* These structures are used to get at merged pixel information, such as iterating through 
* the merged data of the current layer or entire document, to be able to return a selection 
* or use for a preview proxy.	\n\n
* For more information, refer @ref SelectionModule, especially see @ref selectionSelectorExecute.
*
* <b> Accessing the Suite </b> \n\n
* The Channel Ports suite is referred to as:
* @code
  #define kPSChannelPortsSuite 			"Photoshop ChannelPorts Suite for Plug-ins"
@endcode
* There are two version constants available:
* @code
  #define kPSChannelPortsSuiteVersion2			2	
  #define kPSChannelPortsSuiteVersion3			3  
@endcode
* The suite is acquired as follows:
* @code
  PSChannelPortsSuite1 *sPSChannelPorts;
 
  // Acquiring version 3.
  error = sSPBasic->AcquireSuite(kPSChannelPortsSuite,
  								 kPSChannelPortsSuiteVersion3,
  								 &sPSChannelPorts);

  if (error) goto . . . //handle error
@endcode
* For PICA errors, see SPErrorCodes.h.
* @{
*/

#ifndef __PIChannelPortsSuite__
#define __PIChannelPortsSuite__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIGeneral.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/// Unique identifier for the Channel Ports Suite.
#define kPSChannelPortsSuite 			"Photoshop ChannelPorts Suite for Plug-ins"

/******************************************************************************/

#define kPSChannelPortsSuiteVersion2			2	/**< Channel Ports Suite version 2  */
#define kPSChannelPortsSuiteVersion3			3	/**< Channel Ports Suite version 3. */

/******************************************************************************/

/** 
* The set of routines available in the Channel Ports Suite.
*/
typedef struct PSChannelPortsSuite1
	{
	/**Determines the number levels the port has. This is the number of levels
	* in the pyramid of an image.
    * @param port Port to check.
	* @param count [OUT] The number of levels the port has. Zero if port is invalid.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*CountLevels)
		(
		PIChannelPort port, 
		int32 *count
		);

	/** Gets the pixel depth at a given level. 
	* @param port Port to check.
	* @param level Level of the port to check.
	* @param depth [OUT] Pixel depth, returned. Zero if the port or level is invalid.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetDepth)
		(
		PIChannelPort port, 
		int32 level, 
		int32 *depth
		);

	/** Gets the bounds for the pixel data at a given level. 
	* @param port Port to check.
	* @param level Level of the port to check.
	* @param bounds [OUT] Rectangle that provides the bounds for the pixel data. An empty rectangle if
	* the parameters are invalid.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetDataBounds) 
		(
		PIChannelPort port,
		int32 level,
		VRect *bounds
		);

	/** Gets the bounds to which we can write at a given level.
	* @param port Port to check.
	* @param level Level of the port to check.
	* @param writeBounds [OUT] Rectangle that provides the write bounds for the pixel data. 
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetWriteLimit) 
		(
		PIChannelPort port,
		int32 level,
		VRect *writeBounds
		);

	/** Gets the tiling information at a given level.
	* @param port Port to check.
	* @param level Level of the port to check.
	* @param tileOrigin [OUT] Origin point for the tiling system.
	* @param tileSize [OUT]	Size of the tiles. This is the best size to work with, 
	* if possible.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetTilingGrid) 
		(
		PIChannelPort port,
		int32 level,
		VPoint *tileOrigin,
		VPoint *tileSize
		);

	/** Finds the rectangle used as the downsample source 
	* for a particular level in the pyramid.
	* @param port Port to check.
	* @param level Level of the port to check.
	* @param bounds [OUT]
	* @param supportLevel [OUT] Set to -1 if no support rectangle exists.
    * @param supportBounds [OUT] Support rectangle, returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetSupportRect) 
		(
		PIChannelPort port,
		int32 level, const 
		VRect *bounds,
		int32 *supportLevel, 
		VRect *supportBounds
		);

	/** Gets the dependent rectangle at a particular level.
	* @param port Port to check.
	* @param sourceLevel Level of the port to check.
	* @param sourceBounds [OUT]
	* @param dependentLevel
    * @param dependentBounds [OUT] Dependent rectangle, returned.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*GetDependentRect) 
		(
		PIChannelPort port,
		int32 sourceLevel, 
		const VRect *sourceBounds,
		int32 dependentLevel, 
		VRect *dependentBounds
		);

	/** Determines if the plug-in can read from the port.
	* @param port Port to check.
	* @param canRead [OUT] Indicates if the plug-in can read from the port; TRUE if so.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*CanRead) 
		(
		PIChannelPort port, 
		Boolean *canRead
		);

	/** Determines if the plug-in can write to the port.
	* @param port Port to check.
	* @param canRead [OUT] Indicates if the plug-in can write to the port; TRUE if so.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*CanWrite) 
		(
		PIChannelPort port, 
		Boolean *canWrite
		);

	/** Reads a given rectangle (tile) of pixels from a given level of the port. 
	* @param port Port to read from.
	* @param level Level of the port.
	* @param bounds [IN/OUT] Provides the rectangular area (tile) of the port to read as an input
	* parameter.  Provides the rectangular area (tile) of data actually read into 
	* \c destination.data as an output parameter, 
	* if \c result is \c noErr. If \c result is non-zero, the value is undefined.
	* @param destination [IN/OUT] A description of the memory to read, provided as input. 
	* The data read from the port is written into the buffer provided in \c destination.data. 
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*ReadPixelsFromLevel) 
		(
		PIChannelPort port,
		int32 level, 
		VRect *bounds,	/* IN/OUT */
		const PixelMemoryDesc *destination
		);

	/** Writes a rectangle (tile) of pixels to a level in the pyramid. 
	* @param port Port to write to.
	* @param bounds [IN/OUT] As input, provides the rectangular area (tile) of \c source.data the pixels 
	* are written from. As output, reflects the area of the port actually written to.
	* If the input rectangle maps to pixels beyond the bounds of the port, the output rectangle 
	* reflects the area actually written.
	* @param source A description of the memory to write. The actual pixels that are written to the port 
	* are provided in \c source.data. [??? no existing doc. verify. This appears to be an input only
	* parameter for this function, verify.]
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*WritePixelsToBaseLevel) 
		(
		PIChannelPort port,
		VRect *bounds,	/* IN/OUT */
		const PixelMemoryDesc *source
		);

	/** Reads a given rectangle (tile) of scaled data from the pyramid provided in the port.
	* To determine what level is used for a given scaling, use \c FindSourceForScaledRead.	
	* @param port Port to read from.
	* @param readRect [IN/OUT] Provides the rectangular area (tile) of the port to read as an input
	* parameter.  Provides the rectangular area (tile) of data actually read as an output parameter.
	* The output rectangle is scaled based on the information provided in \c scaling.
	* @param scaling A scaling between source and destination rectangles.
	* @param destination [IN/OUT] A description of the memory to read, provided as input. 
	* The data read from the port is written into \c destination.data. 
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*ReadScaledPixels) 
		(
		PIChannelPort port,
		VRect *readRect,	/* IN/OUT */
		const PSScaling *scaling,
		const PixelMemoryDesc *destination
		);

	/** Determines what level would be used for a given scaling.
	* @param port Port to read from.
	* @param readRect [IN/OUT] Provides the rectangular area of the port to read as an input
	* parameter.  Provides the rectangular area of data actually read as an output parameter.
	* The output rectangle is scaled based on the information provided in \c scaling.
	* @param scaling A scaling between source and destination rectangles for which to find the
	* pyramid level.
	* @param dstDepth
	* @param sourceLevel [OUT] The level that would be read from for this scaling.
	* @param sourceRect [OUT]  The rectangle that would be read from for this scaling.
	* @param sourceScalingBounds [OUT] The bounds used for scaling from this level to the final result.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*FindSourceForScaledRead) 
		(
		PIChannelPort port,
		const VRect *readRect,
		const PSScaling *scaling,
		int32 dstDepth,
		int32 *sourceLevel,
		VRect *sourceRect,
		VRect *sourceScalingBounds
		);

	/** Creates a pixel array and the port to go with it.
	* @param port Returned port.
	* @param rect The rectangle used to create a pixel array.
	* @param depth The pixel depth for the pixel array.
	* @param globalScope
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*New) 
		(
		PIChannelPort *port,
		const VRect *rect,
		int32 depth,
		Boolean globalScope
		);

	/**
	* Disposes of a port and sets the port to NULL.
	* @param port The port to dispose of.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr(* Dispose)
		(
		PIChannelPort *port
		);
	
	/*********************************************************************/

	// The following routines are new in version 3.

	// We wrap a variety of filtering operations into two callbacks. One
	// checks to see whether an operation is supported and the other
	// actually applies the operation from a source port to a destination
	// port. We do this rather than adding new routines for each operation
	// because it keeps us from having to repeatedly revise the suite
	// number. The list of operations is provided in PIChannelPortOperations.h.

	///@name New in version 3 
	//@{

	/** 
	* Checks to see whether the host supports an operation.
	* @param operation  The operation to check. See @ref ChannelPortOperations.
	* @param supported [OUT] Indicates whether the operation is supported; TRUE if so.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr(*SupportsOperation)
		(
		const char *operation,
		Boolean *supported
		);

	/**	 
	* Applies an operation from a source port to a destination port.
	* @param operation  The operation to apply. See @ref ChannelPortOperations.
	* @param sourcePort The source port to apply an operation from.
	* @param destinationPort The destination port to write the results of the operation.
	* @param maskPort
	* @param parameters A structure that provides the parameters for the operation. The
	* structure depends on the operation.  See @ref ChannelPortOperations.
	* @param rect [IN/OUT] A bounding rectangle; may also be an output parameter, depending on 
	* the operation.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr(*ApplyOperation)
		(
		const char *operation,
		PIChannelPort sourcePort,
		PIChannelPort destinationPort,
		PIChannelPort maskPort,
		void *parameters,	// The exact structure of which will depend on the operation
		VRect *rect			// A bounding rectangle. Could also be an output.
		);

	// We also support plug-ins adding and removing operations.
	
	/** 
	* Adds a channel port operation.
	* @param operation The name of the operation.
	* @param proc The routine to execute when this operation is invoked. The first three
	* parameters indicate source, destination and mask ports, respectively. The fifth
	* parameter is a bounding rectangle, and the sixth is a structure used to pass parameters
	* to the operation.
	* @param refCon
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr(*AddOperation) (const char *operation,
								SPErr (*proc) (PIChannelPort, PIChannelPort, PIChannelPort,
											   void *, VRect *, void *refCon),
								void *refCon);

	/** 
	* Removes a channel port operation.
	* @param operation The name of the operation.
	* @param refCon
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr(*RemoveOperation) (const char *operation, void **refCon);

	/** Supports using the copy-on-write mechanism.
	* @param result [OUT] The destination port, returned.
	* @param basePort The base port; must be frozen. See @ref Freeze.
	* @param writeLimit [OUT] Defines a rectangle that limits the scope of the write.
	* Can be NULL in which case writing is allowed everywhere.
	* @param globalScope
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*NewCopyOnWrite) (PIChannelPort *result,
								   PIChannelPort basePort,
								   VRect *writeLimit,
								   Boolean globalScope);

	/** Freezes the data associated with a channel port. This should generally only
	* be used in conjunction with ports allocated through \c NewCopyOnWrite.
	* @param port The port to freeze.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*Freeze) (PIChannelPort port);

	/** Restores an \c area within a copy-on-write port to its initial state.
	* @param port The port to restore.
	* @param area. The area to restore. If NULL, the entire port is restored.
	* @returns Non-zero error if failure.
	*/
	SPAPI SPErr (*Restore) (PIChannelPort port, VRect *area);
	//@}

	} PSChannelPortsSuite1;


#ifdef __cplusplus
}
#endif

/** @} */
#endif	// PIChannelPortsSuite
