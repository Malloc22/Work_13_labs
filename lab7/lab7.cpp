//-------------------------------------

#include <iostream>

#include "lab7_vector.hpp"
#include "lab7_time.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    Vector<int> dataInt;
    Vector<float> dataFloat;
    Vector<double> dataDouble;

    dataInt.add(4);
    dataInt.add(6);

    dataFloat.add(5.4f);
    dataFloat.add(2.5f);

    dataDouble.add(5.5435f);
    dataDouble.add(2.4324f);

    IDENT_PRINT;

    std::cout << "test template:" << std::endl;

    std::cout << "int:";
    std::cout << dataInt << std::endl;

    std::cout << "float:";
    std::cout << dataFloat << std::endl;

    std::cout << "double:";
    std::cout << dataDouble << std::endl;

    IDENT_PRINT;

    std::cout << "test operator+:" << std::endl;
    std::cout << "int:+5; float:+5.1f, double:+5.2f" << std::endl;

    dataInt = dataInt + 5;
    dataFloat = dataFloat + 5.1f;
    dataDouble = dataDouble + 5.2f;

    std::cout << "int:";
    std::cout << dataInt << std::endl;

    std::cout << "float:";
    std::cout << dataFloat << std::endl;

    std::cout << "double:";
    std::cout << dataDouble << std::endl;

    IDENT_PRINT;

    std::cout << "test operator():" << std::endl;

    std::cout << "size(int): " << dataInt() << std::endl;
    std::cout << "size(float): " << dataFloat() << std::endl;
    std::cout << "size(double): " << dataDouble() << std::endl;

    IDENT_PRINT;

    Vector<Time> dataTime;

    dataTime.add(Time(10, 20));
    dataTime.add(Time(12, 20));

    std::cout << "test type Time\n";

    IDENT_PRINT;

    std::cout << "operator<<" << std::endl;
    std::cout << dataTime << std::endl;

    IDENT_PRINT;

    std::cout << "operator+" << std::endl;
    std::cout << "+Time(10, 10)" << std::endl;

    dataTime = dataTime + Time(10, 10);

    std::cout << dataTime << std::endl;

    IDENT_PRINT;

    std::cout << "operator[]" << std::endl;
    std::cout << dataTime[0] << std::endl;

    IDENT_PRINT;

    std::cout << "operator>>" << std::endl;
    std::cin >> dataTime[0];
    std::cout << dataTime[0] << std::endl;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------
