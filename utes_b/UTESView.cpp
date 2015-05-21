//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Main description view class
// UTESView.cpp : implementation of the CUTESView class
//
//---------------------------------------------------------------------------


#include "stdafx.h"
#include "UTES.h"

#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "ExponentDialog.h"
#include "DialogSelMethod.h"
//#include "Criterion.h"
//#include "CGroup.h"

#include "UTESDoc.h"
#include "DssPref.h"
#include "UTESView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUTESView

IMPLEMENT_DYNCREATE(CUTESView, CFormView)

BEGIN_MESSAGE_MAP(CUTESView, CFormView)
	//{{AFX_MSG_MAP(CUTESView)
	ON_COMMAND(ID_ADDCR, OnAddCriteria)
	ON_COMMAND(ID_CHCR, OnChangeCriterion)
	ON_COMMAND(ID_DELCR, OnDelCriterion)
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CRIT, OnDblclkListCrit)
	ON_UPDATE_COMMAND_UI(ID_CHCR, OnUpdateChCr)
	ON_UPDATE_COMMAND_UI(ID_DELCR, OnUpdateDelCr)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST_CRIT, OnKillfocusListCrit)
	ON_COMMAND(ID_MENUITEM_SELMETH, OnMenuitemSelMethod)
	ON_UPDATE_COMMAND_UI(ID_MENUITEM_SELMETH, OnUpdateMenuitemSelMethod)
	ON_UPDATE_COMMAND_UI(ID_ADDCR, OnUpdateAddcr)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_NOTIFY(NM_SETFOCUS, IDC_TREE, OnSetfocusTree)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUTESView construction/destruction

CUTESView::CUTESView()
	: CFormView(CUTESView::IDD)
{
	//{{AFX_DATA_INIT(CUTESView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	fSize=0;
}

CUTESView::~CUTESView()
{
}

void CUTESView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUTESView)
	DDX_Control(pDX, IDC_STATIC_PF, m_GroupCount);
	DDX_Control(pDX, IDC_STATIC_CR, m_CriterionCount);
	DDX_Control(pDX, IDC_TREE, m_DecompTree);
	DDX_Control(pDX, IDC_LIST_GRUP, m_GroupList);
	DDX_Control(pDX, IDC_LIST_CRIT, m_CritList);
	//}}AFX_DATA_MAP
}

BOOL CUTESView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUTESView printing

BOOL CUTESView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUTESView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUTESView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CUTESView::OnPrint(CDC* pDC, CPrintInfo*)
{
	// TODO: add code to print the controls
}

/////////////////////////////////////////////////////////////////////////////
// CUTESView diagnostics

#ifdef _DEBUG
void CUTESView::AssertValid() const
{
	CFormView::AssertValid();
}

void CUTESView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CUTESDoc* CUTESView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUTESDoc)));
	return (CUTESDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUTESView message handlers

void CUTESView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	ReSize();
	fSize=1;
	for (int i=5; i>=0; i--) m_CritList.DeleteColumn(i);
	LV_COLUMN lvc;
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.fmt = LVCFMT_LEFT;
	lvc.pszText = (LPTSTR) "Имя";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 60;
	lvc.iSubItem = 0;
	m_CritList.InsertColumn(0,&lvc);
	
	lvc.pszText = (LPTSTR) "Описание";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 20;
	lvc.iSubItem = 1;
	m_CritList.InsertColumn(1,&lvc);
	
	lvc.pszText = (LPTSTR) "Тип";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 15;
	lvc.iSubItem = 2;
	m_CritList.InsertColumn(2,&lvc);
	
	lvc.pszText = (LPTSTR) "Исп.";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 15;
	lvc.iSubItem = 3;
	m_CritList.InsertColumn(3,&lvc);
	
	lvc.pszText = (LPTSTR) "Ч.град.";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 15;
	lvc.iSubItem = 4;
	m_CritList.InsertColumn(4,&lvc);
	
	lvc.pszText = (LPTSTR) "Метод";
	lvc.cx = m_CritList.GetStringWidth(lvc.pszText) + 60;
	lvc.iSubItem = 5;
	m_CritList.InsertColumn(5,&lvc);
	
	ReDrawCrit();
	RebildTree();
	SetCritSel();
}

void CUTESView::OnAddCriteria() 
{
	CExponentDialog dlg;
#ifdef DEMOVER
	if (GetDocument()->m_Exp.GetCount()>=CRIT_LIM)
	{
		AfxMessageBox("В демонстрационной программе Вы не можете\n работать больше чем с 4-я показателями");
		return;
	}
#else
	if (((CUTESApp*)AfxGetApp())->m_Protection.CheckStatus(1))
	{
		AfxMessageBox("Программа запущена в некорректном режиме");
		return;
	}
#endif
	int n = m_CritList.GetItemCount();
	for (int i=0; i<n;i++)
		if (m_CritList.GetItemState(i,LVIS_SELECTED))
			GetCritPos(m_CritList.GetItemText(i,0));
	do
	{
		dlg.m_E=NULL;
		dlg.m_pAllE=&(GetDocument()->m_Exp);
		if (dlg.DoModal()==IDOK)
		{
			GetDocument()->SetModifiedFlag();
			if (dlg.m_E==NULL) AfxMessageBox("Непредвиденная ошибка");
			else
			{
				GetDocument()->m_Exp.AddTail(dlg.m_E);
				GetCritPos(dlg.m_E->GetName());
				if (m_CritList.GetItemCount()>=m_CritList.GetCountPerPage()) 
					GetDocument()->m_CritPos=m_CritList.GetItemCount()-m_CritList.GetCountPerPage()+1;
			}
			ReDrawCrit();
			RebildTree();
			SetCritSel();
		}
#ifdef DEMOVER
		if ((GetDocument()->m_Exp.GetCount()>=CRIT_LIM)&&(dlg.flag))
		{
			AfxMessageBox("В демонстрационной программе Вы не можете\n работать больше чем с 4-я показателями");
			return;
		}
#else
		if (((CUTESApp*)AfxGetApp())->m_Protection.CheckStatus(1))
		{
			AfxMessageBox("Программа запущена в некорректном режиме");
			return;
		}
#endif
	}
	while (dlg.flag);
	SetCritSel();
}


void CUTESView::OnChangeCriterion() 
{
	int n = m_CritList.GetItemCount();
	int i=0;
	UINT flag;
//	int NumGrad;
	do
		flag=m_CritList.GetItemState(i++,LVIS_SELECTED);
	while ((i<n)&&(!flag));
	if (flag)
	{
		CString Buff=m_CritList.GetItemText(--i,0);
		CExponent *pE;
		POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
		BOOL flag=TRUE;
		while ((pos!=NULL)&&(flag))
		{
			pE = (CExponent*) GetDocument()->m_Exp.GetAt(pos);
			if (Buff == pE->GetName())
			{
				flag=FALSE;
				//NumGrad=pC->GetGradation();
				CExponentDialog dlg;
				dlg.m_E=pE;
				dlg.m_pAllE=&(GetDocument()->m_Exp);
				GetCritPos(dlg.m_E->GetName());
				if (dlg.DoModal()==IDOK)
				{
					GetCritPos(dlg.m_E->GetName());
					GetDocument()->SetModifiedFlag();
					if (pE!=dlg.m_E)
					{
						GetDocument()->m_Exp.SetAt(pos,dlg.m_E);
						CExponent* pG;
						POSITION pos1;
						POSITION pos2;
						pos1 = GetDocument()->m_Exp.GetHeadPosition();
						while (pos1!=NULL)
						{
							pG = (CExponent*) GetDocument()->m_G.GetNext(pos1);
							if ( (pos2 = pG->m_agr.Find(pE)) != NULL ) 
							{
								pG->m_agr.SetAt(pos2, dlg.m_E);
								//if (NumGrad!=pC->GetGradation()) SetDim(pG);
							}
						}
						delete pE;
					}
					ReDrawCrit();
					RebildTree();
				}
				SetCritSel();
			}
			GetDocument()->m_Exp.GetNext(pos);
		}
	}
	//else AfxMessageBox("Не выбран показатель");
}

void CUTESView::OnDelCriterion() 
{
	int n = m_CritList.GetItemCount();
	int i=0;
	UINT flag;
	do
		flag=m_CritList.GetItemState(i++,LVIS_SELECTED);
	while ((i<n)&&(!flag));
	if (flag)
	{
		CString Buff=m_CritList.GetItemText(--i,0);
		GetCritPos(Buff);
		if (AfxMessageBox("Вы действительно хотите удалить показатель \""+
			Buff+"\"?",MB_YESNO)==IDYES)
		{
			if ((i+1)<n) GetCritPos(m_CritList.GetItemText(i+1,0));
			else GetCritPos(m_CritList.GetItemText(i-1,0));

			CExponent *pE;
			POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
			BOOL flag=TRUE;
		
			while ((pos!=NULL)&&(flag))
			{
				pE = (CExponent*) GetDocument()->m_Exp.GetAt(pos);
				if (Buff == pE->GetName())
				{
					flag=FALSE;
					GetDocument()->m_Exp.RemoveAt(pos);
					CExponent *pG;
					POSITION pos2;
					pos = GetDocument()->m_Exp.GetHeadPosition();
					while (pos!=NULL)
					{ 
						pG = (CExponent*) GetDocument()->m_Exp.GetNext(pos);
						if ((pos2 = pG->m_agr.Find(pE)) != NULL ) 
						{
							pG->m_agr.RemoveAt(pos2);
							if ((pG->m_Method!=NULL)&&
								(pG->m_Method->GetType()==METHOD_PREFERENCE))
								((CMethodPR*)pG->m_Method)->SetCritDim();
						}
					}
					delete pE;
					ReDrawCrit();
					RebildTree();
				}
				else GetDocument()->m_Exp.GetNext(pos);
			}
			GetDocument()->SetModifiedFlag();
		}
		SetCritSel();
	}
	else AfxMessageBox("Не выбран показатель");
}


void CUTESView::SetDim(CExponent *pG)
{
	/*POSITION pos=pG->m_cc.GetHeadPosition();
	int v[10];
	int i=0;
	CCrit *pC;
	while (pos!=NULL)
	{
		CString Buff=pG->m_cc.GetNext(pos);
		POSITION pos2=GetDocument()->m_C.GetHeadPosition();
		do 
			pC = (CCrit*)GetDocument()->m_C.GetNext(pos2);
		while ((Buff!=pC->GetName())&&(pos2!=NULL));
		if (Buff!=pC->GetName()) 
		{
			pos2=GetDocument()->m_G.GetHeadPosition();
			CGroup* pG;
			do 
				pG = (CGroup*)GetDocument()->m_G.GetNext(pos2);
			while ((Buff!=pG->GetName())&&(pos2!=NULL));
			v[i]=pG->GetGradation();
		}
		else v[i]=pC->GetGradation();
		i++;
	}
	pG->SetCritDim(v);*/
}

int CUTESView::RebildTree()
{
	CExponent *pE;
	m_DecompTree.DeleteAllItems();
	POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
	POSITION pos2;
	while (pos!=NULL)
	{
		pE=(CExponent*)GetDocument()->m_Exp.GetNext(pos);
		pos2=GetDocument()->m_Exp.GetHeadPosition();
		POSITION Rez=NULL;
		while ((pos2!=NULL)&&(Rez==NULL))
			Rez=((CExponent*) GetDocument()->m_Exp.GetNext(pos2))->m_agr.Find(pE);
		if (Rez==NULL) //One root find
			AddNode(NULL, pE);
	}
	return 0;
}

int CUTESView::AddNode(HTREEITEM Father, CExponent *pG)
{
	HTREEITEM Dad=m_DecompTree.InsertItem(pG->GetName(),Father);
	POSITION pos=pG->m_agr.GetHeadPosition();
	while (pos!=NULL)
	{
		AddNode(Dad,(CExponent*) pG->m_agr.GetNext(pos));
	}
	m_DecompTree.Expand(Dad,TVE_EXPAND);
	return 1;
}

void CUTESView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	if (fSize) ReSize();
}

void CUTESView::ReSize()
{
	CRect rect;
	GetClientRect(rect);
	int x=2*(rect.right-rect.left)/5;
	int y1=(rect.bottom-rect.top)/3;
	int y2=2*(rect.bottom-rect.top)/3;

	m_DecompTree.SetWindowPos(&wndTop,2,20,x-15,y1+y2-20,SWP_SHOWWINDOW);
	m_GroupCount.ShowWindow(SW_HIDE);
	m_GroupList.ShowWindow(SW_HIDE);
	//m_GroupCount.SetWindowPos(&wndTop,x,5,x-10,15,SWP_SHOWWINDOW);
	//m_GroupList.SetWindowPos(&wndTop,x,25,x-10,y1-30,SWP_SHOWWINDOW);
	//m_CriterionCount.SetWindowPos(&wndTop,x,y1+10,x-10,15,SWP_SHOWWINDOW);
	//m_CritList.SetWindowPos(&wndTop,x,y1+25,x-10,y2-25,SWP_SHOWWINDOW);
	m_CriterionCount.SetWindowPos(&wndTop,x,3,rect.right-x-10,13,SWP_SHOWWINDOW);
	m_CritList.SetWindowPos(&wndTop,x,20,rect.right-x-10,y1+y2-20,SWP_SHOWWINDOW);
}

void CUTESView::ReDrawCrit()
{
	m_CritList.DeleteAllItems();
	CExponentFactory f;
	CMethodFactory mf;
	CExponent* pE;
	int item;
	
	CString Buff;
	LV_ITEM lvItem;
	item = 0;
	lvItem.mask = LVIF_TEXT;
	POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
	while (pos!=NULL)
	{
		pE = (CExponent*) GetDocument()->m_Exp.GetNext(pos);
		lvItem.iItem = item++;
		lvItem.iSubItem = 0;
		Buff = pE->GetName();
		lvItem.pszText = Buff.GetBuffer(20);
		Buff.ReleaseBuffer();
		m_CritList.InsertItem(&lvItem);
		
		lvItem.iSubItem = 1;
		Buff=pE->GetDescription();
		lvItem.pszText = Buff.GetBuffer(20);
		Buff.ReleaseBuffer();
		m_CritList.SetItem(&lvItem);

		lvItem.iSubItem = 2;
		f.GetTypeLex(pE->GetType(),Buff);
		lvItem.pszText = Buff.GetBuffer(20);
		Buff.ReleaseBuffer();
		m_CritList.SetItem(&lvItem);

		lvItem.iSubItem = 3;
		Buff="";
		CExponent* pG;
		POSITION pos2;
		pos2 = GetDocument()->m_Exp.GetHeadPosition();
		while ((pos2!=NULL)&&(Buff==""))
		{ 
			pG = (CExponent*) GetDocument()->m_G.GetNext(pos2);
			if ( (pG->m_agr.Find(pE)) != NULL ) Buff="Да";
		}
		lvItem.pszText = Buff.GetBuffer(20);
		Buff.ReleaseBuffer();
		m_CritList.SetItem(&lvItem);
		
		if (pE->m_scale!=NULL)
		{
			lvItem.iSubItem = 4;
			Buff.Format("%i",pE->m_scale->GetGradation());
			lvItem.pszText = Buff.GetBuffer(20);
			Buff.ReleaseBuffer();
			m_CritList.SetItem(&lvItem);
		}
		if (pE->m_Method!=NULL)
		{
			lvItem.iSubItem = 5;
			mf.GetTypeLex(pE->m_Method->GetType(),Buff);
			lvItem.pszText = Buff.GetBuffer(20);
			Buff.ReleaseBuffer();
			m_CritList.SetItem(&lvItem);
		}
	}
	Buff.Format("Показатели (кол-во:%i)", GetDocument()->m_Exp.GetCount());
	m_CriterionCount.SetWindowText(Buff);
}



void CUTESView::OnDblclkListCrit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnChangeCriterion();
	*pResult = 0;
}

void CUTESView::OnUpdateChCr(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(IsSelect());
}

void CUTESView::OnUpdateDelCr(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(IsSelect());
}

int CUTESView::IsSelect(int k)
{
	int n = m_CritList.GetItemCount();
	int i=0;
	UINT flag=FALSE;
	do
		flag = m_CritList.GetItemState(i++,LVIS_SELECTED);
	while ((i<n)&&(!flag));
	if ((k==0)||(!flag)) return flag;
	CString Buff=m_CritList.GetItemText(--i,0);
	CExponent *pE;
	POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
	while (pos!=NULL)
	{
		pE = (CExponent*) GetDocument()->m_Exp.GetNext(pos);
		if (Buff == pE->GetName())
		{
			if (pE->GetType()==EXPONENT_GROUP) return TRUE;
			return FALSE;				
		}
	}
	return FALSE;
}

void CUTESView::OnKillfocusListCrit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int n = m_CritList.GetItemCount();
	for (int i=0; i<n; i++)
		m_CritList.SetItemState(i,0,LVIS_SELECTED);
	*pResult = 0;
}

void CUTESView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	RebildTree();
	ReDrawCrit();
}

void CUTESView::OnMenuitemSelMethod() 
{
	// TODO: Add your command handler code here
	CDialogSelMethod dlg;
	int n = m_CritList.GetItemCount();
	int i=0;
	UINT flag;
	do
		flag=m_CritList.GetItemState(i++,LVIS_SELECTED);
	while ((i<n)&&(!flag));
	if (flag)
	{
		CString Buff=m_CritList.GetItemText(--i,0);
		GetCritPos(Buff);
		CExponent *pE;
		POSITION pos = GetDocument()->m_Exp.GetHeadPosition();
		BOOL flag=TRUE;
		while ((pos!=NULL)&&(flag))
		{
			pE = (CExponent*) GetDocument()->m_Exp.GetAt(pos);
			if (Buff == pE->GetName())
			{
				flag=FALSE;
				dlg.m_pE=pE;
				if (dlg.DoModal()==IDOK)
				{
					GetDocument()->SetModifiedFlag();
					ReDrawCrit();
				}
			}
			GetDocument()->m_Exp.GetNext(pos);
		}
		SetCritSel();
	}
}

void CUTESView::OnUpdateMenuitemSelMethod(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(IsSelect(1));	
}

void CUTESView::OnUpdateAddcr(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(((CUTESApp*)AfxGetApp())->m_Protection.m_ProgCode!=SP_CODE);
}



void CUTESView::SetCritSel()
{
	if (GetDocument()->m_sel_crit!="")
	{
		int n = m_CritList.GetItemCount();
		for (int i=0; i<n; i++)
			if (m_CritList.GetItemText(i,0)==GetDocument()->m_sel_crit)
			{
				m_CritList.SetItemState(i,-1,LVIS_SELECTED);
				RECT r;
				m_CritList.GetItemRect(0,&r,LVIR_BOUNDS);
				int h=r.bottom - r.top;
				if ((h>=0)&&(!m_CritList.GetTopIndex()))
					m_CritList.Scroll(CSize(0,GetDocument()->m_CritPos*h));
			}
	}
}


void CUTESView::GetCritPos(CString name)
{
	GetDocument()->m_CritPos=m_CritList.GetTopIndex(); //m_CritList.GetScrollPos(SB_VERT);
	GetDocument()->m_sel_crit=name;
}


void CUTESView::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	GetCritPos(m_DecompTree.GetItemText(m_DecompTree.GetSelectedItem()));
	SetCritSel();
	*pResult = 0;
}


void CUTESView::OnSetfocusTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	GetCritPos(m_DecompTree.GetItemText(m_DecompTree.GetSelectedItem()));
	SetCritSel();
	*pResult = 0;
}
