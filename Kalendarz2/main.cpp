#include <iostream>
#include "Date.h"
#include "DateFormatter.h"

int main()
{

	Date date (1997,1,1);
	ComputerDateFormatter CDF;

    std::cout<<CDF.format(date)<<std::endl;


	return 0;
}
