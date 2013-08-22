#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) return result;
        result.push_back(vector<int>(1, 1));
        for (int row = 1; row < numRows; row++) {
            vector<int> currRow = vector<int>(row + 1, 0);
            const vector<int>& lastRow = result.back();
            currRow[0] = lastRow[0];
            currRow[row] = lastRow[row-1];
            for (int col = 1; col < row; col++) {
                currRow[col] = lastRow[col-1] + lastRow[col];
            }
            result.push_back(currRow);
        }
        return result;
    }
};

#if 0
#include "Util.h"
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<vector<int> > pascal = s.generate(n);
    for (int i = 0; i < (int)pascal.size(); i++) {
        printVector(pascal[i]);
    }

    return 0;
}
#endif

