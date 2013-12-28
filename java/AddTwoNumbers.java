import LeetcodeUtil.*;

public class AddTwoNumbers {
    private int carry = 0;
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        carry = 0;
        ListNode head = new ListNode(0);
        ListNode curr = head;
        while (l1 != null || l2 != null) {
            curr.next = addNode(l1, l2);
            curr = curr.next;
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        if (carry != 0) {
            curr.next = new ListNode(carry);
        }
        return head.next;
    }
    
    private ListNode addNode(ListNode n1, ListNode n2) {
        int x1 = (n1 != null ? n1.val : 0);
        int x2 = (n2 != null ? n2.val : 0);
        int x = (x1 + x2 + carry) % 10;
        carry = (x1 + x2 + carry) / 10;
        return new ListNode(x);
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode l1 = reader.readList();
        ListNode l2 = reader.readList();
        
        AddTwoNumbers solution = new AddTwoNumbers();
        ListNode result = solution.addTwoNumbers(l1, l2);
        ListNode.printList(result);
    }
}
        
            