#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Quadruple {
    Quadruple(int a_, int b_, int c_, int d_): a(a_), b(b_), c(c_), d(d_) {}
    int a;
    int b;
    int c;
    int d;
    bool operator < (const Quadruple& other) const {
        if (a < other.a) return true;
        if (a > other.a) return false;
        if (b < other.b) return true;
        if (b > other.b) return false;
        if (c < other.c) return true;
        if (c > other.c) return false;
        return (d < other.d);
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int n = num.size();
        set<Quadruple> quadSet;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k1 = j + 1;
                int k2 = n - 1;
                while (k1 < k2) {
                    int a = num[i];
                    int b = num[j];
                    int c = num[k1];
                    int d = num[k2];
                    int s = a + b + c + d;
                    if (s > target) {
                        k2--;
                    }
                    else if (s < target) {
                        k1++;
                    }
                    else {
                        quadSet.insert(Quadruple(a, b, c, d));
                        k2--;
                        k1++;
                    }
                }
            }
        }
        for (set<Quadruple>::const_iterator it = quadSet.begin();
             it != quadSet.end(); it++) {
            vector<int> v(4, 0);
            v[0] = it->a;
            v[1] = it->b;
            v[2] = it->c;
            v[3] = it->d;
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
    int target;
    cin >> target;
    Solution s;
    vector<vector<int> > result = s.fourSum(num, target);
    for (int i = 0; i < (int)result.size(); i++) {
        for (int j = 0; j < (int)result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#endif

