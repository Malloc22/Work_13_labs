//-------------------------------------

#include "lab12_time.hpp"

//-------------------------------------

Time::Time() {

    m_minutes = 0;
    m_seconds = 0;
}

//-------------------------------------

Time::Time(int minutes, int seconds) {

    this->setMinutes(minutes);
    this->setSeconds(seconds);
}

//-------------------------------------

Time::Time(const Time& time) {

    m_minutes = time.m_minutes;
    m_seconds = time.m_seconds;
}

//-------------------------------------

Time::~Time() {
    //
}

//-------------------------------------

Time& Time::operator=(const Time& time) {
    if(this == &time)
        return *this;

    m_minutes = time.m_minutes;
    m_seconds = time.m_seconds;

    return *this;
}

//-------------------------------------

Time Time::operator+(const Time& time) {

    uint32_t    newtime = time.m_minutes*MAX_SECONDS + time.m_seconds;
                newtime += (m_minutes*MAX_SECONDS + m_seconds);

    return Time(newtime/MAX_SECONDS, newtime%MAX_SECONDS);
}

//-------------------------------------

bool Time::operator==(const Time& time) const {
    return time.m_minutes == m_minutes && time.m_seconds == m_seconds;
}

//-------------------------------------

Time Time::operator/(const Time& time) {
    int time1 = m_minutes * MAX_SECONDS + m_seconds,
        time2 = time.m_minutes * MAX_SECONDS + time.m_seconds;

    return Time((time1/time2)/MAX_SECONDS, (time1/time2)%MAX_SECONDS);
}

//-------------------------------------

Time Time::operator/(const int& num) {
    int time = m_minutes * MAX_SECONDS + m_seconds;

    return Time((time/num)/MAX_SECONDS, (time/num)%MAX_SECONDS);
}

//-------------------------------------

bool Time::operator>(const Time& time) {
    return  (m_minutes > time.m_minutes ||
            (m_minutes == time.m_minutes && m_seconds > time.m_seconds));
}

//-------------------------------------

bool Time::operator<(const Time& time) {
    return  (m_minutes < time.m_minutes ||
            (m_minutes == time.m_minutes && m_seconds < time.m_seconds));
}

//-------------------------------------

std::istream& operator>>(std::istream& input, Time& time) {

    std::cout << "minutes: ";
    input >> time.m_minutes;

    std::cout << "seconds: ";
    input >> time.m_seconds;

    return input;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Time& time) {
    return (output << "time: " << time.getMinutes() << ":" << (int)time.getSeconds());
}

//-------------------------------------
