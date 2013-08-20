#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;
        return getSum(root, 0);
    }
private:
    int getSum(TreeNode *node, int prefix) {
        int currVal = prefix * 10 + node->val;
        if (!node->left && !node->right) {
            return currVal;
        }
        int result = 0;
        if (node->left) {
            result = getSum(node->left, currVal);
        }
        if (node->right) {
            result += getSum(node->right, currVal);
        }
        return result;
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
    cout << s.sumNumbers(root) <<endl;

    return 0;
}
#endif


