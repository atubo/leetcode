#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        return fib(n+1);
    }
private:
    int fib(int n) {
        if (n == 1) return 1;
        int f1 = 0;
        int f2 = 1;
        for (int i = 2; i < n; i++) {
            int ftmp = f2;
            f2 = f1 + f2;
            f1 = ftmp;
        }
        return f1 + f2;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;

    return 0;
}
#endif

