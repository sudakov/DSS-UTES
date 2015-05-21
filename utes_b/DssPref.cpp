//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Class for Using Ole Automation access
// DssPref.cpp : implementation file
//
//---------------------------------------------------------------------------
//

#include "stdafx.h"
#include "UTES.h"
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "dialogselmethod.h"
//#include "CritDialog.h"
//#include "Criterion.h"
//#include "CGroup.h"

#include "MainFrm.h"
#include "UTESDoc.h"
#include "UTESView.h"
#include "DssPref.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDssPref
CUTESDoc* CDssPref::m_pDoc=NULL;

IMPLEMENT_DYNCREATE(CDssPref, CCmdTarget)

CDssPref::CDssPref()
{
	EnableAutomation();
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	TRACE("create object!!!");
	AfxOleLockApp();
	m_pG=NULL;
}

CDssPref::~CDssPref()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	AfxOleUnlockApp();
}


void CDssPref::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CDssPref, CCmdTarget)
	//{{AFX_MSG_MAP(CDssPref)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDssPref, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CDssPref)
	DISP_FUNCTION(CDssPref, "GetCriterionName", GetCriterionName, VT_VARIANT, VTS_I2)
	DISP_FUNCTION(CDssPref, "GetCriterionNumber", GetCriterionNumber, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "SetCriterionValue", SetCriterionValue, VT_EMPTY, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CDssPref, "GetPreferenceValue", GetPreferenceValue, VT_R8, VTS_NONE)
	DISP_FUNCTION(CDssPref, "Initialize", Initialize, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "GetCriterionValue", GetCriterionValue, VT_R8, VTS_I2)
	DISP_FUNCTION(CDssPref, "TestArray2", TestArray2, VT_EMPTY, VTS_PVARIANT)
	DISP_FUNCTION(CDssPref, "GetCriterionInfo", GetCriterionInfo, VT_I2, VTS_I2 VTS_PI2 VTS_PVARIANT VTS_PVARIANT)
	DISP_FUNCTION(CDssPref, "GetGradation", GetGradation, VT_I2, VTS_I2 VTS_I2 VTS_PVARIANT)
	DISP_FUNCTION(CDssPref, "GetCriterionScaleType", GetCriterionScaleType, VT_I2, VTS_I2 VTS_PI2)
	DISP_FUNCTION(CDssPref, "IsAllPref", IsAllPref, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "GetCriterionParent", GetCriterionParent, VT_I2, VTS_I2)
	DISP_FUNCTION(CDssPref, "GetPreferenceValueEx", GetPreferenceValueEx, VT_I2, VTS_PR8)
	DISP_FUNCTION(CDssPref, "GetCriterionValueEx", GetCriterionValueEx, VT_I2, VTS_I2 VTS_PR8)
	DISP_FUNCTION(CDssPref, "SetCriterionValueEx", SetCriterionValueEx, VT_I2, VTS_I2 VTS_VARIANT)
	DISP_FUNCTION(CDssPref, "GetMinMaxDir", GetMinMaxDir, VT_I2, VTS_I2 VTS_PR8 VTS_PR8 VTS_PI2)
	DISP_FUNCTION(CDssPref, "OpenFile", OpenFile, VT_I2, VTS_BSTR)
	DISP_FUNCTION(CDssPref, "CreateVariant", CreateVariant, VT_VARIANT, VTS_BSTR)
	DISP_FUNCTION(CDssPref, "GetCriterionInfoPB", GetCriterionInfoPB, VT_I2, VTS_I2 VTS_PI2 VTS_PBSTR VTS_PBSTR)
	DISP_FUNCTION(CDssPref, "GetGradationPB", GetGradationPB, VT_I2, VTS_I2 VTS_I2 VTS_PBSTR)
	DISP_FUNCTION(CDssPref, "Visible", Visible, VT_EMPTY, VTS_BOOL)
	DISP_FUNCTION(CDssPref, "SaveFile", SaveFile, VT_I2, VTS_BSTR)
	DISP_FUNCTION(CDssPref, "NewFile", NewFile, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "LoadCriterionPB", LoadCriterionPB, VT_I2, VTS_I2 VTS_BSTR VTS_BSTR VTS_R8 VTS_R8 VTS_I2)
	DISP_FUNCTION(CDssPref, "SetCriterionArgPB", SetCriterionArgPB, VT_I2, VTS_I2 VTS_I2)
	DISP_FUNCTION(CDssPref, "SetCriterionMethod", SetCriterionMethod, VT_I2, VTS_I2 VTS_I2)
	DISP_FUNCTION(CDssPref, "UpdateUTESView", UpdateUTESView, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "LoadScalePB", LoadScalePB, VT_I2, VTS_I2 VTS_I2)
	DISP_FUNCTION(CDssPref, "SetCriterionGradation", SetCriterionGradation, VT_I2, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CDssPref, "GetDocPath", GetDocPath, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CDssPref, "GetGradationFromDouble", GetGradationFromDouble, VT_I2, VTS_I2 VTS_R8 VTS_PBSTR)
	DISP_FUNCTION(CDssPref, "DeleteAll", DeleteAll, VT_I2, VTS_NONE)
	DISP_FUNCTION(CDssPref, "DeleteCriterion", DeleteCriterion, VT_I2, VTS_I2)
	DISP_FUNCTION(CDssPref, "GetMinMaxBest", GetMinMaxBest, VT_I2, VTS_I2 VTS_PR8 VTS_PR8 VTS_PR8)
	DISP_FUNCTION(CDssPref, "SetHWND", SetHWND, VT_I2, VTS_I4)
	DISP_FUNCTION(CDssPref, "SetCriterionName", SetCriterionName, VT_I2, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CDssPref, "GetCriterionIndex", GetCriterionIndex, VT_I4, VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDssPref to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {C8870361-7B2A-11D2-B7A1-A7B00D604327}
static const IID IID_IDssPref =
{ 0xc8870361, 0x7b2a, 0x11d2, { 0xb7, 0xa1, 0xa7, 0xb0, 0xd, 0x60, 0x43, 0x27 } };

BEGIN_INTERFACE_MAP(CDssPref, CCmdTarget)
	INTERFACE_PART(CDssPref, IID_IDssPref, Dispatch)
END_INTERFACE_MAP()

// {C8870362-7B2A-11D2-B7A1-A7B00D604327}
IMPLEMENT_OLECREATE(CDssPref, "UTES.DSSPREF", 0xc8870362, 0x7b2a, 0x11d2, 0xb7, 0xa1, 0xa7, 0xb0, 0xd, 0x60, 0x43, 0x27)

/////////////////////////////////////////////////////////////////////////////
// CDssPref message handlers

VARIANT CDssPref::GetCriterionName(short index) 
{
	CString buff;
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos!=NULL) buff=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetName();
	return COleVariant(buff);
}

short CDssPref::GetCriterionNumber() 
{
	return m_pDoc->m_Exp.GetCount();
}

void CDssPref::SetCriterionValue(short index, const VARIANT FAR& value) 
{
	// TODO: Add your dispatch handler code here
	((CExponent*)(m_pDoc->m_Exp.GetAt(m_pDoc->m_Exp.FindIndex(index))))->SetValue(value);
}

short CDssPref::SetCriterionValueEx(short index, const VARIANT FAR& v)
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	return ((CExponent*)(m_pDoc->m_Exp.GetAt(pos)))->SetValue(v);
}

double CDssPref::GetPreferenceValue() 
{
	// TODO: Add your dispatch handler code here
	if (m_pG==NULL) return -666.0;
	double x;
	m_pG->GetValue(x);
	return x;
}

short CDssPref::GetPreferenceValueEx(double FAR* v) 
{
	// TODO: Add your dispatch handler code here
	if (m_pG==NULL) return -1;
	double x;
	if (m_pG->GetValue(x)) return -1;
	*v=x;
	return 0;
}

short CDssPref::Initialize() 
{
	// TODO: Add your dispatch handler code here
	POSITION pos = m_pDoc->m_Exp.GetHeadPosition();
	POSITION pos2;
	CExponent* pG;
	m_pG=NULL;
	CString Buff2(((CUTESApp*)AfxGetApp())->szInProcServer);
	while (pos!=NULL)
	{
		pG=(CExponent*)m_pDoc->m_Exp.GetNext(pos);
		pos2=m_pDoc->m_Exp.GetHeadPosition();
		POSITION Rez=NULL;
		while ((pos2!=NULL)&&(Rez==NULL))
			Rez=((CExponent*)m_pDoc->m_Exp.GetNext(pos2))->m_agr.Find(pG);
		if ((Rez==NULL)&&(m_pG!=NULL)) //More roots find
			return 0;
		if ((Rez==NULL)&&(m_pG==NULL)) //One root find
			m_pG=pG;
#ifndef DEMOVER
		if (((CUTESApp*)AfxGetApp())->m_Protection.CheckStatus(1))
		{
			m_pG=NULL;	// Nothing root find
			return -1;
		}
#endif
	}
	if (m_pG==NULL)	return -1; // Nothing root find
	return 1;
}


double CDssPref::GetCriterionValue(short Index) 
{
	double v=0;
	POSITION pos=m_pDoc->m_Exp.FindIndex(Index);;
	if (pos==NULL) return -1.0;
	if (((CExponent*) m_pDoc->m_Exp.GetAt(pos))->GetValue(v)) return -2.0;
	return v;
}

short CDssPref::GetCriterionValueEx(short index, double FAR* v) 
{
	// TODO: Add your dispatch handler code here
	double vv=0;
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	if (((CExponent*) m_pDoc->m_Exp.GetAt(pos))->GetValue(vv)) return -1;
	*v=vv;
	return 0;
}

void CDssPref::TestArray2(VARIANT FAR* A1) 
{
	// TODO: Add your dispatch handler code here
	COleVariant v(A1);
	COleVariant res;
	short n;
	n=6;
	//v.ChangeType(VT_ARRAY|VT_R8);
	int k=SafeArrayGetDim(v.parray);
	long ind[2];
	ind[0]=0; ind[1]=1;
	SafeArrayGetElement(v.parray,ind,&res);
	res=n;
}


short CDssPref::GetCriterionInfo(short index, short FAR* type, VARIANT FAR* name, VARIANT FAR* description) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	*type=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetType();
	COleVariant v(((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetName());
	*name=v;
	COleVariant vv(((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetDescription());
	*description=vv;
	return 0;
}



short CDssPref::GetGradation(short index, short i, VARIANT FAR* grad) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	CExponent* pG=((CExponent*)m_pDoc->m_Exp.GetAt(pos));
	if (pG->m_scale==NULL) return -1;
	if (pG->m_scale->GetGradation()<=i) return -1;
	COleVariant  v(pG->m_scale->GetLex(i));
	*grad=v;
	return 0;
}

short CDssPref::GetCriterionScaleType(short index, short FAR* type) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	CExponent* pG=((CExponent*)m_pDoc->m_Exp.GetAt(pos));
	*type=0;
	if (pG->m_scale==NULL) return -1;
	*type = (short) pG->m_scale->GetType();
	return 0;
}

short CDssPref::IsAllPref() 
{
	// TODO: Add your dispatch handler code here
	POSITION pos = m_pDoc->m_Exp.GetHeadPosition();
	CExponent* pG;
	while (pos!=NULL)
	{
		pG=(CExponent*)m_pDoc->m_Exp.GetNext(pos);
		if ((pG->m_Method!=NULL)&&(!(pG->m_Method->IsAllPref()))) return -1;
	}
	return 0;
}

short CDssPref::GetCriterionParent(short index) 
{
	// TODO: Add your dispatch handler code here
	int i=0;
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	CExponent* pG=((CExponent*)m_pDoc->m_Exp.GetAt(pos));
	pos=m_pDoc->m_Exp.GetHeadPosition();
	while (pos!=NULL)
	{
		if ( ( ((CExponent*)m_pDoc->m_Exp.GetAt(pos))->m_agr.Find(pG) ) != NULL )
			return i;
		m_pDoc->m_Exp.GetNext(pos);
		i++;
	}
	return -2;
}

short CDssPref::GetMinMaxDir(short index, double FAR* min, double FAR* max, short FAR* dir) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	*min=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetMinValue();
	*max=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetMaxValue();
	*dir=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetBestDir();
	return 0;
}

short CDssPref::OpenFile(LPCTSTR name) 
{
	CUTESDoc* pD=NULL;
	CMainFrame *pMainWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	POSITION pos=AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = (CDocTemplate*) AfxGetApp()->GetNextDocTemplate(pos);
	BOOL bVisibleFlag = pMainWnd->IsWindowVisible();
	pD=(CUTESDoc*)pTemplate->OpenDocumentFile(name, TRUE);
	Visible(bVisibleFlag);
	if (pD!=NULL)
	{
		m_pDoc=pD;
		return 0;
	}
	return -1;
}

VARIANT CDssPref::CreateVariant(LPCTSTR s) 
{
	//VARIANT vaResult;
	//VariantInit(&vaResult);
	// TODO: Add your dispatch handler code here
	VARIANT v;
	VariantInit(&v);
	v.vt=VT_BYREF|VT_VARIANT;
	v.pvarVal=new COleVariant(s);
	
	return v;
}

short CDssPref::GetCriterionInfoPB(short index, short FAR* type, BSTR FAR* name, BSTR FAR* description) 
{
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	*type=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetType();
	
	CString str;
	str = ((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetName();
	str.SetSysString(name);
	
	str = ((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetDescription();
	str.SetSysString(description);


	return 0;
}

short CDssPref::GetGradationPB(short index, short i, BSTR FAR* grad) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	CExponent* pG=((CExponent*)m_pDoc->m_Exp.GetAt(pos));
	if (pG->m_scale==NULL) return -1;
	if (pG->m_scale->GetGradation()<=i) return -1;
	
	CString str = pG->m_scale->GetLex(i);
	str.SetSysString(grad);

	return 0;
}

void CDssPref::Visible(BOOL bFlag) 
{
	CMainFrame *pMainWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(pMainWnd != NULL)
	{
		if(!bFlag && pMainWnd->IsWindowVisible())
			pMainWnd->ShowWindow(SW_HIDE);
		if(bFlag && !pMainWnd->IsWindowVisible())
			pMainWnd->ShowWindow(SW_SHOW);
	}
}

short CDssPref::SaveFile(LPCTSTR lpszFileName) 
{
	CUTESDoc* pDoc = NULL;
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = (CDocTemplate*) AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	if ((pDoc != NULL) && (pDoc->DoSave(lpszFileName)))
	{
		return 0;
	}
	return -1;
}

short CDssPref::NewFile() 
{
	CUTESDoc* pDoc = NULL;
	CMainFrame *pMainWnd = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = (CDocTemplate*) AfxGetApp()->
		GetNextDocTemplate(pos);
	BOOL bVisibleFlag = pMainWnd->IsWindowVisible();

	pDoc = (CUTESDoc*)pTemplate->OpenDocumentFile(NULL,TRUE);
	Visible(bVisibleFlag);
	
	if(pDoc != NULL)
	{
		m_pDoc = pDoc;
		return 0;
	}

	return -1;
}

short CDssPref::LoadCriterionPB(short type, LPCTSTR name, LPCTSTR description, double max_val, double min_val, short direction) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	
	if(pDoc != NULL)
	{
	    CExponentFactory expFactory;
        CExponent *pExp = NULL; 
		
        if((pExp = expFactory.CreateObject((int)type)) == NULL)
			return -1;

        pExp->SetName(name);
		pExp->SetDescription(description);
        pExp->SetMaxValue(max_val);
		pExp->SetMinValue(min_val);
		pExp->SetBestDir((int)direction);

		pDoc->m_Exp.AddTail(pExp);

		return 0;
	}


	return -1;
}

short CDssPref::SetCriterionArgPB(short index_pr, short index_ch) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	
	if(pDoc != NULL)
	{
		CExponent *pParent = NULL, *pChild = NULL; 

		if((pos = pDoc->m_Exp.FindIndex((int)index_pr)) == NULL)
			return -1;
		if((pParent = (CExponent*)pDoc->m_Exp.GetAt(pos)) == NULL)
			return -1;

		if((pos = pDoc->m_Exp.FindIndex((int)index_ch)) == NULL)
			return -1;
		if((pChild = (CExponent*)pDoc->m_Exp.GetAt(pos)) == NULL)
			return -1;
		
		if(pParent->GetType() != 3)
		{
			CExponentFactory expFactory;
			CExponent *pExp = NULL;

			if((pExp = expFactory.CreateObject(3)) == NULL)
				return -1;

			pExp->SetName(pParent->GetName());
			pExp->SetDescription(pParent->GetDescription());
			pExp->SetMaxValue(pParent->GetMaxValue());
			pExp->SetMinValue(pParent->GetMinValue());
			pExp->SetBestDir(pParent->GetBestDir());

			*pParent = *pExp;
		
			delete pExp;
		}

		pParent->m_agr.AddTail(pChild);

		return 0;
	}

	return -1;
}

short CDssPref::SetCriterionMethod(short index, short index_meth) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)	
	{
		CExponent *pExp = NULL;
		CDialogSelMethod dlg;

		if((pos = pDoc->m_Exp.FindIndex((int)index)) == NULL)
			return -1;
		if((pExp = (CExponent*)pDoc->m_Exp.GetAt(pos)) == NULL)
			return -1;

		switch(index_meth)
		{
		case -1:
			dlg.m_pE = pExp;
			
			if(dlg.DoModal() == IDCANCEL)
				return -1;

			break;
		default:
			break;
		}

		return 0; 
	}
	return -1;
}

short CDssPref::UpdateUTESView() 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)
	{
		pos = pDoc->GetFirstViewPosition();
		CUTESView *pView = (CUTESView*)pDoc->GetNextView(pos);

		if(pView == NULL)
			return -1;

		pView->RebildTree();
		pView->ReDrawCrit();
	
		return 0;
	}

	return -1;
}

short CDssPref::LoadScalePB(short index, short sc_type) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	
	if(pDoc != NULL)
	{
		CScaleFactory scaleFactory;
		CScale *pScale = NULL;
		CExponent *pExp = NULL;

		if((pos = pDoc->m_Exp.FindIndex((int)index)) == NULL)
			return -1;
		if((pExp = (CExponent*)pDoc->m_Exp.GetAt(pos)) == NULL)
			return -1;
		
		int type = pExp->GetType();

		switch(type)
		{
		case EXPONENT_LEXICAL:
			if((pScale = scaleFactory.
				CreateObject(SCALE_LEXICAL)) == NULL)
			{	 
				return -1;
			}
			pExp->m_scale = pScale;
			break;
		case EXPONENT_NUMBER:
			if((pScale = scaleFactory.
				CreateObject(SCALE_DISCRET)) == NULL)
			{	 
				return -1;
			}
			pExp->m_scale = pScale;
			break;
		case EXPONENT_GROUP:
			switch(sc_type)
			{
			case EXPONENT_LEXICAL:
				if((pScale = scaleFactory.
					CreateObject(SCALE_PREFERENCE)) == NULL)
				{
					return -1;
				}
				break;
			case EXPONENT_NUMBER:
				if((pScale = scaleFactory.
					CreateObject(SCALE_DISCRET)) == NULL)
				{
					return -1;
				}
				break;
			default:
				return -1;
			}
			pExp->m_scale = pScale;
			break;
		default:
			return -1;
		}

		return 0;
	}

	return -1;
}


short CDssPref::SetCriterionGradation(short index, LPCTSTR lpsz_grad) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)
	{
		CExponent *pExp = NULL;

		if((pos = pDoc->m_Exp.FindIndex((int)index)) == NULL)
			return -1;
		if((pExp = (CExponent*)pDoc->m_Exp.GetAt(pos)) == NULL)
			return -1;

		pExp->m_scale->SetGradation(lpsz_grad);

		return 0;
	}

	return -1;
}

BSTR CDssPref::GetDocPath() 
{
	CString strResult;
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)
	{
		strResult = pDoc->GetPathName();
	}

	return strResult.AllocSysString();
}

short CDssPref::GetGradationFromDouble(short index, double number, BSTR FAR* lp_grad) 
{
	CString strGrad;
	int grad_index;
	POSITION pos=NULL;
	CExponent *pExp = NULL;
	if((pos = m_pDoc->m_Exp.FindIndex((int)index)) == NULL)	return -1;
	pExp = (CExponent*)m_pDoc->m_Exp.GetAt(pos);
	if (pExp->m_scale->GetIndex(number, grad_index, pExp->m_Method)) return -1;
	strGrad = pExp->m_scale->GetLex(grad_index);
	strGrad.SetSysString(lp_grad);
	return 0;
}

short CDssPref::DeleteAll() 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)
	{
		pDoc->m_Exp.RemoveAll();

		return 0;
	}

	return -1;
}

short CDssPref::DeleteCriterion(short index) 
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);

	if(pDoc != NULL)
	{
		CExponent *pExp = NULL;

		if((pos = pDoc->m_Exp.FindIndex((int)index)) == NULL)
			return -1;
		
		pDoc->m_Exp.RemoveAt(pos);
		
		return 0;
	}

	return -1;
}

short CDssPref::GetMinMaxBest(short index, double FAR* min_value, double FAR* max_value, double FAR* best_value) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	*min_value=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetMinValue();
	*max_value=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetMaxValue();
	short dir=((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetBestDir();
	if (!dir) return -2;
	if (dir==1)
		*best_value=*max_value;
	else
		*best_value=*min_value;
	return 0;
}

short CDssPref::SetHWND(long hwnd) 
{
	// TODO: Add your dispatch handler code here
	CUTESDoc* pDoc = NULL;
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate* pTemplate = (CDocTemplate*) AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	if (pDoc != NULL) pDoc->m_hwnd=(HWND)hwnd;
	return 0;
}

short CDssPref::SetCriterionName(short index, LPCTSTR Name) 
{
	// TODO: Add your dispatch handler code here
	POSITION pos=m_pDoc->m_Exp.FindIndex(index);
	if (pos==NULL) return -1;
	((CExponent*)m_pDoc->m_Exp.GetAt(pos))->SetName(Name);
	return 0;
}

long CDssPref::GetCriterionIndex(LPCTSTR Name) 
{
	// TODO: Add your dispatch handler code here
	long i=0;
	POSITION pos=m_pDoc->m_Exp.GetHeadPosition();
	if (pos==NULL) return -1;
	while (pos!=NULL)
	{
		if (((CExponent*)m_pDoc->m_Exp.GetAt(pos))->GetName()==Name)
			return i;
		i++;
		m_pDoc->m_Exp.GetNext(pos);
	}
	return -2;
}
