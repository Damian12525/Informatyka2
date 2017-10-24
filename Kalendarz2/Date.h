#ifndef KALENDARZ_Date_H
#define KALENDARZ_Date_H

#include <iostream>
#include <cstdlib>
#include <ostream>

class Date
{
	private:
		int year;
		int month;
		int day;

		friend Date operator+ (int offset, Date &old_Date);
	public:
		Date (int year = 1970, int month = 1, int day = 1);
		Date (const Date &old_Date);

		int getYear();
		int getMonth();
		int getDay();

		Date reCalculate ();

		Date operator+ (int offset);
		Date operator- (int offset);
		Date& operator+= (int offset);
		bool operator== (Date &date1) const;
		bool operator!= (Date &date2) const;
	
		void show ();
	
};

#endif //KALENDARZ_Date_H
