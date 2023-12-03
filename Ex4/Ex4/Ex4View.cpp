
// Ex4View.cpp : CEx4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CEx4View::On32771)
	ON_COMMAND(ID_32772, &CEx4View::On32772)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CEx4View ����/����

CEx4View::CEx4View()
{
	// TODO:  �ڴ˴���ӹ������

}

CEx4View::~CEx4View()
{
}

BOOL CEx4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx4View ����

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


// CEx4View ��ӡ

BOOL CEx4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEx4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEx4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CEx4View ���

#ifdef _DEBUG
void CEx4View::AssertValid() const
{
	CView::AssertValid();
}

void CEx4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx4Doc* CEx4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx4Doc)));
	return (CEx4Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx4View ��Ϣ�������


void CEx4View::On32771()
{
	// �޸���ɫ
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		m_color = dlg.GetColor();
		RedrawWindow();
	}
}


void CEx4View::On32772()
{
	// �޸�����
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
