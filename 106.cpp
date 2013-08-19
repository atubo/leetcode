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
    TreeNode *buildTree(vector<int> &inorder, vector<int>& postorder) {
        assert(inorder.size() == postorder.size());
        int n = inorder.size();
        TreeNode *root = createSubtree(inorder, postorder, 0, n, 0, n);
        return root;
    }
private:
    TreeNode* createSubtree(vector<int> &inorder, vector<int>& postorder,
                            int m1, int n1, int m2, int n2) {
        assert(n1 - m1 == n2 - m2);
        if (m1 == n1) return NULL;
        int rval = postorder[n2-1];
        int inorderPos = m1;
        for (; inorderPos < n1; inorderPos++) {
            if (inorder[inorderPos] == rval) break;
        }
        TreeNode *node = new TreeNode(rval);
        int l1 = inorderPos - m1;
        node->left = createSubtree(inorder, postorder,
                                   m1, m1+l1, m2, m2+l1);
        node->right = createSubtree(inorder, postorder,
                                    m1+1+l1, n1, m2+l1, n2-1);
        return node;
    }
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> inorder    = getVector();
    vector<int> postorder  = getVector();
    Solution s;
    TreeNode *root = s.buildTree(inorder, postorder);
    printTree(root);

    return 0;
}
#endif



