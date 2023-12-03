
// Ex4View.h : CEx4View 类的接口
//

#pragma once


class CEx4View : public CView
{
protected: // 仅从序列化创建
	CEx4View();
	DECLARE_DYNCREATE(CEx4View)

// 特性
public:
	CEx4Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CEx4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // Ex4View.cpp 中的调试版本
inline CEx4Doc* CEx4View::GetDocument() const
   { return reinterpret_cast<CEx4Doc*>(m_pDocument); }
#endif

