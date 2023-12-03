#pragma once
#include "ClockBase.h"
class CClockBackground :
	public CClockBase
{
public:
	CClockBackground();
	virtual ~CClockBackground();
	virtual void Draw(CDC *pDC);
};

