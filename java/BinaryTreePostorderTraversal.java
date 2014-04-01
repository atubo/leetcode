import LeetcodeUtil.*;
import java.util.*;

public class BinaryTreePostorderTraversal {
    public static class TaggedNode {
        public TreeNode node;
        public boolean visited;
        
        public TaggedNode(TreeNode node, boolean visited) {
            this.node = node;
            this.visited = visited;
        }
    }
    
    public ArrayList<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        
        Stack<TaggedNode> stack = new Stack<>();
        if (root != null) stack.push(new TaggedNode(root, false));
        while (!stack.empty()) {
            TaggedNode tnode = stack.pop();
            TreeNode node = tnode.node;
            if (tnode.visited) {
                result.add(node.val);
            } else {
                stack.push(new TaggedNode(node, true));
                if (node.right != null) {
                    stack.push(new TaggedNode(node.right, false));
                }
                if (node.left != null) {
                    stack.push(new TaggedNode(node.left, false));
                }
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BinaryTreePostorderTraversal solution = new BinaryTreePostorderTraversal();
        ArrayList<Integer> result = solution.postorderTraversal(root);
        for (Integer i: result) {
            System.out.println(i);
        }
    }
}