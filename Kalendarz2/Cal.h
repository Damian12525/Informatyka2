/*
 * cal.hpp
 *
 *  Created on: 10-10-2017
 *      Author: Wawryka, Warzecha, Król
 */

#ifndef KALENDARZ_CAL_H
#define KALENDARZ_CAL_H

#include <iostream>
#include <cstdlib>
#include <ostream>
using namespace std;

class Cal
{
private:
	int year;
	int month;
	int day;

	friend Cal operator+ (int offset, Cal &old_cal);
public:

	Cal (int year = 1970, int month = 1, int day = 1);
	Cal (const Cal &old_cal);

	int getYear();
	int getMonth();
	int getDay();

	Cal recalculate ();

	Cal operator+ (int offset);
	Cal operator- (int offset);

	/*Cal operator+= (int offset);

	//Compare
	bool operator== (const Cal &cal2);
	bool operator!= (const Cal &cal2);

	int operator- (const Cal &cal1, const Cal &cal2);

	//Show
	//friend outstream& operator<<(ostream &out, const Cal &old_cal);
	*/

	void show ();

};

/*
class DateFormatter
{
public:
    void ComputerDateFormatter(const Cal &Cal);
    void GermanDateFormatter(const Cal &Cal);
};

*/

#endif //KALENDARZ_CAL_H
