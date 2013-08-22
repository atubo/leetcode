#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *node = root;
        while (node) {
            node = connectLevelBelow(node);
        }
    }
private:
    TreeLinkNode* connectLevelBelow(TreeLinkNode *node) {
        TreeLinkNode *firstNodeBelow = NULL;
        TreeLinkNode **lastNext = NULL;
        while (node) {
            if (!node->left && !node->right) {
                node = node->next;
                continue;
            }
            TreeLinkNode *left = node->left;
            TreeLinkNode *right = node->right;
            if (!firstNodeBelow) {
                firstNodeBelow = (left ? left : right);
            }
            if (left) {
                if (lastNext) {
                    *lastNext = left;
                }
                if (right) {
                    left->next = right;
                    lastNext = &right->next;
                }
                else {
                    lastNext = &left->next;
                }
            }
            else {
                if (lastNext) {
                    *lastNext = right;
                }
                lastNext = &right->next;
            }
            node = node->next;
        }
        return firstNodeBelow;
    }
};

#if DEBUG
#include "Util.h"

using namespace std;
int main()
{
    vector<int> preorder = getVector();
    vector<int> inorder  = getVector();
    TreeLinkNode *root = buildLinkedTree(preorder, inorder);
    Solution s;
    s.connect(root);
    printLinkedTree(root);

    return 0;
}
#endif

