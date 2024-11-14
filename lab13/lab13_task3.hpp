//-------------------------------------

#ifndef LAB13_TASK3_HPP_INCLUDED
#define LAB13_TASK3_HPP_INCLUDED

//-------------------------------------

#include <vector>
#include <numeric>
#include <functional>

#include <set>

#include "lab13_task1.hpp"

//-------------------------------------

namespace Task3 {

    //-------------------------------------

    template<class T>
    void fill_array(std::set<T>& data, size_t max, std::function<T(void)> function) {

        for(size_t i = 0; i < max; ++i)
            data.insert(function());
    }

    //-------------------------------------

    template<class T>
    T replace_max_element(std::set<T>& data, T t) {

        auto it = std::max_element(data.begin(), data.end());
        T buff = *it;

        data.erase(it);
        data.insert(t);

        return buff;
    }

    //-------------------------------------

    template<class T>
    T pop_min_element(std::set<T>& data) {

        auto it = std::min_element(data.begin(), data.end());
        T buff = *it;

        data.erase(it);

        return buff;
    }

    //-------------------------------------

    template<class T, class N>
    T add_average_elements(std::set<T>& data) {

        std::vector<T> buff;

        for(auto it : data)
            buff.push_back(it);

        T average = Task1::add_average_elements<T, N>(buff);

        data.clear();
        std::for_each(buff.begin(), buff.end(), [&](T& it){ data.insert(it); });

        return average;
    }

    //-------------------------------------

    template<class T>
    void print(std::set<T>& data) {

        std::cout << "array(" << &data << "): [";

        for(auto it = data.begin(); it != data.end(); ++it) {
            std::cout << *it;

            if(it != --data.end())
                std::cout << ',';
        }

        std::cout << "]\n";
    }

    //-------------------------------------

};

//-------------------------------------

#endif // LAB13_TASK1_HPP_INCLUDED

//-------------------------------------

