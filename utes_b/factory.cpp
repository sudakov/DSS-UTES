//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Factory that generates exponent and scale objects
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "Factory.h"

const strcType all_crit[]=
				{	{EXPONENT_LEXICAL,"Лексический"},
    				{EXPONENT_NUMBER,"Числовой"},
					{EXPONENT_GROUP,"Обобщенный"}
				};

CExponentFactory::CExponentFactory()
{
	Count=3;
}

CExponentFactory::~CExponentFactory()
{
	;
}

CExponent* CExponentFactory::CreateObject(int Type)
{
	switch(Type)
	{   
	case EXPONENT_LEXICAL: return new CExponent(Type);
	case EXPONENT_NUMBER:  return new CExponent(Type);
	case EXPONENT_GROUP:   return new CExponent(Type);
	};
	return NULL;
}
	
int CExponentFactory::GetTypeLex(int Type,CString& Name)
{
	for (int i=0; i<Count; i++)
	{
		if (all_crit[i].ID==Type) 
		{
			Name=all_crit[i].Name;
			return 0;	//if successful
		}
	}
	return -1;
}

int CExponentFactory::GetAllID(int* IDs)
{
	for (int i=0; i<Count; i++)
	{
		IDs[i]=all_crit[i].ID;
	}
	return Count; // return number of types
}


const strcType all_scale[]=
			   {{SCALE_INTERVAL,"Интервальная"},
				{SCALE_DISCRET,"Точечная"},
				{SCALE_LEXICAL,"Символьная"},
				{SCALE_PREFERENCE,"Предпочтений"}};

CScaleFactory::CScaleFactory()
{
	Count=4;
}

CScaleFactory::~CScaleFactory()
{
	;
}

CScale* CScaleFactory::CreateObject(int Type)
{
	switch(Type)
	{
	case SCALE_INTERVAL:	return new CScale(Type);
	case SCALE_DISCRET:		return new CScale(Type);
	case SCALE_LEXICAL:		return new CScale(Type);
	case SCALE_PREFERENCE:	return new CScale(Type);
	};
	return NULL;
}
	
int CScaleFactory::GetTypeLex(int Type,CString &Name)
{
	for (int i=0; i<Count; i++)
	{
		if (all_scale[i].ID==Type) 
		{
			Name=all_scale[i].Name;
			return 0;	//if successful
		}
	}
	return -1; //not found
}

int CScaleFactory::GetAllID(int* IDs)
{
	for (int i=0; i<Count; i++)
	{
		IDs[i]=all_scale[i].ID;
	}
	return Count;					// return number of types
};

int CScaleFactory::GetAllForType(int ExpType,int* IDs)
{
	switch (ExpType)
	{
		case EXPONENT_LEXICAL:
			IDs[0]=SCALE_LEXICAL;
			return 1;
		case EXPONENT_NUMBER:
			IDs[0]=SCALE_DISCRET;
			IDs[1]=SCALE_INTERVAL;
			return 2;
		case EXPONENT_GROUP:
			IDs[0]=SCALE_PREFERENCE;
			IDs[1]=SCALE_DISCRET;
			IDs[2]=SCALE_INTERVAL;
			return 3;
	}
	return 0;
}


const strcType all_method[]=
				{	{METHOD_PREFERENCE,"Функция предпочтения"},
    				{METHOD_WEIGHT,"Взвешенная сумма"},
					{METHOD_POINT,"Идеальная точка"}
				};

CMethodFactory::CMethodFactory()
{
	CString par_name;
	char buf[200];
	CString path=((CUTESApp*)AfxGetApp())->m_Path+"\\dss.ini";
	for (int i=0; i<50; i++)
	{
		par_name.Format("m%i",i);
		GetPrivateProfileString("Methods",par_name,"NotSet", buf, sizeof(buf), path);
		par_name=buf;
		if (par_name!="NotSet")
		{
			m_Names.AddTail(par_name);
			m_IDs.AddTail(i);
			par_name.Format("p%i",i);
			GetPrivateProfileString("Methods",par_name,"NotSet", buf, sizeof(buf), path);
			m_ProgID.AddTail(buf);
			par_name.Format("s%i",i);
			GetPrivateProfileString("Methods",par_name,"NotSet", buf, sizeof(buf), path);
			m_ProgID2.AddTail(buf);
		}
	}
	
	Count=m_IDs.GetCount();
}

CMethodFactory::~CMethodFactory()
{
	
}

CMethod* CMethodFactory::CreateObject(int Type)
{
	switch(Type)
	{
	case METHOD_PREFERENCE: return new CMethodPR();
	case METHOD_WEIGHT:		return new CMethodWE();
	case METHOD_POINT:		return new CMethodIP();
	default:				return new CMethodOLE(Type);
	};
	return NULL;
}
	
int CMethodFactory::GetTypeLex(int Type,CString& Name)
{
	int ID;
	POSITION pos=m_IDs.GetHeadPosition();
	for (int i=0; i<Count; i++)
	{
		ID=m_IDs.GetNext(pos);
		if (ID==Type) 
		{
			Name=m_Names.GetAt(m_Names.FindIndex(i));
			return 0;	//if successful
		}
	}
	return -1;
}

int CMethodFactory::GetProgID(int Type,CString& ProgID)
{
	int ID;
	POSITION pos=m_IDs.GetHeadPosition();
	for (int i=0; i<Count; i++)
	{
		ID=m_IDs.GetNext(pos);
		if (ID==Type) 
		{
			ProgID=m_ProgID.GetAt(m_ProgID.FindIndex(i));
			return 0;	//if successful
		}
	}
	return -1;;
}

int CMethodFactory::GetProgID2(int Type,CString& ProgID)
{
	int ID;
	POSITION pos=m_IDs.GetHeadPosition();
	for (int i=0; i<Count; i++)
	{
		ID=m_IDs.GetNext(pos);
		if (ID==Type) 
		{
			ProgID=m_ProgID2.GetAt(m_ProgID2.FindIndex(i));
			return 0;	//if successful
		}
	}
	return -1;;
}

int CMethodFactory::GetAllID(int* IDs)
{
	POSITION pos=m_IDs.GetHeadPosition();
	int i=0;
	while (pos!=NULL)
	{
		IDs[i++]=m_IDs.GetNext(pos);
	}
	return Count; // return number of types
}