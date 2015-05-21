//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Edit class for Method Ideal Point
// UTESView.h : interface of the CPointView class
//
//---------------------------------------------------------------------------
#pragma once
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

// представление формы CPointView

class CPointView : public CFormView
{
	
public:
	CPointView();           // защищенный конструктор, используемый при динамическом создании
	DECLARE_DYNCREATE(CPointView)
protected:
	virtual ~CPointView();

public:
	enum { IDD = IDD_UTES_POINT };
	CUTESDoc* GetDocument();	
	virtual BOOL DestroyWindow();
	CExponent* m_pE;
	CMethodIP* m_pM;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	CArray <CWnd*, CWnd*> m_pW;
	CExponent* CPointView::GetExponent(CString& name);
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	DECLARE_MESSAGE_MAP()
	virtual void OnInitialUpdate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	bool fSize;	
	int sel;
public:
	afx_msg void NextExp();
};
#ifndef _DEBUG  // debug version in PointView.cpp
inline CUTESDoc* CPointView::GetDocument()
   { return (CUTESDoc*)m_pDocument; }
#endif


