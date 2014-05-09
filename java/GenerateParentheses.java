import java.util.*;

public class GenerateParentheses {
    public ArrayList<String> generateParenthesis(int n) {
        ArrayList<ArrayList<String>> paren = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            paren.add(new ArrayList<String>());
        }
        paren.get(0).add("");
        for (int len = 1; len <= n; len++) {
            for (int k = 1; k < 2*len; k += 2) {
                int l1 = (k-1)/2;
                int l2 = (2*len-1-k)/2;
                ArrayList<String> p1 = paren.get(l1);
                ArrayList<String> p2 = paren.get(l2);
                for (String part1: p1) {
                    for (String part2: p2) {
                        paren.get(len).add("(" + part1 + ")" + part2);
                    }
                }
            }
        }
        return paren.get(n);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        GenerateParentheses solution = new GenerateParentheses();
        ArrayList<String> result = solution.generateParenthesis(n);
        for (String s: result) {
            System.out.println(s);
        }
    }
}