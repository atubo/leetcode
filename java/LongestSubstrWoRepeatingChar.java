import java.util.*;

public class LongestSubstrWoRepeatingChar {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        
        int result = 1;
        int streak = 1;
        HashMap<Character, Integer> lastSeen = new HashMap<Character, Integer>();
        lastSeen.put(s.charAt(0), 0);
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            int lastPos = -1;
            if (lastSeen.containsKey(c)) lastPos = lastSeen.get(c);
            streak = Math.min(streak + 1, i - lastPos);
            lastSeen.put(c, i);
            result = Math.max(result, streak);
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        LongestSubstrWoRepeatingChar solution = new LongestSubstrWoRepeatingChar();
        System.out.println(solution.lengthOfLongestSubstring(s));
    }
}
        