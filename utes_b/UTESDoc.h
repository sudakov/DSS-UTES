//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Documen class
// UTESDoc.h : interface of the CUTESDoc class
//
//---------------------------------------------------------------------------

class CUTESDoc : public CDocument
{
protected: // create from serialization only
	CUTESDoc();
	DECLARE_DYNCREATE(CUTESDoc)

// Attributes
public:
	int SaveBeforDelete();
	CObList m_C;
	CObList m_G;
	CObList m_Exp;
	CString m_sel_crit;
	int m_CritPos;
	int m_IsErr;
	CString m_err_msg;
	HWND m_hwnd;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTESDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUTESDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUTESDoc)
	afx_msg void OnImportDocument();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CUTESDoc* GetMyDoc();

/////////////////////////////////////////////////////////////////////////////
