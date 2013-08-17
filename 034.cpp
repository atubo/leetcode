#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (n == 0) return result;
        int lo = searchLastLess(A, n, target);
        int hi = searchFirstMore(A, n, target);
        if (hi - lo > 1) {
            result[0] = lo + 1;
            result[1] = hi - 1;
        }
        return result;
    }
private:
    int searchLastLess(int A[], int n, int target) {
        if (A[0] >= target) return -1;
        if (A[n-1] < target) return  n-1;
        int i = 0;
        int j = n - 1;
        while (j - i > 1) {
            int mid = (i + j) / 2;
            if (A[mid] >= target) j = mid;
            else                  i = mid;
        }
        return i;
    }
    int searchFirstMore(int A[], int n, int target) {
        if (A[0] > target) return 0;
        if (A[n-1] <= target) return n;
        int i = 0;
        int j = n - 1;
        while (j - i > 1) {
            int mid = (i + j) / 2;
            if (A[mid] <= target) i = mid;
            else                  j = mid;
        }
        return j;
    }
};

#if 0
#include "Util.h"
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
    vector<int> result = s.searchRange(a, n, target);
    printVector(result);

    return 0;
}
#endif

