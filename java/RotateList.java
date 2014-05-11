import LeetcodeUtil.*;
import java.util.*;

public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        int n = 1;
        ListNode tail = head;
        while (tail.next != null) {
            n++;
            tail = tail.next;
        }
        
        k = k % n;
        if (k == 0) return head;
        
        ListNode curr = head;
        for (int i = 1; i < n-k; i++) {
            curr = curr.next;
        }
        ListNode tmp = curr.next;
        curr.next = null;
        tail.next = head;
        head = tmp;
        
        return head;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int k = reader.readInt();
        ListNode head = reader.readList();
        RotateList solution = new RotateList();
        head = solution.rotateRight(head, k);
        ListNode.printList(head);
    }
}