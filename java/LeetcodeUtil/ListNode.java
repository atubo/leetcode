package LeetcodeUtil;

public class ListNode {
    public int val;
    public ListNode next;
    
    public ListNode(int x) {
        this.val  = x;
        this.next = null;
    }
    
    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.printf("%d ", curr.val);
            curr = curr.next;
        }
        System.out.println();
    }
}
    