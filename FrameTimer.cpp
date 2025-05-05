#include "FrameTimer.h"

void FrameTimer::init(int fps)
{
    QueryPerformanceFrequency(&timerFreq);
    QueryPerformanceCounter(&timeNow);
    QueryPerformanceCounter(&timePrevious);

    requestedFps = fps;

    intervalsPerFrame = (float)(timerFreq.QuadPart / requestedFps);
}

int FrameTimer::framesToUpdate()
{
	int framesToUpdate = 0;
	QueryPerformanceCounter(&timeNow);

	intervalsSinceLastUpdate = (float)timeNow.QuadPart - (float)timePrevious.QuadPart;
	framesToUpdate = (int)(intervalsSinceLastUpdate / intervalsPerFrame);

	if (framesToUpdate != 0)
		QueryPerformanceCounter(&timePrevious);

	return framesToUpdate;
}
