//-------------------------------------

#include "lab6_vector.hpp"

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
        m_data = new int[m_capacity];

        return;
    }

    m_capacity*=2;

    int* array = new int[m_capacity];

    for(size_t i = 0; i < m_size; ++i)
        array[i] = m_data[i];

    delete []m_data;

    m_data = array;
}

//-------------------------------------

void Vector::add(int value) {

    this->realloc();

    m_data[m_size] = value;
    m_size++;
}

//-------------------------------------

int& Vector::operator[](const size_t pos) {

    if(m_size < pos)
        throw std::range_error("m_size < pos");

    return m_data[pos];
}

//-------------------------------------

Vector Vector::operator+(const int num) {

    Vector vector;

    for(size_t i = 0; i < this->size(); ++i)
        vector.add((*this)[i]+num);

    return vector;
}

//-------------------------------------

Vector& Vector::operator=(Vector vector) {

    if(&vector == this)
        return *this;

    this->clear();

    for(size_t i = 0; i < vector.size(); ++i)
        this->add(vector[i]);

    return *this;
}

//-------------------------------------

void Vector::clear() {

    if(m_data != nullptr)
        delete []m_data;

    m_size = 0;
    m_capacity = 0;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Vector& data) {

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

std::istream& operator>>(std::istream& input, Vector& data) {

    std::cout << "add " << data.size() << " elements: ";

    int a;
    input >> a;

    data.add(a);

    return input;
}

//-------------------------------------

