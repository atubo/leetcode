#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> posStack;
        vector<int> len(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') posStack.push(i);
            if (s[i] == ')') {
                if (!posStack.empty()) {
                    int pos = posStack.top();
                    posStack.pop();
                    len[i] = i - pos + 1;
                    if (pos > 0) {
                        len[i] += len[pos-1];
                    }
                    maxLen = max(maxLen, len[i]);
                }
            }
        }
        return maxLen;
    }
};

#if 0
int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.longestValidParentheses(str) << endl;

    return 0;
}
#endif

