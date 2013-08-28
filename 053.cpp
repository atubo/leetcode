#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int dp[n];
        dp[0] = A[0];
        int maxVal = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(A[i], A[i] + dp[i-1]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
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
    cout << s.maxSubArray(A, n) << endl;

    return 0;
}
#endif

