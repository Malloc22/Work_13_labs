//-------------------------------------

#ifndef LAB2_STUDENT_HPP_INCLUDED
#define LAB2_STUDENT_HPP_INCLUDED

//-------------------------------------

#include <iostream>

//-------------------------------------

class Student {
public:

    Student();
    Student(const Student& student);
    Student(std::string fcs, std::string group, float averageScore);
    ~Student();

    std::string getFcs() { return m_fcs; }
    std::string getGroup() { return m_group; }
    float getAverageScore() { return m_averageScore; }

    void setFcs(std::string fcs) { m_fcs = fcs; }
    void setGroup(std::string group) { m_group = group; }
    void setAverageScore(float averageScore) { m_averageScore = averageScore; }

#ifdef debug_v
    void debugShow() {
        std::cout   << "object: " << this
                    << "\nfcs: " << m_fcs
                    << "\ngroup: " << m_group
                    << "\naverage score: " << m_averageScore << std::endl;
    }
#endif // debug_v

private:

    std::string m_fcs,
                m_group;

    float m_averageScore;
};

//-------------------------------------

#endif // LAB2_STUDENT_HPP_INCLUDED

//-------------------------------------
