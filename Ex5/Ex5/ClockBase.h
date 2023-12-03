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
	// ���û�ͼ����
	void setRegion(LPRECT lprcRect);
	// ���õ�ǰʱ��
	void setTime(const CTime& time);
	// ������ɫ
	void setColor(const COLORREF& mainColor, const COLORREF& otherColor);

	virtual void Draw(CDC *pDC) = 0;
};

