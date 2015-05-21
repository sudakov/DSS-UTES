; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDssPref
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UTES.h"
ODLFile=dsspref.odl
LastPage=0

ClassCount=18
Class1=CUTESApp
Class2=CUTESDoc
Class3=CUTESView
Class4=CMainFrame

ResourceCount=14
Resource1=IDD_DIALOG_EXPONENT
Resource2=IDD_UTES_WEIGHT
Class5=CAboutDlg
Resource3=IDD_UTES_FORM
Class6=CPrefView
Resource4=IDD_UTES_PREF
Resource5=IDD_DIALOG_SCALE
Class7=CGroupSet
Class8=CSplashWnd
Class9=CNewGrid
Class10=CDssPref
Class11=CScaleDialog
Resource6=IDD_DIALOG_GROUP
Class12=CExponentDialog
Class13=CDialogExpAdv
Resource7=IDD_DIALOG_ROBAST
Class14=CWeightView
Resource8=IDD_DIALOG_OPTIONS
Resource9=IDD_DIALOG_EXP_ADV
Class15=COptionsDlg
Resource10=IDD_DIALOG_SELPR
Resource11=IDD_ABOUTBOX
Class16=CDialogSelMethod
Resource12=IDD_DIALOG_AUTO_SCALE
Class17=CScaleAutoDef
Resource13=IDR_MENU_PREF
Class18=CDialogRobast
Resource14=IDR_MAINFRAME

[CLS:CUTESApp]
Type=0
HeaderFile=UTES.h
ImplementationFile=UTES.cpp
Filter=N
LastObject=CUTESApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CUTESDoc]
Type=0
HeaderFile=UTESDoc.h
ImplementationFile=UTESDoc.cpp
Filter=N
LastObject=CUTESDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CUTESView]
Type=0
HeaderFile=UTESView.h
ImplementationFile=UTESView.cpp
Filter=D
LastObject=CUTESView
BaseClass=CFormView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame



[CLS:CAboutDlg]
Type=0
HeaderFile=UTES.cpp
ImplementationFile=UTES.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308480
Control4=IDC_STATIC,static,1073872897
Control5=IDOK,button,1342373889
Control6=IDC_STATIC,static,1342312449
Control7=IDC_STATIC,static,1342308353
Control8=IDC_STATIC_VER,static,1342308354

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_MENUITEM_IMPORT
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_ADDCR
Command9=ID_CHCR
Command10=ID_DELCR
Command11=ID_MENUITEM_SELMETH
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_VIEW_CRITERIA
Command15=ID_VIEW_PREF
Command16=ID_HELP
Command17=ID_MENUITEM_SETUP
Command18=ID_APP_ABOUT
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_UTES_FORM]
Type=1
Class=CUTESView
ControlCount=6
Control1=IDC_TREE,SysTreeView32,1350631431
Control2=IDC_LIST_CRIT,SysListView32,1350664205
Control3=IDC_LIST_GRUP,SysListView32,1350631425
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC_PF,static,1342308352
Control6=IDC_STATIC_CR,static,1342308352

[DLG:IDD_UTES_PREF]
Type=1
Class=CPrefView
ControlCount=19
Control1=IDC_MSFLEXGRID1,{6262D3A0-531B-11CF-91F6-C2863C385E30},1342242816
Control2=IDC_SPIN,msctls_updown32,1342177281
Control3=IDC_SLIDER1,msctls_trackbar32,1342242837
Control4=IDC_COMBO_X,combobox,1344339971
Control5=IDC_COMBO_Y,combobox,1344339971
Control6=IDC_EDIT_CRNAME,edit,1350568064
Control7=IDC_BUDDY_SPIN,edit,1350633600
Control8=IDC_LIST_VAL,SysListView32,1350598661
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_GOD,edit,1350568064
Control14=IDC_STATIC,static,1342177283
Control15=IDC_STATIC_FACE,static,1342177283
Control16=IDC_STATIC_SCALE,static,1342308608
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT_GNAME,edit,1350633600
Control19=IDC_STATIC,static,1342308352

[CLS:CPrefView]
Type=0
HeaderFile=PrefView.h
ImplementationFile=PrefView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_COMBO_Y
VirtualFilter=VWC

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_ADDCR
Command5=ID_CHCR
Command6=ID_DELCR
Command7=ID_BUTTON_EXCEl
Command8=ID_BUTTON_CHANGE_VIEW
Command9=ID_HELP
CommandCount=9

[DLG:IDD_DIALOG_GROUP]
Type=1
Class=CGroupSet
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350633600
Control4=IDC_STATIC,static,1342308354
Control5=IDC_LIST1,listbox,1352728841
Control6=IDC_LIST2,listbox,1352728841
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_BUTTON2,button,1342242816
Control11=IDC_COMBO_METHOD,combobox,1344339971
Control12=IDC_STATIC,static,1342308354

[CLS:CGroupSet]
Type=0
HeaderFile=GroupSet.h
ImplementationFile=GroupSet.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST2
VirtualFilter=dWC

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd

[CLS:CNewGrid]
Type=0
HeaderFile=\Lab\testcross\newgrid.h
ImplementationFile=\Lab\testcross\newgrid.cpp
BaseClass=CStatic
LastObject=CNewGrid

[CLS:CDssPref]
Type=0
HeaderFile=DssPref.h
ImplementationFile=DssPref.cpp
BaseClass=CCmdTarget
Filter=N
VirtualFilter=C
LastObject=CDssPref

[DLG:IDD_DIALOG_SCALE]
Type=1
Class=CScaleDialog
ControlCount=11
Control1=IDC_EDIT_TERM,edit,1350635588
Control2=IDC_EDIT_FORMAT,edit,1350631552
Control3=IDC_BUTTON_DEFAULT,button,1342251008
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC_P1,static,1342177283
Control8=IDC_STATIC_P2,static,1342177283
Control9=IDC_STATIC_FBORDER,button,1342177287
Control10=IDC_CHECK_RANG,button,1073807363
Control11=IDC_BUTTON_AUTO,button,1342242816

[CLS:CScaleDialog]
Type=0
HeaderFile=ScaleDialog.h
ImplementationFile=ScaleDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScaleDialog

[DLG:IDD_DIALOG_EXPONENT]
Type=1
Class=CExponentDialog
ControlCount=14
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDC_EDIT2,edit,1350631492
Control3=IDC_COMBO_TYPE,combobox,1344339971
Control4=IDC_COMBO_SCALE,combobox,1344339971
Control5=IDC_BUTTON_CHARACT,button,1342242816
Control6=IDC_BUTTON_SCALE,button,1342242816
Control7=IDC_BUTTON_NEXT_EXP,button,1342242817
Control8=IDOK,button,1342242816
Control9=IDCANCEL,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_BUTTON_ADV,button,1342242816

[CLS:CExponentDialog]
Type=0
HeaderFile=ExponentDialog.h
ImplementationFile=ExponentDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CExponentDialog
VirtualFilter=dWC

[DLG:IDD_UTES_WEIGHT]
Type=1
Class=CWeightView
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CHECK2,button,1342242819
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_GNAME,edit,1350633600
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_SUM_W,button,1342177287
Control7=IDC_EDIT1,edit,1350633600
Control8=IDC_BUTTON2,button,1073807361
Control9=IDC_MYGRID,MFCGridCtrl,1350631424

[CLS:CWeightView]
Type=0
HeaderFile=WeightView.h
ImplementationFile=WeightView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=CWeightView

[MNU:IDR_MENU_PREF]
Type=1
Class=?
Command1=ID_MENUITEM_COPY
Command2=ID_MENUITEM_INSERT
Command3=ID_MENUITEM_CLEAR
Command4=ID_MENUITEM_UNDO
Command5=ID_MENUITEM_DECL
Command6=ID_MENUITEM_INCL
Command7=ID_MENUITEM_APPROX
Command8=ID_MENUITEM_ISALL
Command9=ID_MENUITEM_SHOWGRAD
CommandCount=9

[DLG:IDD_DIALOG_OPTIONS]
Type=1
Class=COptionsDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,button,1342177287
Control6=IDC_EDIT2,edit,1350633600
Control7=IDC_STATIC,button,1342177287
Control8=IDC_EDIT3,edit,1350633600
Control9=IDC_STATIC,button,1342177287
Control10=IDC_EDIT4,edit,1350631552

[CLS:COptionsDlg]
Type=0
HeaderFile=OptionsDlg.h
ImplementationFile=OptionsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COptionsDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_EXP_ADV]
Type=1
Class=CDialogExpAdv
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,button,1342177287
Control8=IDC_COMBO1,combobox,1344340226

[CLS:CDialogExpAdv]
Type=0
HeaderFile=DialogExpAdv.h
ImplementationFile=DialogExpAdv.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogExpAdv
VirtualFilter=dWC

[DLG:IDD_DIALOG_SELPR]
Type=1
Class=CDialogSelMethod
ControlCount=6
Control1=IDC_LIST_METHODS,listbox,1352728833
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_NAME,edit,1350568064
Control6=IDC_BUTTON_OPTIONS,button,1342242816

[CLS:CDialogSelMethod]
Type=0
HeaderFile=DialogSelMethod.h
ImplementationFile=DialogSelMethod.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogSelMethod
VirtualFilter=dWC

[DLG:IDD_DIALOG_AUTO_SCALE]
Type=1
Class=CScaleAutoDef
ControlCount=8
Control1=IDC_EDIT_MIN,edit,1350631552
Control2=IDC_EDIT_MAX,edit,1350631552
Control3=IDC_EDIT_STEP,edit,1350631552
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CScaleAutoDef]
Type=0
HeaderFile=ScaleAutoDef.h
ImplementationFile=ScaleAutoDef.cpp
BaseClass=CDialog
Filter=D
LastObject=CScaleAutoDef
VirtualFilter=dWC

[DLG:IDD_DIALOG_ROBAST]
Type=1
Class=CDialogRobast
ControlCount=7
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_RADIO1,button,1342242825
Control3=IDC_RADIO2,button,1342177289
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,button,1342177287

[CLS:CDialogRobast]
Type=0
HeaderFile=DialogRobast.h
ImplementationFile=DialogRobast.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogRobast
VirtualFilter=dWC

