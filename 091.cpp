#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int dp[n+1];
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        for (int i = n - 2; i >= 0; i--) {
            switch (s[i]) {
                case '0':
                    dp[i] = 0;
                    break;
                case '1':
                    dp[i] = dp[i+1] + dp[i+2];
                    break;
                case '2':
                    if (s[i+1] <= '6') {
                        dp[i] = dp[i+1] + dp[i+2];
                    }
                    else {
                        dp[i] = dp[i+1];
                    }
                    break;
                default:
                    dp[i] = dp[i+1];
                    break;
            }
        }
        return dp[0];
    }
};

#if 0
int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.numDecodings(str) << endl;

    return 0;
}
#endif

