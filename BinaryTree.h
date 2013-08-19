#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>
#include <cassert>

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

inline TreeNode* createSubtree(std::vector<int> &preorder,
                               std::vector<int>& inorder,
                        int m1, int n1, int m2, int n2) {
    assert(n1 - m1 == n2 - m2);
    if (m1 == n1) return NULL;
    int rval = preorder[m1];
    int inorderPos = m2;
    for (; inorderPos < n2; inorderPos++) {
        if (inorder[inorderPos] == rval) break;
    }
    TreeNode *node = new TreeNode(rval);
    int l1 = inorderPos - m2;
    node->left = createSubtree(preorder, inorder,
                               m1+1, m1+1+l1, m2, m2+l1);
    node->right = createSubtree(preorder, inorder,
                                m1+1+l1, n1, m2+l1+1, n2);
    return node;
}

inline TreeNode *buildTree(std::vector<int> &preorder,
                           std::vector<int>& inorder) {
    assert(preorder.size() == inorder.size());
    int n = preorder.size();
    TreeNode *root = createSubtree(preorder, inorder, 0, n, 0, n);
    return root;
}


#endif
