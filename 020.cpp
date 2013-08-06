#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> pstack;
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                pstack.push(s[i]);
            }
            else {
                if (pstack.empty()) return false;
                char c = pstack.top();
                pstack.pop();
                if (!(s[i] == ')' && c == '(' ||
                      s[i] == ']' && c == '[' ||
                      s[i] == '}' && c == '{')) {
                    return false;
                }
            }
        }
        return pstack.empty();
    }
};

#if 0
#include <iostream>

int main()
{
    string s;
    cin >> s;
    Solution solution;
    cout << solution.isValid(s) << endl;

    return 0;
}
#endif
