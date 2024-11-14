//-------------------------------------

#include <iostream>

#include "lab2_student.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

int main() {

    //call constructor default
    std::cout << "call constructor default:\n";
    Student student;
    student.debugShow();

    IDENT_PRINT;

    //call constructor with parameters
    std::cout << "call constructor with parameters:\n";
    Student student1("Ivanov Ivan Ivanovich", "RIS-17-1", 4.5f);
    student1.debugShow();

    IDENT_PRINT;

    //call copy constructor
    std::cout << "call copy constructor:\n";
    Student student2(student1);
    student2.debugShow();

    return 0;
}

//-------------------------------------