//-------------------------------------

#ifndef LAB6_VECTOR_HPP_INCLUDED
#define LAB6_VECTOR_HPP_INCLUDED

//-------------------------------------

#include <iostream>
#include <exception>

//-------------------------------------

#define BASE_SIZE 4

//-------------------------------------

class Vector;

class Iterator {
friend Vector;
public:

    Iterator() { m_current = nullptr; }
    Iterator(const Iterator& it) { m_current = it.m_current; }
    ~Iterator() {  }

    Iterator& operator++() { m_current++; return *this; }
    Iterator& operator--() { m_current--; return *this; }
    bool operator==(const Iterator& it) { return *m_current == *it.m_current; }
    bool operator!=(const Iterator& it) { return !(*this == it); }

    int& operator*() const { return *m_current; }

private:

    Iterator(int* current) { m_current = current; }

    int* m_current;
};

//-------------------------------------

class Vector {
public:

    Vector();
    ~Vector();

    void add(int value);

    int& operator[](const size_t pos);
    Vector operator+(const int num);
    Vector& operator=(Vector vector);

    size_t operator()(){ return m_size; }

    size_t capacity() { return m_capacity; }
    size_t size() { return m_size; }

    void clear();

    Iterator first() { return { m_data }; }
    Iterator last() { return { (m_data + m_size) - 1 }; }

    friend std::ostream& operator<<(std::ostream& output, Vector& data);
    friend std::istream& operator>>(std::istream& input, Vector& data);

private:

    int* m_data;

    size_t  m_capacity,
            m_size;

    void realloc();
};

//-------------------------------------

#endif // LAB6_VECTOR_HPP_INCLUDED

//-------------------------------------
