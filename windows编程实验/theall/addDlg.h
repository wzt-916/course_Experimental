#if !defined(AFX_ADDDLG_H__477DCFAC_853D_4C36_9503_B0976E4E6C88__INCLUDED_)
#define AFX_ADDDLG_H__477DCFAC_853D_4C36_9503_B0976E4E6C88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// addDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CaddDlg dialog

class CaddDlg : public CDialog
{
// Construction
public:
	CaddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CaddDlg)
	enum { IDD = IDD_DIALOG2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CaddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CaddDlg)
	afx_msg void OnBtnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_blsCreate;
	CButton m_btn;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__477DCFAC_853D_4C36_9503_B0976E4E6C88__INCLUDED_)
