
// Ex4View.cpp : CEx4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Ex4.h"
#endif

#include "Ex4Doc.h"
#include "Ex4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx4View

IMPLEMENT_DYNCREATE(CEx4View, CView)

BEGIN_MESSAGE_MAP(CEx4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CEx4View::On32771)
	ON_COMMAND(ID_32772, &CEx4View::On32772)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEx4View 构造/析构

CEx4View::CEx4View()
{
	// TODO:  在此处添加构造代码

}

CEx4View::~CEx4View()
{
}

BOOL CEx4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx4View 绘制

void CEx4View::OnDraw(CDC* pDC)
{
	CEx4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->SelectObject(m_font);
	pDC->SetTextColor(m_color);
	pDC->TextOutW(100, 100, TEXT("Hello World"));
}


// CEx4View 打印

BOOL CEx4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEx4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CEx4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CEx4View 诊断

#ifdef _DEBUG
void CEx4View::AssertValid() const
{
	CView::AssertValid();
}

void CEx4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx4Doc* CEx4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx4Doc)));
	return (CEx4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx4View 消息处理程序


void CEx4View::On32771()
{
	// 修改颜色
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor();
		RedrawWindow();
	}
}


void CEx4View::On32772()
{
	// 修改字体
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		static LOGFONT t;
		dlg.GetCurrentFont(&t);
		delete m_font;
		(m_font=new CFont)->CreateFontIndirectW(&t);
		RedrawWindow();
	}
}

#include "MainFrm.h"

//const static CMainFrame* myFrame((CMainFrame*)AfxGetMainWnd());

int CEx4View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_color = RGB(0, 0, 0);
	(m_font=new CFont)->CreateFontW(0, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_DONTCARE, nullptr);
	/*CPoint p;
	GetCursorPos(&p);
	((CMainFrame*)AfxGetMainWnd())->OnMouseMove(0, p);*/
	/*CPoint p;
	GetCursorPos(&p);
	((CMainFrame*)AfxGetMainWnd())->initPointPrint(p);*/

	return 0;
}


void CEx4View::OnMouseMove(UINT nFlags, CPoint point)
{
	((CMainFrame*)AfxGetMainWnd())->OnMouseMove(nFlags, point);

	CView::OnMouseMove(nFlags, point);
}
