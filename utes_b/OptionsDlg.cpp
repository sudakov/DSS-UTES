// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UTES.h"
#include "OptionsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_Slover = _T("");
	m_Code = _T("");
	m_Comp = _T("");
	m_CodeW = _T("");
	//}}AFX_DATA_INIT
}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Slover);
	DDX_Text(pDX, IDC_EDIT2, m_Code);
	DDX_Text(pDX, IDC_EDIT3, m_Comp);
	DDX_Text(pDX, IDC_EDIT4, m_CodeW);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

BOOL COptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString Buf;
	m_c=0;

	// TODO: Add extra initialization here
#ifdef DEMOVER
	m_Code="Демо Версия";
#else
	m_Code.Format("%u",((CUTESApp*)AfxGetApp())->m_Protection.m_ProgID);
	m_Comp.Format("%u",((CUTESApp*)AfxGetApp())->m_Protection.m_CompID);
	if (((CUTESApp*)AfxGetApp())->m_Protection.m_ProgCode!=0)
			m_CodeW.Format("%u",((CUTESApp*)AfxGetApp())->m_Protection.m_ProgCode);

#endif

	if (m_Slover.IsEmpty()) m_Slover="c:\\dss_utes";
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsDlg::OnOK() 
{
	// TODO: Add extra validation here
	char* s;
	char* s2;
	UpdateData(TRUE);
	CString BuffErr;
	s=m_CodeW.GetBuffer(100);
	m_c=strtoul(s,&s2,10);
	m_CodeW.ReleaseBuffer();
	BuffErr=s2;
	BuffErr.TrimLeft(); BuffErr.TrimRight();
	if (!BuffErr.IsEmpty())
	{
		AfxMessageBox("Ошибка ввода числа");
		return;
	}

	CDialog::OnOK();
}
