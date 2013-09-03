#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "BinaryTree.h"
#include "LinkedList.h"
#endif

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        return build(head, NULL);
    }
private:
    TreeNode *build(ListNode *head, ListNode *tail) {
        if (head == tail) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != tail && fast->next->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left = build(head, slow);
        node->right = build(slow->next, tail);
        return node;
    }
};

#if DEBUG
int main()
{
    ListNode *head = readList();
    Solution s;
    TreeNode *root = s.sortedListToBST(head);
    printTree(root);

    return 0;
}
#endif

