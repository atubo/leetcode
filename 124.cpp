#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

struct AuxTreeNode {
    int val;
    int maxPathVal;
    AuxTreeNode *left;
    AuxTreeNode *right;
    AuxTreeNode(int x): val(x), maxPathVal(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        AuxTreeNode *auxRoot = createAuxTree(root);
        int result = numeric_limits<int>::min();
        getMaxPathSum(auxRoot, result);
        return result;
    }
private:
    AuxTreeNode* createAuxTree(TreeNode* origNode) {
        if (!origNode) return NULL;
        AuxTreeNode *node = new AuxTreeNode(origNode->val);
        node->left = createAuxTree(origNode->left);
        node->right = createAuxTree(origNode->right);
        int leftVal = (node->left ? node->left->maxPathVal : 0);
        int rightVal = (node->right ? node->right->maxPathVal : 0);
        leftVal = max(0, leftVal);
        rightVal = max(0, rightVal);
        node->maxPathVal = max(leftVal, rightVal) + node->val;
        return node;
    }
    void getMaxPathSum(AuxTreeNode *node, int& currMax) {
        if (!node) return;
        int leftVal = (node->left ? node->left->maxPathVal : 0);
        int rightVal = (node->right ? node->right->maxPathVal : 0);
        leftVal = max(0, leftVal);
        rightVal = max(0, rightVal);
        currMax = max(currMax, leftVal + rightVal + node->val);
        getMaxPathSum(node->left, currMax);
        getMaxPathSum(node->right, currMax);
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
    cout << s.maxPathSum(root) << endl;

    return 0;
}
#endif

