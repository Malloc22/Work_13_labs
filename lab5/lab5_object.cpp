//-------------------------------------

#include "lab5_object.hpp"

//-------------------------------------

//-------------------------------------
//  class Pair
//-------------------------------------

//-------------------------------------

Pair::Pair() {

    m_first = 0;
    m_second = 0;
}

//-------------------------------------

Pair::Pair(const Pair& pair) : Pair(pair.m_first, pair.m_second) {
    //
}

//-------------------------------------

Pair::Pair(int first, int second) {

    m_first = first;
    m_second = second;
}

//-------------------------------------

Pair::~Pair() {
    //
}

//-------------------------------------

int Pair::compareTo(const Pair& pair) {

#ifdef debug_v
    std::cout << "compare(" << this << "," << &pair << ")" << std::endl;
#endif // debug_v

    if(pair.m_first == m_first && pair.m_second == m_second)
        return 0;

    else if(m_first > pair.m_first || (m_first == pair.m_first && m_second > pair.m_second))
        return 1;

    return -1;
}

//-------------------------------------

Pair& Pair::operator=(const Pair& pair) {

    if(this == &pair)
        return *this;

    m_first = pair.m_first;
    m_second = pair.m_second;

    return *this;
}

//-------------------------------------

bool Pair::operator==(const Pair& pair) {

#ifdef debug_v
    std::cout << "operator== ";
#endif // debug_v

    return compareTo(pair) == 0;
}

//-------------------------------------

bool Pair::operator!=(const Pair& pair) {
#ifdef debug_v
    std::cout << "operator!= ";
#endif // debug_v
    return compareTo(pair) != 0;
}

//-------------------------------------

bool Pair::operator<(const Pair& pair) {
#ifdef debug_v
    std::cout << "operator< ";
#endif // debug_v
    return compareTo(pair) == -1;
}

//-------------------------------------

bool Pair::operator>(const Pair& pair) {
#ifdef debug_v
    std::cout << "operator> ";
#endif // debug_v
    return compareTo(pair) == 1;
}

//-------------------------------------

bool Pair::operator>=(const Pair& pair) {
#ifdef debug_v
    std::cout << "operator>= ";
#endif // debug_v
    return compareTo(pair) != -1;
}

//-------------------------------------

bool Pair::operator<=(const Pair& pair) {
#ifdef debug_v
    std::cout << "operator<= ";
#endif // debug_v
    return compareTo(pair) != 1;
}

//-------------------------------------

std::istream& operator>>(std::istream& input, Pair& pair) {

#ifdef debug_v
    std::cout << "object: " << &pair << std::endl;
#endif // debug_v

    std::cout << "first: ";
    input >> pair.m_first;

    std::cout << "second: ";
    input >> pair.m_second;

    return input;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Pair& pair) {

#ifdef debug_v
    std::cout << "object: " << &pair << std::endl;
#endif // debug_v

    return output   << "first: " << pair.m_first
                    << "\nsecond: " << pair.m_second;
}

//-------------------------------------

//-------------------------------------
//  class Fraction
//-------------------------------------

//-------------------------------------

Fraction::Fraction() : Pair() {
    //
}

//-------------------------------------

Fraction::Fraction(const Fraction& fraction) : Pair(fraction.m_first, fraction.m_second) {
    //
}

//-------------------------------------

Fraction::Fraction(int first, int second) : Pair(first, second) {
    //
}

//-------------------------------------

Fraction::~Fraction() {
    //
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Fraction& fraction) {

#ifdef debug_v
    std::cout << "object: " << &fraction << std::endl;
#endif // debug_v

    return output   << "first: " << fraction.m_first
                    << "\nsecond: " << fraction.m_second
                    << "\nipart: " << fraction.getIntPart()
                    << "\nfraction part: " << fraction.getFractionPart();
}

//-------------------------------------
