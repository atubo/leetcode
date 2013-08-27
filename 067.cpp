#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length();
        int n2 = b.length();
        if (n1 == 0) return b;
        if (n2 == 0) return a;
        string result;
        int carry = 0;
        for (int i = 0; i < max(n1, n2); i++) {
            int d1;
            int d2;
            if (i >= n1) {
                d1 = 0;
                d2 = b[n2-1-i] - '0';
            }
            else if (i >= n2) {
                d1 = a[n1-1-i] - '0';
                d2 = 0;
            }
            else {
                d1 = a[n1-1-i] - '0';
                d2 = b[n2-1-i] - '0';
            }
            int d = (d1 + d2 + carry) & 0x1;
            carry = ((d1 + d2 + carry) >= 2);
            result.push_back(d + '0');
        }
        if (carry) result.push_back('1');
        reverse(result.begin(), result.end());
        int firstNon0 = 0;
        while (result[firstNon0] == '0') {
            firstNon0++;
        }
        if (firstNon0 == (int)result.length()) {
            result = "0";
        }
        else {
            result.erase(result.begin(), result.begin()+firstNon0);
        }
        return result;
    }
};

#if 0
int main()
{
    string a;
    string b;
    cin >> a >> b;
    Solution s;
    cout << s.addBinary(a, b) << endl;
 
    return 0;
}
#endif

