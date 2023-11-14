#if !defined(AFX_COLOR_H__F31A310E_047D_471E_8F4E_76604514C4F4__INCLUDED_)
#define AFX_COLOR_H__F31A310E_047D_471E_8F4E_76604514C4F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// color.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ccolor dialog

class Ccolor : public CDialog
{
// Construction
public:
	Ccolor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ccolor)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ccolor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ccolor)
	afx_msg void OnBtnColor();
	afx_msg void OnColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOR_H__F31A310E_047D_471E_8F4E_76604514C4F4__INCLUDED_)
