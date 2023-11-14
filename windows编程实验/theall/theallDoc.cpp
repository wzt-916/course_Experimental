// theallDoc.cpp : implementation of the CTheallDoc class
//

#include "stdafx.h"
#include "theall.h"

#include "theallDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTheallDoc

IMPLEMENT_DYNCREATE(CTheallDoc, CDocument)

BEGIN_MESSAGE_MAP(CTheallDoc, CDocument)
	//{{AFX_MSG_MAP(CTheallDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTheallDoc construction/destruction

CTheallDoc::CTheallDoc()
{
	// TODO: add one-time construction code here

}

CTheallDoc::~CTheallDoc()
{
}

BOOL CTheallDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTheallDoc serialization

void CTheallDoc::Serialize(CArchive& ar)
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
// CTheallDoc diagnostics

#ifdef _DEBUG
void CTheallDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTheallDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTheallDoc commands
