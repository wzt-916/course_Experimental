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

	//�������֣��ڴ��ڴ�С�����仯��ʱ�򲻻���ʧ
	CString str("hello���θ磬�þò���");
	pDC->TextOut(50,50,str);
	CSize sz = pDC->GetTextExtent(str);//��ȡ�ַ���ռ�ݵĿ��

	str.LoadString(IDS_TAOGE);//��ȡ�ַ�����Դ
	pDC->TextOut(0,200,str);

	//·����
	pDC->BeginPath();
	pDC->Rectangle(50,50,50+sz.cx,50+sz.cy);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);//�ѵ�ǰ��·����ֿ�


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
	/*CreateSolidCaret(20,100);//�����ı������
	ShowCaret();//��ʾ�ı������*/

	//�����豸������
	CClientDC dc(this);
	//�����ı���Ϣ�ṹ�����
	TEXTMETRIC tm;
	//����豸�������е��ı���Ϣ
	dc.GetTextMetrics(&tm);
	//���������С���������ʵĲ����
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	//��ʾ�����
	ShowCaret();

	//����ͼ�β����
	/*CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);//װ��λͼ
	CreateCaret(&bitmap);//���������
	ShowCaret();//��ʾ�����
	bitmap.Detach();*/

	SetTimer(1,100,NULL);//����ʱ��
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
	//����
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc,m_ptOrigin.x,m_ptOrigin.y,NULL);
	LineTo(hdc,point.x,point.y);
	::ReleaseDC(m_hWnd,hdc);

	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/

	//������õ���GetDC()��ReleaseDC��
	/*CClientDC dc(this);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/

	//CWindowDC dc(GetParent());
	/*CWindowDC dc(GetDesktopWindow());//��ȡ���洰��
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/

	//��ɫ����������
	/*CPen pen(PS_SOLID,2,RGB(255,0,0));//���廭��
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);//�������ʣ�������ԭ���Ļ���
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);//����ԭ���Ļ���
	*/
	//�������
	/*CBrush brush(RGB(255,0,0));//������ˢ
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point),&brush);//�������CRect�ǻ�ȡ����
	*/
	//����λͼ��ˢ���л�ͼ
	/*CBitmap bitmap;//����λͼ
	bitmap.LoadBitmap(IDB_BITMAP1);//����λͼ
	CBrush brush(&bitmap);//������ˢ
	CClientDC dc(this);
	dc.FillRect(CRect(m_ptOrigin,point),&brush);*/

	//������
	/*CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//�����ջ�ˢ
	CBrush *pOldBrush = dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_ptOrigin,point));//������
	dc.SelectObject(pOldBrush);*///�ָ�ԭ���Ļ�ˢ

	/*m_bDraw = FALSE;

	SetCaretPos(point);//ʵ���ı��༭���������������ƶ�
	m_strLine.Empty();
	m_ptOrigin = point;//��¼��ǰ����
	CView::OnLButtonUp(nFlags, point);*/


}

void CTheallView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//ʵ�ֻ�ͼ����
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(R,G,B));//���廭��
	CPen *pOldPen = dc.SelectObject(&pen);//�������ʣ�������ԭ���Ļ���
	if(m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		m_ptOrigin = point;
	}
	dc.SelectObject(pOldPen);

		// ״̬����ʾ��������
	CString str;
	str.Format("���꣺X=%d  Y=%d", point.x, point.y);
	((CMainFrame*)GetParent())->GetMessageBar()-> SetWindowText(str);*/

	//�������ߵ�����
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(255,0,0));
	CPen *pOldPen = dc.SelectObject(&pen);
	if(m_bDraw == TRUE)
	{
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
	}
	dc.SelectObject(pOldPen);*/

	//�����ߵ�����
	/*CClientDC dc(this);
	CPen pen(PS_SOLID,2,RGB(255,0,0));
	CPen *pOldPen = dc.SelectObject(&pen);
	if(m_bDraw == TRUE)
	{
		//dc.SetROP2(R2_BLACK);//���û�ͼ��ģʽ
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
		//�����豸������
	CClientDC dc(this);
	if (13 == nChar)     //�س�����ASCII��Ϊ13
	{
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
	else if (8 == nChar)     //�˸����ASCII��Ϊ8
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

	//��ȡ�ı���Ϣ
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);

	CRect rect;//���ڱ�ʾ��������
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;

	dc.SetTextColor(RGB(255,0,0));//�����ı���ɫ
	CString str;
	str.LoadString(IDS_TAOGE);//�����ַ���
	dc.DrawText(str,rect,DT_LEFT);//����ı�

	CSize sz = dc.GetTextExtent(str);//��ȡ�ı��ߴ���С
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
	CaddDlg dlg;//�Ի������
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
