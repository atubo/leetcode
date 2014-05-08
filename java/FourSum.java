import LeetcodeUtil.*;
import java.util.*;

public class FourSum {
    private static class Pair {
        public int first;
        public int second;
        
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    private static class Quad implements Comparable<Quad> {
        public int a;
        public int b;
        public int c;
        public int d;
        
        public Quad(int a, int b, int c, int d) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
        
        @Override
        public int compareTo(Quad other) {
            if (a < other.a) return -1;
            if (a > other.a) return 1;
            if (b < other.b) return -1;
            if (b > other.b) return 1;
            if (c < other.c) return -1;
            if (c > other.c) return 1;
            if (d < other.d) return -1;
            if (d > other.d) return 1;
            return 0;
        }
        
        public ArrayList<Integer> toList() {
            ArrayList<Integer> result = new ArrayList<>();
            result.add(a);
            result.add(b);
            result.add(c);
            result.add(d);
            return result;
        }
    }
    
    public ArrayList<ArrayList<Integer>> fourSum(int[] a, int target) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        TreeSet<Quad> quads = new TreeSet<>();
        
        Arrays.sort(a);
        int n = a.length;
        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                ArrayList<Pair> pairs = twoSum(a, j+1, target-a[i]-a[j]);
                for (Pair p: pairs) {
                    quads.add(new Quad(a[i], a[j], p.first, p.second));
                }
            }
        }
        for (Quad q: quads) {
            result.add(q.toList());
        }
        return result;
    }
    
    private ArrayList<Pair> twoSum(int[] a, int start, int target) {
        ArrayList<Pair> result = new ArrayList<>();
        int n = a.length;
        HashSet<Integer> seen = new HashSet<>();
        for (int i = start; i < n; i++) {
            if (seen.contains(target-a[i])) {
                result.add(new Pair(target-a[i], a[i]));
            }
            seen.add(a[i]);
        }
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int target = reader.readInt();
        int[] a = reader.readArray();
        FourSum solution = new FourSum();
        ArrayList<ArrayList<Integer>> result = solution.fourSum(a, target);
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }
    }
}