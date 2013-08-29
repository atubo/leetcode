#include <vector>
#include <utility>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        result.clear();
        doPermute(num, 0);
        return result;
    }
private:
    void doPermute(vector<int>& num, int pos) {
        int n = num.size();
        bool found = false;
        for (int i = pos; i < n; i++) {
            if (num[i] != num[pos]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(num);
            return;
        }
        set<int> swapped;
        for (int i = pos; i < n; i++) {
            if (swapped.count(num[i]) == 0) {
                swapped.insert(num[i]);
                swap(num[i], num[pos]);
                doPermute(num, pos + 1);
                swap(num[i], num[pos]);
            }
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
    vector<vector<int> > result = s.permuteUnique(num);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

