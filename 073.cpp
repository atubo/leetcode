#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix){
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int rowMarker = -1;
        int colMarker = -1;
        int m = matrix.size();
        int n = matrix[0].size();
        bool found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rowMarker = i;
                    colMarker = j;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) return;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][colMarker] = 0;
                    matrix[rowMarker][j] = 0;
                }
            }
        }
        for (int i = rowMarker + 1; i < m; i++) {
            if (matrix[i][colMarker] == 0) {
                setZeroRow(matrix, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == colMarker) continue;
            if (matrix[rowMarker][i] == 0) {
                setZeroCol(matrix, i);
            }
        }
        setZeroRow(matrix, rowMarker);
        setZeroCol(matrix, colMarker);
    }
private:
    void setZeroRow(vector<vector<int> >& matrix, int row) {
        for (int i = 0; i < (int)matrix[0].size(); i++) {
            matrix[row][i] = 0;
        }
    }
    void setZeroCol(vector<vector<int> >& matrix, int col) {
        for (int i = 0; i < (int)matrix.size(); i++) {
            matrix[i][col] = 0;
        }
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<vector<int> > matrix = getMatrix();
    Solution s;
    s.setZeroes(matrix);
    printMatrix(matrix);

    return 0;
}
#endif

