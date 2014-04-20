import LeetcodeUtil.*;
import java.util.*;

public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int N = preorder.length;
        return build(preorder, 0, N, inorder, 0, N);
    }
    private TreeNode build(int[] preorder, int lo1, int hi1, int[] inorder, int lo2, int hi2) {
        if (lo1 == hi1) return null;
        TreeNode node = new TreeNode(preorder[lo1]);
        int rootIndex = lo2;
        for (; rootIndex < hi2; rootIndex++) {
            if (inorder[rootIndex] == preorder[lo1]) break;
        }
        int lenLeft = rootIndex - lo2;
        node.left = build(preorder, lo1+1, lo1+1+lenLeft, inorder, lo2, lo2+lenLeft);
        node.right = build(preorder, lo1+1+lenLeft, hi1, inorder, lo2+1+lenLeft, hi2);
        return node;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] preorder = reader.readArray();
        int[] inorder  = reader.readArray();
        ConstructBinaryTreeFromPreorderAndInorderTraversal solution = 
            new ConstructBinaryTreeFromPreorderAndInorderTraversal();
        TreeNode root = solution.buildTree(preorder, inorder);
        ArrayList<String> result = TreeNode.serialize(root);
        System.out.println(result);
    }
}