#include <string>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        if (n == 0) return path;

        int startPos = 0;
        while (path[startPos] == '/') {
            startPos++;
        }

        deque<string> pathStack;
        string name;
        for (int i = startPos; i < n; i++) {
            if (path[i] == '/') {
                if (name.compare("..") == 0) {
                    if (!pathStack.empty()) {
                        pathStack.pop_front();
                    }
                }
                else if (name.compare(".") != 0) {
                    pathStack.push_front(name);
                }
                name.clear();
                while (i < n-1 && path[i+1] == '/') {
                    i++;
                }
            }
            else {
                name.push_back(path[i]);
            }
        }
        if (path[n-1] != '/') {
            if (name.compare("..") == 0) {
                if (!pathStack.empty()) {
                    pathStack.pop_front();
                }
            }
            else if (name.compare(".") != 0) {
                pathStack.push_front(name);
            }
        }

        string result;
        while (!pathStack.empty()) {
            string dir = pathStack.back();
            pathStack.pop_back();
            result.append("/" + dir);
        }
        if (result.empty()) {
            result = "/";
        }
        return result;
    }
};

#if 0
int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.simplifyPath(str) << endl;

    return 0;
}
#endif


