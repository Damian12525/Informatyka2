#include "DateFormatter.h"
#include <sstream>
#include <iomanip>


std::string GermanDateFormatter::format(Date date) {
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();

    std::ostringstream to_print;

    to_print<< std::setfill('0') << std::setw(2) <<d<<'.'<< std::setfill('0') << std::setw(2) <<m<<'.'<<y;
	
	return to_print.str();
}

std::string ComputerDateFormatter::format(Date date) {
	int y = date.getYear();
	int m = date.getMonth();
	int d = date.getDay();

    std::ostringstream to_print;

    to_print<<y<<'-'<< std::setfill('0') << std::setw(2) <<m<<'-'<< std::setfill('0') << std::setw(2) <<d;

    return to_print.str();
}
