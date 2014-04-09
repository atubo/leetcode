import LeetcodeUtil.*;
import java.util.*;

public class ReverseLinkedListII {
    public static class Pts {
        public ListNode head;
        public ListNode tail;
        public Pts(ListNode head, ListNode tail) {
            this.head = head;
            this.tail = tail;
        }
    }
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode left = head;
        for (int i = 0; i < m-2; i++) {
            left = left.next;
        }
        ListNode right = head;
        for (int i = 0; i < n; i++) {
            right = right.next;
        }
        Pts pts = reverse((m==1 ? left : left.next), n-m+1);
        if (m == 1) {
            head = pts.head;
        } else {
            left.next = pts.head;
        }
        pts.tail.next = right;
        return head;
    }
    private Pts reverse(ListNode node, int length) {
        if (length == 1) {
            return new Pts(node, node);
        }
        Pts pts = reverse(node.next, length-1);
        pts.tail.next = node;
        return new Pts(pts.head, node);
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode head = reader.readList();
        ReverseLinkedListII solution = new ReverseLinkedListII();
        head = solution.reverseBetween(head, 1, 1);
        ListNode.printList(head);
    }
}
            
        