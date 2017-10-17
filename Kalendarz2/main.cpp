//iostream czy ostream?
#include <iostream>
//Potrzebne?
#include "Date.h"
//Potrzebne?
#include "DateFormatter.h"

int main()
{

	std::cout << "     //***** Welcome to our Calendar *****//" << std::endl << std::endl;
	std::cout << "	[ALERT] Default date: ";
	Date date (1997,7,24);

	date.show();

	GermanDateFormatter GDF;
	ComputerDateFormatter CDF;

	DateFormatter *DF = &CDF;

	std::cout << DF->format(date) << std::endl;

	return 0;
}
