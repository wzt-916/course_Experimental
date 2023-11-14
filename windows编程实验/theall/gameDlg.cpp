// gameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "theall.h"
#include "gameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CgameDlg dialog


CgameDlg::CgameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CgameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CgameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_blsCreate=FALSE;
}


void CgameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CgameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CgameDlg, CDialog)
	//{{AFX_MSG_MAP(CgameDlg)
	ON_COMMAND(IDM_GAME, OnGame)
	ON_BN_CLICKED(IDC_BTN_GAME, OnBtnGame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CgameDlg message handlers

void CgameDlg::OnGame() 
{
	// TODO: Add your command handler code here

}

void CgameDlg::OnBtnGame() 
{
	// TODO: Add your control notification handler code here
		if(m_blsCreate==FALSE)
	{
		m_btn.Create("这是非模式对话框！",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,
			CRect(100,0,350,30),this,123);
		m_blsCreate=TRUE;
	}
	//猜数字
	int h=45;
	int num1;
	char ch1[10],ch2[3];
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch1,10);
	num1=atoi(ch1);//字符串转数字
	if(num1>h)
	{
		GetDlgItem(IDC_EDIT3)->SetWindowText("猜大了");
	}
	else if(num1<h)
	{
		GetDlgItem(IDC_EDIT3)->SetWindowText("猜小了");
	}
	else
	{
		GetDlgItem(IDC_EDIT3)->SetWindowText("猜对了");
		MessageBox("你对了，太棒了!");
	}
	
}
