#include "stdafx.h"
#include "ClockWidget.h"


CClockWidget::CClockWidget()
{
}


CClockWidget::~CClockWidget()
{
}


void CClockWidget::PreSubclassWindow()
{
	GetClientRect(m_client);
	m_background.setRegion(m_client);
	m_hourhand.setRegion(m_client);
	m_minutehand.setRegion(m_client);
	m_secondhand.setRegion(m_client);
	SetTimer(1u, 1000u, nullptr);

	CStatic::PreSubclassWindow();
}
BEGIN_MESSAGE_MAP(CClockWidget, CStatic)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CClockWidget::OnSize(UINT nType, int cx, int cy)
{
	CStatic::OnSize(nType, cx, cy);

	GetClientRect(m_client);
	m_background.setRegion(m_client);
	m_hourhand.setRegion(m_client);
	m_minutehand.setRegion(m_client);
	m_secondhand.setRegion(m_client);
}


void CClockWidget::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate(FALSE);

	CStatic::OnTimer(nIDEvent);
}


void CClockWidget::OnPaint()
{
	CPaintDC dc(this);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(&dc, m_client.Width(), m_client.Height());
	dcMem.SelectObject(&bmp);
	//dcMem.SetBkColor(RGB(255, 255, 255));
	//static CBrush whiteBrush(RGB(255, 255, 255));
	//dcMem.SelectObject(&whiteBrush);
	DrawClock(&dcMem);
	dc.BitBlt(0, 0, m_client.Width(), m_client.Height(), &dcMem, 0, 0, SRCCOPY);
}


void CClockWidget::DrawClock(CDC* pDC)
{
	CTime time(CTime::GetTickCount());
	m_background.setTime(time);
	m_hourhand.setTime(time);
	m_minutehand.setTime(time);
	m_secondhand.setTime(time);
	m_background.Draw(pDC);
	m_secondhand.Draw(pDC);
	m_minutehand.Draw(pDC);
	m_hourhand.Draw(pDC);
}
