#include "Timer.h"

void Timer::setTime(float time)
{
	this->time = time;
}

float Timer::getTime()
{
	time--;
	return time;
}
