#pragma once
#include <chrono>
class Timer
{
public:
	Timer();
	float Mark();
	float Peek();
private:
	std::chrono::steady_clock::time_point last;
};

