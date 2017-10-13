#include <iostream>
#include "Cal.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    Cal data (1997,7,24);

    data.show();



    data = 10 + data;

    data.show();




    return 0;
}