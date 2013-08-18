#include <string>
#include <iostream>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (i < n && !isalnum(tolower(s[i]))) {
            i++;
        }
        while (j >= 0 && !isalnum(tolower(s[j]))) {
            j--;
        }
        while (i < j) {
            if (tolower(s[i++]) != tolower(s[j--])) {
                return false;
            }
            while (!isalnum(tolower(s[i]))) {
                i++;
            }
            while (!isalnum(tolower(s[j]))) {
                j--;
            }
        }
        return true;
    }
};

#if 0
int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.isPalindrome(str) << endl;

    return 0;
}
#endif

