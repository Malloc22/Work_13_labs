//-------------------------------------

#include "lab8_object.hpp"
#include "lab8_dialog.hpp"

//-------------------------------------

//-------------------------------------
//  class Person
//-------------------------------------

//-------------------------------------

Person::Person() {
    m_age = 0;
}

//-------------------------------------

Person::Person(const Person& person) :
    Person(person.m_name, person.m_age) {
    //
}

//-------------------------------------

Person::Person(const std::string& name, int age) {

    m_name  = name;
    m_age   = age;
}

//-------------------------------------

Person::~Person() {
    //
}

//-------------------------------------

void Person::handleEvent(const Event& event) {

    if(event.what == Event::Type::Message) {
        switch(event.command) {
            case event.NameObject:
                std::cout << m_name << std::endl;
                break;

            default: break;
        }
    }
}

//-------------------------------------

Person& Person::operator=(const Person& person) {
    if(this == &person)
        return *this;

    m_name  = person.m_name;
    m_age   = person.m_age;

    return *this;
}

std::istream& operator>>(std::istream& input, Person& person) {

    std::cout << "name: ";
    input >> person.m_name;

    std::cout << "age: ";
    input >> person.m_age;

    return input;
}

std::ostream& operator<<(std::ostream& output, Person& person) {

    return output   << "name: " << person.m_name
                    << "\nage: "  << person.m_age;
}

//-------------------------------------

//-------------------------------------
//  class Student
//-------------------------------------

//-------------------------------------

Student::Student() : Person() {
    m_rating = 0;
}

//-------------------------------------

Student::Student(const Student& student) :
    Student(student.m_rating, student.m_name, student.m_age) {
    //
}

//-------------------------------------

Student::Student(float rating, const std::string& name, int age) :
    Person(name, age) {

    m_rating = rating;
}

//-------------------------------------

Student::~Student() {
    //
}

//-------------------------------------

Student& Student::operator=(const Student& student) {

    if(this == &student)
        return *this;

    *((Person*)this) = (Person)student;
    m_rating = student.m_rating;

    return *this;
}

//-------------------------------------

std::istream& operator>>(std::istream& input, Student& student) {

    std::cout << "rating: ";
    input >> student.m_rating;
    input >> ((Person&)student);

    return input;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Student& student) {

    return output << "rating: " << student.m_rating << "\n" << ((Person&)student);
}

//-------------------------------------
