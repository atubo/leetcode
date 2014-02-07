import java.util.*;

public class ValidParentheses {
    private static boolean isSameCategory(char a, char b) {
        return (a == '(' && b == ')') ||
               (a == '[' && b == ']') ||
               (a == '{' && b == '}');
    }
    
    public boolean isValid(String s) {
        Stack<Stack<Character>> pStack = new Stack<Stack<Character>>();
        Stack<Character> curr = null;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                if (curr == null || curr.peek() != c) {
                    curr = new Stack<Character>();
                    pStack.push(curr);
                }
                curr.push(c);
            } else {
                if (curr == null || !isSameCategory(curr.peek(), c)) {
                    return false;
                }
                curr.pop();
                if (curr.isEmpty()) {
                    pStack.pop();
                }
                curr = (pStack.isEmpty() ? null : pStack.peek());
            }
        }
        return (curr == null);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        ValidParentheses solution = new ValidParentheses();
        System.out.println(solution.isValid(s));
    }
}