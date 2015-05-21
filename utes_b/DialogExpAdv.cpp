// DialogExpAdv.cpp : implementation file
//

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "DialogExpAdv.h"
#include "sys_add_ins.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogExpAdv dialog


CDialogExpAdv::CDialogExpAdv(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogExpAdv::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogExpAdv)
	m_Min = _T("");
	m_Max = _T("");
	//}}AFX_DATA_INIT
}


void CDialogExpAdv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogExpAdv)
	DDX_Text(pDX, IDC_EDIT1, m_Min);
	DDX_Text(pDX, IDC_EDIT2, m_Max);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogExpAdv, CDialog)
	//{{AFX_MSG_MAP(CDialogExpAdv)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogExpAdv message handlers

BOOL CDialogExpAdv::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString buf;
	// TODO: Add extra initialization here
	int i=2;

	i=m_E->GetBestDir();
	switch (i)
	{
	case -1: i=1; break;
	case  1: i=0; break;
	case  0: i=2; break;
	}

	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(i);
	buf.Format("%g",m_E->GetMaxValue());
	m_Max=buf;
	buf.Format("%g",m_E->GetMinValue());
	m_Min=buf;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDialogExpAdv::OnOK() 
{
	// TODO: Add extra validation here
	int i=0;
	double dmax=0;
	double dmin=0;
	UpdateData(TRUE);
	if (GetNumber(m_Min,dmin)) 
	{
		AfxMessageBox("Ошибка ввода числа");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return;
	}
	if (GetNumber(m_Max,dmax)) 
	{
		AfxMessageBox("Ошибка ввода числа");
		GetDlgItem(IDC_EDIT2)->SetFocus();
		return;
	}

	if (dmax<=dmin)
	{
		AfxMessageBox("Максимальное значение должно быть\n"
					  "      больше минимального");
		GetDlgItem(IDC_EDIT1)->SetFocus();
		return;
	}
	m_E->SetMaxValue(dmax);
	m_E->SetMinValue(dmin);

	i=((CComboBox*)GetDlgItem(IDC_COMBO1))->GetCurSel();
	switch (i)
	{
	case  0: m_E->SetBestDir( 1); break;
	case  1: m_E->SetBestDir(-1); break;
	case  2: m_E->SetBestDir( 0); break;
	}
	
	CDialog::OnOK();
}

void CDialogExpAdv::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	GetDlgItem(IDC_EDIT1)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(0,0);
	
}
