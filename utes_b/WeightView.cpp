//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Edit class for pref. method Wieght
// WeightView.cpp : implementation file
//
//---------------------------------------------------------------------------


#include "stdafx.h"
#include "sys_add_ins.h"
#include "UTES.h"
#include "GridCtrl.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "UTESDoc.h"
#include "WeightView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeightView

IMPLEMENT_DYNCREATE(CWeightView, CFormView)

CWeightView::CWeightView()
	: CFormView(CWeightView::IDD)
{
	//{{AFX_DATA_INIT(CWeightView)
	m_Norm = FALSE;
	
	
	fSize=0;
	m_FromE=FALSE;

	m_PCMode = false;
	m_PC = NULL;
	//}}AFX_DATA_INIT
}

CWeightView::~CWeightView()
{
}

void CWeightView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeightView)
	DDX_Check(pDX, IDC_CHECK2, m_Norm);
	DDX_GridControl(pDX, IDC_MYGRID, m_myGrid);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider);	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeightView, CFormView)
	//{{AFX_MSG_MAP(CWeightView)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, OnNormW)
	ON_BN_CLICKED(IDC_RADIO1, &CWeightView::OnSelShortMode)
	ON_BN_CLICKED(IDC_RADIO3, &CWeightView::OnSelSpecialMode)
	ON_BN_CLICKED(IDC_RADIO2, &CWeightView::OnSelFullMode)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CWeightView::OnSelSpecialItem)
	ON_BN_CLICKED(IDC_BUTTON4, &CWeightView::OnPrefChange)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON3, &CWeightView::OnInitPairedComparison)
	ON_BN_CLICKED(IDC_BUTTON5, &CWeightView::OnOK)
	ON_BN_CLICKED(IDC_BUTTON6, &CWeightView::OnCancel)
	ON_WM_LBUTTONUP()
	ON_EN_KILLFOCUS(IDC_EDIT2, &CWeightView::OnEnKillfocusEdit2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeightView diagnostics

#ifdef _DEBUG
void CWeightView::AssertValid() const
{
	CFormView::AssertValid();
}

void CWeightView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUTESDoc* CWeightView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUTESDoc)));
	return (CUTESDoc*)m_pDocument;
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CWeightView message handlers

void CWeightView::OnInitialUpdate() 
{	
	CFormView::OnInitialUpdate();

	//ReSize();
	// TODO: Add your specialized code here and/or call the base class

	SetDlgItemText(IDC_EDIT_GNAME,m_pE->GetName());

	OnInitialGrid();

	m_Slider.SetRange(100,SLIDER_MAX_VALUE*100);
}

void CWeightView::OnNormW() 
{
	// TODO: Add your control notification handler code here
	double s=0;
	CString Buff;
	int n=m_pM->m_W.GetSize();
	if (n==m_pE->m_agr.GetCount())
	{
		GetDocument()->SetModifiedFlag();
		for (int i=0; i<n; i++) s+=m_pM->m_W[i];
		if (s) for (int i=0; i<n; i++) m_pM->m_W[i]/=s;
		s=0;
		for (int i=0; i<n; i++)
		{
			Buff.Format("%g",m_pM->m_W[i]);
			m_myGrid.SetItemText(i+1,1,Buff);
			s+=m_pM->m_W[i];
		}
		Buff.Format("%g",s);
		SetDlgItemText(IDC_EDIT1,Buff);
		if (m_pE->GetMaxValue()==m_pE->GetMinValue())
		{
			m_pE->SetMaxValue(s);
			m_pE->SetMinValue(0);
		}
		m_myGrid.RedrawColumn(1);
	}
}

/*void CWeightView::OnCheckNorm() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	m_pM->m_Norm=m_Norm;
}
*/

void CWeightView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
    if (fSize) ReSize();	
	
}

void CWeightView::ReSize()
{
	CRect rect;
	GetClientRect(&rect);
	int x=rect.right/2;
	int y=rect.bottom;
	WORD x0=10;
	WORD y0=80;
	LONG l=GetDialogBaseUnits();
	double dx=LOWORD(l)/8.0;
	double dy=HIWORD(l)/16.0;
	
	m_myGrid.MoveWindow(x0*dx,y0*dy,x-x0*dx,y-(y0+10)*dy,FALSE);
	GetDlgItem(IDC_CHECK2)->MoveWindow(x+10,y0*dy,200*dx,15*dy);
	GetDlgItem(IDC_BUTTON1)->MoveWindow(x+10,(y0+45)*dy,200*dx,30*dy);
	GetDlgItem(IDC_SUM_W)->MoveWindow(x+10,(y0+95)*dy,200*dx,45*dy);
	GetDlgItem(IDC_EDIT1)->MoveWindow(x+15,(y0+110)*dy,190*dx,25*dy);
	GetDlgItem(IDC_BUTTON3)->MoveWindow(x+10,(y0+145)*dy,200*dx,30*dy);
	GetDlgItem(IDC_STATIC4)->MoveWindow(x+10,y0*dy,200*dx,100*dy);
	GetDlgItem(IDC_RADIO1)->MoveWindow(x+15,(y0+20)*dy,190*dx,10*dy);
	GetDlgItem(IDC_RADIO2)->MoveWindow(x+15,(y0+35)*dy,190*dx,10*dy);
	GetDlgItem(IDC_RADIO3)->MoveWindow(x+15,(y0+50)*dy,190*dx,10*dy);
	GetDlgItem(IDC_COMBO1)->MoveWindow(x+30,(y0+65)*dy,170*dx,150*dy);
	GetDlgItem(IDC_BUTTON4)->MoveWindow(x+10,(y0+110)*dy,200*dx,30*dy);
	GetDlgItem(IDC_SLIDER1)->MoveWindow(x+10,(y0+145)*dy,150*dx,30*dy);
	GetDlgItem(IDC_EDIT2)->MoveWindow(x+150*dx+10,(y0+145)*dy,50*dx,25*dy);
	GetDlgItem(IDC_BUTTON5)->MoveWindow(x+10,(y0+180)*dy,95*dx,30*dy);
	GetDlgItem(IDC_BUTTON6)->MoveWindow(x+115,(y0+180)*dy,95*dx,30*dy);
	
//	OnKillfocusEditG();
//	CWnd* w= new CWnd;
//	w->m_hWnd=(HWND) m_G.GetHWnd();
//	CClientDC dc(w);
//	dc.SetMapMode(MM_TWIPS);
//	CSize s(x/2-10,0);
//	dc.DPtoLP(&s);
//	m_G.SetColWidth(0,abs(s.cx));
//	m_G.SetColWidth(1,abs(s.cx));
//	w->m_hWnd=NULL;
//	delete w;
}


BEGIN_EVENTSINK_MAP(CWeightView, CFormView)
    //{{AFX_EVENTSINK_MAP(CWeightView)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

/*void CWeightView::OnKeyPressMsflexgrid(short FAR* KeyAscii) 
{
	// TODO: Add your control notification handler code here
	int x=m_x;
	int y=m_y;
	CString Buff;

	m_x=m_G.GetCol();
	m_y=m_G.GetRow();
	
	if (m_E.IsWindowVisible())
	{
		m_G.SetCol(x);
		m_G.SetRow(y);
		m_E.GetWindowText(Buff);
		m_G.SetText(Buff);
	}

	m_G.SetCol(m_x);
	m_G.SetRow(m_y);

	CRect r;
	r.left=m_G.GetCellLeft();
	r.top=m_G.GetCellTop();
	r.right=m_G.GetCellLeft()+m_G.GetCellWidth();
	r.bottom=m_G.GetCellTop()+m_G.GetCellHeight();
	
	CWnd* w= new CWnd;
	w->m_hWnd=(HWND) m_G.GetHWnd();
	
	CClientDC dc(w);
	
	dc.SetMapMode(MM_TWIPS);
	
	dc.LPtoDP(&r);

	LONG l=GetDialogBaseUnits();
	double dx=LOWORD(l)/8.0;
	double dy=HIWORD(l)/16.0;

	r.top=abs(r.top)+80*dy;
	r.bottom=abs(r.bottom)+80*dy;
	r.left=r.left+10*dx;
	r.right=r.right+10*dx;
	m_E.ShowWindow(SW_SHOW);
	m_E.MoveWindow(r);
	Buff=m_G.GetText();
	if (Buff.IsEmpty())
	{
		if (KeyAscii!=NULL) Buff=(char) *KeyAscii;
		m_E.SetWindowText(Buff);
		m_E.SetFocus();
		m_E.SetSel(1,1);
	}
	else
	{
		m_E.SetWindowText(Buff);
		m_E.SetFocus();
		m_E.SetSel(0,-1);
	}
//	m_E.SetWindowPos
	w->m_hWnd=NULL;
	delete w;
}

void CWeightView::OnKillfocusEditG() 
{
	// TODO: Add your control notification handler code here
	int x=m_x;
	int y=m_y;
	int n=m_pE->m_agr.GetCount();
	double s=0;
	double d=0;
	CString Buff;
	m_FromE=TRUE;

	m_x=m_G.GetCol();
	m_y=m_G.GetRow();
	
	if (m_E.IsWindowVisible())
	{
		m_G.SetCol(x);
		m_G.SetRow(y);
		m_E.GetWindowText(Buff);
		if (GetNumber(Buff,d)) 
		{
			AfxMessageBox("Ошибка ввода числа");
		}
		else
		{
			m_G.SetText(Buff);
			if (m_pM->m_W.GetSize()!=n)
			{
				m_pM->m_W.SetSize(n);
				for (int i=0; i<n; i++) m_pM->m_W[i]=0.0;
			}
			m_pM->m_W[y-1]=d;
			for (int i=0; i<n; i++) s+=m_pM->m_W[i];
			Buff.Format("%g",s);
			SetDlgItemText(IDC_EDIT1,Buff);
			if (m_pE->GetMaxValue()==m_pE->GetMinValue())
			{
				m_pE->SetMaxValue(s);
				m_pE->SetMinValue(0);
			}
		}
		m_E.ShowWindow(SW_HIDE);

	}

	m_G.SetCol(m_x);
	m_G.SetRow(m_y);	
}


void CWeightView::OnButton2() 
{
	int n=m_pE->m_agr.GetCount();
	
	int x=m_G.GetCol();
	if (x==0) return;
	int y=m_G.GetRow();
	if (y==0) return;
	if (m_FromE)
	{
		m_FromE=FALSE;
		if (m_G.GetRows()>(y+1)) m_G.SetRow(y+1);
		m_G.SetFocus();
	}
	else OnKeyPressMsflexgrid(NULL); 
}
*/


BOOL CWeightView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class	
	switch (wParam) {
	case IDC_MYGRID:
		if (m_PCMode) {
			m_myGrid.SetSelectedRange(-1,-1,-1,-1);
			NM_GRIDVIEW* nm=(NM_GRIDVIEW*)lParam;
			if ((nm->hdr.code)==GVN_SELCHANGED) {
				if (nm->iRow > 0) {
					int d = m_PC->GetValue(nm->iRow-1)*1000;
					d = (d+1)/10;	// Компенсация ошибки приведения типов
					m_Slider.SetPos(d);	
					CString Buff;
					Buff.Format(_T("%g"),(float)d/100);
					SetDlgItemText(IDC_EDIT2,Buff);
				}
			}
		} else {
			NM_GRIDVIEW* nm=(NM_GRIDVIEW*)lParam;
			if ((nm->hdr.code)==GVN_ENDLABELEDIT) {
				CString Buff;
				int i=0;
				double s=0.0, d=0.0;
				GetDocument()->SetModifiedFlag();
				if ((nm->iColumn==1)&&(nm->iRow>0)) {
					int n=m_pE->m_agr.GetCount();
					if (m_pM->m_W.GetSize()!=n) {
						m_pM->m_W.SetSize(n);
						for (i=0; i<n; i++) m_pM->m_W[i]=0.0;
					}
					for (int i=1; i< m_myGrid.GetRowCount(); i++) {
						if ((Buff=m_myGrid.GetItemText(i,1))=="") Buff="0";
						if (GetNumber(Buff,d)) {
							AfxMessageBox("Ошибка ввода числа");
							return CFormView::OnNotify(wParam, lParam, pResult);
						}
						m_pM->m_W[i-1]=d;
						s+=d;
					}
				}
				Buff.Format("%g",s);
				SetDlgItemText(IDC_EDIT1,Buff);
				if (m_pE->GetMaxValue()==m_pE->GetMinValue()) {
					m_pE->SetMaxValue(s);
					m_pE->SetMinValue(0);
				}
			}
		}
		break;
	case IDC_SLIDER1: 
		CString Buff;
		switch (((NMHDR*)lParam)->code) {
		case NM_CUSTOMDRAW:		
			Buff.Format("%g",m_Slider.GetPos()/100.0);
			SetDlgItemText(IDC_EDIT2,Buff);
			break;
		case NM_RELEASEDCAPTURE:
			OnEnKillfocusEdit2();
			break;
		}
		break;
	}
	return CFormView::OnNotify(wParam, lParam, pResult);
}


void CWeightView::OnModeChange(int Mode)
{
	// TODO: добавьте свой код обработчика уведомлений
	switch (m_PC->GetType()) {
	case TYPE_SHORT:
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(false);
		break;
	case TYPE_FULL:
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(false);
		break;
	case TYPE_ONE_WITH_ALL:
		((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);
		((CComboBox *)GetDlgItem(IDC_COMBO1))->ResetContent();
		((CComboBox *)GetDlgItem(IDC_COMBO1))->EnableWindow(false);
		break;
	case -1:
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(false);
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(false);
		((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);
		((CComboBox *)GetDlgItem(IDC_COMBO1))->ResetContent();
		((CComboBox *)GetDlgItem(IDC_COMBO1))->EnableWindow(false);
		break;
	}
	if (Mode == TYPE_ONE_WITH_ALL) {
		((CComboBox *)GetDlgItem(IDC_COMBO1))->EnableWindow(true);
		POSITION pos=m_pE->m_agr.GetHeadPosition();
		while (pos!=NULL)
			((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(((CExponent*)m_pE->m_agr.GetNext(pos))->GetName()); 
		((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(0);
		m_PC->SetType(Mode,((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCurSel());
	} else {
		m_PC->SetType(Mode);
	}
	OnInitialGrid();
}


void CWeightView::OnInitialGrid()
{
	fSize=1;
	m_myGrid.DeleteAllItems();
	// Режим ввода парных сравнений
	if (m_PCMode) {
		int n = m_pE->m_agr.GetCount();
		m_myGrid.SetColumnCount(4);
		switch (m_PC->GetType()) {
		case TYPE_ONE_WITH_ALL:
			m_myGrid.SetRowCount(n);
			break;
		case TYPE_SHORT:
			m_myGrid.SetRowCount(n);
			break;
		case TYPE_FULL:
			m_myGrid.SetRowCount((n-1)*n/2+1);
			break;
		}
		m_myGrid.SetFixedRowCount(1);
		m_myGrid.SetFixedColumnCount(1);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = 0;
		Item.col = 1;
		Item.nFormat = DT_LEFT;
		Item.szText.Format(_T("%s"),"Предпочтительнее критерий:");
		m_myGrid.SetItem(&Item);
		Item.col = 2;
		Item.szText.Format(_T("%s"),"На");
		m_myGrid.SetItem(&Item);
		Item.col = 3;
		Item.szText.Format(_T("%s"),"Чем критерий:");
		m_myGrid.SetItem(&Item);

		int i = 1;
		POSITION pos=m_pE->m_agr.GetHeadPosition();
		switch (m_PC->GetType()) {
		case TYPE_ONE_WITH_ALL:	
			// i - хранит номер строки, на котором остановилось заполнение столбца 3
			for (int j = 0; j < n; j++) {
				if (j != m_PC->GetMain()) {				
					Item.row = i;
					Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
					if (!m_PC->IsPreferable(Item.row-1)) Item.col = 1;
					else Item.col = 3;
					m_myGrid.SetItem(&Item);
					i++;
				} else {
					// Основной критерий
					Item.row = 1;
					Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
					while (Item.row < n) {		
						if (!m_PC->IsPreferable(Item.row-1)) Item.col = 3;
						else Item.col = 1;
						m_myGrid.SetItem(&Item);
						Item.row++;
					}	
					// Предпочтительность
					Item.row = 1;
					Item.col = 2;
					while (Item.row < n) {										
						Item.szText.Format(_T("%g"),m_PC->GetValue(Item.row-1));
						m_myGrid.SetItem(&Item);
						Item.row++;
					}
				}
			}
			break;
		case TYPE_SHORT:
			while (pos!=NULL) {
				// i - хранит номер заполняемой строки
				Item.row = i;
				Item.col = 1;
				if (i == 1) {
					Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
					if (!m_PC->IsPreferable(Item.row-1)) Item.col = 3;
					m_myGrid.SetItem(&Item);
				} else {
					if (i != n) {
						Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
						if (!m_PC->IsPreferable(Item.row-1)) Item.col = 3;
						m_myGrid.SetItem(&Item);
						Item.row--;					
						Item.col = 3;
						if (!m_PC->IsPreferable(Item.row-1)) Item.col = 1;
						m_myGrid.SetItem(&Item);
					} else {
						Item.row--;
						Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
						Item.col = 3;
						if (!m_PC->IsPreferable(Item.row-1)) Item.col = 1;
						m_myGrid.SetItem(&Item);
					}
					// Предпочтительность
					Item.col = 2;
					Item.szText.Format(_T("%g"),m_PC->GetValue(Item.row-1));
					m_myGrid.SetItem(&Item);
				}
				i++;
			}
			break;
		case TYPE_FULL:
			// i - хранит номер строки, на котором остановилось заполнение столбца 1
			int k = 0; // хранит количество прочитанных (и пропечатанных) критериев
			while (pos!=NULL) {
				Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
				Item.row = i;
				for (int j = 1; j < n; j++) {
					if (!m_PC->IsPreferable(Item.row-1)) Item.col = 3;
					else Item.col = 1;
					m_myGrid.SetItem(&Item);
					Item.row++;	
				}
				n--;
				i = Item.row;
				Item.row = k;
				for (int j = 0; j < k; j++) {
					if (!m_PC->IsPreferable(Item.row-1)) Item.col = 1;
					else Item.col = 3;
					m_myGrid.SetItem(&Item);
					Item.row += n+k-j-1;	
				}			
				k++;
			}
			// Предпочтительность
			n = (k-1)*k/2;
			Item.row = 1;
			Item.col = 2;
			for (int j = 0; j < n; j++) {										
				Item.szText.Format(_T("%g"),m_PC->GetValue(j));
				m_myGrid.SetItem(&Item);
				Item.row++;
			}
			break;
		}
		m_myGrid.SetEditable(FALSE);
	} else {
		// Режим ввода весовых коэффициентов
		double s=0;
		CString Buff;
		m_myGrid.SetColumnCount(2);
		//m_myGrid.SetColumnWidth(0,1500);
		//m_myGrid.SetColumnWidth(1,1500);
		m_myGrid.SetRowCount(m_pE->m_agr.GetCount()+1);
		m_myGrid.SetFixedRowCount(1);
		m_myGrid.SetFixedColumnCount(1);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = 0;
		Item.col = 0;
		Item.nFormat = DT_LEFT;
		Item.szText.Format(_T("%s"),"Показатели");
		m_myGrid.SetItem(&Item);
		Item.col = 1;
		Item.szText.Format(_T("%s"),"Веса");
		m_myGrid.SetItem(&Item);

		int i=1;
	
		POSITION pos=m_pE->m_agr.GetHeadPosition();
		while (pos!=NULL) {
			Item.row = i;
			Item.col = 0;
			Item.nFormat = DT_LEFT; //|DT_WORDBREAK;
			Item.szText.Format(_T("%s"),((CExponent*)m_pE->m_agr.GetNext(pos))->GetName());
			m_myGrid.SetItem(&Item);
			if (m_pM->m_W.GetSize()==m_pE->m_agr.GetCount())
			{
				Item.col = 1;
				Item.nFormat = DT_RIGHT;
				Item.szText.Format(_T("%g"),m_pM->m_W[i-1]);
				m_myGrid.SetItem(&Item);
				s+=m_pM->m_W[i-1];
			}
			i++;
		}
	
		m_Norm=m_pM->m_Norm;
		if (s) {
			Buff.Format("%g",s);
			SetDlgItemText(IDC_EDIT1,Buff);
			if (m_pE->GetMaxValue()==m_pE->GetMinValue())
			{
				m_pE->SetMaxValue(s);
				m_pE->SetMinValue(0);
			}
		}
		m_myGrid.SetEditable(TRUE);
	}
	m_myGrid.AutoSize();
	UpdateData(FALSE);
}


void CWeightView::OnSelShortMode()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnModeChange(TYPE_SHORT);
}


void CWeightView::OnSelSpecialMode()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnModeChange(TYPE_ONE_WITH_ALL);
}


void CWeightView::OnSelFullMode()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnModeChange(TYPE_FULL);
}


void CWeightView::OnSelSpecialItem()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_PC->SetType(TYPE_ONE_WITH_ALL,((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCurSel());
	OnInitialGrid();
}


void CWeightView::OnPrefChange()
{
	// TODO: добавьте свой код обработчика уведомлений
	CCellID ID = m_myGrid.GetFocusCell();
	if (ID.row > 0) {
		m_PC->ChangePreferable(ID.row-1);
		CString Buff = m_myGrid.GetItemText(ID.row,1);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = ID.row;
		Item.col = 1;
		Item.nFormat = DT_LEFT;
		Item.szText.Format(_T("%s"),m_myGrid.GetItemText(ID.row,3));
		m_myGrid.SetItem(&Item);
		Item.col = 3;
		Item.szText.Format(_T("%s"),Buff);
		m_myGrid.SetItem(&Item);
		m_myGrid.RedrawCell(ID.row,1);
		m_myGrid.RedrawCell(ID.row,3);
	}
}

void CWeightView::OnInitPairedComparison()
{
	// TODO: добавьте свой код обработчика уведомлений
	m_PCMode = true;
	if (m_pM->m_W.GetSize()!= 0)
		m_PC = new CMethodPC(m_pM, MessageBox("Вычислить матрицу парных сравнений из весовых коэффициентов? ", "Дополнительный параметры ", MB_YESNO));
	else m_PC = new CMethodPC(m_pM,IDNO);

	GetDlgItem(IDC_CHECK2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SUM_W)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RADIO1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RADIO2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_RADIO3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_COMBO1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SLIDER1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_SHOW);
	
	m_Slider.SetPos(100);
	OnSelShortMode();
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(true);
}


void CWeightView::OnDelPairedComparison(int Msg)
{
	// TODO: добавьте свой код обработчика уведомлений
	if (Msg == IDOK) {
		GetDocument()->SetModifiedFlag();
		m_PC->GetWeights();
	}
	m_PCMode = false;
	m_PC->~CMethodPC();

	GetDlgItem(IDC_RADIO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RADIO2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RADIO3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SLIDER1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON6)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_CHECK2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SUM_W)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON3)->ShowWindow(SW_SHOW);

	OnInitialGrid();
}


void CWeightView::OnOK()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnDelPairedComparison(IDOK);
}


void CWeightView::OnCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	OnDelPairedComparison();
}


void CWeightView::OnEnKillfocusEdit2()
{
	// TODO: добавьте свой код обработчика уведомлений
	CCellID ID = m_myGrid.GetFocusCell();
	if (ID.row > 0) {
		CString Buff;
		GetDlgItemText(IDC_EDIT2,Buff);
		float d;
		sscanf(Buff, "%f", &d);
		GV_ITEM Item;
		Item.mask = GVIF_TEXT|GVIF_FORMAT;
		Item.row = ID.row;
		Item.col = 2;
		Item.nFormat = DT_LEFT;
		Item.szText.Format(_T("%s"),Buff);
		m_myGrid.SetItem(&Item);
		m_myGrid.RedrawCell(ID.row,2);
		m_PC->SetValue(d,ID.row-1);
	}
}
