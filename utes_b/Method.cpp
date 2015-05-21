//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Preference Methods implemention
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "UTES.h"
#include <atlbase.h>
#include "Method.h"
#include "Scale.h"
#include "Exponent.h"
#include "factory.h"
#include "GroupSet.h"
#include "UTESDoc.h"
#include "PrefView.h"
#include "PointView.h"
#include "WeightView.h"
#include "fserver.h"
#include "DialogRobast.h"
#include "math.h"

IMPLEMENT_SERIAL(CMethod, CObject,	1)
IMPLEMENT_SERIAL(CMethodPR, CObject, 1)
IMPLEMENT_SERIAL(CMethodWE, CObject, 1)
IMPLEMENT_SERIAL(CMethodOLE, CObject, 1)
IMPLEMENT_SERIAL(CMethodIP, CObject, 1)


CMethod& CMethod::operator=(const CMethod& other)
{
	return *this;
}

CMethodPR::CMethodPR()
{
	for (int i=0; i<MAX_E; i++) m_v[i]=0;
	m_P.RemoveAll();
	m_robast=0;
	m_is_number=FALSE;
	for (int i=0; i<MAX_E; i++) m_U[i]=0;
	m_XName="";
	m_YName="";
	m_is_grad=FALSE;
}

CMethodPR::~CMethodPR()
{
	m_P.RemoveAll();
}


void CMethodPR::SerializeNew(CArchive& ar)
{
	int i=0;
	if (ar.IsLoading())
	{
		// read in current version of
		// this object
		m_P.Serialize(ar);
		for (i=0; i<MAX_E; i++)	ar >> m_v[i];
		for (i=0; i<MAX_E; i++)	ar >> m_U[i];
		ar >> m_robast >> m_is_number >> m_XName >> m_YName >> m_is_grad;
	}
	else
	{
		m_P.Serialize(ar);
		for (i=0; i<MAX_E; i++)	ar << m_v[i];
		for (i=0; i<MAX_E; i++)	ar << m_U[i];
		ar << m_robast << m_is_number << m_XName << m_YName << m_is_grad;
	}
}

void CMethodPR::Serialize(CArchive& ar)
{
	int i=0;
	if (ar.IsLoading())
	{
		// read in previous version of 
		// this object
		m_P.Serialize(ar);
		for (i=0; i<MAX_E; i++)	ar >> m_v[i];		
	}
	else
	{
		m_P.Serialize(ar);
		for (i=0; i<MAX_E; i++)	ar << m_v[i];
		ar << m_robast << m_is_number;
	}
}

CMethodPR& CMethodPR::operator=(const CMethodPR& other)
{
	int n=other.m_P.GetSize();
	m_P.SetSize(n);
	for (int i=0; i<n; i++) m_P[i]=other.m_P[i];
	for (int i=0; i<MAX_E; i++) m_v[i]=other.m_v[i];
	for (int i=0; i<MAX_E; i++) m_U[i]=other.m_U[i];
	m_robast=other.m_robast;
	m_is_number=other.m_is_number;
	m_XName=other.m_XName;
	m_YName=other.m_YName;
	m_pE=other.m_pE;
	m_is_grad=other.m_is_grad;
	return *this;
}

CView* CMethodPR::CreateEditView()
{
	CPrefView* pV=new CPrefView();
	pV->m_pG=m_pE;
	pV->m_pM=this;
	return pV;
}


void CMethodPR::SetCritDim()
{
	int s=1;
	POSITION pos=m_pE->m_agr.GetHeadPosition();
	int i=0;
	CExponent* pE;
	while (pos!=NULL)
	{
		pE=(CExponent*)m_pE->m_agr.GetNext(pos);
		if (pE->m_scale!=NULL) m_v[i]=pE->m_scale->GetGradation();
		else m_v[i]=0;
		if ((m_v[i]-1)<m_U[i]) m_U[i]=0;
		s*=m_v[i];
		i++;
	}
	m_P.RemoveAll();
	m_P.SetSize(s);
	for (i=0; i<s; i++) m_P[i]=255;
}

void CMethodPR::SetPreference(int *i, int p)
{
	int index=0;
	int n=m_pE->m_agr.GetCount();
	int s=1;
	for (int j=0; j<n; j++)
	{
		index+=s*i[j];
		s*=m_v[j];
	}
	m_P[index]=p;
}

int CMethodPR::GetPreferance(int *i)
{
	int index=0;
	int n=m_pE->m_agr.GetCount();
	int s=1;
	for (int j=0; j<n; j++)
	{
		index+=s*i[j];
		s*=m_v[j];
	}
	return m_P[index];
}

void CMethodPR::GetCritDim(int *v)
{
	int n = m_pE->m_agr.GetCount();
	for (int i=0; i<n; i++)	v[i] = m_v[i];
}

int CMethodPR::GetValue(double& x)
{
	POSITION pos=m_pE->m_agr.GetHeadPosition();
	int index=0;
	int n=m_pE->m_agr.GetCount();
	int s=1;
	int i;
	double v=0;

	for (int j=0; j<n; j++)
	{
		if (((CExponent*)m_pE->m_agr.GetNext(pos))->GetGradation(i))
			return -1;
		index+=s*i;
		s*=m_v[j];
	}
	if (!IsValid()) return -1;
	if (m_P[index]>254) return -1;
	if (m_pE->m_scale->GetRang(m_P[index],v)) x=(double) m_P[index];
	else x=v;

	return 0;
}

/*int CMethod::Estimate()
{
	int v[10];
	double x;
	for (int i=0; i<m_cc.GetCount(); i++)
	{
		((CExponent*)m_c[i])->GetValue(x);
		v[i]=(int)x;
		if (v[i]==-1) return -1;
	}
	return GetPreferance(v);
}*/

int CMethodPR::GetType()
{
	return METHOD_PREFERENCE;
}


int CMethodPR::IsValid()
{
	if (m_pE->m_scale==NULL) 
	{
		m_err_msg="Не задана шкала для обобщенного показателя "+m_pE->GetName();
		return 0;
	}
	if (m_robast<m_pE->m_scale->GetGradation()) m_robast=m_pE->m_scale->GetGradation();
	POSITION pos=m_pE->m_agr.GetHeadPosition();
	CExponent* pE;
	while (pos!=NULL)
	{
		pE=(CExponent*) m_pE->m_agr.GetNext(pos);
		if (((CScale*) pE->m_scale)
		    ==NULL) 
		{
			m_err_msg="Не задана шкала для показателя "+pE->GetName();
			return 0;
		}
	}
	pos=m_pE->m_agr.GetHeadPosition();
	int i=0;
	while (pos!=NULL)
		if ( ( (CScale*) ( (CExponent*) m_pE->m_agr.GetNext(pos)
			             )->m_scale
			 )->GetGradation()
			  != (int) m_v[i++]
		   ) { SetCritDim(); return 1;}
	
	return 1;
}

int CMethodPR::SetOptions()
{
	CDialogRobast dlg;
	dlg.m_pMethod=this;
	dlg.DoModal();
	return 0;
}

CMethodWE::CMethodWE()
{
	m_W.RemoveAll();
	m_Norm=1;
}

CMethodWE::~CMethodWE()
{
	;
}

int CMethodWE::GetType()
{
	return METHOD_WEIGHT;
}

CView* CMethodWE::CreateEditView()
{
	CWeightView* pV=new CWeightView();
	pV->m_pE=m_pE;
	pV->m_pM=this;
	return pV;
}

void CMethodWE::Serialize(CArchive& ar)
{
	m_W.Serialize(ar);
	if (ar.IsStoring())	ar << m_Norm;
	else ar >> m_Norm;

}

CMethodWE& CMethodWE::operator=(const CMethodWE& other)
{
	int n=other.m_W.GetSize();
	m_W.SetSize(n);
	for (int i=0; i<n; i++) m_W[i]=other.m_W[i];
	m_Norm=other.m_Norm;
	m_pE=other.m_pE;
	return *this;
}

int CMethodWE::GetValue(double& x)
{
	POSITION pos=m_pE->m_agr.GetHeadPosition();
	CExponent* pE;
	int index=0;
	int n=m_pE->m_agr.GetCount();
	double s=0;
	double v;
	double a=0.0; double b=1.0;
	double d=1;
	if (m_W.GetSize()!=n) return -1;
	for (int j=0; j<n; j++)
	{
		pE=(CExponent*)m_pE->m_agr.GetNext(pos);
		if (pE->GetValue(v))
			return -1;
		if (m_Norm) {
			switch (pE->GetType()) {
			case EXPONENT_LEXICAL:
				if (pE->m_scale==NULL) return -1;
				b=pE->m_scale->GetGradation()-1;
				break;
			case EXPONENT_NUMBER:
				a=pE->GetMinValue();
				b=pE->GetMaxValue();
				//if (a==b) return -1;
				d=pE->GetBestDir();
				if (!d) return -1;
				if (a!=b) break;
				if (pE->m_scale==NULL) return -1;
				if (pE->m_scale->GetRange(a,b)) return -1;
				break;
			case EXPONENT_GROUP:
				a=pE->GetMinValue();
				b=pE->GetMaxValue();
				//if (pE->GetBestDir()!=1) return -1;
				d=pE->GetBestDir();
				if (!d) return -1;
				if (a!=b) break;
				if (pE->m_scale==NULL) return -1;
				if ((pE->m_scale->GetType()==SCALE_LEXICAL)||
					(pE->m_scale->GetType()==SCALE_PREFERENCE))
				{
					a=0; b=pE->m_scale->GetGradation()-1;
					break;
				}
				if (pE->m_scale->GetRange(a,b)) return -1;
				break;
			}
		}			
		if (d==1)
			s+=m_W[j]*(v-a)/(b-a);
		else
			s+=m_W[j]*(b-v)/(b-a);
	}
	a=m_pE->GetMinValue();
	b=m_pE->GetMaxValue();
	if ((m_Norm)&&(a!=b))
		if (pE->GetBestDir()==-1) x=b - (b-a) * s;
		else x=a + (b-a) * s;
	else
		x=s;
	return 0;
}

int CMethodPR::IsAllPref()
{
	for (int i = 0; i < m_P.GetSize(); i++)
		if (m_P[i]>254) return 0;
	return 1;
}

CMethodOLE::CMethodOLE()
{
	m_Type=0;
}

CMethodOLE::CMethodOLE(int t)
{
	m_Type=t;
	CComBSTR cbstr;
	CMethodFactory mf;
	//LPDISPATCH pDisp;
	//LPUNKNOWN pUnk;
	CLSID clsid;
	CString buf;
	if (m_fmod.m_lpDispatch == NULL)
	{
	  TRACE("Entering ::On_fmodConnect\n");
	  if (mf.GetProgID(m_Type, buf))
	  {
		  AfxMessageBox("Ошибка файла настройки!");
		  return;
	  }
	  AfxGetApp()->BeginWaitCursor();
	  cbstr=buf;
	  if (::CLSIDFromProgID(cbstr, &clsid)!=S_OK) // from registry
	  	  AfxMessageBox("Ошибка файла настройки! Модуль не найден");
	  else
	  {
	  /*if(::GetActiveObject(clsid, NULL, &pUnk) == S_OK) {
		TRACE("attaching\n");
		VERIFY(pUnk->QueryInterface(IID_IDispatch,
            (void**) &pDisp) == S_OK);
		m_fmod.AttachDispatch(pDisp);
		pUnk->Release();
	  } 
      else {*/
		TRACE("creating\n");
		VERIFY(m_fmod.CreateDispatch(buf) == TRUE);
//		VERIFY(m_app.CreateDispatch(excelClsid) == TRUE);
	  //}
	  }
	  AfxGetApp()->EndWaitCursor();
	}
	m_fmod.SetVisible(0);
	
}

CMethodOLE::~CMethodOLE()
{
	m_fmod.ReleaseDispatch();
}

int CMethodOLE::GetType()
{
	return m_Type;
}

CView* CMethodOLE::CreateEditView()
{
	m_fmod.SetAggr(m_pE->GetName());
	m_fmod.SetVisible(1);
	//CWnd* pWnd = CWnd::FindWindow("Ribba", NULL);
	//if (pWnd != NULL) {
	//	TRACE("Mxm window found\n");
		//pWnd->ShowWindow(SW_SHOW);   //NORMAL);
		//pWnd->UpdateWindow();
		//pWnd->BringWindowToTop();
     //pWnd->RedrawWindow(NULL,NULL,RDW_INVALIDATE);
   //}
	return NULL;
}

void CMethodOLE::Serialize(CArchive& ar)
{
	CMethodFactory mf;
	CLSID clsid;
    LPCLASSFACTORY pClf; 
    LPUNKNOWN pUnk;
    IRibbaFServer* pMot;
    HRESULT hr;
	CString buf2;
	CComBSTR cbstr;
	
	if (ar.IsStoring())	
	{
		ar << m_Type;
		
		if (mf.GetProgID2(m_Type, buf2)) 
		{
			return;	
		}
		cbstr=buf2;
		if ((hr = ::CLSIDFromProgID(cbstr, &clsid)) != NOERROR) {
			TRACE("unable to find Program ID -- error = %x\n", hr);
			return;
		}
		if ((hr = ::CoGetClassObject(clsid, CLSCTX_LOCAL_SERVER,
			NULL, IID_IClassFactory, (void **) &pClf)) != NOERROR) {;
			TRACE("unable to find CLSID -- error = %x\n", hr);
			return;
		}

		pClf->CreateInstance(NULL, IID_IUnknown, (void**) &pUnk);
		pUnk->QueryInterface(IID_IRibbaFServer, (void**) &pMot); // all three
		TRACE("main: pUnk = %p, pMot = %p\n", pUnk, pMot);
    
		// test all the interface virtual functions
		CString path=ar.GetFile()->GetFilePath();
		if (path!="")
		{
			int pos=path.ReverseFind('.');
			if (pos>0)
			{
				//COleVariant buf= COleVariant("@save|"+path.Mid(0,pos));
				COleVariant buf= COleVariant("@save|"+path);
				pMot->OutMessage(buf.bstrVal);
			}
		}
		pClf->Release();
		pUnk->Release();
		pMot->Release();
    }
	else ar >> m_Type;
}

int CMethodOLE::GetValue(double& x)
{
	double v=0;
	int r=0;
	m_fmod.SetAggr(m_pE->GetName());
	r=m_fmod.GetValue(&v);
	x=v;
	return r;
}

int CMethodOLE::IsValid()
{
	return 1;
}

CMethodOLE& CMethodOLE::operator=(const CMethodOLE& other)
{
	m_Type=other.m_Type;
	m_pE=other.m_pE;
	return *this;
}


CMethodPC::CMethodPC(CMethodWE* m_pM, int SetM)
{
	this->m_pM = m_pM;
	for(int i = 0; i < m_PC.GetSize(); i++) {
		m_PC[i].RemoveAll();
	}
	m_PC.RemoveAll();
	int n = m_pM->m_pE->m_agr.GetSize();
	m_PC.SetSize(n);
	for(int i = 0; i < n; i++) {
		m_PC[i].SetSize(n);
		for (int j = 0; j < n; j++) {
			m_PC[i][j].m_Value = 1;
		}
	}
	m_Type = -1;
	// Генерация МПС из весовых коэффициентов
	if (SetM == IDYES) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				m_PC[i][j].m_Value = m_pM->m_W[i]/m_pM->m_W[j];
		}
	}
}

CMethodPC::~CMethodPC()
{
	for(int i = 0; i < m_PC.GetSize(); i++) {
		m_PC[i].RemoveAll();
	}
	m_PC.RemoveAll();
	m_pM = NULL;
}

void CMethodPC::SetType(int new_Type, int new_Main)
{
	Check();
	m_Type = new_Type;
	m_Main = new_Main;
	int n = m_PC.GetSize();
	// Сброс настроек отображения/приоритетности
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			m_PC[i][j].m_EP = false;
		}
	// Уставновка приоритетности в зависимости от варианта заполнения МПС
	switch (m_Type) {
	case TYPE_ONE_WITH_ALL:
		for (int i = 0; i < n; i++)
			if (m_PC[m_Main][i].m_Value >=1 ) m_PC[m_Main][i].m_EP = true;
			else m_PC[m_Main][i].m_EP = false;
		break;
	case TYPE_SHORT:
		for (int i = 0; i < n-1; i++)
			if (m_PC[i][i+1].m_Value >=1 ) m_PC[i][i+1].m_EP = true;
			else m_PC[i][i+1].m_EP = false;
		break;
	case TYPE_FULL:
		for (int i = 0; i < n-1; i++)
			for (int j = i+1; j < n; j++)
				if (m_PC[i][j].m_Value >=1 ) m_PC[i][j].m_EP = true;
				else m_PC[i][j].m_EP = false;
		break;
	}
}

void CMethodPC::SetValue(float new_Value, int i)
{
	int j;
	Indexer(i,j);
	if (m_PC[i][j].m_EP)
		m_PC[i][j].m_Value = new_Value;
	else m_PC[j][i].m_Value = new_Value;
}

int CMethodPC::GetType()
{
	return m_Type;
}

int CMethodPC::GetMain()
{
	return m_Main;
}

float CMethodPC::GetValue(int i)
{
	int j;
	Indexer(i,j);
	if (m_PC[i][j].m_EP)
		return m_PC[i][j].m_Value;
	else return m_PC[j][i].m_Value;
}

void CMethodPC::GetWeights()
{
	m_pM->m_W.RemoveAll();
	m_pM->m_W.SetSize(m_PC.GetSize());
	Check();
	for (int i = 0; i < m_PC.GetSize(); i++) {
		m_pM->m_W[i] = 1;
		for (int j = 0; j < m_PC.GetSize(); j++) {
			m_pM->m_W[i] *= m_PC[i][j].m_Value;
		}
		m_pM->m_W[i] = pow(m_pM->m_W[i],(1.0/m_PC.GetSize()));
	}
}

void CMethodPC::Check()
{
	// Доопределение МПС в соответствии с вариантом её заполнения
	switch (m_Type) {
	case TYPE_ONE_WITH_ALL:
		for (int i = 0; i < m_PC.GetSize(); i++) {
			if (m_PC[m_Main][i].m_EP) m_PC[i][m_Main].m_Value = 1.0/m_PC[m_Main][i].m_Value;
			else m_PC[m_Main][i].m_Value = 1.0/m_PC[i][m_Main].m_Value;
		}
		for (int i = 0; i < m_PC.GetSize(); i++) {
			if (i != m_Main) {
				for (int j = 0; j < m_PC.GetSize(); j++) {
					m_PC[i][j].m_Value = m_PC[m_Main][j].m_Value/m_PC[m_Main][i].m_Value;
				}
			}
		}
		break;
	case TYPE_SHORT:
		for (int i = 0; i < m_PC.GetSize()-1; i++) {
			if (m_PC[i][i+1].m_EP) m_PC[i+1][i].m_Value = 1.0/m_PC[i][i+1].m_Value;
			else m_PC[i][i+1].m_Value = 1.0/m_PC[i+1][i].m_Value;
		}
		// Подиагональное заполнение
		for (int i = 2; i < m_PC.GetSize(); i++) {
			for (int j = 0; j < m_PC.GetSize()-i; j++) {
				m_PC[j][i+j].m_Value = m_PC[j][j+1].m_Value*m_PC[j+1][i+j].m_Value;
				m_PC[i+j][j].m_Value = 1.0/m_PC[j][i+j].m_Value;
			}
		}
		break;
	case TYPE_FULL:
		for (int i = 0; i < m_PC.GetSize()-1; i++) {
			for (int j = i+1; j < m_PC.GetSize(); j++) {
				if (m_PC[i][j].m_EP) m_PC[j][i].m_Value = 1.0/m_PC[i][j].m_Value;
				m_PC[i][j].m_Value = 1.0/m_PC[j][i].m_Value;
			}
		}
		// Согласование матрицы
		// Генерация весовых коэффициентов в первом столбце МПС
		for (int i = 0; i < m_PC.GetSize(); i++) {
			for (int j = 1; j < m_PC.GetSize(); j++) {
				m_PC[i][0].m_Value *= m_PC[i][j].m_Value;
			}
			m_PC[i][0].m_Value = pow(m_PC[i][0].m_Value,(float)(1.0/m_PC.GetSize()));
		}
		// Расчёт МПС из полученных весовых коэффициентов	
		float n;
		for (int j = m_PC.GetSize()-1; j >= 0; j--) {
			n = m_PC[j][0].m_Value;
			for (int i = 0; i < m_PC.GetSize(); i++) {
				m_PC[i][j].m_Value = m_PC[i][0].m_Value/n;
			}
		}
		break;
	}
}

void CMethodPC::ChangePreferable(int i)
{
	int j;
	Indexer(i,j);
	m_PC[i][j].m_EP = !m_PC[i][j].m_EP;
	if (m_PC[i][j].m_EP) {
		m_PC[i][j].m_Value = m_PC[j][i].m_Value;
	} else {
		m_PC[j][i].m_Value = m_PC[i][j].m_Value;
	}
}

void CMethodPC::Indexer(int &i, int &j)
{
	switch (m_Type) {
	case TYPE_ONE_WITH_ALL:
		if (i<m_Main) j = i;
		else j = i+1;
		i = m_Main;
		break;
	case TYPE_SHORT:
		j = i+1;
		break;
	case TYPE_FULL:
		float b = 2*(m_PC.GetSize()-1)+1;
		int k = (int)((b-sqrt(pow(b,2)-8*(i)))/2);
		j = i - (b-k)*k/2+k+1;
		i = k;
		break;
	}
}

bool CMethodPC::IsPreferable(int i)
{
	int j;
	Indexer(i,j);
	return m_PC[i][j].m_EP;
}


CMethodIP::CMethodIP()
{
	m_W.RemoveAll();
}

CMethodIP::~CMethodIP()
{
	m_W.RemoveAll();
}

CView* CMethodIP::CreateEditView()
{
	CPointView* pV=new CPointView();
	pV->m_pE=m_pE;
	pV->m_pM=this;
	return pV;
}


int CMethodIP::GetType()
{
	return METHOD_POINT;
}


void CMethodIP::Serialize(CArchive& ar)
{
	m_W.Serialize(ar);
}


int CMethodIP::GetValue(double& x)
{
	POSITION pos=m_pE->m_agr.GetHeadPosition();
	double v;
	double a,b;
	double sum = 0;
	double max;
	CExponent* pE;
	int n=m_pE->m_agr.GetCount();
	if (m_W.GetSize()!=n) return -1;
	for (int j=0; j<n; j++) {
		pE=(CExponent*)m_pE->m_agr.GetNext(pos);
		if (pE->GetValue(v))
			return -1;
		switch (pE->GetType()) {
		case EXPONENT_LEXICAL:
			if (pE->m_scale==NULL) return -1;
			a=0;
			b=pE->m_scale->GetGradation()-1;
			break;
		case EXPONENT_NUMBER:
			a=pE->GetMinValue();
			b=pE->GetMaxValue();
			if (a!=b) break;
			if (pE->m_scale==NULL) return -1;
			if (pE->m_scale->GetRange(a,b)) return -1;
			break;
		case EXPONENT_GROUP:
			a=pE->GetMinValue();
			b=pE->GetMaxValue();
			if (a!=b) break;
			if (pE->m_scale==NULL) return -1;
			if ((pE->m_scale->GetType()==SCALE_LEXICAL)||
			(pE->m_scale->GetType()==SCALE_PREFERENCE))
			{
				a=0; b=pE->m_scale->GetGradation()-1;
				break;
			}
			if (pE->m_scale->GetRange(a,b)) return -1;
			break;
		}
		max = b-m_W[j];
		if (max < m_W[j]-a) max = m_W[j]-a;
		v = (v - m_W[j])/max;
		sum += pow(v,2);
	}
	x = pow(sum/n,0.5);
	a=m_pE->GetMinValue();
	b=m_pE->GetMaxValue();
	if (a!=b)
		x=b - (b-a) * x;
	return 0;
}


CMethodIP& CMethodIP::operator=(const CMethodIP& other)
{
	int n=other.m_W.GetSize();
	m_W.SetSize(n);
	for (int i=0; i<n; i++) m_W[i]=other.m_W[i];
	m_pE=other.m_pE;
	return *this;
}