//-------------------------------------

#ifndef LAB13_TASK2_H_INCLUDED
#define LAB13_TASK2_H_INCLUDED

//-------------------------------------

#include <stack>

//-------------------------------------

namespace Task2 {

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
    T replace_max_element(std::stack<T>& data, T t) {

        T* end   = &data.top() + 1;
        T* begin = end - data.size();

        auto it = std::max_element(begin, end);
        T buff = *it;

        std::replace_if(begin, end, [&](T a){ return a == *it; }, t);
        return buff;
    }

    //-------------------------------------

    template<class T>
    T pop_min_element(std::stack<T>& data) {

        T* end   = &data.top() + 1;
        T* begin = end - data.size();

        auto it = std::min_element(begin, end);
        T buff = *it;

        std::remove(begin, end, buff);
        data.pop();

        return buff;
    }

    //-------------------------------------

    template<class T, class N>
    T add_average_elements(std::stack<T>& data) {

        T* end   = &data.top() + 1;
        T* begin = end - data.size();

        T average = std::accumulate(begin, end, T());
        average = average / (N)data.size();

        std::for_each(begin, end, [&](T& it){ it = it + average; });
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

#endif // LAB13_TASK2_H_INCLUDED

//-------------------------------------
