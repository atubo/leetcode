import java.util.*;
import LeetcodeUtil.*;

public class RemoveNthNodeFromEndOfList {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first = head;
        for (int i = 0; i < n; i++) {
            first = first.next;
        }
        
        ListNode curr = head;
        ListNode prev = null;
        while (first != null) {
            first = first.next;
            prev  = curr;
            curr  = curr.next;
        }
        
        if (prev != null) {
            prev.next = curr.next;
        } else {
            head = head.next;
        }
        
        return head;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int m = reader.readInt();
        ListNode head = reader.readList();
        
        RemoveNthNodeFromEndOfList solution = new RemoveNthNodeFromEndOfList();
        head = solution.removeNthFromEnd(head, m);
        ListNode.printList(head);
    }
}