#include <vector>
#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& num) {
        result.clear();
        doPermute(num, 0);
        return result;
    }
private:
    void doPermute(vector<int>& num, int pos) {
        int n = num.size();
        if (pos == n - 1) {
            result.push_back(num);
            return;
        }
        for (int i = pos; i < n; i++) {
            swap(num[i], num[pos]);
            doPermute(num, pos + 1);
            swap(num[i], num[pos]);
        }
    }

    vector<vector<int> > result;
};

#if 0
#include "Util.h"
int main()
{
    vector<int> num = getVector();
    Solution s;
    vector<vector<int> > result = s.permute(num);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

