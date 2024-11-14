//-------------------------------------

#include <iostream>

#include "lab4_object.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

void output_test(Pair& pair) {
    pair.setFirst(1000);
    std::cout << pair << std::endl;
}

//-------------------------------------

Pair create_fraction() {
    return Fraction(-50, 90);
}

//-------------------------------------

int main() {

    ///test class Pair
    Pair        pair,
                pair1;

    std::cout << "test class Pair" << std::endl;

    IDENT_PRINT;

    //input test
    std::cin >> pair;
    std::cin >> pair1;

    IDENT_PRINT;

    //compare test
    std::cout << "compare test" << std::endl;
    std::cout << (pair > pair1) << std::endl;
    std::cout << (pair < pair1) << std::endl;
    std::cout << (pair == pair1) << std::endl;
    std::cout << (pair != pair1) << std::endl;
    std::cout << (pair >= pair1) << std::endl;
    std::cout << (pair <= pair1) << std::endl;

    IDENT_PRINT;

    //output test
    std::cout << "output test" << std::endl;
    std::cout << pair << std::endl;
    std::cout << pair1 << std::endl;

    IDENT_PRINT;

    //assign test
    std::cout << "assign test" << std::endl;
    pair = pair1;
    std::cout << pair;

    IDENT_PRINT;

    std::cout << "test class Fraction" << std::endl;

    IDENT_PRINT;

    Fraction fraction;

    //input test
    std::cin >> fraction;
    std::cout << fraction << std::endl;

    IDENT_PRINT;

    std::cout << "Principle of substitution" << std::endl;

    IDENT_PRINT;

    output_test(fraction);
    pair = create_fraction();

    std::cout << pair << std::endl;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------