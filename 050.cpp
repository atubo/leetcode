#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        if (x == -1) return (n % 2 == 0 ? 1 : -1);
        if (n < 0) return 1.0/pow(x, -n);
        double y = pow(x, n/2);
        if (n % 2 == 0) {
            return y * y;
        }
        else {
            return y * y * x;
        }
    }
};

#if 0
int main()
{
    double x;
    int n;
    cin >> x >> n;
    Solution s;
    cout << s.pow(x, n) << endl;

    return 0;
}
#endif


