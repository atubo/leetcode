package LeetcodeUtil;

import java.util.Scanner;

public class InputReader {
    Scanner sc = new Scanner(System.in);
    
    public String readString() {
        return sc.next();
    }
    
    public int[] readArray() {
        int n = sc.nextInt();
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = sc.nextInt();
        }
        return result;
    }
    
    public int readInt() {
        int result = sc.nextInt();
        return result;
    }
    
    public ListNode readList() {
        int n = sc.nextInt();
        ListNode head = new ListNode(0);
        ListNode curr = head;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            curr.next = new ListNode(x);
            curr = curr.next;
        }
        return head.next;
    }
}
        