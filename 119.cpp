#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) return vector<int>();
        vector<int> rowPrev(rowIndex+1, 0);
        vector<int> rowCurr(rowIndex+1, 0);
        rowPrev[0] = 1;
        for (int row = 1; row <= rowIndex; row++) {
            rowCurr[0] = rowPrev[0];
            rowCurr[row] = rowPrev[row-1];
            for (int col = 1; col < row; col++) {
                rowCurr[col] = rowPrev[col-1] + rowPrev[col];
            }
            rowCurr.swap(rowPrev);
        }
        return rowPrev;
    }
};

#if 0
#include "Util.h"
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<int> row = s.getRow(n);
    printVector(row);

    return 0;
}
#endif

