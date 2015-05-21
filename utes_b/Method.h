//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Methods description
//---------------------------------------------------------------------------

#ifndef DSSLIB_METHOD_H
#define DSSLIB_METHOD_H

class CExponent;

#define MAX_E 10 

class CMethod : public CObject 
{
    DECLARE_SERIAL(CMethod)

// interface
	CMethod()	{m_pE=NULL; m_err_msg="";}
	virtual ~CMethod()	{;}

// overloading save and load procedures
	virtual void Serialize(CArchive& ar) {;}
	virtual void SerializeNew(CArchive& ar) { Serialize(ar);}

	virtual CView* CreateEditView() {return NULL;}

	virtual int IsValid() { return 1; }

// Estimation function
	virtual int GetValue(double& x) {return -1;}

	virtual int GetType(){ return 0;}
	virtual CMethod& operator=(const CMethod& other);

	virtual int IsAllPref(){ return 1;}
	virtual int SetOptions() {return -1;}
	CExponent* m_pE;
	CString m_err_msg;
	
};

class CMethodPR : public CMethod 
{
    DECLARE_SERIAL(CMethodPR)

// interface
	CMethodPR();
	virtual ~CMethodPR();

	void SetCritDim();
	void GetCritDim(int *v);
	
	void SetPreference(int *i, int p);
	int  GetPreferance(int *i);

// overloading save and load procedures
	virtual void Serialize(CArchive& ar);
	virtual void SerializeNew(CArchive& ar);
	virtual CView* CreateEditView();	

	virtual int IsValid();
	virtual int IsAllPref();
	virtual int SetOptions();

	virtual CMethodPR& operator=(const CMethodPR& other);

// Estimation function
	virtual int GetValue(double& x);

	virtual int GetType();
	
	UINT m_v[MAX_E];
	CByteArray m_P;
	unsigned char m_robast;
	int m_is_number;
	UINT m_U[MAX_E];
	CString m_XName;
	CString m_YName;
	BOOL m_is_grad;
protected:
// internal data and functions
//	CStringList m_Scale;
//	COLORREF m_GColor;
//	CStringList m_cc;
	
//	CObArray m_c;
	
};

class CMethodWE : public CMethod 
{
    DECLARE_SERIAL(CMethodWE)

// interface
	CMethodWE();
	virtual ~CMethodWE();
	virtual int GetType();
	virtual CView* CreateEditView();
	virtual void Serialize(CArchive& ar);
	virtual int GetValue(double& x);

	virtual CMethodWE& operator=(const CMethodWE& other);

public:
	CArray<double, double&> m_W;
	UINT m_Norm;
};

class CMethodOLE : public CMethod 
{
    DECLARE_SERIAL(CMethodOLE)

// interface
	CMethodOLE();
	CMethodOLE(int t);
	virtual ~CMethodOLE();
	virtual int GetType();
	virtual CView* CreateEditView();
	virtual void Serialize(CArchive& ar);
	virtual int GetValue(double& x);
	virtual int IsValid();

	virtual CMethodOLE& operator=(const CMethodOLE& other);

private:
	int m_Type;
	IFmod m_fmod;
};

#define TYPE_ONE_WITH_ALL		0
#define TYPE_SHORT				1
#define TYPE_FULL				2

#define SLIDER_MAX_VALUE		3

struct Element {
	bool m_EP;
	float m_Value;
};

class CMethodPC
{
public:
	CMethodPC(CMethodWE* m_pM, int SetM);
	~CMethodPC();
	void SetType(int new_Type, int new_Main = 0);
	void SetValue(float new_Value, int i);
	int GetType();
	int GetMain();
	float GetValue(int i);
	void GetWeights();
	void ChangePreferable(int i);	
	bool IsPreferable(int i);
private:
	void Check();
	void Indexer(int &i, int &j);
	CArray<CArray<Element, Element&>, CArray<Element, Element&>&> m_PC;
	int m_Type;
	int m_Main;
	CMethodWE* m_pM;
};

class CMethodIP : public CMethod
{
    DECLARE_SERIAL(CMethodIP)

// interface
	CMethodIP();
	~CMethodIP();
	virtual int GetType();
	virtual CView* CreateEditView();
	virtual void Serialize(CArchive& ar);
	virtual int GetValue(double& x);

	virtual CMethodIP& operator=(const CMethodIP& other);
public:
	CArray<double, double&> m_W;
};
#endif // DSSLIB_GROUP_H