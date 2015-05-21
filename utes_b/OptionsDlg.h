#if !defined(AFX_OPTIONSDLG_H__8E105E61_8705_11D3_9B7C_24F4F9C00000__INCLUDED_)
#define AFX_OPTIONSDLG_H__8E105E61_8705_11D3_9B7C_24F4F9C00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
public:
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_DIALOG_OPTIONS };
	CString	m_Slover;
	CString	m_Code;
	CString	m_Comp;
	CString	m_CodeW;
	//}}AFX_DATA

	DWORD m_c;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDLG_H__8E105E61_8705_11D3_9B7C_24F4F9C00000__INCLUDED_)
