#include <iostream>
#include "Cal.h"
#include "DateFormatter.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;


    Cal data (1997,7,24);

    data.show();

    German GDF;
    Computer CDF;

    DateFormatter *DF = &CDF;

    cout << DF->format(data) << endl;


    return 0;
}