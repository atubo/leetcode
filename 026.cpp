#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (A[i] != A[j]) {
                swap(A[(i++)+1], A[j]);
            }
        }
        
        return i + 1;
    }
};

