#include <numeric>
#include <stack>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        int psum[n];
        partial_sum(A, A+n, psum);
        int water = 0;
        stack<pair<int, int> > elev;
        elev.push(make_pair(A[0], 0));
        for (int i = 1; i < n; i++) {
            while (elev.size() > 1 && elev.top().first <= A[i]) {
                elev.pop();
            }
            if (elev.top().first <= A[i]) {
                water += getWater(elev.top().first, elev.top().second, i, psum);
                elev.pop();
            }
            elev.push(make_pair(A[i], i));
        }
        while (elev.size() > 1) {
            pair<int, int> p = elev.top();
            elev.pop();
            water += getWater(p.first, elev.top().second, p.second, psum);
        }
        return water;
    }
private:
    int getWater(int h, int pos1, int pos2, int psum[]) {
        int water = h * (pos2 - pos1 - 1);
        water -= psum[pos2-1] - psum[pos1];
        return water;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Solution s;
    cout << s.trap(A, n) << endl;

    return 0;
}
#endif

