#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

inline void printTree(TreeNode *node)
{
    using std::cout;
    using std::endl;

    if (!node) {
        cout << "# ";
        return;
    }
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

#endif
