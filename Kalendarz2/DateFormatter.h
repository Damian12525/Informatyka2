#ifndef KALENDARZ_DATEFORMATTER_H
#define KALENDARZ_DATEFORMATTER_H

//potrzebne?
#include "Date.h"

class DateFormatter {
	public:
		virtual std::string format(Date date) = 0;
};

class GermanDateFormatter : public DateFormatter {
	public:
		virtual std::string format(Date date);
};

class ComputerDateFormatter : public DateFormatter {
	public:
		virtual std::string format(Date date);
};

#endif //KALENDARZ_DATEFORMATTER_H
