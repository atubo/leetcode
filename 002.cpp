class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbersRecur(l1, l2, 0);
    }
    ListNode *addTwoNumbersRecur(ListNode *l1, ListNode *l2, int carry) {
        if (!l1 && !l2 && carry == 0) {
            return NULL;
        }
        int x1 = (l1 ? l1->val : 0);
        int x2 = (l2 ? l2->val : 0);
        int x = (x1 + x2 + carry) % 10;
        int c = (x1 + x2 + carry) / 10;
        ListNode *ln = new ListNode(x);
        ListNode *l1next = (l1 ? l1->next : NULL);
        ListNode *l2next = (l2 ? l2->next : NULL);
        ln->next = addTwoNumbersRecur(l1next, l2next, c);
        return ln;
    }
};

