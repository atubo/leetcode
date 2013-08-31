#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

struct Bar {
    int x;
    int y;
    Bar(int x_, int y_): x(x_), y(y_) {}
};

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;
        stack<Bar> barStack;
        barStack.push(Bar(0, height[0]));
        int maxArea = 0;
        for (int i = 1; i < n; i++) {
            if (height[i] < height[i-1]) {
                while (!barStack.empty() && barStack.top().y > height[i]) {
                    Bar bar = barStack.top();
                    barStack.pop();
                    int left = (barStack.empty() ? -1 : barStack.top().x);
                    int area = bar.y * (i - left - 1);
                    maxArea = max(area, maxArea);
                }
                barStack.push(Bar(i, height[i]));
            }
            if (height[i] >= height[i-1]) {
                barStack.push(Bar(i, height[i]));
            }
        }
        while (!barStack.empty()) {
            Bar bar = barStack.top();
            barStack.pop();
            int left = (barStack.empty() ? -1 : barStack.top().x);
            int area = bar.y * (n - left - 1);
            maxArea = max(maxArea, area);
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


