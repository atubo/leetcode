import LeetcodeUtil.*;
import java.util.*;

public class SingleNumberII {
    public int singleNumber(int[] A) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            long bit_i = 0;
            long mask = (1 << i);
            for (int j = 0; j < A.length; j++) {
                bit_i += (A[j] & mask);
            }
            result |= (bit_i % (3 * mask));
        }
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] A = reader.readArray();
        SingleNumberII solution = new SingleNumberII();
        System.out.printf("%d\n", solution.singleNumber(A));
    }
}
        