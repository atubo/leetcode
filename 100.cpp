#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (p && q) {
            if (p->val != q->val) return false;
            if (!isSameTree(p->left, q->left)) return false;
            return isSameTree(p->right, q->right);
        }
        return false;
    }
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder1 = getVector();
    vector<int> inorder1  = getVector();
    vector<int> preorder2 = getVector();
    vector<int> inorder2  = getVector();
    TreeNode *p = buildTree(preorder1, inorder1);
    TreeNode *q = buildTree(preorder2, inorder2);
    Solution s;
    cout << s.isSameTree(p, q) << endl;

    return 0;
}
#endif

