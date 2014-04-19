import LeetcodeUtil.*;
import java.util.*;

public class LongestConsecutiveSequence {
    public int longestConsecutive(int[] num) {
        HashSet<Integer> hash = new HashSet<>();
        for (int i = 0; i < num.length; i++) {
            hash.add(num[i]);
        }
        int result = 0;
        while (!hash.isEmpty()) {
            int x = hash.iterator().next();
            int length = 1;
            hash.remove(x);
            int y = x + 1;
            while (hash.contains(y)) {
                hash.remove(y);
                length++;
                y++;
            }
            y = x - 1;
            while (hash.contains(y)) {
                hash.remove(y);
                length++;
                y--;
            }
            result = Math.max(result, length);
        }
        return result;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        int[] a = reader.readArray();
        LongestConsecutiveSequence solution = new LongestConsecutiveSequence();
        int result = solution.longestConsecutive(a);
        System.out.println(result);
    }
}