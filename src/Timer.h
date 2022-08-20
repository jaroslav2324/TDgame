
#pragma once

#include <iostream>

#include "SDL2/SDL.h"

using std::cout;
using std::endl;

/*Periodic timer with count period in milliseconds*/
class Timer {
public:
	Timer(const double countPeriod) : countPeriod(countPeriod) {
		currentTime = SDL_GetTicks();
	};

	/*copy constructor to set different countPeriod*/
	Timer(Timer& timer, double countPeriod): countPeriod(countPeriod){
		prevTime = timer.prevTime;
		currentTime = timer.currentTime;
		frameTime = timer.frameTime;
		amountTicks = timer.amountTicks;
	}

	void printCountPeriod();
	void printAmountTicks();

	double getCountPeriod();

	bool tickIfNeeded();
protected:
	
	double prevTime = 0;
	double currentTime;
	double frameTime = 0;
    //in milliseconds
	const double countPeriod;

	long long amountTicks = 0;
};

/*return true if tick has been made otherwise false*/
bool Timer::tickIfNeeded() {

	prevTime = currentTime;
	currentTime = SDL_GetTicks();

	double deltaTime = currentTime - prevTime;

	frameTime += deltaTime;

	if (frameTime >= countPeriod) {
		frameTime -= countPeriod;
		amountTicks++;
		return true;
	}

	return false;
}

/*in milliseconds*/ 
double Timer::getCountPeriod(){
	return countPeriod;
}

void Timer::printAmountTicks() {

	cout << "Amount ticks: " << amountTicks << endl;
}

void Timer::printCountPeriod() {

	cout << "Count period: " << countPeriod << endl;
}
