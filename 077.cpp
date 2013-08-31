#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        result.clear();
        vector<int> a;
        combineRecur(n, k, a);
        return result;
    }
private:
    vector<vector<int> > result;
    void combineRecur(int n, int k, vector<int>& a) {
        if ((int)a.size() == k) {
            result.push_back(a);
            return;
        }
        int start = (a.empty() ? 1 : a.back() + 1);
        for (int i = start; i <= n; i++) {
            a.push_back(i);
            combineRecur(n, k, a);
            a.pop_back();
        }
    }
};

#if 0
#include "Util.h"
int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    vector<vector<int> > result = s.combine(n, k);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

