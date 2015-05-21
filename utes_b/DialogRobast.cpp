// DialogRobast.cpp : implementation file
//

#include "stdafx.h"
#include "UTES.h"
#include <atlbase.h>
#include "sys_add_ins.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "DialogRobast.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogRobast dialog


CDialogRobast::CDialogRobast(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogRobast::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogRobast)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogRobast::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogRobast)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogRobast, CDialog)
	//{{AFX_MSG_MAP(CDialogRobast)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogRobast message handlers

BOOL CDialogRobast::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString buf;
	// TODO: Add extra initialization here
	if (m_pMethod->m_is_number)
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(0);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(1);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(1);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(0);
	}
	if (m_pMethod->m_robast<m_pMethod->m_pE->GetNumGrad()) buf.Format("%i", m_pMethod->m_pE->GetNumGrad());
	else buf.Format("%i", m_pMethod->m_robast);
	SetDlgItemText(IDC_EDIT1, buf);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialogRobast::OnOK() 
{
	// TODO: Add extra validation here
	CString buf="";
	int i_buf;
	GetDlgItemText(IDC_EDIT1,buf);
	if (GetNumberInt(buf, i_buf))
	{
		AfxMessageBox("Ошибка ввода числа градаций");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return;
	}
	if (i_buf<0)
	{
		AfxMessageBox("Число градаций должно быть положительным");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return;
	}
	if (i_buf>254)
	{
		AfxMessageBox("Число градаций не может быть больше 254");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return;
	}
	
	m_pMethod->m_robast=i_buf;
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck()==1) m_pMethod->m_is_number=FALSE;
	else m_pMethod->m_is_number=TRUE;
	CDialog::OnOK();
}
