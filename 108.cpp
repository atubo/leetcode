#include <vector>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size() - 1);
    }
private:
    TreeNode *build(vector<int>& a, int i, int j) {
        if (i > j) return NULL;
        int mid = (i + j) / 2;
        TreeNode *node = new TreeNode(a[mid]);
        node->left = build(a, i, mid - 1);
        node->right = build(a, mid + 1, j);
        return node;
    }
};

#if DEBUG
#include "Util.h"
int main()
{
    vector<int> num = getVector();
    Solution s;
    TreeNode *root = s.sortedArrayToBST(num);
    printTree(root);

    return 0;
}
#endif

