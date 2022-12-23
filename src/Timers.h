
#pragma once

#include <iostream>
#include <fstream>

#include "SDL2/SDL.h"

using std::ostream;
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

	// in milliseconds
	void setTime(double ms);
	// sets frame time which used to check if tick is needed (if frame time > count period)
	void setFrameTime(double ms);

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

	friend ostream& operator<<(ostream& os, const PeriodicTimer& timer);
	friend ostream& operator<<(ostream& os, const PeriodicTimer* timer);
};

ostream& operator<<(ostream& os, const PeriodicTimer& timer);
ostream& operator<<(ostream& os, const PeriodicTimer* timer);


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

	double getTimeLeft();


	private:
	double countdownTime;

	double currentTime;
	double prevTime = 0;

	long long amountTicks = 0;

	void countdown();

	friend ostream& operator<<(ostream& os, const CountdownTimer& timer);
	friend ostream& operator<<(ostream& os, const CountdownTimer* timer);
};

ostream& operator<<(ostream& os, const CountdownTimer& timer);
ostream& operator<<(ostream& os, const CountdownTimer* timer);
