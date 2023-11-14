// wzt259Doc.cpp : implementation of the CWzt259Doc class
//

#include "stdafx.h"
#include "wzt259.h"

#include "wzt259Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzt259Doc

IMPLEMENT_DYNCREATE(CWzt259Doc, CDocument)

BEGIN_MESSAGE_MAP(CWzt259Doc, CDocument)
	//{{AFX_MSG_MAP(CWzt259Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWzt259Doc construction/destruction

CWzt259Doc::CWzt259Doc()
{
	// TODO: add one-time construction code here

}

CWzt259Doc::~CWzt259Doc()
{
}

BOOL CWzt259Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CWzt259Doc serialization

void CWzt259Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CWzt259Doc diagnostics

#ifdef _DEBUG
void CWzt259Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWzt259Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWzt259Doc command
BOOL LoadBmpFile(char * BmpFileName);
BOOL CWzt259Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	LoadBmpFile((char*) lpszPathName);

	return TRUE;
}
