#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string str) {
        const char* s = str.c_str();
        int sz = str.length();
        vector<string> result = parse(s, sz, 4);
        return result;
    }
private:
    vector<string> parse(const char* s, int sz, int k) {
        vector<string> result;
        if (sz == 0) return result;
        if (k == 1) {
            if (sz > 3) return result;
            if (s[0] == '0' && sz > 1) return result;
            int quad = readInt(s, sz);
            if (quad > 255) {
                return result;
            }
            else {
                result.push_back(string(s, sz));
                return result;
            }
        }
        int maxIter = min(3, sz);
        if (s[0] == '0') maxIter = 1;
        for (int i = 1; i <= maxIter; i++) {
            int quad = readInt(s, i);
            if (quad > 255) break;
            vector<string> suffix = parse(s+i, sz-i, k-1);
            if (suffix.empty()) continue;
            for (int j = 0; j < (int)suffix.size(); j++) {
                string candidate = string(s, i) + string(".") + suffix[j];
                result.push_back(candidate);
            }
        }
        return result;
    }

    int readInt(const char* s, int sz) {
        int x = 0;
        for (int i = 0; i < sz; i++) {
            x = x * 10 + (s[i] - '0');
        }
        return x;
    }
};

#if 0
int main()
{
    string str;
    cin >> str;
    Solution s;
    vector<string> result = s.restoreIpAddresses(str);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
#endif


