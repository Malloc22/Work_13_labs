//-------------------------------------

#include <iostream>

#include "lab9_vector.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    Vector vector;

    for(size_t i = 0; i < 10; ++i)
        vector.add(i);

    IDENT_PRINT;

    std::cout << "vector:" << std::endl;
    std::cout << vector << std::endl;

    IDENT_PRINT;

    std::cout << "operator[]" << std::endl;
    std::cout << vector[0] << std::endl;

    IDENT_PRINT;

    std::cout << "operator--" << std::endl;
    --vector;
    std::cout << vector << std::endl;

    IDENT_PRINT;

    std::cout << "operator-, vector = vector - 5, remove 5 last element" << std::endl;
    vector = vector - 5;
    std::cout << vector << std::endl;

    IDENT_PRINT;

    std::cout << "opertor+, add constant 5 to all elements of the array" << std::endl;
    vector = vector + 5;
    std::cout << vector << std::endl;

    IDENT_PRINT;

    std::cout << "test exception:" << std::endl;

#ifdef CUSTOM_EXCEPTION
    try {

        std::cout << "index > size, size: " << vector() << " | call " << "vector[100]" << std::endl;
        std::cout << vector[100] << std::endl;

    } catch (VectorException& e) {
        std::cout << "Error. Type: " << e.getCode() << std::endl;
    }

    std::cout << std::endl;

    try {

        std::cout << "removing n elements from the end of the array, where n > m_size" << " | call " << "vector = vector - 1000" << std::endl;
        vector = vector - 1000;

    } catch (VectorException& e) {
        std::cout << "Error. Type: " << e.getCode() << std::endl;
    }
#else
    try {

        std::cout << "index > size, size: " << vector() << " | call " << "vector[100]" << std::endl;
        std::cout << vector[100] << std::endl;

    } catch (std::exception& e) {
        std::cout << "Error" << std::endl;
    }

    std::cout << std::endl;

    try {

        std::cout << "removing n elements from the end of the array, where n > m_size" << " | call " << "vector = vector - 1000" << std::endl;
        vector = vector - 1000;

    } catch (std::exception& e) {
        std::cout << "Error" << std::endl;
    }
#endif

    IDENT_PRINT;

    return 0;
}

//-------------------------------------
