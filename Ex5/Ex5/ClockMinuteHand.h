#pragma once
#include "ClockBase.h"
class CClockMinuteHand :
	public CClockBase
{
public:
	CClockMinuteHand();
	virtual ~CClockMinuteHand();
	virtual void Draw(CDC *pDC);
};

