#if !defined(AFX_DIALOGROBAST_H__890404E1_DB22_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
#define AFX_DIALOGROBAST_H__890404E1_DB22_11D4_AD4F_00C0DFF08F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogRobast.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogRobast dialog

class CDialogRobast : public CDialog
{
// Construction
public:
	CDialogRobast(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogRobast)
	enum { IDD = IDD_DIALOG_ROBAST };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	CMethodPR* m_pMethod;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogRobast)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogRobast)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGROBAST_H__890404E1_DB22_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
