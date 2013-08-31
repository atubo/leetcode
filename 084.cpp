#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
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
    vector<int> height = getVector();
    Solution s;
    cout << s.largestRectangleArea(height) << endl;

    return 0;
}
#endif


