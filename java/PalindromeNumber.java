import LeetcodeUtil.InputReader;

public class PalindromeNumber {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int mask = 1;

        while (x / mask >= 10) mask *= 10;
        
        while (x > 0) {
            int a = x % 10;
            if (x / mask != a) return false;
            x = (x - a * mask - a) / 10;
            mask /= 100;
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int x = reader.readInt();
        
        PalindromeNumber solution = new PalindromeNumber();
        System.out.println(solution.isPalindrome(x));
    }
}