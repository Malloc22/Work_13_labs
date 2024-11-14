//-------------------------------------

#include "lab10_io_stream.hpp"

//-------------------------------------

void create_time(const size_t& n, std::fstream& temp) {

    Time time;
    for(size_t i = 0; i < n; ++i) {
        std::cin >> time;
        temp << time;
    }
}

//-------------------------------------

void path_editor(std::string& path) {

    std::string::iterator it = path.end();

    size_t pos = 0;
    while(it != path.begin()) {

        if(*it == '/' || *it == '\\') {
            pos = it - path.begin();
            break;
        }

        --it;
    }

    path = pos == 0 ? "./temp" : path.substr(0, pos+1) + "temp";
}

//-------------------------------------

bool IOTime::write(const char* path, size_t n, std::ios_base::openmode mode) {

    std::fstream stream(path, mode);

    if(!stream.is_open())
        return false;

    Time time;

    for(size_t i = 0; i < n; ++i) {
        std::cin >> time;
        stream << time;
    }

    stream.close();

    return true;
}

//-------------------------------------

bool IOTime::read(const char* path) {

    std::fstream stream(path, std::ios::in);

    if(!stream.is_open())
        return false;

    Time time;
    while(stream >> time)
        std::cout << "time: " << time;

    stream.close();

    return true;
}

//-------------------------------------

int IOTime::remove(const char* path, const Time& time) {

    std::string tempPath = path;

    path_editor(tempPath);

    std::fstream    stream(path, std::ios::in),
                    temp(tempPath, std::ios::out);

    int removed = 0;

    Time buffer;
    while(stream >> buffer) {

        if(time == buffer) {
            ++removed;
            continue;
        }

        temp << buffer;
    }

    temp.close();
    stream.close();

    if(removed == 0) {
        std::remove(tempPath.c_str());
        return removed;
    }

    std::remove(path);
    std::rename(tempPath.c_str(), path);

    return removed;
}

//-------------------------------------

int IOTime::increase_specified_time(const char* path, const Time& cpecified, const Time& time) {

    int edit = 0;

    std::string tempPath = path;
    path_editor(tempPath);

    std::fstream    stream(path, std::ios::in),
                    temp(tempPath, std::ios::out);

    Time buffer;
    while(stream >> buffer) {

        if(cpecified == buffer) {
            buffer = buffer + time;
            ++edit;
        }

        temp << buffer;
    }

    temp.close();
    stream.close();

    if(edit == 0) {
        std::remove(tempPath.c_str());
        return edit;
    }

    std::remove(path);
    std::rename(tempPath.c_str(), path);

    return edit;
}

//-------------------------------------

bool IOTime::add(const char* path, size_t n, size_t shift) {

    if(n == 0)
        return false;

    std::string tempPath = path;
    path_editor(tempPath);

    std::fstream    stream(path, std::ios::in),
                    temp(tempPath, std::ios::out);

    if(!stream.is_open())
        return false;

    Time buffer;

    size_t num = 0;
    bool isAdd = false;
    while(stream >> buffer) {
        if(num == shift) {
            create_time(n, temp);
            isAdd = true;
        }

        temp << buffer;
        ++num;
    }

    if(!isAdd)
        create_time(n, temp);

    temp.close();
    stream.close();

    std::remove(path);
    std::rename(tempPath.c_str(), path);

    return true;
}

//-------------------------------------
