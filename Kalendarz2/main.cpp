#include <iostream>
#include "Cal.h"
#include "DateFormatter.h"

int main()
{

	cout << "     //***** Welcome to our Calendar *****//" << endl << endl;
	cout << " //***** INSTRUCTION *****//" << endl << endl;
	cout << "1 | Write date" << endl;
	cout << "2 | currentDate + n * days" << endl;
	cout << "3 | n * days + currentDate" << endl;
	cout << "4 | currentDate - n * days" << endl;
	cout << "5 | Check if Date1 == Date2 is true" << endl;
	cout << "6 | Check if Date1 != Date2 is true" << endl;
	cout << "7 | Show my current Date" << endl;
	cout << "8 | Show ComputerDateFormatter" << endl;
	cout << "9 | Show GermanDateFormatter" << endl;

	cout << "	[ALERT] Default date: ";
	Cal data (1997,7,24);

	char key;

	switch(key)
	{
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
		case '9':
			break;
	}

	data.show();

	German GDF;
	Computer CDF;

	DateFormatter *DF = &CDF;

	cout << DF->format(data) << endl;

	return 0;
}
