import LeetcodeUtil.*;
import java.util.*;

public class SumRootToLeafNumbers {
    private int result;
    private void init() {
        result = 0;
    }
    public int sumNumbers(TreeNode root) {
        if (root == null) return 0;
        init();
        visit(root, 0);
        return result;
    }
    private void visit(TreeNode node, int x) {
        int xp = 10 * x + node.val;
        if (node.left == null && node.right == null) {
            result += xp;
            return;
        }
        if (node.left != null) {
            visit(node.left, xp);
        }
        if (node.right != null) {
            visit(node.right, xp);
        }
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        SumRootToLeafNumbers solution = new SumRootToLeafNumbers();
        int result = solution.sumNumbers(root);
        System.out.printf("%d\n", result);
    }
}