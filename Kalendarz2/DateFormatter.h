#ifndef KALENDARZ_DATEFORMATTER_H
#define KALENDARZ_DATEFORMATTER_H

#include <sstream>

#include "Date.h"
#include <string.h>

class DateFormatter {
	public:
		virtual std::string format(Date date) = 0;
};

class GermanDateFormatter : public DateFormatter {
	public:
	std::string format(Date date) override;
};

class ComputerDateFormatter : public DateFormatter {
	public:
	std::string format(Date date) override;
};

#endif //KALENDARZ_DATEFORMATTER_H
