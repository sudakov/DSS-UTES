//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Scale dialog class
// ScaleDialog.cpp : implementation file
//
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "def_scale.h"
#include "ScaleDialog.h"
#include "ScaleAutoDef.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern const char* def_scale[];

/////////////////////////////////////////////////////////////////////////////
// CScaleDialog dialog


CScaleDialog::CScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CScaleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScaleDialog)
	m_AllGrad = _T("");
	m_Rang = FALSE;
	m_Format = _T("");
	//}}AFX_DATA_INIT
}


void CScaleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScaleDialog)
	DDX_Text(pDX, IDC_EDIT_TERM, m_AllGrad);
	DDX_Check(pDX, IDC_CHECK_RANG, m_Rang);
	DDX_Text(pDX, IDC_EDIT_FORMAT, m_Format);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CScaleDialog, CDialog)
	//{{AFX_MSG_MAP(CScaleDialog)
	ON_BN_CLICKED(IDC_BUTTON_DEFAULT, OnButtonDefault)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDC_BUTTON_AUTO, OnButtonAuto)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScaleDialog message handlers

void CScaleDialog::OnButtonDefault() 
{
	int i;
	m_AllGrad="";
	for (i=0; i<15; i++)
	{
		m_AllGrad=m_AllGrad+def_scale[i]+"\r\n";
	}
	UpdateData(FALSE);
}

BOOL CScaleDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CScaleFactory f;
	POSITION pos;
	CString buff;

	f.GetTypeLex(m_pScale->GetType(),buff);
	SetWindowText("Редактор шкалы (тип:"+buff+")");
	switch (m_pScale->GetType())
	{
	case SCALE_PREFERENCE:
		GetDlgItem(IDC_STATIC_P1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_P2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_DEFAULT)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_CHECK_RANG)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FBORDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FORMAT)->ShowWindow(SW_HIDE);
		break;
	case SCALE_LEXICAL:
		GetDlgItem(IDC_STATIC_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_P2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DEFAULT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_AUTO)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_CHECK_RANG)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FBORDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FORMAT)->ShowWindow(SW_HIDE);
		break;
	case SCALE_INTERVAL:
	case SCALE_DISCRET:
		GetDlgItem(IDC_STATIC_P1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_P2)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DEFAULT)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_CHECK_RANG)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FBORDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_FORMAT)->ShowWindow(SW_SHOW);
	}
	pos=m_pScale->m_Lex.GetHeadPosition();
	while (pos!=NULL)
			m_AllGrad=m_AllGrad+m_pScale->m_Lex.GetNext(pos)+"\r\n";
	m_Rang=m_pScale->m_Rang;
	m_Format=m_pScale->m_Format;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CScaleDialog::OnOK() 
{
	// TODO: Add extra validation here
	typedef CArray<double, double&> CDoubleArray;
	int index;
	int n=m_pScale->m_Lex.GetCount();
	int nn=0;
	POSITION pos;
	CStringList BuffList;
	CDoubleArray x;
	char* s; char* s2; 
	CString Buff;
	CString BuffErr;

	UpdateData(TRUE);
	m_AllGrad.TrimLeft(); m_AllGrad.TrimRight();
	while (!m_AllGrad.IsEmpty())
	{
		if ((index=m_AllGrad.Find("\r\n"))!=-1)
		{
			Buff=m_AllGrad.Left(index);
			m_AllGrad=m_AllGrad.Mid(index+2);
		}
		else 
		{
			Buff=m_AllGrad;
			m_AllGrad.Empty();
		}
		Buff.TrimLeft(); Buff.TrimRight();
		if (Buff.IsEmpty())
		{
			AfxMessageBox("Ошибка. Введена пустая градация");
			GetDlgItem(IDC_EDIT_TERM)->SetFocus();
			index=((CEdit*)GetDlgItem(IDC_EDIT_TERM))->LineIndex(BuffList.GetCount());
			((CEdit*)GetDlgItem(IDC_EDIT_TERM))->SetSel(index,index);
			return;
		}
		BuffList.AddTail(Buff);
	}
	if (BuffList.GetCount()<2)
	{
		AfxMessageBox("Число градаций не может быть меньше двух");
		GetDlgItem(IDC_EDIT_TERM)->SetFocus();
		return;
	}
	x.SetSize(BuffList.GetCount());
	UpdateData(TRUE);
	if ((m_pScale->m_Type==SCALE_DISCRET)||(m_pScale->m_Type==SCALE_INTERVAL))
	{
		pos=BuffList.GetHeadPosition();
		while (pos!=NULL)
		{
			Buff=BuffList.GetNext(pos);
			if ((Buff=="INF")||(Buff=="+INF")) x[nn]=HUGE_VAL;
			else
			{
				if (Buff=="-INF") x[nn]=-HUGE_VAL;
				else
				{
					s=Buff.GetBuffer(100);
					x[nn]=strtod(s,&s2);
					//TRACE("End string %s", s2);
					Buff.ReleaseBuffer();
					BuffErr=s2;
					BuffErr.TrimLeft(); BuffErr.TrimRight();
					if (!BuffErr.IsEmpty())
					{
						pos=NULL;
						AfxMessageBox("Ошибка ввода числа");
						index=m_AllGrad.Find(BuffErr);
						GetDlgItem(IDC_EDIT_TERM)->SetFocus();
						((CEdit*)GetDlgItem(IDC_EDIT_TERM))->SetSel(index,index);
						return;
					}
				}
			}
			if ((nn)&&(x[nn-1]>=x[nn]))
			{
				pos=NULL;
				AfxMessageBox("Ошибочная последовательность числел");
				index=m_AllGrad.Find(Buff);
				GetDlgItem(IDC_EDIT_TERM)->SetFocus();
				((CEdit*)GetDlgItem(IDC_EDIT_TERM))->SetSel(index,index);
				return;
			}
			nn++;
		}
	}

	if ((m_pScale->m_Type==SCALE_DISCRET)||(m_pScale->m_Type==SCALE_INTERVAL))
	{
		m_pScale->m_Count=nn;
		if (m_pScale->m_Numbers!=NULL) delete [] m_pScale->m_Numbers;
		m_pScale->m_Numbers=new double[nn];
		for (int i=0; i<nn; i++) m_pScale->m_Numbers[i]=x[i];
	}
	else nn=BuffList.GetCount();
	
	if ((nn!=n)&&(n))
	{
		if (AfxMessageBox("Число градаций шкалы изменилось",MB_OKCANCEL)==IDCANCEL)
		{
			GetDlgItem(IDC_EDIT_TERM)->SetFocus();
			return;
		}
	}
	m_pScale->m_Rang=m_Rang;
	m_pScale->m_Format=m_Format;
	m_pScale->m_Lex.RemoveAll();
	pos=BuffList.GetHeadPosition();
	while (pos!=NULL)
		m_pScale->m_Lex.AddTail(BuffList.GetNext(pos));
	CDialog::OnOK();
}




void CScaleDialog::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	int i=m_AllGrad.GetLength();
	GetDlgItem(IDC_EDIT_TERM)->SetFocus();
	((CEdit*)GetDlgItem(IDC_EDIT_TERM))->SetSel(i,i);
	
}

void CScaleDialog::OnButtonAuto() 
{
	// TODO: Add your control notification handler code here
	CScaleAutoDef dlg;
	double x;
	CString buff;
	dlg.m_Max="";
	dlg.m_Min="";
	dlg.m_Step="";
	if (dlg.DoModal()==IDOK)
	{
		m_AllGrad="";
		x=dlg.m_dMin;
		while (x<=dlg.m_dMax)
		{
			buff.Format("%g",x);
			m_AllGrad+=buff+"\r\n";
			x+=dlg.m_dStep;
		}
		UpdateData(FALSE);
	}
}
