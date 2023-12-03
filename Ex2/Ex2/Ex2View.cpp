
// Ex2View.cpp : CEx2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex2.h"
#endif

#include "Ex2Doc.h"
#include "Ex2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <math.h>
//const double pi(52163.0 / 16604);
const double pi2(52163.0 / 33208);

// CEx2View

IMPLEMENT_DYNCREATE(CEx2View, CView)

BEGIN_MESSAGE_MAP(CEx2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEx2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CEx2View ����/����

CEx2View::CEx2View()
{
	// TODO:  �ڴ˴���ӹ������

}

CEx2View::~CEx2View()
{
}

BOOL CEx2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx2View ����

void CEx2View::OnDraw(CDC* pDC)
{
	CEx2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// ����sin(x)��ͼ���
	short k(550);
	CPoint sin_x[550], *p(sin_x+k);
	do
	{
		(--p)->x = 50 + k;
		p->y = 200 - 70 * sin(k * pi2 / 50 - pi2);
	} while (--k);
	CPen axis(PS_SOLID, 1, RGB(255, 0, 0)), fun(PS_SOLID, 2, RGB(0, 0, 0));
	pDC->SelectObject(axis);
	pDC->SetTextColor(RGB(255, 0, 0));
	// ����x��
	const short s_1(1), end(11);
	CString str(TEXT("-pi/2"));
	pDC->TextOutW(40, 205, str);
	pDC->MoveTo(50, 195);
	pDC->LineTo(50, 200);
	pDC->LineTo(100, 200);
	str.Format(TEXT("O"));
	pDC->TextOutW(90, 205, str);
	pDC->MoveTo(100, 195);
	pDC->LineTo(100, 200);
	while (++k != end)
	{
		short pos(100 + 50 * k);
		pDC->LineTo(pos, 200);
		if (k & s_1)
		{
			str.Format(TEXT("%d/2*pi"), k);
			pDC->TextOutW(pos - 25, 205, str);
		}
		else if (k != 2)
		{
			str.Format(TEXT("%d*pi"), k >> 1);
			pDC->TextOutW(pos - 15, 205, str);
		}
		else
		{
			str.Format(TEXT("pi"));
			pDC->TextOutW(pos - 5, 205, str);
		}
		pDC->MoveTo(pos, 195);
		pDC->LineTo(pos, 200);
	}
	// ����y��
	pDC->MoveTo(105, 340);
	pDC->LineTo(100, 340);
	str.Format(TEXT("-2"));
	pDC->TextOutW(80, 330, str);
	pDC->LineTo(100, 60);
	pDC->MoveTo(100, 270);
	pDC->LineTo(105, 270);
	pDC->MoveTo(100, 140);
	pDC->LineTo(105, 140);
	pDC->MoveTo(100, 60);
	pDC->LineTo(105, 60);
	str.Format(TEXT("-1"));
	pDC->TextOutW(80, 260, str);
	str.Format(TEXT("1"));
	pDC->TextOutW(85, 130, str);
	str.Format(TEXT("2"));
	pDC->TextOutW(85, 50, str);
	// ���ƺ���ͼ��
	pDC->SelectObject(fun);
	pDC->Polyline(p, 550);
}


// CEx2View ��ӡ


void CEx2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEx2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEx2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEx2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CEx2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEx2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEx2View ���

#ifdef _DEBUG
void CEx2View::AssertValid() const
{
	CView::AssertValid();
}

void CEx2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx2Doc* CEx2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx2Doc)));
	return (CEx2Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx2View ��Ϣ�������
