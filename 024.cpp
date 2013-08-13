#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *curr = head;
        ListNode *next = curr->next;
        ListNode *tail;
        head = next;
        tail = curr;
        curr = next->next;
        next->next = tail;
        while (curr && curr->next) {
            next = curr->next;
            tail->next = next;
            tail = curr;
            curr = next->next;
            next->next = tail;
        }
        tail->next = curr;
        return head;
    }
};

#if DEBUG
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ListNode *head = makeList(a, n);
    Solution s;
    head = s.swapPairs(head);
    printList(head);

    return 0;
}
#endif

