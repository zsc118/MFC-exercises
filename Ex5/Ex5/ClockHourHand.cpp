#include "stdafx.h"
#include "ClockHourHand.h"

#include <math.h>
#define PI 3.14159265358979

CClockHourHand::CClockHourHand()
{
	m_mainColor = RGB(0, 255, 100);
	m_otherColor = RGB(128, 128, 0);
}


CClockHourHand::~CClockHourHand()
{
}

void CClockHourHand::Draw(CDC* pDC)
{
	CPen mainPen(PS_SOLID, 1, m_mainColor), otherPen(PS_SOLID, 1, m_otherColor);
	CBrush mainBrush(m_mainColor), otherBrush(m_otherColor);
	CPen* oldPen(pDC->SelectObject(&otherPen));
	CBrush* oldBrush(pDC->SelectObject(&mainBrush));
	int time((m_time.GetHour() % 12) * 3600 + m_time.GetMinute() * 60 + m_time.GetSecond());
	double theta(PI * time / 21600), s_theta(sin(theta)), c_theta(cos(theta));
	/*CPoint p1(m_region.CenterPoint()), p2(p1), p3(p1), p4(p1);
	int r(m_radius >> 1);
	p1.Offset(r*s_theta, -r*c_theta);
	r >>= 2;
	p3.Offset(-r*s_theta, r*c_theta);
	r >>= 1;
	p2.Offset(r*c_theta, r*s_theta);
	p4.Offset(-r*c_theta, -r*s_theta);*/
	CPoint P[4], *p(P + 3), *q(p);
	*p = m_region.CenterPoint();
	do *--q = *p; while (q != P);
	int r(m_radius >> 1);
	q->Offset(r*s_theta, -r*c_theta);
	r >>= 2;
	(--p)->Offset(-r*s_theta, r*c_theta);
	r >>= 1;
	(++q)->Offset(r*c_theta, r*s_theta);
	(++p)->Offset(-r*c_theta, -r*s_theta);
	pDC->Polygon(P, 4);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}