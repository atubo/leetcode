#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

vector<string> getNeighbors(const string& str,
                            const unordered_set<string>& dict)
{
    vector<string> result;
    for (int pos = 0; pos < (int)str.length(); pos++) {
        string s = str;
        for (char c = 'a'; c <= 'z'; c++) {
            if (c == str[pos]) continue;
            s[pos] = c;
            if (dict.count(s) == 1) {
                result.push_back(s);
            }
        }
    }
    return result;
}


class Solution {
public:
    vector<vector<string> > findLadders(string start, string end,
                                        unordered_set<string>& dict) {
        dict.insert(end);

        // Do BFS
        unordered_set<string> visited;
        unordered_map<string, int> dist;
        unordered_map<string, vector<string> > pred;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        dist[start] = 1;
        while (!q.empty()) {
            string v = q.front();
            q.pop();
            vector<string> neighbors = getNeighbors(v, dict);
            for (int i = 0; i < (int)neighbors.size(); i++) {
                string u = neighbors[i];
                if (visited.count(u) == 0) {
                    q.push(u);
                    visited.insert(u);
                    dist[u] = dist[v] + 1;
                    pred[u].push_back(v);
                }
                else if (dist[u] == dist[v] + 1) {
                    pred[u].push_back(v);
                }
            }
        }
        if (visited.count(end) == 1) {
            return getPath(pred, end);
        }
        else {
            return vector<vector<string> >();
        }
    }
private:
    vector<vector<string> > getPath(
        const unordered_map<string, vector<string> >& pred,
        const string& str
        ) {
        if (pred.count(str) == 0) {
            // This is start
            vector<vector<string> > pathStart;
            pathStart.push_back(vector<string>(1, str));
            return pathStart;
        }
        vector<vector<string> > result;
        unordered_map<string, vector<string> >::const_iterator it =
            pred.find(str);
        assert(it != pred.end());
        const vector<string>& predecessors = it->second;
        for (int i = 0; i < (int)predecessors.size(); i++) {
            vector<vector<string> > prefix = getPath(pred,
                                                     predecessors[i]);
            for (int j = 0; j < (int)prefix.size(); j++) {
                vector<string> path = prefix[j];
                path.push_back(str);
                result.push_back(path);
            }
        }
        return result;
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
    vector<vector<string> > result = s.findLadders(start, end, dict);
    for (int i = 0; i < (int)result.size(); i++) {
        for (int j = 0; j < (int)result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#endif

