#include "stdafx.h"
#include "ClockSecondHand.h"

#include <math.h>
#define PI 3.14159265358979

CClockSecondHand::CClockSecondHand()
{
	m_mainColor = m_otherColor = RGB(0, 200, 200);
}


CClockSecondHand::~CClockSecondHand()
{
}


void CClockSecondHand::Draw(CDC *pDC)
{
	CPen mainPen(PS_SOLID, 1, m_mainColor);
	CPen* oldPen(pDC->SelectObject(&mainPen));
	CPoint P(m_region.CenterPoint());
	pDC->MoveTo(P);
	int r(m_radius - 10);
	double theta(PI * m_time.GetSecond() / 30);
	P.Offset(r*sin(theta), -r*cos(theta));
	pDC->LineTo(P);
	pDC->SelectObject(oldPen);
}