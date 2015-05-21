//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Single document of DSS/UTES
// UTESDoc.cpp : implementation of the CUTESDoc class
//
//---------------------------------------------------------------------------


#include "stdafx.h"
#include "UTES.h"

#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
//#include "CritDialog.h"
//#include "Criterion.h"
//#include "CGroup.h"

#include "UTESDoc.h"
#include "DssPref.h"

//IMPLEMENT_SERIAL(CCriterion, CObject, 1)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUTESDoc

IMPLEMENT_DYNCREATE(CUTESDoc, CDocument)

BEGIN_MESSAGE_MAP(CUTESDoc, CDocument)
	//{{AFX_MSG_MAP(CUTESDoc)
	ON_COMMAND(ID_MENUITEM_IMPORT, OnImportDocument)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUTESDoc construction/destruction

CUTESDoc::CUTESDoc()
{
	// TODO: add one-time construction code here
	m_CritPos=0;
	CDssPref::m_pDoc=this;
	m_hwnd=NULL;
}

CUTESDoc::~CUTESDoc()
{
	if (m_hwnd!=NULL) PostMessage(m_hwnd, WM_USER, 0, 0);
}

BOOL CUTESDoc::OnNewDocument()
{

	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CUTESDoc serialization

void CUTESDoc::Serialize(CArchive& ar)
{
	POSITION pos,pos2;
	CStringList s;
	CExponent* pE;
	CString Buff;
	CString Name;
	
	if (ar.IsStoring())
	{
		if (m_hwnd!=NULL) PostMessage(m_hwnd, WM_USER, 0, 1);
		m_Exp.Serialize(ar);
		// TODO: add storing code here
		pos=m_Exp.GetHeadPosition();
		while (pos!=NULL)
		{
			s.RemoveAll();
			pE=(CExponent*)m_Exp.GetNext(pos);
			pos2=pE->m_agr.GetHeadPosition();
			while (pos2!=NULL)
				s.AddTail(((CExponent*)pE->m_agr.GetNext(pos2))->GetName());
			s.Serialize(ar);
		}
	}
	else
	{
		m_IsErr=FALSE;
		m_Exp.Serialize(ar);

#ifdef DEMOVER
		if (m_Exp.GetCount()>CRIT_LIM)
		{
			AfxMessageBox(" В демонстрационной программе Вы не можете\n работать с файлом, содержащим более 4-х показателей");
			m_IsErr=TRUE;
			DeleteContents();
			OnNewDocument();
			UpdateAllViews(NULL);
			return;
		}
#endif
		// TODO: add loading code here
		pos=m_Exp.GetHeadPosition();
		while (pos!=NULL)
		{
			s.Serialize(ar);
			while (!s.IsEmpty())
			{
				Buff=s.RemoveTail();
				pos2=m_Exp.GetHeadPosition();
				while (pos2!=NULL)
				{
					pE=(CExponent*) m_Exp.GetNext(pos2);
					if (pE->GetName()==Buff)
					{
						((CExponent*)m_Exp.GetAt(pos))->m_agr.AddHead(pE);
						pos2=NULL;
					}
				}
			}
			m_Exp.GetNext(pos);
		}

	}
}

/////////////////////////////////////////////////////////////////////////////
// CUTESDoc diagnostics

#ifdef _DEBUG
void CUTESDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUTESDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUTESDoc commands

BOOL CUTESDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	if (m_IsErr) return FALSE;
	return TRUE;
}

BOOL CUTESDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	CString Buff(lpszPathName);
	if (Buff.IsEmpty())
	{
		CString sFilter="Файлы Описания (*.uts) | *.uts ||";
		CFileDialog dlg(FALSE,"uts","*.uts",OFN_HIDEREADONLY|
			OFN_OVERWRITEPROMPT|OFN_PATHMUSTEXIST,(LPCTSTR) sFilter);
		if (dlg.DoModal()==IDOK)
		{
			Buff=dlg.GetPathName();
			AfxGetApp()->AddToRecentFileList(Buff);
		}
		else return FALSE;
	}
	return CDocument::OnSaveDocument(Buff);
}

void CUTESDoc::DeleteContents() 
{
/*	CCriterion *pC;
	while (!m_C.IsEmpty())
	{
		pC = (CCriterion*) m_C.RemoveHead();
		delete pC;
	}
	CGroup *pG;
	while (!m_G.IsEmpty())
	{
		pG = (CGroup*) m_G.RemoveHead();
		delete pG;
	}*/
	CExponent *pExp;
	while (!m_Exp.IsEmpty())
	{
		pExp=(CExponent*) m_Exp.RemoveHead();
		delete pExp;
	}

	CDocument::DeleteContents();
}

int CUTESDoc::SaveBeforDelete()
{
	CString buff;
	int rez;
	buff="Сохранить изменения в документе \""+GetTitle()+"\"?";
	if (IsModified()) rez=AfxMessageBox(buff,MB_YESNOCANCEL);
	else return TRUE;
	if (rez==IDYES) 
	{
		buff=GetPathName();
		return OnSaveDocument(buff);
	}
	if (rez==IDNO)  return TRUE;
	return FALSE;
}

BOOL CUTESDoc::SaveModified() 
{
	// TODO: Add your specialized code here and/or call the base class
	return SaveBeforDelete();
	//return CDocument::SaveModified();
}

void CUTESDoc::OnImportDocument() 
{
	// TODO: Add your command handler code here
	CString sFilter="Файлы Описания (*.uts) | *.uts ||";
	CFileDialog dlg(TRUE,"uts","*.uts",OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
		(LPCTSTR) sFilter);
	if (dlg.DoModal()==IDOK)
	{
		CFile file;
		if (file.Open(dlg.GetPathName(),CFile::modeRead))
		{
			CArchive ar(&file, CArchive::load);
			POSITION pos,pos2;
			CStringList s;
			CObList BuffList;
			CExponent* pE;
			CString Buff;
			CString Name;

			BuffList.Serialize(ar);

#ifdef DEMOVER
			if ((BuffList.GetCount()+m_Exp.GetCount())>CRIT_LIM)
			{
				AfxMessageBox(" В демонстрационной программе Вы не можете\n работать с файлом, содержащим более 4-х показателей");
				return;
			}
#endif
			pos=BuffList.GetHeadPosition();
			while (pos!=NULL)
			{
				s.Serialize(ar);
				while (!s.IsEmpty())
				{
					Buff=s.RemoveTail();
					pos2=BuffList.GetHeadPosition();
					while (pos2!=NULL)
					{
						pE=(CExponent*) BuffList.GetNext(pos2);
						if (pE->GetName()==Buff)
						{
							((CExponent*)BuffList.GetAt(pos))->m_agr.AddHead(pE);
							pos2=NULL;
						}
					}
				}
				BuffList.GetNext(pos);
			}
			pos=BuffList.GetHeadPosition();
			while (pos!=NULL)
			{
				pE=(CExponent*) BuffList.GetNext(pos);
				pos2=m_Exp.GetHeadPosition();
				while (pos2!=NULL)
				{
					if (pE->GetName()==
						((CExponent*) m_Exp.GetNext(pos2))->GetName())
					{
						AfxMessageBox("Обнаружен дублирующийся показатель\""+
							pE->GetName()+"\"");
						CExponent *pExp;
						while (!BuffList.IsEmpty())
						{
							pExp=(CExponent*) BuffList.RemoveHead();
							delete pExp;
						}
						return;
					}
				}
			}
			m_Exp.AddTail(&BuffList);
			SetModifiedFlag();
			UpdateAllViews(NULL);
			ar.Close();
		}
		file.Close();
	}
}

CUTESDoc* GetMyDoc()
{
	POSITION pos = AfxGetApp()->GetFirstDocTemplatePosition();
	CDocTemplate *pTemplate = (CDocTemplate*)AfxGetApp()->
		GetNextDocTemplate(pos);
	pos = pTemplate->GetFirstDocPosition();
	CUTESDoc *pDoc = (CUTESDoc*)pTemplate->GetNextDoc(pos);
	return pDoc;
}