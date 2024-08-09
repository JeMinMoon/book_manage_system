#define _CRT_SECURE_NO_WARNINGS
#include "date.h"


Date::Date() {
	now = chrono::system_clock::now();
}
tm Date::getNow_time_t() {
	time_t now_time_t = chrono::system_clock::to_time_t(now);
	tm now_tm = *localtime(&now_time_t);
	return now_tm;
}

tm Date::getAfterTwoWeek() {
	chrono::duration<int, ratio<60 * 60 * 24>> two_week(14);
	auto future = now + two_week;
	time_t future_time_t = std::chrono::system_clock::to_time_t(future);
	tm future_tm = *std::localtime(&future_time_t);
	return future_tm;
}

bool Date::timeOver(tm r_date, tm now) {
	if (r_date.tm_year < now.tm_year)
		return true;
	if (r_date.tm_mon < now.tm_mon)
		return true;
	if (r_date.tm_mday < now.tm_mday)
		return true;
	return false;
}

QString Date::tmToQString(std::tm* tm, const char* format) {
    char buffer[100];
    if (std::strftime(buffer, sizeof(buffer), format, tm)) {
        return QString(buffer);
    } else {
        return QString();
    }
}
