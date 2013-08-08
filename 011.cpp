#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

struct Stick {
    Stick(int x_, int h_): x(x_), h(h_) {}
    int x;
    int h;

    bool operator < (const Stick& other) const {
        return h < other.h;
    }
};

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max1 = maxAreaOneSweep(height);
        vector<int> revHeight;
        reverse_copy(height.begin(), height.end(), back_inserter(revHeight));
        int max2 = maxAreaOneSweep(revHeight);
        return max(max1, max2);
    }
private:
    int maxAreaOneSweep(const vector<int>& height) {
        int a = -1;
        vector<Stick> hvec;
        int maxFound = 0;
        for (int i = 0; i < (int)height.size(); i++) {
            if (height[i] > a) {
                hvec.push_back(Stick(i, height[i]));
                a = height[i];
            }
            else {
                vector<Stick>::iterator it = lower_bound(hvec.begin(),
                                                         hvec.end(),
                                                         Stick(i, height[i]));
                assert(it != hvec.end());
                int area = height[i] * (i - it->x);
                maxFound = max(area, maxFound);
            }
        }
        return maxFound;
    }
};

#if 0
int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    Solution s;
    cout << s.maxArea(a);

    return 0;
}
#endif
