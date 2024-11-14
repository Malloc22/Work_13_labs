//-------------------------------------

#include <iostream>
#include <ctime>

#include "lab6_vector.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    srand(time(0));

    Vector vector;

    for(size_t i = 0; i < 20; ++i)
        vector.add(std::rand()%256);

    IDENT_PRINT;

    //print array
    std::cout << "print array" << std::endl;
    std::cout << vector << std::endl;

    IDENT_PRINT;

    //operator []
    std::cout << "operator []\nvector[0]:" << std::endl;
    std::cout << vector[0] << std::endl;

    IDENT_PRINT;

    //operator()
    std::cout << "operator ()" << std::endl;
    std::cout << vector() << std::endl;

    IDENT_PRINT;

    //test iterator
    std::cout << "test iterator" << std::endl;
    Iterator it = vector.first();

    std::cout << "first\n";
    std::cout << "*it: " << *it << std::endl;
    std::cout << "*(++it): " << *(++it) << std::endl;

    it = vector.last();

    std::cout << "second\n";
    std::cout << "*it: " << *it << std::endl;
    std::cout << "*(--it): " << *(--it) << std::endl;

    IDENT_PRINT;

    Vector vector1;
    for(size_t i = 0; i < 20; ++i)
        vector1.add(std::rand()%256);

    //test copy
    std::cout << "test copy" << std::endl;
    std::cout << "old: " << vector1 << std::endl;

    vector1 = vector;
    std::cout << "copy: " << vector1 << std::endl;

    IDENT_PRINT;

    //test operator+
    std::cout << "test operator+" << std::endl;
    std::cout << "old: " << vector << std::endl;
    vector = vector + 5;

    std::cout << "new +5:" << vector << std::endl;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------