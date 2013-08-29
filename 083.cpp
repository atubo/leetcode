#include <iostream>

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        ListNode *nextElem = head->next;
        while (nextElem && nextElem->val == head->val) {
            nextElem = nextElem->next;
        }
        head->next = deleteDuplicates(nextElem);
        return head;
    }
};

#if DEBUG
int main()
{
    ListNode *head = readList();
    Solution s;
    head = s.deleteDuplicates(head);
    printList(head);

    return 0;
}
#endif

