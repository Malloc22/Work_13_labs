//-------------------------------------

#include <iostream>
#include <map>

#include "lab12_time.hpp"

#include "lab12_task1.hpp"
#include "lab12_task3.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

void task1() {

    std::cout << "Task1\n";

    IDENT_PRINT;

    std::multimap<int, double> data;

    Task1::fill_array<int, double>(data, 4, []{ return (double)std::rand() / (double)RAND_MAX; });
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "push front max element\n";
    double max = Task1::push_front_max_element(data);

    std::cout << "max element: " << max << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    double min = Task1::pop_min_element<int, double>(data);

    std::cout << "min element: " << min << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    double average = Task1::add_average_elements<int, double, double>(data);

    std::cout << "average element: " << average << std::endl;
    Task1::print(data);

    IDENT_PRINT;
}

//-------------------------------------

void task2() {

    std::cout << "Task2\n";

    IDENT_PRINT;

    std::multimap<int, Time> data;

    Task1::fill_array<int, Time>(data, 4, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    Task1::print(data, '|');

    IDENT_PRINT;

    std::cout << "push front max element\n";
    Time max = Task1::push_front_max_element<int, Time>(data);

    std::cout << "max element: " << max << std::endl;
    Task1::print(data, '|');

    IDENT_PRINT;

    std::cout << "pop min element\n";
    Time min = Task1::pop_min_element(data);

    std::cout << "min element: " << min << std::endl;
    Task1::print(data, '|');

    IDENT_PRINT;

    std::cout << "add average elements\n";
    Time average = Task1::add_average_elements<int, Time, int>(data);

    std::cout << "average element: " << average << std::endl;
    Task1::print(data, '|');

    IDENT_PRINT;
}

//-------------------------------------

void task3() {


    std::cout << "Task3\n";

    CustomMap<int, Time> data;

    IDENT_PRINT;

    data.fillRandom(4, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    data.print('|');

    IDENT_PRINT;

    Time buff;

    std::cout << "push front max element\n";
    buff = data.pushFrontMaxElement();
    std::cout << "max element: " << buff << std::endl;
    data.print('|');

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = data.popMinElement();
    std::cout << "min element: " << buff << std::endl;
    data.print('|');

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = data.addAverageElements<int>();
    std::cout << "average: " << buff << std::endl;
    data.print('|');
}

//-------------------------------------
