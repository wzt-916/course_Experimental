#if !defined(AFX_GAMEDLG_H__A312612F_1167_4F89_98F6_E06BBD540BE6__INCLUDED_)
#define AFX_GAMEDLG_H__A312612F_1167_4F89_98F6_E06BBD540BE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// gameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CgameDlg dialog

class CgameDlg : public CDialog
{
// Construction
public:
	CgameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CgameDlg)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CgameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CgameDlg)
	afx_msg void OnGame();
	afx_msg void OnBtnGame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CButton m_btn;
	BOOL m_blsCreate;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEDLG_H__A312612F_1167_4F89_98F6_E06BBD540BE6__INCLUDED_)
