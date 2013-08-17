#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        ListNode *pre       = NULL;
        ListNode *pretail   = NULL;
        ListNode *post      = NULL;
        ListNode *posttail  = NULL;
        ListNode *curr = head;
        while (curr) {
            if (curr->val >= x) {
                if (post == NULL) {
                    post = posttail = curr;
                }
                else {
                    posttail = posttail->next = curr;
                }
            }
            else {
                if (pre == NULL) {
                    pre = pretail = curr;
                }
                else {
                    pretail = pretail->next = curr;
                }
            }
            curr = curr->next;
        }
        if (pre) {
            head = pre;
            pretail->next = post;
        }
        else {
            head = post;
        }
        if (posttail) posttail->next = NULL;
        else pretail->next = NULL;
        return head;
    }
};

#if DEBUG
int main()
{
    ListNode *head = readList();
    int x;
    cin >> x;
    Solution s;
    head = s.partition(head, x);
    printList(head);

    return 0;
}
#endif

