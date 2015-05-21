#if !defined(AFX_DIALOGEXPADV_H__A73962E1_4787_11D4_AD4D_00C0DFF08F0F__INCLUDED_)
#define AFX_DIALOGEXPADV_H__A73962E1_4787_11D4_AD4D_00C0DFF08F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogExpAdv.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogExpAdv dialog

class CDialogExpAdv : public CDialog
{
// Construction
public:
	CDialogExpAdv(CWnd* pParent = NULL);   // standard constructor

	CExponent* m_E;

// Dialog Data
	//{{AFX_DATA(CDialogExpAdv)
	enum { IDD = IDD_DIALOG_EXP_ADV };
	CString	m_Min;
	CString	m_Max;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogExpAdv)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogExpAdv)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGEXPADV_H__A73962E1_4787_11D4_AD4D_00C0DFF08F0F__INCLUDED_)
