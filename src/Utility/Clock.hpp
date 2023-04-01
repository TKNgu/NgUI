#ifndef Clock_hpp
#define Clock_hpp

#include <chrono>

namespace il012e::utility {
class Clock {
public:
using Time = std::chrono::duration<double>;
public:
	Clock();
	Time restart();
private:
	std::chrono::time_point<std::chrono::steady_clock> startTime;
};
}

#endif
