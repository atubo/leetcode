#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>();
        parray.clear();
        parray.resize(n+1);
        parray[0] = vector<string>(1, string(""));
        for (int index = 1; index <= n; index++) {
            for (int i = 0; i < index; i++) {
                build(0, 2*i+1, i, index-1-i);
            }
        }
        return parray[n];
    }
private:
    vector<vector<string> > parray;
    void build(int left, int right, int p, int q) {
        for (int i = 0; i < (int)parray[p].size(); i++) {
            for (int j = 0; j < (int)parray[q].size(); j++) {
                string s(2*(p+q+1), '\0');
                s[left] = '(';
                s[right] = ')';
                copy(parray[p][i].begin(), parray[p][i].end(),
                     s.begin() + left + 1);
                copy(parray[q][j].begin(), parray[q][j].end(),
                     s.begin() + right + 1);
                parray[p+q+1].push_back(s);
            }
        }
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
#endif

