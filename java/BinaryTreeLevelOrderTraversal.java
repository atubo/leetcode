import LeetcodeUtil.*;
import java.util.*;

public class BinaryTreeLevelOrderTraversal {
    public static class TaggedNode {
        public TreeNode node;
        public int depth;
        public TaggedNode(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }
    
    private void add(LinkedList<TaggedNode> queue, TreeNode node, int depth) {
        if (node == null) return;
        queue.offerLast(new TaggedNode(node, depth));
    }
    
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        LinkedList<TaggedNode> queue = new LinkedList<>();
        add(queue, root, 1);
        while (!queue.isEmpty()) {
            TaggedNode tnode = queue.pollFirst();
            TreeNode node = tnode.node;
            int depth = tnode.depth;
            if (depth > result.size()) {
                result.add(new ArrayList<Integer>());
            }
            result.get(result.size()-1).add(node.val);
            add(queue, node.left, depth+1);
            add(queue, node.right, depth+1);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BinaryTreeLevelOrderTraversal solution = new BinaryTreeLevelOrderTraversal();
        ArrayList<ArrayList<Integer>> result = solution.levelOrder(root);
        for (ArrayList<Integer> list: result) {
            for (Integer x: list) {
                System.out.printf("%d ", x);
            }
            System.out.println();
        }
    }
}
        