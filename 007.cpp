#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x = x / 10;
        }

        return sign * y;
    }
};

#if 0
int main() {
    Solution s;
    cout << s.reverse(-123) << endl;
    return 0;
}
#endif

