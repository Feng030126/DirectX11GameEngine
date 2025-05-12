#pragma once
#include "D3DX.h"

class FrameTimer
{
public:
	void init(int);
	int framesToUpdate();

private:
    LARGE_INTEGER perfFreq;      // Performance counter frequency
    LARGE_INTEGER lastCount;     // Last counter value
    double frameInterval;        // Target frame time (seconds per update)
    double accumulator;    
};

