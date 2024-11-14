//-------------------------------------

#ifndef LAB7_VECTOR_HPP_INCLUDED
#define LAB7_VECTOR_HPP_INCLUDED

//-------------------------------------

#include <iostream>
#include <cstring>
#include <exception>

//-------------------------------------

#define BASE_SIZE 4

//-------------------------------------

template <class T>
class Vector {
public:

    Vector();
    Vector(const Vector& vector);
    ~Vector();

    void add(T value);

    T& operator[](const size_t pos) const;
    Vector operator+(const T num);
    Vector& operator=(Vector vector);

    size_t operator()(){ return m_size; }

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    void clear();

    template <class Output>
    friend std::ostream& operator<<(std::ostream& output, Vector<Output>& data);

    template <class Input>
    friend std::istream& operator>>(std::istream& input, Vector<Input>& data);

private:

    T* m_data;

    size_t  m_capacity,
            m_size;

    void realloc();
};

//-------------------------------------

template <class T>
Vector<T>::Vector() {

    m_size = 0;
    m_capacity = 0;

    this->realloc();
}

//-------------------------------------

template <class T>
Vector<T>::Vector(const Vector<T>& vector) : Vector() {

    for(size_t i = 0; i < vector.size(); ++i)
        this->add(vector[i]);
}

//-------------------------------------

template <class T>
Vector<T>::~Vector() {
    this->clear();
}

//-------------------------------------

template <class T>
void Vector<T>::realloc() {
    if(m_size < m_capacity)
        return;

    if(m_capacity == 0) {
        m_capacity = BASE_SIZE;
        m_data = new T[m_capacity];

        return;
    }

    m_capacity*=2;

    T* array = new T[m_capacity];

    for(size_t i = 0; i < m_size; ++i)
        array[i] = m_data[i];

    //memcpy(array, m_data, m_size*sizeof(T));

    delete []m_data;

    m_data = array;
}

//-------------------------------------

template <class T>
void Vector<T>::add(T value) {

    this->realloc();

    m_data[m_size] = value;
    m_size++;
}

//-------------------------------------

template <class T>
T& Vector<T>::operator[](const size_t pos) const {

    if(m_size < pos)
        throw std::range_error("m_size < pos");

    return m_data[pos];
}

//-------------------------------------

template <class T>
Vector<T> Vector<T>::operator+(const T num) {

    Vector<T> vector;

    for(size_t i = 0; i < this->size(); ++i)
        vector.add((*this)[i]+num);

    return vector;
}

//-------------------------------------

template <class T>
Vector<T>& Vector<T>::operator=(Vector vector) {

    if(&vector == this)
        return *this;

    this->clear();

    for(size_t i = 0; i < vector.size(); ++i)
        this->add(vector[i]);

    return *this;
}

//-------------------------------------

template <class T>
void Vector<T>::clear() {

    if(m_data != nullptr)
        delete []m_data;

    m_size = 0;
    m_capacity = 0;
}

//-------------------------------------

template <class T>
std::ostream& operator<<(std::ostream& output, Vector<T>& data) {

    output << "[";

    for(size_t i = 0; i < data.size(); ++i) {
        output << data[i];
        if(data.size()-1 != i)
            output << ",";
    }

    output << "]";

    return output;
}

//-------------------------------------

template <class T>
std::istream& operator>>(std::istream& input, Vector<T>& data) {

    std::cout << "add " << data.size() << " elements: ";

    int a;
    input >> a;

    data.add(a);

    return input;
}

//-------------------------------------

#endif // LAB7_VECTOR_HPP_INCLUDED

//-------------------------------------
