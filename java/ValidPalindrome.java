import java.util.*;

public class ValidPalindrome {
    public boolean isPalindrome(String s0) {
        int N = s0.length();
        if (N == 0) return true;
        String s = s0.toLowerCase();
        int p1 = 0;
        int p2 = N-1;
        while (true) {
            while (p1 < N && !isAlphaNum(s.charAt(p1))) {
                p1++;
            }
            if (p1 == N) break;
            while (p2 >= 0 && !isAlphaNum(s.charAt(p2))) {
                p2--;
            }
            if (p2 < 0) break;
            if (p1 >= p2) break;
            if (s.charAt(p1) != s.charAt(p2)) return false;
            p1++;
            p2--;
        }
        return true;
    }
    private boolean isAlphaNum(char c) {
        return Character.isDigit(c) || Character.isLetter(c);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        ValidPalindrome solution = new ValidPalindrome();
        boolean result = solution.isPalindrome(s);
        System.out.println(result);
    }
}