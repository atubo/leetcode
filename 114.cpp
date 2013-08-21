#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

#include <iostream>
using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode** rightnext = createSubtree(root);
        *rightnext = NULL;
    }
private:
    TreeNode** createSubtree(TreeNode *node) {
        if (node->left) {
            TreeNode **leftnext = createSubtree(node->left);
            if (node->right) {
                TreeNode **rightnext = createSubtree(node->right);
                TreeNode *oldright = node->right;
                node->right = node->left;
                node->left = NULL;
                *leftnext = oldright;
                return rightnext;
            }
            else {
                node->right = node->left;
                node->left = NULL;
                return leftnext;
            }
        }
        else if (node->right) {
            TreeNode **rightnext = createSubtree(node->right);
            return rightnext;
        }
        else {
            return &node->right;
        }
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
    s.flatten(root);
    printTree(root);

    return 0;
}
#endif

