import LeetcodeUtil.*;
import java.util.*;

public class JumpGame {
    public boolean canJump(int[] a) {
        int N = a.length;
        if (N <= 1) return true;
        
        int minFeasible = N-1;
        for (int i = N-2; i >= 0; i--) {
            if (a[i] + i >= minFeasible) minFeasible = i;
        }
        return (minFeasible == 0);
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        JumpGame solution = new JumpGame();
        System.out.println(solution.canJump(a));
    }
}
