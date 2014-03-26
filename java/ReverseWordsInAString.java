import java.util.*;

public class ReverseWordsInAString {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s);
        reverse(sb, 0, sb.length());
        removeLeadingTrailingSpace(sb);
        
        int p1 = 0;
        int p2 = 0;
        while (p1 < sb.length()) {
            p2 = p1 + 1;
            while (p2 < sb.length() && sb.charAt(p2) != ' ') {
                p2++;
            }
            reverse(sb, p1, p2);
            p2++;
            while (p2 < sb.length() && sb.charAt(p2) == ' ') {
                sb.deleteCharAt(p2);
            }
            p1 = p2;
        }
        
        return sb.toString();
    }
    
    private void reverse(StringBuilder sb, int start, int end) {
        if (end <= start) return;
        end--;
        int mid = (start + end) / 2;
        for (int i = start; i <= mid; i++) {
            char c1 = sb.charAt(i);
            char c2 = sb.charAt(start + end - i);
            sb.setCharAt(i, c2);
            sb.setCharAt(start + end - i, c1);
        }
    }
    
    private void removeLeadingTrailingSpace(StringBuilder sb) {
        for (int i = sb.length() - 1; i >= 0; i--) {
            if (sb.charAt(i) == ' ') {
                sb.deleteCharAt(i);
            } else {
                break;
            }
        }
        while (sb.length() > 0 && sb.charAt(0) == ' ') {
            sb.deleteCharAt(0);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        ReverseWordsInAString solution = new ReverseWordsInAString();
        System.out.println(solution.reverseWords(s));
    }
}