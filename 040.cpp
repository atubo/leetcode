#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        resultSet.clear();
        vector<vector<int> > result;
        int n = candidates.size();
        if (n == 0) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        checkSum(candidates, 0, n, target, current);
        copy(resultSet.begin(), resultSet.end(), back_inserter(result));
        return result;
    }
private:
    set<vector<int> > resultSet;
    void checkSum(const vector<int>& candidates,
                  int start, int end, int target, vector<int>& current) {
        if (target == 0) {
            resultSet.insert(current);
            return;
        }
        if (start == end) return;
        int currSize = current.size();
        int a = candidates[start];
        for (int i = 0; i <= min(1, target/a); i++) {
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
    vector<vector<int> > result = s.combinationSum2(candidates, target);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif



