#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<string> getNeighbors(const string& str, unordered_set<string>& dict)
{
    vector<string> result;
    for (int pos = 0; pos < (int)str.length(); pos++) {
        string s = str;
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == str[pos]) continue;
            s[pos] = c;
            if (dict.count(s) == 1) {
                result.push_back(s);
                dict.erase(s);
            }
        }
    }
    return result;
}


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
        typedef pair<string, int> StrIntPair;
        dict.insert(end);

        // Do BFS
        queue<StrIntPair> q;
        q.push(make_pair(start, 1));
        while (!q.empty()) {
            StrIntPair pair = q.front();
            string s   = pair.first;
            int length = pair.second; 
            q.pop();
            vector<string> neighbors = getNeighbors(s, dict);
            for (int i = 0; i < (int)neighbors.size(); i++) {
                string u = neighbors[i];
                if (u.compare(end) == 0) return length + 1;
                q.push(make_pair(u, length + 1));
            }
        }
        return 0;
    }
};


#if 0
int main()
{
    string start;
    string end;
    cin >> start >> end;
    int n;
    cin >> n;
    unordered_set<string> dict;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict.insert(s);
    }
    Solution s;
    cout << s.ladderLength(start, end, dict) << endl;

    return 0;
}
#endif

