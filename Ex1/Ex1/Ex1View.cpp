
// Ex1View.cpp : CEx1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex1.h"
#endif

#include "Ex1Doc.h"
#include "Ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#include <string>

// CEx1View

IMPLEMENT_DYNCREATE(CEx1View, CView)

BEGIN_MESSAGE_MAP(CEx1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEx1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CEx1View 构造/析构

CEx1View::CEx1View()
{
	// TODO:  在此处添加构造代码
	
}

CEx1View::~CEx1View()
{
}

BOOL CEx1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx1View 绘制

void CEx1View::OnDraw(CDC* /*pDC*/)
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CEx1View 打印


void CEx1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEx1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEx1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CEx1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CEx1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEx1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEx1View 诊断

#ifdef _DEBUG
void CEx1View::AssertValid() const
{
	CView::AssertValid();
}

void CEx1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx1Doc* CEx1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx1Doc)));
	return (CEx1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx1View 消息处理程序


void CEx1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*std::string s("鼠标左键在 ( ");
	(((s += std::to_string(point.x)) += ", ") += std::to_string(point.y)) += " ) 按下!";
	MessageBox(s.c_str());*/
	/*CString s;
	s.Format(TEXT("鼠标左键在 ( %d , %d )按下！"), point.x, point.y);
	MessageBox(s);*/
	MessageBox(TEXT("鼠标左键按下！"));
	CView::OnLButtonDown(nFlags, point);
}


void CEx1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	/*CString s;
	s.Format(TEXT("鼠标右键在 ( %d , %d )按下！"), point.x, point.y);
	MessageBox(s);*/
	MessageBox(TEXT("鼠标右键按下！"));
	CView::OnRButtonDown(nFlags, point);
}


void CEx1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*if (GetKeyState(VK_SHIFT) < 0)
		MessageBox(TEXT("按下Shift键！"));
	else if (GetKeyState(VK_CONTROL) < 0)
		MessageBox(TEXT("按下Ctrl键！"));*/
	switch (nChar)
	{
	case VK_SHIFT:
		MessageBox(TEXT("按下Shift键！"));
		break;
	case VK_CONTROL:
		MessageBox(TEXT("按下Ctrl键！"));
	};
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CEx1View::OnMouseMove(UINT nFlags, CPoint point)
{
	CView::OnMouseMove(nFlags, point);
	//CPaintDC p(this);
	//Invalidate();
	auto p = GetDC();
	CBrush brush(RGB(255, 255, 255));
	p->SelectObject(&brush);
	p->PatBlt(0, 0, 500, 500, WHITENESS);
	CString s;
	s.Format(TEXT("鼠标位于 ( %d , %d )"), point.x, point.y);
	p->SetDCPenColor(BLACKNESS);
	p->TextOut(100, 100, s);
	//RedrawWindow(nullptr, nullptr, RDW_FRAME | RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);
}


void CEx1View::OnPaint()
{
	CPaintDC dc(this);
	CPoint p;
	GetCursorPos(&p);
	CString s;
	s.Format(TEXT("鼠标位于 ( %d , %d )"), p.x, p.y);
	dc.TextOut(100, 100, s);
}
