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
	Date comp1, comp2;
	Date comp3 (2012, 12, 21);

	date.show();
	date += 10;
	date.show();
	
	if(comp1 == comp2)
		std::cout << "ok1" << std::endl;
	if(comp1 !=	comp2)
		std::cout << "błąd1" << std::endl;
	if(comp1 != comp3)
		std::cout << "ok2" << std::endl;
	if(comp2 == comp3)
		std::cout << "błąd błędem pogania" << std::endl;
	

	GermanDateFormatter GDF;
	ComputerDateFormatter CDF;

	DateFormatter *DF = &CDF;

	std::cout << DF->format(date) << std::endl;

	return 0;
}
