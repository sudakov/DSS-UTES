//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Exponent dialog class description interface
// ExponentDialog.h : header file
//
//---------------------------------------------------------------------------

#if !defined(AFX_EXPONENTDIALOG_H__4D8A4F44_3C4B_11D3_AF6C_E58EBFE6405F__INCLUDED_)
#define AFX_EXPONENTDIALOG_H__4D8A4F44_3C4B_11D3_AF6C_E58EBFE6405F__INCLUDED_

#include "factory.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExponentDialog dialog

class CExponentDialog : public CDialog
{
// Construction
public:
	CObList* m_pAllE;
	void BeforExit();
	CScaleFactory m_sF;
	CExponentFactory m_eF;
	int MakeScaleList(int ExpType);
	int flag; //,m_first;
	//int m_IsChange;
	RECT m_Rect;
	CExponent* m_E;
	CExponent* m_BuffE;
	CExponentDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExponentDialog)
	enum { IDD = IDD_DIALOG_EXPONENT };
	CButton	m_NextExp;
	CString	m_Name;
	CString	m_Description;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExponentDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExponentDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonNextExp();
	afx_msg void OnCloseupComboType();
	afx_msg void OnButtonCharact();
	afx_msg void OnButtonScale();
	afx_msg void OnCloseupComboScale();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonAdv();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXPONENTDIALOG_H__4D8A4F44_3C4B_11D3_AF6C_E58EBFE6405F__INCLUDED_)
