#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


inline ListNode* makeList(int *a, int size)
{
    ListNode *next = NULL;
    ListNode *curr;
    for (int i = size - 1; i >= 0; i--) {
        curr = new ListNode(a[i]);
        curr->next = next;
        next = curr;
    }
    return curr;
}

inline void printList(ListNode *head)
{
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

#endif
