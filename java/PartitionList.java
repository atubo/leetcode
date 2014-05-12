import LeetcodeUtil.*;
import java.util.*;

public class PartitionList {
    public ListNode partition(ListNode head, int x) {
        if (head == null) return head;
        
        ListNode h1 = null, h2 = null, p1 = null, p2 = null;
        ListNode curr = head;
        while (curr != null) {
            if (curr.val < x) {
                if (h1 == null) {
                    h1 = p1 = curr;
                } else {
                    p1.next = curr;
                    p1 = curr;
                }
            } else {
                if (h2 == null) {
                    h2 = p2 = curr;
                } else {
                    p2.next = curr;
                    p2 = curr;
                }
            }
            curr = curr.next;
        }
        
        if (p2 != null) {
            p2.next = null;
        }
        if (h1 != null) {
            p1.next = h2;
            return h1;
        } else {
            return h2;
        }
    }
    
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int x = reader.readInt();
        ListNode head = reader.readList();
        PartitionList solution = new PartitionList();
        head = solution.partition(head, x);
        ListNode.printList(head);
    }
}