import java.util.*;
import LeetcodeUtil.*;

public class TwoSum {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();
        for (int i = 0; i < numbers.length; i++) {
            int a = numbers[i];
            if (seen.containsKey(target - a)) {
                result[0] = seen.get(target - a) + 1;
                result[1] = i + 1;
                return result;
            }
            seen.put(a, i);
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] numbers = reader.readArray();
        int target = reader.readInt();
        TwoSum solution = new TwoSum();
        int[] result = solution.twoSum(numbers, target);
        for (int i = 0; i < 2; i++) {
            System.out.println(result[i]);
        }
    }
}
        