import LeetcodeUtil.*;
import java.util.*;

public class ConvertSortedListToBinarySearchTree {
    public TreeNode sortedListToBST(ListNode head) {
        return build(head, null);
    }
    private TreeNode build(ListNode begin, ListNode end) {
        if (begin == end) return null;
        ListNode fast = begin;
        ListNode slow = begin;
        while (true) {
            if (fast.next == end || fast.next.next == end) {
                break;
            }
            fast = fast.next.next;
            slow = slow.next;
        }
        TreeNode node = new TreeNode(slow.val);
        node.left = build(begin, slow);
        if (slow.next != null) {
            node.right = build(slow.next, end);
        }
        return node;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        ListNode head = reader.readList();
        ConvertSortedListToBinarySearchTree solution = new ConvertSortedListToBinarySearchTree();
        TreeNode root = solution.sortedListToBST(head);
        System.out.println(TreeNode.serialize(root));
    }
}
        