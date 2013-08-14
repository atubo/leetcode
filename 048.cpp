#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                rotateOnePixel(matrix, i, j);
            }
        }
        if (n % 2 == 1) {
            for (int i = 0; i < n/2; i++) {
                rotateOnePixel(matrix, i, n/2);
            }
        }
    }
private:
    void rotateOnePixel(vector<vector<int> >& matrix, int i, int j) {
        int n = matrix.size();
        int& a = matrix[i][j];
        int& b = matrix[j][n-1-i];
        int& c = matrix[n-1-i][n-1-j];
        int& d = matrix[n-1-j][i];
        rotate4(a, b, c, d);
    }
    void rotate4(int& a, int& b, int& c, int& d) {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix;
    for (int i = 0; i < n; i++) {
        matrix.push_back(vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution s;
    s.rotate(matrix);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif


