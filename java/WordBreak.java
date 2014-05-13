import java.util.*;

public class WordBreak {
    public boolean wordBreak(String s, Set<String> dict) {
        int N = s.length();
        if (N == 0) return dict.contains("");
        
        boolean[][] dp = new boolean[N+1][N+1];
        for (int len = 1; len <= N; len++) {
            for (int pos = 0; pos <= N-len; pos++) {
                if (dict.contains(s.substring(pos, pos+len))) {
                    dp[pos][pos+len] = true;
                    continue;
                }
                for (int split = pos; split <= pos+len-2; split++) {
                    if (dp[pos][split+1] && dp[split+1][pos+len]) {
                        dp[pos][pos+len] = true;
                        break;
                    }
                }
            }
        }
        return dp[0][N];
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        Set<String> dict = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            dict.add(sc.next());
        }
        WordBreak solution = new WordBreak();
        System.out.println(solution.wordBreak(s, dict));
    }
}
            