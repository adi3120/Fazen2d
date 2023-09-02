#include "headers/TimeManager.h"

TimeManager::TimeManager()
{
	Reset();
}

void TimeManager::Reset()
{
	tp1 = std::chrono::system_clock::now();
	tp2 = tp1;
}

float TimeManager::GetElapsedTime()
{
	tp2 = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsedTime = tp2 - tp1;
	tp1 = tp2;
	return elapsedTime.count();
}