#include <vector>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return build(0, n);
    }
private:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;
        if (start == end) {
            result.push_back(NULL);
            return result;
        }
        for (int k = start; k < end; k++) {
            vector<TreeNode*> leftTrees = build(start, k);
            vector<TreeNode*> rightTrees = build(k+1, end);
            for (int i = 0; i < (int)leftTrees.size(); i++) {
                for (int j = 0; j < (int)rightTrees.size(); j++) {
                    TreeNode *node = new TreeNode(k+1);
                    node->left = leftTrees[i];
                    node->right = rightTrees[j];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};

#if DEBUG
int main()
{
    int n;
    cin >> n;
    Solution s;
    vector<TreeNode*> result = s.generateTrees(n);
    for (int i = 0; i < (int)result.size(); i++) {
        printTree(result[i]);
        cout << endl;
    }

    return 0;
}
#endif



