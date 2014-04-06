import LeetcodeUtil.*;
import java.util.*;

public class PopulatingNextRightPointersInEachNode {
    public void connect(TreeLinkNode root) {
        if (root == null) return;
        visit(root);
    }
    
    private void visit(TreeLinkNode node) {
        if (node.left == null) return;
        node.left.next = node.right;
        if (node.next != null) {
            node.right.next = node.next.left;
        }
        visit(node.left);
        visit(node.right);
    }
    
    public static void main(String[] args) {
        TreeLinkNode root = TreeLinkNode.parse();
        PopulatingNextRightPointersInEachNode solution = new PopulatingNextRightPointersInEachNode();
        solution.connect(root);
        if (root != null) print(root);
    }
    
    public static void print(TreeLinkNode node) {
        System.out.printf("%d -> ", node.val);
        if (node.next != null) {
            System.out.println(node.next.val);
        } else {
            System.out.println("null");
        }
        if (node.left != null) {
            print(node.left);
            print(node.right);
        }
    }
}
    
    