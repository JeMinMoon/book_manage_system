#include <chrono>

using namespace std;
class Date {

public:
	chrono::system_clock::time_point now;
	
	static bool timeOver(tm r_date, tm now);

	tm getNow_time_t();

	tm getAfterTwoWeek();
	Date();
};