#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot;
        if (A[0] < A[n-1]) pivot = 0;
        else if (A[n-2] > A[n-1]) pivot = n - 1;
        else {
            int i = 0;
            int j = n - 2;
            while (j > i + 1) {
                int mid = (i + j) / 2;
                if (A[mid] > A[n-1]) {
                    i = mid;
                }
                else {
                    j = mid;
                }
            }
            pivot = j;
        }
        int i = pivot;
        int j = (pivot - 1 + n) % n;
        if (A[i] > target || A[j] < target) return -1;
        if (A[j] == target) return j;
        while (dist2p(j, pivot, n) > dist2p(i, pivot, n) + 1) {
            int mid = ((dist2p(i, pivot, n) + dist2p(j, pivot, n)) / 2 + pivot)
                       % n;
            if (A[mid] <= target) {
                i = mid;
            }
            else {
                j = mid;
            }
        }
        if (A[i] == target) return i;
        else                return -1;
    }
private:
    int dist2p(int i, int pivot, int n) {
        return (i - pivot + n) % n;
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
    int target;
    cin >> target;
    Solution s;
    cout << s.search(A, n, target) << endl;

    return 0;
}
#endif

