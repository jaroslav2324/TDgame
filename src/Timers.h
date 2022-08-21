
#pragma once

#include <iostream>

#include "SDL2/SDL.h"

using std::cout;
using std::endl;

/*Periodic timer with count period in milliseconds*/
class PeriodicTimer {
public:
	PeriodicTimer(const double countPeriod) : countPeriod(countPeriod) {
		currentTime = SDL_GetTicks();
	};

	/*copy constructor to set different countPeriod*/
	PeriodicTimer(PeriodicTimer& timer, double countPeriod): countPeriod(countPeriod){
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
bool PeriodicTimer::tickIfNeeded() {

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
double PeriodicTimer::getCountPeriod(){
	return countPeriod;
}

void PeriodicTimer::printAmountTicks() {

	cout << "Amount ticks: " << amountTicks << endl;
}

void PeriodicTimer::printCountPeriod() {

	cout << "Count period: " << countPeriod << endl;
}



/*starts countdown when created
countdown time in milliseconds*/
class CountdownTimer{
	public:
	CountdownTimer(double countdownTime);

	void addTime(double countdownTime);
	/*replaces timer time if new value is bigger*/ 
	void replaceToMoreTime(double countDownTime);
	void replaceTime(double countdownTime);

	bool isCountdownEnd();

	private:
	double countdownTime;

	double currentTime;
	double prevTime = 0;

	long long amountTicks = 0;

	void countdown();
};

CountdownTimer::CountdownTimer(double countdownTime){
	currentTime = SDL_GetTicks();
	CountdownTimer::countdownTime = countdownTime;
}

void CountdownTimer::countdown(){
	prevTime = currentTime;
	currentTime = SDL_GetTicks();

	if (countdownTime > 0)
		countdownTime -= currentTime - prevTime;
	else
		countdownTime = 0;
}

bool CountdownTimer::isCountdownEnd(){

	countdown();
	if (countdownTime > 0)
		return false;
	return true;
}

void CountdownTimer::addTime(double countdownTime){
	CountdownTimer::countdownTime += countdownTime;
}

void CountdownTimer::replaceToMoreTime(double countdownTime){
	if (countdownTime > CountdownTimer::countdownTime)
		CountdownTimer::countdownTime = countdownTime;
}

void CountdownTimer::replaceTime(double countdownTime){
	CountdownTimer::countdownTime = countdownTime;
}