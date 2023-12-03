#include "stdafx.h"
#include "ClockMinuteHand.h"

#include <math.h>
#define PI 3.14159265358979

CClockMinuteHand::CClockMinuteHand()
{
	m_mainColor = RGB(0, 255, 100);
	m_otherColor = RGB(128, 128, 0);
}


CClockMinuteHand::~CClockMinuteHand()
{
}


void CClockMinuteHand::Draw(CDC *pDC)
{
	CPen mainPen(PS_SOLID, 1, m_mainColor), otherPen(PS_SOLID, 1, m_otherColor);
	CBrush mainBrush(m_mainColor), otherBrush(m_otherColor);
	CPen* oldPen(pDC->SelectObject(&otherPen));
	CBrush* oldBrush(pDC->SelectObject(&mainBrush));
	int time(m_time.GetMinute() * 60 + m_time.GetSecond());
	double theta(PI * time / 1800), s_theta(sin(theta)), c_theta(cos(theta));
	CPoint P[4], *p(P + 3), *q(p);
	*p = m_region.CenterPoint();
	do *--q = *p; while (q != P);
	int r((m_radius << 1) / 3);
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