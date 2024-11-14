//-------------------------------------

#include "lab1_fraction.hpp"

#include <cassert>
#include <cmath>

//-------------------------------------

Fraction::Fraction() {
    m_vector = { 0, 0 };
}

//-------------------------------------

Fraction::~Fraction() {
    //
}

//-------------------------------------

void Fraction::init(int x, int y) {
    this->init({x, y});
}

//-------------------------------------

void Fraction::init(Vector vector) {
    m_vector = vector;
    assert("The denominator cannot be zero!" && m_vector.y != 0);
}

//-------------------------------------

void Fraction::read() {

    std::cout << "enter first: ";
    std::cin >> m_vector.x;

    std::cout << "enter second: ";
    std::cin >> m_vector.y;

    assert("The denominator cannot be zero!" && m_vector.y != 0);
}

//-------------------------------------

void Fraction::show() {

    std::cout   << "fisrt: " << m_vector.x
                << "\nsecond: " << m_vector.y << std::endl;

    assert("The denominator cannot be zero!" && m_vector.y != 0);

    double intpart = 0;

    modf((float)(m_vector.x / m_vector.y), &intpart);

    std::cout   << "first / second = "      << (float)m_vector.x / m_vector.y
                << "\nintpart: "            << ipart()
                << "\nintpart modf: "       << intpart << std::endl;
}

//-------------------------------------

int Fraction::ipart() {

    assert("The denominator cannot be zero!" && m_vector.y != 0);

    return m_vector.x / m_vector.y;
}

//-------------------------------------
