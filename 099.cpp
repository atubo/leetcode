#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    void recoverTree(TreeNode *root) {
        prev = NULL;
        p1   = NULL;
        p2   = NULL;
        visit(root);
        swap(p1->val, p2->val);
    }
private:
    void visit(TreeNode *node) {
        if (node->left) visit(node->left);
        if (!prev) {
            prev = node;
        }
        else {
            if (prev->val > node->val) {
                if (!p1) p1 = prev;
                p2 = node;
            }
            prev = node;
        }
        if (node->right) visit(node->right);
    }

    TreeNode *prev;
    TreeNode *p1;
    TreeNode *p2;
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    TreeNode *root = buildTree(preorder, inorder);
    Solution s;
    s.recoverTree(root);
    printTree(root);

    return 0;
}
#endif


