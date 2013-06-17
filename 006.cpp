#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int m) {
        vector<vector<char> > a(m);
        int len = s.length();
        if (m == 1) {
            return s;
        }
        int T = 2 * (m-1);
        for (int i = 0; i <= len/T; i++) {
            if (i*T < len) {
                a[0].push_back(s[i*T]);
            }
        }
        for (int k = 1; k < m-1; k++) {
            for (int i = 0; i <= len/T; i++) {
                if (i*T + k < len) {
                    a[k].push_back(s[i*T+k]);
                }
                if ((i+1)*T - k < len) {
                    a[k].push_back(s[(i+1)*T-k]);
                }
            }
        }
        for (int i = 0; i <= len/T; i++) {
            if (i*T+m-1 < len) {
                a[m-1].push_back(s[i*T+m-1]);
            }
        }

        string result;
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < (int)a[k].size(); j++) {
                result.append(1, a[k][j]);
            }
        }

        return result;
    }
};

#if 0
int main() {
    Solution s;
    cout << s.convert("", 1) << endl;
    //cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
#endif

