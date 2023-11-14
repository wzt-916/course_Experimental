// theallView.h : interface of the CTheallView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEALLVIEW_H__335A27C6_3381_4E5E_BC81_4B9EF2D3AE53__INCLUDED_)
#define AFX_THEALLVIEW_H__335A27C6_3381_4E5E_BC81_4B9EF2D3AE53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTheallView : public CView
{
protected: // create from serialization only
	CTheallView();
	DECLARE_DYNCREATE(CTheallView)

// Attributes
public:
	CTheallDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTheallView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_nWidth;
	CString m_strLine;
	virtual ~CTheallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTheallView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCancelMode();
	afx_msg void OnDialog();
	afx_msg void OnGame();
	afx_msg void OnColor();
	afx_msg void OnDll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_ptOld;
	BOOL m_bDraw;
	CPoint m_ptOrigin;
};

#ifndef _DEBUG  // debug version in theallView.cpp
inline CTheallDoc* CTheallView::GetDocument()
   { return (CTheallDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEALLVIEW_H__335A27C6_3381_4E5E_BC81_4B9EF2D3AE53__INCLUDED_)
