#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

#define INFINITY 0x7fffffff

class DArray
{
public:
    DArray(int* a_, int n_, int db_):a(a_), n(n_), db(db_) {}
    int operator [] (int pos) const {
        if (pos <= db-1) {
            return -INFINITY;
        }
        if (pos >= db+n) {
            return INFINITY;
        }
        return a[pos-db];
    }
private:
    const int* a;
    const int n;
    const int db; // added band
};

// case 1: total number of elements is odd
int findMedianCase1(const DArray& a, int i, int j,
                    const DArray& b, int p, int q)
{
    int m = j-i+1;
    int n = q-p+1;
    assert(m == n+1 || m == n-1);
    if (m % 2 == 0) {
        return findMedianCase1(b, p, q, a, i, j);
    }
    if (n == 0) {
        return a[i];
    }

    int m_a = i + (j-i)/2;
    int x = a[m_a];
    int m_b1 = p + (q-p)/2;
    int m_b2 = m_b1 + 1;
    int y1 = b[m_b1];
    int y2 = b[m_b2];
    if (y1 <= x && x <= y2) {
        return x;
    }
    if (x > y2) {
        if (m > n) {
            return findMedianCase1(a, i, m_a, b, m_b2, q);
        }
        else {
            return findMedianCase1(a, i, m_a-1, b, m_b2, q);
        }
    }
    else {
        if (m > n) {
            return findMedianCase1(a, m_a, j, b, p, m_b1);
        }
        else {
            return findMedianCase1(a, m_a+1, j, b, p, m_b1);
        }
    }
}

// case 2: total number of elements is even
pair<int, int> findMedianCase2(const DArray& a, int i, int j,
                               const DArray& b, int p, int q)
{
    int m = j-i+1;
    int n = q-p+1;
    assert(m == n);
    if (m == 2) {
        vector<int> tmp(4, 0);
        tmp[0] = a[i];
        tmp[1] = a[i+1];
        tmp[2] = b[p];
        tmp[3] = b[p+1];
        sort(tmp.begin(), tmp.end());
        return make_pair(tmp[1], tmp[2]);
    }

    if (m % 2 == 0) {
        int m_a1 = i + (j-i)/2;
        int m_a2 = m_a1 + 1;
        int m_b1 = p + (q-p)/2;
        int m_b2 = m_b1 + 1;
        int x1 = a[m_a1];
        int x2 = a[m_a2];
        int y1 = b[m_b1];
        int y2 = b[m_b2];
        if (y1 <= x1 && x1 <= y2) {
            return make_pair(x1, min(y2, x2));
        }
        if (x1 > y2) {
            return findMedianCase2(a, i, m_a1, b, m_b2, q);
        }
        else {
            return findMedianCase2(a, m_a1, j, b, p, m_b2);
        }
    }
    else {
        int m_a = i + (j-i)/2;
        int m_a1 = m_a - 1;
        int m_a2 = m_a + 1;
        int m_b = p + (q-p)/2;
        int m_b1 = m_b - 1;
        int m_b2 = m_b + 1;
        int x = a[m_a];
        int x1 = a[m_a1];
        int x2 = a[m_a2];
        int y = b[m_b];
        int y1 = b[m_b1];
        int y2 = b[m_b2];
        if (y1 <= x && x <= y) {
            return make_pair(x, min(x2, y));
        }
        if (y <= x && x <= y2) {
            return make_pair(max(x1, y), x);
        }
        if (x > y2) {
            return findMedianCase2(a, i, m_a, b, m_b, q);
        }
        else {
            return findMedianCase2(a, m_a, j, b, p, m_b);
        }
    }
}

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 0) {
            pair<int, int> rt;
            if (m > n) {
                DArray a(A, m, 0);
                DArray b(B, n, (m-n)/2);
                rt = findMedianCase2(a, 0, m-1, b, 0, m-1);
            }
            else {
                DArray a(A, m, (n-m)/2);
                DArray b(B, n, 0);
                rt = findMedianCase2(a, 0, n-1, b, 0, n-1);
            }
            return (rt.first + rt.second)/2.0;
        }
        else {
            if (m > n) {
                DArray a(A, m, 0);
                DArray b(B, n, (m-n)/2);
                return findMedianCase1(a, 0, m-1, b, 0, m-2);
            }
            else {
                DArray a(A, m, (n-m)/2);
                DArray b(B, n, 0);
                return findMedianCase1(a, 0, n-2, b, 0, n-1);
            }
        }
    }
};

#if 0
int main()
{
    int m, n;
    cin >> m >> n;
    int A[m], B[n];
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    Solution s;
    cout << s.findMedianSortedArrays(A, m, B, n) << endl;

    return 0;
}
#endif
