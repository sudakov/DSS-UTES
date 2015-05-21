// Protection.h: interface for the CProtection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROTECTION_H__71E3B3E1_AB5E_11D3_9B7C_14F4F9C00000__INCLUDED_)
#define AFX_PROTECTION_H__71E3B3E1_AB5E_11D3_9B7C_14F4F9C00000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define SP_CODE 312

class CProtection  
{
public:
	CProtection();
	virtual ~CProtection();

	void LoadInfo();
	int CheckStatus(int ID=0);
	DWORD GetCorrectNumber(DWORD code);
	DWORD SetScriptNumber(DWORD n);

	void SetRegValue(HKEY hKey,CString strKey,CString strChildKey, CString strChildKeyValue);
	void SetRegValue(HKEY hKey,CString strKey,CString strChildKey, DWORD dwChildKeyValue);

	DWORD m_CompID;
	DWORD m_ProgID;
	DWORD m_ProgCode;
	int m_is_demo;
	
};

#endif // !defined(AFX_PROTECTION_H__71E3B3E1_AB5E_11D3_9B7C_14F4F9C00000__INCLUDED_)
