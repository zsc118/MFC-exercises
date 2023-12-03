#pragma once
#include "ClockBase.h"
class CClockSecondHand :
	public CClockBase
{
public:
	CClockSecondHand();
	virtual ~CClockSecondHand();
	virtual void Draw(CDC *pDC);
};

