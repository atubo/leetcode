#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

#define RECURSIVE 0
#if RECURSIVE
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (left && right) {
            if (left->val != right->val) return false;
            return (isMirror(left->left, right->right) &&
                    isMirror(left->right, right->left));
        }
        return false;
    }
};
#else
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        string left = serialize(root->left, 0);
        string right = serialize(root->right, 1);
        return left.compare(right) == 0;
    }
private:
    string serialize(TreeNode *root, int mode) {
        string result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                stringstream stream;
                stream << node->val << ",";
                result.append(stream.str());
                if (mode == 0) {
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    q.push(node->right);
                    q.push(node->left);
                }
            }
            else {
                result.append("#,");
            }
        }
        return result;
    }
};
#endif



#if DEBUG
#include "Util.h"
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    TreeNode *root = buildTree(preorder, inorder);
    Solution s;
    cout << s.isSymmetric(root) << endl;

    return 0;
}
#endif

