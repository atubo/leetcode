import LeetcodeUtil.*;
import java.util.*;

public class PathSumII {
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) {
            return new ArrayList<ArrayList<Integer>>();
        }
        ArrayList<ArrayList<Integer>> result = solve(root, sum);
        for (ArrayList<Integer> array: result) {
            Collections.reverse(array);
        }
        return result;
    }
    private ArrayList<ArrayList<Integer>> solve(TreeNode node, int target) {
        if (node.left == null && node.right == null) {
            ArrayList<ArrayList<Integer>> result = new ArrayList<>();
            if (node.val == target) {
                result.add(new ArrayList<Integer>());
                result.get(0).add(target);
            }
            return result;
        }
        ArrayList<ArrayList<Integer>> result;
        if (node.left != null && node.right != null) {
            result = solve(node.left, target - node.val);
            result.addAll(solve(node.right, target - node.val));
        } else if (node.left != null) {
            result = solve(node.left, target - node.val);
        } else {
            result = solve(node.right, target - node.val);
        }
        for (ArrayList<Integer> array: result) {
            array.add(node.val);
        }
        return result;
    }
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        PathSumII solution = new PathSumII();
        ArrayList<ArrayList<Integer>> result = solution.pathSum(root, 12);
        for (ArrayList<Integer> array: result) {
            System.out.println(array);
        }
    }
}