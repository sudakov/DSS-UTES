// DialogSelMethod.cpp : implementation file
//

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "DialogSelMethod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogSelMethod dialog


CDialogSelMethod::CDialogSelMethod(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSelMethod::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogSelMethod)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CDialogSelMethod::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogSelMethod)
	DDX_Control(pDX, IDC_LIST_METHODS, m_ListMethod);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogSelMethod, CDialog)
	//{{AFX_MSG_MAP(CDialogSelMethod)
	ON_BN_CLICKED(IDC_BUTTON_OPTIONS, OnButtonOptions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogSelMethod message handlers

BOOL CDialogSelMethod::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_pE==NULL) return TRUE;
	if (m_pE->GetType()!=EXPONENT_GROUP) return TRUE;
	m_Name=m_pE->GetName();
	m_pM=NULL;
	CMethodFactory f;
	CString Buff;
	int j=0;
	int ids[20];
	int count=f.GetAllID(ids);
	for (int i=0; i<count; i++)
	{
		if (f.GetTypeLex(ids[i],Buff)) AfxMessageBox("Ошибка в определении имени метода");
		else 
		{
			m_ListMethod.AddString(Buff);
			if (m_pE->m_Method!=NULL)
			{
				if (m_pE->m_Method->GetType()==ids[i]) j=i;
			}
		}
	}
	m_ListMethod.SetCurSel(j);
	m_pM = f.CreateObject(ids[j]);
	m_pM->m_pE = m_pE;
	if ((m_pE->m_Method!=NULL)&&(m_pM->GetType()==m_pE->m_Method->GetType()))
	{
		switch(m_pM->GetType())
			{
			case METHOD_PREFERENCE: 
				*((CMethodPR*)m_pM)=*((CMethodPR*)m_pE->m_Method);
				break;
			case METHOD_WEIGHT:
				*((CMethodWE*)m_pM)=*((CMethodWE*)m_pE->m_Method);
				break;
			case METHOD_POINT:
				*((CMethodIP*)m_pM)=*((CMethodIP*)m_pE->m_Method);
				break;
			};
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialogSelMethod::OnOK() 
{
	// TODO: Add extra validation here
	int j=m_ListMethod.GetCurSel();
	CMethodFactory f;
	int IDs[20];
	int count=f.GetAllID(IDs);
	if (m_pE->m_Method==NULL) 
	{
		m_pE->m_Method=f.CreateObject(IDs[j]);
	}
	else
	{
		if (IDs[j]!=m_pE->m_Method->GetType())
		{
			delete m_pE->m_Method;
			m_pE->m_Method=NULL;
			m_pE->m_Method=f.CreateObject(IDs[j]);
		}
	}
	if (m_pE->m_Method!=NULL) 
	{
		if ((m_pM!=NULL)&&(m_pM->GetType()==IDs[j]))
		{
			switch(m_pM->GetType())
			{
			case METHOD_PREFERENCE: 
				*((CMethodPR*)m_pE->m_Method)=*((CMethodPR*)m_pM);
				break;
			case METHOD_WEIGHT:
				*((CMethodWE*)m_pE->m_Method)=*((CMethodWE*)m_pM);
				break;
			case METHOD_POINT:
				*((CMethodIP*)m_pE->m_Method)=*((CMethodIP*)m_pM);
				break;
			};
		}
		m_pE->m_Method->m_pE=m_pE;
	}
	if (m_pM!=NULL) delete m_pM;
	CDialog::OnOK();
}

void CDialogSelMethod::OnButtonOptions()
{
	// TODO: Add your control notification handler code here
	int j=m_ListMethod.GetCurSel();
	CMethodFactory f;
	int IDs[20];
	int count=f.GetAllID(IDs);
	if ((m_pM==NULL)||(IDs[j]!=m_pM->GetType())) 
	{
		if (m_pM!=NULL) delete m_pM;
		m_pM = f.CreateObject(IDs[j]);
		m_pM->m_pE=m_pE;
	}
	/*if ((m_pE->m_Method!=NULL)&&(m_pM->GetType()==m_pE->m_Method->GetType()))
	{
		switch(m_pM->GetType())
			{
			case METHOD_PREFERENCE: 
				*((CMethodPR*)m_pM)=*((CMethodPR*)m_pE->m_Method);
				break;
			case METHOD_WEIGHT:
				*((CMethodWE*)m_pM)=*((CMethodWE*)m_pE->m_Method);
				break;
			};
	}*/
	if (m_pM->SetOptions()) AfxMessageBox("Метод не поддерживает дополнительную настройку");
}

void CDialogSelMethod::OnCancel() 
{
	// TODO: Add extra cleanup here
	if (m_pM!=NULL) delete m_pM;	
	CDialog::OnCancel();
}
