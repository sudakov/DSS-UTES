//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1997/1998 Russia
//---------------------------------------------------------------------------
// Author: Vladimir_Sudakov
// Description: Criterion description interface agrigate CCritetion object
//---------------------------------------------------------------------------

#ifndef DSSLIB_CRITERION_H
#define DSSLIB_CRITERION_H

// Type constants
#define CRITERION_NONSET       -1
#define CRITERION_LEXICAL		0
#define CRITERION_DISCRET		1
#define CRITERION_INTERVAL		2
#define CRITERION_NONLIMITED	3	

class CCrit : public CExponent
{
    DECLARE_SERIAL(CCrit)
public:
// interface
	CCrit();
	~CCrit();

	int GetType();
	virtual CString GetName();
	virtual int GetGradation();
	// if number type this function return string represantion
	virtual CString GetLex(int index);
	int DialogSet();	//return 0 if normal execution


// overloading save and load procedures
	virtual void Serialize(CArchive& ar);

// Estimating functions
	virtual double GetValue(); 
	virtual int SetValue(COleVariant v);
	virtual int Estimate();

protected:
	int m_vi;
	double  m_vd;
// internal data and functions
//	CCriterion* pC;
};

#endif // DSSLIB_CRITERION_H