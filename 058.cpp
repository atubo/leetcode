#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int lastNonSpace = n - 1;
        while (lastNonSpace >= 0 && s[lastNonSpace] == ' ') {
            lastNonSpace--;
        }
        if (lastNonSpace < 0) return 0;
        int posBefore = lastNonSpace;
        while (posBefore >= 0 && s[posBefore] != ' ') {
            posBefore--;
        }
        return lastNonSpace - posBefore;
    }
};

#if 0
int main()
{
    char str[256];
    cin.getline(str, 256);
    Solution s;
    cout << s.lengthOfLastWord(str) << endl;

    return 0;
}
#endif

