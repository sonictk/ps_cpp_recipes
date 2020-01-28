// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IActionReference wrapper class

class IActionReference : public COleDispatchDriver
{
public:
	IActionReference() {}		// Calls COleDispatchDriver default constructor
	IActionReference(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IActionReference(const IActionReference& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void GetForm(long* value);
	void GetDesiredClass(long* value);
	void PutClass(long desiredClass);
	void GetName(BSTR* name);
	void PutName(long desiredClass, LPCTSTR name);
	void GetIndex(long* value);
	void PutIndex(long desiredClass, long value);
	void GetIdentifier(long* value);
	void PutIdentifier(long desiredClass, long value);
	void GetOffset(long* value);
	void PutOffset(long desiredClass, long value);
	void GetEnumerated(long* type, long* enumValue);
	void PutEnumerated(long desiredClass, long type, long value);
	void GetProperty_(long* value);
	void PutProperty(long desiredClass, long value);
	void GetContainer(LPDISPATCH* value);
};
/////////////////////////////////////////////////////////////////////////////
// IActionList wrapper class

class IActionList : public COleDispatchDriver
{
public:
	IActionList() {}		// Calls COleDispatchDriver default constructor
	IActionList(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IActionList(const IActionList& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void GetType(long index, long* value);
	void GetCount(long* value);
	void GetInteger(long index, long* value);
	void PutInteger(long value);
	void GetDouble(long index, double* value);
	void PutDouble(double value);
	void GetUnitDouble(long index, long* unit, double* value);
	void PutUnitDouble(long unit, double value);
	void GetString(long index, BSTR* str);
	void PutString(LPCTSTR str);
	void GetBoolean(long index, long* value);
	void PutBoolean(long value);
	void GetList(long index, LPDISPATCH* actionList);
	void PutList(LPDISPATCH actionList);
	void GetObject(long index, long* type, LPDISPATCH* value);
	void PutObject(long type, LPDISPATCH value);
	void GetGlobalObject(long index, long* type, LPDISPATCH* value);
	void PutGlobalObject(long type, LPDISPATCH value);
	void GetEnumerated(long index, long* type, long* value);
	void PutEnumerated(long type, long value);
	void GetReference(long index, LPDISPATCH* value);
	void PutReference(LPDISPATCH value);
	void GetClass(long index, long* value);
	void PutClass(long value);
	void GetGlobalClass(long index, long* value);
	void PutGlobalClass(long value);
	void GetPath(long index, BSTR* pathString);
	void PutPath(LPCTSTR pathString);
	void GetDataLength(long index, long* value);
	void GetData(long index, BSTR* value);
	void PutData(long length, LPCTSTR value);
};
/////////////////////////////////////////////////////////////////////////////
// IActionDescriptor wrapper class

class IActionDescriptor : public COleDispatchDriver
{
public:
	IActionDescriptor() {}		// Calls COleDispatchDriver default constructor
	IActionDescriptor(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IActionDescriptor(const IActionDescriptor& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void GetType(long key, long* type);
	void GetKey(long index, long* key);
	void HasKey(long key, long* HasKey);
	void GetCount(long* count);
	void IsEqual(LPDISPATCH otherDesc, long* IsEqual);
	void Erase(long key);
	void Clear();
	void GetInteger(long key, long* retval);
	void PutInteger(long key, long value);
	void GetDouble(long key, double* retval);
	void PutDouble(long key, double value);
	void GetUnitDouble(long key, long* unitID, double* retval);
	void PutUnitDouble(long key, long unitID, double value);
	void GetString(long key, BSTR* retval);
	void PutString(long key, LPCTSTR value);
	void GetBoolean(long key, long* retval);
	void PutBoolean(long key, long value);
	void GetList(long key, LPDISPATCH* list);
	void PutList(long key, LPDISPATCH list);
	void GetObject(long key, long* classID, LPDISPATCH* retval);
	void PutObject(long key, long classID, LPDISPATCH value);
	void GetGlobalObject(long key, long* classID, LPDISPATCH* retval);
	void PutGlobalObject(long key, long classID, LPDISPATCH value);
	void GetEnumerated(long key, long* enumType, long* value);
	void PutEnumerated(long key, long enumType, long value);
	void GetReference(long key, LPDISPATCH* reference);
	void PutReference(long key, LPDISPATCH reference);
	void GetClass(long key, long* classID);
	void PutClass(long key, long classID);
	void GetGlobalClass(long key, long* classID);
	void PutGlobalClass(long key, long classID);
	void GetPath(long key, BSTR* pathString);
	void PutPath(long key, LPCTSTR pathString);
	void GetDataLength(long key, long* value);
	void GetData(long key, BSTR* retval);
	void PutData(long key, LPCTSTR value);
};
/////////////////////////////////////////////////////////////////////////////
// IActionControl wrapper class

class IActionControl : public COleDispatchDriver
{
public:
	IActionControl() {}		// Calls COleDispatchDriver default constructor
	IActionControl(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IActionControl(const IActionControl& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH Play(long eventID, LPDISPATCH parameters, long dialogOptions);
	void GetActionProperty(LPDISPATCH reference, LPDISPATCH* propertyDesc);
	void StringIDToTypeID(LPCTSTR stringID, long* typeID);
	void TypeIDToStringID(long typeID, BSTR* stringID);
};
/////////////////////////////////////////////////////////////////////////////
// IAutoPSDoc wrapper class

class IAutoPSDoc : public COleDispatchDriver
{
public:
	IAutoPSDoc() {}		// Calls COleDispatchDriver default constructor
	IAutoPSDoc(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAutoPSDoc(const IAutoPSDoc& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetTitle();
	void Close();
	void SaveTo(LPCTSTR fileName);
	void Activate();
};
/////////////////////////////////////////////////////////////////////////////
// IAction wrapper class

class IAction : public COleDispatchDriver
{
public:
	IAction() {}		// Calls COleDispatchDriver default constructor
	IAction(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAction(const IAction& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	void Play();
};
/////////////////////////////////////////////////////////////////////////////
// IActions wrapper class

class IActions : public COleDispatchDriver
{
public:
	IActions() {}		// Calls COleDispatchDriver default constructor
	IActions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IActions(const IActions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	LPDISPATCH GetItem(long index);
};
/////////////////////////////////////////////////////////////////////////////
// IPhotoshopApplication wrapper class

class IPhotoshopApplication : public COleDispatchDriver
{
public:
	IPhotoshopApplication() {}		// Calls COleDispatchDriver default constructor
	IPhotoshopApplication(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IPhotoshopApplication(const IPhotoshopApplication& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetFullName();
	void Quit();
	LPDISPATCH Open(LPCTSTR fileName);
	long PlayAction(LPCTSTR fileName);
	LPDISPATCH GetActions();
	LPDISPATCH MakeControlObject();
	LPDISPATCH MakeDescriptor();
	LPDISPATCH MakeList();
	LPDISPATCH MakeReference();
	long GetVisible();
	void SetVisible(long nNewValue);
};
