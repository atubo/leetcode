#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] =  i + 1;
        }
        int fact[11] = {1, 1, 2, 6, 24, 120,
                        720, 5040, 40320, 362880, 3628800};
        getSeq(k - 1, n, digits, fact, result);
        return result;
    }
private:
    void getSeq(int k, int n, vector<int>& digits, int fact[], string& result) {
        if (n == 0) return;
        int d = k / fact[n-1];
        result += (digits[d] + '0');
        digits.erase(digits.begin() + d);
        getSeq(k % fact[n-1], n - 1, digits, fact, result);
    }
};

#if 0
int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.getPermutation(n, k) << endl;

    return 0;
}
#endif

