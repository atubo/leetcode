#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

#define DEBUG 1
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int n = getListSize(head);
        k = k % n;
        if (k == 0) return head;
        ListNode *last = getNthNode(head, n);
        ListNode *p_k  = getNthNode(head, n-k);
        shiftLeft3(head, p_k->next, last->next);
        return head;
    }
private:
    int getListSize(ListNode *head) {
        int count = 0;
        ListNode *p = head;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }
    ListNode* getNthNode(ListNode *head, int n) {
        int k = 1;
        ListNode *p = head;
        while (k != n) {
            assert(p);
            p = p->next;
            k++;
        }
        return p;
    }
    void shiftLeft3(ListNode*& a, ListNode*& b, ListNode*& c) {
        ListNode* tmp = a;
        a = b;
        b = c;
        c = tmp;
    }
};

#if DEBUG
int main()
{
    int n;
    int k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ListNode *head = makeList(a, n);
    Solution s;
    head = s.rotateRight(head, k);
    printList(head);
    return 0;
}
#endif

