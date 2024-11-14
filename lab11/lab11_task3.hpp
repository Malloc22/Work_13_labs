//-------------------------------------

#ifndef LAB11_TASK3_HPP_INCLUDED
#define LAB11_TASK3_HPP_INCLUDED

//-------------------------------------

#include "lab11_base_wrap.hpp"
#include "lab11_task1.hpp"

//-------------------------------------

template<class T>
class Vector : public BaseWrap<T> {
private:

    typedef std::vector<T> data_t;

public:

    //-------------------------------------

    ~Vector() = default;

    //-------------------------------------

    /**
     * example Vector::fillRandom<double>(10, []{ return (double)std::rand() / (double)(RAND_MAX / 3.0d); });
     */
    void fillRandom(size_t max, std::function<T()> function) {
        Task1::fill_array<T>(m_data, max, function);
    }

    //-------------------------------------

    T pushFrontMaxElement() {
        return Task1::push_front_max_element<T>(m_data);
    }

    //-------------------------------------

    T popMinElement() {
        return Task1::pop_min_element<T>(m_data);
    }

    //-------------------------------------

    template <class N>
    T addAverageElements() {
        return Task1::add_average_elements<T, N>(m_data);
    }

    //-------------------------------------

    void print() {
        Task1::print<T>(m_data);
    }

    //-------------------------------------

private:

    data_t m_data;
};

//-------------------------------------

#endif // LAB11_TASK3_HPP_INCLUDED

//-------------------------------------
