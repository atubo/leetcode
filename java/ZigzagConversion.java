import java.util.*;

import LeetcodeUtil.InputReader;

public class ZigzagConversion {
    public String convert(String s, int nRow) {
        if (nRow == 1) return s;
        
        final int m = 2 * (nRow - 1);
        final int L = s.length();
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        while (pos < L) {
            sb.append(s.charAt(pos));
            pos += m;
        }
        
        for (int j = 1; j < nRow - 1; j++) {
            pos = j;
            if (pos >= L) continue;
            sb.append(s.charAt(pos));
            while (true) {
                pos += (m - 2*j);
                if (pos >= L) break;
                sb.append(s.charAt(pos));
                pos += 2 * j;
                if (pos >= L) break;
                sb.append(s.charAt(pos));
            }
        }
        
        pos = nRow - 1;
        while (pos < L) {
            sb.append(s.charAt(pos));
            pos += m;
        }
        
        return sb.toString();
    }
    
    public static void main(String[] args) {
        InputReader reader = new InputReader();
        String s = reader.readString();
        int n = reader.readInt();
        
        ZigzagConversion solution = new ZigzagConversion();
        System.out.println(solution.convert(s, n));
    }
}
                