#include "stdafx.h"
#include "ClockHandBase.h"


template <double dir1, double dir2, double dir3, double dir4>
CClockHandBase<dir1, dir2, dir3, dir4>::CClockHandBase()
{
	m_mainColor = RGB(0, 255, 100);
	m_otherColor = RGB(128, 128, 0);
}


template <double dir1, double dir2, double dir3, double dir4>
CClockHandBase<dir1, dir2, dir3, dir4>::~CClockHandBase()
{
}


template <double dir1, double dir2, double dir3, double dir4>
void CClockHandBase<dir1, dir2, dir3, dir4>::Draw(CDC *pDC)
{
	CPen mainPen(PS_SOLID, 1, m_mainColor), otherPen(PS_SOLID, 1, m_otherColor);
	CBrush mainBrush(m_mainColor), otherBrush(m_otherColor);
	CPen* oldPen(pDC->SelectObject(&otherPen));
	CBrush* oldBrush(pDC->SelectObject(&mainBrush));
}