import LeetcodeUtil.*;

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        boolean result = true;
        while (true) {
            if (fast == null || fast.next == null || fast.next.next == null) {
                result = false;
                break;
            }
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) break;
        }
        return result;
    }
}
            
    