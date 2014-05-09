import LeetcodeUtil.*;
import java.util.*;

public class MergeKSortedLists {
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(11,
                                                         new Comparator<ListNode>() {
            @Override
            public int compare(ListNode n1, ListNode n2) {
                return Integer.compare(n1.val, n2.val);
            }
        });
        for (int i = 0; i < lists.size(); i++) {
            ListNode head = lists.get(i);
            if (head != null) {
                pq.add(head);
            }
        }
        if (pq.isEmpty()) return null;
        
        ListNode node = pq.poll();
        addNext(pq, node);
        ListNode head = node;
        ListNode curr = node;
        while (!pq.isEmpty()) {
            node = pq.poll();
            addNext(pq, node);
            curr.next = node;
            curr = node;
        }
        return head;
    }
    
    private void addNext(PriorityQueue<ListNode> pq, ListNode node) {
        if (node.next != null) {
            pq.add(node.next);
        }
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int n = reader.readInt();
        ArrayList<ListNode> lists = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ListNode head = reader.readList();
            lists.add(head);
        }
        MergeKSortedLists solution = new MergeKSortedLists();
        ListNode head = solution.mergeKLists(lists);
        ListNode.printList(head);
    }
}
        
            