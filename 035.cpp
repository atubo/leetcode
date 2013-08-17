#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) return 0;
        if (A[0] >= target) return 0;
        if (A[n-1] < target) return n;
        int i = 0; 
        int j = n - 1;
        while (j > i + 1) {
            int mid = (i + j) / 2;
            if (A[mid] < target) {
                i = mid;
            }
            else {
                j = mid;
            }
        }
        return j;
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
    int target;
    cin >> target;
    Solution s;
    cout << s.searchInsert(a, n, target) << endl;

    return 0;
}
#endif

