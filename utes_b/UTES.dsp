# Microsoft Developer Studio Project File - Name="UTES" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=UTES - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "UTES.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UTES.mak" CFG="UTES - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UTES - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "UTES - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "UTES - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:".\Release\DSS-Utes.exe"

!ELSEIF  "$(CFG)" == "UTES - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# SUBTRACT BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386

!ENDIF 

# Begin Target

# Name "UTES - Win32 Release"
# Name "UTES - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Approx.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogExpAdv.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogRobast.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogSelMethod.cpp
# End Source File
# Begin Source File

SOURCE=.\DssPref.cpp
# End Source File
# Begin Source File

SOURCE=.\dsspref.odl
# ADD MTL /tlb "Dss_Info.tlb" /h "Dss_Info.h"
# End Source File
# Begin Source File

SOURCE=.\excel8.cpp
# End Source File
# Begin Source File

SOURCE=.\Exponent.cpp
# End Source File
# Begin Source File

SOURCE=.\ExponentDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\factory.cpp
# End Source File
# Begin Source File

SOURCE=.\fmod.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\fserver_i.c
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\gridctrl.cpp
# End Source File
# Begin Source File

SOURCE=.\GridDropTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\GroupSet.cpp
# End Source File
# Begin Source File

SOURCE=.\InPlaceEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\InPlaceList.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Method.cpp
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\PrefView.cpp
# End Source File
# Begin Source File

SOURCE=.\Protection.cpp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\rowcursor.cpp
# End Source File
# Begin Source File

SOURCE=.\Scale.cpp
# End Source File
# Begin Source File

SOURCE=.\ScaleAutoDef.cpp
# End Source File
# Begin Source File

SOURCE=.\ScaleDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\sys_add_ins.cpp
# End Source File
# Begin Source File

SOURCE=.\TitleTip.cpp
# End Source File
# Begin Source File

SOURCE=.\UTES.cpp
# End Source File
# Begin Source File

SOURCE=.\UTES.rc
# End Source File
# Begin Source File

SOURCE=.\UTESDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\UTESView.cpp
# End Source File
# Begin Source File

SOURCE=.\WeightView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\Approx.h
# End Source File
# Begin Source File

SOURCE=.\CellRange.h
# End Source File
# Begin Source File

SOURCE=.\def_scale.h
# End Source File
# Begin Source File

SOURCE=.\DialogExpAdv.h
# End Source File
# Begin Source File

SOURCE=.\DialogRobast.h
# End Source File
# Begin Source File

SOURCE=.\DialogSelMethod.h
# End Source File
# Begin Source File

SOURCE=.\DssPref.h
# End Source File
# Begin Source File

SOURCE=.\excel8.h
# End Source File
# Begin Source File

SOURCE=.\Exponent.h
# End Source File
# Begin Source File

SOURCE=.\ExponentDialog.h
# End Source File
# Begin Source File

SOURCE=.\factory.h
# End Source File
# Begin Source File

SOURCE=.\fmod.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\gridctrl.h
# End Source File
# Begin Source File

SOURCE=.\GridDropTarget.h
# End Source File
# Begin Source File

SOURCE=.\GroupSet.h
# End Source File
# Begin Source File

SOURCE=.\InPlaceEdit.h
# End Source File
# Begin Source File

SOURCE=.\InPlaceList.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\MemDC.h
# End Source File
# Begin Source File

SOURCE=.\Method.h
# End Source File
# Begin Source File

SOURCE=.\msflexgrid.h
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\PrefView.h
# End Source File
# Begin Source File

SOURCE=.\Protection.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\rowcursor.h
# End Source File
# Begin Source File

SOURCE=.\Scale.h
# End Source File
# Begin Source File

SOURCE=.\ScaleAutoDef.h
# End Source File
# Begin Source File

SOURCE=.\ScaleDialog.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\sys_add_ins.h
# End Source File
# Begin Source File

SOURCE=.\TitleTip.h
# End Source File
# Begin Source File

SOURCE=.\UTES.h
# End Source File
# Begin Source File

SOURCE=.\UTESDoc.h
# End Source File
# Begin Source File

SOURCE=.\UTESView.h
# End Source File
# Begin Source File

SOURCE=.\WeightView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Face01.ico
# End Source File
# Begin Source File

SOURCE=.\res\Face02.ico
# End Source File
# Begin Source File

SOURCE=.\res\Face03.ico
# End Source File
# Begin Source File

SOURCE=.\res\Face04.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\UTES.ico
# End Source File
# Begin Source File

SOURCE=.\res\UTES.rc2
# End Source File
# Begin Source File

SOURCE=.\res\UTESDoc.ico
# End Source File
# End Group
# End Target
# End Project
# Section UTES : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section UTES : {9F6AA700-D188-11CD-AD48-00AA003C9CB6}
# 	2:5:Class:CRowCursor
# 	2:10:HeaderFile:rowcursor.h
# 	2:8:ImplFile:rowcursor.cpp
# End Section
# Section OLE Controls
# 	{A8C3B720-0B5A-101B-B22E-00AA0037B2FC}
# End Section
# Section UTES : {B1CFAF11-5E8E-11D1-93B4-8F39C3B21717}
# 	0:8:Splash.h:C:\Lab\Utes\Splash.h
# 	0:10:Splash.cpp:C:\Lab\Utes\Splash.cpp
# 	1:10:IDB_SPLASH:102
# 	2:10:ResHdrName:resource.h
# 	2:11:ProjHdrName:stdafx.h
# 	2:10:WrapperDef:_SPLASH_SCRN_
# 	2:12:SplClassName:CSplashWnd
# 	2:21:SplashScreenInsertKey:4.0
# 	2:10:HeaderName:Splash.h
# 	2:10:ImplemName:Splash.cpp
# 	2:7:BmpID16:IDB_SPLASH
# End Section
# Section UTES : {F4392540-0CFE-101B-B22E-00AA0037B2FC}
# 	2:5:Class:CGridCtrl
# 	2:10:HeaderFile:gridctrl.h
# 	2:8:ImplFile:gridctrl.cpp
# End Section
# Section UTES : {A8C3B720-0B5A-101B-B22E-00AA0037B2FC}
# 	0:12:GridCtrl.cpp:C:\Lab\Utes\GridCtrl.cpp
# 	0:9:Picture.h:C:\Lab\Utes\Picture.h
# 	0:8:Font.cpp:C:\Lab\Utes\Font.cpp
# 	0:6:Font.h:C:\Lab\Utes\Font.h
# 	0:10:GridCtrl.h:C:\Lab\Utes\GridCtrl.h
# 	0:11:Picture.cpp:C:\Lab\Utes\Picture.cpp
# 	2:21:DefaultSinkHeaderFile:gridctrl.h
# 	2:16:DefaultSinkClass:CGridCtrl
# End Section
# Section UTES : {5F4DF280-531B-11CF-91F6-C2863C385E30}
# 	2:5:Class:CMSFlexGrid
# 	2:10:HeaderFile:msflexgrid.h
# 	2:8:ImplFile:msflexgrid.cpp
# End Section
# Section UTES : {6262D3A0-531B-11CF-91F6-C2863C385E30}
# 	2:21:DefaultSinkHeaderFile:msflexgrid.h
# 	2:16:DefaultSinkClass:CMSFlexGrid
# End Section
# Section UTES : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section
