//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Edit class for pref. method Ideal Point
// PointView.cpp : implementation file
//
//---------------------------------------------------------------------------


#include "stdafx.h"
#include "sys_add_ins.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "UTESDoc.h"
#include "PointView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CPointView

IMPLEMENT_DYNCREATE(CPointView, CFormView)

CPointView::CPointView()
	: CFormView(CPointView::IDD)
{
	fSize = 0;
	m_pW.RemoveAll();
}

CPointView::~CPointView()
{
}

void CPointView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPointView, CFormView)
	ON_WM_SIZE()
	ON_COMMAND(ID_NEXT_EXP, &CPointView::NextExp)
END_MESSAGE_MAP()


// диагностика CPointView

#ifdef _DEBUG
void CPointView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPointView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUTESDoc* CPointView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUTESDoc)));
	return (CUTESDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CPointView


void CPointView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: добавьте специализированный код или вызов базового класса

	SetDlgItemText(IDC_EDIT_GNAME,m_pE->GetName());

	fSize = 1;
	sel = 0;

	CStatic *Text;
	CString Name;
	CExponent* m_pC;
	CComboBox *Combo;
	CEdit *Edit;
	CFont *Font = new CFont;
	CWnd *Wnd = GetDlgItem(IDC_EXP_GROUP);
	CString Buff;

	int y0 = 20;
	m_pW.SetSize(m_pE->m_agr.GetCount());

	Font = GetDlgItem(IDC_EDIT_GNAME)->GetFont();	
	POSITION pos = m_pE->m_agr.GetHeadPosition();
	for (int i = 0; i < m_pW.GetCount(); i++) {
		Text = new CStatic;
		Name = ((CExponent*)m_pE->m_agr.GetNext(pos))->GetName();
		Text->Create(Name, WS_CHILD|WS_VISIBLE,  CRect(5,y0+i*30,205,y0+i*30+22),Wnd);
		Text->SetFont(Font);
		m_pC = GetExponent(Name);
		if (m_pC->GetType() == EXPONENT_NUMBER) {
			Edit = new CEdit;
			m_pW[i] = Edit;
			Edit->Create(WS_CHILD|WS_VISIBLE, CRect(210,y0+i*30,415,y0+i*30+22), Wnd, 2034);
			Edit->SetFont(Font);
			Edit->ModifyStyleEx(0,WS_EX_CLIENTEDGE,SWP_FRAMECHANGED);
			if (m_pM->m_W.GetSize()==m_pW.GetCount()) {
				Buff.Format(_T("%g"),m_pM->m_W[i]);
				m_pW[i]->SetWindowTextA(Buff);
			} else m_pW[i]->SetWindowTextA(_T("0"));
		} else {
			Combo = new CComboBox;
			m_pW[i] = Combo;
			int c = m_pC->m_scale->GetGradation();
			Combo->Create(WS_CHILD|WS_VISIBLE|CBS_DROPDOWN,  CRect(210,y0+i*30,415,y0+i*30+(c+1)*22),Wnd,i+1);
			Combo->SetFont(Font);
			Combo->ResetContent();
			for (int j = 0; j < c; j++)
				Combo->AddString(m_pC->m_scale->GetLex(j));
			if (m_pM->m_W.GetSize()==m_pW.GetCount()) {
				Combo->SetCurSel(m_pM->m_W[i]);
			}
		}
		m_pW[0]->SetFocus();
	}
	UpdateData();
}


void CPointView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: добавьте свой код обработчика сообщений
	if (fSize) {
		CRect rect;
		GetClientRect(&rect);
		int x,y;
		if (rect.Width() < 432) x = 432;
		else x = rect.Width();
		y = 25+m_pW.GetSize()*30;
		GetDlgItem(IDC_EXP_GROUP)->MoveWindow(7,55,x-12,y);
	}
}


CExponent* CPointView::GetExponent(CString& name)
{
	CExponent* pC=NULL;
	POSITION pos=GetDocument()->m_Exp.GetHeadPosition();
	do
		pC=(CExponent*) GetDocument()->m_C.GetNext(pos);
	while ((pC->GetName()!=name)&&(pos!=NULL));
	return pC;
}


BOOL CPointView::DestroyWindow()
{
	// TODO: добавьте специализированный код или вызов базового класса
	if (m_pM->m_W.GetSize()!=m_pW.GetCount()) {
		m_pM->m_W.RemoveAll();
		m_pM->m_W.SetSize(m_pW.GetCount());
	}

	CString Buff;
	float d;
	for (int i = 0; i < m_pW.GetCount(); i++) {		
		if (m_pW[i]->IsKindOf(RUNTIME_CLASS(CComboBox)))
			m_pM->m_W[i] = ((CComboBox*)m_pW[i])->GetCurSel();
		else if (m_pW[i]->IsKindOf(RUNTIME_CLASS(CEdit))) {
			((CEdit*)m_pW[i])->GetWindowTextA(Buff);
			sscanf(Buff, "%f", &d);
			m_pM->m_W[i] = d;
		}
	}

	return CFormView::DestroyWindow();
}

void CPointView::NextExp()
{
	// TODO: добавьте свой код обработчика команд
	if (sel == m_pW.GetCount()-1) sel=-1;
	m_pW[++sel]->SetFocus();
}
