#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        try {
            check(root, sum);
        }
        catch (int e) {
            return true;
        }
        return false;
    }
private:
    void check(TreeNode *node, int sum) {
        if (!node->left && !node->right && node->val == sum) {
            throw 1;
        }
        if (node->left) check(node->left, sum - node->val);
        if (node->right) check(node->right, sum - node->val);
    }
};

#if DEBUG
#include <vector>
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder = getVector();
    int sum;
    cin >> sum;
    TreeNode *root = buildTree(preorder, inorder);
    Solution s;
    cout << s.hasPathSum(root, sum) << endl;

    return 0;
}
#endif


