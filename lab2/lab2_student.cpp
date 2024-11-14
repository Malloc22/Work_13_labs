//-------------------------------------

#include "lab2_student.hpp"

//-------------------------------------

Student::Student() {
    m_averageScore = 0.0f;
}

//-------------------------------------

Student::Student(const Student& student) {
    m_fcs           = student.m_fcs;
    m_group         = student.m_group;
    m_averageScore  = student.m_averageScore;
}

//-------------------------------------

Student::Student(std::string fcs, std::string group, float averageScore) {

    m_fcs           = fcs;
    m_group         = group;
    m_averageScore  = averageScore;
}

//-------------------------------------

Student::~Student() {
    //
}

//-------------------------------------
