#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        if ((int)s3.length() != m + n) return false;
        if (m == 0) return (s2.compare(s3) == 0);
        if (n == 0) return (s1.compare(s3) == 0);
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        for (int k = 1; k <= m; k++) {
            if (s1[k-1] == s3[k-1]) dp[k][0] = true;
            else break;
        }
        for (int k = 1; k <= n; k++) {
            if (s2[k-1] == s3[k-1]) dp[0][k] = true;
            else break;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s3[i+j-1] == s1[i-1]) dp[i][j] = dp[i-1][j];
                if (s3[i+j-1] == s2[j-1]) dp[i][j] = dp[i][j] || dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

#if 0
int main()
{
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3;
    Solution s;
    cout << s.isInterleave(s1, s2, s3) << endl;

    return 0;
}
#endif

