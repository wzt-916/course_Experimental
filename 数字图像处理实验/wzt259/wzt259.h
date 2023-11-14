// wzt259.h : main header file for the WZT259 application
//

#if !defined(AFX_WZT259_H__9B26F1E9_D1F0_4DF1_89D0_E9C7DB956A01__INCLUDED_)
#define AFX_WZT259_H__9B26F1E9_D1F0_4DF1_89D0_E9C7DB956A01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzt259App:
// See wzt259.cpp for the implementation of this class
//

class CWzt259App : public CWinApp
{
public:
	CWzt259App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzt259App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWzt259App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZT259_H__9B26F1E9_D1F0_4DF1_89D0_E9C7DB956A01__INCLUDED_)
