// wzt259Doc.h : interface of the CWzt259Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_WZT259DOC_H__661FA50D_6596_4C64_BFB1_AAA72D677848__INCLUDED_)
#define AFX_WZT259DOC_H__661FA50D_6596_4C64_BFB1_AAA72D677848__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWzt259Doc : public CDocument
{
protected: // create from serialization only
	CWzt259Doc();
	DECLARE_DYNCREATE(CWzt259Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzt259Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWzt259Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CWzt259Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZT259DOC_H__661FA50D_6596_4C64_BFB1_AAA72D677848__INCLUDED_)
