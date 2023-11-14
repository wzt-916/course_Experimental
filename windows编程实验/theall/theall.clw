; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDLLDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "theall.h"
LastPage=0

ClassCount=10
Class1=CTheallApp
Class2=CTheallDoc
Class3=CTheallView
Class4=CMainFrame

ResourceCount=8
Resource1=IDD_DIALOG3
Class5=CAboutDlg
Resource2=IDR_TOOLBAR1
Class6=CTheall
Resource3=IDD_ABOUTBOX
Class7=CaddDlg
Resource4=IDD_DIALOG2
Class8=CgameDlg
Resource5=IDR_MAINFRAME
Class9=Ccolor
Resource6=IDD_DIALOG1
Resource7=IDD_DIALOG4
Class10=CDLLDlg
Resource8=IDD_DIALOG5

[CLS:CTheallApp]
Type=0
HeaderFile=theall.h
ImplementationFile=theall.cpp
Filter=N

[CLS:CTheallDoc]
Type=0
HeaderFile=theallDoc.h
ImplementationFile=theallDoc.cpp
Filter=N

[CLS:CTheallView]
Type=0
HeaderFile=theallView.h
ImplementationFile=theallView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDC_BTN_COLOR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_DLL




[CLS:CAboutDlg]
Type=0
HeaderFile=theall.cpp
ImplementationFile=theall.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_COLOR
Command18=IDM_DIALOG
Command19=IDM_GAME
Command20=ID_DLL
CommandCount=20

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CTheall
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CTheall]
Type=0
HeaderFile=Theall1.h
ImplementationFile=Theall1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDM_DIALOG

[DLG:IDD_DIALOG2]
Type=1
Class=CaddDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_BTN_ADD,button,1342242816

[CLS:CaddDlg]
Type=0
HeaderFile=addDlg.h
ImplementationFile=addDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CaddDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CgameDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_BTN_GAME,button,1342242816

[CLS:CgameDlg]
Type=0
HeaderFile=gameDlg.h
ImplementationFile=gameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BTN_GAME
VirtualFilter=dWC

[DLG:IDD_DIALOG4]
Type=1
Class=Ccolor
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_BTN_COLOR,button,1342242816

[CLS:Ccolor]
Type=0
HeaderFile=color.h
ImplementationFile=color.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Ccolor

[TB:IDR_TOOLBAR1]
Type=1
Class=?
CommandCount=0

[DLG:IDD_DIALOG5]
Type=1
Class=CDLLDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_EDIT2,edit,1350631552
Control10=IDC_EDIT3,edit,1350631552

[CLS:CDLLDlg]
Type=0
HeaderFile=DLLDlg.h
ImplementationFile=DLLDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON1
VirtualFilter=dWC

