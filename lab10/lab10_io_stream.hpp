//-------------------------------------

#ifndef LAB10_IO_STREAM_H_INCLUDED
#define LAB10_IO_STREAM_H_INCLUDED

//-------------------------------------

#include <fstream>

#include "lab10_time.hpp"

//-------------------------------------

namespace IOTime {

    //-------------------------------------

    bool write(const char* path, size_t n, std::ios_base::openmode mode = std::ios::out);

    //-------------------------------------

    bool read(const char* path);

    //-------------------------------------

    int remove(const char* path, const Time& time);

    //-------------------------------------

    int increase_specified_time(const char* path, const Time& cpecified, const Time& time);

    //-------------------------------------

    bool add(const char* path, size_t n, size_t shift);

    //-------------------------------------
}

//-------------------------------------

#endif // LAB10_IO_STREAM_H_INCLUDED

//-------------------------------------
