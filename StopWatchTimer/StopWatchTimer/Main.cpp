#include <iostream>
#include "StopWatch.h"
#include "CountDown.h"



int main() {

	/*std::cout << std::endl;

	StopWatch stopwatch("stopwatch1");

	stopwatch.Start();*/

	CountDown countdown("myCountDown", 0, 1, 10);

	countdown.Start();

	return 0;
}