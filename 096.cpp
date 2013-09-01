#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        tArray.clear();
        tArray.resize(n+1, 0);
        build(n);
        return tArray[n];
    }
private:
    vector<int> tArray;
    void build(int n) {
        tArray[0] = 1;
        for (int index = 1; index <= n; index++) {
            for (int k = 0; k < index; k++) {
                tArray[index] += tArray[k] * tArray[index-1-k];
            }
        }
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.numTrees(n) << endl;

    return 0;
}
#endif

