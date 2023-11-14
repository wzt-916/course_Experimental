// DLLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "theall.h"
#include "DLLDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDLLDlg dialog


CDLLDlg::CDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDLLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLLDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLLDlg, CDialog)
	//{{AFX_MSG_MAP(CDLLDlg)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLLDlg message handlers

void CDLLDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int num1, num2, num3;
	HMODULE hModule;
	hModule = LoadLibrary("Dll.dll");	
	typedef int (*FUNC) (int a, int b); //定义函数指针类型
	FUNC sub = (FUNC)GetProcAddress(hModule, "sub");//使用C导入
	if (!sub)
	{
		MessageBox("获取函数地址失败！");
		return;
	}
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
    num3 = sub(num1,num2);
	SetDlgItemInt(IDC_EDIT3, num3);
}

void CDLLDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int num1, num2, num3;
	HMODULE hModule;
	hModule = LoadLibrary("Dll.dll");	
	typedef int (*FUNC) (int a, int b); //定义函数指针类型
	FUNC add = (FUNC)GetProcAddress(hModule, "add");//使用C导入
	if (!add)
	{
		MessageBox("获取函数地址失败！");
		return;
	}
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
    num3 = add(num1,num2);
	SetDlgItemInt(IDC_EDIT3, num3);
}
