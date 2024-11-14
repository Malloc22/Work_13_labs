//-------------------------------------

#ifndef LAB8_OBJECT_H_INCLUDED
#define LAB8_OBJECT_H_INCLUDED

//-------------------------------------

#include <iostream>

#include "lab8_dialog.hpp"

//-------------------------------------

class Object {
public:

    Object() = default;
    virtual ~Object() = default;

    virtual void show() = 0;
    virtual void input() = 0;

    virtual void handleEvent(const Event& event) = 0;
};

//-------------------------------------

class Person : public Object {
public:

    Person();
    Person(const Person& person);
    Person(const std::string& name, int age);
    ~Person();

    virtual void show() { std::cout << *this << std::endl; }
    virtual void input() { std::cin >> *this; }

    virtual void handleEvent(const Event& event);

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }

    void setName(const std::string& name) { m_name = name; }
    void setAge(int age) { m_age = age; }

    Person& operator=(const Person& person);

    friend std::istream& operator>>(std::istream& input, Person& person);
    friend std::ostream& operator<<(std::ostream& output, Person& person);

protected:

    std::string m_name;

    int m_age;
};

//-------------------------------------

class Student : public Person {
public:

    Student();
    Student(const Student& student);
    Student(float rating, const std::string& name, int age);
    ~Student();

    virtual void show() { std::cout << *this << std::endl; }
    virtual void input() { std::cin >> *this; }

    void setRating(float rating) { m_rating = rating; }
    float getRating() const { return m_rating; }

    Student& operator=(const Student& student);

    friend std::istream& operator>>(std::istream& input, Student& student);
    friend std::ostream& operator<<(std::ostream& output, Student& student);

protected:

    float m_rating;
};

//-------------------------------------

#endif // LAB8_OBJECT_H_INCLUDED

//-------------------------------------
