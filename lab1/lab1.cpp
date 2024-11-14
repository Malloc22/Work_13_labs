//-------------------------------------

#include <iostream>

#include "lab1_fraction.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

Fraction::Vector make_vector(int x, int y) {
    return { x, y };
}

//-------------------------------------

int main() {

    //create objects
    Fraction fraction1;

    Fraction* fraction2 = new Fraction;
    delete fraction2;

    const int size = 2;
    Fraction fractions[size];
    Fraction* ptrFractions = new Fraction[size];

    Fraction* ptr[] = { fractions, ptrFractions };

    IDENT_PRINT;

    //filling array
    for(size_t i = 0; i < size*2; ++i) {

        if(i % size == 0)
            std::cout << "array '" << (int)(i/(size)) + 1 << "' filling:\n";

        std::cout << "iteration: " << (i%size) + 1 << std::endl;

        ptr[(int)(i/(size))][i%size].read();
    }

    IDENT_PRINT;

    //show array
    for(size_t i = 0; i < size*2; ++i) {

        if(i % size == 0)
            std::cout << "array '" << (int)(i/(size)) + 1 << "' show:\n";

        std::cout << "iteration: " << (i%size) + 1 << std::endl;

        ptr[(int)(i/(size))][i%size].show();

        if(i != size*2 - 1)
            std::cout << std::endl;
    }

    IDENT_PRINT;

    //call init, read, show for first instance
    std::cout << "init fraction1 { 2, 3 }\n";
    fraction1.init(2, 3);

    std::cout << "call show:\n\n";
    fraction1.show();

    std::cout << std::endl;
    std::cout << "call ipart: " << fraction1.ipart() << std::endl;

    IDENT_PRINT;

    std::cout << "call make_vector(6,5):\n";
    std::cout << "init fraction1 again:\n";

    fraction1.init(make_vector(6, 5));

    std::cout << "call show:\n";

    fraction1.show();

    delete []ptrFractions;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------