import LeetcodeUtil.*;
import java.util.*;

public class PlusOne {
    public int[] plusOne(int[] digits) {
        boolean allNine = true;
        final int N = digits.length;
        for (int i = 0; i < N; i++) {
            if (digits[i] < 9) {
                allNine = false;
                break;
            }
        }
        if (allNine) {
            int[] result = new int[N+1];
            result[0] = 1;
            for (int i = 1; i <= N; i++) {
                result[i] = 0;
            }
            return result;
        }
        
        int[] result = new int[N];
        for (int i = 0; i < N; i++) {
            result[i] = digits[i];
        }
        int carry = 1;
        for (int i = N-1; i >= 0; i--) {
            if (result[i] + carry <= 9) {
                result[i]++;
                break;
            }
            result[i] = 0;
            carry = 1;
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        PlusOne solution = new PlusOne();
        int[] result = solution.plusOne(a);
        for (int i = 0; i < result.length; i++) {
            System.out.printf("%d ", result[i]);
        }
        System.out.println();
    }
}