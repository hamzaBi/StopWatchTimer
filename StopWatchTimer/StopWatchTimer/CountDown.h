#pragma once
#include "Clock.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h> 
#include "Flag.h"
#include <thread>


class CountDown : public Clock
{

public:
	CountDown() = delete;
	CountDown(const char* p_Name):Clock(p_Name), m_Hours(0),m_Minutes(0), m_Seconds(0) {}
	CountDown(const char* p_Name, uint p_hours, uint p_minutes, uint p_seconds) : Clock(p_Name), m_Hours(p_hours), m_Minutes(p_minutes), m_Seconds(p_seconds){}
	void Start() override;
	void MainLoop();
	bool IsFinished() const;


	friend void __ClockLoop(CountDown&);
	friend std::ostream& operator<<(std::ostream&, const CountDown&);


private:
	uint m_Seconds;
	uint m_Minutes;
	uint m_Hours;

};

void __ClockLoop(CountDown&);
std::ostream& operator<<(std::ostream& , const CountDown&);

