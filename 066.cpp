#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> & digits) {
        int n = digits.size();
        int firstNot9 = n - 1;
        while (firstNot9 >= 0 && digits[firstNot9] == 9) {
            firstNot9--;
        }
        if (firstNot9 == -1) {
            vector<int> result(n+1, 0);
            result[0] = 1;
            return result;
        }
        else {
            vector<int> result = digits;
            result[firstNot9] = digits[firstNot9] + 1;
            for (int i = firstNot9 + 1; i < n; i++) {
                result[i] = 0;
            }
            return result;
        }
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<int> digits = getVector();
    Solution s;
    vector<int> result = s.plusOne(digits);
    printVector(result);

    return 0;
}
#endif


