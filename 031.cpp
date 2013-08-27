#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n == 0) return;

        int i = n - 1;
        while (i > 0 && num[i-1] >= num[i]) {
            i--;
        }
        if (i > 0) {
            int j = n - 1;
            while (num[j] <= num[i-1]) {
                j--;
            }
            swap(num[i-1], num[j]);
        }
        sort(num.begin() + i, num.end());
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<int> num = getVector();
    Solution s;
    s.nextPermutation(num);
    printVector(num);

    return 0;
}
#endif

