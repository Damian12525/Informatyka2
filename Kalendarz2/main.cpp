#include <iostream>
#include "Date.h"
#include "DateFormatter.h"

int main()
{

	std::cout << "     //***** Welcome to our Calendar *****//" << std::endl << std::endl;
	std::cout << "	[ALERT] Default date: ";
	Date date (1997,7,24);
	
	GermanDateFormatter GDF;
	ComputerDateFormatter CDF;

	DateFormatter *DF = &CDF;

	std::cout << DF->format(date) << std::endl;

	return 0;
}
