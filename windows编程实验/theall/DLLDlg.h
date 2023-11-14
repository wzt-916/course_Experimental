#if !defined(AFX_DLLDLG_H__F5D978B2_9754_437F_A791_3A22554D616F__INCLUDED_)
#define AFX_DLLDLG_H__F5D978B2_9754_437F_A791_3A22554D616F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DLLDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDLLDlg dialog

class CDLLDlg : public CDialog
{
// Construction
public:
	CDLLDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDLLDlg)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDLLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDLLDlg)
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLLDLG_H__F5D978B2_9754_437F_A791_3A22554D616F__INCLUDED_)
