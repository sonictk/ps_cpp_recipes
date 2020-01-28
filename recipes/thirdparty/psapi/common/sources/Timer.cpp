#include "Timer.h"
#include <time.h>

Timer::Timer()
{
	startTime = (double)clock();
	endTime = (double)clock();
}

Timer::~Timer()
{
}

void Timer::Start(void)
{
	startTime = (double)clock();
}

void Timer::Stop(void)
{
	endTime = (double)clock();
}

double Timer::GetTime(void)
{
	return ((endTime - startTime) / (double)CLOCKS_PER_SEC);
}

double Timer::GetElapsed(void)
{
	Stop();
	return GetTime();
}

// end Timer.cpp
