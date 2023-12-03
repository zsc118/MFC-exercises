
// Ex1View.cpp : CEx1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CEx1View ����/����

CEx1View::CEx1View()
{
	// TODO:  �ڴ˴���ӹ������
	
}

CEx1View::~CEx1View()
{
}

BOOL CEx1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx1View ����

void CEx1View::OnDraw(CDC* /*pDC*/)
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CEx1View ��ӡ


void CEx1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEx1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEx1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEx1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CEx1View ���

#ifdef _DEBUG
void CEx1View::AssertValid() const
{
	CView::AssertValid();
}

void CEx1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx1Doc* CEx1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx1Doc)));
	return (CEx1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx1View ��Ϣ�������


void CEx1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	/*std::string s("�������� ( ");
	(((s += std::to_string(point.x)) += ", ") += std::to_string(point.y)) += " ) ����!";
	MessageBox(s.c_str());*/
	/*CString s;
	s.Format(TEXT("�������� ( %d , %d )���£�"), point.x, point.y);
	MessageBox(s);*/
	MessageBox(TEXT("���������£�"));
	CView::OnLButtonDown(nFlags, point);
}


void CEx1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	/*CString s;
	s.Format(TEXT("����Ҽ��� ( %d , %d )���£�"), point.x, point.y);
	MessageBox(s);*/
	MessageBox(TEXT("����Ҽ����£�"));
	CView::OnRButtonDown(nFlags, point);
}


void CEx1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	/*if (GetKeyState(VK_SHIFT) < 0)
		MessageBox(TEXT("����Shift����"));
	else if (GetKeyState(VK_CONTROL) < 0)
		MessageBox(TEXT("����Ctrl����"));*/
	switch (nChar)
	{
	case VK_SHIFT:
		MessageBox(TEXT("����Shift����"));
		break;
	case VK_CONTROL:
		MessageBox(TEXT("����Ctrl����"));
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
	s.Format(TEXT("���λ�� ( %d , %d )"), point.x, point.y);
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
	s.Format(TEXT("���λ�� ( %d , %d )"), p.x, p.y);
	dc.TextOut(100, 100, s);
}
