import LeetcodeUtil.*;

public class LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        boolean hasCycle = true;
        while (true) {
            if (fast == null || fast.next == null || fast.next.next == null) {
                hasCycle = false;
                break;
            }
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow) break;
        }
        if (!hasCycle) return null;
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
    
    public static void main(String[] args) {
        ListNode node0 = new ListNode(3);
        ListNode node1 = new ListNode(2);
        ListNode node2 = new ListNode(0);
        ListNode node3 = new ListNode(-4);
        node0.next = node1;
        node1.next = node2;
        node2.next = node3;
        node3.next = node1;
        LinkedListCycleII solution = new LinkedListCycleII();
        ListNode result = solution.detectCycle(node0);
    }
}