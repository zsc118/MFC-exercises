#pragma once
#include "ClockBase.h"
template <double dir1, double dir2, double dir3, double dir4>
class CClockHandBase :
	public CClockBase
{
public:
	CClockHandBase();
	virtual ~CClockHandBase();
	virtual void Draw(CDC *pDC);
};

