//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Description main view class
// UTESView.h : interface of the CUTESView class
//
//---------------------------------------------------------------------------

class CUTESView : public CFormView
{
public: // create from serialization only
	void ReDrawCrit();
	void ReSize();
	int fSize;
	int AddNode(HTREEITEM Father, CExponent *pG);
	int RebildTree();
	void SetDim(CExponent *pG);
	int IsSelect(int k=0);
	CUTESView();
	DECLARE_DYNCREATE(CUTESView)

public:
	//{{AFX_DATA(CUTESView)
	enum { IDD = IDD_UTES_FORM };
	CStatic	m_GroupCount;
	CStatic	m_CriterionCount;
	CTreeCtrl	m_DecompTree;
	CListCtrl	m_GroupList;
	CListCtrl	m_CritList;
	//}}AFX_DATA

// Attributes
public:
	CUTESDoc* GetDocument();

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUTESView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	void GetCritPos(CString name);
	void SetCritSel();
	virtual ~CUTESView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUTESView)
	afx_msg void OnAddCriteria();
	afx_msg void OnChangeCriterion();
	afx_msg void OnDelCriterion();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDblclkListCrit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnUpdateChCr(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelCr(CCmdUI* pCmdUI);
	afx_msg void OnKillfocusListCrit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemSelMethod();
	afx_msg void OnUpdateMenuitemSelMethod(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAddcr(CCmdUI* pCmdUI);
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusTree(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UTESView.cpp
inline CUTESDoc* CUTESView::GetDocument()
   { return (CUTESDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
