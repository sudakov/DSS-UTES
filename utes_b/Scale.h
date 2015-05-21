//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Base Scale class description interface
//---------------------------------------------------------------------------

#ifndef DSSLIB_CSCALE_H
#define DSSLIB_CSCALE_H

class CScale : public CObject
{
	DECLARE_SERIAL(CScale)
	friend class CScaleDialog;
public:
// interface
	CScale();
	CScale(int Type);
	~CScale();

	virtual int  GetGradation();
	int GetRange(double& a, double& b);
// if number type this function return string represantion
	virtual CString GetLex(int index);
	
	virtual int DialogEdit();

	virtual int GetType();

// Estimation functions
	virtual int GetIndex(COleVariant v,int& ind, CMethod* pM);
	virtual int GetNearest(COleVariant v,int& r);
	virtual int GetRang(int ind, double& r);
	
	virtual void SetGradation(LPCTSTR lpsz_grad);

	CScale& operator=(const CScale& other);

// overloading save and load procedures
	virtual void Serialize(CArchive& ar);

protected:
// internal data and functions
	int m_Count;
	int m_Type;
	int m_Rang;
	CString m_Format;
	double* m_Numbers;
	double* m_Rangs;
	CStringList m_Lex;
};

#endif // DSSLIB_CSCALE_H