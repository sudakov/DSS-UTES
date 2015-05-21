//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1997/1998 Russia
//---------------------------------------------------------------------------
// Author: Vladimir_Sudakov
// Description: Group of criterion description implemention
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Exponent.h"
#include "CGroup.h"
#include "GroupSet.h"
#include "def_scale.h"

IMPLEMENT_SERIAL(CGroup, CObject, 1)

CGroup::CGroup()
{
	m_Grad=15;
	m_GColor=RGB(255,255,255);
	for (int i=0; i<10; i++) m_v[i]=0;
	CString buff;
	for (i=0; i<m_Grad; i++) 
	{
		buff=def_scale[i];
		m_Scale.AddTail(buff);
	}
}

CGroup::~CGroup()
{
	m_P.RemoveAll();
	m_Scale.RemoveAll();
}


void CGroup::Serialize(CArchive& ar)
{
	int i,n;
	if (!ar.IsStoring()) m_Scale.RemoveAll();
	m_cc.Serialize(ar);
	m_P.Serialize(ar);
	m_Scale.Serialize(ar);
	n=m_cc.GetCount();
	if (ar.IsStoring())
	{
		ar <<  m_Name << m_Grad << (DWORD) m_GColor;
		for (i=0; i<n; i++) ar << m_v[i];
	}
	else
	{
		ar >>  m_Name >> m_Grad >> (DWORD) m_GColor;
		for (i=0; i<n; i++) ar >> m_v[i];
	}
}

int CGroup::DialogSet(CStringList *pAllC)
{
	CGroupSet D;
	
	D.m_Name=m_Name;
	D.m_grad=m_Grad;
	D.m_pAllC=pAllC;
	D.m_pSelC=&m_cc;
	D.m_Color=m_GColor;
	D.m_pScale=&m_Scale;
	if (D.DoModal()==IDOK) 
	{
		m_Name=D.m_Name;
		m_Grad=D.m_grad;
		m_GColor=D.m_Color;
		return 1;
	}
	return 0;
}

int CGroup::RemoveCriterion(CString c)
{
	POSITION pos=m_cc.Find(c);
	if (pos==NULL) return 0;
	m_cc.RemoveAt(pos);
	return 1;
}
	
int CGroup::FindCriterion(CString c)
{
	if (m_cc.Find(c)==NULL) return 0;
	return 1;
}

void CGroup::SetCritDim(int *v)
{
	int s=1;
	int n=m_cc.GetCount();
	for (int i=0; i<n; i++)
	{
		m_v[i]=v[i];
		s*=m_v[i];
	}
	m_P.RemoveAll();
	m_P.SetSize(s);
	for (i=0; i<s; i++) m_P[i]=255;
}

void CGroup::SetPreference(int *i, int p)
{
	int index=0;
	int n=m_cc.GetCount();
	int s=1;
	for (int j=0; j<n; j++)
	{
		index+=s*i[j];
		s*=m_v[j];
	}
	m_P[index]=p;
}

int CGroup::GetPreferance(int *i)
{
	int index=0;
	int n=m_cc.GetCount();
	int s=1;
	for (int j=0; j<n; j++)
	{
		index+=s*i[j];
		s*=m_v[j];
	}
	return m_P[index];
}

void CGroup::GetCritDim(int *v)
{
	int n = m_cc.GetCount();
	for (int i=0; i<n; i++)	v[i] = m_v[i];
}

CString CGroup::GetLex(int index)
{
	CString Buff;
	if (index<m_Grad)
		Buff=m_Scale.GetAt(m_Scale.FindIndex(index));
	else Buff="Не определено";
	return Buff;
}

double CGroup::GetValue()
{
	return -1.0;
}

int CGroup::Estimate()
{
	int v[10];
	for (int i=0; i<m_cc.GetCount(); i++)
	{
		v[i]=((CExponent*)m_c[i])->Estimate();
		if (v[i]==-1) return -1;
	}
	return GetPreferance(v);
}
