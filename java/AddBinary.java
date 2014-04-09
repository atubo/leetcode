import java.util.*;

public class AddBinary {
    public String addBinary(String a, String b) {
        StringBuilder a1 = new StringBuilder(a).reverse();
        StringBuilder b1 = new StringBuilder(b).reverse();
        final int N = Math.max(a1.length(), b1.length()) + 1;
        for (int i = a1.length(); i < N; i++) {
            a1.append('0');
        }
        for (int i = b1.length(); i < N; i++) {
            b1.append('0');
        }
        
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = 0; i < N; i++) {
            int d = a1.charAt(i) - '0' + b1.charAt(i) - '0' + carry;
            sb.append((char)('0' + (d & 1)));
            carry = (d > 1 ? 1 : 0);
        }

        // remove trailing 0s
        for (int i = sb.length() - 1; i >= 1; i--) {
            if (sb.charAt(i) == '0') {
                sb.deleteCharAt(i);
            } else {
                break;
            }
        }
        return sb.reverse().toString();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        AddBinary solution = new AddBinary();
        System.out.println(solution.addBinary(a, b));
    }
}