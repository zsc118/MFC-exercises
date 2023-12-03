#pragma once
#include "ClockBase.h"
class CClockHourHand :
	public CClockBase
{
public:
	CClockHourHand();
	virtual ~CClockHourHand();
	virtual void Draw(CDC *pDC);
};

