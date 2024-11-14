//-------------------------------------

#ifndef LAB11_TASK4_H_INCLUDED
#define LAB11_TASK4_H_INCLUDED

//-------------------------------------

#include <stack>

#include "lab11_task1.hpp"

//-------------------------------------

namespace Task4 {

    //-------------------------------------

    template <class T>
    void copy_stack_to_vector(std::stack<T>& stack, std::vector<T>& vector) {
        while(!stack.empty()) {
            vector.push_back(stack.top());
            stack.pop();
        }

        std::reverse(vector.begin(), vector.end());
    }

    //-------------------------------------

    template<class T>
    void fill_array(std::stack<T>& data, size_t max, std::function<T(void)> function) {

        for(size_t i = 0; i < max; ++i)
            data.push(function());
    }

    //-------------------------------------

    template<class T>
    T push_front_max_element(std::stack<T>& data) {

        std::vector<T> vector;
        copy_stack_to_vector(data, vector);

        T buff = Task1::push_front_max_element<T>(vector);

        for(auto& it : vector)
            data.push(it);

        return buff;
    }

    //-------------------------------------

    template<class T>
    T pop_min_element(std::stack<T>& data) {

        std::vector<T> vector;
        copy_stack_to_vector(data, vector);

        T buff = Task1::pop_min_element<T>(vector);

        for(auto& it : vector)
            data.push(it);

        return buff;
    }

    //-------------------------------------

    template<class T, class N>
    T add_average_elements(std::stack<T>& data) {

        std::vector<T> vector;
        copy_stack_to_vector(data, vector);

        T average = Task1::add_average_elements<T, N>(vector);

        for(auto& it : vector)
            data.push(it);

        return average;
    }

    //-------------------------------------

    template<class T>
    void print(std::stack<T>& data) {

        std::cout << "array(" << &data << "): [";

        T* end   = &data.top() + 1;
        T* begin = end - data.size();

        std::vector<T> vector(begin, end);

        for(size_t i = 0; i < vector.size(); ++i) {
            std::cout << vector[i];
            if(i != vector.size()-1)
                std::cout << ',';
        }

        std::cout << "]\n";
    }

    //-------------------------------------

}

//-------------------------------------

#endif // LAB11_TASK4_H_INCLUDED

//-------------------------------------
