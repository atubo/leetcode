#include <iostream>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode **last = &head;
        for (int i = 0; i < m - 1; i++) {
            last = &((*last)->next);
        }
        *last = reverseRange(*last, n-m+1);
        return head;
    }
private:
    ListNode* reverseRange(ListNode *head, int n) {
        ListNode *tail = head;
        ListNode *curr = head->next;
        for (int i = 0; i < n - 1; i++) {
            ListNode *next = curr->next;
            curr->next = tail;
            tail = curr;
            curr = next;
        }
        head->next = curr;
        return tail;
    }
};

#if DEBUG
int main()
{
    ListNode *head = readList();
    int m, n;
    cin >> m >> n;
    Solution s;
    head = s.reverseBetween(head, m, n);
    printList(head);

    return 0;
}
#endif

