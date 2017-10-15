//
// Created by Damian on 15.10.2017.
//

#ifndef KALENDARZ_DATEFORMATTER_H
#define KALENDARZ_DATEFORMATTER_H

#include "Cal.h"

class DateFormatter {


public:

    virtual string format(Cal date) = 0;


};


class German : public DateFormatter {
public:

    virtual string format(Cal date);

};


class Computer : public DateFormatter {
public:

    virtual string format(Cal date);


};


#endif //KALENDARZ_DATEFORMATTER_H
