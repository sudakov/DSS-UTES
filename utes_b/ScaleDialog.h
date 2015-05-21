//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Base Scale Edit class description interface
// ScaleDialog.h : header file
//
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
// CScaleDialog dialog

class CScaleDialog : public CDialog
{
// Construction
public:
	CScaleDialog(CWnd* pParent = NULL);   // standard constructor
	CScale* m_pScale;
// Dialog Data
	//{{AFX_DATA(CScaleDialog)
	enum { IDD = IDD_DIALOG_SCALE };
	CString	m_AllGrad;
	BOOL	m_Rang;
	CString	m_Format;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScaleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScaleDialog)
	afx_msg void OnButtonDefault();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonAuto();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
