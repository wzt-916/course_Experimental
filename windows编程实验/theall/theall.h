// theall.h : main header file for the THEALL application
//

#if !defined(AFX_THEALL_H__5FE93791_3461_4280_BDF0_5903011A0A21__INCLUDED_)
#define AFX_THEALL_H__5FE93791_3461_4280_BDF0_5903011A0A21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTheallApp:
// See theall.cpp for the implementation of this class
//

class CTheallApp : public CWinApp
{
public:
	CTheallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTheallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTheallApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEALL_H__5FE93791_3461_4280_BDF0_5903011A0A21__INCLUDED_)
