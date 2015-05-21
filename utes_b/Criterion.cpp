#include "stdafx.h"
#include "CritDialog.h"
#include "Exponent.h"
#include "Criterion.h"

IMPLEMENT_SERIAL(CCrit, CObject, 1)

CCrit::CCrit()
{
	pC=new CCriterion();
	m_vd=0.0;
	m_vi=0;
}

CCrit::~CCrit()
{
	delete pC;
}

int CCrit::GetType()
{
  return pC->GetType();
}

CString CCrit::GetName()
{
	return pC->GetName();
}

int  CCrit::GetGradation()
{
	return pC->GetGradation();
}

CString CCrit::GetLex(int index)
{
	return pC->GetLex(index);
}

int CCrit::DialogSet()
{
	return pC->DialogEdit();
}

void  CCrit::Serialize(CArchive& ar)
{
  pC->Serialize(ar);
}


double CCrit::GetValue()
{
	return m_vd;
}

int CCrit::SetValue(COleVariant v)
{
	switch (v.vt)
	{
	case VT_BSTR:
		if (pC->GetType()==CRITERION_LEXICAL)
		{
			CString buff,vs;
			vs=v.bstrVal;
			vs.TrimRight(); vs.TrimLeft();
			for (int i=0; i<pC->GetGradation(); i++)
			{
				buff=pC->GetLex(i);
				buff.TrimRight(); buff.TrimLeft();
				if (buff==vs) break;
			}
			if (buff==vs) m_vi=i;
			else { m_vi=-1; return 0;}
			TRACE("\ni=%i",i);
			return 1;
		}
		break;
	case VT_I2:			// 2-byte signed int.
	case VT_I4:			// 4-byte signed int.
	case VT_R4:			// 4-byte real.
	case VT_R8:			// 8-byte real.
		if (pC->GetType()>CRITERION_LEXICAL)
		{
			v.ChangeType(VT_R8);
			m_vd=v.dblVal;
			return 1;
		}
	}
	return 0;
}

int CCrit::Estimate()
{
	int type=pC->GetType();
	if (type==CRITERION_LEXICAL) return m_vi;
	int n=pC->GetGradation();
	if ((type==CRITERION_INTERVAL)||(type==CRITERION_NONLIMITED))
	{
		int rez=pC->GetIndex(m_vd);
		if (rez>=n) return n-1;
		else return rez;
	}

	//CRITERION_DISCRET
	double* p=new double[n+3];
	TRACE("\nNAME:%s\n", pC->GetName());
	pC->GetPoints(p);
	
	for (int i=0; i<n; i++)
	{
		if ((i==0)&&(m_vd<=p[i])) break;
		if ((i>0)&&(i<(n-1)))
			if ((((p[i-1]+p[i])/2)<=m_vd)&&(m_vd<((p[i]+p[i+1])/2)))
				break;
		if ((i==(n-1))&&(((p[i-1]+p[i])/2)<=m_vd)) break;
	}
	delete [] p;
	if (i<n) return i;
	//Error
	return -1;	
}
