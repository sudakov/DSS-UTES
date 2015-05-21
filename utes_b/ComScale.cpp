//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1997/1998 Russia
//---------------------------------------------------------------------------
// Author: Vladimir_Sudakov
// Description: Factory for all components prototype
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "ComScale.h"
#include "ScaleDialog.h"

IMPLEMENT_SERIAL(CLexScale, CObject, 1)

CLexScale::CLexScale()
{
	m_Grad=0;
}

CLexScale::~CLexScale()
{
	;
}


// if number type this function return string represantion
CString CLexScale::GetLex(int index)
{
	return m_Lex.GetAt(m_Lex.FindIndex(index));
}
	

int CLexScale::DialogEdit()
{
	CScaleDialog dlg;
//	dlg.m_grad=10;
//	dlg.m_pScale=&m_Lex;
	return dlg.DoModal();
}

void CLexScale::Serialize(CArchive& ar)
{
	CScale::Serialize(ar);
	m_Lex.Serialize(ar);
	m_Grad=m_Lex.GetCount();
}

