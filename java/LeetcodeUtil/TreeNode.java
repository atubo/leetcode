package LeetcodeUtil;

import java.util.*;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) {val = x;}
    
    private static boolean isNullNode(String item) {
        return item.equals("#");
    }
    
    private static TreeNode makeNode(String item) {
        if (isNullNode(item)) return null;
        return new TreeNode(Integer.parseInt(item));
    }
    
    private static String makeString(TreeNode node) {
        if (node == null) return "#";
        return Integer.toString(node.val);
    }
    
    public static TreeNode deserialize(String[] items) {
        Deque<TreeNode> queue = new ArrayDeque<>();
        
        TreeNode root = makeNode(items[0]);
        if (root != null) queue.addLast(root);
        int index = 1;
        while (!queue.isEmpty()) {
            TreeNode node = queue.pollFirst();
            if (index < items.length) node.left  = makeNode(items[index++]);
            if (index < items.length) node.right = makeNode(items[index++]);
            if (node.left != null) queue.addLast(node.left);
            if (node.right != null) queue.addLast(node.right);
        }
        
        return root;
    }
    
    public static ArrayList<String> serialize(TreeNode root) {
        ArrayList<String> result = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        
        queue.offerLast(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.pollFirst();
            result.add(makeString(node));
            if (node == null) continue;
            queue.offerLast(node.left);
            queue.offerLast(node.right);
        }
        return result;
    }
    
    public static TreeNode parse() {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] items = s.split(" ");
        return deserialize(items);
    }
}
