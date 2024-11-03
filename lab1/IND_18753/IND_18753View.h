
// IND_18753View.h : interface of the CIND18753View class
//

#pragma once


class CIND18753View : public CView
{
protected: // create from serialization only
	CIND18753View() noexcept;
	DECLARE_DYNCREATE(CIND18753View)

// Attributes
public:
	CIND18753Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CIND18753View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in IND_18753View.cpp
inline CIND18753Doc* CIND18753View::GetDocument() const
   { return reinterpret_cast<CIND18753Doc*>(m_pDocument); }
#endif

