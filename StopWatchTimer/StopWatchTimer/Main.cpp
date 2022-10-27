#include <iostream>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include "StopWatch.h"



int main() {

	std::cout << std::endl;

	StopWatch stopwatch("stopwatch1");

	stopwatch.Start();

	return 0;
}