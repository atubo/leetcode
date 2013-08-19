#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>

inline void printVector(const std::vector<int>& v)
{
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

inline std::vector<int> getVector()
{
    using std::cin;
    int n;
    cin >> n;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }
    return result;
}

#endif
