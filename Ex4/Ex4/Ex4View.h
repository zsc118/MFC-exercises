
// Ex4View.h : CEx4View ��Ľӿ�
//

#pragma once


class CEx4View : public CView
{
protected: // �������л�����
	CEx4View();
	DECLARE_DYNCREATE(CEx4View)

// ����
public:
	CEx4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CEx4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	COLORREF m_color;
//	CFont m_font;
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CFont* m_font;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex4View.cpp �еĵ��԰汾
inline CEx4Doc* CEx4View::GetDocument() const
   { return reinterpret_cast<CEx4Doc*>(m_pDocument); }
#endif

