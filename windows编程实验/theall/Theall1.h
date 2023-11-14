#if !defined(AFX_THEALL1_H__071827A5_DF66_474B_9D92_774CB43CB458__INCLUDED_)
#define AFX_THEALL1_H__071827A5_DF66_474B_9D92_774CB43CB458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Theall1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTheall dialog

class CTheall : public CDialog
{
// Construction
public:
	CTheall(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTheall)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTheall)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTheall)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEALL1_H__071827A5_DF66_474B_9D92_774CB43CB458__INCLUDED_)
