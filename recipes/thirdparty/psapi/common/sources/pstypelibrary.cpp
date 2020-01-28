// Machine generated IDispatch wrapper class(es) created with ClassWizard
// and then fixed by truark
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT



#include "pstypelibrary.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IActionReference properties

/////////////////////////////////////////////////////////////////////////////
// IActionReference operations

void IActionReference::GetForm(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020000, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::GetDesiredClass(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::PutClass(long desiredClass)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass);
}

void IActionReference::GetName(BSTR* name)
{
	static BYTE parms[] =
		VTS_PBSTR;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 name);
}

void IActionReference::PutName(long desiredClass, LPCTSTR name)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, name);
}

void IActionReference::GetIndex(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::PutIndex(long desiredClass, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, value);
}

void IActionReference::GetIdentifier(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::PutIdentifier(long desiredClass, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, value);
}

void IActionReference::GetOffset(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::PutOffset(long desiredClass, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, value);
}

void IActionReference::GetEnumerated(long* type, long* enumValue)
{
	static BYTE parms[] =
		VTS_PI4 VTS_PI4;
	InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 type, enumValue);
}

void IActionReference::PutEnumerated(long desiredClass, long type, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x6002000c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, type, value);
}

void IActionReference::GetProperty_(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x6002000d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionReference::PutProperty(long desiredClass, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6002000e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 desiredClass, value);
}

void IActionReference::GetContainer(LPDISPATCH* value)
{
	static BYTE parms[] =
		VTS_PDISPATCH;
	InvokeHelper(0x6002000f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}


/////////////////////////////////////////////////////////////////////////////
// IActionList properties

/////////////////////////////////////////////////////////////////////////////
// IActionList operations

void IActionList::GetType(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020000, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::GetCount(long* value)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetInteger(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutInteger(long value)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetDouble(long index, double* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PR8;
	InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutDouble(double value)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetUnitDouble(long index, long* unit, double* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PR8;
	InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, unit, value);
}

void IActionList::PutUnitDouble(long unit, double value)
{
	static BYTE parms[] =
		VTS_I4 VTS_R8;
	InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 unit, value);
}

void IActionList::GetString(long index, BSTR* str)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, str);
}

void IActionList::PutString(LPCTSTR str)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 str);
}

void IActionList::GetBoolean(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutBoolean(long value)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetList(long index, LPDISPATCH* actionList)
{
	static BYTE parms[] =
		VTS_I4 VTS_PDISPATCH;
	InvokeHelper(0x6002000c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, actionList);
}

void IActionList::PutList(LPDISPATCH actionList)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x6002000d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 actionList);
}

void IActionList::GetObject(long index, long* type, LPDISPATCH* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PDISPATCH;
	InvokeHelper(0x6002000e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, type, value);
}

void IActionList::PutObject(long type, LPDISPATCH value)
{
	static BYTE parms[] =
		VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x6002000f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 type, value);
}

void IActionList::GetGlobalObject(long index, long* type, LPDISPATCH* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PDISPATCH;
	InvokeHelper(0x60020010, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, type, value);
}

void IActionList::PutGlobalObject(long type, LPDISPATCH value)
{
	static BYTE parms[] =
		VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x60020011, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 type, value);
}

void IActionList::GetEnumerated(long index, long* type, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4;
	InvokeHelper(0x60020012, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, type, value);
}

void IActionList::PutEnumerated(long type, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60020013, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 type, value);
}

void IActionList::GetReference(long index, LPDISPATCH* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PDISPATCH;
	InvokeHelper(0x60020014, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutReference(LPDISPATCH value)
{
	static BYTE parms[] =
		VTS_DISPATCH;
	InvokeHelper(0x60020015, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetClass(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020016, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutClass(long value)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020017, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetGlobalClass(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020018, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutGlobalClass(long value)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020019, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 value);
}

void IActionList::GetPath(long index, BSTR* pathString)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x6002001a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, pathString);
}

void IActionList::PutPath(LPCTSTR pathString)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x6002001b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 pathString);
}

void IActionList::GetDataLength(long index, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x6002001c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::GetData(long index, BSTR* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x6002001d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, value);
}

void IActionList::PutData(long length, LPCTSTR value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6002001e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 length, value);
}


/////////////////////////////////////////////////////////////////////////////
// IActionDescriptor properties

/////////////////////////////////////////////////////////////////////////////
// IActionDescriptor operations

void IActionDescriptor::GetType(long key, long* type)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020000, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, type);
}

void IActionDescriptor::GetKey(long index, long* key)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 index, key);
}

void IActionDescriptor::HasKey(long key, long* HasKey)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, HasKey);
}

void IActionDescriptor::GetCount(long* count)
{
	static BYTE parms[] =
		VTS_PI4;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 count);
}

void IActionDescriptor::IsEqual(LPDISPATCH otherDesc, long* IsEqual)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PI4;
	InvokeHelper(0x60020004, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 otherDesc, IsEqual);
}

void IActionDescriptor::Erase(long key)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020005, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key);
}

void IActionDescriptor::Clear()
{
	InvokeHelper(0x60020006, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IActionDescriptor::GetInteger(long key, long* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020007, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, retval);
}

void IActionDescriptor::PutInteger(long key, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60020008, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}

void IActionDescriptor::GetDouble(long key, double* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PR8;
	InvokeHelper(0x60020009, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, retval);
}

void IActionDescriptor::PutDouble(long key, double value)
{
	static BYTE parms[] =
		VTS_I4 VTS_R8;
	InvokeHelper(0x6002000a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}

void IActionDescriptor::GetUnitDouble(long key, long* unitID, double* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PR8;
	InvokeHelper(0x6002000b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, unitID, retval);
}

void IActionDescriptor::PutUnitDouble(long key, long unitID, double value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_R8;
	InvokeHelper(0x6002000c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, unitID, value);
}

void IActionDescriptor::GetString(long key, BSTR* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x6002000d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, retval);
}

void IActionDescriptor::PutString(long key, LPCTSTR value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6002000e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}

void IActionDescriptor::GetBoolean(long key, long* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x6002000f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, retval);
}

void IActionDescriptor::PutBoolean(long key, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x60020010, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}

void IActionDescriptor::GetList(long key, LPDISPATCH* list)
{
	static BYTE parms[] =
		VTS_I4 VTS_PDISPATCH;
	InvokeHelper(0x60020011, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, list);
}

void IActionDescriptor::PutList(long key, LPDISPATCH list)
{
	static BYTE parms[] =
		VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x60020012, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, list);
}

void IActionDescriptor::GetObject(long key, long* classID, LPDISPATCH* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PDISPATCH;
	InvokeHelper(0x60020013, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID, retval);
}

void IActionDescriptor::PutObject(long key, long classID, LPDISPATCH value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x60020014, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID, value);
}

void IActionDescriptor::GetGlobalObject(long key, long* classID, LPDISPATCH* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PDISPATCH;
	InvokeHelper(0x60020015, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID, retval);
}

void IActionDescriptor::PutGlobalObject(long key, long classID, LPDISPATCH value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x60020016, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID, value);
}

void IActionDescriptor::GetEnumerated(long key, long* enumType, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4 VTS_PI4;
	InvokeHelper(0x60020017, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, enumType, value);
}

void IActionDescriptor::PutEnumerated(long key, long enumType, long value)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60020018, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, enumType, value);
}

void IActionDescriptor::GetReference(long key, LPDISPATCH* reference)
{
	static BYTE parms[] =
		VTS_I4 VTS_PDISPATCH;
	InvokeHelper(0x60020019, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, reference);
}

void IActionDescriptor::PutReference(long key, LPDISPATCH reference)
{
	static BYTE parms[] =
		VTS_I4 VTS_DISPATCH;
	InvokeHelper(0x6002001a, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, reference);
}

void IActionDescriptor::GetClass(long key, long* classID)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x6002001b, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID);
}

void IActionDescriptor::PutClass(long key, long classID)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6002001c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID);
}

void IActionDescriptor::GetGlobalClass(long key, long* classID)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x6002001d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID);
}

void IActionDescriptor::PutGlobalClass(long key, long classID)
{
	static BYTE parms[] =
		VTS_I4 VTS_I4;
	InvokeHelper(0x6002001e, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, classID);
}

void IActionDescriptor::GetPath(long key, BSTR* pathString)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x6002001f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, pathString);
}

void IActionDescriptor::PutPath(long key, LPCTSTR pathString)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x60020020, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, pathString);
}

void IActionDescriptor::GetDataLength(long key, long* value)
{
	static BYTE parms[] =
		VTS_I4 VTS_PI4;
	InvokeHelper(0x60020021, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}

void IActionDescriptor::GetData(long key, BSTR* retval)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x60020022, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, retval);
}

void IActionDescriptor::PutData(long key, LPCTSTR value)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x60020023, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 key, value);
}


/////////////////////////////////////////////////////////////////////////////
// IActionControl properties

/////////////////////////////////////////////////////////////////////////////
// IActionControl operations

LPDISPATCH IActionControl::Play(long eventID, LPDISPATCH parameters, long dialogOptions)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4 VTS_DISPATCH VTS_I4;
	InvokeHelper(0x60020000, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		eventID, parameters, dialogOptions);
	return result;
}

void IActionControl::GetActionProperty(LPDISPATCH reference, LPDISPATCH* propertyDesc)
{
	static BYTE parms[] =
		VTS_DISPATCH VTS_PDISPATCH;
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 reference, propertyDesc);
}

void IActionControl::StringIDToTypeID(LPCTSTR stringID, long* typeID)
{
	static BYTE parms[] =
		VTS_BSTR VTS_PI4;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 stringID, typeID);
}

void IActionControl::TypeIDToStringID(long typeID, BSTR* stringID)
{
	static BYTE parms[] =
		VTS_I4 VTS_PBSTR;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 typeID, stringID);
}


/////////////////////////////////////////////////////////////////////////////
// IAutoPSDoc properties

/////////////////////////////////////////////////////////////////////////////
// IAutoPSDoc operations

CString IAutoPSDoc::GetTitle()
{
	CString result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IAutoPSDoc::Close()
{
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void IAutoPSDoc::SaveTo(LPCTSTR fileName)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 fileName);
}

void IAutoPSDoc::Activate()
{
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// IAction properties

/////////////////////////////////////////////////////////////////////////////
// IAction operations

CString IAction::GetName()
{
	CString result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IAction::Play()
{
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// IActions properties

/////////////////////////////////////////////////////////////////////////////
// IActions operations

long IActions::GetCount()
{
	long result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH IActions::GetItem(long index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		index);
	return result;
}


/////////////////////////////////////////////////////////////////////////////
// IPhotoshopApplication properties

/////////////////////////////////////////////////////////////////////////////
// IPhotoshopApplication operations

CString IPhotoshopApplication::GetFullName()
{
	CString result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void IPhotoshopApplication::Quit()
{
	InvokeHelper(0x60020001, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH IPhotoshopApplication::Open(LPCTSTR fileName)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		fileName);
	return result;
}

long IPhotoshopApplication::PlayAction(LPCTSTR fileName)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x60020003, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		fileName);
	return result;
}

LPDISPATCH IPhotoshopApplication::GetActions()
{
	LPDISPATCH result;
	InvokeHelper(0x60020004, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH IPhotoshopApplication::MakeControlObject()
{
	LPDISPATCH result;
	InvokeHelper(0x60020005, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH IPhotoshopApplication::MakeDescriptor()
{
	LPDISPATCH result;
	InvokeHelper(0x60020006, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH IPhotoshopApplication::MakeList()
{
	LPDISPATCH result;
	InvokeHelper(0x60020007, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH IPhotoshopApplication::MakeReference()
{
	LPDISPATCH result;
	InvokeHelper(0x60020008, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long IPhotoshopApplication::GetVisible()
{
	long result;
	InvokeHelper(0x60020009, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void IPhotoshopApplication::SetVisible(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x60020009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}
