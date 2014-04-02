import LeetcodeUtil.*;
import java.util.*;

public class BinaryTreePreorderTraversal {
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        if (root != null) stack.push(root);
        
        while (!stack.empty()) {
            TreeNode node = stack.pop();
            result.add(node.val);
            if (node.right != null) stack.push(node.right);
            if (node.left  != null) stack.push(node.left);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BinaryTreePreorderTraversal solution = new BinaryTreePreorderTraversal();
        ArrayList<Integer> result = solution.preorderTraversal(root);
        for (Integer i: result) {
            System.out.printf("%d\n", i);
        }
    }
}