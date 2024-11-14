//-------------------------------------

#ifndef LAB12_TASK3_HPP_INCLUDED
#define LAB12_TASK3_HPP_INCLUDED

//-------------------------------------

#include "lab12_task1.hpp"

//-------------------------------------

template<class T, class N>
class CustomMap {
private:

    typedef std::multimap<T, N> data_t;

public:

    //-------------------------------------

    ~CustomMap() = default;

    //-------------------------------------

    /**
     * example Vector::fillRandom<double>(10, []{ return (double)std::rand() / (double)(RAND_MAX / 3.0d); });
     */
    void fillRandom(size_t max, std::function<N()> function) {
        Task1::fill_array<T, N>(m_data, max, function);
    }

    //-------------------------------------

    N pushFrontMaxElement() {
        return Task1::push_front_max_element<T, N>(m_data);
    }

    //-------------------------------------

    N popMinElement() {
        return Task1::pop_min_element<T, N>(m_data);
    }

    //-------------------------------------

    template <class Custom>
    N addAverageElements() {
        return Task1::add_average_elements<T, N, Custom>(m_data);
    }

    //-------------------------------------

    void print(char delimiter = ':') {
        Task1::print<T, N>(m_data, delimiter);
    }

    //-------------------------------------

private:

    data_t m_data;
};

//-------------------------------------

#endif // LAB12_TASK3_HPP_INCLUDED

//-------------------------------------
