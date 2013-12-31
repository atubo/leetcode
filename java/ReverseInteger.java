import java.util.*;
import LeetcodeUtil.InputReader;

public class ReverseInteger {
    public int reverse(int x) {
        if (x == 0) return 0;
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int result = 0;
        while (x > 0) {
            result = result * 10 + (x % 10);
            x = x / 10;
        }
        
        return result * sign;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int x = reader.readInt();
        
        ReverseInteger solution = new ReverseInteger();
        System.out.println(solution.reverse(x));
    }
}