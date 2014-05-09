import LeetcodeUtil.*;
import java.util.*;

public class ReverseNodesInKGroup {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null) return head;
        
        ListNode start = head;
        ListNode end   = forward(head, k-1);
        if (end == null) return head;
        
        reverse(start, end);
        head = end;
        ListNode prev = start;
        start = start.next;
        
        while (start != null) {
            end = forward(start, k-1);
            if (end == null) break;
            reverse(start, end);
            prev.next = end;
            prev = start;
            start = start.next;
        }
        
        return head;
    }
    
    private ListNode forward(ListNode node, int steps) {
        ListNode result = node;
        for (int i = 0; i < steps; i++) {
            result = result.next;
            if (result == null) return null;
        }
        return result;
    }
    
    private void reverse(ListNode start, ListNode end) {
        ListNode curr = start;
        ListNode prev = end.next;
        ListNode stop = end.next;
        while (curr != stop) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int k = reader.readInt();
        ListNode head = reader.readList();
        ReverseNodesInKGroup solution = new ReverseNodesInKGroup();
        head = solution.reverseKGroup(head, k);
        ListNode.printList(head);
    }
}