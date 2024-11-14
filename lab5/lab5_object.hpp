//-------------------------------------

#ifndef LAB5_OBJECT_HPP_INCLUDED
#define LAB5_OBJECT_HPP_INCLUDED

//-------------------------------------

#include <iostream>

//-------------------------------------

class Object {
public:

    Object() {  }
    virtual ~Object() {  }

    virtual void show() = 0;
};

//-------------------------------------

class Pair : public Object {
public:

    Pair();
    Pair(const Pair& pair);
    Pair(int first, int second);
    virtual ~Pair();

    int getFirst() { return m_first; }
    int getSecond() { return m_second; }

    void setFirst(int first) { m_first = first; }
    void setSecond(int second) { m_second = second; }

    void show() { std::cout << *this << std::endl; }

    Pair& operator=(const Pair& pair);

    bool operator==(const Pair& pair);
    bool operator<(const Pair& pair);
    bool operator>(const Pair& pair);
    bool operator>=(const Pair& pair);
    bool operator<=(const Pair& pair);
    bool operator!=(const Pair& pair);

    friend std::istream& operator>>(std::istream& input, Pair& pair);
    friend std::ostream& operator<<(std::ostream& output, Pair& pair);

protected:

    int m_first,
        m_second;

    int compareTo(const Pair& pair);
};

//-------------------------------------

class Fraction : public Pair {
public:

    Fraction();
    Fraction(const Fraction& fraction);
    Fraction(int first, int second);
    virtual ~Fraction();

    int getIntPart() { return (int)(m_first / m_second); }
    float getFractionPart() { return ((float)m_first / (float)m_second) - ((int)(m_first / m_second)); }

    void show() { std::cout << *this << std::endl; }

    friend std::ostream& operator<<(std::ostream& output, Fraction& fraction);

protected:

};

//-------------------------------------

#endif // LAB5_OBJECT_HPP_INCLUDED

//-------------------------------------
