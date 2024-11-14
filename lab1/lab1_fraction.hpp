//-------------------------------------

#ifndef LAB1_FRACTION_H_INCLUDED
#define LAB1_FRACTION_H_INCLUDED

//-------------------------------------

#include <iostream>

//-------------------------------------

class Fraction {
public:

    struct Vector {
        int x,
            y;
    };

public:

    Fraction();
    ~Fraction();

    void init(int x, int y);
    void init(Vector vector);

    void read();
    void show();

    int ipart();

private:

    Vector m_vector;

};

//-------------------------------------

#endif // LAB1_FRACTION_H_INCLUDED

//-------------------------------------
