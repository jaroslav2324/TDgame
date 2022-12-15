#include "Timers.h"

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

void PeriodicTimer::setTime(double ms){
	currentTime = ms;
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
