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

Date Date::reCalculate() {
	year += day / 365;
	day = day % 365;

	while(day > daysPerMonth[month-1])
	{
		month++;
		day = day % daysPerMonth[month-2];
		
		if(month == 12)
			month = 1;
	}

	while(day < 1)
	{
		month--;
		day = daysPerMonth[month-1] + day;
		
		if(month == -1)
			month = 12;
	}
	
	return Date();
}

Date Date::operator+(int offset) {
	day += offset;

	this->reCalculate();
	
	return Date(*this);
}

Date operator+(int offset, Date &old_Date) {
	old_Date.day += offset;
	old_Date.reCalculate();

	return Date(old_Date);
}

Date Date::operator-(int offset) {
	day -= offset;

	this->reCalculate();

	return Date();
}

Date& Date::operator+= (const int offset) {
	day += offset;
	this->reCalculate();
	return *this;
}


bool Date::operator== (Date &date1) const {
	if( (year == date1.year) && (month== date1.month) && (day == date1.day))
		return true;
	else
		return false;
}

bool Date::operator!= (Date &date1) const {
	return !(*this == date1);
}

void Date::show() {
	std::cout << day << "-" << month << "-" << year << std::endl;
}
