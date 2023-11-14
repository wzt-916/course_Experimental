// addDlg.cpp : implementation file
//

#include "stdafx.h"
#include "theall.h"
#include "addDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CaddDlg dialog


CaddDlg::CaddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CaddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CaddDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_blsCreate=FALSE;
}


void CaddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CaddDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CaddDlg, CDialog)
	//{{AFX_MSG_MAP(CaddDlg)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CaddDlg message handlers

void CaddDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	if(m_blsCreate==FALSE)
	{
		m_btn.Create("这是模式对话框！",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,
			CRect(50,20,200,50),this,123);
		m_blsCreate=TRUE;
	}
	else
	{
		m_btn.DestroyWindow();
		m_blsCreate=FALSE;
	}
		//实现加法
	int num1,num2,num3;
	char ch1[10],ch2[10],ch3[10];
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1,10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2,10);
	num1=atoi(ch1);//字符串转数字
	num2=atoi(ch2);
	num3=num1+num2;
	itoa(num3,ch3,10);//将数字转字符
	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);

}
