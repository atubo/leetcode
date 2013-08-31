#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j] = 1 + height[j];
                }
                else {
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        vector<int> h = height;
        h.push_back(0);
        stack<int> barStack;
        barStack.push(0);
        int maxArea = 0;
        for (int i = 1; i < (int)h.size(); i++) {
            if (h[i] < h[i-1]) {
                while (!barStack.empty() && h[barStack.top()] > h[i]) {
                    int pos = barStack.top();
                    barStack.pop();
                    int left = (barStack.empty() ? -1 : barStack.top());
                    int area = h[pos] * (i - left - 1);
                    maxArea = max(area, maxArea);
                }
            }
            barStack.push(i);
        }
        return maxArea;
    }
};

#if 0
#include "Util.h"
int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<char> > matrix(m, vector<char>(n, '0'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution s;
    cout << s.maximalRectangle(matrix) << endl;

    return 0;
}
#endif

