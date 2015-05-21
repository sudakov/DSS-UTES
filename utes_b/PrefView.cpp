//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Preferance Estimator Edit
// PrefView.cpp : implementation file
//
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "font.h"
#include "picture.h"
#include "UTES.h"
#include "Approx.h"
//#include "CritDialog.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
//#include "Criterion.h"
//#include "CGroup.h"
//#include "c:\Lab\TestCross\NewGrid.h"
#include "UTESDoc.h"
#include "DssPref.h"
#include "PrefView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrefView

IMPLEMENT_DYNCREATE(CPrefView, CFormView)

CPrefView::CPrefView()
	: CFormView(CPrefView::IDD)
{
	//{{AFX_DATA_INIT(CPrefView)
	//}}AFX_DATA_INIT
	fSize=0;
	m_pPict=NULL;
	m_pBitmap=NULL;
	m_pPictX=NULL;
	m_pBitmapX=NULL;
	m_Brush=NULL;
	m_Pen=NULL;
	m_sG.cx=500;
	m_sG.cy=(long)(m_sG.cx*0.8);
	m_sG0.cx=1100;
	m_sG0.cy=900;
	m_pMenu= new CMenu();
	m_pMenu->LoadMenu(IDR_MENU_PREF);
	AfxGetApp()->m_pMainWnd->GetMenu()->InsertMenu(1,MF_BYPOSITION|MF_POPUP, (UINT) m_pMenu->m_hMenu,"&Правка ФП");
	AfxGetApp()->m_pMainWnd->RedrawWindow(NULL,NULL,RDW_FRAME|RDW_INVALIDATE);
}

CPrefView::~CPrefView()
{
	if (m_pPict!=NULL) delete [] m_pPict;		
	if (m_pBitmap!=NULL) delete [] m_pBitmap;
	if (m_Brush!=NULL) delete [] m_Brush;
	if (m_Pen!=NULL) delete [] m_Pen;
	
	if (m_pPictX!=NULL) delete [] m_pPictX;
	if (m_pBitmapX!=NULL) delete [] m_pBitmapX;
	
	CByteArray* P;
	while (!m_UndoP.IsEmpty())
	{
		P=(CByteArray*) m_UndoP.RemoveHead();
		delete P;
	}

	AfxGetApp()->m_pMainWnd->GetMenu()->DeleteMenu(1,MF_BYPOSITION);
	AfxGetApp()->m_pMainWnd->RedrawWindow(NULL,NULL,RDW_FRAME|RDW_INVALIDATE);
	delete m_pMenu;
}

void CPrefView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrefView)
	DDX_Control(pDX, IDC_SPIN, m_Spin);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider);
	DDX_Control(pDX, IDC_LIST_VAL, m_OtherC);
	DDX_Control(pDX, IDC_COMBO_X, m_ComboX);
	DDX_Control(pDX, IDC_COMBO_Y, m_ComboY);
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_Grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrefView, CFormView)
	//{{AFX_MSG_MAP(CPrefView)
	ON_CBN_SELCHANGE(IDC_COMBO_X, OnChangeComboX)
	ON_CBN_SELCHANGE(IDC_COMBO_Y, OnChangeComboY)
	ON_WM_HSCROLL()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_VAL, OnItemchangedListVal)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN, OnDeltaposSpin)
	ON_COMMAND(ID_MENUITEM_APPROX, OnMenuitemApprox)
	ON_COMMAND(ID_MENUITEM_CLEAR, OnMenuitemClear)
	ON_COMMAND(ID_MENUITEM_COPY, OnMenuitemCopy)
	ON_COMMAND(ID_MENUITEM_DECL, OnMenuitemDecL)
	ON_COMMAND(ID_MENUITEM_INCL, OnMenuitemIncL)
	ON_COMMAND(ID_MENUITEM_INSERT, OnMenuitemInsert)
	ON_COMMAND(ID_MENUITEM_ISALL, OnMenuItemIsAll)
	ON_BN_CLICKED(IDC_STATIC_SCALE, OnStaticScale)
	ON_COMMAND(ID_MENUITEM_UNDO, OnMenuitemUndo)
	ON_COMMAND(ID_MENUITEM_SHOWGRAD, OnMenuitemShowgrad)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrefView diagnostics

#ifdef _DEBUG
void CPrefView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPrefView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUTESDoc* CPrefView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUTESDoc)));
	return (CUTESDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrefView message handlers

void CPrefView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();

//	AfxGetApp()->m_pMainWnd->GetMenu()->EnableMenuItem(ID_FILE_MRU_FILE1,MF_GRAYED);
//	GetMenu()->EnableMenuItem(ID_FILE_MRU_FILE2,MF_GRAYED);
	
//	AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_MENUITEM_SHOWGRAD,MF_UNCHECKED);
	//ReSize();
	if (m_pM->m_is_grad) AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_MENUITEM_SHOWGRAD,MF_CHECKED);
	else AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_MENUITEM_SHOWGRAD,MF_UNCHECKED);
	fSize=1;

	for (int i=3; i>=0; i--) m_OtherC.DeleteColumn(i);

	LV_COLUMN lvc;
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.fmt = LVCFMT_LEFT;
	lvc.pszText = (LPTSTR) "Наименование";
	lvc.cx = m_OtherC.GetStringWidth(lvc.pszText) + 15;
	lvc.iSubItem = 0;
	m_OtherC.InsertColumn(0,&lvc);
	lvc.pszText = (LPTSTR) "Значение     ";
	lvc.cx = m_OtherC.GetStringWidth(lvc.pszText) + 15;
	lvc.iSubItem = 1;
	m_OtherC.InsertColumn(1,&lvc);
	LoadFont();
	SetDlgItemText(IDC_EDIT_GNAME,m_pG->GetName());
	m_Slider.EnableWindow(FALSE);
	SetDlgItemText(IDC_EDIT_GOD,"");
	SetAxis();
	GetDlgItem(IDC_MSFLEXGRID1)->SetFocus();
}

// Подготовка обоих осей при тек. ФП No Index
void CPrefView::SetAxis()
{
   	BOOL fX=FALSE;
	BOOL fY=FALSE;
	for (int i=0; i<m_pG->m_agr.GetCount(); i++) m_U[i] = m_pM->m_U[i];
	SetDlgItemText(IDC_EDIT_CRNAME, "");
	SetDlgItemText(IDC_BUDDY_SPIN, "");
		
	if (!m_pM->m_is_number) CreateAllBitmap();


//	m_Slider.SetRange(0,m_pG->m_scale->GetGradation()-1);
	m_Slider.SetRange(0,m_pM->m_robast-1);
	m_Slider.SetPageSize(1);
	m_ComboX.ResetContent();
	m_ComboY.ResetContent();
	POSITION pos=m_pG->m_agr.GetHeadPosition();
	CExponent* pE;
	while (pos!=NULL)
	{
		pE=(CExponent*) m_pG->m_agr.GetNext(pos);
		m_ComboX.AddString(pE->GetName());
		m_ComboY.AddString(pE->GetName());
		if (pE->GetName()==m_pM->m_XName) fX=TRUE;
		if (pE->GetName()==m_pM->m_YName) fY=TRUE;
	}

	if (m_ComboX.GetCount()>0) 
	{
		if (!fX) m_ComboX.GetLBText(0,m_pM->m_XName);
		m_ComboX.SelectString(-1, m_pM->m_XName);
		m_pX=(CExponent*)m_pG->m_agr.GetAt(m_pG->m_agr.FindIndex(GetIndex(m_pM->m_XName,m_pG)));
	}
	else m_pX=NULL;

	if (m_ComboY.GetCount()>1) 
	{
		if (!fY) m_ComboY.GetLBText(1,m_pM->m_YName);
		m_ComboY.SelectString(-1, m_pM->m_YName);
		m_pY=(CExponent*)m_pG->m_agr.GetAt(m_pG->m_agr.FindIndex(GetIndex(m_pM->m_YName,m_pG)));
	}
	else 
	{
		m_ComboY.EnableWindow(FALSE);
		m_pY=NULL;
	}

	SetOtherCriterion();
	ChangeGrid();
}

void CPrefView::SetOtherCriterion()
{
	m_OtherC.DeleteAllItems();
	LV_ITEM lvItem;
	lvItem.mask = LVIF_TEXT;
	int k=0;
	int nx=m_ComboX.GetCurSel();
	int ny=m_ComboY.GetCurSel();
	CExponent* pE;
	CString Buff;
	int i=0;
	POSITION pos = m_pG->m_agr.GetHeadPosition();
	while (pos!=NULL)
	{	// Проверка не является ли осью тек. сечения
		if ( ((nx==CB_ERR)||(i!=nx))&&((ny==CB_ERR)||(i!=ny)) )
		{
			lvItem.iItem = k++;
			lvItem.iSubItem = 0;
			pE = (CExponent*) m_pG->m_agr.GetAt(pos);
			Buff=pE->GetName();
			lvItem.pszText = Buff.GetBuffer(20);
			Buff.ReleaseBuffer();
			m_OtherC.InsertItem(&lvItem);
			Buff=pE->m_scale->GetLex(m_U[i]);
			lvItem.iSubItem = 1;
			lvItem.pszText = Buff.GetBuffer(20);
			Buff.ReleaseBuffer();
			m_OtherC.SetItem(&lvItem);
		}
		i++;
		m_pG->m_agr.GetNext(pos);
	}
}

void CPrefView::OnChangeComboX() 
{
	m_pX=(CExponent*) m_pG->m_agr.GetAt(m_pG->m_agr.FindIndex(m_ComboX.GetCurSel()));
	m_pM->m_XName=m_pX->GetName();
	SetOtherCriterion();
	ChangeGrid();
	SetDlgItemText(IDC_EDIT_CRNAME, "");
	SetDlgItemText(IDC_BUDDY_SPIN, "");
}

void CPrefView::OnChangeComboY() 
{
	m_pY=(CExponent*) m_pG->m_agr.GetAt(m_pG->m_agr.FindIndex(m_ComboY.GetCurSel()));
	m_pM->m_YName=m_pY->GetName();
	SetOtherCriterion();
	ChangeGrid();
	SetDlgItemText(IDC_EDIT_CRNAME, "");
	SetDlgItemText(IDC_BUDDY_SPIN, "");
}

void CPrefView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CString Buff;
	UINT k=SB_ENDSCROLL;
	if ((pScrollBar!=NULL)&&(pScrollBar->m_hWnd==GetDlgItem(IDC_SLIDER1)->m_hWnd))
		DoWithRgn(IDC_STATIC_SCALE);
	
	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}



void CPrefView::ClearGrid()
{
	
	m_Grid.Clear();
}

void CPrefView::OnItemchangedListVal(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int n=pNMListView->iItem;
	if (n>=0)
	{
		CString Buff;
		Buff=m_OtherC.GetItemText(n,0);
		SetDlgItemText(IDC_EDIT_CRNAME,Buff);
		CExponent *pC;
		pC=GetExponent(Buff);
		m_Spin.SetRange(0,pC->m_scale->GetGradation()-1);
//		m_Slider.SetRange(0,m_pM->m_robast-1);
		int j=GetIndex(Buff,m_pG);
		m_Spin.SetPos(m_U[j]);
		Buff=m_OtherC.GetItemText(n,1);
		SetDlgItemText(IDC_BUDDY_SPIN,Buff);
	}
	*pResult = 0;
}


BEGIN_EVENTSINK_MAP(CPrefView, CFormView)
    //{{AFX_EVENTSINK_MAP(CPrefView)
	ON_EVENT(CPrefView, IDC_MSFLEXGRID1, 69 /* SelChange */, OnSelChangeMsflexgrid1, VTS_NONE)
	ON_EVENT(CPrefView, IDC_MSFLEXGRID1, -600 /* Click */, OnClickMsflexgrid1, VTS_NONE)
	ON_EVENT(CPrefView, IDC_MSFLEXGRID1, -601 /* DblClick */, OnDblClickMsflexgrid1, VTS_NONE)
	ON_EVENT(CPrefView, IDC_MSFLEXGRID1, -603 /* KeyPress */, OnKeyPressMsflexgrid1, VTS_PI2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CPrefView::OnSelChangeMsflexgrid1() 
{
	// TODO: Add your control notification handler code here
	UpdateValue();
}

void CPrefView::OnClickMsflexgrid1() 
{
	// TODO: Add your control notification handler code here
	UpdateValue();
}


int CPrefView::GetIndex(CString s, CExponent* pG)
{
	CString Buff;
	int k=0;
	POSITION pos = pG->m_agr.GetHeadPosition();
	while (((CExponent*)pG->m_agr.GetNext(pos))->GetName()!=s) k++;
	return k;
}

void CPrefView::UpdateValue()
{
	CString Buff;
	int i=m_Grid.GetCol()-1;
	m_ComboX.GetWindowText(Buff);
	if (Buff!="")
	{
		m_U[GetIndex(Buff,m_pG)]=i;
		m_pM->m_U[GetIndex(Buff,m_pG)]=i;
		m_Slider.EnableWindow(TRUE);
	}
	i=m_Grid.GetRow()-1;
	m_ComboY.GetWindowText(Buff);
	if (Buff!="")
	{
		m_U[GetIndex(Buff,m_pG)]=i;
		m_pM->m_U[GetIndex(Buff,m_pG)]=i;
	}
	int pref=m_pM->GetPreferance(m_U);
	int index=255;
	m_pG->m_scale->GetIndex(COleVariant((double)pref),index, m_pM);
	Buff=m_pG->m_scale->GetLex(index);
	SetDlgItemText(IDC_EDIT_GOD, Buff);
	m_Slider.SetPos(pref);
}

BOOL CPrefView::LoadFont()
{
	LOGFONT logFont;
	GetFont()->GetLogFont(&logFont);
	logFont.lfEscapement = 900;
	logFont.lfOrientation = 900;

	lstrcpy(logFont.lfFaceName, "Arial Cyr");

	return m_curFont.CreateFontIndirect(&logFont);
}

void CPrefView::ChangeGrid()
{
	CString Buff;
	int i1,i2,j,k;
	int n=m_pG->m_agr.GetCount();
	int* u=new int[n];
	int* v=new int[n];
	CExponent* pC;
	m_Grid.SetHighLight(0);
	m_ComboX.GetWindowText(Buff); 
	if (Buff!="")
	{
		pC=GetExponent(Buff);
		m_Grid.SetCols(pC->m_scale->GetGradation()+1);
		m_ComboY.GetWindowText(Buff); 
		if (Buff!="")
		{
			pC=GetExponent(Buff);
			m_Grid.SetRows(pC->m_scale->GetGradation()+1);
		}
		else m_Grid.SetRows(2);
	}
	else
	{
		ClearGrid();
	}

	m_ComboX.GetWindowText(Buff);
	if (Buff!="")
	{
		pC=GetExponent(Buff);                //,&flag);
		m_Grid.SetRow(0);
		m_Grid.SetColWidth(0,m_sG0.cx);
		m_Grid.SetRowHeight(0,m_sG0.cy);
		CreateAllBitmapX();
		for (j=0; j<pC->m_scale->GetGradation(); j++)
		{
			m_Grid.SetColWidth(j+1,m_sG.cx);
			m_Grid.SetCol(j+1);	//firs col is head
			//if (flag) { SetBitmap(j,pC->GetGradation()-1, j+1,0); m_Grid.SetText("");}
			//else { m_Grid.SetText(pC->GetLex(j)); m_Grid.SetPicture(NULL);}
			
			m_Grid.SetRefCellPicture(m_pPictX[j].GetPictureDispatch());
			m_Grid.SetCellPictureAlignment(4);
		}
		
		for (j=0; j<n; j++) u[j]=m_U[j];
		m_pM->GetCritDim(v);
		i1=GetIndex(Buff,m_pG);
		m_ComboY.GetWindowText(Buff);
		if (Buff!="") 
		{
			pC=GetExponent(Buff); //,&flag);
			m_Grid.SetCol(0);
			for (j=0; j<pC->m_scale->GetGradation(); j++)
			{
				m_Grid.SetRowHeight(j+1,m_sG.cy);
				m_Grid.SetRow(j+1);	//firs col is head
			//	if (flag) { SetBitmap(j,pC->GetGradation()-1,0,j+1); m_Grid.SetText("");}
			//	else { m_Grid.SetText(pC->GetLex(j)); m_Grid.SetPicture(NULL);}
				m_Grid.SetText(pC->m_scale->GetLex(j));
			}
			i2=GetIndex(Buff,m_pG);
			for (j=0; j<v[i1]; j++)
			{
				m_Grid.SetCol(j+1);
				u[i1]=j;
				for (k=0; k<v[i2]; k++)
				{
					m_Grid.SetRow(k+1);
					u[i2]=k;
					SetBitmap(m_pM->GetPreferance(u), m_pM->m_robast-1,j+1,k+1);
				}
			}
		}
		else
		{
			m_Grid.SetRow(1);
			m_Grid.SetCol(0);
			m_Grid.SetRowHeight(1,m_sG.cy);
			m_Grid.SetText(""); m_Grid.SetRefCellPicture(NULL);
			for (j=0; j<v[i1]; j++)
			{
				m_Grid.SetCol(j+1);
				u[i1]=j;
				SetBitmap(m_pM->GetPreferance(u),m_pM->m_robast-1,j+1,1);
			}
		}
	}
	m_ComboY.GetWindowText(Buff);
	if (Buff!="") 
	{
		m_Grid.SetRow(m_U[i2]+1);
	}
	else m_Grid.SetRow(1);
	m_Grid.SetCol(m_U[i1]+1);
	m_Grid.SetHighLight(1);
	delete [] u;
	delete [] v;
	UpdateValue();
}

CExponent* CPrefView::GetExponent(CString& name)
{
	CExponent* pC=NULL;
	POSITION pos=GetDocument()->m_Exp.GetHeadPosition();
	do
		pC=(CExponent*) GetDocument()->m_C.GetNext(pos);
	while ((pC->GetName()!=name)&&(pos!=NULL));
	return pC;
}

void CPrefView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	DrawRect();
	// Do not call CFormView::OnPaint() for painting messages
}

void CPrefView::DrawRect()
{
	int g; //,x0,x1;
	int min;
	int ng=m_pM->m_robast; //m_pG->m_scale->GetGradation();
	CString buf;
	CWnd* pWnd=GetDlgItem(IDC_STATIC_SCALE);
	CDC* pDC=pWnd->GetDC();
	CFont font;
	RECT rect;
	pWnd->GetClientRect(&rect);
	pWnd->Invalidate();
	pWnd->UpdateWindow();
	m_scaleX.SetSize(ng+1);
	m_scaleX[0]=rect.left;
	m_scaleX[ng]=rect.right;
	min=(m_scaleX[ng]-m_scaleX[0])/2;
	if (ng>2) 
	{	
		m_scaleX[ng-1] = (2*m_Slider.GetTicPos(ng-3) + rect.right)/3;
		for (g=1; g<(ng-1); g++)
		{
			m_scaleX[g]=(m_scaleX[g-1]+2*m_Slider.GetTicPos(g-1))/3;
			if (abs(m_scaleX[g]-m_scaleX[g-1])<min)
				min=abs(m_scaleX[g]-m_scaleX[g-1]);
		}
	}
	else
		m_scaleX[1] = min;

	if ((min>2)&&(!m_pM->m_is_number))
	for (g=0; g<ng; g++)
	{
		//TRACE("m_scaleX %i %i\n", m_scaleX[g], m_scaleX[g+1]);
		CBrush Brush(RGB((255*g)/(ng-1),
					     (255*g)/(ng-1),
					     (255*g)/(ng-1)));
		pDC->SelectObject(&Brush);
		pDC->SelectStockObject(NULL_PEN);
		pDC->Rectangle(m_scaleX[g],0,m_scaleX[g+1],rect.bottom);
	};
	if (m_pM->m_is_number)
	{
		font.CreatePointFont(80,"Arial Cyr");
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectObject(font);
		pDC->SetTextAlign(TA_CENTER);
		pDC->TextOut((m_scaleX[0]+m_scaleX[1])/2, 0,"1");
		buf.Format("%i",ng);
		int NextPos=0;
		int LastPos=(m_scaleX[ng-1]+m_scaleX[ng])/2;
		pDC->TextOut(LastPos, 0, buf);
		int step=0;
		if (min<1) min=1;
		for (int i=50; i>=5; i-=5)
		{
			if ((20/min)<i)
			{ 
				step=i; 
				g=i-1;
			}
		}
		if ((20/min)<1) { step=1; g=1;}
		if (step)
			for (; g<(ng-1); g+=step)
			{
				buf.Format("%i",g+1);
				NextPos=(m_scaleX[g]+m_scaleX[g+1])/2;
				if ((LastPos-NextPos)>20) pDC->TextOut(NextPos, 0, buf);
			}
	}
	pWnd->ReleaseDC(pDC);
}


void CPrefView::SetBitmap(int ps, int max_ps, int j, int k)
{
	CString buf;
	if ((m_pM->m_is_number)&&(!m_pM->m_is_grad))
	{
		if (ps>max_ps) buf="Н/О";
		else buf.Format("%i",ps+1);
		m_Grid.SetText(buf);
		m_Grid.SetCellAlignment(4);
		m_Grid.SetCellForeColor(RGB(0,0,255));
		m_Grid.SetCellFontBold(TRUE);
	}
	else
	{
		if (!m_pM->m_is_number)
		{
			if (ps>max_ps) ps=max_ps+1;
			m_Grid.SetRefCellPicture(m_pPict[ps].GetPictureDispatch());
			m_Grid.SetCellPictureAlignment(4);
		}
		if (m_pM->m_is_grad)
		{
			int index=255;
			m_pG->m_scale->GetIndex(COleVariant((double) ps), index, m_pM);
			buf=m_pG->m_scale->GetLex(index);
			m_Grid.SetText(buf);
			m_Grid.SetCellAlignment(1);
			m_Grid.SetCellForeColor(RGB(0,150,0));
			m_Grid.SetCellFontBold(TRUE);
		}
		else
		{
			m_Grid.SetText("");
		}
	}
}

void CPrefView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (fSize) ReSize();
}

void CPrefView::ReSize()
{
	CRect rect;
	CRect rect_cy;
	GetClientRect(rect);
	int x=rect.right;
	int y=rect.bottom;
//	if (x<500) x=500;
//	if (y<400) y=400;
	LONG l=GetDialogBaseUnits();
	double kx=LOWORD(l)/8.0;
	double ky=HIWORD(l)/16.0;

	m_ComboY.GetClientRect(rect_cy);
	WORD dx=6;
	WORD dy=13;
	int x1,y1;
	x1=(136*dx)/4; y1=(125*dy)/8;
	//m_Grid.MoveWindow((int)(x1*kx),(int)(y1*ky),(int)(x-x1*kx-10),(int)(y-y1*ky-10));
	m_Grid.MoveWindow(rect_cy.right+30,(int)(y1*ky),(int)(x-rect_cy.right-40),(int)(y-y1*ky-10));
	GetDlgItem(IDC_STATIC_FACE)->MoveWindow((int)(x-40*kx),(int)(33*ky),32,32);
	x1=(140*dx)/4; y1=(13*dy)/8;
	//GetDlgItem(IDC_STATIC_SCALE)->MoveWindow((int)(x1*kx),(int)(33*ky),(int)(x-(x1+50)*kx),(int)(20*ky));
	GetDlgItem(IDC_STATIC_SCALE)->MoveWindow(rect_cy.right+30,(int)(33*ky),(int)(x-rect_cy.right-30-50*kx),(int)(20*ky));
	//y1=(25*dy)/8;
	//m_Slider.MoveWindow((int)(x1*kx),(int)(55*ky),(int)(x-(x1+50)*kx),(int)(30*ky));
	m_Slider.MoveWindow(rect_cy.right+30,(int)(55*ky),(int)(x-rect_cy.right-30-50*kx),(int)(30*ky));
}

void CPrefView::CreateAllBitmap()
{
	// Pictures preparate
	int max_ps=m_pM->m_robast; //m_pG->m_scale->GetGradation();
	if (m_pPict!=NULL) delete [] m_pPict;		
	m_pPict=new CPictureHolder[max_ps+1];
	if (m_pBitmap!=NULL) delete [] m_pBitmap;
	m_pBitmap=new CBitmap[max_ps+1];
	if (m_Brush!=NULL) delete [] m_Brush;
	m_Brush=new CBrush[max_ps+1];
	if (m_Pen!=NULL) delete [] m_Pen;
	m_Pen=new CPen[max_ps+1];
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.SetMapMode(MM_TWIPS);
//	CSize size(m_Grid.GetColWidth(1),m_Grid.GetRowHeight(1));
	CSize size(m_sG);
	dc.LPtoDP(&size);
	size.cx=(long) (size.cx*0.9);
	size.cy=(long) (size.cy*0.9);
	COLORREF color;
	CDC* dcMemory=new CDC();
	dcMemory->CreateCompatibleDC(&dc);	
	for (int ps=0; ps<=max_ps; ps++)
	{
		m_pBitmap[ps].CreateCompatibleBitmap(&dc,size.cx,size.cy);
		dcMemory->SelectObject(&(m_pBitmap[ps]));
		if (ps==max_ps) color=RGB(200,0,0);
		else color=RGB((255*ps)/(max_ps-1),
					   (255*ps)/(max_ps-1),
				       (255*ps)/(max_ps-1));
		m_Brush[ps].CreateSolidBrush(color);
		dcMemory->SelectObject(m_Brush+ps);
		m_Pen[ps].CreatePen(PS_SOLID,0,color);
		dcMemory->SelectObject(m_Pen+ps);
		dcMemory->Rectangle(0,0,size.cx,size.cy);
		m_pPict[ps].CreateFromBitmap(&m_pBitmap[ps]);
	}
	delete dcMemory;

// end pictures
}

void CPrefView::CreateAllBitmapX()
{
	// Pictures preparate
	int n=m_pX->m_scale->GetGradation();
	if (m_pPictX!=NULL) delete [] m_pPictX;		
	m_pPictX=new CPictureHolder[n];
	if (m_pBitmapX!=NULL) delete [] m_pBitmapX;
	m_pBitmapX=new CBitmap[n];
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.SetMapMode(MM_TWIPS);
//	CSize size(m_Grid.GetColWidth(1),m_Grid.GetRowHeight(1));
	CSize size(m_sG.cx,m_sG0.cy);
	dc.LPtoDP(&size);

	CDC* dcMemory=new CDC();
	dcMemory->CreateCompatibleDC(&dc);	
	for (int j=0; j<n; j++)
	{
		m_pBitmapX[j].CreateCompatibleBitmap(&dc,size.cx-3,size.cy-3);
		dcMemory->SelectObject(&(m_pBitmapX[j]));
		dcMemory->SelectStockObject(LTGRAY_BRUSH);
		dcMemory->SelectStockObject(NULL_PEN);
		dcMemory->Rectangle(0,0,size.cx,size.cy);
		dcMemory->SetBkMode(TRANSPARENT);
		dcMemory->SelectObject(m_curFont);
		dcMemory->TextOut(size.cx/2-11,size.cy-5,m_pX->m_scale->GetLex(j));
		m_pPictX[j].CreateFromBitmap(&m_pBitmapX[j]);
	}
	delete dcMemory;

// end pictures
}

void CPrefView::OnDblClickMsflexgrid1() 
{
	// TODO: Add your control notification handler code here
	/*CString Buff;
	int i=m_Grid.GetCol()-1;
	if (i<0) return;
	m_ComboX.GetWindowText(Buff);
	if (Buff!="")
	{
		m_U[GetIndex(Buff,m_pG)]=i;
		m_Slider.EnableWindow(TRUE);
	}
	int j=m_Grid.GetRow()-1;
	if (j<0) return;
	m_ComboY.GetWindowText(Buff);
	if (Buff!="") m_U[GetIndex(Buff,m_pG)]=j;
	int pref=255;
	m_pM->SetPreference(m_U,pref);
	Buff=m_pG->m_scale->GetLex(pref);
	SetDlgItemText(IDC_EDIT_GOD, Buff);
	m_Slider.SetPos(pref);
	SetBitmap(pref,m_pG->m_scale->GetGradation()-1,i,j);*/
	DoWithRgn(ID_MENUITEM_CLEAR);
}

void CPrefView::OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	CString Buff;
	GetDlgItemText(IDC_EDIT_CRNAME,Buff);
	CExponent *pC;
	if (!Buff.IsEmpty())
	{
		pC=GetExponent(Buff);
		int j=GetIndex(Buff,m_pG);
		int k=pNMUpDown->iDelta+pNMUpDown->iPos;
		if (k>=pC->m_scale->GetGradation()) k=0;
		if (k<0) k=pC->m_scale->GetGradation()-1;
		m_U[j]=k;
		m_pM->m_U[j]=k;
		int i=0;
		while (m_OtherC.GetItemText(i, 0)!=Buff) i++;
		m_OtherC.SetItemText(i, 1, pC->m_scale->GetLex(m_U[j]));
		SetDlgItemText(IDC_BUDDY_SPIN, pC->m_scale->GetLex(m_U[j]));
		ChangeGrid();
	}
	else AfxMessageBox("Сначала выделите изменяемый показатель");
	*pResult = 0;
}



void CPrefView::OnMenuitemApprox() 
{
	DoWithRgn(ID_MENUITEM_APPROX);
}

void CPrefView::OnMenuitemClear() 
{
	// TODO: Add your command handler code here
	DoWithRgn(ID_MENUITEM_CLEAR);
}

void CPrefView::OnMenuitemCopy() 
{
	// TODO: Add your command handler code here
	DoWithRgn(ID_MENUITEM_COPY);
}

void CPrefView::OnMenuitemDecL() 
{
	// TODO: Add your command handler code here
	DoWithRgn(ID_MENUITEM_DECL);
}

void CPrefView::OnMenuitemIncL() 
{
	// TODO: Add your command handler code here
	DoWithRgn(ID_MENUITEM_INCL);
}

void CPrefView::OnMenuitemInsert() 
{
	// TODO: Add your command handler code here
	DoWithRgn(ID_MENUITEM_INSERT);
}

void CPrefView::DoWithRgn(int ID)
{
	int MaxL=m_pM->m_robast-1; //m_pG->m_scale->GetGradation()-1;
	CByteArray* P;
	int ps=0;
	
	m_Grid.SetHighLight(0);
	CApprox Model;
	Model.SetDimention(2);
	int maxDim=m_Grid.GetCols()*m_Grid.GetRows();
	double *w=new double[maxDim];
	double **MX=Model.Matrix(maxDim,2);
	double xn[2];
	int NumPoints=0;
	int sl_ps=m_Slider.GetPos();
		
	CString	Buff=m_pG->m_scale->GetLex(ps);
	int xx=m_Grid.GetCol();		int yy=m_Grid.GetRow();
	int xs=m_Grid.GetColSel();	int ys=m_Grid.GetRowSel();
	int i0=min(ys,yy);	int i1=max(ys,yy);
	int j0=min(xs,xx);	int j1=max(xs,xx);
	if (ID==ID_MENUITEM_UNDO)
	{
		P=(CByteArray*)m_UndoP.RemoveTail();
		m_pM->m_P.Copy(*P);
		delete P;
		i0=1; i1=m_Grid.GetRows()-1;
		j0=1; j1=m_Grid.GetCols()-1;
	}
	else
	{
		P=new CByteArray();
		P->Copy(m_pM->m_P);
		m_UndoP.AddTail(P);
		if (m_UndoP.GetCount()>10)
		{
			P=(CByteArray*)m_UndoP.RemoveHead();
			delete P;
		}
	}

	if (ID==ID_MENUITEM_COPY) m_clP.SetSize(i1-i0+1);
	if (ID==ID_MENUITEM_INSERT)
	{
		if (m_clP.GetSize()==0)
		{
			AfxMessageBox("В буфере не данных!!!");
			return;
		}

		if ((i1==i0)&&(j1==j0)) 
		{
			i1=i0+m_clP.GetSize()-1;
			j1=j0+m_clP[0].GetSize()-1;
		}
		if ((m_clP.GetSize()!=(i1-i0+1))
			||(i1>=m_Grid.GetRows())||(j1>=m_Grid.GetCols()))
		{
			AfxMessageBox("Не верный размер области вставки");
			return;
		}
	}
	int n=m_pG->m_agr.GetCount();
	int* u= new int[n];
	for (int j=0; j<n; j++) u[j]=m_U[j];
	m_ComboX.GetWindowText(Buff);
	int x=GetIndex(Buff,m_pG);
	int y=0;
	m_ComboY.GetWindowText(Buff);
	if (Buff!="") y=GetIndex(Buff,m_pG);
	for (int i=i0; i<=i1; i++)
	{
		if (ID==ID_MENUITEM_COPY) m_clP[i-i0].SetSize(j1-j0+1);
		if ((ID==ID_MENUITEM_INSERT)&&(m_clP[i-i0].GetSize()!=(j1-j0+1)))
		{
			AfxMessageBox("Не верный размер области вставки");
			delete [] u;
			return;
		}
		m_Grid.SetRow(i);
		for (int j=j0; j<=j1; j++)
		{
			m_Grid.SetCol(j);
			u[x]=j-1;
			if (!Buff.IsEmpty()) u[y]=i-1;
			switch (ID)
			{
			case ID_MENUITEM_INCL:
				ps=m_pM->GetPreferance(u);
				if (ps<MaxL)  ps++;
				break;
			case ID_MENUITEM_DECL:
				ps=m_pM->GetPreferance(u);
				if ((ps>0)&&(ps<=MaxL))  ps--;
				break;
			case ID_MENUITEM_COPY:
				ps=m_pM->GetPreferance(u);
				m_clP[i-i0][j-j0]=ps;
				break;
			case ID_MENUITEM_INSERT:
				ps=m_clP[i-i0][j-j0];
				break;
			case ID_MENUITEM_CLEAR:
				ps=255;
				break;
			case ID_MENUITEM_UNDO:
				ps=m_pM->GetPreferance(u);
				break;
			case IDC_STATIC_SCALE:
				ps=sl_ps;
				break;
			case ID_MENUITEM_APPROX:
				ps=m_pM->GetPreferance(u);
				if (ps<=MaxL)
				{
					MX[NumPoints][0]=i; MX[NumPoints][1]=j;
					w[NumPoints++]=ps;
				}
			}
			m_pM->SetPreference(u,ps);
			SetBitmap(ps,MaxL,0,0);
		}
	}
	if ((ID==ID_MENUITEM_APPROX)&&
		((NumPoints>2)||((NumPoints==2)&&((i0==i1)||(j0==j1))))&&
		(NumPoints<maxDim)
		)
	{
		Model.SetNumPoints(NumPoints);
		Model.LoadPoints(MX,w);
		for (int i=i0; i<=i1; i++)
		{
			m_Grid.SetRow(i);
			for (int j=j0; j<=j1; j++)
			{
				m_Grid.SetCol(j);
				u[x]=j-1;
				if (!Buff.IsEmpty()) u[y]=i-1;
				ps=m_pM->GetPreferance(u);
				if (ps>MaxL) 
				{
					xn[0]=i; xn[1]=j;
					ps=(int) Model.GetPref(xn);
					if (ps<0) ps=0;
					if (ps>MaxL) ps=MaxL;
					m_pM->SetPreference(u,ps);
					SetBitmap(ps,MaxL,0,0);
				}
			}
		}
	}
	Model.RemoveMatrix(maxDim,2,MX);
	delete [] w;
	delete [] u;
	m_Grid.SetRow(yy);		m_Grid.SetCol(xx);
	m_Grid.SetColSel(xs);	m_Grid.SetRowSel(ys);
	
	int index=255;
	m_pG->m_scale->GetIndex(COleVariant((double)(m_pM->GetPreferance(m_U))),index, m_pM);
	Buff=m_pG->m_scale->GetLex(index);
	SetDlgItemText(IDC_EDIT_GOD,Buff);
	m_Grid.SetHighLight(1);
	GetDocument()->SetModifiedFlag();
}


void CPrefView::OnMenuItemIsAll() 
{
	m_n=m_pG->m_agr.GetCount();
	if (Step(0))
	{
		//AfxMessageBox("Ошибка обнаружена \n"+Buff);
		for (int j=0; j<m_n; j++) 
		{
			m_U[j]=m_UU[j];
			m_pM->m_U[j]=m_UU[j];
		}
		SetOtherCriterion();
		ChangeGrid();
		SetDlgItemText(IDC_EDIT_CRNAME, "");
		SetDlgItemText(IDC_BUDDY_SPIN, "");
	}
	else AfxMessageBox("Ошибок нет");
}

int CPrefView::Step(int i)
{
	if (i==m_n)
	{
		if (m_pM->GetPreferance(m_UU)>254) return -1;
		return 0;
	}
	for (int j=0; j < (int) m_pM->m_v[i]; j++)
	{
		m_UU[i]=j;
		if (Step(i+1)) return -1;
	}
	return 0;
}

void CPrefView::OnStaticScale() 
{
	// TODO: Add your control notification handler code here
	CPoint point;
	CRect Rect;
	GetCursorPos(&point);
	GetDlgItem(IDC_STATIC_SCALE)->GetWindowRect(&Rect);
	int x0=Rect.left;
	int n=m_scaleX.GetSize();
	for (int i=0; i<n; i++)
	{
		if (((x0+m_scaleX[i])<point.x)&&(point.x<=(x0+m_scaleX[i+1])))
		{
			m_Slider.SetPos(i);
			DoWithRgn(IDC_STATIC_SCALE);
			i=n;
		}
	}
}

void CPrefView::OnMenuitemUndo() 
{
	// TODO: Add your command handler code here
	if (m_UndoP.GetCount()>0) DoWithRgn(ID_MENUITEM_UNDO);
}

void CPrefView::OnMenuitemShowgrad() 
{
	// TODO: Add your command handler code here
	if (AfxGetApp()->m_pMainWnd->GetMenu()->GetMenuState(ID_MENUITEM_SHOWGRAD,MF_BYCOMMAND)&MF_CHECKED)
	{
		AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_MENUITEM_SHOWGRAD, MF_UNCHECKED);
		m_pM->m_is_grad=FALSE;
	}
	else 
	{
		AfxGetApp()->m_pMainWnd->GetMenu()->CheckMenuItem(ID_MENUITEM_SHOWGRAD, MF_CHECKED);
		m_pM->m_is_grad=TRUE;
	}
	ChangeGrid();
}

void CPrefView::OnKeyPressMsflexgrid1(short FAR* KeyAscii) 
{
	// TODO: Add your control notification handler code here
	int pos=m_Slider.GetPos();
	switch (*KeyAscii)
	{
	case 45:
	case 95:
		//-
		if (pos) pos--;
		m_Slider.SetPos(pos);
		DoWithRgn(IDC_STATIC_SCALE);
		break;
	case 43:
	case 61:
		//+
		if (pos<(m_pM->m_robast-1)) pos++;
		m_Slider.SetPos(pos);
		DoWithRgn(IDC_STATIC_SCALE);
	}
}
