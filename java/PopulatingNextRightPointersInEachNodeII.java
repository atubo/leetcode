import LeetcodeUtil.*;
import java.util.*;

public class PopulatingNextRightPointersInEachNodeII {
    public void connect(TreeLinkNode root) {
        TreeLinkNode head = root;
        while (head != null) {
            head = process(head);
        }
    }
    private TreeLinkNode process(TreeLinkNode head) {
        while (head != null && head.left == null && head.right == null) {
            head = head.next;
        }
        if (head == null) {
            return null;
        }
        TreeLinkNode nextHead;
        TreeLinkNode prev;
        if (head.left != null && head.right != null) {
            head.left.next = head.right;
            prev = head.right;
            nextHead = head.left;
        } else if (head.left != null) {
            prev = head.left;
            nextHead = head.left;
        } else {
            prev = head.right;
            nextHead = head.right;
        }
        TreeLinkNode curr = head.next;
        while (true) {
            while (curr != null && curr.left == null && curr.right == null) {
                curr = curr.next;
            }
            if (curr == null) {
                break;
            }
            if (curr.left != null && curr.right != null) {
                prev.next = curr.left;
                curr.left.next = curr.right;
                prev = curr.right;
            } else if (curr.left != null) {
                prev.next = curr.left;
                prev = curr.left;
            } else {
                prev.next = curr.right;
                prev = curr.right;
            }
            curr = curr.next;
        }
        return nextHead;
    }
    public static void main(String[] args) {
        TreeLinkNode root = TreeLinkNode.parse();
        PopulatingNextRightPointersInEachNodeII solution = new PopulatingNextRightPointersInEachNodeII();
        solution.connect(root);
        if (root != null) print(root);
    }
    
    public static void print(TreeLinkNode node) {
        System.out.printf("%d -> ", node.val);
        if (node.next != null) {
            System.out.println(node.next.val);
        } else {
            System.out.println("null");
        }
        if (node.left != null) {
            print(node.left);
        }
        if (node.right != null) {
            print(node.right);
        }
    }
}

            