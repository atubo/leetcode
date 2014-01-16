import java.util.*;

public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        int M = strs.length;
        StringBuilder sb = new StringBuilder();
        if (M > 0) {
            for (int i = 0; i < strs[0].length(); i++) {
                char c = strs[0].charAt(i);
                for (int k = 1; k < M; k++) {
                    if (strs[k].length() < i+1 || strs[k].charAt(i) != c) {
                        return sb.toString();
                    }
                }
                sb.append(c);
            }
        }
        return sb.toString();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] strs = new String[N];
        for (int i = 0; i < N; i++) {
            strs[i] = sc.next();
        }
        
        LongestCommonPrefix solution = new LongestCommonPrefix();
        System.out.println(solution.longestCommonPrefix(strs));
    }
}
            