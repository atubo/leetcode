#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        string curr;
        for (int i = 2; i <= n; i++) {
            curr.clear();
            char c = prev[0];
            int len = 1;
            for (int j = 1; j < (int)prev.length(); j++) {
                if (prev[j] != prev[j-1]) {
                    curr.push_back(len + '0');
                    curr.push_back(c);
                    c = prev[j];
                    len = 1;
                }
                else {
                    len++;
                }
            }
            curr.push_back(len + '0');
            curr.push_back(c);
            curr.swap(prev);
        }
        return prev;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    Solution s;
    cout << s.countAndSay(n) << endl;

    return 0;
}
#endif




