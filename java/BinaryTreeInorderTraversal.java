import LeetcodeUtil.*;
import java.util.*;

public class BinaryTreeInorderTraversal {
    private static class TaggedNode {
        public TreeNode node;
        public boolean flag;
        public TaggedNode(TreeNode node, boolean flag) {
            this.node = node;
            this.flag = flag;
        }
    }
        
    private void addToStack(Stack<TaggedNode> stack, TreeNode node) {
        if (node == null) return;
        if (node.right != null) {
            stack.push(new TaggedNode(node.right, false));
        }
        stack.push(new TaggedNode(node, true));
        if (node.left != null) {
            stack.push(new TaggedNode(node.left, false));
        }
    }
    
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<>();
        Stack<TaggedNode> stack = new Stack<>();
        addToStack(stack, root);
        while (!stack.empty()) {
            TaggedNode tnode = stack.pop();
            if (tnode.flag) result.add(tnode.node.val);
            else {
                addToStack(stack, tnode.node);
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        TreeNode root = TreeNode.parse();
        BinaryTreeInorderTraversal solution = new BinaryTreeInorderTraversal();
        ArrayList<Integer> result = solution.inorderTraversal(root);
        for (Integer x: result) {
            System.out.printf("%d ", x);
        }
    }
}