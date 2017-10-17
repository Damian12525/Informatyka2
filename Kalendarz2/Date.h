/*
 * Date.hpp
 *
 *  Created on: 10-10-2017
 *      Author: Wawryka, Warzecha, Król
 */

#ifndef KALENDARZ_Date_H
#define KALENDARZ_Date_H

#include <iostream>
#include <cstdlib>
#include <ostream>
//using namespace std;

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

	Date reDateculate ();

	Date operator+ (int offset);
	Date operator- (int offset);

	/*Date operator+= (int offset);

	//Compare
	bool operator== (const Date &Date2);
	bool operator!= (const Date &Date2);

	int operator- (const Date &Date1, const Date &Date2);

	//Show
	//friend outstream& operator<<(ostream &out, const Date &old_Date);
	*/

	void show ();

};

#endif //KALENDARZ_Date_H
