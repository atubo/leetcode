#include <deque>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0) return 0;
        deque<pair<int, int> > dq;
        dq.push_front(make_pair(0, n-1));
        for (int i = n - 2; i >= 0; i--) {
            while (dq.size() > 1 && dq[1].second <= i + A[i]) {
                dq.pop_front();
            }
            pair<int, int> next = dq.front();
            dq.push_front(make_pair(next.first + 1, i));
        }
        return dq.front().first;
    }
};

#if 0
#include "Util.h"
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Solution s;
    cout << s.jump(A, n) << endl;

    return 0;
}
#endif

