//-------------------------------------

#ifndef LAB13_TIME_HPP_INCLUDED
#define LAB13_TIME_HPP_INCLUDED

//-------------------------------------

#include <iostream>
#include <cstdint>

//-------------------------------------

#define MAX_SECONDS 60

//-------------------------------------

class Time {
public:

    Time();
    Time(int minutes, int seconds);
    Time(const Time& time);
    ~Time();

    int getMinutes() const { return m_minutes; }
    int getSeconds() const { return m_seconds; }

    void setMinutes(int minutes) { m_minutes = minutes; }
    void setSeconds(int seconds) { m_seconds = seconds % MAX_SECONDS; }

    void reset() { m_minutes = 0; m_seconds = 0; }

    Time& operator=(const Time& time);
    Time operator+(const Time& time);

    bool operator==(const Time& time) const;

    Time operator/(const Time& time);
    Time operator/(const int& num);

    bool operator>(const Time& time) const;
    bool operator<(const Time& time) const;

    friend std::istream& operator>>(std::istream& input, Time& time);
    friend std::ostream& operator<<(std::ostream& output, const Time& time);

private:

    int m_minutes,
        m_seconds;

};

//-------------------------------------

#endif // LAB13_TIME_HPP_INCLUDED

//-------------------------------------
