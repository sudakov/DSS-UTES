// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IFmod wrapper class

class IFmod : public COleDispatchDriver
{
public:
	IFmod() {}		// Calls COleDispatchDriver default constructor
	IFmod(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IFmod(const IFmod& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	short SetVisible(short flag);
	short SetAggr(LPCTSTR name);
	short GetValue(double* v);
};
