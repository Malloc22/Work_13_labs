//-------------------------------------

#ifndef LAB8_VECTOR_HPP_INCLUDED
#define LAB8_VECTOR_HPP_INCLUDED

//-------------------------------------

#include <iostream>
#include <cstdlib>
#include <cstdint>

//-------------------------------------

#define BASE_SIZE 4

//-------------------------------------

class Object;
class Event;

class Vector {
public:

    Vector();
    ~Vector();

    void add(Object* object);

    Object* operator[](const size_t pos) { return m_size < pos ? nullptr : m_objects[pos]; }

    size_t operator()() { return m_size; }

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    void show() { std::cout << *this << std::endl; }

    void pop_back();
    void clear();

    virtual void handleEvent(Event& event);

    friend std::ostream& operator<<(std::ostream& output, Vector& data);

protected:

    Object** m_objects;

private:

    size_t  m_capacity,
            m_size;

    void realloc();
};

//-------------------------------------

#endif // LAB8_VECTOR_HPP_INCLUDED

//-------------------------------------
