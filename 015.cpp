#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Triplet {
    Triplet(int a_, int b_, int c_): a(a_), b(b_), c(c_) {}
    int a;
    int b;
    int c;
    bool operator < (const Triplet& other) const {
        if (a < other.a) return true;
        if (a > other.a) return false;
        if (b < other.b) return true;
        if (b > other.b) return false;
        return (c < other.c);
    }
};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int n = num.size();
        set<Triplet> tripSet;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int a = num[i];
                int b = num[j];
                int c = num[k];
                if (a + b + c > 0) {
                    k--;
                }
                else if (a + b + c < 0) {
                    j++;
                }
                else {
                    tripSet.insert(Triplet(a, b, c));
                    k--;
                }
            }
        }
        for (set<Triplet>::const_iterator it = tripSet.begin();
             it != tripSet.end(); it++) {
            vector<int> v(3, 0);
            v[0] = it->a;
            v[1] = it->b;
            v[2] = it->c;
            result.push_back(v);
        }

        return result;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    Solution s;
    vector<vector<int> > result = s.threeSum(num);
    for (int i = 0; i < (int)result.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif

