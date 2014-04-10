import LeetcodeUtil.*;
import java.util.*;

public class FlattenBinaryTreeToLinkedList {
    public static class Pts {
        public TreeNode head;
        public TreeNode tail;
        public Pts(TreeNode head, TreeNode tail) {
            this.head = head;
            this.tail = tail;
        }
    }
    public void flatten(TreeNode root) {
        if (root != null) {
            build(root);
        }
    }
    public Pts build(TreeNode node) {
        if (node.left == null && node.right == null) {
            return new Pts(node, node);
        }
        Pts right = null;
        Pts left = null;
        if (node.left != null) {
            left = build(node.left);
        }
        if (node.right != null) {
            right = build(node.right);
        }
        if (right == null) {
            node.left = null;
            node.right = left.head;
            return new Pts(node, left.tail);
        } else if (left == null) {
            node.right = right.head;
            return new Pts(node, right.tail);
        } else {
            node.left = null;
            node.right = left.head;
            left.tail.right = right.head;
            return new Pts(node, right.tail);
        }
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        FlattenBinaryTreeToLinkedList solution = new FlattenBinaryTreeToLinkedList();
        solution.flatten(root);
        ArrayList<String> result = TreeNode.serialize(root);
        for (String s: result) {
            System.out.println(s);
        }
    }
}