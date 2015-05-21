// ScaleAutoDef.cpp : implementation file
//

#include "stdafx.h"
#include "UTES.h"
#include "ScaleAutoDef.h"
#include "sys_add_ins.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScaleAutoDef dialog


CScaleAutoDef::CScaleAutoDef(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleAutoDef::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleAutoDef)
	m_Max = _T("");
	m_Min = _T("");
	m_Step = _T("");
	//}}AFX_DATA_INIT
}


void CScaleAutoDef::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleAutoDef)
	DDX_Text(pDX, IDC_EDIT_MAX, m_Max);
	DDX_Text(pDX, IDC_EDIT_MIN, m_Min);
	DDX_Text(pDX, IDC_EDIT_STEP, m_Step);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScaleAutoDef, CDialog)
	//{{AFX_MSG_MAP(CScaleAutoDef)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScaleAutoDef message handlers

void CScaleAutoDef::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if (GetNumber(m_Min, m_dMin))
	{
		AfxMessageBox("Ошибка ввода минимума");
		return;
	}
	if (GetNumber(m_Max, m_dMax))
	{
		AfxMessageBox("Ошибка ввода максимума");
		return;
	}
	if (GetNumber(m_Step, m_dStep))
	{
		AfxMessageBox("Ошибка ввода шага");
		return;
	}
	if (m_dStep<=0)
	{
		AfxMessageBox("Ошибка! Отрицательный или нулевой шаг");
		return;
	}
	if (m_dMax<=m_dMin)
	{
		AfxMessageBox("Ошибка! Максимум должен быть строго больше минимума");
		return;
	}

	CDialog::OnOK();
}
