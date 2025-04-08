#pragma once
#include "D3DX.h"

class FrameTimer
{
public:
	void init(int);
	int framesToUpdate();

private:
	LARGE_INTEGER timerFreq{};
	LARGE_INTEGER timeNow{};
	LARGE_INTEGER timePrevious{};
	int requestedFps{};
	float intervalsPerFrame{};
	float intervalsSinceLastUpdate{};
};

