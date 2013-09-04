#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] + max(prices[i] - prices[i-1], 0);
        }
        return dp[n-1];
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<int> prices = getVector();
    Solution s;
    cout << s.maxProfit(prices) << endl;

    return 0;
}
#endif

