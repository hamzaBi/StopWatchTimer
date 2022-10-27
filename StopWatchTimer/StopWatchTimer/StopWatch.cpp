#include "StopWatch.h"
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>


bool StopWatch::m_Stop;
bool StopWatch::m_Pause;


std::ostream& operator<<(std::ostream& out, const StopWatch& watch) {
	out << watch.m_Hours << ":" << watch.m_Minutes << ":" << watch.m_Seconds << ":" << watch.m_Millis << std::endl;
	return out;
}

/**
* __ClockLoop is private member function that will run clock loop until the class member m_Stop changes to true
* it sleeps for 1 milisecond each iteration this will cause a 10% error (which means after 100seconds we will get a 1 second error added I choose
* to ignore for now)
* the number of milliseconds resets when it gets to 1000 and I increment the number of seconds by 1 same for seconds and minutes when it reaches 60
* the maximum is set to 9999:00:00:000 when the stopwatch reaches it will restart automaticly
*/
void __ClockLoop(StopWatch & watch) {
	
	while (true) {
		if (StopWatch::m_Pause) {
			continue;
		}

		Sleep(1000);
		

		/*
		watch.m_Millis++;
		if (watch.m_Millis > 999) {
			watch.m_Seconds++;
			watch.m_Millis = 0;
		}*/

		watch.m_Seconds++;

		if (watch.m_Seconds > 59) {
			watch.m_Minutes++;
			watch.m_Seconds = 0;
		}

		if (watch.m_Minutes > 59) {
			watch.m_Hours++;
			watch.m_Minutes = 0;
		}

		if (watch.m_Hours == 9999) {
			watch.m_Minutes = 0;
			watch.m_Seconds = 0;
			watch.m_Millis = 0;
			watch.m_Hours = 0;
		}

		system("cls");
		std::cout << watch << "\n";

		if (StopWatch::m_Stop) break;
	}

}

/**
* MainLoop function will handle keyboard interactions 
* p : for pause
* e : for exit
* f : to mark a flag
*/
void StopWatch::MainLoop() {

	std::thread _MainThread(__ClockLoop, std::ref(*this));
	while (!StopWatch::m_Stop) {
		char choice = (char)_getch();

		switch (choice) {
		case 'p': {
			StopWatch::m_Pause = !StopWatch::m_Pause;
			break;
			}
		case 'e': {
			
			StopWatch::m_Stop = true;
			_MainThread.join();
			break;
		}
		case 'f':
		{
			__AddFlag();
			break;
		}
		}
	}
}


void StopWatch::__AddFlag() {

}

void StopWatch::Start()   {
	MainLoop();
}