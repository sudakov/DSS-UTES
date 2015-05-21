#if !defined(AFX_DIALOGSELMETHOD_H__4F6C15C1_856D_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
#define AFX_DIALOGSELMETHOD_H__4F6C15C1_856D_11D4_AD4F_00C0DFF08F0F__INCLUDED_

#include "Method.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogSelMethod.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogSelMethod dialog

class CDialogSelMethod : public CDialog
{
// Construction
public:
	CExponent* m_pE;
	CDialogSelMethod(CWnd* pParent = NULL);   // standard constructor
	CMethod* m_pM;
// Dialog Data
	//{{AFX_DATA(CDialogSelMethod)
	enum { IDD = IDD_DIALOG_SELPR };
	CListBox	m_ListMethod;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogSelMethod)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogSelMethod)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButtonOptions();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGSELMETHOD_H__4F6C15C1_856D_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
