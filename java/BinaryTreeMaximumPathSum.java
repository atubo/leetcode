import LeetcodeUtil.*;
import java.util.*;

public class BinaryTreeMaximumPathSum {
    private static class SumInfo {
        private int maxSum;
        private int maxSumToLeaf;
        public SumInfo(int maxSum, int maxSumToLeaf) {
            this.maxSum = maxSum;
            this.maxSumToLeaf = maxSumToLeaf;
        }
    }
    public int maxPathSum(TreeNode root) {
        if (root == null) return 0;
        SumInfo sumInfo = visit(root);
        return sumInfo.maxSum;
    }
    private SumInfo visit(TreeNode node) {
        int maxSumLeft = Integer.MIN_VALUE;
        int maxSumToLeafLeft = 0;
        int maxSumRight = Integer.MIN_VALUE;
        int maxSumToLeafRight = 0;
        if (node.left != null) {
            SumInfo sumInfo = visit(node.left);
            maxSumLeft = sumInfo.maxSum;
            maxSumToLeafLeft = Math.max(0, sumInfo.maxSumToLeaf);
        }
        if (node.right != null) {
            SumInfo sumInfo = visit(node.right);
            maxSumRight = sumInfo.maxSum;
            maxSumToLeafRight = Math.max(0, sumInfo.maxSumToLeaf);
        }
        int maxSumToLeaf = Math.max(maxSumToLeafLeft, maxSumToLeafRight) + node.val;
        int maxSum = Math.max(Math.max(maxSumLeft, maxSumRight),
                              maxSumToLeafLeft + maxSumToLeafRight + node.val);
        return new SumInfo(maxSum, maxSumToLeaf);
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BinaryTreeMaximumPathSum solution = new BinaryTreeMaximumPathSum();
        int result = solution.maxPathSum(root);
        System.out.println(result);
    }
}