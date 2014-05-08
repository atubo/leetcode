import LeetcodeUtil.*;
import java.util.*;

public class ThreeSumClosest {
    public int threeSumClosest(int[] a, int target) {
        Arrays.sort(a);
        int n = a.length;
        int result = a[0] + a[1] + a[n-1];
        for (int i = 0; i < n-2; i++) {
            int j = i+1;
            int k = n-1;
            while (k > j) {
                int sum = a[i] + a[j] + a[k];
                if (Math.abs(sum-target) < Math.abs(result-target)) {
                    result = sum;
                }
                if (sum >= target) k--;
                else j++;
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        ThreeSumClosest solution = new ThreeSumClosest();
        System.out.println(solution.threeSumClosest(a, -1));
    }
}