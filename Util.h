#ifndef UTIL_H
#define UTIL_H

#include <iostream>

inline void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

#endif
