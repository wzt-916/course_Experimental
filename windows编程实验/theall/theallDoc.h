// theallDoc.h : interface of the CTheallDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_THEALLDOC_H__E19332C6_2415_4600_B3D5_0E8112A9C199__INCLUDED_)
#define AFX_THEALLDOC_H__E19332C6_2415_4600_B3D5_0E8112A9C199__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTheallDoc : public CDocument
{
protected: // create from serialization only
	CTheallDoc();
	DECLARE_DYNCREATE(CTheallDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTheallDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTheallDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTheallDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEALLDOC_H__E19332C6_2415_4600_B3D5_0E8112A9C199__INCLUDED_)
