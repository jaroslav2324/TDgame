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

void PeriodicTimer::setFrameTime(double ms){
	frameTime = ms;
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

ostream& operator<<(ostream& os, const PeriodicTimer& timer){
    cout << "Count period " << timer.countPeriod << " ms," << endl;
	cout << "Previous time " << timer.prevTime << " ms," << endl;
	cout << "Current time " << timer.currentTime << " ms," << endl;
	cout << "Frame time " << timer.frameTime << " ms." << endl;
    return os;
}

ostream& operator<<(ostream& os, const PeriodicTimer* timer){
    cout << "Count period " << timer->countPeriod << " ms," << endl;
	cout << "Previous time " << timer->prevTime << " ms," << endl;
	cout << "Current time " << timer->currentTime << " ms," << endl;
	cout << "Frame time " << timer->frameTime << " ms." << endl;
    return os;
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

double CountdownTimer::getTimeLeft(){
	return countdownTime;
}

ostream& operator<<(ostream& os, const CountdownTimer& timer){
    cout << "Countdown time " << timer.countdownTime << " ms," << endl;
	cout << "Previous time " << timer.prevTime << " ms," << endl;
	cout << "Current time " << timer.currentTime << " ms." << endl;
    return os;
}

ostream& operator<<(ostream& os, const CountdownTimer* timer){
    cout << "Countdown time " << timer->countdownTime << " ms," << endl;
	cout << "Previous time " << timer->prevTime << " ms," << endl;
	cout << "Current time " << timer->currentTime << " ms." << endl;
    return os;
}
