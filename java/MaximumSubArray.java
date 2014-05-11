import LeetcodeUtil.*;
import java.util.*;

public class MaximumSubArray {
    public int maxSubArray(int[] a) {
        int N = a.length;
        if (N == 0) return 0;
        
        int dp = a[0];
        int result = a[0];
        for (int i = 1; i < N; i++) {
            if (dp < 0) dp = a[i];
            else dp += a[i];
            result = Math.max(result, dp);
        }
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        MaximumSubArray solution = new MaximumSubArray();
        System.out.println(solution.maxSubArray(a));
    }
}