#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        return generateSubsets(S, 0);
    }
private:
    vector<vector<int> > generateSubsets(const vector<int>& S, int start) {
        int n = S.size();
        vector<vector<int> > result;
        if (start == n) {
            result.push_back(vector<int>());
            return result;
        }

        int nextStart = start + 1;
        for (; nextStart < n; nextStart++) {
            if (S[nextStart] != S[start]) break;
        }
        vector<vector<int> > suffix = generateSubsets(S, nextStart);
        for (int i = 0; i <= nextStart - start; i++) {
            for (int j = 0; j < (int)suffix.size(); j++) {
                vector<int> vec(i, S[start]);
                copy(suffix[j].begin(), suffix[j].end(), back_inserter(vec));
                result.push_back(vec);
            }
        }
        return result;
    }
};

#if 0
#include "Util.h"
int main()
{
    vector<int> v = getVector();
    Solution s;
    vector<vector<int> > result = s.subsetsWithDup(v);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

