import LeetcodeUtil.*;
import java.util.*;

public class PathSum {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) return false;
        return check(root, sum);
    }
    
    private boolean check(TreeNode node, int value) {
        if (node.left == null && node.right == null) {
            return node.val == value;
        }
        
        if (node.left != null && check(node.left, value - node.val)) {
            return true;
        }
        if (node.right != null && check(node.right, value - node.val)) {
            return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        PathSum solution = new PathSum();
        System.out.println(solution.hasPathSum(root, 28));
    }
}
        