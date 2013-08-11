#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > tab(m, vector<int>(n, 0));
        bool gridMet = false;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) gridMet = true;
            if (!gridMet) tab[0][i] = 1;
        }
        gridMet = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) gridMet = true;
            if (!gridMet) tab[i][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    tab[i][j] = 0;
                }
                else {
                    tab[i][j] = tab[i-1][j] + tab[i][j-1];
                }
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
    vector<vector<int> > grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution s;
    cout << s.uniquePathsWithObstacles(grid) << endl;

    return 0;
}
#endif

