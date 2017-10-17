#include "Date.h"

int dpm [12] = {31,28,31,30,31,30,31,31,30,31,30,31};



Date :: Date (int _year, int _month , int _day )
{
	this -> year = _year;
	this -> month = _month;
	this -> day = _day;

}

Date :: Date (const Date &old_Date)
{
	this -> year = old_Date.year;
	this -> month = old_Date.month;
	this -> day = old_Date.day;

}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}





Date Date::reCalculate()
{

	//Date old_Date (year, month ,day);

	this -> year += day / 365;
	this ->day = day % 365;



	while(this -> day > dpm[this -> month-1])
	{
		month++;
		day = day % dpm[month-2];
	}

	while(day<1)
	{
		month--;
		day=dpm[month-1]+day;
	}

	return Date();
}

Date Date::operator+(int offset)
{
	day += offset;

	this->reDateculate();
	std::cout << "     //***** NORMAL PLUS *****//" << std::endl;

	return Date(*this);
}

Date Date::operator-(int offset)
{

	day -= offset;

	this->reDateculate();

	return Date();
}

Date operator+(int offset, Date &old_Date)
{
	std::cout << "     //***** SUPER PLUS *****//" << std::endl;

	old_Date.day += offset;
	old_Date.reCalculate();

	return Date(old_Date);
}

void Date::show()
{
	std::cout << day << "-" << month << "-" << year << std::endl;
}
