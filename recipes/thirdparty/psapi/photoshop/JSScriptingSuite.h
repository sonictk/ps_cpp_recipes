// ADOBE SYSTEMS INCORPORATED
// Copyright  2002-2003 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
/**
 * \file JSScriptingSuite.h
 *
 * \brief This file contains all the public definitions and
 *	structures related to using the JavaScript engine.
 *
 * \details
 * The JavaScript suite is a set of routines to execute JavaScript code 
 * in a plug-in. These routines allow you to acquire, execute and release
 * a JavaScript engine. Use the JSScriptingSuite2 suite to get a JavaScript engine
 *	and execute scripting code.
 * The JavaScript suite is available in Adobe Photoshop 12.0 and later.
 *
**/


#ifndef __JSScriptingSuite__
#define __JSScriptingSuite__

#if MC_WIN
#include <crtdefs.h>
#endif

#ifndef __ASTypes__
#include "ASTypes.h"
#endif

#ifndef __ASPragma__
#include "ASPragma.h"
#endif

#ifndef __SPFiles__
#include "SPFiles.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma PRAGMA_IMPORT_BEGIN


/*******************************************************************************
 * @defgroup JavaScriptSuite
 **/

///Unique identifier for the JavaScript Scripting Suite.
#define kJSScriptingSuite				"JavaScript Scripting Suite"
#define kJSScriptingSuiteVersion4		4L
#define kJSScriptingSuiteVersion3		3L
#define kJSScriptingSuiteVersion2		2L
#define kJSScriptingSuiteVersion1		1L
#define kJSScriptingSuiteVersion		kJSScriptingSuiteVersion3
#define kJSScriptingVersion				kJSScriptingSuiteVersion


//-------------------------------------------------------------------------------
//	Error codes.
//-------------------------------------------------------------------------------
/** Standard errors that are returned:
 **		kSPBadParameterError
 **		kSPTroubleInitializingError
 **
 **	Suite specific errors:
 **/
/** @name JavaScript Error Codes */
//@{
#define kJSScriptExecutionError			'ScEr'	/**< Error executing the script code. */
#define kJSScriptInternalError			'ScIE'	/**< Internal error executing the script code. */
#define kJSScriptGeneralError			'ScGr'	/**< General error executing the script code. */
#define kJSScriptCantCreateEngine		'ScCJ'	/**< Engine cannot be created at this time. */
#define kJSScriptBadEnginReference		'ScBR'	/**< Engine reference is not valid. */
#define kJSScriptLanguageNotSupported	'Sc!s'	/**< Language is not supported. */
#define kJSBufferTooSmall				'Sbts'	/**< Buffer is too small error executing the script code. */
//@}
/** @} */	  // close defgroup, because I don't want others to appear in it.

/*******************************************************************************
 **
 **	Types
 **
 **/

/** @ingroup JavaScriptSuite */
typedef struct _t_JSEngine				* JSEngineRef; /**< Opaque ID for JavaScript engine. */

/** @name JavaScript Execution Modes */
//@{
enum  JavaScriptExecutionMode
{
 	kJSExecutionModeNoDebug				= 1,	/**< Never stop in the debugger. */
 	kJSExecutionModeDebugOnError		= 2,	/**< Stop in the debugger if an error is encountered. */
 	kJSExecutionModeDebugAtBeginning	= 3	/**< Stop in the debugger immediately. */
};



/*******************************************************************************
 * @ingroup JavaScriptSuite

	How to use the Scripting suite:
	
	To execute a JavaScript script inside a host application, you must acquire 
	and use a JavaScript engine instance.

	A typical use of the engine:

		JSEngineRef		engineRef = NULL;
		SPErr			err = noErr;

		JSScriptingSuite2 * sScriptingSuite = NULL;
		err = basicSuite->AcquireSuite(kJSScriptingSuite, 
		                           kJSScriptingSuiteVersion, 
								   (const void **)&sScriptingSuite);
		if ( err == kSPNoError ) 
		{
			err = sScriptingSuite->CreateEngine( &engineRef );
			if ( err == kSPNoError )
			{
				const ASUnicode        scriptText[] = {'a', 'l', 'e', 'r', 't', '(', '\'', 'h', 'i', '\'', ')', ';', 0 } ;  //    Script to create a new document
				const ASUnicode        * result = NULL;
			
				err = sScriptingSuite->ExecuteScript( engineRef, scriptText, kJSExecutionModeNoDebug, &result );
				if ( err == kJSScriptExecutionError )
				{
					//	If error during execution, display a dialog containing returned error information string.
					// ErrorAlert( result );
				}
			}
		}
		
		...
		
		err = sScriptingSuite->DeleteEngine( engineRef );
		engineRef = NULL;

		basicSuite->ReleaseSuite(kJSScriptingSuite, 
		                           kJSScriptingSuiteVersion);


	Notes:
	
		Do not deallocate the result value.  The engine instance owns it and will dispose of it.

		The engine instance doesn't need to be deleted after calling ExecuteJavaScript.  If you execute 
		multiple JavaScript scripts inside the same engine instance they will share the same context 
		(including global variables).  If you want scripts to execute independently use a different 
		engine instance for each script.
*/

/** @ingroup JavaScriptSuite */

/** The set of routines available in Version 4 of the JavaScript suite. */
typedef struct {

	///	Returns true if any of the published scripting engines is currently executing a script.
	ASAPI ASBoolean	(*ScriptIsRunning) ( void );

	///	Creates a new instance of a JavaScript Engine.
	ASAPI ASErr (*CreateEngine) ( JSEngineRef * engineRefPtr );
	
	///	Disposes of a JavaScript Engine instance.
	ASAPI ASErr (*DeleteEngine) ( JSEngineRef engineRef );

	/**	Set the default search path(s) for include files encountered in script files executed by 
	*	an engine.  This string contains all include directories, separated by the colon or the
	*	semicolon characters. **/
	ASAPI ASErr (*SetIncludePath) ( JSEngineRef engineRef, const ASUnicode * includePath );
	
	/**	Get the default search path(s) for include files encountered in script files executed by 
	*	an engine.  
	*
	*		buffSize		size, in ASUnicode characters, of the includePathBuff being passed in.
	*		If get fails, buffSize will contain the required size for the buffer to contain the entire path string. **/
	ASAPI ASErr (*GetIncludePath) ( JSEngineRef engineRef, ASUnicode * includePathBuff, long * buffSize );

	/**	Execute a JavaScript script
			@param engineRef Engine with which to execute JavaScript script, acquired from CreateEngine.
			@param script unicode text of the JavaScript script to be executed.
			@param executionMode If kJSExecutionModeRun then the JavaScript is executed normally, if kJSExecutionModeDebug then the JavaScript is halted at the first line and the debugger Ui is shown
			@param result Pointer to result of execution. If an execution error occured, the returned string will contain error information.
			@returns kSPNoError					Success. kJSScriptExecutionError		Additional information available in result string.
	**/
	ASAPI ASErr (*ExecuteScript) ( JSEngineRef				engineRef,
								   const ASUnicode			* script,
								   JavaScriptExecutionMode	executionMode,
								   const ASUnicode			** result );

	//@}

	/** Suspend / resume the processing of Apple events.
	This method can be nested and you have to call the method with "false" as many times
	as you call it with "true".
	----
	@param suspend		if true then processing of Apple events is suspended.
						if false, then processing of Apple events is resumed.
						If event processing becomes effectively resumed by calling this
						method with false, then all suspended events are dispatched before
						the method returns. This means that event processing should only
						be resumes when Photoshop is in a state where Apple events may be
						processed.
	*/
	ASAPI ASErr (*SuspendResumeAppleEventProcessing) (ASBoolean suspend);
	
	/** Return true if Apple event processing is suspended
	*/
	ASAPI ASErr (*IsAppleEventProcessingSuspended) (ASBoolean* suspended);

	/** Return true if any Apple events have been suspended since calling
	SuspendResumeAppleEventProcessing
	*/
	ASAPI ASErr (*HasSuspendedAppleEvents) (ASBoolean* hasEvents);

} JSScriptingSuite4;

/** The set of routines available in Version 3 of the JavaScript suite. */
typedef struct {

	///	Returns true if any of the published scripting engines is currently executing a script.
	ASAPI ASBoolean	(*ScriptIsRunning) ( void );

	///	Creates a new instance of a JavaScript Engine.
	ASAPI ASErr (*CreateEngine) ( JSEngineRef * engineRefPtr );
	
	///	Disposes of a JavaScript Engine instance.
	ASAPI ASErr (*DeleteEngine) ( JSEngineRef engineRef );

	/**	Set the default search path(s) for include files encountered in script files executed by 
	*	an engine.  This string contains all include directories, separated by the colon or the
	*	semicolon characters. **/
	ASAPI ASErr (*SetIncludePath) ( JSEngineRef engineRef, const ASUnicode * includePath );
	
	/**	Get the default search path(s) for include files encountered in script files executed by 
	*	an engine.  
	*
	*		buffSize		size, in ASUnicode characters, of the includePathBuff being passed in.
	*		If get fails, buffSize will contain the required size for the buffer to contain the entire path string. **/
	ASAPI ASErr (*GetIncludePath) ( JSEngineRef engineRef, ASUnicode * includePathBuff, long * buffSize );

	/**	Execute a JavaScript script
			@param engineRef Engine with which to execute JavaScript script, acquired from CreateEngine.
			@param script unicode text of the JavaScript script to be executed.
			@param executionMode If kJSExecutionModeRun then the JavaScript is executed normally, if kJSExecutionModeDebug then the JavaScript is halted at the first line and the debugger Ui is shown
			@param result Pointer to result of execution. If an execution error occured, the returned string will contain error information.
			@returns kSPNoError					Success. kJSScriptExecutionError		Additional information available in result string.
	**/
	ASAPI ASErr (*ExecuteScript) ( JSEngineRef				engineRef,
								   const ASUnicode			* script,
								   JavaScriptExecutionMode	executionMode,
								   const ASUnicode			** result );

	//@}

	/** Suspend / resume the processing of Apple events.
	This method can be nested and you have to call the method with "false" as many times
	as you call it with "true".
	----
	@param suspend		if true then processing of Apple events is suspended.
						if false, then processing of Apple events is resumed.
						If event processing becomes effectively resumed by calling this
						method with false, then all suspended events are dispatched before
						the method returns. This means that event processing should only
						be resumes when Photoshop is in a state where Apple events may be
						processed.
	*/
	ASAPI ASErr (*SuspendResumeAppleEventProcessing) (ASBoolean suspend);
	
	/** Return true if Apple event processing is suspended
	*/
	ASAPI ASErr (*IsAppleEventProcessingSuspended) (ASBoolean* suspended);

} JSScriptingSuite3;

/** The set of routines available in Version 2 of the JavaScript suite. */
typedef struct {

	///	Returns true if any of the published scripting engines is currently executing a script.
	ASAPI ASBoolean	(*ScriptIsRunning) ( void );

	///	Creates a new instance of a JavaScript Engine.
	ASAPI ASErr (*CreateEngine) ( JSEngineRef * engineRefPtr );
	
	///	Disposes of a JavaScript Engine instance.
	ASAPI ASErr (*DeleteEngine) ( JSEngineRef engineRef );

	/**	Set the default search path(s) for include files encountered in script files executed by 
	*	an engine.  This string contains all include directories, separated by the colon or the
	*	semicolon characters. **/
	ASAPI ASErr (*SetIncludePath) ( JSEngineRef engineRef, const ASUnicode * includePath );
	
	/**	Get the default search path(s) for include files encountered in script files executed by 
	*	an engine.  
	*
	*		buffSize		size, in ASUnicode characters, of the includePathBuff being passed in.
	*		If get fails, buffSize will contain the required size for the buffer to contain the entire path string. **/
	ASAPI ASErr (*GetIncludePath) ( JSEngineRef engineRef, ASUnicode * includePathBuff, long * buffSize );

	/**	Execute a JavaScript script
			@param engineRef Engine with which to execute JavaScript script, acquired from CreateEngine.
			@param script unicode text of the JavaScript script to be executed.
			@param executionMode If kJSExecutionModeRun then the JavaScript is executed normally, if kJSExecutionModeDebug then the JavaScript is halted at the first line and the debugger Ui is shown
			@param result Pointer to result of execution. If an execution error occured, the returned string will contain error information.
			@returns kSPNoError					Success. kJSScriptExecutionError		Additional information available in result string.
	**/
	ASAPI ASErr (*ExecuteScript) ( JSEngineRef				engineRef,
								   const ASUnicode			* script,
								   JavaScriptExecutionMode	executionMode,
								   const ASUnicode			** result );

	//@}
	///@name New in 12.0 version 2 of the suite
	//@{

	///	Creates a new instance of a JavaScript Engine with an APE reference for High Bandwidth API
	ASAPI ASErr (*CreateEngineAPE) ( JSEngineRef * engineRefPtr, intptr_t apeEngineRef  );

} JSScriptingSuite2;



/** @ingroup JavaScriptSuite */
/** The set of routines available in Version 1 of the JavaScript suite. */
typedef struct {

	///	@returns true if any of the published scripting engines is currently executing a script.
	ASAPI ASBoolean	(*ScriptIsRunning) ( void );

	///	Creates a new instance of a JavaScript Engine.
	ASAPI ASErr (*CreateEngine) ( JSEngineRef * engineRefPtr );
	
	///	Disposes of a JavaScript Engine instance.
	ASAPI ASErr (*DeleteEngine) ( JSEngineRef engineRef );

	/**	Set the default search path(s) for include files encountered in script files executed by 
	*	an engine.  This string contains all include directories, separated by the colon or the
	*	semicolon characters. **/
	ASAPI ASErr (*SetIncludePath) ( JSEngineRef engineRef, const ASUnicode * includePath );
	
	/**	Get the default search path(s) for include files encountered in script files executed by 
	*	an engine.  
	*
	*		buffSize		size, in ASUnicode characters, of the includePathBuff being passed in.
	*		If get fails, buffSize will contain the required size for the buffer to contain the entire path string. **/
	ASAPI ASErr (*GetIncludePath) ( JSEngineRef engineRef, ASUnicode * includePathBuff, long * buffSize );

	/**	Execute a JavaScript script
			@param engineRef Engine with which to execute JavaScript script, acquired from CreateEngine.
			@param script unicode text of the JavaScript script to be executed.
			@param executionMode If kJSExecutionModeRun then the JavaScript is executed normally, if kJSExecutionModeDebug then the JavaScript is halted at the first line and the debugger Ui is shown
			@param result Pointer to result of execution. If an execution error occured, the returned string will contain error information.
			@returns kSPNoError					Success. kJSScriptExecutionError		Additional information available in result string.
	**/
	ASAPI ASErr (*ExecuteScript) ( JSEngineRef				engineRef,
								   const ASUnicode			* script,
								   JavaScriptExecutionMode	executionMode,
								   const ASUnicode			** result );

} JSScriptingSuite1;


#pragma PRAGMA_IMPORT_END

#ifdef __cplusplus
}
#endif


#endif // __JSScriptingSuite__
