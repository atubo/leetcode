#include <utility>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while (A[i] >= 1  && A[i] < n && 
                   A[i] != i+1 && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1) return i+1;
        }
        return n+1;
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
    Solution s;
    cout << s.firstMissingPositive(A, n) << endl;

    return 0;
}
#endif

