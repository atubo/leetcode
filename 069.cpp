#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1) return x;
        int i = 1;
        int j = x;
        while (j > i + 1) {
            int mid = (i + j) / 2;
            if (mid > x / mid) {
                j = mid;
            }
            else {
                i = mid;
            }
        }
        return i;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.sqrt(n) << endl;

    return 0;
}
#endif


