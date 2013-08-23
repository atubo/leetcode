#include <limits>
#include <iostream>
#include <limits>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        prev = numeric_limits<int>::min();
        isFirst = true;
        try {
            visit(root);
        }
        catch (int e) {
            return false;
        }
        return true;
    }
private:
    void visit(TreeNode *node) {
        if (node->left) visit(node->left);
        if (isFirst) {
            isFirst = false;
            prev = node->val;
        }
        else {
            if (prev >= node->val) throw 1;
            prev = node->val;
        }
        if (node->right) visit(node->right);
    }
    int prev;
    bool isFirst;
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    TreeNode *root = buildTree(preorder, inorder);
    Solution s;
    cout << s.isValidBST(root) << endl;

    return 0;
}
#endif

