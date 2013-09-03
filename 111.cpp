#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    int minDepth(TreeNode *root) {
        const int MAX_INT = numeric_limits<int>::max();
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int lh = (root->left ? minDepth(root->left) : MAX_INT);
        int rh = (root->right ? minDepth(root->right) : MAX_INT);
        return 1 + min(lh, rh);
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
    cout << s.minDepth(root) << endl;

    return 0;
}
#endif

