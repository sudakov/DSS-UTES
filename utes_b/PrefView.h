//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Preferance Estimator Edit View interface
// PrefView.h : header file
//
//---------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////
// CPrefView form view
//{{AFX_INCLUDES()
#include "gridctrl.h"
#include "msflexgrid.h"
//}}AFX_INCLUDES

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CPrefView : public CFormView
{
public:
//	CPicture* m_pPicture;
	CPictureHolder* m_pPict;
	CBitmap* m_pBitmap;
	CPictureHolder* m_pPictX;
	CBitmap* m_pBitmapX;
	CBrush* m_Brush;
	CPen* m_Pen;
	CSize m_sG;
	CSize m_sG0;
	CArray <int,int&> m_scaleX;

	CArray <CByteArray,CByteArray&> m_clP;
	CObList m_UndoP;
	
	CMenu* m_pMenu;
	int fSize;
	void ReSize();
	void SetBitmap(int ps, int max_ps, int j, int k);
	CExponent* m_pG;
	CExponent* m_pX;
	CExponent* m_pY;
	CMethodPR* m_pM;
	CFont m_curFont;
	BOOL LoadFont();
	void DrawRect();
	CExponent* GetExponent(CString& name);
	void ChangeGrid();
	void UpdateValue();
	int  GetIndex(CString s, CExponent* pG);
	void ClearGrid();
	void DoWithRgn(int ID);
	int Step(int i);

	CPrefView();           // protected constructor used by dynamic creation

	DECLARE_DYNCREATE(CPrefView)
// Form Data
public:
	//{{AFX_DATA(CPrefView)
	enum { IDD = IDD_UTES_PREF };
	CSpinButtonCtrl	m_Spin;
	CSliderCtrl	m_Slider;
	CListCtrl	m_OtherC;
	CComboBox	m_ComboX;
	CComboBox	m_ComboY;
	CMSFlexGrid	m_Grid;
	//}}AFX_DATA

// Attributes
public:
	int m_U[MAX_E];
	int m_UU[MAX_E];
	int m_n;
	CUTESDoc* GetDocument();
// Operations
public:
	void SetOtherCriterion();
	void SetAxis();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrefView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void CreateAllBitmap();
	void CreateAllBitmapX();
	virtual ~CPrefView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPrefView)
	afx_msg void OnChangeComboX();
	afx_msg void OnChangeComboY();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnItemchangedListVal(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelChangeMsflexgrid1();
	afx_msg void OnClickMsflexgrid1();
	afx_msg void OnDblClickMsflexgrid1();
	afx_msg void OnDeltaposSpin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemApprox();
	afx_msg void OnMenuitemClear();
	afx_msg void OnMenuitemCopy();
	afx_msg void OnMenuitemDecL();
	afx_msg void OnMenuitemIncL();
	afx_msg void OnMenuitemInsert();
	afx_msg void OnMenuItemIsAll();
	afx_msg void OnStaticScale();
	afx_msg void OnMenuitemUndo();
	afx_msg void OnMenuitemShowgrad();
	afx_msg void OnKeyPressMsflexgrid1(short FAR* KeyAscii);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
#ifndef _DEBUG  // debug version in PrefView.cpp
inline CUTESDoc* CPrefView::GetDocument()
   { return (CUTESDoc*)m_pDocument; }
#endif
/////////////////////////////////////////////////////////////////////////////
