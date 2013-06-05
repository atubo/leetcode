#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int last = 0, longest = 0;
        map<char, int> m;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (m.count(c) > 0) {
                int newpos = m[c] + 1;
                for (int j = last; j <= m[c]; j++) {
                    m.erase(s[j]);
                }
                last = newpos;
            }
            else {
                longest = max(longest, i - last + 1);
            }
            m[c] = i;
        }
        return longest;
    }
};
