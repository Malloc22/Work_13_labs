//-------------------------------------

#include "lab10_time.hpp"

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

#ifdef LOG
    std::cout << "object: " << &time << std::endl;
#endif //LOG

    std::cout << "minutes: ";
    input >> time.m_minutes;

    std::cout << "seconds: ";
    input >> time.m_seconds;

    time.m_seconds %= MAX_SECONDS;

    return input;
}

//-------------------------------------

std::ostream& operator<<(std::ostream& output, Time& time) {
    return (output <<
#ifdef LOG
        "object: " << &time << "\n" <<
#endif // LOG
        time.getMinutes() << ":" << (int)time.getSeconds() << "\n");
}

//-------------------------------------

std::fstream& operator>>(std::fstream& input, Time& time) {

    std::string buffer;
    input >> buffer;

    size_t pos = buffer.find(":");

    try {

        time.m_minutes = std::stoi(buffer.substr(0, pos));
        time.m_seconds = std::stoi(buffer.substr(pos+1, buffer.size()));

    } catch(const std::exception& e) {  }

    time.m_seconds %= MAX_SECONDS;

    return  input;
}

//-------------------------------------
