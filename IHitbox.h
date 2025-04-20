#pragma once

#include "FrameTimer.h"

__interface IHitbox
{
	void setSize(float, float);
	RECT hitBox();
};