#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> seen;
        vector<int> result;
        for (int i = 0; i < (int)numbers.size(); i++) {
            int x = numbers[i];
            if (seen.count(target-x) > 0) {
                result.push_back(seen[target-x]+1);
                result.push_back(i+1);
                break;
            }
            else {
                seen.insert(make_pair(x, i));
            }
        }
        return result;
    }
};
