
#pragma once

#include <iostream>
#include <fstream>

#include "SDL2/SDL.h"

using std::ostream;
using std::cout;
using std::endl;

//TODO refactor double -> int

/*Periodic timer with count period in milliseconds*/
class PeriodicTimer {
public:
	PeriodicTimer(const int countPeriod) : countPeriod(countPeriod) {
		currentTime = SDL_GetTicks();
	};

	/*copy constructor to set different countPeriod*/
	PeriodicTimer(PeriodicTimer& timer, int countPeriod): countPeriod(countPeriod){
		prevTime = timer.prevTime;
		currentTime = timer.currentTime;
		frameTime = timer.frameTime;
		amountTicks = timer.amountTicks;
	}

	// in milliseconds
	void setTime(int ms);
	// sets frame time which used to check if tick is needed (if frame time > count period)
	void setFrameTime(int ms);

	void printCountPeriod();
	void printAmountTicks();

	int getCountPeriod();
	int getTime();

	bool tickIfNeeded();
protected:
	
	int prevTime = 0;
	int currentTime;
	int frameTime = 0;
    //in milliseconds
	const int countPeriod;

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

	CountdownTimer(int countdownTime);

	void addTime(int countdownTime);
	/*replaces timer time if new value is bigger*/ 
	void replaceToMoreTime(int countDownTime);
	void replaceTime(int countdownTime);

	bool isCountdownEnd();

	int getTimeLeft();


	private:
	int countdownTime;

	int currentTime;
	int prevTime = 0;

	long long amountTicks = 0;

	void countdown();

	friend ostream& operator<<(ostream& os, const CountdownTimer& timer);
	friend ostream& operator<<(ostream& os, const CountdownTimer* timer);
};

ostream& operator<<(ostream& os, const CountdownTimer& timer);
ostream& operator<<(ostream& os, const CountdownTimer* timer);
