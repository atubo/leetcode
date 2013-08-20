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
        unordered_set<char> tSetWaiting;
        unordered_map<char, int> numInT;
        unordered_map<char, int> numSeen;
        for (int i = 0; i < (int)T.length(); i++) {
            tSet.insert(T[i]);
            tSetWaiting.insert(T[i]);
            numInT[T[i]]++;
        }

        deque<PosInfo> dq;
        int n  = S.length();
        int pos = 0;
        for (; pos < n; pos++) {
            if (tSet.count(S[pos]) >= 1) {
                dq.push_back(PosInfo(S[pos], pos));
                numSeen[S[pos]]++;
                if (numSeen[S[pos]] >= numInT[S[pos]] &&
                    tSetWaiting.count(S[pos]) >= 1) {
                    tSetWaiting.erase(S[pos]);
                }
                if (tSetWaiting.empty()) break;
            }
        }
        if (pos == n) return string();

        while (numSeen[dq.front().c] > numInT[dq.front().c]) {
            numSeen[dq.front().c]--;
            dq.pop_front();
        }

        int currLen = pos - dq.front().pos + 1;
        int currPos = pos;
        for (int i = pos + 1; i < n; i++) {
            if (tSet.count(S[i]) >= 1) {
                dq.push_back(PosInfo(S[i], i));
                numSeen[S[i]]++;
                while (numSeen[dq.front().c] > numInT[dq.front().c]) {
                    numSeen[dq.front().c]--;
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

