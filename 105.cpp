#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int>& inorder) {
        assert(preorder.size() == inorder.size());
        int n = preorder.size();
        TreeNode *root = createSubtree(preorder, inorder, 0, n, 0, n);
        return root;
    }
private:
    TreeNode* createSubtree(vector<int> &preorder, vector<int>& inorder,
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
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);
    printTree(root);

    return 0;
}
#endif



