#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; i++) {
            for (int j = result.size() - 1; j >= 0; j--) {
                result.push_back(1 << (i-1) | result[j]);
            }
        }
        return result;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<int> result = s.grayCode(n);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif

