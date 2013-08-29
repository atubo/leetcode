#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
        if (!head->next || head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
        }
        else {
            ListNode *nextElem = head->next;
            while (nextElem && nextElem->val == head->val) {
                nextElem = nextElem->next;
            }
            head = deleteDuplicates(nextElem);
        }
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

