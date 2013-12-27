package LeetcodeUtil;

import java.util.Scanner;

public class InputReader {
    Scanner sc = new Scanner(System.in);
    
    public int[] readArray() {
        int n = sc.nextInt();
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = sc.nextInt();
        }
        return result;
    }
    
    public int readInt() {
        int result = sc.nextInt();
        return result;
    }
}
        