//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Main class
// UTES.h : main header file for the DSS/UTES application
//
//---------------------------------------------------------------------------
//#define DEMOVER
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "excel8.h"
#include "fmod.h"
#include "Protection.h"

#define CRIT_LIM 4

/////////////////////////////////////////////////////////////////////////////
// CUTESApp:
// See UTES.cpp for the implementation of this class
//

class CUTESApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CUTESApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTESApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUTESApp)
	afx_msg void OnAppAbout();
	afx_msg void OnBUTTONEXCEl();
	afx_msg void OnMenuitemSetup();
	afx_msg void OnUpdateFileMruFile1(CCmdUI* pCmdUI);
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	static TCHAR szCompanyName[16]; //=_T("MAI_DSS");
	static TCHAR szInProcServer[64]; //=_T("CCrit.dll");
	_Application m_app;
	IFmod m_fmod;
	Workbooks m_workbooks;
	CString m_Path;
	CProtection m_Protection;
};

/////////////////////////////////////////////////////////////////////////////
