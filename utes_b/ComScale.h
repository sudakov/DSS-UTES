//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1999 Russia
//---------------------------------------------------------------------------
// Author: Vladimir_Sudakov
// Description: Common scale types description
//---------------------------------------------------------------------------

#ifndef DSSLIB_COMSCALE_H
#define DSSLIB_COMSCALE_H

class CLexScale : public CScale
{
	DECLARE_SERIAL(CLexScale)
public:
// interface
	CLexScale();
	~CLexScale();

// if number type this function return string represantion
	virtual CString GetLex(int index);
	

	virtual int DialogEdit();

	virtual int GetType() {return SCALE_LEXICAL;}

// Estimation functions
//	virtual int Estimate(COleVariant v,int& Index) {return -1;}
//	virtual int EstimateNearest(COleVariant v,int& Index) {return -1;}

// overloading save and load procedures
	virtual void Serialize(CArchive& ar);

protected:
// internal data and functions
	CStringList m_Lex;
};

#endif // DSSLIB_COMSCALE_H