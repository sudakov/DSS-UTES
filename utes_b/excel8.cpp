// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "excel8.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// _Application properties

/////////////////////////////////////////////////////////////////////////////
// _Application operations

LPDISPATCH _Application::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetCreator()
{
	long result;
	InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveCell()
{
	LPDISPATCH result;
	InvokeHelper(0x131, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveChart()
{
	LPDISPATCH result;
	InvokeHelper(0xb7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetActivePrinter()
{
	CString result;
	InvokeHelper(0x132, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetActivePrinter(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x132, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

LPDISPATCH _Application::GetActiveSheet()
{
	LPDISPATCH result;
	InvokeHelper(0x133, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveWindow()
{
	LPDISPATCH result;
	InvokeHelper(0x2f7, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetActiveWorkbook()
{
	LPDISPATCH result;
	InvokeHelper(0x134, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAddIns()
{
	LPDISPATCH result;
	InvokeHelper(0x225, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetAssistant()
{
	LPDISPATCH result;
	InvokeHelper(0x59e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::Calculate()
{
	InvokeHelper(0x117, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPDISPATCH _Application::GetCells()
{
	LPDISPATCH result;
	InvokeHelper(0xee, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCharts()
{
	LPDISPATCH result;
	InvokeHelper(0x79, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetColumns()
{
	LPDISPATCH result;
	InvokeHelper(0xf1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetCommandBars()
{
	LPDISPATCH result;
	InvokeHelper(0x59f, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetDDEAppReturnCode()
{
	long result;
	InvokeHelper(0x14c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::DDEExecute(long Channel, LPCTSTR String)
{
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x14d, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel, String);
}

long _Application::DDEInitiate(LPCTSTR App, LPCTSTR Topic)
{
	long result;
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x14e, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		App, Topic);
	return result;
}

void _Application::DDEPoke(long Channel, const VARIANT& Item, const VARIANT& Data)
{
	static BYTE parms[] =
		VTS_I4 VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x14f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel, &Item, &Data);
}

VARIANT _Application::DDERequest(long Channel, LPCTSTR Item)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x150, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Channel, Item);
	return result;
}

void _Application::DDETerminate(long Channel)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x151, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Channel);
}

VARIANT _Application::Evaluate(const VARIANT& Name)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x1, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Name);
	return result;
}

VARIANT _Application::_Evaluate(const VARIANT& Name)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xfffffffb, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Name);
	return result;
}

VARIANT _Application::ExecuteExcel4Macro(LPCTSTR String)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x15e, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		String);
	return result;
}

LPDISPATCH _Application::Intersect(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, 
		const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, 
		const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_DISPATCH VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT 
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x2fe, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Arg1, Arg2, &Arg3, &Arg4, &Arg5, &Arg6, &Arg7, &Arg8, &Arg9, &Arg10, &Arg11, &Arg12, &Arg13, &Arg14, &Arg15, &Arg16, &Arg17, &Arg18, &Arg19, &Arg20, &Arg21, &Arg22, &Arg23, &Arg24, &Arg25, &Arg26, &Arg27, &Arg28, &Arg29, &Arg30);
	return result;
}

LPDISPATCH _Application::GetNames()
{
	LPDISPATCH result;
	InvokeHelper(0x1ba, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetRange(const VARIANT& Cell1, const VARIANT& Cell2)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xc5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		&Cell1, &Cell2);
	return result;
}

LPDISPATCH _Application::GetRows()
{
	LPDISPATCH result;
	InvokeHelper(0x102, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

VARIANT _Application::Run(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT 
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x103, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Macro, &Arg1, &Arg2, &Arg3, &Arg4, &Arg5, &Arg6, &Arg7, &Arg8, &Arg9, &Arg10, &Arg11, &Arg12, &Arg13, &Arg14, &Arg15, &Arg16, &Arg17, &Arg18, &Arg19, &Arg20, &Arg21, &Arg22, &Arg23, &Arg24, &Arg25, &Arg26, &Arg27, &Arg28, &Arg29, &Arg30);
	return result;
}

VARIANT _Application::_Run2(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT 
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x326, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Macro, &Arg1, &Arg2, &Arg3, &Arg4, &Arg5, &Arg6, &Arg7, &Arg8, &Arg9, &Arg10, &Arg11, &Arg12, &Arg13, &Arg14, &Arg15, &Arg16, &Arg17, &Arg18, &Arg19, &Arg20, &Arg21, &Arg22, &Arg23, &Arg24, &Arg25, &Arg26, &Arg27, &Arg28, &Arg29, &Arg30);
	return result;
}

LPDISPATCH _Application::GetSelection()
{
	LPDISPATCH result;
	InvokeHelper(0x93, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::SendKeys(const VARIANT& Keys, const VARIANT& Wait)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x17f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Keys, &Wait);
}

LPDISPATCH _Application::GetSheets()
{
	LPDISPATCH result;
	InvokeHelper(0x1e5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetThisWorkbook()
{
	LPDISPATCH result;
	InvokeHelper(0x30a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::Union(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, const VARIANT& Arg11, 
		const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, const VARIANT& Arg21, 
		const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_DISPATCH VTS_DISPATCH VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT 
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x30b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Arg1, Arg2, &Arg3, &Arg4, &Arg5, &Arg6, &Arg7, &Arg8, &Arg9, &Arg10, &Arg11, &Arg12, &Arg13, &Arg14, &Arg15, &Arg16, &Arg17, &Arg18, &Arg19, &Arg20, &Arg21, &Arg22, &Arg23, &Arg24, &Arg25, &Arg26, &Arg27, &Arg28, &Arg29, &Arg30);
	return result;
}

LPDISPATCH _Application::GetWindows()
{
	LPDISPATCH result;
	InvokeHelper(0x1ae, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetWorkbooks()
{
	LPDISPATCH result;
	InvokeHelper(0x23c, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetWorksheetFunction()
{
	LPDISPATCH result;
	InvokeHelper(0x5a0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetWorksheets()
{
	LPDISPATCH result;
	InvokeHelper(0x1ee, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetExcel4IntlMacroSheets()
{
	LPDISPATCH result;
	InvokeHelper(0x245, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetExcel4MacroSheets()
{
	LPDISPATCH result;
	InvokeHelper(0x243, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::ActivateMicrosoftApp(long Index)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x447, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Index);
}

void _Application::AddChartAutoFormat(const VARIANT& Chart, LPCTSTR Name, const VARIANT& Description)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_BSTR VTS_VARIANT;
	InvokeHelper(0xd8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Chart, Name, &Description);
}

void _Application::AddCustomList(const VARIANT& ListArray, const VARIANT& ByRow)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x30c, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &ListArray, &ByRow);
}

BOOL _Application::GetAlertBeforeOverwriting()
{
	BOOL result;
	InvokeHelper(0x3a2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetAlertBeforeOverwriting(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3a2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetAltStartupPath()
{
	CString result;
	InvokeHelper(0x139, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetAltStartupPath(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x139, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetAskToUpdateLinks()
{
	BOOL result;
	InvokeHelper(0x3e0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetAskToUpdateLinks(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3e0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetEnableAnimations()
{
	BOOL result;
	InvokeHelper(0x49c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableAnimations(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x49c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

LPDISPATCH _Application::GetAutoCorrect()
{
	LPDISPATCH result;
	InvokeHelper(0x479, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetBuild()
{
	long result;
	InvokeHelper(0x13a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetCalculateBeforeSave()
{
	BOOL result;
	InvokeHelper(0x13b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetCalculateBeforeSave(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x13b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetCalculation()
{
	long result;
	InvokeHelper(0x13c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetCalculation(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x13c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

VARIANT _Application::GetCaller(const VARIANT& Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x13d, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index);
	return result;
}

BOOL _Application::GetCanPlaySounds()
{
	BOOL result;
	InvokeHelper(0x13e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetCanRecordSounds()
{
	BOOL result;
	InvokeHelper(0x13f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

CString _Application::GetCaption()
{
	CString result;
	InvokeHelper(0x8b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetCaption(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x8b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

BOOL _Application::GetCellDragAndDrop()
{
	BOOL result;
	InvokeHelper(0x140, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetCellDragAndDrop(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x140, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

double _Application::CentimetersToPoints(double Centimeters)
{
	double result;
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x43e, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		Centimeters);
	return result;
}

BOOL _Application::CheckSpelling(LPCTSTR Word, const VARIANT& CustomDictionary, const VARIANT& IgnoreUppercase)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x1f9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Word, &CustomDictionary, &IgnoreUppercase);
	return result;
}

VARIANT _Application::GetClipboardFormats(const VARIANT& Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x141, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index);
	return result;
}

BOOL _Application::GetDisplayClipboardWindow()
{
	BOOL result;
	InvokeHelper(0x142, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayClipboardWindow(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x142, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetCommandUnderlines()
{
	long result;
	InvokeHelper(0x143, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetCommandUnderlines(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x143, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetConstrainNumeric()
{
	BOOL result;
	InvokeHelper(0x144, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetConstrainNumeric(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x144, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT _Application::ConvertFormula(const VARIANT& Formula, long FromReferenceStyle, const VARIANT& ToReferenceStyle, const VARIANT& ToAbsolute, const VARIANT& RelativeTo)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x145, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&Formula, FromReferenceStyle, &ToReferenceStyle, &ToAbsolute, &RelativeTo);
	return result;
}

BOOL _Application::GetCopyObjectsWithCells()
{
	BOOL result;
	InvokeHelper(0x3df, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetCopyObjectsWithCells(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3df, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetCursor()
{
	long result;
	InvokeHelper(0x489, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetCursor(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x489, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetCustomListCount()
{
	long result;
	InvokeHelper(0x313, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetCutCopyMode()
{
	long result;
	InvokeHelper(0x14a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetCutCopyMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetDataEntryMode()
{
	long result;
	InvokeHelper(0x14b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetDataEntryMode(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x14b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _Application::Get_Default()
{
	CString result;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Application::GetDefaultFilePath()
{
	CString result;
	InvokeHelper(0x40e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultFilePath(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

void _Application::DeleteChartAutoFormat(LPCTSTR Name)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0xd9, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Name);
}

void _Application::DeleteCustomList(long ListNum)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x30f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 ListNum);
}

LPDISPATCH _Application::GetDialogs()
{
	LPDISPATCH result;
	InvokeHelper(0x2f9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetDisplayAlerts()
{
	BOOL result;
	InvokeHelper(0x157, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayAlerts(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x157, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayFormulaBar()
{
	BOOL result;
	InvokeHelper(0x158, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayFormulaBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x158, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayFullScreen()
{
	BOOL result;
	InvokeHelper(0x425, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayFullScreen(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x425, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayNoteIndicator()
{
	BOOL result;
	InvokeHelper(0x159, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayNoteIndicator(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x159, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetDisplayCommentIndicator()
{
	long result;
	InvokeHelper(0x4ac, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayCommentIndicator(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4ac, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetDisplayExcel4Menus()
{
	BOOL result;
	InvokeHelper(0x39f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayExcel4Menus(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x39f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayRecentFiles()
{
	BOOL result;
	InvokeHelper(0x39e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayRecentFiles(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x39e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayScrollBars()
{
	BOOL result;
	InvokeHelper(0x15a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayScrollBars(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x15a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetDisplayStatusBar()
{
	BOOL result;
	InvokeHelper(0x15b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetDisplayStatusBar(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x15b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::DoubleClick()
{
	InvokeHelper(0x15d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL _Application::GetEditDirectlyInCell()
{
	BOOL result;
	InvokeHelper(0x3a1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetEditDirectlyInCell(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x3a1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetEnableAutoComplete()
{
	BOOL result;
	InvokeHelper(0x49b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableAutoComplete(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x49b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetEnableCancelKey()
{
	long result;
	InvokeHelper(0x448, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableCancelKey(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x448, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetEnableSound()
{
	BOOL result;
	InvokeHelper(0x4ad, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableSound(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4ad, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT _Application::GetFileConverters(const VARIANT& Index1, const VARIANT& Index2)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x3a3, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index1, &Index2);
	return result;
}

LPDISPATCH _Application::GetFileSearch()
{
	LPDISPATCH result;
	InvokeHelper(0x4b0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetFileFind()
{
	LPDISPATCH result;
	InvokeHelper(0x4b1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

void _Application::FindFile()
{
	InvokeHelper(0x42c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL _Application::GetFixedDecimal()
{
	BOOL result;
	InvokeHelper(0x15f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetFixedDecimal(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x15f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetFixedDecimalPlaces()
{
	long result;
	InvokeHelper(0x160, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetFixedDecimalPlaces(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x160, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

VARIANT _Application::GetCustomListContents(long ListNum)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x312, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		ListNum);
	return result;
}

long _Application::GetCustomListNum(const VARIANT& ListArray)
{
	long result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x311, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		&ListArray);
	return result;
}

VARIANT _Application::GetOpenFilename(const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText, const VARIANT& MultiSelect)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x433, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&FileFilter, &FilterIndex, &Title, &ButtonText, &MultiSelect);
	return result;
}

VARIANT _Application::GetSaveAsFilename(const VARIANT& InitialFilename, const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x434, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		&InitialFilename, &FileFilter, &FilterIndex, &Title, &ButtonText);
	return result;
}

void _Application::Goto(const VARIANT& Reference, const VARIANT& Scroll)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x1db, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Reference, &Scroll);
}

double _Application::GetHeight()
{
	double result;
	InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetHeight(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

void _Application::Help(const VARIANT& HelpFile, const VARIANT& HelpContextID)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x162, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &HelpFile, &HelpContextID);
}

BOOL _Application::GetIgnoreRemoteRequests()
{
	BOOL result;
	InvokeHelper(0x164, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetIgnoreRemoteRequests(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x164, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

double _Application::InchesToPoints(double Inches)
{
	double result;
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x43f, DISPATCH_METHOD, VT_R8, (void*)&result, parms,
		Inches);
	return result;
}

VARIANT _Application::InputBox(LPCTSTR Prompt, const VARIANT& Title, const VARIANT& Default, const VARIANT& Left, const VARIANT& Top, const VARIANT& HelpFile, const VARIANT& HelpContextID, const VARIANT& Type)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x165, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms,
		Prompt, &Title, &Default, &Left, &Top, &HelpFile, &HelpContextID, &Type);
	return result;
}

BOOL _Application::GetInteractive()
{
	BOOL result;
	InvokeHelper(0x169, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetInteractive(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x169, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

VARIANT _Application::GetInternational(const VARIANT& Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x16a, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index);
	return result;
}

BOOL _Application::GetIteration()
{
	BOOL result;
	InvokeHelper(0x16b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetIteration(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x16b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

double _Application::GetLeft()
{
	double result;
	InvokeHelper(0x7f, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetLeft(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x7f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _Application::GetLibraryPath()
{
	CString result;
	InvokeHelper(0x16e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::MacroOptions(const VARIANT& Macro, const VARIANT& Description, const VARIANT& HasMenu, const VARIANT& MenuText, const VARIANT& HasShortcutKey, const VARIANT& ShortcutKey, const VARIANT& Category, const VARIANT& StatusBar, 
		const VARIANT& HelpContextID, const VARIANT& HelpFile)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x46f, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Macro, &Description, &HasMenu, &MenuText, &HasShortcutKey, &ShortcutKey, &Category, &StatusBar, &HelpContextID, &HelpFile);
}

void _Application::MailLogoff()
{
	InvokeHelper(0x3b1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::MailLogon(const VARIANT& Name, const VARIANT& Password, const VARIANT& DownloadNewMail)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x3af, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Name, &Password, &DownloadNewMail);
}

VARIANT _Application::GetMailSession()
{
	VARIANT result;
	InvokeHelper(0x3ae, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

long _Application::GetMailSystem()
{
	long result;
	InvokeHelper(0x3cb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetMathCoprocessorAvailable()
{
	BOOL result;
	InvokeHelper(0x16f, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

double _Application::GetMaxChange()
{
	double result;
	InvokeHelper(0x170, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetMaxChange(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x170, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _Application::GetMaxIterations()
{
	long result;
	InvokeHelper(0x171, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetMaxIterations(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x171, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetMemoryFree()
{
	long result;
	InvokeHelper(0x172, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetMemoryTotal()
{
	long result;
	InvokeHelper(0x173, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

long _Application::GetMemoryUsed()
{
	long result;
	InvokeHelper(0x174, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetMouseAvailable()
{
	BOOL result;
	InvokeHelper(0x175, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetMoveAfterReturn()
{
	BOOL result;
	InvokeHelper(0x176, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetMoveAfterReturn(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x176, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

long _Application::GetMoveAfterReturnDirection()
{
	long result;
	InvokeHelper(0x478, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetMoveAfterReturnDirection(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x478, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

LPDISPATCH _Application::GetRecentFiles()
{
	LPDISPATCH result;
	InvokeHelper(0x4b2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetName()
{
	CString result;
	InvokeHelper(0x6e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::NextLetter()
{
	LPDISPATCH result;
	InvokeHelper(0x3cc, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetNetworkTemplatesPath()
{
	CString result;
	InvokeHelper(0x184, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetODBCErrors()
{
	LPDISPATCH result;
	InvokeHelper(0x4b3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long _Application::GetODBCTimeout()
{
	long result;
	InvokeHelper(0x4b4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetODBCTimeout(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4b4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

void _Application::OnKey(LPCTSTR Key, const VARIANT& Procedure)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT;
	InvokeHelper(0x272, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Key, &Procedure);
}

void _Application::OnRepeat(LPCTSTR Text, LPCTSTR Procedure)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x301, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Text, Procedure);
}

void _Application::OnTime(const VARIANT& EarliestTime, LPCTSTR Procedure, const VARIANT& LatestTime, const VARIANT& Schedule)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_BSTR VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x270, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &EarliestTime, Procedure, &LatestTime, &Schedule);
}

void _Application::OnUndo(LPCTSTR Text, LPCTSTR Procedure)
{
	static BYTE parms[] =
		VTS_BSTR VTS_BSTR;
	InvokeHelper(0x302, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Text, Procedure);
}

CString _Application::GetOnWindow()
{
	CString result;
	InvokeHelper(0x26f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetOnWindow(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x26f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Application::GetOperatingSystem()
{
	CString result;
	InvokeHelper(0x177, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Application::GetOrganizationName()
{
	CString result;
	InvokeHelper(0x178, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Application::GetPath()
{
	CString result;
	InvokeHelper(0x123, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

CString _Application::GetPathSeparator()
{
	CString result;
	InvokeHelper(0x179, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

VARIANT _Application::GetPreviousSelections(const VARIANT& Index)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x17a, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index);
	return result;
}

BOOL _Application::GetPivotTableSelection()
{
	BOOL result;
	InvokeHelper(0x4b5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetPivotTableSelection(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4b5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetPromptForSummaryInfo()
{
	BOOL result;
	InvokeHelper(0x426, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetPromptForSummaryInfo(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x426, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::Quit()
{
	InvokeHelper(0x12e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void _Application::RecordMacro(const VARIANT& BasicCode, const VARIANT& XlmCode)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x305, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &BasicCode, &XlmCode);
}

BOOL _Application::GetRecordRelative()
{
	BOOL result;
	InvokeHelper(0x17b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _Application::GetReferenceStyle()
{
	long result;
	InvokeHelper(0x17c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetReferenceStyle(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x17c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

VARIANT _Application::GetRegisteredFunctions(const VARIANT& Index1, const VARIANT& Index2)
{
	VARIANT result;
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x307, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&Index1, &Index2);
	return result;
}

BOOL _Application::RegisterXLL(LPCTSTR Filename)
{
	BOOL result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
		Filename);
	return result;
}

void _Application::Repeat()
{
	InvokeHelper(0x12d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

BOOL _Application::GetRollZoom()
{
	BOOL result;
	InvokeHelper(0x4b6, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetRollZoom(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4b6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::SaveWorkspace(const VARIANT& Filename)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xd4, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Filename);
}

BOOL _Application::GetScreenUpdating()
{
	BOOL result;
	InvokeHelper(0x17e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetScreenUpdating(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x17e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::SetDefaultChart(const VARIANT& FormatName, const VARIANT& Gallery)
{
	static BYTE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0xdb, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &FormatName, &Gallery);
}

long _Application::GetSheetsInNewWorkbook()
{
	long result;
	InvokeHelper(0x3e1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetSheetsInNewWorkbook(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x3e1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetShowChartTipNames()
{
	BOOL result;
	InvokeHelper(0x4b7, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetShowChartTipNames(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4b7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _Application::GetShowChartTipValues()
{
	BOOL result;
	InvokeHelper(0x4b8, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetShowChartTipValues(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4b8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetStandardFont()
{
	CString result;
	InvokeHelper(0x39c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetStandardFont(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x39c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

double _Application::GetStandardFontSize()
{
	double result;
	InvokeHelper(0x39d, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetStandardFontSize(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x39d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

CString _Application::GetStartupPath()
{
	CString result;
	InvokeHelper(0x181, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

VARIANT _Application::GetStatusBar()
{
	VARIANT result;
	InvokeHelper(0x182, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
	return result;
}

void _Application::SetStatusBar(const VARIANT& newValue)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x182, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 &newValue);
}

CString _Application::GetTemplatesPath()
{
	CString result;
	InvokeHelper(0x17d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetShowToolTips()
{
	BOOL result;
	InvokeHelper(0x183, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetShowToolTips(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x183, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

double _Application::GetTop()
{
	double result;
	InvokeHelper(0x7e, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetTop(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x7e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _Application::GetDefaultSaveFormat()
{
	long result;
	InvokeHelper(0x4b9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultSaveFormat(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4b9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _Application::GetTransitionMenuKey()
{
	CString result;
	InvokeHelper(0x136, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetTransitionMenuKey(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x136, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _Application::GetTransitionMenuKeyAction()
{
	long result;
	InvokeHelper(0x137, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetTransitionMenuKeyAction(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x137, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetTransitionNavigKeys()
{
	BOOL result;
	InvokeHelper(0x138, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetTransitionNavigKeys(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x138, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::Undo()
{
	InvokeHelper(0x12f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

double _Application::GetUsableHeight()
{
	double result;
	InvokeHelper(0x185, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

double _Application::GetUsableWidth()
{
	double result;
	InvokeHelper(0x186, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetUserControl()
{
	BOOL result;
	InvokeHelper(0x4ba, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetUserControl(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4ba, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _Application::GetUserName_()
{
	CString result;
	InvokeHelper(0x187, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _Application::SetUserName(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x187, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _Application::GetValue()
{
	CString result;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

LPDISPATCH _Application::GetVbe()
{
	LPDISPATCH result;
	InvokeHelper(0x4bb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

CString _Application::GetVersion()
{
	CString result;
	InvokeHelper(0x188, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

BOOL _Application::GetVisible()
{
	BOOL result;
	InvokeHelper(0x22e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetVisible(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x22e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _Application::Volatile(const VARIANT& Volatile)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x314, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Volatile);
}

void _Application::Wait(const VARIANT& Time)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x189, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Time);
}

double _Application::GetWidth()
{
	double result;
	InvokeHelper(0x7a, DISPATCH_PROPERTYGET, VT_R8, (void*)&result, NULL);
	return result;
}

void _Application::SetWidth(double newValue)
{
	static BYTE parms[] =
		VTS_R8;
	InvokeHelper(0x7a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

BOOL _Application::GetWindowsForPens()
{
	BOOL result;
	InvokeHelper(0x18b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

long _Application::GetWindowState()
{
	long result;
	InvokeHelper(0x18c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetWindowState(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x18c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetUILanguage()
{
	long result;
	InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetUILanguage(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetDefaultSheetDirection()
{
	long result;
	InvokeHelper(0xe5, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetDefaultSheetDirection(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetCursorMovement()
{
	long result;
	InvokeHelper(0xe8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetCursorMovement(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _Application::GetControlCharacters()
{
	long result;
	InvokeHelper(0xe9, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _Application::SetControlCharacters(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0xe9, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _Application::GetEnableEvents()
{
	BOOL result;
	InvokeHelper(0x4bc, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _Application::SetEnableEvents(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4bc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}


/////////////////////////////////////////////////////////////////////////////
// Workbooks properties

/////////////////////////////////////////////////////////////////////////////
// Workbooks operations

LPDISPATCH Workbooks::GetApplication()
{
	LPDISPATCH result;
	InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

long Workbooks::GetCreator()
{
	long result;
	InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Workbooks::GetParent()
{
	LPDISPATCH result;
	InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
	return result;
}

LPDISPATCH Workbooks::Add(const VARIANT& Template)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		&Template);
	return result;
}

void Workbooks::Close()
{
	InvokeHelper(0x115, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

long Workbooks::GetCount()
{
	long result;
	InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

LPDISPATCH Workbooks::GetItem(const VARIANT& Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xaa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		&Index);
	return result;
}

LPUNKNOWN Workbooks::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

LPDISPATCH Workbooks::Open(LPCTSTR Filename, const VARIANT& UpdateLinks, const VARIANT& ReadOnly, const VARIANT& Format, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& IgnoreReadOnlyRecommended, const VARIANT& Origin, 
		const VARIANT& Delimiter, const VARIANT& Editable, const VARIANT& Notify, const VARIANT& Converter, const VARIANT& AddToMru)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x2aa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Filename, &UpdateLinks, &ReadOnly, &Format, &Password, &WriteResPassword, &IgnoreReadOnlyRecommended, &Origin, &Delimiter, &Editable, &Notify, &Converter, &AddToMru);
	return result;
}

LPDISPATCH Workbooks::Open(LPCTSTR Filename)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2aa, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms,
		Filename);
	return result;
}

void Workbooks::OpenText(LPCTSTR Filename, const VARIANT& Origin, const VARIANT& StartRow, const VARIANT& DataType, long TextQualifier, const VARIANT& ConsecutiveDelimiter, const VARIANT& Tab, const VARIANT& Semicolon, const VARIANT& Comma, 
		const VARIANT& Space, const VARIANT& Other, const VARIANT& OtherChar, const VARIANT& FieldInfo, const VARIANT& TextVisualLayout)
{
	static BYTE parms[] =
		VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_I4 VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x2ab, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 Filename, &Origin, &StartRow, &DataType, TextQualifier, &ConsecutiveDelimiter, &Tab, &Semicolon, &Comma, &Space, &Other, &OtherChar, &FieldInfo, &TextVisualLayout);
}

LPDISPATCH Workbooks::Get_Default(const VARIANT& Index)
{
	LPDISPATCH result;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms,
		&Index);
	return result;
}
