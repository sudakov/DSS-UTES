//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Support functions module
//---------------------------------------------------------------------------

#include "stdafx.h"
#include "sys_add_ins.h"

int GetNumber(CString buf, double& d)
{
	char* s;
	char* s2;
	double dd;
	CString BufErr;
	if (buf=="") return -1;
	s=buf.GetBuffer(100);
	dd=strtod(s,&s2);
	BufErr=s2;
	buf.ReleaseBuffer();
	BufErr.TrimLeft(); BufErr.TrimRight();
	if (!BufErr.IsEmpty()) return -1;
	d=dd;
	return 0;
}

int GetNumberInt(CString buf, int& d)
{
	char* s;
	char* s2;
	int dd;
	CString BufErr;
	if (buf=="") return -1;
	s=buf.GetBuffer(100);
	dd=strtoul(s,&s2,10);
	BufErr=s2;
	buf.ReleaseBuffer();
	BufErr.TrimLeft(); BufErr.TrimRight();
	if (!BufErr.IsEmpty()) return -1;
	d=dd;
	return 0;
}
