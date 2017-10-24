#include "Date.h"

const int daysPerMonth [12] = {31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date (int _year, int _month , int _day ) {
	year = _year;
	month = _month;
	day = _day;
}

Date::Date (const Date &old_Date) {
	year = old_Date.year;
	month = old_Date.month;
	day = old_Date.day;

}

int Date::getDay() { return day; }

int Date::getMonth() { return month; }

int Date::getYear() { return year; }

void Date::reCalculate() {
	year += day / 365;
	day = day % 365;

	while(day > daysPerMonth[month-1])
	{
		month++;
		day = day % daysPerMonth[month-2];
		
		if(month == 13)
        {
            month = 1;
            year++;
        }

	}



	while(day < 1)
	{
		month--;
		day = daysPerMonth[month-1] + day;
		
		if(month == 0)
        {
            month = 12;
            year--;
        }
	}
	
}

Date Date::operator+(int offset) {

    Date tmp (*this);

    tmp.day += offset;

	tmp.reCalculate();

    return tmp;
}

Date operator+(int offset, Date &old_Date) {
	Date tmp = old_Date+offset;

	return tmp;
}

Date Date::operator-(int offset) {

    return this->operator+(-offset);
}

Date& Date::operator+= (const int offset) {
    this->day += offset;
    this->reCalculate();

	return *this;
}


bool Date::operator== (Date &date1) const {
	return (year == date1.year) && (month== date1.month) && (day == date1.day);
}

bool Date::operator!= (Date &date1) const {
	return !(*this == date1);
}

void Date::show() {
	std::cout << day << "-" << month << "-" << year << std::endl;
}
