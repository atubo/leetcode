import java.util.*;

public class ScrambleString {
    public boolean isScramble(String s1, String s2) {
        int N = s1.length();
        if (N == 0) return true;
        return check(s1, 0, N-1, s2, 0, N-1);
    }
    
    private boolean check(String s1, int p1, int q1, String s2, int p2, int q2) {
        if (p1 == q1) {
            return (s1.charAt(p1) == s2.charAt(p2));
        }
        
        int len = (q1+1-p1)/2;
        return check(s1, p1, p1+len-1, s2, p2, p2+len-1) &&
               check(s1, p1+len, q1, s2, p2+len, q2) ||
               check(s1, p1, p1+len-1, s2, q2+1-len, q2) &&
               check(s1, p1+len, q1, s2, p2, q2-len);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next();
        String s2 = sc.next();
        ScrambleString solution = new ScrambleString();
        System.out.printf("%b\n", solution.isScramble(s1, s2));
    }
}