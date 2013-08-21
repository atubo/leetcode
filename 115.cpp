#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.length();
        int m = T.length();
        vector<int> dpPrev(n, 0);
        vector<int> dpCurr(n, 0);

        if (n == 0) return 0;
        dpPrev[0] = (S[0] == T[0]);
        for (int i = 1; i < n; i++) {
            dpPrev[i] = dpPrev[i-1];
            if (S[i] == T[0]) dpPrev[i]++;
        }

        for (int i = 1; i < m; i++) {
            dpCurr[0] = 0;
            for (int j = 1; j < n; j++) {
                dpCurr[j] = dpCurr[j-1];
                if (S[j] == T[i]) {
                    dpCurr[j] += dpPrev[j-1];
                }
            }
            dpCurr.swap(dpPrev);
        }
        return dpPrev[n-1];
    }
};

#if 0
int main()
{
    string sStr;
    string tStr;
    cin >> sStr;
    cin >> tStr;

    Solution s;
    cout << s.numDistinct(sStr, tStr) << endl;

    return 0;
}
#endif


