//potrzebne?
#include "DateFormatter.h"

std::string GermanDateFormatter::format(Date date) {
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();

	char s[11];
	sprintf(s, "%02d.%02d.%04d\n", d, m, y);

    std::string to_print(s);

	return to_print;
}


std::string ComputerDateFormatter::format(Date date) {
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();

	char s[11];
	sprintf(s, "%04d-%02d-%02d\n", y, m, d);

    std::string to_print(s);

	return to_print;
}
