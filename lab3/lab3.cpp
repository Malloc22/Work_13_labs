//-------------------------------------

#include <iostream>

#include "lab3_time.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    IDENT_PRINT;

    //call default constructor
    std::cout << "call default constructor\n";

    Time time;
    std::cout << time << std::endl;

    IDENT_PRINT;

    //call constructor with parameters
    std::cout << "call constructor with parameters\n";

    Time time1(21, 30);
    std::cout << time1 << std::endl;

    IDENT_PRINT;

    //call copy constructor
    std::cout << "call copy constructor:\n";

    Time time2(time1);
    std::cout << time2 << std::endl;

    IDENT_PRINT;

    std::cin >> time;
    std::cin >> time1;

    IDENT_PRINT;

    time2 = time + time1;

    std::cout << "operator +:" << std::endl;
    std::cout << time2 << std::endl;

    IDENT_PRINT;

    std::cout << "operator ==:" << std::endl;
    std::cout << "time:" << &time << " == time1:" << &time1 << " ? " << ((time == time1) ? "true" : "false")<< std::endl;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------
