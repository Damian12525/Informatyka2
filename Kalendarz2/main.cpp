#include <iostream>
#include "Date.h"
#include "DateFormatter.h"

int main()
{

	std::cout << "     //***** Welcome to our Calendar *****//" << std::endl << std::endl;
	std::cout << "	[ALERT] Default date: ";
	Date date (1997,1,1);
	
	date.show();

	date = date + 370;

	date.show();

	return 0;
}
