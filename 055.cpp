#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int minFeasible = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + A[i] >= minFeasible) {
                minFeasible = i;
            }
        }
        return minFeasible == 0;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution s;
    cout << s.canJump(a, n) << endl;

    return 0;
}
#endif

