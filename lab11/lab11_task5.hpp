//-------------------------------------

#ifndef LAB11_TASK5_HPP_INCLUDED
#define LAB11_TASK5_HPP_INCLUDED

//-------------------------------------

#include <stack>

#include "lab11_base_wrap.hpp"
#include "lab11_task4.hpp"

//-------------------------------------

template <class T>
class StackWrap : public BaseWrap<T> {
private:

    typedef std::stack<T> data_t;

public:

    //-------------------------------------

    ~StackWrap() = default;

    //-------------------------------------

    /**
     * example StackWrap::fillRandom<double>(10, []{ return (double)std::rand() / (double)(RAND_MAX / 3.0d); });
     */
    void fillRandom(size_t max, std::function<T()> function) {
        Task4::fill_array<T>(m_data, max, function);
    }

    //-------------------------------------

    T pushFrontMaxElement() {
        return Task4::push_front_max_element<T>(m_data);
    }

    //-------------------------------------

    T popMinElement() {
        return Task4::pop_min_element<T>(m_data);
    }

    //-------------------------------------

    template <class N>
    T addAverageElements() {
        return Task4::add_average_elements<T, N>(m_data);
    }

    //-------------------------------------

    void print() {
        Task4::print<T>(m_data);
    }

    //-------------------------------------

private:

    data_t m_data;
};

//-------------------------------------

#endif // LAB11_TASK5_HPP_INCLUDED

//-------------------------------------
