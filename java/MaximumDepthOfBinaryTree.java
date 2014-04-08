import LeetcodeUtil.*;
import java.util.*;

public class MaximumDepthOfBinaryTree {
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
    
    public int maxDepth(TreeNode root) {
        int result = 0;
        LinkedList<TaggedNode> queue = new LinkedList<>();
        add(queue, root, 1);
        while (!queue.isEmpty()) {
            TaggedNode tnode = queue.pollFirst();
            TreeNode node = tnode.node;
            int depth = tnode.depth;
            result = Math.max(result, depth);
            add(queue, node.left, depth+1);
            add(queue, node.right, depth+1);
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        MaximumDepthOfBinaryTree solution = new MaximumDepthOfBinaryTree();
        System.out.println(solution.maxDepth(root));
    }
}