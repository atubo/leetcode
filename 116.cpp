#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#endif

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        visit(root);
    }
private:
    void visit(TreeLinkNode *node) {
        setNext(node);
        if (node->left) {
            visit(node->left);
            visit(node->right);
        }
    }
    void setNext(TreeLinkNode *node) {
        if (!node->left) return;
        TreeLinkNode *left = node->left;
        TreeLinkNode *right = node->right;
        while (left) {
            left->next = right;
            left = left->right;
            right = right->left;
        }
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
    printLinkedTree(root);
    Solution s;
    s.connect(root);
    printLinkedTree(root);

    return 0;
}
#endif

