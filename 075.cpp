#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        for (int i = 0; i < n; i++) {
            if (A[i] == 1) exch(A, 0, i);
            break;
        }
        int lt = 0;
        int gt = n - 1;
        int i = 0;
        while (i <= gt) {
            if (A[i] < 1) exch(A, i++, lt++);
            else if (A[i] > 1) exch(A, i, gt--);
            else i++;
        }
    }
private:
    void exch(int A[], int i, int j) {
        swap(A[i], A[j]);
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
    s.sortColors(A, n);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
#endif

