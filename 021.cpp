#include <iostream>
using namespace std;

#define DEBUG 1
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head;
        ListNode *tail;
        if (l1->val < l2->val) {
            head = tail = l1;
            l1 = l1->next;
        }
        else {
            head = tail = l2;
            l2 = l2->next;
        }

        while (l1 || l2) {
            if (l1 == NULL) {
                tail->next = l2;
                break;
            }
            else if (l2 == NULL) {
                tail->next = l1;
                break;
            }
            else {
                if (l1->val < l2->val) {
                    tail = tail->next = l1;
                    l1 = l1->next;
                }
                else {
                    tail = tail->next = l2;
                    l2 = l2->next;
                }
            }
        }
        return head;
    }
};
                    
#if DEBUG
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++) {
        cin >> a1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> a2[i];
    }

    ListNode *l1 = makeList(a1, n1);
    ListNode *l2 = makeList(a2, n2);
    Solution s;
    ListNode *head = s.mergeTwoLists(l1, l2);
    printList(head);

    return 0;
}
#endif

