//
// Created by Damian on 12.10.2017.
//

#include "Cal.h"









Cal :: Cal (int year, int month , int day )
{
    this -> year = year;
    this -> month = month;
    this -> day = day;

}

Cal :: Cal (const Cal &old_cal)
{
    this -> year = old_cal.year;
    this -> month = old_cal.month;
    this -> day = old_cal.day;

}

Cal Cal::recalculate() {

    //Cal old_cal (year, month ,day);

    this -> year+=day/365;
    this ->day = day%365;

    int dpm [12] = {31,28,31,30,31,30,31,31,30,31,30,31};   //day per month

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




    return Cal();
}

Cal Cal::operator+(int offset) {
    day+=offset;

    this->recalculate();
    cout<<"Zwykly plus"<<endl;


    return Cal(*this);
}

void Cal::show() {

    cout<< day <<"-"<<month<<"-"<<year<<endl;

}

Cal Cal::operator-(int offset) {

    day-=offset;

    this->recalculate();


    return Cal();
}

Cal operator+(int offset, Cal &old_cal) {

        cout<<"niezwykly plus"<<endl;
    old_cal.day+=offset;
    old_cal.recalculate();

    return Cal(old_cal);
}






