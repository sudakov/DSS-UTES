#if !defined(AFX_SCALEAUTODEF_H__D92889A1_C7A9_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
#define AFX_SCALEAUTODEF_H__D92889A1_C7A9_11D4_AD4F_00C0DFF08F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScaleAutoDef.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScaleAutoDef dialog

class CScaleAutoDef : public CDialog
{
// Construction
public:
	CScaleAutoDef(CWnd* pParent = NULL);   // standard constructor
	double m_dMin;
	double m_dMax;
	double m_dStep;
// Dialog Data
	//{{AFX_DATA(CScaleAutoDef)
	enum { IDD = IDD_DIALOG_AUTO_SCALE };
	CString	m_Max;
	CString	m_Min;
	CString	m_Step;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScaleAutoDef)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScaleAutoDef)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCALEAUTODEF_H__D92889A1_C7A9_11D4_AD4F_00C0DFF08F0F__INCLUDED_)
