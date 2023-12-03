#pragma once
class CClockBase
{
public:
	CClockBase();
	virtual ~CClockBase();
protected:
	COLORREF m_mainColor;
	COLORREF m_otherColor;
	CTime m_time;
	CRect m_region;
	int m_radius;
public:
	// 设置绘图区域
	void setRegion(LPRECT lprcRect);
	// 设置当前时间
	void setTime(const CTime& time);
	// 设置颜色
	void setColor(const COLORREF& mainColor, const COLORREF& otherColor);

	virtual void Draw(CDC *pDC) = 0;
};

