import LeetcodeUtil.*;
import java.util.*;

public class ConvertSortedArrayToBinarySearchTree {
    public TreeNode sortedArrayToBST(int[] num) {
        return build(num, 0, num.length);
    }
    private TreeNode build(int[] a, int start, int end) {
        if (start == end) return null;
        int mid = (start + end)/2 ;
        TreeNode node = new TreeNode(a[mid]);
        node.left  = build(a, start, mid);
        node.right = build(a, mid+1, end);
        return node;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] num = reader.readArray();
        ConvertSortedArrayToBinarySearchTree solution = new ConvertSortedArrayToBinarySearchTree();
        TreeNode root = solution.sortedArrayToBST(num);
        ArrayList<String> s = TreeNode.serialize(root);
        System.out.println(s);
    }
}