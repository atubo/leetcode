import java.util.*;

public class LRUCache {
    public static class Node {
        public int val;
        public Node prev;
        public Node next;
        
        public Node(int val, Node prev, Node next) {
            this.val  = val;
            this.prev = prev;
            this.next = next;
        }
    }
    
    public static class DList {
        public Node head;
        public Node tail;
        
        public void moveToFront(Node node) {
            if (head == node) return;
            Node prev = node.prev;
            Node next = node.next;
            prev.next = next;
            if (next != null) {
                next.prev = prev;
            } else {
                tail = prev;
            }
            
            node.next = head;
            head.prev = node;
            head = node;
        }
        
        public void removeTail() {
            if (head == tail) {
                head = tail = null;
                return;
            }
            
            Node prev = tail.prev;
            prev.next = null;
            tail = prev;
        }
        
        public void addFront(int val) {
            Node node = new Node(val, null, head);
            head = node;
            if (tail == null) tail = node;
        }
    }
    
    int capacity;
    int size;
    DList list = new DList();
    HashMap<Integer, Node> index = new HashMap<>();
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Node node = index.get(key);
        if (node == null) return -1;
        
        list.moveToFront(node);
        return node.val;
    }
    
    public void set(int key, int val) {
        Node node = index.get(key);
        if (node != null) {
            node.val = val;
            list.moveToFront(node);
        } else {
            if (size < capacity) {
                size++;
            } else {
                list.removeTail();
            }
            list.addFront(val);
            index.put(key, list.head);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int capacity = sc.nextInt();
        LRUCache cache = new LRUCache(capacity);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int op = sc.nextInt();
            if (op == 0) {
                int key = sc.nextInt();
                System.out.println(cache.get(key));
            } else {
                int key = sc.nextInt();
                int val = sc.nextInt();
                cache.set(key, val);
            }
        }
    }
}
                
    
    
        
        