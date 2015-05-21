//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Scale class implementation
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "math.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "ScaleDialog.h"
#include "sys_add_ins.h"

IMPLEMENT_SERIAL(CScale, CObject, 1)

CScale::CScale()
{
	m_Count=0;
	m_Type=0;
	m_Format="%g";
	m_Numbers=NULL;
	m_Rangs=NULL;
	m_Rang=FALSE;
	m_Lex.RemoveAll();
}

CScale::CScale(int Type)
{
	m_Count=0;
	m_Type=Type;
	m_Format="%g";
	m_Numbers=NULL;
	m_Rangs=NULL;
	m_Rang=FALSE;
	m_Lex.RemoveAll();
}

CScale::~CScale()
{
	if (m_Numbers!=NULL) delete [] m_Numbers;
	if (m_Rangs!=NULL) delete [] m_Rangs;
	m_Lex.RemoveAll();
}


// if number type this function return string represantion
CString CScale::GetLex(int index)
{
	CString Buff="";
	if (index>=m_Lex.GetCount()) return "Н/О";
	switch (m_Type)
	{
	case SCALE_LEXICAL:
	case SCALE_PREFERENCE:
		return m_Lex.GetAt(m_Lex.FindIndex(index));
	case SCALE_DISCRET:
		Buff.Format(m_Format,atof(m_Lex.GetAt(m_Lex.FindIndex(index))));
		return Buff;
	case SCALE_INTERVAL:
		Buff.Format("("+m_Format+","+m_Format+")",
			        atof(m_Lex.GetAt(m_Lex.FindIndex(index))),
					atof(m_Lex.GetAt(m_Lex.FindIndex(index+1))));
		return Buff;
	}
	return "-666";
}
	
int CScale::DialogEdit()
{
	CScaleDialog dlg;
	dlg.m_pScale=this;
	return dlg.DoModal();
}

int CScale::GetType()
{
	return m_Type;
}

// Estimation functions
int CScale::GetIndex(COleVariant v,int& ind, CMethod* pM)
{
	double x=0;
	int i=0;
	int n;
	switch (v.vt)
	{
	case VT_BSTR:
		if (m_Type==SCALE_LEXICAL)
		{
			CString buff,vs;
			vs=v.bstrVal;
			vs.TrimRight(); vs.TrimLeft();
			POSITION pos=m_Lex.GetHeadPosition();
			while (pos!=NULL)
			{
				buff=m_Lex.GetNext(pos);
				if (buff==vs) 
				{
					ind=i;
					return 0;
				}
				i++;
			}
			return -1;
		}
		else return -1;
	case VT_I2:			// 2-byte signed int.
	case VT_I4:			// 4-byte signed int.
	case VT_R4:			// 4-byte real.
	case VT_R8:			// 8-byte real.
		v.ChangeType(VT_R8);
		x=v.dblVal;
		if ((pM!=NULL)&&(pM->GetType()==METHOD_PREFERENCE)&&(x<(((CMethodPR*)pM)->m_robast)))
		{
			if (((CMethodPR*)pM)->m_robast!=0) x=floor(x*GetGradation()/((CMethodPR*)pM)->m_robast);
		}
		n=m_Lex.GetCount();
		if (m_Numbers==NULL)
		{
			m_Numbers=new double [n];
			POSITION pos=m_Lex.GetHeadPosition();
			while (pos!=NULL)
				m_Numbers[i++]=atof(m_Lex.GetNext(pos));
		}
		switch (m_Type)
		{
		case SCALE_INTERVAL:
			for (i=0; i<(n-1); i++)
				if (((m_Numbers[i]<=x)&&(x<m_Numbers[i+1]))||
					((i==(n-2))&&(x<=m_Numbers[n-1])))
				{
					ind=i;
					return 0;
				}
			return -1;
		case SCALE_DISCRET:
			for (i=0; i<n; i++)
			{
				if ((i==0)&&(x<((m_Numbers[i]+m_Numbers[i+1])/2.0))) break;
				if ((i>0)&&(i<(n-1)))
					if ((((m_Numbers[i-1]+m_Numbers[i])/2.0)<=x)&&
						(x<((m_Numbers[i]+m_Numbers[i+1])/2.0)))
						break;
				if ((i==(n-1))&&(((m_Numbers[i-1]+m_Numbers[i])/2.0)<=x)) break;
			}
			if (i>=n) return -1;
			ind=i;
			return 0;
		case SCALE_PREFERENCE:
			if (m_Rangs==NULL)
			{
				ind=(int) x;
				return 0;
			}
			for (i=0; i<n; i++)
				if (m_Rangs[i]==x)
				{
					ind=i;
					return 0;
				}
			return -1;
		}
	}
	return -1;
}

int CScale::GetNearest(COleVariant v,int& ind)
{
	return -1;
}

int CScale::GetRang(int ind, double& r)
{
	if (m_Rangs==NULL) return -1;
	r=m_Rangs[ind];
	return 0;
}

// overloading save and load procedures
void CScale::Serialize(CArchive& ar)
{
	m_Lex.Serialize(ar);
	int i=0;
	int n=m_Lex.GetCount();
	if (ar.IsStoring())
	{
		ar << m_Type << m_Format << m_Rang;
		if (m_Rang)
			for (i=0; i<n; i++)	ar << m_Rangs[i];

	}
	else
	{
		ar >> m_Type >> m_Format >> m_Rang;
		if (m_Rang)
		{
			m_Rangs=new double[n];
			for (i=0; i<n; i++)	ar >> m_Rangs[i];
		}
	}
}

int CScale::GetGradation()
{
	if (m_Type==SCALE_INTERVAL) return m_Lex.GetCount()-1;
	return m_Lex.GetCount();
}

int CScale::GetRange(double& a, double& b)
{
	a=0; b=0;
	if ((m_Type==SCALE_INTERVAL)||(m_Type==SCALE_DISCRET))
	{	
		if ((GetNumber(m_Lex.GetHead(),a))||
			(GetNumber(m_Lex.GetTail(),b))) return -1;
	}
	else
		b=m_Lex.GetCount()-1;
	return 0;
}

CScale& CScale::operator=(const CScale& other)
{
	m_Lex.RemoveAll();
	POSITION pos=other.m_Lex.GetHeadPosition();
	while (pos!=NULL)
		m_Lex.AddTail(other.m_Lex.GetNext(pos));
	m_Type=other.m_Type;
	m_Format=other.m_Format;
	m_Rang=other.m_Rang;
	if (m_Rang)
	{	
		int n=m_Lex.GetCount();
		if (m_Rangs!=NULL) delete m_Rangs;
		m_Rangs=new double[n];
		for (int i=0; i<n; i++)	m_Rangs[i]=other.m_Rangs[i];
	}
	m_Numbers=NULL;	
	m_Count=0;
	return *this;
}

void CScale::SetGradation(LPCTSTR lpsz_grad)
{
	if (lpsz_grad == NULL)
		return;
	
	int n = m_Lex.GetCount();
	if (m_Lex.AddTail(lpsz_grad) == NULL)
	{
//		AfxMessageBox("Ошибка при добавлении градации");
		return;
	}

	m_Count = n + 1;
}