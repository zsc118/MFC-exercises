#pragma once
#include "afxwin.h"
#include "ClockBackground.h"
#include "ClockHourHand.h"
#include "ClockMinuteHand.h"
#include "ClockSecondHand.h"
class CClockWidget :
	public CStatic
{
public:
	CClockWidget();
	~CClockWidget();
private:
	CClockBackground m_background;
	CClockHourHand m_hourhand;
	CClockMinuteHand m_minutehand;
	CClockSecondHand m_secondhand;
	CRect m_client;
	virtual void PreSubclassWindow();
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnPaint();
	void DrawClock(CDC* pDC);
};

