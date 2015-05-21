//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Main frame
// MainFrm.cpp : implementation of the CMainFrame class
//
//---------------------------------------------------------------------------


#include "stdafx.h"
#include "UTES.h"

#include "MainFrm.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
//#include "CritDialog.h"
//#include "Criterion.h"
//#include "CGroup.h"
// #include "c:\Lab\TestCross\NewGrid.h"
#include "UTESDoc.h"
#include "DssPref.h"
#include "UTESView.h"
//#include "PrefView.h"
#include "Splash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CRITERIA, OnViewCriteria)
	ON_UPDATE_COMMAND_UI(ID_VIEW_CRITERIA, OnUpdateViewCriteria)
	ON_COMMAND(ID_VIEW_PREF, OnViewPref)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PREF, OnUpdateViewPref)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_UPDATE_COMMAND_UI(ID_FILE_OPEN, OnUpdateFileOpen)
	ON_COMMAND(ID_BUTTON_CHANGE_VIEW, OnButtonChangeView)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_CHANGE_VIEW, OnUpdateButtonChangeView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips or a resizeable toolbar
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	/*cs.style=cs.style^WS_MAXIMIZEBOX^WS_THICKFRAME;
	cs.cy=420;
	cs.cx=510;
	cs.x=20;
	cs.y=10;*/
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnViewCriteria() 
{
	CView* pOldActiveView=GetActiveView();
	CView* pNewActiveView=(CView*)GetDlgItem(CRITERIA);
	//if (pNewActiveView==NULL)
	//{
		pNewActiveView=(CView*)new CUTESView;
		CCreateContext context;
		context.m_pCurrentDoc=pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, CRITERIA, &context);
		pNewActiveView->OnInitialUpdate();
	//}
	SetActiveView(pNewActiveView);
	pNewActiveView->ShowWindow(SW_SHOW);
	pOldActiveView->ShowWindow(SW_HIDE);
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
	pOldActiveView->DestroyWindow();
}

void CMainFrame::OnUpdateViewCriteria(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)));
}

void CMainFrame::OnViewPref() 
{
	CUTESView* pV=(CUTESView*)GetActiveView();
	CView* pNewV;
	int n = pV->m_CritList.GetItemCount();
	int i=0;
	UINT flag;
	do
		flag=pV->m_CritList.GetItemState(i++,LVIS_SELECTED);
	while ((i<n)&&(!flag));
	if (flag)
	{
		CString Buff=pV->m_CritList.GetItemText(--i,0);
		pV->GetCritPos(Buff);
		CExponent *pE;
		POSITION pos = pV->GetDocument()->m_Exp.GetHeadPosition();
		while ((pos!=NULL)&&(flag))
		{
			pE = (CExponent*) pV->GetDocument()->m_Exp.GetNext(pos);
			if (Buff == pE->GetName())
			{
				pos=NULL;
				if (pE->GetType()==EXPONENT_GROUP)
				{
					if (pE->m_Method==NULL)
					{
						AfxMessageBox("Метод скаляризации не задан");
						return;
					}
					if (!pE->m_Method->IsValid())
					{
						AfxMessageBox("Ошибки задания метода скаляризации\r\n"+pE->m_Method->m_err_msg);
						return;
					}
					pNewV=pE->m_Method->CreateEditView();
					if (pNewV==NULL)
					{
						//AfxMessageBox("Метод скаляризации не требует ввода предпочтений");
						//или произошел вызов по OLE
						return;
					}
				}
				else 
				{
					AfxMessageBox("Показатель не агрегирующий");
					return;
				}

			}
		}
	}
	else 
	{
		AfxMessageBox("Показатель не выбран");
		return;
	}

	CCreateContext context;
	context.m_pCurrentDoc=pV->GetDocument();
	pNewV->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, PREF, &context);
	pNewV->OnInitialUpdate();
	
	SetActiveView(pNewV);
	pNewV->ShowWindow(SW_SHOW);
	pV->ShowWindow(SW_HIDE);
	pV->SetDlgCtrlID(pV->GetRuntimeClass()==
		RUNTIME_CLASS(CUTESView) ? CRITERIA : PREF);
	pNewV->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
	pV->DestroyWindow();
}

void CMainFrame::OnUpdateViewPref(CCmdUI* pCmdUI) 
{
	UINT flag=FALSE;
	
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)))
	{
		CUTESView* pV=(CUTESView*)GetActiveView();
		/*int n = pV->m_CritList.GetItemCount();
		int i=0;
		do
			flag=pV->m_CritList.GetItemState(i++,LVIS_SELECTED);
		while ((i<n)&&(!flag));*/
		flag=pV->IsSelect(1);
	}

	pCmdUI->Enable(flag);
}

void CMainFrame::SwitchToView(eView nView)
{
	CView* pOldActiveView=GetActiveView();
	CView* pNewActiveView=(CView*)GetDlgItem(nView);
	if (pNewActiveView==NULL)
	{
		switch (nView)
		{
		case CRITERIA:
			pNewActiveView=(CView*)new CUTESView;
			break;
		case PREF:
//			pNewActiveView=(CView*)new CPrefView;
			break;
		}
		CCreateContext context;
		context.m_pCurrentDoc=pOldActiveView->GetDocument();
		pNewActiveView->Create(NULL, NULL, 0L, CFrameWnd::rectDefault, this, nView, &context);
		pNewActiveView->OnInitialUpdate();
	}
	else if (nView==PREF) pNewActiveView->OnInitialUpdate();
	SetActiveView(pNewActiveView);
	pNewActiveView->ShowWindow(SW_SHOW);
	pOldActiveView->ShowWindow(SW_HIDE);
	pOldActiveView->SetDlgCtrlID(pOldActiveView->GetRuntimeClass()==
		RUNTIME_CLASS(CUTESView) ? CRITERIA : PREF);
	pNewActiveView->SetDlgCtrlID(AFX_IDW_PANE_FIRST);
	RecalcLayout();
}



void CMainFrame::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)));
}



void CMainFrame::OnUpdateFileOpen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)));
}

void CMainFrame::OnButtonChangeView() 
{
	// TODO: Add your command handler code here
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)))
	{
		OnViewPref();
	}
	else 
	{
		OnViewCriteria();
	}
}

void CMainFrame::OnUpdateButtonChangeView(CCmdUI* pCmdUI) 
{
	UINT flag=TRUE;
	if (GetActiveView()->IsKindOf(RUNTIME_CLASS(CUTESView)))
	{
		CUTESView* pV=(CUTESView*)GetActiveView();
		/*int n = pV->m_CritList.GetItemCount();
		int i=0;
		do
			flag=pV->m_CritList.GetItemState(i++,LVIS_SELECTED);
		while ((i<n)&&(!flag));*/
		flag=pV->IsSelect(1);
	}
	pCmdUI->Enable(flag);
}

