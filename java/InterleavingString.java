import java.util.*;

public class InterleavingString {
    public static class Pair {
        public int i;
        public int j;
        public Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        int N1 = s1.length();
        int N2 = s2.length();
        int N3 = s3.length();
        if (N1 == 0 && N2 == 0 && N3 == 0) return true;
        if (N1 + N2 != N3) return false;
        LinkedList<Pair> queue = new LinkedList<>();
        queue.add(new Pair(-1, -1));
        for (int i = 0; i < N3; i++) {
            char c = s3.charAt(i);
            LinkedList<Pair> q0 = new LinkedList<>(queue);
            queue.clear();
            for (Pair p: q0) {
                if (p.i < N1 - 1 && s1.charAt(p.i+1) == c) {
                    queue.add(new Pair(p.i+1, p.j));
                }
                if (p.j < N2 - 1 && s2.charAt(p.j+1) == c) {
                    queue.add(new Pair(p.i, p.j+1));
                }
            }
            if (queue.isEmpty()) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        String s3 = sc.next();
        InterleavingString solution = new InterleavingString();
        boolean result = solution.isInterleave(s1, s2, s3);
        System.out.println(result);
    }
}