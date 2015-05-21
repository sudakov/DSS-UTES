//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1997/1998 Russia
//---------------------------------------------------------------------------
// Author: Vladimir_Sudakov
// Description: Group of criterion description interface
//---------------------------------------------------------------------------

#ifndef DSSLIB_GROUP_H
#define DSSLIB_GROUP_H

class CGroup : public CExponent
{
    DECLARE_SERIAL(CGroup)
public:
	CStringList m_Scale;
	COLORREF m_GColor;
	CStringList m_cc;
	CObArray m_c;
// interface
	CGroup();
	~CGroup();

	virtual CString GetLex(int index);
	
	void AddCriterion(CString c) { m_cc.AddTail(c); }
	int RemoveCriterion(CString c); //return 1 if succesfull
	int FindCriterion(CString c);	// ---//---
		
	int DialogSet(CStringList *pAllC);	//return 0 if abnormal execution
										//else return 1

	void SetCritDim(int *V);
	void GetCritDim(int *v);
	void SetPreference(int *i, int p);
	int  GetPreferance(int *i);
// overloading save and load procedures
	virtual void Serialize(CArchive& ar);

// Estimation functions
	virtual double GetValue(); 
	virtual int Estimate();



protected:
// internal data and functions
	CByteArray m_P;
	int m_v[10];
};

#endif // DSSLIB_GROUP_H