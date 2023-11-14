// Theall1.cpp : implementation file
//

#include "stdafx.h"
#include "theall.h"
#include "Theall1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTheall dialog


CTheall::CTheall(CWnd* pParent /*=NULL*/)
	: CDialog(CTheall::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTheall)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTheall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTheall)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTheall, CDialog)
	//{{AFX_MSG_MAP(CTheall)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTheall message handlers
