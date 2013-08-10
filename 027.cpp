#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = n - 1;
        int i = 0;
        while (i <= j) {
            if (A[i] == elem) swap(A[i], A[j--]);
            else i++;
        }
        return j + 1;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int elem;
    cin >> elem;
    Solution s;
    int m = s.removeElement(A, n, elem);
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif

