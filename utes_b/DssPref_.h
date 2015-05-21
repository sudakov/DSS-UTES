//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Prefefrance Estimator
// DssPref.h : header file
//
//---------------------------------------------------------------------------



/////////////////////////////////////////////////////////////////////////////
// CDssPref command target

class CDssPref : public CCmdTarget
{
	DECLARE_DYNCREATE(CDssPref)

public:
	CDssPref();

// Attributes
	static CUTESDoc* m_pDoc;
	CExponent* m_pG;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDssPref)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CDssPref();


	// Generated message map functions
	//{{AFX_MSG(CDssPref)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CDssPref)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDssPref)
	afx_msg VARIANT GetCriterionName(short index);
	afx_msg short GetCriterionNumber();
	afx_msg void SetCriterionValue(short index, const VARIANT FAR& value);
	afx_msg double GetPreferenceValue();
	afx_msg short Initialize();
	afx_msg double GetCriterionValue(short Index);
	afx_msg void TestArray2(VARIANT FAR* A1);
	afx_msg short GetCriterionInfo(short index, short FAR* type, VARIANT FAR* name, VARIANT FAR* description);
	afx_msg short GetGradation(short index, short i, VARIANT FAR* grad);
	afx_msg short GetCriterionScaleType(short index, short FAR* type);
	afx_msg short IsAllPref();
	afx_msg short GetCriterionParent(short index);
	afx_msg short GetPreferenceValueEx(double FAR* v);
	afx_msg short GetCriterionValueEx(short index, double FAR* v);
	afx_msg short SetCriterionValueEx(short index, const VARIANT FAR& v);
	afx_msg short GetMinMaxDir(short index, double FAR* min, double FAR* max, short FAR* dir);
	afx_msg short OpenFile(LPCTSTR name);
	afx_msg VARIANT CreateVariant(LPCTSTR s);
	afx_msg short GetCriterionInfoPB(short index, short FAR* type, BSTR FAR* name, BSTR FAR* description);
	afx_msg short GetGradationPB(short index, short i, BSTR FAR* grad);
	afx_msg void Visible(BOOL bFlag);
	afx_msg short SaveFile(LPCTSTR lpszFileName);
	afx_msg short NewFile();
	afx_msg short LoadCriterionPB(short type, LPCTSTR name, LPCTSTR description, double max_val, double min_val, short direction);
	afx_msg short SetCriterionArgPB(short index_pr, short index_ch);
	afx_msg short SetCriterionMethod(short index, short index_meth);
	afx_msg short UpdateUTESView();
	afx_msg short LoadScalePB(short index, short sc_type);
	afx_msg short SetCriterionGradation(short index, LPCTSTR lpsz_grad);
	afx_msg BSTR GetDocPath();
	afx_msg short GetGradationFromDouble(short index, double number, BSTR FAR* lp_grad);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
