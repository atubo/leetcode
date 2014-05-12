import LeetcodeUtil.*;
import java.util.*;

public class SortList {
    public static class NodePair {
        public ListNode first;
        public ListNode second;
        
        public NodePair(ListNode first, ListNode second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public ListNode sortList(ListNode head) {
        if (head == null) return head;
        NodePair np = splitList(head);
        ListNode l1 = sortList(np.first);
        ListNode l2 = sortList(np.second);
        return mergeTwoLists(l1, l2);
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
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        
        ListNode head;
        if (l1.val < l2.val) {
            head = l1;
            l1 = l1.next;
        } else {
            head = l2;
            l2 = l2.next;
        }
        
        ListNode prev = head;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }
        if (l1 == null) {
            prev.next = l2;
        } else {
            prev.next = l1;
        }
        
        return head;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode head = reader.readList();
        SortList solution = new SortList();
        head = solution.sortList(head);
        ListNode.printList(head);
    }
}