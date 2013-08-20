#include <string>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

struct PosInfo {
    char c;
    int pos;

    PosInfo(char c_, int pos_): c(c_), pos(pos_) {}
};

class Solution {
public:
    string minWindow(string S, string T) {
        unordered_set<char> tSet;
        unordered_set<char> unseen;
        unordered_map<char, int> lastPos;
        for (int i = 0; i < (int)T.length(); i++) {
            tSet.insert(T[i]);
            unseen.insert(T[i]);
        }

        deque<PosInfo> dq;
        int n  = S.length();
        int pos = 0;
        for (; pos < n; pos++) {
            if (tSet.count(S[pos]) == 1) {
                dq.push_back(PosInfo(S[pos], pos));
                unseen.erase(S[pos]);
                lastPos[S[pos]] = pos;
                if (unseen.empty()) break;
            }
        }
        if (pos == n) return string();

        int currLen = pos - dq.front().pos + 1;
        int currPos = pos;
        for (int i = pos + 1; i < n; i++) {
            if (tSet.count(S[i]) == 1) {
                dq.push_back(PosInfo(S[i], i));
                lastPos[S[i]] = i;
                while (dq.front().pos != lastPos[dq.front().c]) {
                    dq.pop_front();
                }
                int length = i - dq.front().pos + 1;
                if (length < currLen) {
                    currLen = length;
                    currPos = i;
                }
            }
        }
        return S.substr(currPos - currLen + 1, currLen);
    }
};

#if 0
int main()
{
    string sStr;
    string tStr;
    cin >> sStr;
    cin >> tStr;
    
    Solution s;
    cout << s.minWindow(sStr, tStr) << endl;

    return 0;
}
#endif

