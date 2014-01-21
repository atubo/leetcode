import java.util.*;
import LeetcodeUtil.*;

public class ThreeSum {
    private static class Triplet implements Comparable<Triplet> {
        private final int x;
        private final int y;
        private final int z;
        
        public Triplet(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        
        @Override
        public int compareTo(Triplet other) {
            if (x < other.x) return -1;
            if (x > other.x) return 1;
            if (y < other.y) return -1;
            if (y > other.y) return 1;
            if (z < other.z) return -1;
            if (z > other.z) return 1;
            return 0;
        }
        
        public ArrayList<Integer> toArray() {
            ArrayList<Integer> result = new ArrayList<Integer>();
            result.add(x);
            result.add(y);
            result.add(z);
            return result;
        }
    }
    
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
        Arrays.sort(num);
        int n = num.length;
        TreeSet<Triplet> triplets = new TreeSet<Triplet>();
        for (int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int x = num[i];
                int y = num[j];
                int z = num[k];
                if (x + y + z == 0) {
                    triplets.add(new Triplet(x, y, z));
                    j++;
                    k--;
                } else if (x + y + z < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        for (Triplet t: triplets) {
            result.add(t.toArray());
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        
        ThreeSum solution = new ThreeSum();
        ArrayList<ArrayList<Integer>> result = solution.threeSum(a);
        for (ArrayList l: result) {
            System.out.println(l);
        }
    }
}