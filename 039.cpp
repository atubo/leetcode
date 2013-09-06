#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        result.clear();
        int n = candidates.size();
        if (n == 0) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        checkSum(candidates, 0, n, target, current);
        return result;
    }
private:
    vector<vector<int> > result;
    void checkSum(const vector<int>& candidates,
                  int start, int end, int target, vector<int>& current) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (start == end) return;
        int currSize = current.size();
        int a = candidates[start];
        for (int i = 0; i <= target/a; i++) {
            checkSum(candidates, start+1, end, target-a*i, current);
            current.push_back(a);
        }
        current.erase(current.begin() + currSize, current.end());
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<int> candidates = getVector();
    int target;
    cin >> target;
    Solution s;
    vector<vector<int> > result = s.combinationSum(candidates, target);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif



