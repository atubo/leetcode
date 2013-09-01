#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        result.clear();
        setupDict();
        int n = digits.size();
        if (n == 0) return vector<string>(1, "");
        string comb(n, '\0');
        generateComb(0, comb, digits);
        return result;
    }
private:
    vector<string> result;
    map<char, string> dict;

    void setupDict() {
        dict.clear();
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
    }

    void generateComb(int start, string& comb, string digits) {
        if (start == (int)digits.size()) {
            result.push_back(comb);
            return;
        }
        for (int i = 0; i < (int)dict[digits[start]].size(); i++) {
            char c = dict[digits[start]][i];
            comb[start] = c;
            generateComb(start+1, comb, digits);
        }
    }
};

#if 0
int main()
{
    string digits;
    cin >> digits;
    Solution s;
    vector<string> result = s.letterCombinations(digits);
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
#endif

