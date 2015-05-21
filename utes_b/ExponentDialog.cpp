//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Dialog class for seting Exponent
// ExponentDialog.cpp : implementation file
//
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "ExponentDialog.h"
#include "ScaleDialog.h"
#include "GroupSet.h"
#include "DialogExpAdv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExponentDialog dialog


CExponentDialog::CExponentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CExponentDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExponentDialog)
	m_Name = _T("");
	m_Description = _T("");
	//}}AFX_DATA_INIT
	m_Rect.bottom=0;
}


void CExponentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExponentDialog)
	DDX_Control(pDX, IDC_BUTTON_NEXT_EXP, m_NextExp);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	DDV_MaxChars(pDX, m_Name, 200);
	DDX_Text(pDX, IDC_EDIT2, m_Description);
	DDV_MaxChars(pDX, m_Description, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CExponentDialog, CDialog)
	//{{AFX_MSG_MAP(CExponentDialog)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_EXP, OnButtonNextExp)
	ON_CBN_CLOSEUP(IDC_COMBO_TYPE, OnCloseupComboType)
	ON_BN_CLICKED(IDC_BUTTON_CHARACT, OnButtonCharact)
	ON_BN_CLICKED(IDC_BUTTON_SCALE, OnButtonScale)
	ON_CBN_CLOSEUP(IDC_COMBO_SCALE, OnCloseupComboScale)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_ADV, OnButtonAdv)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExponentDialog message handlers

BOOL CExponentDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	flag=0;
	//m_first=TRUE;
	CString Buff;
	int n=m_eF.Count;
	int* IDs= new int[n];
//	m_IsChange=FALSE;
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	m_eF.GetAllID(IDs);
	for (int i=0; i<n; i++)
	{
		if (m_eF.GetTypeLex(IDs[i],Buff)) 
			AfxMessageBox("Ошибка в определении типов");
		else pCB->AddString(Buff);
	}
	if (m_E==NULL)
	{
		n=0;
		m_Name="";
		m_Description="";
		m_BuffE=m_eF.CreateObject(IDs[n]);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_NEXT_EXP)->ShowWindow(SW_HIDE);
		m_eF.GetTypeLex(m_E->GetType(),Buff);
		n=pCB->FindString(-1,Buff);
		if (n==CB_ERR)
		{
			AfxMessageBox("Тип не распознан");
			n=0;
		}
		m_Name=m_E->GetName();
		m_Description=m_E->GetDescription();
		m_BuffE=m_eF.CreateObject(IDs[n]);
		*m_BuffE=*m_E;
	}
	if (pCB->SetCurSel(n)==CB_ERR) AfxMessageBox("Ошибка в определении типов");
	else 
	{

		MakeScaleList(IDs[n]);
		if (m_BuffE->m_scale!=NULL)
		{
			m_sF.GetTypeLex(m_BuffE->m_scale->GetType(), Buff);
			CComboBox* pC=(CComboBox*)GetDlgItem(IDC_COMBO_SCALE);
			pC->SetCurSel(pC->FindString(-1,Buff));
		}

		if (IDs[n]==EXPONENT_GROUP)
	 		 GetDlgItem(IDC_BUTTON_CHARACT)->ShowWindow(SW_SHOW);
		else GetDlgItem(IDC_BUTTON_CHARACT)->ShowWindow(SW_HIDE);
		if (IDs[n]!=EXPONENT_LEXICAL)
	 		 GetDlgItem(IDC_BUTTON_ADV)->ShowWindow(SW_SHOW);
		else GetDlgItem(IDC_BUTTON_ADV)->ShowWindow(SW_HIDE);

	}
	delete [] IDs;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CExponentDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	m_Name.TrimLeft(); m_Name.TrimRight();
	if (m_Name=="")
	{
		AfxMessageBox("Имя показателя не задано");
		GetDlgItem(IDC_EDIT_NAME)->SetFocus();
		return;
	}
	
	POSITION pos=m_pAllE->GetHeadPosition();
	CExponent* pE;
	while (pos!=NULL)
	{
		pE=(CExponent*)m_pAllE->GetNext(pos);
		if ((pE!=m_E)&&(pE->GetName()==m_Name))
		{
			AfxMessageBox("Показатель с таким именем уже существует");
			GetDlgItem(IDC_EDIT_NAME)->SetFocus();
			return;
		}
	}

	BeforExit();	
	flag=0;
	GetWindowRect(&m_Rect);
	CDialog::OnOK();
}

void CExponentDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
/*	if ((flag==2)&&(m_E!=NULL)) delete m_E;
	else
	{
		if ((m_E!=NULL)&&(m_E->m_scale!=NULL))
		{
			;
		}
	}
	m_E=NULL;*/
	delete m_BuffE;
	flag=0;
	//scale check
	GetWindowRect(&m_Rect);
	CDialog::OnCancel();
}

void CExponentDialog::OnButtonNextExp() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_Name.TrimLeft(); m_Name.TrimRight();

	if (m_Name=="")
	{
		AfxMessageBox("Имя показателя не задано");
		GetDlgItem(IDC_EDIT_NAME)->SetFocus();
		return;
	}
	
	POSITION pos=m_pAllE->GetHeadPosition();
	CExponent* pE;
	while (pos!=NULL)
	{
		pE=(CExponent*)m_pAllE->GetNext(pos);
		if ((pE!=m_E)&&(pE->GetName()==m_Name))
		{
			AfxMessageBox("Показатель с таким именем уже существует");
			GetDlgItem(IDC_EDIT_NAME)->SetFocus();
			return;
		}
	}

	BeforExit();
	flag=1;
	GetWindowRect(&m_Rect);
	CDialog::OnOK();
}

int CExponentDialog::MakeScaleList(int ExpType)
{
	CString Buff;
	int n=m_sF.Count;
	int* IDs= new int[n];
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_SCALE);
	pCB->ResetContent();
	n=m_sF.GetAllForType(ExpType,IDs);
	for (int i=0; i<n; i++)
	{
		if (m_sF.GetTypeLex(IDs[i],Buff)) 
			AfxMessageBox("Ошибка в определении шкал");
		else pCB->AddString(Buff);
	}
//	if (m_BuffE==NULL) n=0;
//	else
//	{
	n=0;	
	//if (m_BuffE->m_scale==NULL) n=0;
	//	else
	//	{
	//		m_sF.GetTypeLex( m_scale, Buff);
	//		n=pCB->FindString(-1,Buff);
	//	}
//	}
//	if ((m_BuffE->m_scale!=NULL)&&(m_BuffE->GetType()==ExpType))
//	{
//		m_sF.GetTypeLex(m_BuffE->m_scale->GetType(), Buff);
//		n=pCB->FindString(-1,Buff);;
//	}

	if (pCB->SetCurSel(n)==CB_ERR) AfxMessageBox("Ошибка в определении шкал");
	delete [] IDs;
	return n;
}


void CExponentDialog::OnCloseupComboType() 
{
	// TODO: Add your control notification handler code here
	CString Buff;
	int n=m_eF.Count;
	int* IDs= new int[n];
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	m_eF.GetAllID(IDs);
	n=pCB->GetCurSel();
	if (n==CB_ERR) AfxMessageBox("Тип не задан");
	else
	{
//		if (m_E!=NULL)
//			if (m_BuffE->m_scale!=NULL)
//			{
//				delete m_BuffE->m_scale;
//				m_BuffE->m_scale=NULL;
//			}
		MakeScaleList(IDs[n]);
	}
	
	if (IDs[n]==EXPONENT_GROUP)
		GetDlgItem(IDC_BUTTON_CHARACT)->ShowWindow(SW_SHOW);
	else 
	{
		GetDlgItem(IDC_BUTTON_CHARACT)->ShowWindow(SW_HIDE);
		m_BuffE->m_agr.RemoveAll();
	}
	if (IDs[n]!=EXPONENT_LEXICAL)
		GetDlgItem(IDC_BUTTON_ADV)->ShowWindow(SW_SHOW);
	else 
	{
		GetDlgItem(IDC_BUTTON_ADV)->ShowWindow(SW_HIDE);
		m_BuffE->SetBestDir(0);
		m_BuffE->SetMaxValue(0);
		m_BuffE->SetMinValue(0);
	}

	delete [] IDs;
}

void CExponentDialog::BeforExit()
{
	int n=m_eF.Count;
	int* IDs= new int[n];
	m_eF.GetAllID(IDs);
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	n=pCB->GetCurSel();

//	if (m_E!=NULL)
//	{
	if (m_BuffE->GetType()!=IDs[n])
	{
	//		if (!m_first) delete m_E;
	//		else m_first=FALSE;
			m_BuffE->SetType(IDs[n]);
			if (m_BuffE->m_scale!=NULL)
			{
				int t=m_BuffE->m_scale->GetType();
				int f=0;
				int nn=m_sF.Count;
				int* IDss= new int[nn];
				nn=m_sF.GetAllForType(IDs[n],IDss);
				for (int i=0; i<nn; i++)
					if (t==IDss[i]) f=1;
				if (!f)
				{
					delete m_BuffE->m_scale;
					m_BuffE->m_scale=NULL;
				}
				delete [] IDss; 
			}
	}
//	}
//	else
//	{
//		m_E=m_eF.CreateObject(IDs[n]);
//		m_first=FALSE;
//	}
	m_BuffE->SetName(m_Name);
	m_BuffE->SetDescription(m_Description);
	if (m_E==NULL)
		m_E=m_eF.CreateObject(m_BuffE->GetType());
	*m_E=*m_BuffE;
	delete m_BuffE;
	delete [] IDs;
}

void CExponentDialog::OnButtonCharact() 
{
	// TODO: Add your control notification handler code here
	CGroupSet dlg;
//	if (m_E==NULL) flag=2;
	UpdateData(TRUE);
//	BeforExit();
	dlg.m_pAllE=m_pAllE;
	dlg.m_pE=m_BuffE;
	dlg.m_Name=m_Name;
	dlg.DoModal();
//	if (dlg.DoModal()==IDOK) m_IsChange=TRUE;
}

void CExponentDialog::OnButtonScale()
{
	// TODO: Add your control notification handler code here
	int n=m_sF.Count;
	int* IDs= new int[n];
//	if (m_E==NULL) flag=2;
	UpdateData(TRUE);
//	BeforExit();
	CComboBox* pCB=(CComboBox*)GetDlgItem(IDC_COMBO_SCALE);
	CString buff, buff2;
	GetDlgItem(IDC_COMBO_SCALE)->GetWindowText(buff);
	m_sF.GetAllID(IDs);
	for (int i=0; i<n; i++)
	{
		m_sF.GetTypeLex(IDs[i],buff2);
		if (buff==buff2)
		{
			if (m_BuffE->m_scale==NULL)
			{
				m_BuffE->m_scale=m_sF.CreateObject(IDs[i]);
				if (m_BuffE->m_scale->DialogEdit()!=IDOK)
				{
					delete m_BuffE->m_scale;
					m_BuffE->m_scale=NULL;
				}
			}
			else
			{
				if (m_BuffE->m_scale->GetType()==IDs[i])
					m_BuffE->m_scale->DialogEdit();
				else
				{
					CScale* pS=m_sF.CreateObject(IDs[i]);
					if (pS->DialogEdit()==IDOK) *m_BuffE->m_scale=*pS;
					delete pS;
				}
			}
			if (m_BuffE->m_scale!=NULL)
			{
				double a=0.0; double b=0.0;
				m_BuffE->m_scale->GetRange(a,b);
				m_BuffE->SetMinValue(a);
				m_BuffE->SetMaxValue(b);
			}
		}
	}
/*	if (m_BuffE->m_scale!=NULL)
	{
		for (i=0; i<n; i++)
			if (IDs[i]==m_BuffE->m_scale->GetType())
				pCB->SetCurSel(i);
	}
*/	
	//if (m_E->m_scale->DialogEdit()==IDOK) m_IsChange=TRUE;
	delete [] IDs;
}

void CExponentDialog::OnCloseupComboScale() 
{
	// TODO: Add your control notification handler code here
/*	int n=m_sF.Count;
	int* IDs= new int[n];
	if (m_E==NULL) flag=2;
	UpdateData(TRUE);
	BeforExit();
	CString buff, buff2;
	GetDlgItem(IDC_COMBO_SCALE)->GetWindowText(buff);
	m_sF.GetAllID(IDs);
	for (int i=0; i<n; i++)
	{
		m_sF.GetTypeLex(IDs[i],buff2);
		if (buff==buff2) 
		{
			if (m_E->m_scale==NULL)
				m_E->m_scale=m_sF.CreateObject(IDs[i]);
			else
			{
				if (IDs[i]!=m_E->m_scale->GetType())
				{
					delete m_E->m_scale;
					m_E->m_scale=m_sF.CreateObject(IDs[i]);
				}
			}
		}
	}
	delete [] IDs;*/
}

void CExponentDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	int i=m_Name.GetLength();
	GetDlgItem(IDC_EDIT_NAME)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->SetSel(i,i);
	if (m_Rect.bottom==0) GetWindowRect(&m_Rect);
	else MoveWindow(&m_Rect);
}

void CExponentDialog::OnButtonAdv() 
{
	// TODO: Add your control notification handler code here
	CDialogExpAdv dlg;
	dlg.m_E=m_BuffE;
	dlg.DoModal();
}
