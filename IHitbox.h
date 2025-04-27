#pragma once

#include "FrameTimer.h"

class IHitbox
{
public:
	virtual void setSize(float, float) = 0;
	virtual RECT hitBox() = 0;
};