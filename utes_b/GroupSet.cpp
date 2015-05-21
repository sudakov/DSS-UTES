//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Dialog class for seting Exponent Param
// GroupSet.cpp : implementation file
//
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "ScaleDialog.h"
#include "GroupSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroupSet dialog


CGroupSet::CGroupSet(CWnd* pParent /*=NULL*/)
	: CDialog(CGroupSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGroupSet)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CGroupSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGroupSet)
	DDX_Control(pDX, IDC_LIST2, m_AllList);
	DDX_Control(pDX, IDC_LIST1, m_CurList);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGroupSet, CDialog)
	//{{AFX_MSG_MAP(CGroupSet)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddForList)
	ON_BN_CLICKED(IDC_BUTTON2, OnAddFromList)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroupSet message handlers

void CGroupSet::OnAddForList() 
{
	CString Buff;
	int n=0;
	int i=0;
	do
	{
		i=0;
		if (n=m_AllList.GetCount())
		{
			for (; i<n; i++)
			{
				if (m_AllList.GetSel(i))
				{
					m_AllList.GetText(i,Buff);
					m_AllList.DeleteString(i);
					m_CurList.InsertString(-1,Buff);
					i=n+1;
				}
			}
		}
	}
	while (!(i==n));
	EnableButtomCur();
	GetDlgItem(IDOK)->SetFocus();
}

void CGroupSet::OnAddFromList() 
{
	CString Buff;
	int n=0;
	int i=0;
	do
	{
		i=0;
		if (n=m_CurList.GetCount())
		{
			for (; i<n; i++)
			{
				if (m_CurList.GetSel(i))
				{
					m_CurList.GetText(i,Buff);
					m_CurList.DeleteString(i);
					m_AllList.InsertString(-1,Buff);
					i=n+1;
				}
			}
		}
	}
	while (!(i==n));
	EnableButtomAll();
	GetDlgItem(IDOK)->SetFocus();
}

void CGroupSet::EnableButtomCur()
{
	int IsSel=FALSE;
	int n=0;
	n=m_AllList.GetCount();
	for (int i=0; i<n; i++)
	{
		if (m_AllList.GetSel(i))
		{
			IsSel=TRUE;
			i=n;
		}
	}
	GetDlgItem(IDC_BUTTON1)->EnableWindow(IsSel);
}

void CGroupSet::EnableButtomAll()
{
	int IsSel=FALSE;
	int n=0;
	n=m_CurList.GetCount();
	for (int i=0; i<n; i++)
	{
		if (m_CurList.GetSel(i))
		{
			IsSel=TRUE;
			i=n;
		}
	}
	GetDlgItem(IDC_BUTTON2)->EnableWindow(IsSel);
}

BOOL CGroupSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString Buff;
	CStringList SelC;
	//m_Name=m_pE->GetName();
	POSITION pos = m_pE->m_agr.GetHeadPosition();
	while (pos!=NULL)
	{
		Buff=((CExponent*) m_pE->m_agr.GetNext(pos))->GetName();
		m_CurList.InsertString(-1, Buff);
		SelC.AddHead(Buff);
	}
	pos = m_pAllE->GetHeadPosition();
	while (pos!=NULL)
	{
		Buff=((CExponent*) m_pAllE->GetNext(pos))->GetName();
		if ((SelC.Find(Buff)==NULL)&&(Buff!=m_pE->GetName())) 
						m_AllList.InsertString(-1,Buff);
	}
	
	int n=m_F.Count;
	int* IDs= new int[n];
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_METHOD);
	pCB->ResetContent();
	m_F.GetAllID(IDs);
	for (int i=0; i<n; i++)
	{
		if (m_F.GetTypeLex(IDs[i],Buff)) 
			AfxMessageBox("Ошибка в определении методов");
		else pCB->AddString(Buff);
	}
	delete [] IDs;
	if (m_pE->m_Method==NULL) n=0;
	else
	{
		m_F.GetTypeLex(m_pE->m_Method->GetType(),Buff);
		n=pCB->FindString(-1,Buff);
	}
	if (pCB->SetCurSel(n)==CB_ERR) AfxMessageBox("Ошибка в определении методов");
	EnableButtomCur();
	EnableButtomAll();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGroupSet::OnOK() 
{
	// TODO: Add extra validation here
	CString Buff;
	POSITION pos;
	CExponent* pE;
	int n=m_CurList.GetCount();
	if (n>MAX_E) 
	{
		AfxMessageBox("Число агрегируемых показателей\n" 
			          "не может быть больше десяти");
		return;
	}
	m_pE->m_agr.RemoveAll();
	for (int i=0; i<n; i++)
	{
		m_CurList.GetText(i,Buff);
		pos=m_pAllE->GetHeadPosition();
		do
			pE=(CExponent*)m_pAllE->GetNext(pos);
		while (pE->GetName()!=Buff);
		m_pE->m_agr.AddTail(pE);
	}
	
	n=m_F.Count;
	int* IDs= new int[n];
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_METHOD);
	m_F.GetAllID(IDs);
	n=pCB->GetCurSel();
	if (m_pE->m_Method==NULL) m_pE->m_Method=m_F.CreateObject(IDs[n]);
	else
	{
		if (IDs[n]!=m_pE->m_Method->GetType())
		{
			delete m_pE->m_Method;
			m_pE->m_Method=m_F.CreateObject(IDs[n]);
		}
	}
	m_pE->m_Method->m_pE=m_pE;
	delete [] IDs;
	CDialog::OnOK();
}

void CGroupSet::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CGroupSet::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	m_AllList.SelItemRange(FALSE,0,m_AllList.GetCount());
	EnableButtomAll();
	EnableButtomCur();
}

void CGroupSet::OnSelchangeList2() 
{
	// TODO: Add your control notification handler code here
	m_CurList.SelItemRange(FALSE,0,m_CurList.GetCount());
	EnableButtomAll();
	EnableButtomCur();
}
