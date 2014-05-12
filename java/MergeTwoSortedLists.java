import LeetcodeUtil.*;
import java.util.*;

public class MergeTwoSortedLists {
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
        ListNode l1 = reader.readList();
        ListNode l2 = reader.readList();
        MergeTwoSortedLists solution = new MergeTwoSortedLists();
        ListNode head = solution.mergeTwoLists(l1, l2);
        ListNode.printList(head);
    }
}