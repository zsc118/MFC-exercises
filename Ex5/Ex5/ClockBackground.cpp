#include "stdafx.h"
#include "ClockBackground.h"

#include <math.h>
#define PI 3.14159265358979
#include <stdint.h>

CClockBackground::CClockBackground()
{
	m_mainColor = RGB(0, 255, 0);
	m_otherColor = RGB(0, 128, 0);
	//m_otherColor = RGB(255, 255, 255);
}


CClockBackground::~CClockBackground()
{
}

void CClockBackground::Draw(CDC* pDC)
{
	CPen mainPen(PS_SOLID, 1, m_mainColor), otherPen(PS_SOLID, 1, m_otherColor);
	CBrush mainBrush(m_mainColor), otherBrush(m_otherColor);
	CPoint center(m_region.CenterPoint());
	int8_t i(60);
	CPen* oldPen(pDC->SelectObject(&otherPen));
	CBrush* oldBrush(pDC->SelectObject(&mainBrush));
	int r(m_radius - 8);
	do
		if (--i % 5)
		{
			CPoint p(center);
			double theta(PI * i / 30);
			p.Offset(r*sin(theta), r*cos(theta));
			CRect dot(-2, -2, 2, 2);
			dot.OffsetRect(p);
			pDC->Ellipse(dot);
		}
	while (i);
	pDC->SelectObject(&mainPen);
	pDC->SelectObject(&otherBrush);
	do
	{
		CPoint p(center);
		double theta(PI * i / 6);
		p.Offset(r*sin(theta), r*cos(theta));
		CRect dot(-3, -3, 3, 3);
		dot.OffsetRect(p);
		pDC->Rectangle(dot);
	} while (++i < 12);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
}