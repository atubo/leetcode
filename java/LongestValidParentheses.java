import java.util.*;

public class LongestValidParentheses {
    private static class Entry {
        public int pos;
        public int state;
        
        public Entry(int pos, int state) {
            this.pos = pos;
            this.state = state;
        }
    }
        
    public int longestValidParentheses(String s) {
        int result = 0;
        Stack<Entry> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                if (st.empty() || st.peek().state == 0) {
                    st.push(new Entry(i, 0));
                } else {
                    st.peek().state = 0;
                }
            } else {
                if (st.empty()) continue;
                Entry e = st.peek();
                if (e.state == 0) {
                    e.state = 1;
                    result = Math.max(result, i - e.pos + 1);
                } else {
                    st.pop();
                    if (!st.empty()) {
                        st.peek().state = 1;
                        result = Math.max(result, i - st.peek().pos + 1);
                    }
                }
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        LongestValidParentheses solution = new LongestValidParentheses();
        System.out.println(solution.longestValidParentheses(s));
    }
}
                    