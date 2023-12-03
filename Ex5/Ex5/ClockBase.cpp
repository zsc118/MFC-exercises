#include "stdafx.h"
#include "ClockBase.h"

//#include <math.h>
//#define PI 3.14159265358979

CClockBase::CClockBase()
{
	m_radius = 0;
	m_mainColor = RGB(255, 255, 255);
	m_otherColor = RGB(128, 128, 128);
}


CClockBase::~CClockBase()
{
}


// 设置绘图区域
void CClockBase::setRegion(LPRECT lprcRect)
{
	m_region = lprcRect;
	m_radius = (m_region.Width() > m_region.Height() ? m_region.Height() : m_region.Width()) >> 1;
}


// 设置当前时间
void CClockBase::setTime(const CTime& time)
{
	m_time = time;
}


// 设置颜色
void CClockBase::setColor(const COLORREF& mainColor, const COLORREF& otherColor)
{
	m_mainColor = mainColor;
	m_otherColor = otherColor;
}
