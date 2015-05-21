//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Exponent class implementation
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "UTESDoc.h"

IMPLEMENT_SERIAL(CExponent, CObject, VERSIONABLE_SCHEMA|3)

CExponent::CExponent()
{
	m_scale=NULL;
	m_Name="";
	m_Description="";
	m_Type=EXPONENT_LEXICAL;
	m_dValue=0;
	m_iValue=0;
	m_IsSet=false;
	m_Grad=0;
	m_Method=NULL;
	m_dMaxValue=0;
	m_dMinValue=0;
	m_iDirBest=0;
	m_id=0;
}

CExponent::CExponent(int Type)
{
	m_scale=NULL;
	m_Name="";
	m_Description="";
	m_dValue=0;
	m_iValue=0;
	m_IsSet=false;
	m_Grad=0;
	m_Type=Type;
	m_Method=NULL;
	m_dMaxValue=0;
	m_dMinValue=0;
	m_iDirBest=0;
	m_id=0;
}

CExponent::~CExponent()
{
	if (m_scale!=NULL) delete m_scale;
	if (m_Method!=NULL) delete m_Method;
}
	
int CExponent::DialogSet()
{
	return IDOK;
}

int CExponent::DialogEdit()
{
	return IDOK;
}

int CExponent::SetValue(COleVariant v)
{
	switch(m_Type)
	{
	case EXPONENT_LEXICAL:
		if (m_scale==NULL) return -1;
		if (m_scale->GetIndex(v,m_iValue, m_Method)) return -1;
		m_IsSet=true;
		return 0;
	case EXPONENT_NUMBER:
		if ((v.vt==VT_I2)||(v.vt==VT_I4)||(v.vt==VT_R4)||(v.vt==VT_R8))
		{
			v.ChangeType(VT_R8);
			m_dValue=v.dblVal;
			if (m_scale!=NULL)
				if (m_scale->GetIndex(v,m_iValue, m_Method)) return -1;
			m_IsSet=true;
			return 0;
		}
		else return -1;
	}
	return -1;
}

void CExponent::ClearValue()
{
	m_IsSet=false;
}

int CExponent::GetValue(double& v)
{
	double r;
	switch(m_Type)
	{
	case EXPONENT_LEXICAL:
		if (!m_IsSet) 
		{
			GetMyDoc()->m_err_msg="Значение показателя "+GetName()+" не задано";
			return -1;
		}
		if (m_scale->GetRang(m_iValue,r)) v=(double) m_iValue;
		else v = r;
		return 0;
	case EXPONENT_NUMBER:
		if (!m_IsSet) 
		{
			GetMyDoc()->m_err_msg="Значение показателя "+GetName()+" не задано";
			return -1;
		}
		v=m_dValue;
		return 0;
	case EXPONENT_GROUP:
		if (m_Method==NULL) 
		{
			GetMyDoc()->m_err_msg="Метод свертки для показателя "+GetName()+" не задан";
			return -1;
		}
		if (m_Method->GetValue(m_dValue)) return -1;
		v=m_dValue;
		return 0;
	}
	return -1;
}

int CExponent::GetLex(CString& v)
{
	return -1;
}

int CExponent::GetGradation(int& Index)
{
	if (m_scale==NULL) return -1;
	switch(m_Type)
	{
	case EXPONENT_LEXICAL:
	case EXPONENT_NUMBER:
		if (!m_IsSet)	return -1;
		break;
	case EXPONENT_GROUP:
		if (m_Method==NULL) return -1;
		if (m_Method->GetValue(m_dValue)) return -1;
		if (m_scale->GetIndex(COleVariant(m_dValue),m_iValue, m_Method)) return -1;
		break;
	default:
		return -1;
	}
	Index=m_iValue;
	return 0;
}


int CExponent::GetNearestGradation(int& Index)
{
	return 0;
}

int CExponent::GetNumGrad()
{
	if (m_scale==NULL) return 0;
	return m_scale->GetGradation();
}

// overloading save and load procedures
void CExponent::Serialize(CArchive& ar)
{
	UINT t=0;
	if (ar.IsStoring())
	{
		if (m_Method!=NULL) t=m_Method->GetType();
		ar << m_Name << m_Description << m_Grad << m_Type << m_scale << t << m_dMaxValue << m_dMinValue << m_iDirBest << m_id;
		if (m_Method!=NULL) m_Method->SerializeNew(ar);
	}
	else
	{
		int nVersion = ar.GetObjectSchema();

		switch(nVersion)
		{
		case 1:
			// read in previous version of 
			// this object
			ar >>  m_Name >> m_Description >> m_Grad >> m_Type >> m_scale >> t;
			break;
		case 2:
			ar >>  m_Name >> m_Description >> m_Grad >> m_Type >> m_scale >> t >> m_dMaxValue >> m_dMinValue >> m_iDirBest;
			break;
		case 3:
			// read in current version of
			// this object
			ar >>  m_Name >> m_Description >> m_Grad >> m_Type >> m_scale >> t >> m_dMaxValue >> m_dMinValue >> m_iDirBest >> m_id;
			break;
		default:
         // report unknown version of 
         // this object
			TRACE("unknown version!!!");
			break;
		}
   		if (t)
		{
			CMethodFactory f;
			m_Method=f.CreateObject(t);
			if (nVersion<3) m_Method->Serialize(ar);
			else m_Method->SerializeNew(ar);
			m_Method->m_pE=this;
		}
	};
}

CExponent& CExponent::operator=(CExponent& other)
{
	int num=0;
	m_Name=other.m_Name;
	m_Description=other.m_Description;
	m_Grad=other.m_Grad;
	m_Type=other.m_Type;
	m_dMaxValue=other.m_dMaxValue;
	m_dMinValue=other.m_dMinValue;
	m_iDirBest=other.m_iDirBest;
	m_id=other.m_id;
	CScaleFactory sf;
	if (m_scale!=NULL)
	{
		delete m_scale;
		m_scale=NULL;
	}
	if (other.m_scale!=NULL)
	{
		m_scale=sf.CreateObject(other.m_scale->GetType());
		*m_scale=*other.m_scale;
	}
	CMethodFactory f;
	if (m_Method!=NULL)
	{
		delete m_Method;
		m_Method=NULL;
	}

	if (other.m_Method!=NULL)
	{
		m_Method=f.CreateObject(other.m_Method->GetType());
		switch(m_Method->GetType())
		{
		case METHOD_PREFERENCE: 
			*((CMethodPR*)m_Method)=*((CMethodPR*)other.m_Method);
			break;
		case METHOD_WEIGHT:
			*((CMethodWE*)m_Method)=*((CMethodWE*)other.m_Method);
			break;
		};
		m_Method->m_pE=this;
		num=m_agr.GetCount();
	}
	m_agr.RemoveAll();
	POSITION pos=other.m_agr.GetHeadPosition();
	while (pos!=NULL) m_agr.AddTail(other.m_agr.GetNext(pos));
	if ((m_Method!=NULL)&&
		(m_Method->GetType()==METHOD_PREFERENCE)&&
		(num)&&(num!=m_agr.GetCount()))
		((CMethodPR*)m_Method)->SetCritDim();

	return *this;
}

void CExponent::SetType(int t) 
{ 
	if ((m_Type==EXPONENT_GROUP)&&
		(t!=EXPONENT_GROUP))
	{
		m_agr.RemoveAll();
		if (m_Method!=NULL)
		{
			delete m_Method;
			m_Method=NULL;
		}
	}
	m_Type=t;
}

