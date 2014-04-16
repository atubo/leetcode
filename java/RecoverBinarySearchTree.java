import LeetcodeUtil.*;
import java.util.*;

public class RecoverBinarySearchTree {
    TreeNode nodePrev;
    TreeNode node1;
    TreeNode node2;
    private void init() {
        nodePrev = null;
        node1 = null;
        node2 = null;
    }
    public void recoverTree(TreeNode root) {
        if (root == null) return;
        init();
        inorder(root);
        int tmp = node1.val;
        node1.val = node2.val;
        node2.val = tmp;
    }
    private void inorder(TreeNode node) {
        if (node.left != null) {
            inorder(node.left);
        }
        if (node1 == null && nodePrev != null && node.val < nodePrev.val) {
            node1 = nodePrev;
        }
        if (node1 != null && node.val < nodePrev.val) {
            node2 = node;
        }
        nodePrev = node;
        if (node.right != null) {
            inorder(node.right);
        }
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        RecoverBinarySearchTree solution = new RecoverBinarySearchTree();
        solution.recoverTree(root);
        System.out.println(TreeNode.serialize(root));
    }
}
    