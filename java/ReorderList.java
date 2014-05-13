import LeetcodeUtil.*;
import java.util.*;

public class ReorderList {
    public static class NodePair {
        public ListNode first;
        public ListNode second;
        public NodePair(ListNode first, ListNode second) {
            this.first = first;
            this.second = second;
        }
    }
        
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;
        
        NodePair np = splitList(head);
        ListNode l1 = np.first;
        ListNode l2 = reverseList(np.second);
        mergeLists(l1, l2);
    }
    
    private NodePair splitList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode l2 = slow.next;
        slow.next = null;
        return new NodePair(head, l2);
    }
    
    private ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode next = curr.next;
        curr.next = null;
        
        while (next != null) {
            ListNode tmp = next.next;
            next.next = curr;
            curr = next;
            next = tmp;
        }
        return curr;
    }
    
    private ListNode mergeLists(ListNode l1, ListNode l2) {
        ListNode head = l1;
        while (l2 != null) {
            ListNode next1 = l1.next;
            ListNode next2 = l2.next;
            l1.next = l2;
            l2.next = next1;
            l1 = next1;
            l2 = next2;
        }
        return head;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode head = reader.readList();
        ReorderList solution = new ReorderList();
        solution.reorderList(head);
        ListNode.printList(head);
    }
}
        