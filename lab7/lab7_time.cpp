//-------------------------------------

#include "lab3_time.hpp"

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

std::istream& operator>>(std::istream& input, Time& time) {

#ifdef debug_v
    std::cout << "object: " << &time << std::endl;
#endif //debug_v

    std::cout << "minutes: ";
    input >> time.m_minutes;

    std::cout << "seconds: ";
    input >> time.m_seconds;

    return input;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Time& time) {
    return (output <<
#ifdef debug_v
            "object: " << &time << "|" <<
#endif // debug_v
            "time: " << time.getMinutes() << ":" << (int)time.getSeconds());
}

//-------------------------------------
