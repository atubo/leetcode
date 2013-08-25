#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int maxVal = A[0];
        int maxPos = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] > maxVal) {
                maxVal = A[i];
                maxPos = i;
            }
        }
        int pivot = 0;
        for (int i = maxPos; i < maxPos + n; i++) {
            if (A[i % n] < maxVal) {
                pivot = i % n;
                break;
            }
        }
        int i = pivot;
        int j = (pivot - 1 + n) % n;
        if (A[i] > target || A[j] < target) return false;
        if (A[j] == target) return true;
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
        return (A[i] == target);
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

