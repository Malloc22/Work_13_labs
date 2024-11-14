//-------------------------------------

#ifndef LAB5_VECTOR_HPP_INCLUDED
#define LAB5_VECTOR_HPP_INCLUDED

//-------------------------------------

#include <iostream>

//-------------------------------------

#define BASE_SIZE 4

//-------------------------------------

class Object;
class Vector {
public:

    Vector();
    ~Vector();

    void add(Object* object);

    Object* operator[](const size_t pos) { return m_size < pos ? nullptr : m_objects[pos]; }

    size_t capacity() { return m_capacity; }
    size_t size() { return m_size; }

    void clear();

    friend std::ostream& operator<<(std::ostream& output, Vector& data);

private:

    Object** m_objects;

    size_t  m_capacity,
            m_size;

    void realloc();
};

//-------------------------------------

#endif // LAB5_VECTOR_HPP_INCLUDED

//-------------------------------------
