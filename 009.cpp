class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int mask = 1;
        int xt = x;
        while (xt >= 10) {
            xt /= 10;
            mask *= 10;
        }
        while (mask > 1) {
            if (x / mask != x % 10) {
                return false;
            }
            int d = x % 10;
            x = (x - d - d * mask) / 10;
            mask /= 100;
        }
        return true;
    }
};

#if 0
#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    Solution s;
    cout << s.isPalindrome(x) << endl;
    return 0;
}
#endif
