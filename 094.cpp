#include <stack>
#include <vector>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;
        TreeNode *node = root;
        stack<TreeNode*> nodeStack;
        while (true) {
            if (node->left) {
                nodeStack.push(node);
                node = node->left;
                continue;
            }
            if (node->right) {
                result.push_back(node->val);
                node = node->right;
                continue;
            }
            result.push_back(node->val);
            while (!nodeStack.empty() && !nodeStack.top()->right) {
                result.push_back(nodeStack.top()->val);
                nodeStack.pop();
            }
            if (nodeStack.empty()) break;
            node = nodeStack.top();
            nodeStack.pop();
            result.push_back(node->val);
            node = node->right;
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
    vector<int> result = s.inorderTraversal(root);
    printVector(result);

    return 0;
}
#endif


