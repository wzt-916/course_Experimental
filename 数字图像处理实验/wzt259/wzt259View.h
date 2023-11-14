// wzt259View.h : interface of the CWzt259View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WZT259VIEW_H__26C79B83_95C6_40D5_9D7E_AB061F215001__INCLUDED_)
#define AFX_WZT259VIEW_H__26C79B83_95C6_40D5_9D7E_AB061F215001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWzt259View : public CScrollView
{
protected: // create from serialization only
	CWzt259View();
	DECLARE_DYNCREATE(CWzt259View)

// Attributes
public:
	CWzt259Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzt259View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzt259View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWzt259View)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnGray();
	afx_msg void OnHistogramdlg();
	afx_msg void OnUpdateHistogramdlg(CCmdUI* pCmdUI);
	afx_msg void OnLinetrans();
	afx_msg void OnUpdateLinetrans(CCmdUI* pCmdUI);
	afx_msg void OnEqualize();
	afx_msg void OnUpdateEqualize(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in wzt259View.cpp
inline CWzt259Doc* CWzt259View::GetDocument()
   { return (CWzt259Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZT259VIEW_H__26C79B83_95C6_40D5_9D7E_AB061F215001__INCLUDED_)
