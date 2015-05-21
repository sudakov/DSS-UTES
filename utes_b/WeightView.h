//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Edit class for Method Wieght
// UTESView.h : interface of the CWeightView class
//
//---------------------------------------------------------------------------

//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_WEIGHTVIEW_H__570262A5_5A1A_11D3_AF6C_F2BA7074F148__INCLUDED_)
#define AFX_WEIGHTVIEW_H__570262A5_5A1A_11D3_AF6C_F2BA7074F148__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WeightView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeightView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CWeightView : public CFormView
{
public:
	CWeightView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWeightView)

// Form Data
public:
	//{{AFX_DATA(CWeightView)
	enum { IDD = IDD_UTES_WEIGHT };
	BOOL	m_Norm;
	//}}AFX_DATA
	CGridCtrl m_myGrid;
// Attributes
public:
	CExponent* m_pE;
	CMethodWE* m_pM;
	int fSize;
	int m_x;
	int m_y;
	int m_FromE;
	bool m_PCMode;
	CMethodPC* m_PC;
// Operations
public:
	CUTESDoc* GetDocument();
	void ReSize();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeightView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWeightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CWeightView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnNormW();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void OnModeChange(int Mode);
//	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	void OnInitialGrid();
	afx_msg void OnSelShortMode();
	afx_msg void OnSelSpecialMode();
	afx_msg void OnSelFullMode();
	afx_msg void OnSelSpecialItem();
	afx_msg void OnPrefChange();
	CSliderCtrl m_Slider;
	afx_msg void OnInitPairedComparison();
	void OnDelPairedComparison(int Msg = 0);
	afx_msg void OnOK();
	afx_msg void OnCancel();
	afx_msg void OnEnKillfocusEdit2();
};

#ifndef _DEBUG  // debug version in WeightView.cpp
inline CUTESDoc* CWeightView::GetDocument()
   { return (CUTESDoc*)m_pDocument; }
#endif


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEIGHTVIEW_H__570262A5_5A1A_11D3_AF6C_F2BA7074F148__INCLUDED_)
