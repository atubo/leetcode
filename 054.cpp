#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        spiralPrint(matrix, m, n, 0, result);
        return result;
    }
private:
    void spiralPrint(const vector<vector<int> >& matrix, int m, int n, int k,
                     vector<int>& result) {
        if (m == 0 || n == 0) return;
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                result.push_back(matrix[k][k+i]);
            }
            return;
        }
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                result.push_back(matrix[k+i][k]);
            }
            return;
        }
        for (int i = k; i < k + n; i++) {
            result.push_back(matrix[k][i]);
        }
        for (int i = k + 1; i < k + m; i++) {
            result.push_back(matrix[i][k+n-1]);
        }
        for (int i = k + n - 2; i >= k; i--) {
            result.push_back(matrix[k+m-1][i]);
        }
        for (int i = k + m - 2; i >= k + 1; i--) {
            result.push_back(matrix[i][k]);
        }
        spiralPrint(matrix, m-2, n-2, k+1, result);
    }
};

#if 0
int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int> > matrix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif

