//-------------------------------------

#ifndef LAB13_TASK1_HPP_INCLUDED
#define LAB13_TASK1_HPP_INCLUDED

//-------------------------------------

#include <vector>
#include <numeric>
#include <functional>

#include <cmath>

//-------------------------------------

namespace Task1 {

    //-------------------------------------

    template<class T>
    void fill_array(std::vector<T>& data, size_t max, std::function<T(void)> function) {

        for(size_t i = 0; i < max; ++i)
            data.push_back(function());
    }

    //-------------------------------------

    template<class T>
    T replace_max_element(std::vector<T>& data, T t) {

        auto it = std::max_element(data.begin(), data.end());
        T buff = *it;

        std::replace_if(data.begin(), data.end(), [&](T a){ return a == *it; }, t);
        return buff;
    }

    //-------------------------------------

    template<class T>
    T pop_min_element(std::vector<T>& data) {

        auto it = std::min_element(data.begin(), data.end());
        T buff = *it;

        auto pos = std::remove(data.begin(), data.end(), buff);
        data.erase(pos, data.end());

        return buff;
    }

    //-------------------------------------

    template<class T, class N>
    T add_average_elements(std::vector<T>& data) {

        T average = std::accumulate(data.begin(), data.end(), T());
        average = average / (N)data.size();

        std::for_each(data.begin(), data.end(), [&](T& it){ it = it + average; });
        return average;
    }

    //-------------------------------------

    template<class T>
    void print(std::vector<T>& data) {

        std::cout << "array(" << &data << "): [";

        for(size_t i = 0; i < data.size(); ++i) {
            std::cout << data[i];
            if(i != data.size()-1)
                std::cout << ',';
        }

        std::cout << "]\n";
    }

    //-------------------------------------

};

//-------------------------------------

#endif // LAB13_TASK1_HPP_INCLUDED

//-------------------------------------
