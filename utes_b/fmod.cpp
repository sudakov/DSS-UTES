// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "fmod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IFmod properties

/////////////////////////////////////////////////////////////////////////////
// IFmod operations

short IFmod::SetVisible(short flag)
{
	short result;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		flag);
	return result;
}

short IFmod::SetAggr(LPCTSTR name)
{
	short result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		name);
	return result;
}

short IFmod::GetValue(double* v)
{
	short result;
	static BYTE parms[] =
		VTS_PR8;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I2, (void*)&result, parms,
		v);
	return result;
}
