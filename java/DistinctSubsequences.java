import java.util.*;

public class DistinctSubsequences {
    public int numDistinct(String S, String T) {
        int N = S.length();
        int M = T.length();
        if (N == 0 || M == 0) return 0;
        int[][] dp = new int[N][M];
        for (int i = 1; i < M; i++) {
            dp[0][i] = 0;
        }
        dp[0][0] = (S.charAt(0) == T.charAt(0) ? 1 : 0);
        for (int i = 1; i < N; i++) {
            dp[i][0] = dp[i-1][0];
            if (S.charAt(i) == T.charAt(0)) {
                dp[i][0]++;
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (S.charAt(i) == T.charAt(j)) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N-1][M-1];
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        DistinctSubsequences solution = new DistinctSubsequences();
        System.out.printf("%d\n", solution.numDistinct(S, T));
    }
}