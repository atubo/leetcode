#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (A[j] != A[i] || i == 0 || A[j] != A[i-1]) {
                swap(A[(i++)+1], A[j]);
            }
        }
        
        return i + 1;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution s;
    n = s.removeDuplicates(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif

