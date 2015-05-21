//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Exponent class description interface
//---------------------------------------------------------------------------

#ifndef DSSLIB_EXPONENT_H
#define DSSLIB_EXPONENT_H


class CExponent : public CObject
{
    DECLARE_SERIAL(CExponent)
public:

// interface
	CExponent();
	CExponent(int Type);

	~CExponent();

	virtual void SetName(CString n) { m_Name=n;}
	virtual CString GetName() { return m_Name; }
	virtual void SetDescription(CString d) { m_Description=d;}
	virtual CString GetDescription() { return m_Description; }
	
	virtual int GetNumGrad();

	int GetBestDir() { return m_iDirBest;  }
	void SetBestDir(int i) { m_iDirBest=i; }
	double GetMaxValue() { return m_dMaxValue; }
	void SetMaxValue(double d) { m_dMaxValue=d; }
	double GetMinValue() { return m_dMinValue; }
	void SetMinValue(double d) { m_dMinValue=d; }

	virtual int GetType() { return m_Type; }
	virtual void SetType(int t);


	virtual int DialogSet();
	virtual int DialogEdit();

	// Estimation functions return 0 if ok
	virtual int SetValue(COleVariant v);
	virtual void ClearValue();
	virtual int GetValue(double& v);
	virtual int GetLex(CString& v);
	virtual int GetGradation(int& Index);
	virtual int GetNearestGradation(int& Index);

	CExponent& operator=(CExponent& other);
	
// overloading save and load procedures
	virtual void Serialize(CArchive& ar);

	CScale* m_scale;
	CObList m_agr;
	CMethod* m_Method;

protected:
// internal data and functions
	CString m_Name;
	CString m_Description;
	double m_dValue;
	int m_Type;
	UINT m_id;
	int m_iValue;
	int m_Grad;
	bool m_IsSet;
	double m_dMaxValue;
	double m_dMinValue;
	int m_iDirBest; // max =1 min = -1 annown =0
};

#endif // DSSLIB_EXPONENT_H