//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Defines the class behaviors for the application.
// UTES.cpp  
//
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"

#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
//#include "CritDialog.h"
//#include "Criterion.h"
//#include "CGroup.h"

#include "MainFrm.h"
#include "UTESDoc.h"
#include "DssPref.h"
#include "UTESView.h"
#include "Splash.h"
#include "OptionsDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUTESApp

BEGIN_MESSAGE_MAP(CUTESApp, CWinApp)
	//{{AFX_MSG_MAP(CUTESApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_BUTTON_EXCEl, OnBUTTONEXCEl)
	ON_COMMAND(ID_MENUITEM_SETUP, OnMenuitemSetup)
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_FILE1, OnUpdateFileMruFile1)
	ON_COMMAND(ID_HELP, OnHelp)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

TCHAR CUTESApp::szCompanyName[16]=_T("MAI_DSS");
TCHAR CUTESApp::szInProcServer[64]=_T("CCrit.dll");

/////////////////////////////////////////////////////////////////////////////
// CUTESApp construction

CUTESApp::CUTESApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CUTESApp object

CUTESApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CUTESApp initialization

BOOL CUTESApp::InitInstance()
{
	
	// CG: The following block was added by the Splash Screen component.
	{
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);

		CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);
	}
	
	if (!AfxOleInit())
	{
		AfxMessageBox("IDP_OLE_INIT_FALED");
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	AfxEnableControlContainer();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

/*	if (RunAutomated())
		AfxMessageBox("ЗАПУСК ЧЕРЕЗ OLE");
	else
		AfxMessageBox("ЗАПУСК НЕ ЧЕРЕЗ OLE");*/
	

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CUTESDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CUTESView));
	AddDocTemplate(pDocTemplate);


// Register Application
	TCHAR* szSection;
	TCHAR* szName;
	TCHAR* szOut;
	CString Buffer;
	SetRegistryKey(szCompanyName);

	LoadStdProfileSettings(3);  // Load standard INI file options (including MRU)

	szSection=_T("Extentions");
	szName=_T("InProcServer");
	Buffer=GetProfileString(szSection,szName);
	if (Buffer.IsEmpty())
	{
		szOut=szInProcServer;
		WriteProfileString(szSection,szName,szOut);
	}
	szName=_T("CSLID");
	Buffer=GetProfileString(szSection,szName);
	if (Buffer.IsEmpty())
	{
		szOut=_T("{C8870361-7B2A-11D2-B7A1-A7B00D604327}");
		WriteProfileString(szSection,szName,szOut);
		_tcscpy(szInProcServer,szOut);
	}
	else
		_tcscpy(szInProcServer,Buffer);

    szName=_T("XLS module");
	Buffer=GetProfileString(szSection,szName);
	if (Buffer.IsEmpty())
	{
		LPTSTR c=m_Path.GetBuffer(_MAX_PATH);
		GetCurrentDirectory(_MAX_PATH, c);
		m_Path.ReleaseBuffer();
		//m_Path="c:\\dss";
		WriteProfileString(szSection,szName,m_Path);
	}
	else m_Path=Buffer;

	// Enable DDE Execute open
	EnableShellOpen();
	//RegisterShellFileTypes(TRUE);
	//COleObjectFactory::UpdateRegistryAll();
	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	COleTemplateServer::RegisterAll();
	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

#ifndef DEMOVER
	m_Protection.LoadInfo();
	int i=0;
	if (i=m_Protection.CheckStatus(1))
	{
		if (i==-2) return FALSE;
		OnMenuitemSetup();
		m_Protection.LoadInfo();
		if (m_Protection.CheckStatus(1))
		{
			AfxMessageBox("Ваша копия программы не зарегистрирована");
			return FALSE;
		}
	}
#endif

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_VER;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_VER = _T("");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_STATIC_VER, m_VER);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CUTESApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CUTESApp commands

BOOL CUTESApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
	if (CSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

void CUTESApp::OnBUTTONEXCEl() 
{
   LPDISPATCH pDisp;
   LPUNKNOWN pUnk;
   CLSID clsid;
   if (m_app.m_lpDispatch == NULL)
   {
	  TRACE("Entering CEx24dView::OnExcelLoad\n");
	  BeginWaitCursor();
      ::CLSIDFromProgID(L"Excel.Application", &clsid); // from registry
	  if(::GetActiveObject(clsid, NULL, &pUnk) == S_OK) {
// if(::GetActiveObject(excelClsid, NULL, &pUnk) == S_OK) {
		TRACE("attaching\n");
		VERIFY(pUnk->QueryInterface(IID_IDispatch,
            (void**) &pDisp) == S_OK);
		m_app.AttachDispatch(pDisp);
		pUnk->Release();
	  } 
      else {
		TRACE("creating\n");
		VERIFY(m_app.CreateDispatch("Excel.Application") == TRUE);
//		VERIFY(m_app.CreateDispatch(excelClsid) == TRUE);
	  }
	  EndWaitCursor();
   }

   LPDISPATCH pWorkbooks=NULL;
    
   /*CWnd* pWnd = CWnd::FindWindow("XLMAIN", NULL);
   if (pWnd != NULL) {
     TRACE("Excel window found\n");
     pWnd->ShowWindow(SW_SHOW);   //NORMAL);
	 pWnd->UpdateWindow();
     pWnd->BringWindowToTop();
     //pWnd->RedrawWindow(NULL,NULL,RDW_INVALIDATE);
   }*/
   m_app.SetVisible(TRUE);
   pWorkbooks = m_app.GetWorkbooks();
   if (pWorkbooks==NULL) return;
   m_workbooks.AttachDispatch(pWorkbooks);
   m_workbooks.Open(m_Path+"\\"+"dss_slover.xls");
   m_app.SetDisplayFullScreen(TRUE);
   m_app.SetDisplayFullScreen(FALSE);
}

void CUTESApp::OnMenuitemSetup() 
{
	// TODO: Add your command handler code here
	COptionsDlg dlg;
	dlg.m_Slover=m_Path;
	if (dlg.DoModal()==IDOK)
	{
		TCHAR* szSection;
		TCHAR* szName;
		CString Buffer;
		szSection=_T("Extentions");
	    szName=_T("XLS module");
		m_Path=dlg.m_Slover;
		WriteProfileString(szSection,szName,m_Path);
		m_Protection.m_ProgCode=dlg.m_c;
		m_Protection.SetRegValue(HKEY_CURRENT_USER,
			"Software\\MAI_DSS\\DSS-UTES\\Extentions",
			"ProgCode", m_Protection.m_ProgCode);
	}
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
#ifdef DEMOVER
	m_VER="версия 2.0f (демо)";
#else
	m_VER="версия 2.0f       ";
#endif
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUTESApp::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	//pCmdUI->Enable(GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)));
	CWinApp::OnUpdateRecentFileMenu(pCmdUI); 

	POSITION pos=GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = (CDocTemplate*) GetNextDocTemplate(pos);
	pos=pTemplate->GetFirstDocPosition();
	CDocument* pD=pTemplate->GetNextDoc(pos);
	pos=pD->GetFirstViewPosition();
	if (!pD->GetNextView(pos)->IsKindOf(RUNTIME_CLASS(CUTESView)))
	{
		pCmdUI->m_pMenu->EnableMenuItem(ID_FILE_MRU_FILE1,MF_DISABLED | MF_GRAYED);
		pCmdUI->m_pMenu->EnableMenuItem(ID_FILE_MRU_FILE2,MF_DISABLED | MF_GRAYED); 
		pCmdUI->m_pMenu->EnableMenuItem(ID_FILE_MRU_FILE3,MF_DISABLED | MF_GRAYED); 
	}
}





void CUTESApp::OnHelp() 
{
	// TODO: Add your command handler code here
	WinHelp(0,HELP_FINDER);	
}

