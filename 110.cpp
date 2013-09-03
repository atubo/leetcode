#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        try {
            check(root);
        }
        catch (int e) {
            return false;
        }
        return true;
    }
private:
    int check(TreeNode *node) {
        if (!node) return 0;
        int lh = check(node->left);
        int rh = check(node->right);
        if (abs(lh - rh) > 1) throw 1;
        return 1 + max(lh, rh);
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
    cout << s.isBalanced(root) << endl;

    return 0;
}
#endif

