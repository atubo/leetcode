import LeetcodeUtil.*;
import java.util.*;

public class SubsetsII {
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        TreeSet<ArrayList<Integer>> result = new TreeSet<>(new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> a1, ArrayList<Integer> a2) {
                if (a1.size() < a2.size()) return -1;
                if (a1.size() > a2.size()) return 1;
                for (int i = 0; i < a1.size(); i++) {
                    if (a1.get(i) < a2.get(i)) return -1;
                    if (a1.get(i) > a2.get(i)) return 1;
                }
                return 0;
            }
        });
        Arrays.sort(num);
        int n = num.length;
        subsets(num, 0, n, new ArrayList<Integer>(), result);
        return new ArrayList<ArrayList<Integer>>(result);
    }
    private void subsets(int[] num, int i, int j, ArrayList<Integer> s, 
                         TreeSet<ArrayList<Integer>> result) {
        if (i == j) {
            result.add(s);
            return;
        }
        ArrayList<Integer> s1 = new ArrayList<>(s);
        subsets(num, i+1, j, s1, result);
        ArrayList<Integer> s2 = new ArrayList<>(s);
        s2.add(num[i]);
        subsets(num, i+1, j, s2, result);
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        SubsetsII solution = new SubsetsII();
        ArrayList<ArrayList<Integer>> result = solution.subsetsWithDup(a);
        for (ArrayList<Integer> array: result) {
            for (Integer x: array) {
                System.out.printf("%d ", x);
            }
            System.out.println();
        }
    }
}
        