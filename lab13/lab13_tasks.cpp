//-------------------------------------

#include <iostream>
#include <map>

#include "lab13_time.hpp"
#include "lab13_task1.hpp"
#include "lab13_task2.hpp"
#include "lab13_task3.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

void task1() {

    std::cout << "task 1\n";

    IDENT_PRINT;

    std::vector<Time> data;

    Task1::fill_array<Time>(data, 4, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    Task1::print(data);

    IDENT_PRINT;

    Time buff;

    Time replace(10, 10);

    std::cout << "replace max element\n";
    buff = Task1::replace_max_element<Time>(data, replace);
    std::cout << "max element: " << buff << " replace: " << replace << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task1::pop_min_element(data);
    std::cout << "min element: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "sort\n";
    std::cout << "max to min\n";
    std::sort(data.begin(), data.end(), [&](Time t0, Time t1){ return t0 > t1; });

    Task1::print(data);

    std::cout << "min to max\n";
    std::sort(data.begin(), data.end(), [&](Time t0, Time t1){ return t0 < t1; });

    Task1::print(data);

    IDENT_PRINT;

    Time find(10, 10);

    std::cout << "find element: " << find << std::endl;

    auto pos = std::find(data.begin(), data.end(), find);

    if(pos != data.end())
        std::cout << "position: " << (pos - data.begin()) + 1 << std::endl;
    else
        std::cout << "not found!\n";

    Task1::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task1::add_average_elements<Time, int>(data);
    std::cout << "average: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;
}

//-------------------------------------

void task2() {

    std::cout << "task 2\n";

    IDENT_PRINT;

    std::stack<Time> data;

    Task2::fill_array<Time>(data, 4, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS);  });
    Task2::print(data);

    IDENT_PRINT;

    Time buff;

    Time replace(10, 10);

    std::cout << "replace max element\n";
    buff = Task2::replace_max_element<Time>(data, replace);
    std::cout << "max element: " << buff << " replace: " << replace << std::endl;
    Task2::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task2::pop_min_element<Time>(data);
    std::cout << "min element: " << buff << std::endl;
    Task2::print(data);

    IDENT_PRINT;

    std::cout << "sort\n";
    std::cout << "max to min\n";

    Time    *end   = &data.top() + 1,
            *begin = end - data.size();

    std::sort(begin, end, [&](Time& num0, Time& num1){ return num0 > num1; });

    Task2::print(data);

    std::cout << "min to max\n";
    std::sort(begin, end, [&](Time& num0, Time& num1){ return num0 < num1; });

    Task2::print(data);

    IDENT_PRINT;

    Time find(10, 10);

    std::cout << "find element: " << find << std::endl;

    auto pos = std::find(begin, end, find);

    if(pos != end)
        std::cout << "position: " << (pos - begin) + 1 << std::endl;
    else
        std::cout << "not found!\n";

    Task2::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task2::add_average_elements<Time, int>(data);
    std::cout << "average: " << buff << std::endl;
    Task2::print(data);

    IDENT_PRINT;
}

//-------------------------------------

void task3() {

    std::cout << "task 3\n";

    IDENT_PRINT;

    std::set<Time> data;

    Task3::fill_array<Time>(data, 4, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    Task3::print<Time>(data);

    IDENT_PRINT;

    Time buff;

    Time replace(10, 10);

    std::cout << "replace max element\n";
    buff = Task3::replace_max_element<Time>(data, replace);
    std::cout << "max element: " << buff << " replace: " << replace << std::endl;
    Task3::print<Time>(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task3::pop_min_element(data);
    std::cout << "min element: " << buff << std::endl;
    Task3::print(data);

    IDENT_PRINT;

    std::cout << "sort\n";
    std::cout << "max to min\n";

    std::vector<Time> buff_arr;

    for(auto it : data)
        buff_arr.push_back(it);

    std::sort(buff_arr.begin(), buff_arr.end(), [&](Time t0, Time t1){ return t0 > t1; });
    Task1::print<Time>(buff_arr);

    std::cout << "min to max\n";
    Task3::print<Time>(data);

    IDENT_PRINT;

    Time find(10, 10);

    std::cout << "find element: " << find << std::endl;

    auto pos = std::find(data.begin(), data.end(), find);

    if(pos != data.end())
        std::cout << "position: " << std::distance(data.begin(), pos) + 1 << std::endl;
    else
        std::cout << "not found!\n";

    Task3::print<Time>(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task3::add_average_elements<Time, int>(data);
    std::cout << "average: " << buff << std::endl;
    Task3::print<Time>(data);

    IDENT_PRINT;
}

//-------------------------------------
