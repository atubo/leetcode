#include <queue>
#include <iostream>
#include <limits>
using namespace std;

#define DEBUG 0
#if DEBUG
#include "LinkedList.h"
#endif

struct Data {
    Data(ListNode *ptr_):ptr(ptr_) {
        const int MAXINT = numeric_limits<int>::max();
        val = ptr ? ptr->val : MAXINT;
    }
    int val;
    ListNode* ptr;
    bool operator < (const Data& other) const {
        return val > other.val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Data> queue;
        int n = lists.size();
        if (n == 0) return NULL;
        for (int i = 0; i < n; i++) {
            queue.push(Data(lists[i]));
        }
        Data d = queue.top();
        if (d.ptr == NULL) return NULL;
        queue.pop();
        ListNode *head;
        ListNode *tail;
        ListNode *ptr = d.ptr;
        head = tail = ptr;
        ptr = ptr->next;
        queue.push(ptr);
        while (queue.top().ptr != NULL) {
            d = queue.top();
            queue.pop();
            ptr = d.ptr;
            tail = tail->next = ptr;
            ptr  = ptr->next;
            queue.push(ptr);
        }
        return head;
    }
};

#if DEBUG
int main()
{
    int k;
    cin >> k;
    vector<ListNode*> lists;
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        ListNode *head = makeList(a, n);
        lists.push_back(head);
    }

    Solution s;
    ListNode *head = s.mergeKLists(lists);
    printList(head);

    return 0;
}
#endif

