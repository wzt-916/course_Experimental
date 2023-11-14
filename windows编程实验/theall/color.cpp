// color.cpp : implementation file
//

#include "stdafx.h"
#include "theall.h"
#include "color.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ccolor dialog


Ccolor::Ccolor(CWnd* pParent /*=NULL*/)
	: CDialog(Ccolor::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ccolor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ccolor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Ccolor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Ccolor, CDialog)
	//{{AFX_MSG_MAP(Ccolor)
	ON_BN_CLICKED(IDC_BTN_COLOR, OnBtnColor)
	ON_COMMAND(IDM_COLOR, OnColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ccolor message handlers
int R;
int G;
int B;
void Ccolor::OnBtnColor() 
{
	// TODO: Add your control notification handler code here
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
	num3 = GetDlgItemInt(IDC_EDIT3);
	if(num1 < 0 || num1 > 255 || num2 < 0 || num2 >255 || num3 < 0 || num3 > 255)
	{
		MessageBox("RGB的值取值在0-255之间!!!");
		return;
	}
	R = num1;
	G = num2;
	B = num3;
}

void Ccolor::OnColor() 
{
	// TODO: Add your command handler code here
	
}
