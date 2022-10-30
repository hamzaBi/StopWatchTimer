#include "CountDown.h"



std::ostream& operator<<(std::ostream& out, const CountDown& countdown) {
	out << countdown.m_Hours << ":" << countdown.m_Minutes << ":" << countdown.m_Seconds;
	return out;
}

bool CountDown::IsFinished() const {
	return m_Minutes <= 0 && m_Seconds <= 0 && m_Hours <= 0;
}

void __ClockLoop(CountDown& countdown) {
	while (!countdown.IsFinished()) {
		Sleep(1000);


		countdown.m_Seconds--;

		if (countdown.m_Seconds <= 0) {
			countdown.m_Seconds = 59;
			countdown.m_Minutes--;
		}

		if (countdown.m_Minutes <= 0) {
			countdown.m_Minutes = 59;
			countdown.m_Hours--;
		}

		system("cls");
		std::cout << countdown << "\n";
	}
}


void CountDown::MainLoop() {
	std::thread _ClockThread(__ClockLoop, std::ref(*this));

	_ClockThread.join();
}

void CountDown::Start() {
	MainLoop();
}