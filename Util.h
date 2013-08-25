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
    using std::vector;
    int n;
    cin >> n;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        cin >> result[i];
    }
    return result;
}

inline std::vector<std::vector<int> > getMatrix()
{
    using std::cin;
    using std::vector;

    int m;
    int n;
    cin >> m >> n;
    vector<vector<int> > matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

inline void printMatrix(const std::vector<std::vector<int> > &matrix)
{
    using std::cout;
    using std::endl;

    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

#endif
