//-------------------------------------

#ifndef LAB12_TASK1_HPP_INCLUDED
#define LAB12_TASK1_HPP_INCLUDED

//-------------------------------------

#include <map>
#include <functional>
#include <numeric>

#include <cmath>

//-------------------------------------

namespace Task1 {

    //-------------------------------------

    template<class T, class N>
    void fill_array(std::multimap<T, N>& data, size_t max, std::function<N(void)> function) {

        for(size_t i = 0; i < max; ++i)
            data.insert({ i, function() });
    }

    //-------------------------------------

    template<class T, class N>
    N push_front_max_element(std::multimap<T, N>& data) {

        auto it = std::max_element(data.begin(), data.end(),
            [](std::pair<T, N> it0, std::pair<T, N> it1){ return it0.second < it1.second; });

        N buff = it->second;

        data.insert(data.begin(), { data.begin()->first, it->second });

        return buff;
    }

    //-------------------------------------

    template<class T, class N>
    N pop_min_element(std::multimap<T, N>& data) {

        auto it = std::min_element(data.begin(), data.end(),
            [](std::pair<T, N> it0, std::pair<T, N> it1){ return it0.second < it1.second; });

        N buff = it->second;

        data.erase(it);

        return buff;
    }

    //-------------------------------------

    template<class T, class N, class Custom>
    N add_average_elements(std::multimap<T, N>& data) {

        N average = std::accumulate(data.begin(), data.end(), N(),
            [](N buff, std::pair<T, N> it){ return buff + it.second; });

        average = average / (Custom)data.size();

        for(auto& it : data)
            it.second = it.second + average;

        return average;
    }

    //-------------------------------------

    template<class T, class N>
    void print(std::multimap<T, N>& data, char delimiter = ':') {

        std::cout << "array(" << &data << "): key";
        std::cout << delimiter << "num [";

        for(auto it = data.begin(); it != data.end(); ++it) {

            std::cout << it->first << delimiter << it->second;

            if(it != (--data.end()))
                std::cout << ",";
        }

        std::cout << "]\n";
    }

    //-------------------------------------

};

//-------------------------------------

#endif // LAB12_TASK1_HPP_INCLUDED

//-------------------------------------
