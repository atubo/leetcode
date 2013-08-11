#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > tab;
        for (int i = 0; i < m; i++) {
            tab.push_back(vector<int>(n, 0));
        }
        for (int i = 0; i < n; i++) {
            tab[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            tab[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                tab[i][j] = tab[i-1][j] + tab[i][j-1];
            }
        }
        return tab[m-1][n-1];
    }
};

#if 0
int main()
{
    int m, n;
    cin >> m >> n;
    Solution s;
    cout << s.uniquePaths(m, n) << endl;

    return 0;
}
#endif

