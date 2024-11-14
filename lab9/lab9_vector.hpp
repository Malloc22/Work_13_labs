//-------------------------------------

#ifndef LAB9_VECTOR_HPP_INCLUDED
#define LAB9_VECTOR_HPP_INCLUDED

//-------------------------------------

#include <iostream>

#include "lab9_vector_exception.hpp"

//-------------------------------------


//uncomment to check for other exceptions
#define CUSTOM_EXCEPTION

//-------------------------------------

#define BASE_SIZE 4

//-------------------------------------

class Vector {
public:

    Vector();
    ~Vector();

    void add(int value);

    int& operator[](size_t pos);
    Vector operator+(const int& num);
    Vector operator-(size_t num);
    Vector& operator--();
    Vector& operator=(Vector vector);

    size_t operator()(){ return m_size; }

    size_t capacity() { return m_capacity; }
    size_t size() { return m_size; }

    void clear();

    friend std::ostream& operator<<(std::ostream& output, Vector& data);
    friend std::istream& operator>>(std::istream& input, Vector& data);

private:

    int* m_data;

    size_t  m_capacity,
            m_size;

    void realloc();
    void shift(size_t pos);
    void remove(size_t num);
};

//-------------------------------------

#endif // LAB9_VECTOR_HPP_INCLUDED

//-------------------------------------
