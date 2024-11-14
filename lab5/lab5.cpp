//-------------------------------------

#include <iostream>
#include <ctime>

#include "lab5_vector.hpp"
#include "lab5_object.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    srand(time(0));

    Vector data;

    IDENT_PRINT;

    for(int i = 0; i < 3; ++i) {

        Object* object;
        int a = std::rand()%2;

        switch(a){
            case 0: object = new Pair; break;
            case 1: object = new Fraction; break;
        }

        std::cin >> *(a == 0 ? (Pair*)object : (Fraction*)object);

        data.add(object);
    }

    IDENT_PRINT;

    std::cout << "array show: " << std::endl;
    std::cout << data;

    IDENT_PRINT;

    return 0;
}

//-------------------------------------