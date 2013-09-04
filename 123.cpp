#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        int maxVal = 0;
        int maxdp1 = 0;
        for (int i = 1; i < n; i++) {
            int delta = prices[i] - prices[i-1];
            dp1[i] = max(dp1[i-1] + delta, 0);
            maxdp1 = max(maxdp1, dp1[i]);
            dp2[i] = max(max(dp2[i-1] + delta, 0), maxdp1);
            maxVal = max(maxVal, dp2[i]);
        }
        return maxVal;
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

