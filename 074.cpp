#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        if (matrix[0][0] > target) return false;
        if (matrix[m-1][0] <= target) return searchRow(matrix[m-1], target);

        int i = 0;
        int j = m - 1;
        while (j > i + 1) {
            int mid = (j + i) / 2;
            if (matrix[mid][0] <= target) i = mid;
            else j = mid;
        }
        return searchRow(matrix[i], target);
    }
private:
    bool searchRow(vector<int>& a, int target) {
        int n = a.size();
        if (a[n-1] == target) return true;
        if (a[n-1] < target) return false;
        int i = 0;
        int j = n - 1;
        while (j > i + 1) {
            int mid = (j + i) / 2;
            if (a[mid] <= target) i = mid;
            else j = mid;
        }
        return a[i] == target;
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<vector<int> > matrix = getMatrix();
    int target;
    cin >> target;
    Solution s;
    cout << s.searchMatrix(matrix, target) << endl;

    return 0;
}
#endif

