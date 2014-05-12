import java.util.*;

public class ScrambleString {
    private int[][][] dp;
    
    public boolean isScramble(String s1, String s2) {
        int N = s1.length();
        if (N == 0) return true;
        dp = new int[N][N][N+1];
        return check(s1, 0, N-1, s2, 0, N-1) == 2;
    }
    
    private int check(String s1, int p1, int q1, String s2, int p2, int q2) {
        if (dp[p1][p2][q1-p1+1] != 0) {
            return dp[p1][p2][q1-p1+1];
        }
        
        int result = 1;
        if (p1 == q1) {
            result = (s1.charAt(p1) == s2.charAt(p2)) ? 2 : 1;
        } else {
            for (int len = 1; len < q1-p1+1; len++) {
                int c1 = check(s1, p1, p1+len-1, s2, p2, p2+len-1);
                int c2 = check(s1, p1+len, q1, s2, p2+len, q2);
                int c3 = check(s1, p1, p1+len-1, s2, q2+1-len, q2);
                int c4 = check(s1, p1+len, q1, s2, p2, q2-len);
                if (c1 == 2 && c2 == 2 || c3 == 2 && c4 == 2) {
                    result = 2;
                    break;
                }
            }
        }
        dp[p1][p2][q1-p1+1] = result;
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        ScrambleString solution = new ScrambleString();
        System.out.printf("%b\n", solution.isScramble(s1, s2));
    }
}