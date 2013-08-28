#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        result.clear();
        if (!root) return result;
        vector<int> path;
        check(root, sum, path);
        return result;
    }
private:
    void check(TreeNode *node, int sum, vector<int>& path) {
        path.push_back(node->val);
        if (!node->left && !node->right && node->val == sum) {
            result.push_back(path);
        }
        if (node->left) check(node->left, sum - node->val, path);
        if (node->right) check(node->right, sum - node->val, path);
        path.pop_back();
    }
    vector<vector<int> > result;
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
    vector<vector<int> > result = s.pathSum(root, sum);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif


