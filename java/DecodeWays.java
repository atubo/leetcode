import java.util.*;

public class DecodeWays {
    public int numDecodings(String s) {
        int N = s.length();
        if (N == 0) return 0;
        int[] dp = new int[N+1];
        dp[0] = 1;
        dp[1] = isValid(s.substring(0, 1)) ? 1 : 0;
        for (int i = 2; i <= N; i++) {
            if (isValid(s.substring(i-2, i))) {
                dp[i] = dp[i-2];
            }
            if (isValid(s.substring(i-1, i))) {
                dp[i] += dp[i-1];
            }
        }
        return dp[N];
    }
    private boolean isValid(String s) {
        if (s.charAt(0) == '0') return false;
        int x = Integer.parseInt(s);
        return (x > 0 && x <= 26);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        DecodeWays solution = new DecodeWays();
        int result = solution.numDecodings(s);
        System.out.printf("%d\n", result);
    }
}