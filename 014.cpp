#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;
        if (strs.size() == 0) return result;
        int i = 0;
        bool breakOut = false;
        while (true) {
            if (i >= (int)strs[0].size()) {
                break;
            }
            char c = strs[0][i];
            for (int j = 1; j < (int)strs.size(); j++) {
                if (i >= (int)strs[j].size() || strs[j][i] != c) {
                    breakOut = true;
                    break;
                }
            }
            if (!breakOut) {
                result.push_back(c);
                i++;
            }
            else {
                break;
            }
        }
        return result;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;

    return 0;
}
#endif

