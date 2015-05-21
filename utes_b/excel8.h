// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _Application wrapper class

class _Application : public COleDispatchDriver
{
public:
	_Application() {}		// Calls COleDispatchDriver default constructor
	_Application(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_Application(const _Application& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH GetActiveCell();
	LPDISPATCH GetActiveChart();
	CString GetActivePrinter();
	void SetActivePrinter(LPCTSTR lpszNewValue);
	LPDISPATCH GetActiveSheet();
	LPDISPATCH GetActiveWindow();
	LPDISPATCH GetActiveWorkbook();
	LPDISPATCH GetAddIns();
	LPDISPATCH GetAssistant();
	void Calculate();
	LPDISPATCH GetCells();
	LPDISPATCH GetCharts();
	LPDISPATCH GetColumns();
	LPDISPATCH GetCommandBars();
	long GetDDEAppReturnCode();
	void DDEExecute(long Channel, LPCTSTR String);
	long DDEInitiate(LPCTSTR App, LPCTSTR Topic);
	void DDEPoke(long Channel, const VARIANT& Item, const VARIANT& Data);
	VARIANT DDERequest(long Channel, LPCTSTR Item);
	void DDETerminate(long Channel);
	VARIANT Evaluate(const VARIANT& Name);
	VARIANT _Evaluate(const VARIANT& Name);
	VARIANT ExecuteExcel4Macro(LPCTSTR String);
	LPDISPATCH Intersect(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, 
		const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, 
		const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30);
	LPDISPATCH GetNames();
	LPDISPATCH GetRange(const VARIANT& Cell1, const VARIANT& Cell2);
	LPDISPATCH GetRows();
	VARIANT Run(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30);
	VARIANT _Run2(const VARIANT& Macro, const VARIANT& Arg1, const VARIANT& Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, 
		const VARIANT& Arg10, const VARIANT& Arg11, const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, 
		const VARIANT& Arg20, const VARIANT& Arg21, const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, 
		const VARIANT& Arg30);
	LPDISPATCH GetSelection();
	void SendKeys(const VARIANT& Keys, const VARIANT& Wait);
	LPDISPATCH GetSheets();
	LPDISPATCH GetThisWorkbook();
	LPDISPATCH Union(LPDISPATCH Arg1, LPDISPATCH Arg2, const VARIANT& Arg3, const VARIANT& Arg4, const VARIANT& Arg5, const VARIANT& Arg6, const VARIANT& Arg7, const VARIANT& Arg8, const VARIANT& Arg9, const VARIANT& Arg10, const VARIANT& Arg11, 
		const VARIANT& Arg12, const VARIANT& Arg13, const VARIANT& Arg14, const VARIANT& Arg15, const VARIANT& Arg16, const VARIANT& Arg17, const VARIANT& Arg18, const VARIANT& Arg19, const VARIANT& Arg20, const VARIANT& Arg21, 
		const VARIANT& Arg22, const VARIANT& Arg23, const VARIANT& Arg24, const VARIANT& Arg25, const VARIANT& Arg26, const VARIANT& Arg27, const VARIANT& Arg28, const VARIANT& Arg29, const VARIANT& Arg30);
	LPDISPATCH GetWindows();
	LPDISPATCH GetWorkbooks();
	LPDISPATCH GetWorksheetFunction();
	LPDISPATCH GetWorksheets();
	LPDISPATCH GetExcel4IntlMacroSheets();
	LPDISPATCH GetExcel4MacroSheets();
	void ActivateMicrosoftApp(long Index);
	void AddChartAutoFormat(const VARIANT& Chart, LPCTSTR Name, const VARIANT& Description);
	void AddCustomList(const VARIANT& ListArray, const VARIANT& ByRow);
	BOOL GetAlertBeforeOverwriting();
	void SetAlertBeforeOverwriting(BOOL bNewValue);
	CString GetAltStartupPath();
	void SetAltStartupPath(LPCTSTR lpszNewValue);
	BOOL GetAskToUpdateLinks();
	void SetAskToUpdateLinks(BOOL bNewValue);
	BOOL GetEnableAnimations();
	void SetEnableAnimations(BOOL bNewValue);
	LPDISPATCH GetAutoCorrect();
	long GetBuild();
	BOOL GetCalculateBeforeSave();
	void SetCalculateBeforeSave(BOOL bNewValue);
	long GetCalculation();
	void SetCalculation(long nNewValue);
	VARIANT GetCaller(const VARIANT& Index);
	BOOL GetCanPlaySounds();
	BOOL GetCanRecordSounds();
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	BOOL GetCellDragAndDrop();
	void SetCellDragAndDrop(BOOL bNewValue);
	double CentimetersToPoints(double Centimeters);
	BOOL CheckSpelling(LPCTSTR Word, const VARIANT& CustomDictionary, const VARIANT& IgnoreUppercase);
	VARIANT GetClipboardFormats(const VARIANT& Index);
	BOOL GetDisplayClipboardWindow();
	void SetDisplayClipboardWindow(BOOL bNewValue);
	long GetCommandUnderlines();
	void SetCommandUnderlines(long nNewValue);
	BOOL GetConstrainNumeric();
	void SetConstrainNumeric(BOOL bNewValue);
	VARIANT ConvertFormula(const VARIANT& Formula, long FromReferenceStyle, const VARIANT& ToReferenceStyle, const VARIANT& ToAbsolute, const VARIANT& RelativeTo);
	BOOL GetCopyObjectsWithCells();
	void SetCopyObjectsWithCells(BOOL bNewValue);
	long GetCursor();
	void SetCursor(long nNewValue);
	long GetCustomListCount();
	long GetCutCopyMode();
	void SetCutCopyMode(long nNewValue);
	long GetDataEntryMode();
	void SetDataEntryMode(long nNewValue);
	CString Get_Default();
	CString GetDefaultFilePath();
	void SetDefaultFilePath(LPCTSTR lpszNewValue);
	void DeleteChartAutoFormat(LPCTSTR Name);
	void DeleteCustomList(long ListNum);
	LPDISPATCH GetDialogs();
	BOOL GetDisplayAlerts();
	void SetDisplayAlerts(BOOL bNewValue);
	BOOL GetDisplayFormulaBar();
	void SetDisplayFormulaBar(BOOL bNewValue);
	BOOL GetDisplayFullScreen();
	void SetDisplayFullScreen(BOOL bNewValue);
	BOOL GetDisplayNoteIndicator();
	void SetDisplayNoteIndicator(BOOL bNewValue);
	long GetDisplayCommentIndicator();
	void SetDisplayCommentIndicator(long nNewValue);
	BOOL GetDisplayExcel4Menus();
	void SetDisplayExcel4Menus(BOOL bNewValue);
	BOOL GetDisplayRecentFiles();
	void SetDisplayRecentFiles(BOOL bNewValue);
	BOOL GetDisplayScrollBars();
	void SetDisplayScrollBars(BOOL bNewValue);
	BOOL GetDisplayStatusBar();
	void SetDisplayStatusBar(BOOL bNewValue);
	void DoubleClick();
	BOOL GetEditDirectlyInCell();
	void SetEditDirectlyInCell(BOOL bNewValue);
	BOOL GetEnableAutoComplete();
	void SetEnableAutoComplete(BOOL bNewValue);
	long GetEnableCancelKey();
	void SetEnableCancelKey(long nNewValue);
	BOOL GetEnableSound();
	void SetEnableSound(BOOL bNewValue);
	VARIANT GetFileConverters(const VARIANT& Index1, const VARIANT& Index2);
	LPDISPATCH GetFileSearch();
	LPDISPATCH GetFileFind();
	void FindFile();
	BOOL GetFixedDecimal();
	void SetFixedDecimal(BOOL bNewValue);
	long GetFixedDecimalPlaces();
	void SetFixedDecimalPlaces(long nNewValue);
	VARIANT GetCustomListContents(long ListNum);
	long GetCustomListNum(const VARIANT& ListArray);
	VARIANT GetOpenFilename(const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText, const VARIANT& MultiSelect);
	VARIANT GetSaveAsFilename(const VARIANT& InitialFilename, const VARIANT& FileFilter, const VARIANT& FilterIndex, const VARIANT& Title, const VARIANT& ButtonText);
	void Goto(const VARIANT& Reference, const VARIANT& Scroll);
	double GetHeight();
	void SetHeight(double newValue);
	void Help(const VARIANT& HelpFile, const VARIANT& HelpContextID);
	BOOL GetIgnoreRemoteRequests();
	void SetIgnoreRemoteRequests(BOOL bNewValue);
	double InchesToPoints(double Inches);
	VARIANT InputBox(LPCTSTR Prompt, const VARIANT& Title, const VARIANT& Default, const VARIANT& Left, const VARIANT& Top, const VARIANT& HelpFile, const VARIANT& HelpContextID, const VARIANT& Type);
	BOOL GetInteractive();
	void SetInteractive(BOOL bNewValue);
	VARIANT GetInternational(const VARIANT& Index);
	BOOL GetIteration();
	void SetIteration(BOOL bNewValue);
	double GetLeft();
	void SetLeft(double newValue);
	CString GetLibraryPath();
	void MacroOptions(const VARIANT& Macro, const VARIANT& Description, const VARIANT& HasMenu, const VARIANT& MenuText, const VARIANT& HasShortcutKey, const VARIANT& ShortcutKey, const VARIANT& Category, const VARIANT& StatusBar, 
		const VARIANT& HelpContextID, const VARIANT& HelpFile);
	void MailLogoff();
	void MailLogon(const VARIANT& Name, const VARIANT& Password, const VARIANT& DownloadNewMail);
	VARIANT GetMailSession();
	long GetMailSystem();
	BOOL GetMathCoprocessorAvailable();
	double GetMaxChange();
	void SetMaxChange(double newValue);
	long GetMaxIterations();
	void SetMaxIterations(long nNewValue);
	long GetMemoryFree();
	long GetMemoryTotal();
	long GetMemoryUsed();
	BOOL GetMouseAvailable();
	BOOL GetMoveAfterReturn();
	void SetMoveAfterReturn(BOOL bNewValue);
	long GetMoveAfterReturnDirection();
	void SetMoveAfterReturnDirection(long nNewValue);
	LPDISPATCH GetRecentFiles();
	CString GetName();
	LPDISPATCH NextLetter();
	CString GetNetworkTemplatesPath();
	LPDISPATCH GetODBCErrors();
	long GetODBCTimeout();
	void SetODBCTimeout(long nNewValue);
	void OnKey(LPCTSTR Key, const VARIANT& Procedure);
	void OnRepeat(LPCTSTR Text, LPCTSTR Procedure);
	void OnTime(const VARIANT& EarliestTime, LPCTSTR Procedure, const VARIANT& LatestTime, const VARIANT& Schedule);
	void OnUndo(LPCTSTR Text, LPCTSTR Procedure);
	CString GetOnWindow();
	void SetOnWindow(LPCTSTR lpszNewValue);
	CString GetOperatingSystem();
	CString GetOrganizationName();
	CString GetPath();
	CString GetPathSeparator();
	VARIANT GetPreviousSelections(const VARIANT& Index);
	BOOL GetPivotTableSelection();
	void SetPivotTableSelection(BOOL bNewValue);
	BOOL GetPromptForSummaryInfo();
	void SetPromptForSummaryInfo(BOOL bNewValue);
	void Quit();
	void RecordMacro(const VARIANT& BasicCode, const VARIANT& XlmCode);
	BOOL GetRecordRelative();
	long GetReferenceStyle();
	void SetReferenceStyle(long nNewValue);
	VARIANT GetRegisteredFunctions(const VARIANT& Index1, const VARIANT& Index2);
	BOOL RegisterXLL(LPCTSTR Filename);
	void Repeat();
	BOOL GetRollZoom();
	void SetRollZoom(BOOL bNewValue);
	void SaveWorkspace(const VARIANT& Filename);
	BOOL GetScreenUpdating();
	void SetScreenUpdating(BOOL bNewValue);
	void SetDefaultChart(const VARIANT& FormatName, const VARIANT& Gallery);
	long GetSheetsInNewWorkbook();
	void SetSheetsInNewWorkbook(long nNewValue);
	BOOL GetShowChartTipNames();
	void SetShowChartTipNames(BOOL bNewValue);
	BOOL GetShowChartTipValues();
	void SetShowChartTipValues(BOOL bNewValue);
	CString GetStandardFont();
	void SetStandardFont(LPCTSTR lpszNewValue);
	double GetStandardFontSize();
	void SetStandardFontSize(double newValue);
	CString GetStartupPath();
	VARIANT GetStatusBar();
	void SetStatusBar(const VARIANT& newValue);
	CString GetTemplatesPath();
	BOOL GetShowToolTips();
	void SetShowToolTips(BOOL bNewValue);
	double GetTop();
	void SetTop(double newValue);
	long GetDefaultSaveFormat();
	void SetDefaultSaveFormat(long nNewValue);
	CString GetTransitionMenuKey();
	void SetTransitionMenuKey(LPCTSTR lpszNewValue);
	long GetTransitionMenuKeyAction();
	void SetTransitionMenuKeyAction(long nNewValue);
	BOOL GetTransitionNavigKeys();
	void SetTransitionNavigKeys(BOOL bNewValue);
	void Undo();
	double GetUsableHeight();
	double GetUsableWidth();
	BOOL GetUserControl();
	void SetUserControl(BOOL bNewValue);
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	CString GetValue();
	LPDISPATCH GetVbe();
	CString GetVersion();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	void Volatile(const VARIANT& Volatile);
	void Wait(const VARIANT& Time);
	double GetWidth();
	void SetWidth(double newValue);
	BOOL GetWindowsForPens();
	long GetWindowState();
	void SetWindowState(long nNewValue);
	long GetUILanguage();
	void SetUILanguage(long nNewValue);
	long GetDefaultSheetDirection();
	void SetDefaultSheetDirection(long nNewValue);
	long GetCursorMovement();
	void SetCursorMovement(long nNewValue);
	long GetControlCharacters();
	void SetControlCharacters(long nNewValue);
	BOOL GetEnableEvents();
	void SetEnableEvents(BOOL bNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// Workbooks wrapper class

class Workbooks : public COleDispatchDriver
{
public:
	Workbooks() {}		// Calls COleDispatchDriver default constructor
	Workbooks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Workbooks(const Workbooks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetApplication();
	long GetCreator();
	LPDISPATCH GetParent();
	LPDISPATCH Add(const VARIANT& Template);
	void Close();
	long GetCount();
	LPDISPATCH GetItem(const VARIANT& Index);
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH Open(LPCTSTR Filename, const VARIANT& UpdateLinks, const VARIANT& ReadOnly, const VARIANT& Format, const VARIANT& Password, const VARIANT& WriteResPassword, const VARIANT& IgnoreReadOnlyRecommended, const VARIANT& Origin, 
		const VARIANT& Delimiter, const VARIANT& Editable, const VARIANT& Notify, const VARIANT& Converter, const VARIANT& AddToMru);
	LPDISPATCH Open(LPCTSTR Filename);
	void OpenText(LPCTSTR Filename, const VARIANT& Origin, const VARIANT& StartRow, const VARIANT& DataType, long TextQualifier, const VARIANT& ConsecutiveDelimiter, const VARIANT& Tab, const VARIANT& Semicolon, const VARIANT& Comma, 
		const VARIANT& Space, const VARIANT& Other, const VARIANT& OtherChar, const VARIANT& FieldInfo, const VARIANT& TextVisualLayout);
	LPDISPATCH Get_Default(const VARIANT& Index);
};
