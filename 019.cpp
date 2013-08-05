#include <stdio.h>
//#define DEBUG

#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
#endif


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *pprev = NULL;
        ListNode *result = head;
        for (int i = 0; i < n-1; i++) {
            p2 = p2->next;
        }
        while (p2->next) {
            pprev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (pprev != NULL) {
            pprev->next = p1->next;
            delete p1;
            p1 = NULL;
        }
        else {
            result = head->next;
            delete head;
            head = NULL;
        }
        return result;
    }
};

#ifdef DEBUG
ListNode* makeList(int *a, int size)
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

void printList(ListNode *head)
{
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    Solution s;
    int a[] = {1,2,3,4,5};
    ListNode *head = makeList(a, 5);
    ListNode *newhead = s.removeNthFromEnd(head, 2);

    printf("%p\n", newhead);
    printList(newhead);

    return 0;
}
#endif
