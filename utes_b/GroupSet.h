//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Dialog class for seting Exponent Param description interface
// GroupSet.h : header file
//
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
// CGroupSet dialog

class CGroupSet : public CDialog
{
// Construction
public:
	CObList* m_pAllE;
	CExponent* m_pE;
	CGroupSet(CWnd* pParent = NULL);   // standard constructor
	CMethodFactory m_F;
	
	void EnableButtomCur();
	void EnableButtomAll();

// Dialog Data
	//{{AFX_DATA(CGroupSet)
	enum { IDD = IDD_DIALOG_GROUP };
	CListBox	m_AllList;
	CListBox	m_CurList;
	CString	m_Name;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGroupSet)
	afx_msg void OnAddForList();
	afx_msg void OnAddFromList();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSelchangeList1();
	afx_msg void OnSelchangeList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
