// theallView.cpp : implementation of the CTheallView class
//

#include "stdafx.h"
#include "theall.h"

#include "theallDoc.h"
#include "theallView.h"
#include "Theall.h"
#include "addDlg.h"
#include "gameDlg.h"
#include "color.h"
#include "MainFrm.h"
#include "DLLDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTheallView

IMPLEMENT_DYNCREATE(CTheallView, CView)

BEGIN_MESSAGE_MAP(CTheallView, CView)
	//{{AFX_MSG_MAP(CTheallView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
	ON_WM_TIMER()
	ON_WM_CANCELMODE()
	ON_COMMAND(IDM_DIALOG, OnDialog)
	ON_COMMAND(IDM_GAME, OnGame)
	ON_COMMAND(IDM_COLOR, OnColor)
	ON_COMMAND(ID_DLL, OnDll)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTheallView construction/destruction

CTheallView::CTheallView()
{
	// TODO: add construction code here
	m_ptOrigin=0;
	m_bDraw=FALSE;
	m_strLine="";
	m_nWidth=0;
}

CTheallView::~CTheallView()
{
}

BOOL CTheallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTheallView drawing

void CTheallView::OnDraw(CDC* pDC)
{
	CTheallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	//创建文字，在窗口大小发生变化的时候不会消失
	CString str("hello，涛哥，好久不见");
	pDC->TextOut(50,50,str);
	CSize sz = pDC->GetTextExtent(str);//获取字符串占据的宽高

	str.LoadString(IDS_TAOGE);//获取字符串资源
	pDC->TextOut(0,200,str);

	//路径层
	pDC->BeginPath();
	pDC->Rectangle(50,50,50+sz.cx,50+sz.cy);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);//把当前的路径层分开


}

/////////////////////////////////////////////////////////////////////////////
// CTheallView printing

BOOL CTheallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTheallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTheallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTheallView diagnostics

#ifdef _DEBUG
void CTheallView::AssertValid() const
{
	CView::AssertValid();
}

void CTheallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTheallDoc* CTheallView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTheallDoc)));
	return (CTheallDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTheallView message handlers

extern int R;
extern int G;
extern int B;
int CTheallView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	/*CreateSolidCaret(20,100);//创建文本插入符
	ShowCaret();//显示文本插入符*/

	//创建设备描述表
	CClientDC dc(this);
	//定义文本信息结构体变量
	TEXTMETRIC tm;
	//获得设备描述表中的文本信息
	dc.GetTextMetrics(&tm);
	//根据字体大小，创建合适的插入符
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	//显示插入符
	ShowCaret();

	//创建图形插入符
	/*CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);//装入位图
	CreateCaret(&bitmap);//创建插入符
	ShowCaret();//显示插入符
	bitmap.Detach();*/

	SetTimer(1,100,NULL);//设置时钟
	return 0;
}

void CTheallView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDraw = TRUE;
	m_ptOrigin = m_ptOld= point;

	CView::OnLButtonDown(nFlags, point);
}

void CTheallView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//画线
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc,m_ptOrigin.x,m_ptOrigin.y,NULL);
	LineTo(hdc,point.x,point.y);
	::ReleaseDC(m_hWnd,hdc);

	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/

	//这个不用调用GetDC()和ReleaseDC；
	/*CClientDC dc(this);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/

	//CWindowDC dc(GetParent());
	/*CWindowDC dc(GetDesktopWindow());//获取桌面窗口
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/

	//彩色的线条画笔
	/*CPen pen(PS_SOLID,2,RGB(255,0,0));//定义画笔
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);//更换画笔，并保留原来的画笔
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);//换回原来的画笔
	*/
	//填充区域
	/*CBrush brush(RGB(255,0,0));//创建画刷
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point),&brush);//填充区域，CRect是获取区域
	*/
	//创建位图画刷进行画图
	/*CBitmap bitmap;//创建位图
	bitmap.LoadBitmap(IDB_BITMAP1);//加载位图
	CBrush brush(&bitmap);//创建画刷
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point),&brush);*/

	//画矩形
	/*CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//创建空画刷
	CBrush *pOldBrush = dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_ptOrigin,point));//画矩形
	dc.SelectObject(pOldBrush);*///恢复原来的画刷

	/*m_bDraw = FALSE;

	SetCaretPos(point);//实现文本编辑插入符跟随鼠标点击移动
	m_strLine.Empty();
	m_ptOrigin = point;//记录当前坐标
	CView::OnLButtonUp(nFlags, point);*/


}

void CTheallView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//实现画图功能
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(R,G,B));//定义画笔
	CPen *pOldPen = dc.SelectObject(&pen);//更换画笔，并保留原来的画笔
	if(m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin = point;
	}
	dc.SelectObject(pOldPen);

		// 状态栏显示坐标设置
	CString str;
	str.Format("坐标：X=%d  Y=%d", point.x, point.y);
	((CMainFrame*)GetParent())->GetMessageBar()-> SetWindowText(str);*/

	//不带边线的扇形
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(255,0,0));
	CPen *pOldPen = dc.SelectObject(&pen);
	if(m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
	}
	dc.SelectObject(pOldPen);*/

	//带边线的扇形
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(255,0,0));
	CPen *pOldPen = dc.SelectObject(&pen);
	if(m_bDraw == TRUE)
	{
		//dc.SetROP2(R2_BLACK);//设置绘图的模式
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		dc.MoveTo(m_ptOld);
		dc.LineTo(point);
		m_ptOld = point;
	}
	dc.SelectObject(pOldPen);

	CView::OnMouseMove(nFlags, point);*/
}

void CTheallView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
		//创建设备描述表
	CClientDC dc(this);
	if (13 == nChar)     //回车键的ASCII码为13
	{
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
	else if (8 == nChar)     //退格键的ASCII码为8
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1) ;
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine += nChar;
	}
	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;
	SetCaretPos(pt);
	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CTheallView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_nWidth += 5;

	CClientDC dc(this);

	//获取文本信息
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	CRect rect;//用于表示矩形区域
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255,0,0));//设置文本颜色
	CString str;
	str.LoadString(IDS_TAOGE);//加载字符串
	dc.DrawText(str,rect,DT_LEFT);//输出文本

	CSize sz = dc.GetTextExtent(str);//获取文本尺寸或大小
	if(m_nWidth >= sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0,255,0));
		dc.TextOut(0,200,str);
	}

	CView::OnTimer(nIDEvent);
}

void CTheallView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CTheallView::OnDialog() 
{
	// TODO: Add your command handler code here
	CaddDlg dlg;//对话框对象
	dlg.DoModal();

}

void CTheallView::OnGame() 
{
	// TODO: Add your command handler code here
	CgameDlg *pDlg=new CgameDlg();
	pDlg->Create(IDD_DIALOG3,this);
	pDlg->ShowWindow(SW_SHOW);
}

void CTheallView::OnColor() 
{
	// TODO: Add your command handler code here
	Ccolor *pDlg=new Ccolor();
	pDlg->Create(IDD_DIALOG4,this);
	pDlg->ShowWindow(SW_SHOW);
}

void CTheallView::OnDll() 
{
	// TODO: Add your command handler code here
	CDLLDlg *pDlg=new CDLLDlg();
	pDlg->Create(IDD_DIALOG5,this);
	pDlg->ShowWindow(SW_SHOW);
}
