/*

Class file for objects that hold function termination time

*/
#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Timer
{
public:
	clock_t timeStart;
	clock_t timeStop;

	void start() //start timing
	{
		timeStart = clock();
	}

	void stop() //stop timing
	{
		timeStop = clock();
	}

	clock_t time() //display elapsed time
	{
		return (timeStop - timeStart) / (double)(CLOCKS_PER_SEC / 1000);
	}
};