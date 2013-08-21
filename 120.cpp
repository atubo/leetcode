#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> dpPrev(n, 0);
        vector<int> dpCurr(n, 0);
        dpPrev[0] = triangle[0][0];
        for (int row = 1; row < n; row++) {
            dpCurr[0] = dpPrev[0] + triangle[row][0];
            dpCurr[row] = dpPrev[row-1] + triangle[row][row];
            for (int col = 1; col < row; col++) {
                dpCurr[col] = min(dpPrev[col-1], dpPrev[col]) + 
                              triangle[row][col];
            }
            dpCurr.swap(dpPrev);
        }
        return *min_element(dpPrev.begin(), dpPrev.end());
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > triangle;
    for (int i = 0; i < n; i++) {
        vector<int> row(i+1, 0);
        for (int j = 0; j < i + 1; j++) {
            cin >> row[j];
        }
        triangle.push_back(row);
    }

    Solution s;
    cout << s.minimumTotal(triangle) << endl;

    return 0;
}
#endif



