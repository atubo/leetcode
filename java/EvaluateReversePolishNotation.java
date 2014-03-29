import java.util.*;

public class EvaluateReversePolishNotation {
    private boolean isOperator(String s) {
        return s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/");
    }
    
    public int evalRPN(String[] tokens) {
        Stack<Integer> operands = new Stack<>();
        for (String s: tokens) {
            if (isOperator(s)) {
                int op2 = operands.pop();
                int op1 = operands.pop();
                switch (s.charAt(0)) {
                    case '+':
                        operands.push(op1 + op2);
                        break;
                    case '-':
                        operands.push(op1 - op2);
                        break;
                    case '*':
                        operands.push(op1 * op2);
                        break;
                    case '/':
                        operands.push(op1 / op2);
                        break;
                }
            } else {
                operands.push(Integer.parseInt(s));
            }
        }
        assert operands.size() == 1;
        return operands.pop();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] tokens = new String[N];
        for (int i = 0; i < N; i++) {
            tokens[i] = sc.next();
        }
        
        EvaluateReversePolishNotation solution = new EvaluateReversePolishNotation();
        System.out.println(solution.evalRPN(tokens));
    }
}
                