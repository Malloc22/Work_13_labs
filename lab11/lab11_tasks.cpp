//-------------------------------------

#include <iostream>
#include <vector>

#include "lab11_time.hpp"

#include "lab11_task1.hpp"
#include "lab11_task3.hpp"
#include "lab11_task4.hpp"
#include "lab11_task5.hpp"

//-------------------------------------

#define IDENT_PRINT printf("\n--------------------------\n\n")

//-------------------------------------

template <class T>
void template_task(BaseWrap<T>* data, std::function<T(void)> fillFunction, std::function<void(void)> custom = 0) {

    IDENT_PRINT;

    data->fillRandom(3, fillFunction);
    data->print();

    IDENT_PRINT;

    T buff;

    std::cout << "push front max element\n";
    buff = data->pushFrontMaxElement();
    std::cout << "max element: " << buff << std::endl;
    data->print();

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = data->popMinElement();
    std::cout << "min element: " << buff << std::endl;
    data->print();

    IDENT_PRINT;

    if(custom) {
        custom();
        IDENT_PRINT;
    }
}

//-------------------------------------

void task1() {

    std::cout << "Task1\n";

    std::vector<double> data;

    IDENT_PRINT;

    Task1::fill_array<double>(data, 3, []{ return (float)std::rand() / (float)(RAND_MAX / 3); });
    Task1::print(data);

    IDENT_PRINT;

    double buff;

    std::cout << "push front max element\n";
    buff = Task1::push_front_max_element(data);
    std::cout << "max element: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task1::pop_min_element(data);
    std::cout << "min element: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task1::add_average_elements<double, double>(data);
    std::cout << "average: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

}

//-------------------------------------

void task2() {

    std::cout << "Task2\n";

    std::vector<Time> data;

    IDENT_PRINT;

    Task1::fill_array<Time>(data, 3, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    Task1::print(data);

    IDENT_PRINT;

    Time buff;

    std::cout << "push front max element\n";
    buff = Task1::push_front_max_element(data);
    std::cout << "max element: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task1::pop_min_element(data);
    std::cout << "min element: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task1::add_average_elements<Time, int>(data);
    std::cout << "average: " << buff << std::endl;
    Task1::print(data);

    IDENT_PRINT;

}

//-------------------------------------

void task3() {

    std::cout << "Task3\n";

    Vector<Time> data;

    template_task<Time>(&data,
    []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); },
    [&]{
        std::cout << "add average elements\n";
        Time buff = data.addAverageElements<int>();
        std::cout << "average: " << buff << std::endl;
        data.print();
    });
}

//-------------------------------------

void task4() {

    std::cout << "Task4\n";

    std::stack<Time> data;

    IDENT_PRINT;

    Task4::fill_array<Time>(data, 3, []{ return Time(std::rand()%40, std::rand() % MAX_SECONDS); });
    Task4::print(data);

    IDENT_PRINT;

    Time buff;

    std::cout << "push front max element\n";
    buff = Task4::push_front_max_element(data);
    std::cout << "max element: " << buff << std::endl;
    Task4::print(data);

    IDENT_PRINT;

    std::cout << "pop min element\n";
    buff = Task4::pop_min_element(data);
    std::cout << "min element: " << buff << std::endl;
    Task4::print(data);

    IDENT_PRINT;

    std::cout << "add average elements\n";
    buff = Task4::add_average_elements<Time, int>(data);
    std::cout << "average: " << buff << std::endl;
    Task4::print(data);

    IDENT_PRINT;
}

//-------------------------------------

void task5() {

    std::cout << "Task5\n";

    StackWrap<double> data;

    template_task<double>(&data,
    []{ return (float)std::rand() / (float)(RAND_MAX / 3); },
    [&]{
        std::cout << "add average elements\n";
        double buff = data.addAverageElements<int>();
        std::cout << "average: " << buff << std::endl;
        data.print();
    });
}

//-------------------------------------
