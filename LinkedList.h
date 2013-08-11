#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <assert.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


inline ListNode* makeList(int *a, int size)
{
    ListNode *next = NULL;
    ListNode *curr = NULL;
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

inline int getListSize(ListNode *head) {
    int count = 0;
    ListNode *p = head;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

inline ListNode* getNthNode(ListNode *head, int n) {
    int k = 1;
    ListNode *p = head;
    while (k != n) {
        assert(p);
        p = p->next;
        k++;
    }
    return p;
}

#endif
