// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "theall.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}
extern CTheallApp theApp;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// 动画图标
	m_hIcon[0] = ::LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_hIcon[1] = ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_hIcon[2] = ::LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));
	m_hIcon[3] = AfxGetApp()->LoadIcon(IDI_ICON4);
	m_hIcon[4] = AfxGetApp()->LoadIcon(IDI_ICON5);
	SetClassLong(m_hWnd, GCL_HICON,(LONG)m_hIcon[0]);
	SetTimer(1,1000, NULL);
	// 工具栏设置
	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.lpszName = "涛哥，好久不见";
	cs.style = cs.style & ~FWS_ADDTOTITLE; 
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    MessageBox("hello",NULL,MB_OK);
	//m_bDraw = TRUE;
	//m_ptOrigin = m_ptOld= point;
	//CView::OnLButtonDown(nFlags, point);
	CFrameWnd::OnLButtonDown(nFlags, point);
}

void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		// 动态图标
	static int index = 1;
	SetClassLong(m_hWnd, GCL_HICON,(LONG)m_hIcon[index]);
	index = ++index % 5;
	CFrameWnd::OnTimer(nIDEvent);
	// 时间显示状态栏
	CTime t = CTime::GetCurrentTime();
	CString str = t.Format("%H:%M:%:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	//m_wndStatusBar.SetPaneInfo(1, IDS_TIMER,SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(1, str);
	CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnViewNewtoolbar()
{
	if (m_newToolBar.IsWindowVisible())
		m_newToolBar.ShowWindow(SW_HIDE);
	else
		m_newToolBar.ShowWindow(SW_SHOW);
	RecalcLayout();
	DockControlBar(&m_newToolBar);
}
