import java.util.*;

public class LetterComboPhoneNumber {
    private void construct(String digits, int depth, int maxDepth,
                           String[] mapping, 
                           StringBuilder sb, ArrayList<String> result) {
        if (depth == maxDepth) {
            result.add(sb.toString());
            return;
        }
        
        int d = digits.charAt(depth) - '0';
        for (int i = 0; i < mapping[d].length(); i++) {
            char c = mapping[d].charAt(i);
            sb.append(c);
            construct(digits, depth + 1, maxDepth, mapping, sb, result);
            sb.deleteCharAt(sb.length()-1);
        }
    }
   
    public ArrayList<String> letterCombinations(String digits) {
        String[] mapping = {
            " ", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        ArrayList<String> result = new ArrayList<String>();
        StringBuilder sb = new StringBuilder();
        construct(digits, 0, digits.length(), mapping, sb, result);
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String digits = sc.next();
        LetterComboPhoneNumber solution = new LetterComboPhoneNumber();
        ArrayList<String> result = solution.letterCombinations(digits);
        
        for (String s: result) {
            System.out.println(s);
        }
    }
}