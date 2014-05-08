import LeetcodeUtil.*;
import java.util.*;

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode n1 = head;
        ListNode n2 = head.next;
        head = n2;
        swap(n1, n2);
        ListNode prev = n1;
        while (prev.next != null && prev.next.next != null) {
            n1 = prev.next;
            n2 = prev.next.next;
            prev.next = n2;
            swap(n1, n2);
            prev = n1;
        }
        return head;
    }
    private void swap(ListNode n1, ListNode n2) {
        ListNode tmp = n2.next;
        n2.next = n1;
        n1.next = tmp;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode head = reader.readList();
        SwapNodesInPairs solution = new SwapNodesInPairs();
        head = solution.swapPairs(head);
        ListNode.printList(head);
    }
}
        
        
        