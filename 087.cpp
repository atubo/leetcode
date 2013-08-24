#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != (int)s2.length()) return false;
        char dp[n][n][n+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = 0;
                }
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n-l; i++) {
                for (int j = 0; j <= n-l; j++) {
                    for (int k = 1; k < l; k++) {
                        dp[i][j][l] |= dp[i][j][k] & dp[i+k][j+k][l-k]
                                     | dp[i][j+l-k][k] & dp[i+k][j][l-k];
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};

#if 0
int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    Solution s;
    cout << s.isScramble(s1, s2) << endl;

    return 0;
}
#endif

