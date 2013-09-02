#include <vector>
#include <deque>
#include <queue>
#include <iterator>
#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) return result;

        queue<TreeNode*> q1;
        q1.push(root);
        for (int depth = 0; ; depth++) {
            if (q1.empty()) break;
            queue<TreeNode*> q2;
            deque<int> level;
            while (!q1.empty()) {
                TreeNode *node = q1.front();
                q1.pop();
                if (depth % 2 == 0) {
                    level.push_back(node->val);
                }
                else {
                    level.push_front(node->val);
                }
                if (node->left) {
                    q2.push(node->left);
                }
                if (node->right) {
                    q2.push(node->right);
                }
            }
            q1.swap(q2);
            result.push_back(vector<int>());
            copy(level.begin(), level.end(), back_inserter(result.back()));
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
    vector<vector<int> > result = s.zigzagLevelOrder(root);
    for (int i = 0; i < (int)result.size(); i++) {
        printVector(result[i]);
    }

    return 0;
}
#endif

