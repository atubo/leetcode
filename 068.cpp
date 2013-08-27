#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int L) {
        int n = words.size();
        int i = 0;
        int j;
        vector<string> result;
        while (true) {
            int totalLength = words[i].length();
            for (j = i + 1; j < n; j++) {
                totalLength += words[j].length() + 1;
                if (totalLength > L) {
                    break;
                }
            }
            if (j < n) {
                result.push_back(arrange(words, L, i, j));
                i = j;
            }
            else {
                string lastLine;
                for (int k = i; k < n-1; k++) {
                    lastLine.append(words[k]);
                    lastLine.push_back(' ');
                }
                lastLine.append(words[n-1]);
                int numTrailingSpace = L - lastLine.length();
                for (int k = 0; k < numTrailingSpace; k++) {
                    lastLine.push_back(' ');
                }
                result.push_back(lastLine);
                break;
            }
        }
        return result;
    }
private:
    string arrange(const vector<string>& words, int L, int i, int j) {
        string result;
        if (j - i == 1) {
            int numSpaces = L - words[i].length();
            result.append(words[i]);
            for (int iSp = 0; iSp < numSpaces; iSp++) {
                result.push_back(' ');
            }
        }
        else {
            int totalWordLength = 0;
            for (int k = i; k < j; k++) {
                totalWordLength += words[k].length();
            }
            int numEmptySlots = j - i - 1;
            int avgSpaces = (L - totalWordLength) / numEmptySlots;
            int numExtraSpace = (L - totalWordLength) % numEmptySlots;
            for (int k = i; k < j - 1; k++) {
                result.append(words[k]);
                for (int iSp = 0; iSp < avgSpaces; iSp++) {
                    result.push_back(' ');
                }
                if (k - i < numExtraSpace) {
                    result.push_back(' ');
                }
            }
            result.append(words[j-1]);
        }
        return result;
    }
};

#if 0
int main()
{
    int n;
    int L;
    cin >> n >> L;
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }
    Solution s;
    vector<string> result = s.fullJustify(words, L);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
#endif

