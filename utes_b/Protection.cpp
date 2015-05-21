// Protection.cpp: implementation of the CProtection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UTES.h"
#include "Protection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtection::CProtection()
{
	m_CompID=0;
	m_ProgID=0;
	m_ProgCode=0;
	m_is_demo=FALSE;
}

CProtection::~CProtection()
{

}

void CProtection::LoadInfo()
{
   m_CompID=0;
   m_ProgID=0;
   m_ProgCode=0;
   WORD Comp;
   CString strKey = 
      "Software\\MAI_DSS\\DSS-UTES\\Extentions";
return ;
   // Open the registry key
   HKEY hResult;
   if (ERROR_SUCCESS != RegOpenKey(HKEY_CURRENT_USER, 
       (LPCTSTR) strKey, &hResult)) 
   {
	   AfxMessageBox("Ошибка считывания серийного номера!!!");
	   return;
   }

   // Get the values
   DWORD  dwCount = sizeof(DWORD);
   DWORD type;

   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "Serial No", 0, &type, 
      (BYTE*) &m_ProgID, &dwCount))
   {
	 m_ProgID=0;
     RegCloseKey(hResult);    // Close the key
     AfxMessageBox("Ошибка считывания серийного номера!!!");
	 return;
   }

   dwCount = sizeof(DWORD);
   
   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "ProgCode", 0, &type, 
      (BYTE*) &m_ProgCode, &dwCount))
   {
     m_ProgCode=0;
     AfxMessageBox("Не задан регистрационный код программы.\n"
		           "Обратитесь к поставщику программы");
   }
   RegCloseKey(hResult);

   int i=0;
   BYTE szBuf[255];
   
   OSVERSIONINFO osvi;
   osvi.dwOSVersionInfoSize=sizeof(OSVERSIONINFO);
   GetVersionEx (&osvi);
   switch (osvi.dwPlatformId)
   {
   case VER_PLATFORM_WIN32_WINDOWS:
   strKey = "Enum\\Root\\*PNP0C01\\0000";

   if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE, 
       (LPCTSTR) strKey, &hResult)) 
   {
	   m_CompID=HIWORD(m_ProgID << 13);
	   return;
   }
   
   dwCount=255;
   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "BiosDate", 0, &type, 
      &szBuf[0], &dwCount))
   {
		m_CompID=100;
   }
   else while (szBuf[i]!=0) m_CompID+=szBuf[i++];
   
   dwCount=255;
   
   i=0;
   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "BiosVersion", 0, &type, 
      &szBuf[0], &dwCount))
   {
		m_CompID+=666;
   }
   else while (szBuf[i]!=0) m_CompID+=szBuf[i++];
   m_CompID=m_CompID << 6;
   Comp=LOWORD(m_ProgID);
   Comp=Comp >> 6;
   m_CompID+=Comp;
   RegCloseKey(hResult);
   return;
   
   case VER_PLATFORM_WIN32_NT:
   strKey = "HARDWARE\\DESCRIPTION\\System";

   if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE, 
       (LPCTSTR) strKey, &hResult)) 
   {
	   //AfxMessageBox("Ошибка вызова указателя Bios");
	   m_CompID=HIWORD(m_ProgID << 13);
	   return;
   }
   
   
   dwCount=255;
   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "SystemBiosDate", 0, &type, 
      &szBuf[0], &dwCount))
   {
	   //AfxMessageBox("Ошибка вызова даты Bios");
		m_CompID=100;
   }
   else while (szBuf[i]!=0) m_CompID+=szBuf[i++];
   
   dwCount=255;
   
   i=0;
   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "SyatemBiosVersion", 0, &type, 
      &szBuf[0], &dwCount))
   {
	    //AfxMessageBox("Ошибка вызова версии Bios");
		m_CompID+=666;
   }
   else while (szBuf[i]!=0) m_CompID+=szBuf[i++];
   m_CompID=m_CompID << 6;
   Comp=LOWORD(m_ProgID);
   Comp=Comp >> 6;
   m_CompID+=Comp;
   RegCloseKey(hResult);
   return;
   default:
   m_CompID=HIWORD(m_ProgID << 13);
   }
   return;
}

int CProtection::CheckStatus(int ID)
{
   return 0;
   
   // Specify the registry location to get data from
   CString strKey = 
      "SOFTWARE\\Classes\\CLSID\\{71E3B3E1-AB5E-11D3-9B7C-14F4F9C00000}\\InProcServer32";

   // Open the registry key
   HKEY hResult;
   if (ERROR_SUCCESS != RegOpenKey(HKEY_LOCAL_MACHINE, 
       (LPCTSTR) strKey, &hResult)) 
   {
        AfxMessageBox("Переустановите программу с дистрибутива");
		return -2;
   }

   // Get the values
   DWORD   ProgID=0;
   DWORD  dwCount = sizeof(DWORD);
   DWORD type;

   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "ProgID", 0, &type, 
      (BYTE*) &ProgID, &dwCount))
   {
     RegCloseKey(hResult);    // Close the key
     AfxMessageBox("Переустановите программу с дистрибутива");
	 return -2;
   }
   
   if (!ProgID)
   {
     RegCloseKey(hResult);
     AfxMessageBox("Переустановите программу с дистрибутива");
     return -2;
   }
   

   ProgID=GetCorrectNumber(ProgID);
   DWORD r=ProgID / 13;
   
   if ((!ProgID)||(ProgID>0xf0000000)||((r*13)!=ProgID)||
	   (ProgID!=m_ProgID))
   {
     RegCloseKey(hResult);
     AfxMessageBox("Переустановите программу с дистрибутива");
     return -2;
   }

   // Close the key
   RegCloseKey(hResult);

   if (((ID==0)&&(m_ProgCode!=0))||(ID>0))
   {
	   ///
	   if ((m_ProgCode==SP_CODE)&&(m_ProgID==SP_CODE)) return 0;
	   double c=m_CompID;
	   double s=m_ProgID;
	   double res=c*c/2000-s*s/3000-c*s/1000+c/4-s/7+66;
	   DWORD* cc;
	   cc=(DWORD*) &res;
	
	   if ((*cc)!=m_ProgCode) return -1;
   }
   
   return 0;
}

DWORD CProtection::GetCorrectNumber(DWORD code)
{
	return ~code;
}

DWORD CProtection::SetScriptNumber(DWORD n)
{
	return ~n;
}

///////////////////////////////////////////////////////////////////
// CWallFlipDlg::SetRegValue() - writes a registry string value

void CProtection::SetRegValue(HKEY hKey, 
                              CString strKey, 
                              CString strChildKey, 
                              CString strChildKeyValue)
{
   HKEY   hChildKey = 0;
   DWORD  dwDisposition;

   // Create or open the registry key
   RegCreateKeyEx(hKey,
      (LPCTSTR) strKey, 
      0, 
      NULL, 
      REG_OPTION_NON_VOLATILE,
      KEY_CREATE_SUB_KEY | KEY_ALL_ACCESS, 
      NULL, 
      &hChildKey,
      &dwDisposition
   );   

   // Set the new value for the key
   RegSetValueEx(
      hChildKey,
      (LPCTSTR) strChildKey, 
      0,
      REG_SZ,
      (const BYTE*)(LPCTSTR)strChildKeyValue, 
      (DWORD) strChildKeyValue.GetLength()
   );
   // Close the key
   RegCloseKey(hChildKey);
}

///////////////////////////////////////////////////////////////////
// CWallFlipDlg::SetRegValue() - writes a registry dword value

void CProtection::SetRegValue(HKEY hKey, 
                               CString strKey, 
                               CString strChildKey, 
                               DWORD dwChildKeyValue)
{
   HKEY  hChildKey = 0;
   DWORD dwDisposition;

   // Create or open the registry key
   RegCreateKeyEx(hKey,
      (LPCTSTR) strKey, 
      0, 
      NULL, 
      REG_OPTION_NON_VOLATILE,
      KEY_CREATE_SUB_KEY | KEY_ALL_ACCESS, 
      NULL, 
      &hChildKey,
      &dwDisposition
   );   

   // Set the new value for the key
   RegSetValueEx(
      hChildKey,
      (LPCTSTR) strChildKey, 
      0,
      REG_DWORD,
      (const BYTE*) &dwChildKeyValue, 
      sizeof(DWORD)
   );
   RegCloseKey(hChildKey);
}

///////////////////////////////////////////////////////////////////
// CWallFlipDlg::OnDestroy() 

/*void CWallFlipDlg::OnDestroy() 
{
   // Call inherited method
   CDialog::OnDestroy();

   // Specify the registry location to save info to
   CString strKey = 
      "SOFTWARE\\TikiSoft\\WallFlip\\CurrentVersion";
   
   // Delete any existing keys from this location
   RegDeleteKey(HKEY_CURRENT_USER, strKey);

   // Save bitmap names (if any) to registry
   CWallFlipApp* pApp = (CWallFlipApp*) AfxGetApp();
   for (int i = 0; i < m_listBitmaps.GetCount(); i++)
   {
      CString strChildKey = "Bitmap" + pApp->IntToString(i + 1);
      CString strChildKeyValue;
      m_listBitmaps.GetText(i, strChildKeyValue);

      SetRegValue(HKEY_CURRENT_USER, strKey, strChildKey, 
         strChildKeyValue);
   }
   // Save the number of bitmap filenames stored here
   SetRegValue(HKEY_CURRENT_USER, strKey, "BitmapCount", 
      m_listBitmaps.GetCount());

   // Set the next wallpaper bitmap index
   SetRegValue(HKEY_CURRENT_USER, strKey, "NextBitmap", 0);

   // Set the app to autorun when Windows starts
   strKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
   CString str = GetCommandLine();
   str += " /flip";
   
   SetRegValue(HKEY_LOCAL_MACHINE, strKey, "WallFlip", str);
}

///////////////////////////////////////////////////////////////////
// CWallFlipDlg::OnCommand()

BOOL CWallFlipDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
   // Enable or disable the Remove button, depending on selection
   BOOL bEnable = (m_listBitmaps.GetCurSel() >= 0);
   m_btnRemove.EnableWindow(bEnable);
   
   return CDialog::OnCommand(wParam, lParam);
}

///////////////////////////////////////////////////////////////////
// CWallFlipDlg::GetRegData()

void CWallFlipDlg::GetRegData() 
{
   // Specify the registry location to get data from
   CString strKey = 
      "SOFTWARE\\TikiSoft\\WallFlip\\CurrentVersion";   

   // Open the registry key
   HKEY hResult;
   if (ERROR_SUCCESS != RegOpenKey(HKEY_CURRENT_USER, 
       (LPCTSTR) strKey, &hResult)) 
      return;

   // Get the values
   BYTE   cFilenames;
   DWORD  dwCount = sizeof(DWORD);

   if (ERROR_SUCCESS != RegQueryValueEx(hResult, 
      (LPCTSTR) "BitmapCount", 0, 0, 
      &cFilenames, &dwCount))
   {
     RegCloseKey(hResult);    // Close the key
     return;
   }

   // Iterate through the bitmap filenames
   CWallFlipApp* pApp = (CWallFlipApp*) AfxGetApp();
   for (int i = 0; i < cFilenames; i++)
   {
      CString str = "Bitmap" + pApp->IntToString(i + 1);
      BYTE   szBuf[255];
      dwCount = 255;

      RegQueryValueEx(hResult, (LPCTSTR) str,
         0, 0, &szBuf[0], &dwCount);

      // Add the string to the list box
      m_listBitmaps.AddString((LPCTSTR) szBuf);
   }
   // Close the key
   RegCloseKey(hResult);   
}

///////////////////////////////////////////////////////////////////
*/
