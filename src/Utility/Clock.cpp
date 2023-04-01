#include "Clock.hpp"

using namespace std::chrono;
using namespace il012e::utility;

Clock::Clock() :
	startTime(steady_clock::now()) {
}

Clock::Time Clock::restart() {
	auto now = steady_clock::now();
	auto tmp = Time(now - this->startTime);
	this->startTime = now;
	return tmp;
}
