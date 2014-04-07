import LeetcodeUtil.*;
import java.util.*;

public class MinimumDepthOfBinaryTree {
    private static class TaggedNode {
        public TreeNode node;
        public int depth;
        public TaggedNode(TreeNode node, int depth) {
            this.node = node;
            this.depth = depth;
        }
    }
    
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        LinkedList<TaggedNode> nodes = new LinkedList<>();
        nodes.offerLast(new TaggedNode(root, 1));
        while (!nodes.isEmpty()) {
            TaggedNode tnode = nodes.pollFirst();
            TreeNode node = tnode.node;
            if (node.left == null && node.right == null) {
                return tnode.depth;
            }
            if (node.left != null) {
                nodes.offerLast(new TaggedNode(node.left, tnode.depth+1));
            }
            if (node.right != null) {
                nodes.offerLast(new TaggedNode(node.right, tnode.depth+1));
            }
        }
        // shouldn't arrive here
        assert false;
        return 0;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        MinimumDepthOfBinaryTree solution = new MinimumDepthOfBinaryTree();
        System.out.println(solution.minDepth(root));
    }
}