// wzt259View.cpp : implementation of the CWzt259View class
//

#include "stdafx.h"
#include "wzt259.h"

#include "wzt259Doc.h"
#include "wzt259View.h"
#include "HistogramDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzt259View

IMPLEMENT_DYNCREATE(CWzt259View, CScrollView)

BEGIN_MESSAGE_MAP(CWzt259View, CScrollView)
	//{{AFX_MSG_MAP(CWzt259View)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_GRAY, OnGray)
	ON_COMMAND(ID_HISTOGRAMDLG, OnHistogramdlg)
	ON_UPDATE_COMMAND_UI(ID_HISTOGRAMDLG, OnUpdateHistogramdlg)
	ON_COMMAND(ID_LINETRANS, OnLinetrans)
	ON_UPDATE_COMMAND_UI(ID_LINETRANS, OnUpdateLinetrans)
	ON_COMMAND(ID_EQUALIZE, OnEqualize)
	ON_UPDATE_COMMAND_UI(ID_EQUALIZE, OnUpdateEqualize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzt259View construction/destruction

CWzt259View::CWzt259View()
{
	// TODO: add construction code here

}

CWzt259View::~CWzt259View()
{
}

BOOL CWzt259View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWzt259View drawing
extern BITMAPINFO* lpBitsInfo;
void CWzt259View::OnDraw(CDC* pDC)
{
	CWzt259Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(NULL == lpBitsInfo)
		return;
	
	void* lpBits = &lpBitsInfo->bmiColors[lpBitsInfo->bmiHeader.biClrUsed];
	StretchDIBits(pDC->GetSafeHdc(),
		0,0,lpBitsInfo->bmiHeader.biWidth,lpBitsInfo->bmiHeader.biHeight,
		0,0,lpBitsInfo->bmiHeader.biWidth,lpBitsInfo->bmiHeader.biHeight,
		lpBits,lpBitsInfo,
		DIB_RGB_COLORS,
		SRCCOPY);
	// TODO: add draw code for native data here
}

void CWzt259View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CWzt259View printing

BOOL CWzt259View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWzt259View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWzt259View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWzt259View diagnostics

#ifdef _DEBUG
void CWzt259View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CWzt259View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CWzt259Doc* CWzt259View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWzt259Doc)));
	return (CWzt259Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzt259View message handlers
void pixel(int i,int j, char* str);
void CWzt259View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	char xy[100];
	memset(xy,0,100);//清空数组内容
	sprintf(xy, "x:%d y:%d",point.x,point.y);

	char rgb[100];
	memset(rgb,0,100);
	pixel(point.y,point.x,rgb);

	strcat(xy,rgb);

	((CFrameWnd*)GetParent())->SetMessageText(xy);

	CScrollView::OnMouseMove(nFlags, point);
}
void gray();
void CWzt259View::OnGray() 
{
	gray();
	Invalidate();
	// TODO: Add your command handler code here
	
}

void CWzt259View::OnHistogramdlg() 
{
	// TODO: Add your command handler code here
	CHistogramDlg dlg;
	dlg.DoModal();
}

void CWzt259View::OnUpdateHistogramdlg(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL);
}
void LineTrans(float,float);
void CWzt259View::OnLinetrans() 
{
	// TODO: Add your command handler code here
	LineTrans(2,-100);
	Invalidate();//刷新内容
}
BOOL IsGray();
void CWzt259View::OnUpdateLinetrans(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && IsGray());
}
void Equalize();
void CWzt259View::OnEqualize() 
{
	// TODO: Add your command handler code here
	Equalize();
	Invalidate();//刷新内容
}

void CWzt259View::OnUpdateEqualize(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(lpBitsInfo != NULL && IsGray());
}
