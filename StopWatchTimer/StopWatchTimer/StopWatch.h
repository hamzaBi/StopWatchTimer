#pragma once

#include "Clock.h"
#include <thread>
#include <list>
#include <iostream>
#include <stdlib.h>
#include "Flag.h"



using  uint = unsigned int;


class StopWatch : public Clock {
public:
	StopWatch() = delete;
	StopWatch(const char* p_Name):Clock(p_Name),m_Millis(0),m_Minutes(0),m_Seconds(0),m_Hours(0) {
		StopWatch::m_Pause = false;
		StopWatch::m_Stop = false;
	}
	~StopWatch(){}
	void Start() override;
	void MainLoop();

	void Display() const {
		std::cout << m_Millis << ":" << m_Seconds << ":" << m_Minutes << ";" << m_Hours << std::endl;
	}


	Flag getFlag() const {
		return Flag{ m_Hours, m_Minutes, m_Seconds };
	}

	friend void __ClockLoop(StopWatch&);
	friend std::ostream& operator<<(std::ostream& out, const StopWatch& watch);
private:
	
	void __AddFlag();


private:
	uint m_Millis;
	uint m_Seconds;
	uint m_Minutes;
	uint m_Hours;

	std::thread m_MainThread;

	 static bool m_Pause;
	 static bool m_Stop;

	 std::list<std::pair<Flag, Flag>> m_Flags;
	
};


void __ClockLoop(StopWatch&);
std::ostream& operator<<(std::ostream& out, const StopWatch& watch);
std::ostream& operator<<(std::ostream& out, const std::pair<Flag, Flag>& flag);