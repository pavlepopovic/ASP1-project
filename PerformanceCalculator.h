#pragma once
#include "windows.h"
class PerformanceCalculator
{
private:
	LARGE_INTEGER startCounter;
	LARGE_INTEGER stopCounter;
	LARGE_INTEGER frequency;
public:
	PerformanceCalculator() {
		startCounter.QuadPart = stopCounter.QuadPart = 0;
		QueryPerformanceFrequency(&frequency);
	}
	void start() {
		QueryPerformanceCounter(&startCounter);
	}
	void stop() {
		QueryPerformanceCounter(&stopCounter);
	}
	double elapsedMillis() const {
		return (stopCounter.QuadPart - startCounter.QuadPart)*1000. / frequency.QuadPart;
	}

};

