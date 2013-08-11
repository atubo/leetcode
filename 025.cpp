#include <algorithm>
#include <iostream>
using namespace std;

#define DEBUG 1
#if DEBUG
#include "LinkedList.h"
#endif

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = getSize(head);
        ListNode *p2 = head;
        ListNode **ppnext = &head;
        for (int i = 0; i < n/k; i++) {
            pair<ListNode*, ListNode*> ppair = reverseGroup(p2, ppnext, k);
            ListNode* p0 = ppair.first;
            p2 = ppair.second;
            ppnext = &(p0->next);
        }
        *ppnext = p2;
        return head;
    }
private:
    int getSize(ListNode *head) {
        int count = 0;
        ListNode *p = head;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }
    pair<ListNode*, ListNode*> reverseGroup(ListNode* p0,
                                            ListNode** ppnext,
                                            int k) {
        ListNode *p1 = p0;
        ListNode *p2 = p1->next;
        for (int i = 0; i < k - 1; i++) {
            ListNode *p2old = p2;
            p2 = p2->next;
            p2old->next = p1;
            p1 = p2old;
        }
        *ppnext = p1;
        return make_pair(p0, p2);
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
    head = s.reverseKGroup(head, k);
    printList(head);
    return 0;
}
#endif

