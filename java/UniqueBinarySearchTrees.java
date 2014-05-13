import java.util.*;

public class UniqueBinarySearchTrees {
    public int numTrees(int n) {
        int[] dp = new int[n+1];
        dp[0] = 1;
        for (int size = 1; size <= n; size++) {
            for (int root = 1; root <= size; root++) {
                dp[size] += dp[root-1]*dp[size-root];
            }
        }
        return dp[n];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        UniqueBinarySearchTrees solution = new UniqueBinarySearchTrees();
        System.out.println(solution.numTrees(n));
    }
}
            