import LeetcodeUtil.*;
import java.util.*;

public class ValidateBinarySearchTree {
    class NotValidBSTException extends Exception {}
    
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        init();
        try {
            inorder(root);
        } catch (NotValidBSTException e) {
            return false;
        }
        return true;
    }
    private void inorder(TreeNode node) throws NotValidBSTException {
        if (node.left != null) {
            inorder(node.left);
        }
        if (prev >= node.val) {
            throw new NotValidBSTException();
        }
        prev = node.val;
        if (node.right != null) {
            inorder(node.right);
        }
    }
    private void init() {
        prev = Integer.MIN_VALUE;
    }
    private int prev;
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        ValidateBinarySearchTree solution = new ValidateBinarySearchTree();
        System.out.println(solution.isValidBST(root));
    }
}