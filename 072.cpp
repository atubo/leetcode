#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m == 0) return n;
        if (n == 0) return m;
        int dp[m][n];
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (word1[0] == word2[j]) found = true;
            dp[0][j] = (found ? j : j+1);
        }
        found = false;
        for (int i = 0; i < m; i++) {
            if (word2[0] == word1[i]) found = true;
            dp[i][0] = (found ? i : i+1);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int replace = (word1[i] == word2[j] ? 0 : 1);
                dp[i][j] = min3(replace + dp[i-1][j-1],
                                1 + dp[i][j-1],
                                1 + dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
    }
private:
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
};

#if 0
int main()
{
    string word1;
    string word2;
    cin >> word1 >> word2;
    Solution s;
    cout << s.minDistance(word1, word2) << endl;

    return 0;
}
#endif

