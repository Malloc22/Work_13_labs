//-------------------------------------

#include "lab8_vector.hpp"
#include "lab8_object.hpp"

//-------------------------------------

Vector::Vector() {

    m_size = 0;
    m_capacity = 0;

    this->realloc();
}

//-------------------------------------

Vector::~Vector() {
    this->clear();
}

//-------------------------------------

void Vector::realloc() {
    if(m_size < m_capacity)
        return;

    if(m_capacity == 0) {
        m_capacity = BASE_SIZE;
        m_objects = new Object*[m_capacity];

        return;
    }

    m_capacity*=2;

    Object** array = new Object*[m_capacity];

    for(size_t i = 0; i < m_size; ++i)
        array[i] = m_objects[i];

    delete []m_objects;

    m_objects = array;
}

//-------------------------------------

void Vector::add(Object* object) {

    this->realloc();

    m_objects[m_size] = object;
    m_size++;
}

//-------------------------------------

void Vector::pop_back() {

    if(m_size == 0)
        return;

    Object* obj = (*this)[m_size-1];

    if(obj != nullptr)
        delete obj;

    obj = nullptr;
    m_size--;
}

//-------------------------------------

void Vector::clear() {

    for(size_t i = 0; i < m_size; ++i) {
        if(m_objects[i] != nullptr)
            delete m_objects[i];
    }

    delete []m_objects;

    m_size = 0;
    m_capacity = 0;
}

//-------------------------------------

void Vector::handleEvent(Event& event) {

    if(event.what == Event::Type::Message) {
        for(size_t i = 0; i < m_size; ++i)
            m_objects[i]->handleEvent(event);
    }
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Vector& data) {
    for(size_t i = 0; i < data.size(); ++i) {
        data[i]->show();
        if(i != data.size()-1)
            std::cout << std::endl;
    }

    return output;
}

//-------------------------------------

