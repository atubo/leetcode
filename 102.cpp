#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        int currDepth = -1;
        while (!q.empty()) {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int depth = p.second;
            if (depth > currDepth) {
                currDepth = depth;
                result.push_back(vector<int>());
            }
            result.back().push_back(node->val);
            if (node->left) q.push(make_pair(node->left, depth+1));
            if (node->right) q.push(make_pair(node->right, depth+1));
        }
        return result;
    }
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    TreeNode *root = buildTree(preorder, inorder);
    Solution s;
    vector<vector<int> > result = s.levelOrder(root);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

