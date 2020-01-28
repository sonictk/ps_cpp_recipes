/***********************************************************************/
/*                                                                     */
/* ASPragma.h                                                          */
/* Makes #defines for #pragmas to eliminate compiler dependencies      */
/*                                                                     */
/* Copyright 1996-1999 Adobe Systems Incorporated.                     */
/* All Rights Reserved.                                                */
/*                                                                     */
/* Patents Pending                                                     */
/*                                                                     */
/* NOTICE: All information contained herein is the property of Adobe   */
/* Systems Incorporated. Many of the intellectual and technical        */
/* concepts contained herein are proprietary to Adobe, are protected   */
/* as trade secrets, and are made available only to Adobe licensees    */
/* for their internal use. Any reproduction or dissemination of this   */
/* software is strictly forbidden unless prior written permission is   */
/* obtained from Adobe.                                                */
/*                                                                     */
/* Started by Dave Lazarony, 01/26/1996                                */
/*                                                                     */
/***********************************************************************/

#ifndef __ASPragma__
#define __ASPragma__

#ifndef __ASConfig__
#include "ASConfig.h"
#endif


#ifdef MAC_ENV

#ifdef MACPPC_ENV
#define	PRAGMA_ALIGN_BEGIN			options align=mac68k
#define PRAGMA_ALIGN_END			options align=reset
#define PRAGMA_IMPORT_BEGIN			import on
#define PRAGMA_IMPORT_END			import off
#endif

#ifdef MAC68K_ENV
#error 68K plugins no longer supported!
#endif

#endif

#ifdef WIN_ENV
#define	PRAGMA_ALIGN_BEGIN			pack(push, 4)			
#define PRAGMA_ALIGN_END			pack(pop)
#define PRAGMA_IMPORT_BEGIN			
#define PRAGMA_IMPORT_END		
#endif


#endif
