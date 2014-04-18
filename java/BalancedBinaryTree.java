import LeetcodeUtil.*;
import java.util.*;

public class BalancedBinaryTree {
    private static class FastReturn extends Exception {}
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        try {
            check(root);
        } catch (FastReturn e) {
            return false;
        }
        return true;
    }
    private int check(TreeNode node) throws FastReturn {
        int h1 = 0;
        int h2 = 0;
        if (node.left != null) {
            h1 = check(node.left);
        }
        if (node.right != null) {
            h2 = check(node.right);
        }
        if (Math.abs(h1-h2) > 1) {
            throw new FastReturn();
        }
        return Math.max(h1, h2) + 1;
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BalancedBinaryTree solution = new BalancedBinaryTree();
        boolean result = solution.isBalanced(root);
        System.out.println(result);
    }
}