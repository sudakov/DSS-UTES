//---------------------------------------------------------------------------
// DSS Library
// Copyright: (c) MAI 302 Department 1997/1998 Russia
//---------------------------------------------------------------------------
// Author: Andrew_Iltchenko
// Description: interface of CCritetion object
//---------------------------------------------------------------------------

class  CCriterion : public CObject
{
    DECLARE_SERIAL(CCriterion)
public:
// Type constants
   enum  criterion_type  {
      notset = -1,
      lexical,
      discret,
      interval,
      nonlimited
   };

// interface
   __declspec(dllimport) CCriterion();
   __declspec(dllimport) ~CCriterion();
	
   __declspec(dllimport) CCriterion::criterion_type  GetType();
   __declspec(dllimport) LPCTSTR  GetName();

   __declspec(dllimport) int  GetGradation();
   __declspec(dllimport) void  GetPoints(double* points);
	
   __declspec(dllimport) LPCTSTR  GetLex(int index);

// estimation functions
// 0 <= index < GetGradation()
   __declspec(dllimport) int  GetIndex(double x);
   __declspec(dllimport) int  GetIndex(CString term);

   __declspec(dllimport) int  DialogEdit(CWnd* pParent=NULL);

// overloading save and load procedures
   __declspec(dllimport) virtual void  Serialize(CArchive& ar);

private:
   CString   m_csTmp;
   void   * m_pDlg;
   CArray<CString, CString>   m_lexarr;
   CArray<double, double>   m_pntarr;
   criterion_type   m_ct;
   int   m_bStep;
   double   m_left,  m_right,  m_step;

};