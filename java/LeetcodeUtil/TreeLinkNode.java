package LeetcodeUtil;

import java.util.*;

public class TreeLinkNode {
    public int val;
    public TreeLinkNode left, right, next;
    public TreeLinkNode(int x) { val = x; }
    
    private static boolean isNullNode(String item) {
        return item.equals("#");
    }
    
    private static TreeLinkNode makeNode(String item) {
        if (isNullNode(item)) return null;
        return new TreeLinkNode(Integer.parseInt(item));
    }
    
    public static TreeLinkNode deserialize(String[] items) {
        Deque<TreeLinkNode> queue = new ArrayDeque<>();
        
        TreeLinkNode root = makeNode(items[0]);
        if (root != null) queue.addLast(root);
        int index = 1;
        while (!queue.isEmpty()) {
            TreeLinkNode node = queue.pollFirst();
            if (index < items.length) node.left  = makeNode(items[index++]);
            if (index < items.length) node.right = makeNode(items[index++]);
            if (node.left != null) queue.addLast(node.left);
            if (node.right != null) queue.addLast(node.right);
        }
        
        return root;
    }
    
    public static TreeLinkNode parse() {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] items = s.split(" ");
        return deserialize(items);
    }
}