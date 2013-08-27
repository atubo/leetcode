#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        map<string, vector<int> > dict;
        for (int i = 0; i < (int)strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (dict.count(key) == 0) {
                dict[key] = vector<int>();
            }
            dict[key].push_back(i);
        }
        for (map<string, vector<int> >::const_iterator it = dict.begin();
             it != dict.end(); it++) {
            vector<int> words = it->second;
            if (words.size() > 1) {
                for (int i = 0; i < (int)words.size(); i++) {
                    result.push_back(strs[words[i]]);
                }
            }
        }
        return result;
    }
};

#if 0
int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    Solution s;
    vector<string> result = s.anagrams(strs);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
#endif

        
